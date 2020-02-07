// Copyright (c) 2020 The Open-Transactions developers
// This Source Code Form is subject to the terms of the Mozilla Public
// License, v. 2.0. If a copy of the MPL was not distributed with this
// file, You can obtain one at http://mozilla.org/MPL/2.0/.

#include "opentxs-proto/Types.hpp"
#include "verify/Check.hpp"

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
    if (!input.has_weight()) { FAIL_1("missing weight") }

    if (!input.has_unit()) { FAIL_1("missing unit") }

    if (MIN_PLAUSIBLE_IDENTIFIER > input.unit().size()) {
        FAIL_2("invalid unit", input.unit())
    }

    map[input.unit()] += 1;

    if (!input.has_account()) { FAIL_1("missing account") }

    if (MIN_PLAUSIBLE_IDENTIFIER > input.account().size()) {
        FAIL_2("invalid account", input.account())
    }

    return true;
}

bool CheckProto_2(const BasketItem& input, const bool silent, BasketItemMap&)
{
    UNDEFINED_VERSION(2)
}

bool CheckProto_3(const BasketItem& input, const bool silent, BasketItemMap&)
{
    UNDEFINED_VERSION(3)
}

bool CheckProto_4(const BasketItem& input, const bool silent, BasketItemMap&)
{
    UNDEFINED_VERSION(4)
}

bool CheckProto_5(const BasketItem& input, const bool silent, BasketItemMap&)
{
    UNDEFINED_VERSION(5)
}

bool CheckProto_6(const BasketItem& input, const bool silent, BasketItemMap&)
{
    UNDEFINED_VERSION(6)
}

bool CheckProto_7(const BasketItem& input, const bool silent, BasketItemMap&)
{
    UNDEFINED_VERSION(7)
}

bool CheckProto_8(const BasketItem& input, const bool silent, BasketItemMap&)
{
    UNDEFINED_VERSION(8)
}

bool CheckProto_9(const BasketItem& input, const bool silent, BasketItemMap&)
{
    UNDEFINED_VERSION(9)
}

bool CheckProto_10(const BasketItem& input, const bool silent, BasketItemMap&)
{
    UNDEFINED_VERSION(10)
}

bool CheckProto_11(const BasketItem& input, const bool silent, BasketItemMap&)
{
    UNDEFINED_VERSION(11)
}

bool CheckProto_12(const BasketItem& input, const bool silent, BasketItemMap&)
{
    UNDEFINED_VERSION(12)
}

bool CheckProto_13(const BasketItem& input, const bool silent, BasketItemMap&)
{
    UNDEFINED_VERSION(13)
}

bool CheckProto_14(const BasketItem& input, const bool silent, BasketItemMap&)
{
    UNDEFINED_VERSION(14)
}

bool CheckProto_15(const BasketItem& input, const bool silent, BasketItemMap&)
{
    UNDEFINED_VERSION(15)
}

bool CheckProto_16(const BasketItem& input, const bool silent, BasketItemMap&)
{
    UNDEFINED_VERSION(16)
}

bool CheckProto_17(const BasketItem& input, const bool silent, BasketItemMap&)
{
    UNDEFINED_VERSION(17)
}

bool CheckProto_18(const BasketItem& input, const bool silent, BasketItemMap&)
{
    UNDEFINED_VERSION(18)
}

bool CheckProto_19(const BasketItem& input, const bool silent, BasketItemMap&)
{
    UNDEFINED_VERSION(19)
}

bool CheckProto_20(const BasketItem& input, const bool silent, BasketItemMap&)
{
    UNDEFINED_VERSION(20)
}
}  // namespace proto
}  // namespace opentxs
