// Copyright (c) 2020 The Open-Transactions developers
// This Source Code Form is subject to the terms of the Mozilla Public
// License, v. 2.0. If a copy of the MPL was not distributed with this
// file, You can obtain one at http://mozilla.org/MPL/2.0/.

#include "opentxs-proto/Types.hpp"
#include "verify/Check.hpp"

#define PROTO_NAME "token"

#include <algorithm>

namespace opentxs
{
namespace proto
{
bool CheckProto_1(
    const Token& input,
    const bool silent,
    const CashType type,
    const std::set<TokenState>& state,
    std::int64_t& totalValue,
    std::int64_t& validFrom,
    std::int64_t& validTo)
{
    if (type != input.type()) {
        FAIL_4(
            "Incorrect type",
            std::to_string(input.state()),
            " expected ",
            std::to_string(type));
    }

    const bool haveExpectedState = false == state.empty();

    if (haveExpectedState && (0 == state.count(input.state()))) {
        FAIL_2("Incorrect state", std::to_string(input.state()));
    }

    switch (input.state()) {
        case TOKENSTATE_BLINDED:
        case TOKENSTATE_SIGNED:
        case TOKENSTATE_READY: {
            totalValue += input.denomination();
            validFrom = std::max(input.validfrom(), validFrom);
            validTo = std::min(input.validto(), validTo);
        } break;
        case TOKENSTATE_SPENT:
        case TOKENSTATE_EXPIRED: {
        } break;
        case TOKENSTATE_ERROR:
        default: {
            FAIL_2("Invalid state", std::to_string(input.state()));
        }
    }

    CHECK_IDENTIFIER(notary);
    CHECK_IDENTIFIER(mint);

    switch (input.type()) {
        case CASHTYPE_LUCRE: {
            CHECK_SUBOBJECT_VA(
                lucre, TokenAllowedLucreTokenData(), input.state());
        } break;
        case CASHTYPE_ERROR:
        default: {
            FAIL_2("Invalid type", std::to_string(input.type()));
        }
    }

    return true;
}
bool CheckProto_2(
    const Token& input,
    const bool silent,
    const CashType,
    const std::set<TokenState>&,
    std::int64_t&,
    std::int64_t&,
    std::int64_t&)
{
    UNDEFINED_VERSION(2)
}

bool CheckProto_3(
    const Token& input,
    const bool silent,
    const CashType,
    const std::set<TokenState>&,
    std::int64_t&,
    std::int64_t&,
    std::int64_t&)
{
    UNDEFINED_VERSION(3)
}

bool CheckProto_4(
    const Token& input,
    const bool silent,
    const CashType,
    const std::set<TokenState>&,
    std::int64_t&,
    std::int64_t&,
    std::int64_t&)
{
    UNDEFINED_VERSION(4)
}

bool CheckProto_5(
    const Token& input,
    const bool silent,
    const CashType,
    const std::set<TokenState>&,
    std::int64_t&,
    std::int64_t&,
    std::int64_t&)
{
    UNDEFINED_VERSION(5)
}

bool CheckProto_6(
    const Token& input,
    const bool silent,
    const CashType,
    const std::set<TokenState>&,
    std::int64_t&,
    std::int64_t&,
    std::int64_t&)
{
    UNDEFINED_VERSION(6)
}

bool CheckProto_7(
    const Token& input,
    const bool silent,
    const CashType,
    const std::set<TokenState>&,
    std::int64_t&,
    std::int64_t&,
    std::int64_t&)
{
    UNDEFINED_VERSION(7)
}

bool CheckProto_8(
    const Token& input,
    const bool silent,
    const CashType,
    const std::set<TokenState>&,
    std::int64_t&,
    std::int64_t&,
    std::int64_t&)
{
    UNDEFINED_VERSION(8)
}

bool CheckProto_9(
    const Token& input,
    const bool silent,
    const CashType,
    const std::set<TokenState>&,
    std::int64_t&,
    std::int64_t&,
    std::int64_t&)
{
    UNDEFINED_VERSION(9)
}

bool CheckProto_10(
    const Token& input,
    const bool silent,
    const CashType,
    const std::set<TokenState>&,
    std::int64_t&,
    std::int64_t&,
    std::int64_t&)
{
    UNDEFINED_VERSION(10)
}

bool CheckProto_11(
    const Token& input,
    const bool silent,
    const CashType,
    const std::set<TokenState>&,
    std::int64_t&,
    std::int64_t&,
    std::int64_t&)
{
    UNDEFINED_VERSION(11)
}

bool CheckProto_12(
    const Token& input,
    const bool silent,
    const CashType,
    const std::set<TokenState>&,
    std::int64_t&,
    std::int64_t&,
    std::int64_t&)
{
    UNDEFINED_VERSION(12)
}

bool CheckProto_13(
    const Token& input,
    const bool silent,
    const CashType,
    const std::set<TokenState>&,
    std::int64_t&,
    std::int64_t&,
    std::int64_t&)
{
    UNDEFINED_VERSION(13)
}

bool CheckProto_14(
    const Token& input,
    const bool silent,
    const CashType,
    const std::set<TokenState>&,
    std::int64_t&,
    std::int64_t&,
    std::int64_t&)
{
    UNDEFINED_VERSION(14)
}

bool CheckProto_15(
    const Token& input,
    const bool silent,
    const CashType,
    const std::set<TokenState>&,
    std::int64_t&,
    std::int64_t&,
    std::int64_t&)
{
    UNDEFINED_VERSION(15)
}

bool CheckProto_16(
    const Token& input,
    const bool silent,
    const CashType,
    const std::set<TokenState>&,
    std::int64_t&,
    std::int64_t&,
    std::int64_t&)
{
    UNDEFINED_VERSION(16)
}

bool CheckProto_17(
    const Token& input,
    const bool silent,
    const CashType,
    const std::set<TokenState>&,
    std::int64_t&,
    std::int64_t&,
    std::int64_t&)
{
    UNDEFINED_VERSION(17)
}

bool CheckProto_18(
    const Token& input,
    const bool silent,
    const CashType,
    const std::set<TokenState>&,
    std::int64_t&,
    std::int64_t&,
    std::int64_t&)
{
    UNDEFINED_VERSION(18)
}

bool CheckProto_19(
    const Token& input,
    const bool silent,
    const CashType,
    const std::set<TokenState>&,
    std::int64_t&,
    std::int64_t&,
    std::int64_t&)
{
    UNDEFINED_VERSION(19)
}

bool CheckProto_20(
    const Token& input,
    const bool silent,
    const CashType,
    const std::set<TokenState>&,
    std::int64_t&,
    std::int64_t&,
    std::int64_t&)
{
    UNDEFINED_VERSION(20)
}
}  // namespace proto
}  // namespace opentxs
