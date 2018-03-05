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

#define PROTO_NAME "credential set"

namespace opentxs
{
namespace proto
{

bool CheckProto_1(
    const CredentialSet& input,
    const bool silent,
    const std::string& nymID,
    const KeyMode& key,
    bool& haveHD,
    const CredentialSetMode& mode)
{
    if (!input.has_nymid()) {
        FAIL("credential set", "missing nym id")
    }

    if (nymID != input.nymid()) {
        FAIL("credential set", "wrong nym id")
    }

    if (MIN_PLAUSIBLE_IDENTIFIER > input.nymid().size()) {
        FAIL2("credential set", "invalid nym id", input.nymid())
    }

    if (!input.has_masterid()) {
        FAIL("credential set", "missing master credential id")
    }

    if (MIN_PLAUSIBLE_IDENTIFIER > input.masterid().size()) {
        FAIL2(
            "credential set", "invalid master credential id", input.masterid())
    }

    if (!input.has_mode()) {
        FAIL("credential set", "missing mode")
    }

    const bool checkMode = (CREDSETMODE_ERROR != mode);

    if (checkMode) {
        if (input.mode() != mode) {
            FAIL2("credential set", "incorrect mode", input.mode())
        }
    }

    switch (input.mode()) {
        case CREDSETMODE_INDEX:
            if (KEYMODE_PRIVATE == key) {
                if (1 > input.index()) {
                    FAIL("credential set", "missing index")
                }
            } else {
                if (0 < input.index()) {
                    FAIL("credential set", "index present in public mode")
                }
            }

            if (input.has_mastercredential()) {
                FAIL(
                    "credential set",
                    "full master credential included in index mode")
            }

            if (0 < input.activechildren_size()) {
                FAIL2(
                    "credential set",
                    "full active credentials included in index mode",
                    input.activechildren_size())
            }

            if (0 < input.revokedchildren_size()) {
                FAIL2(
                    "credential set",
                    "full revoked credentials included in index mode",
                    input.revokedchildren_size())
            }

            for (auto& it : input.activechildids()) {
                if (MIN_PLAUSIBLE_IDENTIFIER > it.size()) {
                    FAIL2(
                        "credential set",
                        "invalid active child credential identifier",
                        it)
                }
            }

            for (auto& it : input.revokedchildids()) {
                if (MIN_PLAUSIBLE_IDENTIFIER > it.size()) {
                    FAIL2(
                        "credential set",
                        "invalid revoked child credential identifier",
                        it)
                }
            }
            break;
        case CREDSETMODE_FULL:
            if (!input.has_mastercredential()) {
                FAIL("credential set", "missing master credential")
            }

            if (!Check(
                    input.mastercredential(),
                    CredentialSetAllowedCredentials.at(input.version()).first,
                    CredentialSetAllowedCredentials.at(input.version()).second,
                    silent,
                    key,
                    CREDROLE_MASTERKEY,
                    true)) {
                FAIL("credential set", "invalid master credential")
            }

            if (CREDTYPE_HD == input.mastercredential().type()) {
                haveHD = true;
            }

            if (input.mastercredential().id() != input.masterid()) {
                FAIL2(
                    "credential set",
                    "wrong master credential",
                    input.mastercredential().id())
            }

            if (0 < input.activechildids_size()) {
                FAIL2(
                    "credential set",
                    "active credential IDs included in full mode",
                    input.activechildids_size())
            }

            if (0 < input.revokedchildids_size()) {
                FAIL2(
                    "credential set",
                    "revoked credential IDs included in full mode",
                    input.revokedchildids_size())
            }

            for (auto& it : input.activechildren()) {
                if (!Check(
                        it,
                        CredentialSetAllowedCredentials.at(input.version())
                            .first,
                        CredentialSetAllowedCredentials.at(input.version())
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

            for (auto& it : input.revokedchildren()) {
                if (!Check(
                        it,
                        CredentialSetAllowedCredentials.at(input.version())
                            .first,
                        CredentialSetAllowedCredentials.at(input.version())
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
                    if (0 < input.index()) {
                        FAIL("credential set", "index present in public mode")
                    }
                }
            }

            break;
        default:
            FAIL2("credential set", "unknown mode", input.mode())
    }

    return true;
}

bool CheckProto_2(
    const CredentialSet& input,
    const bool silent,
    const std::string& nymID,
    const KeyMode& key,
    bool& haveHD,
    const CredentialSetMode& mode)
{
    return CheckProto_1(input, silent, nymID, key, haveHD, mode);
}

bool CheckProto_3(
    const CredentialSet& input,
    const bool silent,
    const std::string& nymID,
    const KeyMode& key,
    bool& haveHD,
    const CredentialSetMode& mode)
{
    return CheckProto_1(input, silent, nymID, key, haveHD, mode);
}

bool CheckProto_4(
    const CredentialSet& input,
    const bool silent,
    const std::string& nymID,
    const KeyMode& key,
    bool& haveHD,
    const CredentialSetMode& mode)
{
    return CheckProto_1(input, silent, nymID, key, haveHD, mode);
}

bool CheckProto_5(
    const CredentialSet& input,
    const bool silent,
    const std::string&,
    const KeyMode&,
    bool&,
    const CredentialSetMode&)
{
    UNDEFINED_VERSION("credential set", 5)
}

bool CheckProto_6(
    const CredentialSet& input,
    const bool silent,
    const std::string&,
    const KeyMode&,
    bool&,
    const CredentialSetMode&)
{
    UNDEFINED_VERSION2(6)
}

bool CheckProto_7(
    const CredentialSet& input,
    const bool silent,
    const std::string&,
    const KeyMode&,
    bool&,
    const CredentialSetMode&)
{
    UNDEFINED_VERSION2(7)
}

bool CheckProto_8(
    const CredentialSet& input,
    const bool silent,
    const std::string&,
    const KeyMode&,
    bool&,
    const CredentialSetMode&)
{
    UNDEFINED_VERSION2(8)
}

bool CheckProto_9(
    const CredentialSet& input,
    const bool silent,
    const std::string&,
    const KeyMode&,
    bool&,
    const CredentialSetMode&)
{
    UNDEFINED_VERSION2(9)
}

bool CheckProto_10(
    const CredentialSet& input,
    const bool silent,
    const std::string&,
    const KeyMode&,
    bool&,
    const CredentialSetMode&)
{
    UNDEFINED_VERSION2(10)
}

bool CheckProto_11(
    const CredentialSet& input,
    const bool silent,
    const std::string&,
    const KeyMode&,
    bool&,
    const CredentialSetMode&)
{
    UNDEFINED_VERSION2(11)
}

bool CheckProto_12(
    const CredentialSet& input,
    const bool silent,
    const std::string&,
    const KeyMode&,
    bool&,
    const CredentialSetMode&)
{
    UNDEFINED_VERSION2(12)
}

bool CheckProto_13(
    const CredentialSet& input,
    const bool silent,
    const std::string&,
    const KeyMode&,
    bool&,
    const CredentialSetMode&)
{
    UNDEFINED_VERSION2(13)
}

bool CheckProto_14(
    const CredentialSet& input,
    const bool silent,
    const std::string&,
    const KeyMode&,
    bool&,
    const CredentialSetMode&)
{
    UNDEFINED_VERSION2(14)
}

bool CheckProto_15(
    const CredentialSet& input,
    const bool silent,
    const std::string&,
    const KeyMode&,
    bool&,
    const CredentialSetMode&)
{
    UNDEFINED_VERSION2(15)
}

bool CheckProto_16(
    const CredentialSet& input,
    const bool silent,
    const std::string&,
    const KeyMode&,
    bool&,
    const CredentialSetMode&)
{
    UNDEFINED_VERSION2(16)
}

bool CheckProto_17(
    const CredentialSet& input,
    const bool silent,
    const std::string&,
    const KeyMode&,
    bool&,
    const CredentialSetMode&)
{
    UNDEFINED_VERSION2(17)
}

bool CheckProto_18(
    const CredentialSet& input,
    const bool silent,
    const std::string&,
    const KeyMode&,
    bool&,
    const CredentialSetMode&)
{
    UNDEFINED_VERSION2(18)
}

bool CheckProto_19(
    const CredentialSet& input,
    const bool silent,
    const std::string&,
    const KeyMode&,
    bool&,
    const CredentialSetMode&)
{
    UNDEFINED_VERSION2(19)
}

bool CheckProto_20(
    const CredentialSet& input,
    const bool silent,
    const std::string&,
    const KeyMode&,
    bool&,
    const CredentialSetMode&)
{
    UNDEFINED_VERSION2(20)
}
}  // namespace proto
}  // namespace opentxs
