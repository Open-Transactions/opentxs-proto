// Copyright (c) 2018 The Open-Transactions developers
// This Source Code Form is subject to the terms of the Mozilla Public
// License, v. 2.0. If a copy of the MPL was not distributed with this
// file, You can obtain one at http://mozilla.org/MPL/2.0/.

#include "opentxs-proto/Types.hpp"
#include "opentxs-proto/Check.hpp"

#include <iostream>

#define PROTO_NAME "payment code"

namespace opentxs
{
namespace proto
{

bool CheckProto_1(const PaymentCode& input, const bool silent)
{
    if (!input.has_key()) {
        FAIL("payment code", "missing pubkey")
    }

    if (MIN_PLAUSIBLE_KEYSIZE > input.key().size()) {
        FAIL("payment code", "invalid pubkey")
    }

    if (!input.has_chaincode()) {
        FAIL("payment code", "missing chaincode")
    }

    if (MIN_PLAUSIBLE_KEYSIZE > input.chaincode().size()) {
        FAIL("payment code", "invalid chaincode")
    }

    if (input.has_bitmessage()) {
        if (!input.has_bitmessageversion()) {
            FAIL("payment code", "missing Bitmessage address version")
        }

        if (0xff < input.bitmessageversion()) {
            FAIL("payment code", "invalid Bitmessage address version")
        }

        if (!input.has_bitmessagestream()) {
            FAIL("payment code", "missing Bitmessage address stream")
        }

        if (0xff < input.bitmessagestream()) {
            FAIL("payment code", "invalid Bitmessage address stream")
        }
    }

    return true;
}

bool CheckProto_2(const PaymentCode& input, const bool silent)
{
    UNDEFINED_VERSION("payment code", 2)
}

bool CheckProto_3(const PaymentCode& input, const bool silent)
{
    UNDEFINED_VERSION("payment code", 3)
}

bool CheckProto_4(const PaymentCode& input, const bool silent)
{
    UNDEFINED_VERSION("payment code", 4)
}

bool CheckProto_5(const PaymentCode& input, const bool silent)
{
    UNDEFINED_VERSION("payment code", 5)
}

bool CheckProto_6(const PaymentCode& input, const bool silent)
{
    UNDEFINED_VERSION2(6)
}

bool CheckProto_7(const PaymentCode& input, const bool silent)
{
    UNDEFINED_VERSION2(7)
}

bool CheckProto_8(const PaymentCode& input, const bool silent)
{
    UNDEFINED_VERSION2(8)
}

bool CheckProto_9(const PaymentCode& input, const bool silent)
{
    UNDEFINED_VERSION2(9)
}

bool CheckProto_10(const PaymentCode& input, const bool silent)
{
    UNDEFINED_VERSION2(10)
}

bool CheckProto_11(const PaymentCode& input, const bool silent)
{
    UNDEFINED_VERSION2(11)
}

bool CheckProto_12(const PaymentCode& input, const bool silent)
{
    UNDEFINED_VERSION2(12)
}

bool CheckProto_13(const PaymentCode& input, const bool silent)
{
    UNDEFINED_VERSION2(13)
}

bool CheckProto_14(const PaymentCode& input, const bool silent)
{
    UNDEFINED_VERSION2(14)
}

bool CheckProto_15(const PaymentCode& input, const bool silent)
{
    UNDEFINED_VERSION2(15)
}

bool CheckProto_16(const PaymentCode& input, const bool silent)
{
    UNDEFINED_VERSION2(16)
}

bool CheckProto_17(const PaymentCode& input, const bool silent)
{
    UNDEFINED_VERSION2(17)
}

bool CheckProto_18(const PaymentCode& input, const bool silent)
{
    UNDEFINED_VERSION2(18)
}

bool CheckProto_19(const PaymentCode& input, const bool silent)
{
    UNDEFINED_VERSION2(19)
}

bool CheckProto_20(const PaymentCode& input, const bool silent)
{
    UNDEFINED_VERSION2(20)
}
}  // namespace proto
}  // namespace opentxs
