/************************************************************
 *
 *                 OPEN TRANSACTIONS
 *
 *       Financial Cryptography and Digital Cash
 *       Library, Protocol, API, Server, CLI, GUI
 *
 *       -- Anonymous Numbered Accounts.
 *       -- Untraceable Digital Cash.
 *       -- Triple-Signed Receipts.
 *       -- Cheques, Vouchers, Transfers, Inboxes.
 *       -- Basket Currencies, Markets, Payment Plans.
 *       -- Signed, XML, Ricardian-style Contracts.
 *       -- Scripted smart contracts.
 *
 *  EMAIL:
 *  fellowtraveler@opentransactions.org
 *
 *  WEBSITE:
 *  http://www.opentransactions.org/
 *
 *  -----------------------------------------------------
 *
 *   LICENSE:
 *   This Source Code Form is subject to the terms of the
 *   Mozilla Public License, v. 2.0. If a copy of the MPL
 *   was not distributed with this file, You can obtain one
 *   at http://mozilla.org/MPL/2.0/.
 *
 *   DISCLAIMER:
 *   This program is distributed in the hope that it will
 *   be useful, but WITHOUT ANY WARRANTY; without even the
 *   implied warranty of MERCHANTABILITY or FITNESS FOR A
 *   PARTICULAR PURPOSE.  See the Mozilla Public License
 *   for more details.
 *
 ************************************************************/

#include "opentxs-proto/Types.hpp"
#include "opentxs-proto/Check.hpp"

#include <iostream>

namespace opentxs
{
namespace proto
{

bool CheckProto_1(
    const CredentialSet& credSet,
    const bool silent,
    const std::string& nymID,
    const KeyMode& key,
    bool& haveHD,
    const CredentialSetMode& mode)
{
    if (!credSet.has_nymid()) {
        FAIL("credential set", "missing nym id")
    }

    if (nymID != credSet.nymid()) {
        FAIL("credential set", "wrong nym id")
    }

    if (MIN_PLAUSIBLE_IDENTIFIER > credSet.nymid().size()) {
        FAIL2("credential set", "invalid nym id", credSet.nymid())
    }

    if (!credSet.has_masterid()) {
        FAIL("credential set", "missing master credential id")
    }

    if (MIN_PLAUSIBLE_IDENTIFIER > credSet.masterid().size()) {
        FAIL2(
            "credential set",
            "invalid master credential id",
            credSet.masterid())
    }

    if (!credSet.has_mode()) {
        FAIL("credential set", "missing mode")
    }

    const bool checkMode = (CREDSETMODE_ERROR != mode);

    if (checkMode) {
        if (credSet.mode() != mode) {
            FAIL2("credential set", "incorrect mode", credSet.mode())
        }
    }

    switch (credSet.mode()) {
        case CREDSETMODE_INDEX:
            if (KEYMODE_PRIVATE == key) {
                if (1 > credSet.index()) {
                    FAIL("credential set", "missing index")
                }
            } else {
                if (0 < credSet.index()) {
                    FAIL("credential set", "index present in public mode")
                }
            }

            if (credSet.has_mastercredential()) {
                FAIL(
                    "credential set",
                    "full master credential included in index mode")
            }

            if (0 < credSet.activechildren_size()) {
                FAIL2(
                    "credential set",
                    "full active credentials included in index mode",
                    credSet.activechildren_size())
            }

            if (0 < credSet.revokedchildren_size()) {
                FAIL2(
                    "credential set",
                    "full revoked credentials included in index mode",
                    credSet.revokedchildren_size())
            }

            for (auto& it : credSet.activechildids()) {
                if (MIN_PLAUSIBLE_IDENTIFIER > it.size()) {
                    FAIL2(
                        "credential set",
                        "invalid active child credential identifier",
                        it)
                }
            }

            for (auto& it : credSet.revokedchildids()) {
                if (MIN_PLAUSIBLE_IDENTIFIER > it.size()) {
                    FAIL2(
                        "credential set",
                        "invalid revoked child credential identifier",
                        it)
                }
            }
            break;
        case CREDSETMODE_FULL:
            if (!credSet.has_mastercredential()) {
                FAIL("credential set", "missing master credential")
            }

            if (!Check(
                    credSet.mastercredential(),
                    CredentialSetAllowedCredentials.at(credSet.version()).first,
                    CredentialSetAllowedCredentials.at(credSet.version())
                        .second,
                    silent,
                    key,
                    CREDROLE_MASTERKEY,
                    true)) {
                FAIL("credential set", "invalid master credential")
            }

            if (CREDTYPE_HD == credSet.mastercredential().type()) {
                haveHD = true;
            }

            if (credSet.mastercredential().id() != credSet.masterid()) {
                FAIL2(
                    "credential set",
                    "wrong master credential",
                    credSet.mastercredential().id())
            }

            if (0 < credSet.activechildids_size()) {
                FAIL2(
                    "credential set",
                    "active credential IDs included in full mode",
                    credSet.activechildids_size())
            }

            if (0 < credSet.revokedchildids_size()) {
                FAIL2(
                    "credential set",
                    "revoked credential IDs included in full mode",
                    credSet.revokedchildids_size())
            }

            for (auto& it : credSet.activechildren()) {
                if (!Check(
                        it,
                        CredentialSetAllowedCredentials.at(credSet.version())
                            .first,
                        CredentialSetAllowedCredentials.at(credSet.version())
                            .second,
                        silent,
                        key,
                        CREDROLE_ERROR,
                        true)) {
                    FAIL("credential set", "invalid active child credential")
                }

                if (CREDTYPE_HD == it.type()) {
                    haveHD = true;
                }

                if (CREDROLE_MASTERKEY == it.role()) {
                    FAIL("credential set", "unexpected master credential")
                }
            }

            for (auto& it : credSet.revokedchildren()) {
                if (!Check(
                        it,
                        CredentialSetAllowedCredentials.at(credSet.version())
                            .first,
                        CredentialSetAllowedCredentials.at(credSet.version())
                            .second,
                        silent,
                        key,
                        CREDROLE_ERROR,
                        true)) {
                    FAIL("credential set", "invalid revoked child credential")
                }

                if (CREDTYPE_HD == it.type()) {
                    haveHD = true;
                }

                if (CREDROLE_MASTERKEY == it.role()) {
                    FAIL("credential set", "unexpected master credential")
                }
            }

            if (KEYMODE_PRIVATE == key) {
                FAIL(
                    "credential set",
                    "private credentials serialized in public form")
            } else {
                if (haveHD) {
                    if (0 < credSet.index()) {
                        FAIL("credential set", "index present in public mode")
                    }
                }
            }

            break;
        default:
            FAIL2("credential set", "unknown mode", credSet.mode())
    }

    return true;
}

bool CheckProto_2(
    const CredentialSet& credSet,
    const bool silent,
    const std::string& nymID,
    const KeyMode& key,
    bool& haveHD,
    const CredentialSetMode& mode)
{
    return CheckProto_1(credSet, silent, nymID, key, haveHD, mode);
}

bool CheckProto_3(
    const CredentialSet&,
    const bool,
    const std::string&,
    const KeyMode&,
    bool&,
    const CredentialSetMode&)
{
    return false;
}
bool CheckProto_4(
    const CredentialSet&,
    const bool,
    const std::string&,
    const KeyMode&,
    bool&,
    const CredentialSetMode&)
{
    return false;
}
bool CheckProto_5(
    const CredentialSet&,
    const bool,
    const std::string&,
    const KeyMode&,
    bool&,
    const CredentialSetMode&)
{
    return false;
}
}  // namespace proto
}  // namespace opentxs
