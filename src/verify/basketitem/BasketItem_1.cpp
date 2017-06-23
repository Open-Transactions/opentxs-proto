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

#include "opentxs-proto/Types.hpp"
#include "opentxs-proto/Check.hpp"

#include <iostream>

namespace opentxs
{
namespace proto
{

bool CheckProto_1(const BasketItem& item, const bool silent, BasketItemMap& map)
{
    if (!item.has_weight()) {
        FAIL("basket item", "missing weight")
    }

    if (!item.has_unit()) {
        FAIL("basket item", "missing unit")
    }

    if (MIN_PLAUSIBLE_IDENTIFIER > item.unit().size()) {
        FAIL2("basket item", "invalid unit", item.unit())
    }

    map[item.unit()] += 1;

    if (!item.has_account()) {
        FAIL("basket item", "missing account")
    }

    if (MIN_PLAUSIBLE_IDENTIFIER > item.account().size()) {
        FAIL2("basket item", "invalid account", item.account())
    }

    return true;
}
bool CheckProto_2(const BasketItem&, const bool, BasketItemMap&)
{
    return false;
}
bool CheckProto_3(const BasketItem&, const bool, BasketItemMap&)
{
    return false;
}
bool CheckProto_4(const BasketItem&, const bool, BasketItemMap&)
{
    return false;
}
bool CheckProto_5(const BasketItem&, const bool, BasketItemMap&)
{
    return false;
}
}  // namespace proto
}  // namespace opentxs
