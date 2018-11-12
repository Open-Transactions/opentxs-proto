// Copyright (c) 2018 The Open-Transactions developers
// This Source Code Form is subject to the terms of the Mozilla Public
// License, v. 2.0. If a copy of the MPL was not distributed with this
// file, You can obtain one at http://mozilla.org/MPL/2.0/.

#include "opentxs-proto/Types.hpp"
#include "opentxs-proto/Check.hpp"

#define PROTO_NAME "contact event"

namespace opentxs
{
namespace proto
{
bool CheckProto_1(const ContactEvent& input, const bool silent)
{
    CHECK_IDENTIFIER(id);

    switch (input.type()) {
        case CONTACTEVENT_INCOMINGMESSAGE:
        case CONTACTEVENT_OUTGOINGMESSAGE: {
            CHECK_EXISTS_STRING(message);
            CHECK_EXCLUDED(account);
            CHECK_EXCLUDED(accountevent);
        } break;
        case CONTACTEVENT_INCOMONGPAYMENT:
        case CONTACTEVENT_OUTGOINGPAYMENT: {
            CHECK_EXCLUDED(timestamp);
            CHECK_EXCLUDED(message);
            CHECK_IDENTIFIER(account);
            CHECK_SUBOBJECT(accountevent, ContactEventAllowedAccountEvent);
        } break;
        case CONTACTEVENT_ERROR:
        default: {
            FAIL_2("Invalid type", input.type());
        }
    }

    return true;
}

bool CheckProto_2(const ContactEvent& input, const bool silent)
{
    return CheckProto_1(input, silent);
}

bool CheckProto_3(const ContactEvent& input, const bool silent)
{
    UNDEFINED_VERSION(3)
}

bool CheckProto_4(const ContactEvent& input, const bool silent)
{
    UNDEFINED_VERSION(4)
}

bool CheckProto_5(const ContactEvent& input, const bool silent)
{
    UNDEFINED_VERSION(5)
}

bool CheckProto_6(const ContactEvent& input, const bool silent)
{
    UNDEFINED_VERSION(6)
}

bool CheckProto_7(const ContactEvent& input, const bool silent)
{
    UNDEFINED_VERSION(7)
}

bool CheckProto_8(const ContactEvent& input, const bool silent)
{
    UNDEFINED_VERSION(8)
}

bool CheckProto_9(const ContactEvent& input, const bool silent)
{
    UNDEFINED_VERSION(9)
}

bool CheckProto_10(const ContactEvent& input, const bool silent)
{
    UNDEFINED_VERSION(10)
}

bool CheckProto_11(const ContactEvent& input, const bool silent)
{
    UNDEFINED_VERSION(11)
}

bool CheckProto_12(const ContactEvent& input, const bool silent)
{
    UNDEFINED_VERSION(12)
}

bool CheckProto_13(const ContactEvent& input, const bool silent)
{
    UNDEFINED_VERSION(13)
}

bool CheckProto_14(const ContactEvent& input, const bool silent)
{
    UNDEFINED_VERSION(14)
}

bool CheckProto_15(const ContactEvent& input, const bool silent)
{
    UNDEFINED_VERSION(15)
}

bool CheckProto_16(const ContactEvent& input, const bool silent)
{
    UNDEFINED_VERSION(16)
}

bool CheckProto_17(const ContactEvent& input, const bool silent)
{
    UNDEFINED_VERSION(17)
}

bool CheckProto_18(const ContactEvent& input, const bool silent)
{
    UNDEFINED_VERSION(18)
}

bool CheckProto_19(const ContactEvent& input, const bool silent)
{
    UNDEFINED_VERSION(19)
}

bool CheckProto_20(const ContactEvent& input, const bool silent)
{
    UNDEFINED_VERSION(20)
}
}  // namespace proto
}  // namespace opentxs
