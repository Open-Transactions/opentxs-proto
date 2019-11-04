// Copyright (c) 2019 The Open-Transactions developers
// This Source Code Form is subject to the terms of the Mozilla Public
// License, v. 2.0. If a copy of the MPL was not distributed with this
// file, You can obtain one at http://mozilla.org/MPL/2.0/.

#include "opentxs-proto/Types.hpp"
#include "verify/Check.hpp"

#define PROTO_NAME "server context"

namespace opentxs
{
namespace proto
{
bool CheckProto_2(const ServerContext& input, const bool silent)
{
    CHECK_IDENTIFIER(serverid);
    CHECK_EXCLUDED(state);
    CHECK_EXCLUDED(laststatus);
    CHECK_EXCLUDED(pending);

    return true;
}

bool CheckProto_3(const ServerContext& input, const bool silent)
{
    CHECK_IDENTIFIER(serverid);
    CHECK_MEMBERSHIP(state, ServerContextAllowedState());

    switch (input.state()) {
        case DELIVERTYSTATE_PENDINGSEND: {
            CHECK_SUBOBJECT(pending, ServerContextAllowedPendingCommand());
        } break;
        case DELIVERTYSTATE_NEEDNYMBOX:
        case DELIVERTYSTATE_NEEDBOXITEMS:
        case DELIVERTYSTATE_NEEDPROCESSNYMBOX: {
            OPTIONAL_SUBOBJECT(pending, ServerContextAllowedPendingCommand());
        } break;
        case DELIVERTYSTATE_IDLE:
        case DELIVERTYSTATE_ERROR:
        default: {
            CHECK_EXCLUDED(pending);
        }
    }

    CHECK_MEMBERSHIP(laststatus, ServerContextAllowedStatus());

    return true;
}

bool CheckProto_4(const ServerContext& input, const bool silent)
{
    UNDEFINED_VERSION(4)
}

bool CheckProto_5(const ServerContext& input, const bool silent)
{
    UNDEFINED_VERSION(5)
}

bool CheckProto_6(const ServerContext& input, const bool silent)
{
    UNDEFINED_VERSION(6)
}

bool CheckProto_7(const ServerContext& input, const bool silent)
{
    UNDEFINED_VERSION(7)
}

bool CheckProto_8(const ServerContext& input, const bool silent)
{
    UNDEFINED_VERSION(8)
}

bool CheckProto_9(const ServerContext& input, const bool silent)
{
    UNDEFINED_VERSION(9)
}

bool CheckProto_10(const ServerContext& input, const bool silent)
{
    UNDEFINED_VERSION(10)
}

bool CheckProto_11(const ServerContext& input, const bool silent)
{
    UNDEFINED_VERSION(11)
}

bool CheckProto_12(const ServerContext& input, const bool silent)
{
    UNDEFINED_VERSION(12)
}

bool CheckProto_13(const ServerContext& input, const bool silent)
{
    UNDEFINED_VERSION(13)
}

bool CheckProto_14(const ServerContext& input, const bool silent)
{
    UNDEFINED_VERSION(14)
}

bool CheckProto_15(const ServerContext& input, const bool silent)
{
    UNDEFINED_VERSION(15)
}

bool CheckProto_16(const ServerContext& input, const bool silent)
{
    UNDEFINED_VERSION(16)
}

bool CheckProto_17(const ServerContext& input, const bool silent)
{
    UNDEFINED_VERSION(17)
}

bool CheckProto_18(const ServerContext& input, const bool silent)
{
    UNDEFINED_VERSION(18)
}

bool CheckProto_19(const ServerContext& input, const bool silent)
{
    UNDEFINED_VERSION(19)
}

bool CheckProto_20(const ServerContext& input, const bool silent)
{
    UNDEFINED_VERSION(20)
}
}  // namespace proto
}  // namespace opentxs
