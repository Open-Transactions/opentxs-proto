// Copyright (c) 2018 The Open-Transactions developers
// This Source Code Form is subject to the terms of the Mozilla Public
// License, v. 2.0. If a copy of the MPL was not distributed with this
// file, You can obtain one at http://mozilla.org/MPL/2.0/.

#include "opentxs-proto/Types.hpp"
#include "opentxs-proto/Check.hpp"

#include <iostream>

#define PROTO_NAME "basket item"

namespace opentxs
{
namespace proto
{

bool CheckProto_1(
    const BasketItem& input,
    const bool silent,
    BasketItemMap& map)
{
    if (!input.has_weight()) {
        FAIL("basket item", "missing weight")
    }

    if (!input.has_unit()) {
        FAIL("basket item", "missing unit")
    }

    if (MIN_PLAUSIBLE_IDENTIFIER > input.unit().size()) {
        FAIL2("basket item", "invalid unit", input.unit())
    }

    map[input.unit()] += 1;

    if (!input.has_account()) {
        FAIL("basket item", "missing account")
    }

    if (MIN_PLAUSIBLE_IDENTIFIER > input.account().size()) {
        FAIL2("basket item", "invalid account", input.account())
    }

    return true;
}

bool CheckProto_2(const BasketItem& input, const bool silent, BasketItemMap&)
{
    UNDEFINED_VERSION("basket item", 2)
}

bool CheckProto_3(const BasketItem& input, const bool silent, BasketItemMap&)
{
    UNDEFINED_VERSION("basket item", 3)
}

bool CheckProto_4(const BasketItem& input, const bool silent, BasketItemMap&)
{
    UNDEFINED_VERSION("basket item", 4)
}

bool CheckProto_5(const BasketItem& input, const bool silent, BasketItemMap&)
{
    UNDEFINED_VERSION("basket item", 5)
}

bool CheckProto_6(const BasketItem& input, const bool silent, BasketItemMap&)
{
    UNDEFINED_VERSION2(6)
}

bool CheckProto_7(const BasketItem& input, const bool silent, BasketItemMap&)
{
    UNDEFINED_VERSION2(7)
}

bool CheckProto_8(const BasketItem& input, const bool silent, BasketItemMap&)
{
    UNDEFINED_VERSION2(8)
}

bool CheckProto_9(const BasketItem& input, const bool silent, BasketItemMap&)
{
    UNDEFINED_VERSION2(9)
}

bool CheckProto_10(const BasketItem& input, const bool silent, BasketItemMap&)
{
    UNDEFINED_VERSION2(10)
}

bool CheckProto_11(const BasketItem& input, const bool silent, BasketItemMap&)
{
    UNDEFINED_VERSION2(11)
}

bool CheckProto_12(const BasketItem& input, const bool silent, BasketItemMap&)
{
    UNDEFINED_VERSION2(12)
}

bool CheckProto_13(const BasketItem& input, const bool silent, BasketItemMap&)
{
    UNDEFINED_VERSION2(13)
}

bool CheckProto_14(const BasketItem& input, const bool silent, BasketItemMap&)
{
    UNDEFINED_VERSION2(14)
}

bool CheckProto_15(const BasketItem& input, const bool silent, BasketItemMap&)
{
    UNDEFINED_VERSION2(15)
}

bool CheckProto_16(const BasketItem& input, const bool silent, BasketItemMap&)
{
    UNDEFINED_VERSION2(16)
}

bool CheckProto_17(const BasketItem& input, const bool silent, BasketItemMap&)
{
    UNDEFINED_VERSION2(17)
}

bool CheckProto_18(const BasketItem& input, const bool silent, BasketItemMap&)
{
    UNDEFINED_VERSION2(18)
}

bool CheckProto_19(const BasketItem& input, const bool silent, BasketItemMap&)
{
    UNDEFINED_VERSION2(19)
}

bool CheckProto_20(const BasketItem& input, const bool silent, BasketItemMap&)
{
    UNDEFINED_VERSION2(20)
}
}  // namespace proto
}  // namespace opentxs
