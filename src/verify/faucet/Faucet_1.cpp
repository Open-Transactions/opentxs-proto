// Copyright (c) 2018 The Open-Transactions developers
// This Source Code Form is subject to the terms of the Mozilla Public
// License, v. 2.0. If a copy of the MPL was not distributed with this
// file, You can obtain one at http://mozilla.org/MPL/2.0/.

#include "opentxs-proto/Types.hpp"
#include "opentxs-proto/Check.hpp"

#include <iostream>

#define PROTO_NAME "faucet request"

namespace opentxs
{
namespace proto
{
bool CheckProto_1(const Faucet& input, const bool silent)
{
    UNDEFINED_VERSION("faucet request", 1)
}

bool CheckProto_2(const Faucet& input, const bool silent)
{
    UNDEFINED_VERSION("faucet request", 2)
}

bool CheckProto_3(const Faucet& input, const bool silent)
{
    UNDEFINED_VERSION("faucet request", 3)
}

bool CheckProto_4(const Faucet& input, const bool silent)
{
    const bool validChain = ValidContactItemType(
        {CONTACT_VERSION, CONTACTSECTION_CONTRACT}, input.type());

    if (false == validChain) {
        FAIL("faucet request", "invalid chain")
    }

    if (MAX_PLAUSIBLE_IDENTIFIER < input.address().size()) {
        FAIL("faucet request", "invalid address")
    }

    return true;
}

bool CheckProto_5(const Faucet& input, const bool silent)
{
    UNDEFINED_VERSION("faucet request", 5)
}

bool CheckProto_6(const Faucet& input, const bool silent)
{
    UNDEFINED_VERSION2(6)
}

bool CheckProto_7(const Faucet& input, const bool silent)
{
    UNDEFINED_VERSION2(7)
}

bool CheckProto_8(const Faucet& input, const bool silent)
{
    UNDEFINED_VERSION2(8)
}

bool CheckProto_9(const Faucet& input, const bool silent)
{
    UNDEFINED_VERSION2(9)
}

bool CheckProto_10(const Faucet& input, const bool silent)
{
    UNDEFINED_VERSION2(10)
}

bool CheckProto_11(const Faucet& input, const bool silent)
{
    UNDEFINED_VERSION2(11)
}

bool CheckProto_12(const Faucet& input, const bool silent)
{
    UNDEFINED_VERSION2(12)
}

bool CheckProto_13(const Faucet& input, const bool silent)
{
    UNDEFINED_VERSION2(13)
}

bool CheckProto_14(const Faucet& input, const bool silent)
{
    UNDEFINED_VERSION2(14)
}

bool CheckProto_15(const Faucet& input, const bool silent)
{
    UNDEFINED_VERSION2(15)
}

bool CheckProto_16(const Faucet& input, const bool silent)
{
    UNDEFINED_VERSION2(16)
}

bool CheckProto_17(const Faucet& input, const bool silent)
{
    UNDEFINED_VERSION2(17)
}

bool CheckProto_18(const Faucet& input, const bool silent)
{
    UNDEFINED_VERSION2(18)
}

bool CheckProto_19(const Faucet& input, const bool silent)
{
    UNDEFINED_VERSION2(19)
}

bool CheckProto_20(const Faucet& input, const bool silent)
{
    UNDEFINED_VERSION2(20)
}
}  // namespace proto
}  // namespace opentxs
