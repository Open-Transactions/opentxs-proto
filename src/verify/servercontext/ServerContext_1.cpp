// Copyright (c) 2018 The Open-Transactions developers
// This Source Code Form is subject to the terms of the Mozilla Public
// License, v. 2.0. If a copy of the MPL was not distributed with this
// file, You can obtain one at http://mozilla.org/MPL/2.0/.

#include "opentxs-proto/Types.hpp"
#include "opentxs-proto/Check.hpp"

#define PROTO_NAME "server context"

namespace opentxs
{
namespace proto
{
bool CheckProto_1(const ServerContext& input, const bool silent)
{
    if (!input.has_serverid()) { FAIL_1("missing server id") }

    if ((MIN_PLAUSIBLE_IDENTIFIER > input.serverid().size()) ||
        (MAX_PLAUSIBLE_IDENTIFIER < input.serverid().size())) {
        FAIL_1("invalid server id")
    }

    if (0 < input.revision()) { FAIL_1("unexpected revision field found"); }

    if (0 < input.adminpassword().size()) {
        FAIL_1("unexpected adminpassword field found");
    }

    if (input.adminattempted()) {
        FAIL_1("unexpected adminattempted field found");
    }

    if (input.adminsuccess()) { FAIL_1("unexpected adminsuccess field found"); }

    return true;
}
}  // namespace proto
}  // namespace opentxs
