// Copyright (c) 2018 The Open-Transactions developers
// This Source Code Form is subject to the terms of the Mozilla Public
// License, v. 2.0. If a copy of the MPL was not distributed with this
// file, You can obtain one at http://mozilla.org/MPL/2.0/.

#include "opentxs-proto/Types.hpp"
#include "opentxs-proto/Check.hpp"

#include <iostream>

#define PROTO_NAME "ConnectionInfo"

namespace opentxs
{
namespace proto
{
bool CheckProto_1(const ConnectionInfo& input, const bool silent)
{
    if (!input.has_type()) {
        FAIL("ConnectionInfo", "missing type")
    }

    if ((CONNECTIONINFO_BITCOIN > input.type()) ||
        (CONNECTIONINFO_BITMESSAGERPC < input.type())) {
        FAIL2("ConnectionInfo", "invalid type", input.type())
    }

    if (input.has_nym()) {
        FAIL("ConnectionInfo", "unexpected 'for' field present")
    }

    return true;
}

bool CheckProto_2(const ConnectionInfo& input, const bool silent)
{
    return CheckProto_1(input, silent);
}

bool CheckProto_3(const ConnectionInfo& input, const bool silent)
{
    if (!input.has_type()) {
        FAIL("ConnectionInfo", "missing type")
    }

    if ((CONNECTIONINFO_BITCOIN > input.type()) ||
        (CONNECTIONINFO_CJDNS < input.type())) {
        FAIL2("ConnectionInfo", "invalid type", input.type())
    }

    return true;
}

bool CheckProto_4(const ConnectionInfo& input, const bool silent)
{
    return CheckProto_3(input, silent);
}

bool CheckProto_5(const ConnectionInfo& input, const bool silent)
{
    UNDEFINED_VERSION("ConnectionInfo", 5)
}

bool CheckProto_6(const ConnectionInfo& input, const bool silent)
{
    UNDEFINED_VERSION2(6)
}

bool CheckProto_7(const ConnectionInfo& input, const bool silent)
{
    UNDEFINED_VERSION2(7)
}

bool CheckProto_8(const ConnectionInfo& input, const bool silent)
{
    UNDEFINED_VERSION2(8)
}

bool CheckProto_9(const ConnectionInfo& input, const bool silent)
{
    UNDEFINED_VERSION2(9)
}

bool CheckProto_10(const ConnectionInfo& input, const bool silent)
{
    UNDEFINED_VERSION2(10)
}

bool CheckProto_11(const ConnectionInfo& input, const bool silent)
{
    UNDEFINED_VERSION2(11)
}

bool CheckProto_12(const ConnectionInfo& input, const bool silent)
{
    UNDEFINED_VERSION2(12)
}

bool CheckProto_13(const ConnectionInfo& input, const bool silent)
{
    UNDEFINED_VERSION2(13)
}

bool CheckProto_14(const ConnectionInfo& input, const bool silent)
{
    UNDEFINED_VERSION2(14)
}

bool CheckProto_15(const ConnectionInfo& input, const bool silent)
{
    UNDEFINED_VERSION2(15)
}

bool CheckProto_16(const ConnectionInfo& input, const bool silent)
{
    UNDEFINED_VERSION2(16)
}

bool CheckProto_17(const ConnectionInfo& input, const bool silent)
{
    UNDEFINED_VERSION2(17)
}

bool CheckProto_18(const ConnectionInfo& input, const bool silent)
{
    UNDEFINED_VERSION2(18)
}

bool CheckProto_19(const ConnectionInfo& input, const bool silent)
{
    UNDEFINED_VERSION2(19)
}

bool CheckProto_20(const ConnectionInfo& input, const bool silent)
{
    UNDEFINED_VERSION2(20)
}
}  // namespace proto
}  // namespace opentxs
