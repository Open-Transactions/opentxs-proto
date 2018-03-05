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

#ifndef OPENTXS_PROTO_BASKETITEM_HPP
#define OPENTXS_PROTO_BASKETITEM_HPP

#include <map>

#include "VerifyContracts.hpp"

namespace opentxs
{
namespace proto
{
typedef std::map<std::string, uint64_t> BasketItemMap;

bool CheckProto_1(
    const BasketItem& item,
    const bool silent,
    BasketItemMap& map);
bool CheckProto_2(const BasketItem&, const bool, BasketItemMap&);
bool CheckProto_3(const BasketItem&, const bool, BasketItemMap&);
bool CheckProto_4(const BasketItem&, const bool, BasketItemMap&);
bool CheckProto_5(const BasketItem&, const bool, BasketItemMap&);
bool CheckProto_6(const BasketItem&, const bool, BasketItemMap&);
bool CheckProto_7(const BasketItem&, const bool, BasketItemMap&);
bool CheckProto_8(const BasketItem&, const bool, BasketItemMap&);
bool CheckProto_9(const BasketItem&, const bool, BasketItemMap&);
bool CheckProto_10(const BasketItem&, const bool, BasketItemMap&);
bool CheckProto_11(const BasketItem&, const bool, BasketItemMap&);
bool CheckProto_12(const BasketItem&, const bool, BasketItemMap&);
bool CheckProto_13(const BasketItem&, const bool, BasketItemMap&);
bool CheckProto_14(const BasketItem&, const bool, BasketItemMap&);
bool CheckProto_15(const BasketItem&, const bool, BasketItemMap&);
bool CheckProto_16(const BasketItem&, const bool, BasketItemMap&);
bool CheckProto_17(const BasketItem&, const bool, BasketItemMap&);
bool CheckProto_18(const BasketItem&, const bool, BasketItemMap&);
bool CheckProto_19(const BasketItem&, const bool, BasketItemMap&);
bool CheckProto_20(const BasketItem&, const bool, BasketItemMap&);
}  // namespace proto
}  // namespace opentxs

#endif  // OPENTXS_PROTO_BASKETITEM_HPP
