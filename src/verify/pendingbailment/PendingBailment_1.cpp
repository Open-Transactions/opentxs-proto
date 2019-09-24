// Copyright (c) 2019 The Open-Transactions developers
// This Source Code Form is subject to the terms of the Mozilla Public
// License, v. 2.0. If a copy of the MPL was not distributed with this
// file, You can obtain one at http://mozilla.org/MPL/2.0/.

#include "opentxs-proto/Types.hpp"
#include "opentxs-proto/Check.hpp"

#define PROTO_NAME "pending bailment"

namespace opentxs
{
namespace proto
{

bool CheckProto_1(const PendingBailment& input, const bool silent)
{
    CHECK_IDENTIFIER(unitid)
    CHECK_IDENTIFIER(serverid)
    CHECK_IDENTIFIER(txid)
    CHECK_EXCLUDED(requestid)
    CHECK_EXCLUDED(amount)
    return true;
}

bool CheckProto_2(const PendingBailment& input, const bool silent)
{
    return CheckProto_1(input, silent);
}

bool CheckProto_3(const PendingBailment& input, const bool silent)
{
    return CheckProto_1(input, silent);
}

bool CheckProto_4(const PendingBailment& input, const bool silent)
{
    return CheckProto_1(input, silent);
}

bool CheckProto_5(const PendingBailment& input, const bool silent)
{
    CHECK_IDENTIFIER(unitid)
    CHECK_IDENTIFIER(serverid)
    CHECK_IDENTIFIER(txid)
    OPTIONAL_IDENTIFIER(requestid)
    CHECK_EXCLUDED(amount)
    return true;
}

bool CheckProto_6(const PendingBailment& input, const bool silent)
{
    CHECK_IDENTIFIER(unitid)
    CHECK_IDENTIFIER(serverid)
    CHECK_IDENTIFIER(txid)
    OPTIONAL_IDENTIFIER(requestid)
    return true;
}

bool CheckProto_7(const PendingBailment& input, const bool silent)
{
    UNDEFINED_VERSION(7)
}

bool CheckProto_8(const PendingBailment& input, const bool silent)
{
    UNDEFINED_VERSION(8)
}

bool CheckProto_9(const PendingBailment& input, const bool silent)
{
    UNDEFINED_VERSION(9)
}

bool CheckProto_10(const PendingBailment& input, const bool silent)
{
    UNDEFINED_VERSION(10)
}

bool CheckProto_11(const PendingBailment& input, const bool silent)
{
    UNDEFINED_VERSION(11)
}

bool CheckProto_12(const PendingBailment& input, const bool silent)
{
    UNDEFINED_VERSION(12)
}

bool CheckProto_13(const PendingBailment& input, const bool silent)
{
    UNDEFINED_VERSION(13)
}

bool CheckProto_14(const PendingBailment& input, const bool silent)
{
    UNDEFINED_VERSION(14)
}

bool CheckProto_15(const PendingBailment& input, const bool silent)
{
    UNDEFINED_VERSION(15)
}

bool CheckProto_16(const PendingBailment& input, const bool silent)
{
    UNDEFINED_VERSION(16)
}

bool CheckProto_17(const PendingBailment& input, const bool silent)
{
    UNDEFINED_VERSION(17)
}

bool CheckProto_18(const PendingBailment& input, const bool silent)
{
    UNDEFINED_VERSION(18)
}

bool CheckProto_19(const PendingBailment& input, const bool silent)
{
    UNDEFINED_VERSION(19)
}

bool CheckProto_20(const PendingBailment& input, const bool silent)
{
    UNDEFINED_VERSION(20)
}
}  // namespace proto
}  // namespace opentxs
