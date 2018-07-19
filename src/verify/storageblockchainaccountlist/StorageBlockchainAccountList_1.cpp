// Copyright (c) 2018 The Open-Transactions developers
// This Source Code Form is subject to the terms of the Mozilla Public
// License, v. 2.0. If a copy of the MPL was not distributed with this
// file, You can obtain one at http://mozilla.org/MPL/2.0/.

#include "opentxs-proto/Types.hpp"
#include "opentxs-proto/Check.hpp"
#include "opentxs-proto/Contact.hpp"

#include <iostream>

#define PROTO_NAME "storage blockchain account list"

namespace opentxs
{
namespace proto
{

bool CheckProto_1(const StorageBlockchainAccountList& input, const bool silent)
{
    if (false == input.has_id()) {
        FAIL("storage blockchain account list", "missing id")
    }

    const bool validChain = ValidContactItemType(
        {CONTACT_VERSION, CONTACTSECTION_CONTRACT}, input.id());

    if (false == validChain) {
        FAIL("transaction", "invalid chain")
    }

    for (const auto& it : input.list()) {
        if (MIN_PLAUSIBLE_IDENTIFIER > it.size()) {
            FAIL2("storage blockchain account list", "invalid list item", it)
        }

        if (MAX_PLAUSIBLE_IDENTIFIER < it.size()) {
            FAIL2("storage blockchain account list", "invalid list item", it)
        }
    }

    return true;
}

bool CheckProto_2(const StorageBlockchainAccountList& input, const bool silent)
{
    UNDEFINED_VERSION("storage blockchain account list", 2)
}

bool CheckProto_3(const StorageBlockchainAccountList& input, const bool silent)
{
    UNDEFINED_VERSION("storage blockchain account list", 3)
}

bool CheckProto_4(const StorageBlockchainAccountList& input, const bool silent)
{
    UNDEFINED_VERSION("storage blockchain account list", 4)
}

bool CheckProto_5(const StorageBlockchainAccountList& input, const bool silent)
{
    UNDEFINED_VERSION("storage blockchain account list", 5)
}

bool CheckProto_6(const StorageBlockchainAccountList& input, const bool silent)
{
    UNDEFINED_VERSION2(6)
}

bool CheckProto_7(const StorageBlockchainAccountList& input, const bool silent)
{
    UNDEFINED_VERSION2(7)
}

bool CheckProto_8(const StorageBlockchainAccountList& input, const bool silent)
{
    UNDEFINED_VERSION2(8)
}

bool CheckProto_9(const StorageBlockchainAccountList& input, const bool silent)
{
    UNDEFINED_VERSION2(9)
}

bool CheckProto_10(const StorageBlockchainAccountList& input, const bool silent)
{
    UNDEFINED_VERSION2(10)
}

bool CheckProto_11(const StorageBlockchainAccountList& input, const bool silent)
{
    UNDEFINED_VERSION2(11)
}

bool CheckProto_12(const StorageBlockchainAccountList& input, const bool silent)
{
    UNDEFINED_VERSION2(12)
}

bool CheckProto_13(const StorageBlockchainAccountList& input, const bool silent)
{
    UNDEFINED_VERSION2(13)
}

bool CheckProto_14(const StorageBlockchainAccountList& input, const bool silent)
{
    UNDEFINED_VERSION2(14)
}

bool CheckProto_15(const StorageBlockchainAccountList& input, const bool silent)
{
    UNDEFINED_VERSION2(15)
}

bool CheckProto_16(const StorageBlockchainAccountList& input, const bool silent)
{
    UNDEFINED_VERSION2(16)
}

bool CheckProto_17(const StorageBlockchainAccountList& input, const bool silent)
{
    UNDEFINED_VERSION2(17)
}

bool CheckProto_18(const StorageBlockchainAccountList& input, const bool silent)
{
    UNDEFINED_VERSION2(18)
}

bool CheckProto_19(const StorageBlockchainAccountList& input, const bool silent)
{
    UNDEFINED_VERSION2(19)
}

bool CheckProto_20(const StorageBlockchainAccountList& input, const bool silent)
{
    UNDEFINED_VERSION2(20)
}
}  // namespace proto
}  // namespace opentxs
