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

bool CheckProto_1(const CredentialIndex& index, const bool silent)
{
    bool validSource = false;

    if (!index.has_nymid()) {
        FAIL("credential index", "missing nym id")
    }

    if (MIN_PLAUSIBLE_IDENTIFIER > index.nymid().size()) {
        FAIL2("credential index", "invalid nym id", index.nymid())
    }

    if (!index.has_mode()) {
        FAIL("credential index", "missing mode")
    }

    const auto actualMode = index.mode();

    if (!index.has_revision()) {
        FAIL("credential index", "missing revision")
    }

    if (1 > index.revision()) {
        FAIL2("credential index", "invalid revision", index.revision())
    }

    if (!index.has_source()) {
        FAIL("credential index", "missing nym id source")
    }

    validSource = Check(
        index.source(),
        CredentialIndexAllowedNymIDSource.at(index.version()).first,
        CredentialIndexAllowedNymIDSource.at(index.version()).second,
        silent);

    if (!validSource) {
        FAIL("credential index", "invalid nym id source")
    }

    bool haveHD = false;

    for (auto& it : index.activecredentials()) {
        if (!Check(
                it,
                CredentialIndexAllowedCredentialSets.at(index.version()).first,
                CredentialIndexAllowedCredentialSets.at(index.version()).second,
                silent,
                index.nymid(),
                (CREDINDEX_PRIVATE == actualMode) ? KEYMODE_PRIVATE
                                                  : KEYMODE_PUBLIC,
                haveHD)) {
            FAIL("credential index", "invalid credential set")
        }
    }

    for (auto& it : index.revokedcredentials()) {
        if (!Check(
                it,
                CredentialIndexAllowedCredentialSets.at(index.version()).first,
                CredentialIndexAllowedCredentialSets.at(index.version()).second,
                silent,
                index.nymid(),
                (CREDINDEX_PRIVATE == actualMode) ? KEYMODE_PRIVATE
                                                  : KEYMODE_PUBLIC,
                haveHD)) {
            FAIL("credential index", "invalid credential set")
        }
    }

    switch (actualMode) {
        case (CREDINDEX_PRIVATE): {
            if (haveHD) {
                if (1 > index.index()) {
                    FAIL("credential index", "missing index")
                }
            }

            break;
        }
        case (CREDINDEX_PUBLIC): {
            if (index.has_index()) {
                FAIL("credential index", "index present in public mode")
            }

            break;
        }
        default: {
            FAIL2("credential index", "invalid mode", actualMode)
        }
    }

    return true;
}

bool CheckProto_2(const CredentialIndex& index, const bool silent)
{
    return CheckProto_1(index, silent);
}

bool CheckProto_3(const CredentialIndex&, const bool) { return false; }
bool CheckProto_4(const CredentialIndex&, const bool) { return false; }
bool CheckProto_5(const CredentialIndex&, const bool) { return false; }
}  // namespace proto
}  // namespace opentxs
