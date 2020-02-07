// Copyright (c) 2020 The Open-Transactions developers
// This Source Code Form is subject to the terms of the Mozilla Public
// License, v. 2.0. If a copy of the MPL was not distributed with this
// file, You can obtain one at http://mozilla.org/MPL/2.0/.

#include "opentxs-proto/Types.hpp"
#include "verify/Check.hpp"

#define PROTO_NAME "otx push"

namespace opentxs::proto
{
bool CheckProto_1(const OTXPush& input, const bool silent)
{
    switch (input.type()) {
        case OTXPUSH_NYMBOX: {
            CHECK_EXCLUDED(accountid);
            CHECK_EXCLUDED(itemid);
            CHECK_EXCLUDED(account);
            CHECK_EXCLUDED(inbox);
            CHECK_EXCLUDED(inboxhash);
            CHECK_EXCLUDED(outbox);
            CHECK_EXCLUDED(outboxhash);
            CHECK_EXISTS(item);
        } break;
        case OTXPUSH_INBOX:
        case OTXPUSH_OUTBOX: {
            CHECK_IDENTIFIER(accountid);
            CHECK_EXISTS(itemid);
            CHECK_EXISTS_STRING(account);
            CHECK_EXISTS_STRING(inbox);
            CHECK_IDENTIFIER(inboxhash);
            CHECK_EXISTS_STRING(outbox);
            CHECK_IDENTIFIER(outboxhash);
            CHECK_EXISTS_STRING(item);
        } break;
        case OTXPUSH_ERROR:
        default: {
            FAIL_1("Invalid type");
        }
    }

    return true;
}

bool CheckProto_2(const OTXPush& input, const bool silent)
{
    UNDEFINED_VERSION(2)
}

bool CheckProto_3(const OTXPush& input, const bool silent)
{
    UNDEFINED_VERSION(3)
}

bool CheckProto_4(const OTXPush& input, const bool silent)
{
    UNDEFINED_VERSION(4)
}

bool CheckProto_5(const OTXPush& input, const bool silent)
{
    UNDEFINED_VERSION(5)
}

bool CheckProto_6(const OTXPush& input, const bool silent)
{
    UNDEFINED_VERSION(6)
}

bool CheckProto_7(const OTXPush& input, const bool silent)
{
    UNDEFINED_VERSION(7)
}

bool CheckProto_8(const OTXPush& input, const bool silent)
{
    UNDEFINED_VERSION(8)
}

bool CheckProto_9(const OTXPush& input, const bool silent)
{
    UNDEFINED_VERSION(9)
}

bool CheckProto_10(const OTXPush& input, const bool silent)
{
    UNDEFINED_VERSION(10)
}

bool CheckProto_11(const OTXPush& input, const bool silent)
{
    UNDEFINED_VERSION(11)
}

bool CheckProto_12(const OTXPush& input, const bool silent)
{
    UNDEFINED_VERSION(12)
}

bool CheckProto_13(const OTXPush& input, const bool silent)
{
    UNDEFINED_VERSION(13)
}

bool CheckProto_14(const OTXPush& input, const bool silent)
{
    UNDEFINED_VERSION(14)
}

bool CheckProto_15(const OTXPush& input, const bool silent)
{
    UNDEFINED_VERSION(15)
}

bool CheckProto_16(const OTXPush& input, const bool silent)
{
    UNDEFINED_VERSION(16)
}

bool CheckProto_17(const OTXPush& input, const bool silent)
{
    UNDEFINED_VERSION(17)
}

bool CheckProto_18(const OTXPush& input, const bool silent)
{
    UNDEFINED_VERSION(18)
}

bool CheckProto_19(const OTXPush& input, const bool silent)
{
    UNDEFINED_VERSION(19)
}

bool CheckProto_20(const OTXPush& input, const bool silent)
{
    UNDEFINED_VERSION(20)
}
}  // namespace opentxs::proto
