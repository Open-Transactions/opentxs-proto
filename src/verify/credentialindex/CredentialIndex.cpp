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

#include "../../../include/verify/CredentialIndex.hpp"

#include <iostream>

namespace opentxs { namespace proto
{

bool Verify(
        const CredentialIndex& serializedCredIndex)
{
    if (!serializedCredIndex.has_version()) {
        std::cerr << "Verify serialized credential index failed: missing version." << std::endl;
        return false;
    }

    switch (serializedCredIndex.version()) {
        case 1 :

            return CredentialIndex_1(serializedCredIndex);
        default :
            std::cerr << "Verify serialized credential index failed: unknown version ("
                      << serializedCredIndex.version() << ")." << std::endl;

            return false;
    }
    return true;
}

} // namespace proto
} // namespace opentxs
