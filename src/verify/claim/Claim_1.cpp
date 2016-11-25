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

#include "opentxs-proto/verify/Claim.hpp"

#include <iostream>

namespace opentxs { namespace proto
{

bool CheckProto_1(
    const Claim& claim)
{
    if (!claim.has_nymid()) {
        std::cerr << "Verify serialized claim failed: missing nym id." << std::endl;
        return false;
    }
    if (!claim.has_section()) {
        std::cerr << "Verify serialized claim failed: missing section." << std::endl;
        return false;
    }
    if (!claim.has_type()) {
        std::cerr << "Verify serialized claim failed: missing type." << std::endl;
        return false;
    }
    if (!claim.has_start()) {
        std::cerr << "Verify serialized claim failed: missing start." << std::endl;
        return false;
    }
    if (!claim.has_end()) {
        std::cerr << "Verify serialized claim failed: missing end." << std::endl;
        return false;
    }
    if (!claim.has_value()) {
        std::cerr << "Verify serialized claim failed: missing value." << std::endl;
        return false;
    }
    if (claim.start() > claim.end()) {
        std::cerr << "Verify serialized claim failed: invalid interval." << std::endl;
        return false;
    }

    return true;
}
bool CheckProto_2(const Claim&) { return false; }
} // namespace proto
} // namespace opentxs
