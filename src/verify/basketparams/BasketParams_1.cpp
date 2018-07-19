// Copyright (c) 2018 The Open-Transactions developers
// This Source Code Form is subject to the terms of the Mozilla Public
// License, v. 2.0. If a copy of the MPL was not distributed with this
// file, You can obtain one at http://mozilla.org/MPL/2.0/.

#include "opentxs-proto/Types.hpp"
#include "opentxs-proto/Check.hpp"

#include <iostream>

#define PROTO_NAME "basket params"

namespace opentxs
{
namespace proto
{

bool CheckProto_1(const BasketParams& input, const bool silent)
{
    if (!input.has_weight()) {
        FAIL("basket params", "missing weight")
    }

    BasketItemMap itemMap;

    for (auto& item : input.item()) {
        try {
            bool validItem = Check(
                item,
                BasketParamsAllowedBasketItem.at(input.version()).first,
                BasketParamsAllowedBasketItem.at(input.version()).second,
                silent,
                itemMap);

            if (!validItem) {
                FAIL("basket params", "invalid basket")
            }
        } catch (const std::out_of_range&) {
            FAIL2(
                "basket params",
                "allowed basket item version not defined for version",
                input.version())
        }
    }

    for (auto& subcurrency : itemMap) {
        if (subcurrency.second > 1) {
            FAIL("basket params", "duplicate basket")
        }
    }

    return true;
}

bool CheckProto_2(const BasketParams& input, const bool silent)
{
    UNDEFINED_VERSION("basket params", 2)
}

bool CheckProto_3(const BasketParams& input, const bool silent)
{
    UNDEFINED_VERSION("basket params", 3)
}

bool CheckProto_4(const BasketParams& input, const bool silent)
{
    UNDEFINED_VERSION("basket params", 4)
}

bool CheckProto_5(const BasketParams& input, const bool silent)
{
    UNDEFINED_VERSION("basket params", 5)
}

bool CheckProto_6(const BasketParams& input, const bool silent)
{
    UNDEFINED_VERSION2(6)
}

bool CheckProto_7(const BasketParams& input, const bool silent)
{
    UNDEFINED_VERSION2(7)
}

bool CheckProto_8(const BasketParams& input, const bool silent)
{
    UNDEFINED_VERSION2(8)
}

bool CheckProto_9(const BasketParams& input, const bool silent)
{
    UNDEFINED_VERSION2(9)
}

bool CheckProto_10(const BasketParams& input, const bool silent)
{
    UNDEFINED_VERSION2(10)
}

bool CheckProto_11(const BasketParams& input, const bool silent)
{
    UNDEFINED_VERSION2(11)
}

bool CheckProto_12(const BasketParams& input, const bool silent)
{
    UNDEFINED_VERSION2(12)
}

bool CheckProto_13(const BasketParams& input, const bool silent)
{
    UNDEFINED_VERSION2(13)
}

bool CheckProto_14(const BasketParams& input, const bool silent)
{
    UNDEFINED_VERSION2(14)
}

bool CheckProto_15(const BasketParams& input, const bool silent)
{
    UNDEFINED_VERSION2(15)
}

bool CheckProto_16(const BasketParams& input, const bool silent)
{
    UNDEFINED_VERSION2(16)
}

bool CheckProto_17(const BasketParams& input, const bool silent)
{
    UNDEFINED_VERSION2(17)
}

bool CheckProto_18(const BasketParams& input, const bool silent)
{
    UNDEFINED_VERSION2(18)
}

bool CheckProto_19(const BasketParams& input, const bool silent)
{
    UNDEFINED_VERSION2(19)
}

bool CheckProto_20(const BasketParams& input, const bool silent)
{
    UNDEFINED_VERSION2(20)
}
}  // namespace proto
}  // namespace opentxs
