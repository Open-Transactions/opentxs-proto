// Copyright (c) 2020 The Open-Transactions developers
// This Source Code Form is subject to the terms of the Mozilla Public
// License, v. 2.0. If a copy of the MPL was not distributed with this
// file, You can obtain one at http://mozilla.org/MPL/2.0/.

#include "opentxs-proto/Types.hpp"
#include "verify/Check.hpp"

#define PROTO_NAME "move funds"

namespace opentxs
{
namespace proto
{
bool CheckProto_1(const MoveFunds& input, const bool silent)
{
    CHECK_IDENTIFIER(sourceaccount);
    OPTIONAL_NAME(memo);

    switch (input.type()) {
        case RPCPAYMENTTYPE_TRANSFER: {
            CHECK_IDENTIFIER(destinationaccount);
        } break;
        case RPCPAYMENTTYPE_CHEQUE:
        case RPCPAYMENTTYPE_VOUCHER:
        case RPCPAYMENTTYPE_INVOICE:
        case RPCPAYMENTTYPE_BLINDED:
        case RPCPAYMENTTYPE_ERROR:
            break;
        default: {
            FAIL_2("Invalid type", input.type());
        }
    }

    CHECK_EXCLUDED(amount_mp)

    return true;
}
}  // namespace proto
}  // namespace opentxs
