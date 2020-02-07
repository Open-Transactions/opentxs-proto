// Copyright (c) 2020 The Open-Transactions developers
// This Source Code Form is subject to the terms of the Mozilla Public
// License, v. 2.0. If a copy of the MPL was not distributed with this
// file, You can obtain one at http://mozilla.org/MPL/2.0/.

#include "opentxs-proto/Types.hpp"
#include "verify/Check.hpp"

#include <chrono>

#define PROTO_NAME "purse"

namespace opentxs
{
namespace proto
{
bool CheckProto_1(const Purse& input, const bool silent)
{
    std::int64_t value{};

    return CheckProto_1(input, silent, value);
}

bool CheckProto_1(const Purse& input, const bool silent, std::int64_t& value)
{
    switch (input.type()) {
        case CASHTYPE_LUCRE: {
        } break;
        case CASHTYPE_ERROR:
        default: {
            FAIL_2("Invalid type", std::to_string(input.type()));
        }
    }

    auto allowedStates = std::set<TokenState>{};
    auto validFrom = std::int64_t{std::chrono::system_clock::to_time_t(
        std::chrono::system_clock::time_point::min())};
    auto validTo = std::int64_t{std::chrono::system_clock::to_time_t(
        std::chrono::system_clock::time_point::max())};

    switch (input.state()) {
        case PURSETYPE_REQUEST: {
            allowedStates.insert(TOKENSTATE_BLINDED);

            CHECK_SUBOBJECT(secondarykey, PurseAllowedSymmetricKey());
            CHECK_SUBOBJECT(secondarypassword, PurseAllowedEnvelope());
        } break;
        case PURSETYPE_ISSUE: {
            allowedStates.insert(TOKENSTATE_SIGNED);

            CHECK_SUBOBJECT(secondarykey, PurseAllowedSymmetricKey());
            CHECK_SUBOBJECT(secondarypassword, PurseAllowedEnvelope());
        } break;
        case PURSETYPE_NORMAL: {
            allowedStates.insert(TOKENSTATE_READY);
            allowedStates.insert(TOKENSTATE_SPENT);
            allowedStates.insert(TOKENSTATE_EXPIRED);

            CHECK_EXCLUDED(secondarykey);
            CHECK_EXCLUDED(secondarypassword);
        } break;
        case PURSETYPE_ERROR:
        default: {
            FAIL_2("Invalid state", std::to_string(input.state()));
        }
    }

    CHECK_IDENTIFIER(notary);
    CHECK_IDENTIFIER(mint);
    OPTIONAL_SUBOBJECTS_VA(
        token,
        PurseAllowedToken(),
        input.type(),
        allowedStates,
        value,
        validFrom,
        validTo);

    if (input.totalvalue() != value) {
        FAIL_2("Incorrect value", std::to_string(input.totalvalue()));
    }

    if (input.latestvalidfrom() != validFrom) {
        FAIL_2("Incorrect valid from", std::to_string(input.latestvalidfrom()));
    }

    if (input.earliestvalidto() != validTo) {
        FAIL_2("Incorrect valid to", std::to_string(input.earliestvalidto()));
    }

    CHECK_SUBOBJECT(primarykey, PurseAllowedSymmetricKey());
    OPTIONAL_SUBOBJECTS(primarypassword, PurseAllowedEnvelope());

    return true;
}

bool CheckProto_2(const Purse& input, const bool silent)
{
    std::int64_t value{};

    return CheckProto_1(input, silent, value);
}

bool CheckProto_2(const Purse& input, const bool silent, std::int64_t& value)
{
    UNDEFINED_VERSION(2)
}

bool CheckProto_3(const Purse& input, const bool silent)
{
    std::int64_t value{};

    return CheckProto_1(input, silent, value);
}

bool CheckProto_3(const Purse& input, const bool silent, std::int64_t& value)
{
    UNDEFINED_VERSION(3)
}

bool CheckProto_4(const Purse& input, const bool silent)
{
    std::int64_t value{};

    return CheckProto_1(input, silent, value);
}

bool CheckProto_4(const Purse& input, const bool silent, std::int64_t& value)
{
    UNDEFINED_VERSION(4)
}

bool CheckProto_5(const Purse& input, const bool silent)
{
    std::int64_t value{};

    return CheckProto_1(input, silent, value);
}

bool CheckProto_5(const Purse& input, const bool silent, std::int64_t& value)
{
    UNDEFINED_VERSION(5)
}

bool CheckProto_6(const Purse& input, const bool silent)
{
    std::int64_t value{};

    return CheckProto_1(input, silent, value);
}

bool CheckProto_6(const Purse& input, const bool silent, std::int64_t& value)
{
    UNDEFINED_VERSION(6)
}

bool CheckProto_7(const Purse& input, const bool silent)
{
    std::int64_t value{};

    return CheckProto_1(input, silent, value);
}

bool CheckProto_7(const Purse& input, const bool silent, std::int64_t& value)
{
    UNDEFINED_VERSION(7)
}

bool CheckProto_8(const Purse& input, const bool silent)
{
    std::int64_t value{};

    return CheckProto_1(input, silent, value);
}

bool CheckProto_8(const Purse& input, const bool silent, std::int64_t& value)
{
    UNDEFINED_VERSION(8)
}

bool CheckProto_9(const Purse& input, const bool silent)
{
    std::int64_t value{};

    return CheckProto_1(input, silent, value);
}

bool CheckProto_9(const Purse& input, const bool silent, std::int64_t& value)
{
    UNDEFINED_VERSION(9)
}

bool CheckProto_10(const Purse& input, const bool silent)
{
    std::int64_t value{};

    return CheckProto_1(input, silent, value);
}

bool CheckProto_10(const Purse& input, const bool silent, std::int64_t& value)
{
    UNDEFINED_VERSION(10)
}

bool CheckProto_11(const Purse& input, const bool silent)
{
    std::int64_t value{};

    return CheckProto_1(input, silent, value);
}

bool CheckProto_11(const Purse& input, const bool silent, std::int64_t& value)
{
    UNDEFINED_VERSION(11)
}

bool CheckProto_12(const Purse& input, const bool silent)
{
    std::int64_t value{};

    return CheckProto_1(input, silent, value);
}

bool CheckProto_12(const Purse& input, const bool silent, std::int64_t& value)
{
    UNDEFINED_VERSION(12)
}

bool CheckProto_13(const Purse& input, const bool silent)
{
    std::int64_t value{};

    return CheckProto_1(input, silent, value);
}

bool CheckProto_13(const Purse& input, const bool silent, std::int64_t& value)
{
    UNDEFINED_VERSION(13)
}

bool CheckProto_14(const Purse& input, const bool silent)
{
    std::int64_t value{};

    return CheckProto_1(input, silent, value);
}

bool CheckProto_14(const Purse& input, const bool silent, std::int64_t& value)
{
    UNDEFINED_VERSION(14)
}

bool CheckProto_15(const Purse& input, const bool silent)
{
    std::int64_t value{};

    return CheckProto_1(input, silent, value);
}

bool CheckProto_15(const Purse& input, const bool silent, std::int64_t& value)
{
    UNDEFINED_VERSION(15)
}

bool CheckProto_16(const Purse& input, const bool silent)
{
    std::int64_t value{};

    return CheckProto_1(input, silent, value);
}

bool CheckProto_16(const Purse& input, const bool silent, std::int64_t& value)
{
    UNDEFINED_VERSION(16)
}

bool CheckProto_17(const Purse& input, const bool silent)
{
    std::int64_t value{};

    return CheckProto_1(input, silent, value);
}

bool CheckProto_17(const Purse& input, const bool silent, std::int64_t& value)
{
    UNDEFINED_VERSION(17)
}

bool CheckProto_18(const Purse& input, const bool silent)
{
    std::int64_t value{};

    return CheckProto_1(input, silent, value);
}

bool CheckProto_18(const Purse& input, const bool silent, std::int64_t& value)
{
    UNDEFINED_VERSION(18)
}

bool CheckProto_19(const Purse& input, const bool silent)
{
    std::int64_t value{};

    return CheckProto_1(input, silent, value);
}

bool CheckProto_19(const Purse& input, const bool silent, std::int64_t& value)
{
    UNDEFINED_VERSION(19)
}

bool CheckProto_20(const Purse& input, const bool silent)
{
    std::int64_t value{};

    return CheckProto_1(input, silent, value);
}

bool CheckProto_20(const Purse& input, const bool silent, std::int64_t& value)
{
    UNDEFINED_VERSION(20)
}
}  // namespace proto
}  // namespace opentxs
