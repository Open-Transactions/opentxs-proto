// Copyright (c) 2019 The Open-Transactions developers
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

    return true;
}

bool CheckProto_2(const AccountEvent& input, const bool silent)
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

    OPTIONAL_IDENTIFIER(uuid);

    return true;
}

bool CheckProto_3(const AccountEvent& input, const bool silent)
{
    UNDEFINED_VERSION(3)
}

bool CheckProto_4(const AccountEvent& input, const bool silent)
{
    UNDEFINED_VERSION(4)
}

bool CheckProto_5(const AccountEvent& input, const bool silent)
{
    UNDEFINED_VERSION(5)
}

bool CheckProto_6(const AccountEvent& input, const bool silent)
{
    UNDEFINED_VERSION(6)
}

bool CheckProto_7(const AccountEvent& input, const bool silent)
{
    UNDEFINED_VERSION(7)
}

bool CheckProto_8(const AccountEvent& input, const bool silent)
{
    UNDEFINED_VERSION(8)
}

bool CheckProto_9(const AccountEvent& input, const bool silent)
{
    UNDEFINED_VERSION(9)
}

bool CheckProto_10(const AccountEvent& input, const bool silent)
{
    UNDEFINED_VERSION(10)
}

bool CheckProto_11(const AccountEvent& input, const bool silent)
{
    UNDEFINED_VERSION(11)
}

bool CheckProto_12(const AccountEvent& input, const bool silent)
{
    UNDEFINED_VERSION(12)
}

bool CheckProto_13(const AccountEvent& input, const bool silent)
{
    UNDEFINED_VERSION(13)
}

bool CheckProto_14(const AccountEvent& input, const bool silent)
{
    UNDEFINED_VERSION(14)
}

bool CheckProto_15(const AccountEvent& input, const bool silent)
{
    UNDEFINED_VERSION(15)
}

bool CheckProto_16(const AccountEvent& input, const bool silent)
{
    UNDEFINED_VERSION(16)
}

bool CheckProto_17(const AccountEvent& input, const bool silent)
{
    UNDEFINED_VERSION(17)
}

bool CheckProto_18(const AccountEvent& input, const bool silent)
{
    UNDEFINED_VERSION(18)
}

bool CheckProto_19(const AccountEvent& input, const bool silent)
{
    UNDEFINED_VERSION(19)
}

bool CheckProto_20(const AccountEvent& input, const bool silent)
{
    UNDEFINED_VERSION(20)
}
}  // namespace proto
}  // namespace opentxs
