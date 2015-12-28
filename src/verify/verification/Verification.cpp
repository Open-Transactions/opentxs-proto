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

#include "opentxs-proto/verify/Verification.hpp"

#include <iostream>

namespace opentxs { namespace proto
{

bool Verify(
        const Verification& verification,
        const uint32_t minVersion,
        const uint32_t maxVersion)
{
    if (!verification.has_version()) {
        std::cerr << "Verify serialized verification failed: missing version." << std::endl;
        return false;
    }

    uint32_t version = verification.version();

    if ((version < minVersion) || (version > maxVersion)) {
        std::cerr << "Verify serialized verification failed: incorrect version ("
              << verification.version() << ")." << std::endl;
        return false;
    }

    switch (version) {
        case 1 :
            return Verification_1(verification);
        default :
            std::cerr << "Verify serialized verification failed: unknown version ("
                  << verification.version() << ")." << std::endl;

            return false;
    }
    return true;
}

} // namespace proto
} // namespace opentxs
