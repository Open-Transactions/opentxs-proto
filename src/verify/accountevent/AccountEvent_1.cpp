// Copyright (c) 2020 The Open-Transactions developers
// This Source Code Form is subject to the terms of the Mozilla Public
// License, v. 2.0. If a copy of the MPL was not distributed with this
// file, You can obtain one at http://mozilla.org/MPL/2.0/.

#include "opentxs-proto/Types.hpp"
#include "verify/Check.hpp"

#define PROTO_NAME "account event"

namespace opentxs
{
namespace proto
{
bool CheckProto_1(const AccountEvent& input, const bool silent)
{
    OPTIONAL_IDENTIFIER(id);
    CHECK_IDENTIFIER(workflow);

    switch (input.type()) {
        case ACCOUNTEVENT_INCOMINGTRANSFER:
        case ACCOUNTEVENT_INCOMINGINVOICE:
        case ACCOUNTEVENT_INCOMINGVOUCHER:
        case ACCOUNTEVENT_INCOMINGCHEQUE: {
            CHECK_IDENTIFIER(contact);
        } break;
        case ACCOUNTEVENT_OUTGOINGCHEQUE:
        case ACCOUNTEVENT_OUTGOINGTRANSFER:
        case ACCOUNTEVENT_OUTGOINGINVOICE:
        case ACCOUNTEVENT_OUTGOINGVOUCHER: {
            OPTIONAL_IDENTIFIER(contact);
        } break;
        case ACCOUNTEVENT_ERROR:
        default: {
            FAIL_2("Invalid type", input.type());
        }
    }

    CHECK_EXCLUDED(uuid);
    CHECK_EXCLUDED(amount_mp)
    CHECK_EXCLUDED(pendingamount_mp)

    return true;
}

}  // namespace proto
}  // namespace opentxs
