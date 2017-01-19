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

#include "opentxs-proto/verify/StorageItems.hpp"

#include <iostream>

namespace opentxs { namespace proto
{

bool CheckProto_1(
    const StorageItems& items)
{
    if (items.has_creds()) {
        if (MIN_PLAUSIBLE_IDENTIFIER > items.creds().size()) {
            std::cerr << "Verify serialized storage item index failed: invalid "
                      << "credentials." << std::endl;

            return false;
        }
    }

    if (items.has_nyms()) {
        if (MIN_PLAUSIBLE_IDENTIFIER > items.nyms().size()) {
            std::cerr << "Verify serialized storage item index failed: invalid "
                      << "nym list." << std::endl;

            return false;
        }
    }

    if (items.has_servers()) {
        if (MIN_PLAUSIBLE_IDENTIFIER > items.servers().size()) {
            std::cerr << "Verify serialized storage item index failed: invalid "
                      << "server list." << std::endl;

            return false;
        }
    }

    if (items.has_units()) {
        if (MIN_PLAUSIBLE_IDENTIFIER > items.units().size()) {
            std::cerr << "Verify serialized storage item index failed: invalid "
                      << "unit list." << std::endl;

            return false;
        }
    }

    if (items.has_seeds()) {
        if (MIN_PLAUSIBLE_IDENTIFIER > items.seeds().size()) {
            std::cerr << "Verify serialized storage item index failed: invalid "
                      << "seed list." << std::endl;

            return false;
        }
    }

    return true;
}
bool CheckProto_2(const StorageItems&) { return false; }
} // namespace proto
} // namespace opentxs
