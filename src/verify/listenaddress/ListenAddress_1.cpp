// Copyright (c) 2018 The Open-Transactions developers
// This Source Code Form is subject to the terms of the Mozilla Public
// License, v. 2.0. If a copy of the MPL was not distributed with this
// file, You can obtain one at http://mozilla.org/MPL/2.0/.

#include "opentxs-proto/Types.hpp"
#include "opentxs-proto/Check.hpp"

#include <iostream>

#define PROTO_NAME "listen address"

namespace opentxs
{
namespace proto
{

bool CheckProto_1(const ListenAddress& input, const bool silent)
{
    CHECK_EXISTS(type);

    if ((ADDRESSTYPE_IPV4 > input.type()) || (ADDRESSTYPE_EEP < input.type())) {
        FAIL4("invalid type")
    }

    if (!input.has_protocol()) { FAIL4("missing protocol") }

    if ((PROTOCOLVERSION_ERROR == input.protocol()) ||
        (PROTOCOLVERSION_NOTIFY < input.protocol())) {
        FAIL4("invalid protocol")
    }

    CHECK_EXISTS(host);
    CHECK_EXISTS(port);

    if (MAX_VALID_PORT < input.port()) { FAIL4("invalid port") }

    return true;
}

bool CheckProto_2(const ListenAddress& input, const bool silent)
{
    CHECK_EXISTS(type);

    if ((ADDRESSTYPE_IPV4 > input.type()) ||
        (ADDRESSTYPE_INPROC < input.type())) {
        FAIL4("invalid type")
    }

    if (!input.has_protocol()) { FAIL4("missing protocol") }

    if ((PROTOCOLVERSION_ERROR == input.protocol()) ||
        (PROTOCOLVERSION_NOTIFY < input.protocol())) {
        FAIL4("invalid protocol")
    }

    CHECK_EXISTS(host);
    CHECK_EXISTS(port);

    if (MAX_VALID_PORT < input.port()) { FAIL4("invalid port") }

    return true;
}

bool CheckProto_3(const ListenAddress& input, const bool silent)
{
    UNDEFINED_VERSION2(3)
}

bool CheckProto_4(const ListenAddress& input, const bool silent)
{
    UNDEFINED_VERSION2(4)
}

bool CheckProto_5(const ListenAddress& input, const bool silent)
{
    UNDEFINED_VERSION2(5)
}

bool CheckProto_6(const ListenAddress& input, const bool silent)
{
    UNDEFINED_VERSION2(6)
}

bool CheckProto_7(const ListenAddress& input, const bool silent)
{
    UNDEFINED_VERSION2(7)
}

bool CheckProto_8(const ListenAddress& input, const bool silent)
{
    UNDEFINED_VERSION2(8)
}

bool CheckProto_9(const ListenAddress& input, const bool silent)
{
    UNDEFINED_VERSION2(9)
}

bool CheckProto_10(const ListenAddress& input, const bool silent)
{
    UNDEFINED_VERSION2(10)
}

bool CheckProto_11(const ListenAddress& input, const bool silent)
{
    UNDEFINED_VERSION2(11)
}

bool CheckProto_12(const ListenAddress& input, const bool silent)
{
    UNDEFINED_VERSION2(12)
}

bool CheckProto_13(const ListenAddress& input, const bool silent)
{
    UNDEFINED_VERSION2(13)
}

bool CheckProto_14(const ListenAddress& input, const bool silent)
{
    UNDEFINED_VERSION2(14)
}

bool CheckProto_15(const ListenAddress& input, const bool silent)
{
    UNDEFINED_VERSION2(15)
}

bool CheckProto_16(const ListenAddress& input, const bool silent)
{
    UNDEFINED_VERSION2(16)
}

bool CheckProto_17(const ListenAddress& input, const bool silent)
{
    UNDEFINED_VERSION2(17)
}

bool CheckProto_18(const ListenAddress& input, const bool silent)
{
    UNDEFINED_VERSION2(18)
}

bool CheckProto_19(const ListenAddress& input, const bool silent)
{
    UNDEFINED_VERSION2(19)
}

bool CheckProto_20(const ListenAddress& input, const bool silent)
{
    UNDEFINED_VERSION2(20)
}
}  // namespace proto
}  // namespace opentxs
