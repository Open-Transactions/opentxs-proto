// Copyright (c) 2020 The Open-Transactions developers
// This Source Code Form is subject to the terms of the Mozilla Public
// License, v. 2.0. If a copy of the MPL was not distributed with this
// file, You can obtain one at http://mozilla.org/MPL/2.0/.

#include "opentxs-proto/Types.hpp"
#include "verify/Check.hpp"

#define PROTO_NAME "account data"

namespace opentxs
{
namespace proto
{

bool CheckProto_1(const TransactionData& input, const bool silent)
{
    CHECK_IDENTIFIER(uuid);
    OPTIONAL_IDENTIFIERS(sourceaccounts);
    OPTIONAL_IDENTIFIERS(destinationaccounts);
    CHECK_EXCLUDED(amount_mp)
    return true;
}

}  // namespace proto
}  // namespace opentxs
