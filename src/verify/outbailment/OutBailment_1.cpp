// Copyright (c) 2018 The Open-Transactions developers
// This Source Code Form is subject to the terms of the Mozilla Public
// License, v. 2.0. If a copy of the MPL was not distributed with this
// file, You can obtain one at http://mozilla.org/MPL/2.0/.

#include "opentxs-proto/Types.hpp"
#include "opentxs-proto/Check.hpp"

#define PROTO_NAME "outbailment"

namespace opentxs
{
namespace proto
{

bool CheckProto_1(const OutBailment& input, const bool silent)
{
    if (!input.has_unitid()) { FAIL_1("missing unit id") }

    if (MIN_PLAUSIBLE_IDENTIFIER > input.unitid().size()) {
        FAIL_2("invalid unit id", input.unitid())
    }

    if (MAX_PLAUSIBLE_IDENTIFIER < input.unitid().size()) {
        FAIL_2("invalid unit id", input.unitid())
    }

    if (!input.has_serverid()) { FAIL_1("missing server id") }

    if (MIN_PLAUSIBLE_IDENTIFIER > input.serverid().size()) {
        FAIL_2("invalid server id", input.serverid())
    }

    if (MAX_PLAUSIBLE_IDENTIFIER < input.serverid().size()) {
        FAIL_2("invalid server id", input.serverid())
    }

    if (!input.has_amount()) { FAIL_1("missing amount") }

    if (!input.has_instructions()) { FAIL_1("missing instructions") }

    CHECK_NONE(payment)

    return true;
}

bool CheckProto_2(const OutBailment& input, const bool silent)
{

    return CheckProto_1(input, silent);
}

bool CheckProto_3(const OutBailment& input, const bool silent)
{

    return CheckProto_1(input, silent);
}

bool CheckProto_4(const OutBailment& input, const bool silent)
{

    return CheckProto_1(input, silent);
}

bool CheckProto_5(const OutBailment& input, const bool silent)
{
    if (!input.has_unitid()) { FAIL_1("missing unit id") }

    if (MIN_PLAUSIBLE_IDENTIFIER > input.unitid().size()) {
        FAIL_2("invalid unit id", input.unitid())
    }

    if (MAX_PLAUSIBLE_IDENTIFIER < input.unitid().size()) {
        FAIL_2("invalid unit id", input.unitid())
    }

    if (!input.has_serverid()) { FAIL_1("missing server id") }

    if (MIN_PLAUSIBLE_IDENTIFIER > input.serverid().size()) {
        FAIL_2("invalid server id", input.serverid())
    }

    if (MAX_PLAUSIBLE_IDENTIFIER < input.serverid().size()) {
        FAIL_2("invalid server id", input.serverid())
    }

    if (!input.has_amount()) { FAIL_1("missing amount") }

    if (!input.has_instructions()) { FAIL_1("missing instructions") }

    return true;
}

bool CheckProto_6(const OutBailment& input, const bool silent)
{
    UNDEFINED_VERSION(6)
}

bool CheckProto_7(const OutBailment& input, const bool silent)
{
    UNDEFINED_VERSION(7)
}

bool CheckProto_8(const OutBailment& input, const bool silent)
{
    UNDEFINED_VERSION(8)
}

bool CheckProto_9(const OutBailment& input, const bool silent)
{
    UNDEFINED_VERSION(9)
}

bool CheckProto_10(const OutBailment& input, const bool silent)
{
    UNDEFINED_VERSION(10)
}

bool CheckProto_11(const OutBailment& input, const bool silent)
{
    UNDEFINED_VERSION(11)
}

bool CheckProto_12(const OutBailment& input, const bool silent)
{
    UNDEFINED_VERSION(12)
}

bool CheckProto_13(const OutBailment& input, const bool silent)
{
    UNDEFINED_VERSION(13)
}

bool CheckProto_14(const OutBailment& input, const bool silent)
{
    UNDEFINED_VERSION(14)
}

bool CheckProto_15(const OutBailment& input, const bool silent)
{
    UNDEFINED_VERSION(15)
}

bool CheckProto_16(const OutBailment& input, const bool silent)
{
    UNDEFINED_VERSION(16)
}

bool CheckProto_17(const OutBailment& input, const bool silent)
{
    UNDEFINED_VERSION(17)
}

bool CheckProto_18(const OutBailment& input, const bool silent)
{
    UNDEFINED_VERSION(18)
}

bool CheckProto_19(const OutBailment& input, const bool silent)
{
    UNDEFINED_VERSION(19)
}

bool CheckProto_20(const OutBailment& input, const bool silent)
{
    UNDEFINED_VERSION(20)
}
}  // namespace proto
}  // namespace opentxs
