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

#include "../../../include/verify/CredentialSet.hpp"

#include <iostream>

namespace opentxs { namespace proto
{

bool CredentialSet_1(
    const CredentialSet& serializedCredSet,
    const std::string& nymID)
{
    if (!serializedCredSet.has_nymid()) {
        std::cerr << "Verify serialized credential set failed: missing nym identifier." << std::endl;
        return false;
    }

    if (nymID != serializedCredSet.nymid()) {
        std::cerr << "Verify serialized credential set failed: wrong nym identifier." << std::endl;
        return false;
    }

    if (MIN_PLAUSIBLE_IDENTIFIER > serializedCredSet.nymid().size()) {
        std::cerr << "Verify serialized credential set failed: invalid nym identifier ("
                << serializedCredSet.nymid() << ")." << std::endl;
        return false;
    }

    if (!serializedCredSet.has_masterid()) {
        std::cerr << "Verify serialized credential set failed: missing master credential identifier." << std::endl;
        return false;
    }

    if (MIN_PLAUSIBLE_IDENTIFIER > serializedCredSet.masterid().size()) {
        std::cerr << "Verify serialized credential set failed: invalid master credential identifier ("
        << serializedCredSet.masterid() << ")." << std::endl;
        return false;
    }

    for (auto& it: serializedCredSet.activechildren()) {
        if (MIN_PLAUSIBLE_IDENTIFIER > it.size()) {
            std::cerr << "Verify serialized credential set failed: invalid child credential identifier ("
            << it.size() << ")." << std::endl;
            return false;
        }
    }

    for (auto& it: serializedCredSet.revokedchildren()) {
        if (MIN_PLAUSIBLE_IDENTIFIER > it.size()) {
            std::cerr << "Verify serialized credential set failed: invalid child credential identifier ("
            << it.size() << ")." << std::endl;
            return false;
        }
    }

    return true;
}

} // namespace proto
} // namespace opentxs
