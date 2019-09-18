// Copyright (c) 2019 The Open-Transactions developers
// This Source Code Form is subject to the terms of the Mozilla Public
// License, v. 2.0. If a copy of the MPL was not distributed with this
// file, You can obtain one at http://mozilla.org/MPL/2.0/.

#include "opentxs-proto/Check.hpp"
#include "opentxs-proto/Types.hpp"

#define PROTO_NAME "context"

namespace opentxs
{
namespace proto
{
bool CheckProto_1(const Context& input, const bool silent)
{
    CHECK_IDENTIFIER(localnym)
    CHECK_IDENTIFIER(remotenym)
    CHECK_EXISTS(type)

    switch (input.type()) {
        case CONSENSUSTYPE_SERVER: {
            CHECK_EXCLUDED(clientcontext)
            CHECK_SUBOBJECT(servercontext, ContextAllowedServer)
        } break;
        case CONSENSUSTYPE_CLIENT: {
            CHECK_EXCLUDED(servercontext)
            CHECK_SUBOBJECT(clientcontext, ContextAllowedServer)
        } break;
        case CONSENSUSTYPE_PEER:
        case CONSENSUSTYPE_ERROR:
        default: {
            FAIL_1("invalid type")
        }
    }

    CHECK_SUBOBJECT_VA(signature, ContextAllowedSignature, SIGROLE_CONTEXT)

    return true;
}

bool CheckProto_2(const Context& input, const bool silent)
{
    return CheckProto_1(input, silent);
}

bool CheckProto_3(const Context& input, const bool silent)
{
    return CheckProto_1(input, silent);
}

bool CheckProto_4(const Context& input, const bool silent)
{
    UNDEFINED_VERSION(4)
}

bool CheckProto_5(const Context& input, const bool silent)
{
    UNDEFINED_VERSION(5)
}

bool CheckProto_6(const Context& input, const bool silent)
{
    UNDEFINED_VERSION(6)
}

bool CheckProto_7(const Context& input, const bool silent)
{
    UNDEFINED_VERSION(7)
}

bool CheckProto_8(const Context& input, const bool silent)
{
    UNDEFINED_VERSION(8)
}

bool CheckProto_9(const Context& input, const bool silent)
{
    UNDEFINED_VERSION(9)
}

bool CheckProto_10(const Context& input, const bool silent)
{
    UNDEFINED_VERSION(10)
}

bool CheckProto_11(const Context& input, const bool silent)
{
    UNDEFINED_VERSION(11)
}

bool CheckProto_12(const Context& input, const bool silent)
{
    UNDEFINED_VERSION(12)
}

bool CheckProto_13(const Context& input, const bool silent)
{
    UNDEFINED_VERSION(13)
}

bool CheckProto_14(const Context& input, const bool silent)
{
    UNDEFINED_VERSION(14)
}

bool CheckProto_15(const Context& input, const bool silent)
{
    UNDEFINED_VERSION(15)
}

bool CheckProto_16(const Context& input, const bool silent)
{
    UNDEFINED_VERSION(16)
}

bool CheckProto_17(const Context& input, const bool silent)
{
    UNDEFINED_VERSION(17)
}

bool CheckProto_18(const Context& input, const bool silent)
{
    UNDEFINED_VERSION(18)
}

bool CheckProto_19(const Context& input, const bool silent)
{
    UNDEFINED_VERSION(19)
}

bool CheckProto_20(const Context& input, const bool silent)
{
    UNDEFINED_VERSION(20)
}
}  // namespace proto
}  // namespace opentxs
