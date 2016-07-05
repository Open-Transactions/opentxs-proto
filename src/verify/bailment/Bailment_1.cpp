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

#include "opentxs-proto/verify/Bailment.hpp"

#include <iostream>

namespace opentxs { namespace proto
{

bool CheckProto_1(
    const Bailment& bailment)
{
    if (!bailment.has_unitid()) {
        std::cerr << "Verify bailment failed: missing unit id."
                  << std::endl;
        return false;
    }

    if (MIN_PLAUSIBLE_IDENTIFIER > bailment.unitid().size()) {
        std::cerr << "Verify bailment failed: invalid unit id ("
                << bailment.unitid() << ")." << std::endl;
        return false;
    }

    if (MAX_PLAUSIBLE_IDENTIFIER < bailment.unitid().size()) {
        std::cerr << "Verify bailment failed: invalid unit id ("
                << bailment.unitid() << ")." << std::endl;
        return false;
    }

    if (!bailment.has_serverid()) {
        std::cerr << "Verify bailment failed: missing server id."
                  << std::endl;
        return false;
    }

    if (MIN_PLAUSIBLE_IDENTIFIER > bailment.serverid().size()) {
        std::cerr << "Verify bailment failed: invalid server id ("
                << bailment.serverid() << ")." << std::endl;
        return false;
    }

    if (MAX_PLAUSIBLE_IDENTIFIER < bailment.serverid().size()) {
        std::cerr << "Verify bailment failed: invalid server id ("
                << bailment.serverid() << ")." << std::endl;
        return false;
    }

    return true;
}

} // namespace proto
} // namespace opentxs
