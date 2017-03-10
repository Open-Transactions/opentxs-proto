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
 *       -- Scripted smart paramss.
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

namespace opentxs { namespace proto
{

bool CheckProto_1(
    const BasketParams& params)
{
    if (!params.has_weight()) {
        std::cerr << __FUNCTION__
                  << ": Verify basket params failed: missing weight."
                  << std::endl;

        return false;
    }
    BasketItemMap itemMap;

    for (auto& item : params.item()) {
        bool validItem = Check(
            item,
            BasketParamsAllowedBasketItem.at(params.version()).first,
            BasketParamsAllowedBasketItem.at(params.version()).second,
            itemMap);

        if (!validItem) {
            std::cerr << __FUNCTION__
                      << ": Verify basket params failed: invalid basket"
                      << " item." << std::endl;

            return false;
        }
    }

    for (auto& subcurrency : itemMap) {
        if (subcurrency.second > 1) {
            std::cerr << __FUNCTION__
                      << ": Verify basket params failed: duplicate basket"
                      << " item." << std::endl;

            return false;
        }
    }

    return true;
}
bool CheckProto_2(const BasketParams&) { return false; }
bool CheckProto_3(const BasketParams&) { return false; }
bool CheckProto_4(const BasketParams&) { return false; }
bool CheckProto_5(const BasketParams&) { return false; }
} // namespace proto
} // namespace opentxs
