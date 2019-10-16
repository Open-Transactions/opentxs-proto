// Copyright (c) 2019 The Open-Transactions developers
// This Source Code Form is subject to the terms of the Mozilla Public
// License, v. 2.0. If a copy of the MPL was not distributed with this
// file, You can obtain one at http://mozilla.org/MPL/2.0/.

#ifndef OPENTXS_PROTO_BASKETITEM_HPP
#define OPENTXS_PROTO_BASKETITEM_HPP

#include <map>

#include "VerifyContracts.hpp"

namespace opentxs
{
namespace proto
{
typedef std::map<std::string, uint64_t> BasketItemMap;

EXPORT bool CheckProto_1(
    const BasketItem& item,
    const bool silent,
    BasketItemMap& map);
EXPORT bool CheckProto_2(const BasketItem&, const bool, BasketItemMap&);
EXPORT bool CheckProto_3(const BasketItem&, const bool, BasketItemMap&);
EXPORT bool CheckProto_4(const BasketItem&, const bool, BasketItemMap&);
EXPORT bool CheckProto_5(const BasketItem&, const bool, BasketItemMap&);
EXPORT bool CheckProto_6(const BasketItem&, const bool, BasketItemMap&);
EXPORT bool CheckProto_7(const BasketItem&, const bool, BasketItemMap&);
EXPORT bool CheckProto_8(const BasketItem&, const bool, BasketItemMap&);
EXPORT bool CheckProto_9(const BasketItem&, const bool, BasketItemMap&);
EXPORT bool CheckProto_10(const BasketItem&, const bool, BasketItemMap&);
EXPORT bool CheckProto_11(const BasketItem&, const bool, BasketItemMap&);
EXPORT bool CheckProto_12(const BasketItem&, const bool, BasketItemMap&);
EXPORT bool CheckProto_13(const BasketItem&, const bool, BasketItemMap&);
EXPORT bool CheckProto_14(const BasketItem&, const bool, BasketItemMap&);
EXPORT bool CheckProto_15(const BasketItem&, const bool, BasketItemMap&);
EXPORT bool CheckProto_16(const BasketItem&, const bool, BasketItemMap&);
EXPORT bool CheckProto_17(const BasketItem&, const bool, BasketItemMap&);
EXPORT bool CheckProto_18(const BasketItem&, const bool, BasketItemMap&);
EXPORT bool CheckProto_19(const BasketItem&, const bool, BasketItemMap&);
EXPORT bool CheckProto_20(const BasketItem&, const bool, BasketItemMap&);
}  // namespace proto
}  // namespace opentxs

#endif  // OPENTXS_PROTO_BASKETITEM_HPP
