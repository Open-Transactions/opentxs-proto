// Copyright (c) 2020 The Open-Transactions developers
// This Source Code Form is subject to the terms of the Mozilla Public
// License, v. 2.0. If a copy of the MPL was not distributed with this
// file, You can obtain one at http://mozilla.org/MPL/2.0/.

#include "opentxs-proto/Types.hpp"
#include "verify/Check.hpp"

#define PROTO_NAME "send payment"

namespace opentxs
{
namespace proto
{
bool CheckProto_1(const SendPayment& input, const bool silent)
{
    CHECK_IDENTIFIER(contact);
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

    return true;
}

bool CheckProto_2(const SendPayment& input, const bool silent)
{
    UNDEFINED_VERSION(2)
}

bool CheckProto_3(const SendPayment& input, const bool silent)
{
    UNDEFINED_VERSION(3)
}

bool CheckProto_4(const SendPayment& input, const bool silent)
{
    UNDEFINED_VERSION(4)
}

bool CheckProto_5(const SendPayment& input, const bool silent)
{
    UNDEFINED_VERSION(5)
}

bool CheckProto_6(const SendPayment& input, const bool silent)
{
    UNDEFINED_VERSION(6)
}

bool CheckProto_7(const SendPayment& input, const bool silent)
{
    UNDEFINED_VERSION(7)
}

bool CheckProto_8(const SendPayment& input, const bool silent)
{
    UNDEFINED_VERSION(8)
}

bool CheckProto_9(const SendPayment& input, const bool silent)
{
    UNDEFINED_VERSION(9)
}

bool CheckProto_10(const SendPayment& input, const bool silent)
{
    UNDEFINED_VERSION(10)
}

bool CheckProto_11(const SendPayment& input, const bool silent)
{
    UNDEFINED_VERSION(11)
}

bool CheckProto_12(const SendPayment& input, const bool silent)
{
    UNDEFINED_VERSION(12)
}

bool CheckProto_13(const SendPayment& input, const bool silent)
{
    UNDEFINED_VERSION(13)
}

bool CheckProto_14(const SendPayment& input, const bool silent)
{
    UNDEFINED_VERSION(14)
}

bool CheckProto_15(const SendPayment& input, const bool silent)
{
    UNDEFINED_VERSION(15)
}

bool CheckProto_16(const SendPayment& input, const bool silent)
{
    UNDEFINED_VERSION(16)
}

bool CheckProto_17(const SendPayment& input, const bool silent)
{
    UNDEFINED_VERSION(17)
}

bool CheckProto_18(const SendPayment& input, const bool silent)
{
    UNDEFINED_VERSION(18)
}

bool CheckProto_19(const SendPayment& input, const bool silent)
{
    UNDEFINED_VERSION(19)
}

bool CheckProto_20(const SendPayment& input, const bool silent)
{
    UNDEFINED_VERSION(20)
}
}  // namespace proto
}  // namespace opentxs
