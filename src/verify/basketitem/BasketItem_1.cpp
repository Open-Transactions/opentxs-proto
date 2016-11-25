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
 *       -- Scripted smart items.
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

#include <iostream>

#include "opentxs-proto/verify/BasketItem.hpp"

 namespace opentxs { namespace proto
{

bool CheckProto_1(
    const BasketItem& item,
    BasketItemMap& map)
{
    if (!item.has_weight()) {
        std::cerr << __FUNCTION__
                  << ": Verify basket item failed: missing weight."
                  << std::endl;

        return false;
    }

    if (!item.has_unit()) {
        std::cerr << __FUNCTION__
                  << ": Verify basket item failed: missing unit."
                  << std::endl;

        return false;
    }

    if (MIN_PLAUSIBLE_IDENTIFIER > item.unit().size()) {
        std::cerr << __FUNCTION__
                  << ": Verify basket item failed: invalid unit ("
                  << item.unit() << ")." << std::endl;

        return false;
    }

    map[item.unit()] += 1;

    if (!item.has_account()) {
        std::cerr << __FUNCTION__
                  << ": Verify basket item failed: missing account."
                  << std::endl;

        return false;
    }

    if (MIN_PLAUSIBLE_IDENTIFIER > item.account().size()) {
        std::cerr << __FUNCTION__
                  << ": Verify basket item failed: invalid account ("
                  << item.account() << ")." << std::endl;

        return false;
    }

    return true;
}
bool CheckProto_2(const BasketItem&, BasketItemMap&) { return false; }
} // namespace proto
} // namespace opentxs
