// Copyright (c) 2018 The Open-Transactions developers
// This Source Code Form is subject to the terms of the Mozilla Public
// License, v. 2.0. If a copy of the MPL was not distributed with this
// file, You can obtain one at http://mozilla.org/MPL/2.0/.

#include "opentxs-proto/Types.hpp"
#include "opentxs-proto/Check.hpp"

#include <iostream>

#define PROTO_NAME "blockchain transaction input"

namespace opentxs
{
namespace proto
{

bool CheckProto_1(const BlockchainTransactionInput& input, const bool silent)
{
    if (false == input.has_index()) {
        FAIL("blockchain transaction input", "missing index")
    }

    if (false == input.has_serializedscript()) {
        FAIL("blockchain transaction input", "missing serializedscript")
    }

    if (MIN_PLAUSIBLE_SCRIPT > input.serializedscript().size()) {
        FAIL("blockchain transaction input", "invalid serializedscript")
    }

    if (MAX_PLAUSIBLE_SCRIPT < input.serializedscript().size()) {
        FAIL("blockchain transaction input", "invalid serializedscript")
    }

    for (const auto& address : input.address()) {
        if (MIN_PLAUSIBLE_IDENTIFIER > address.size()) {
            FAIL("blockchain transaction input", "invalid serializedscript")
        }

        if (MAX_PLAUSIBLE_IDENTIFIER < address.size()) {
            FAIL("blockchain transaction input", "invalid serializedscript")
        }
    }

    return true;
}

bool CheckProto_2(const BlockchainTransactionInput& input, const bool silent)
{
    UNDEFINED_VERSION("blockchain transaction input", 2)
}

bool CheckProto_3(const BlockchainTransactionInput& input, const bool silent)
{
    UNDEFINED_VERSION("blockchain transaction input", 3)
}

bool CheckProto_4(const BlockchainTransactionInput& input, const bool silent)
{
    UNDEFINED_VERSION("blockchain transaction input", 4)
}

bool CheckProto_5(const BlockchainTransactionInput& input, const bool silent)
{
    UNDEFINED_VERSION("blockchain transaction input", 5)
}

bool CheckProto_6(const BlockchainTransactionInput& input, const bool silent)
{
    UNDEFINED_VERSION2(6)
}

bool CheckProto_7(const BlockchainTransactionInput& input, const bool silent)
{
    UNDEFINED_VERSION2(7)
}

bool CheckProto_8(const BlockchainTransactionInput& input, const bool silent)
{
    UNDEFINED_VERSION2(8)
}

bool CheckProto_9(const BlockchainTransactionInput& input, const bool silent)
{
    UNDEFINED_VERSION2(9)
}

bool CheckProto_10(const BlockchainTransactionInput& input, const bool silent)
{
    UNDEFINED_VERSION2(10)
}

bool CheckProto_11(const BlockchainTransactionInput& input, const bool silent)
{
    UNDEFINED_VERSION2(11)
}

bool CheckProto_12(const BlockchainTransactionInput& input, const bool silent)
{
    UNDEFINED_VERSION2(12)
}

bool CheckProto_13(const BlockchainTransactionInput& input, const bool silent)
{
    UNDEFINED_VERSION2(13)
}

bool CheckProto_14(const BlockchainTransactionInput& input, const bool silent)
{
    UNDEFINED_VERSION2(14)
}

bool CheckProto_15(const BlockchainTransactionInput& input, const bool silent)
{
    UNDEFINED_VERSION2(15)
}

bool CheckProto_16(const BlockchainTransactionInput& input, const bool silent)
{
    UNDEFINED_VERSION2(16)
}

bool CheckProto_17(const BlockchainTransactionInput& input, const bool silent)
{
    UNDEFINED_VERSION2(17)
}

bool CheckProto_18(const BlockchainTransactionInput& input, const bool silent)
{
    UNDEFINED_VERSION2(18)
}

bool CheckProto_19(const BlockchainTransactionInput& input, const bool silent)
{
    UNDEFINED_VERSION2(19)
}

bool CheckProto_20(const BlockchainTransactionInput& input, const bool silent)
{
    UNDEFINED_VERSION2(20)
}
}  // namespace proto
}  // namespace opentxs
