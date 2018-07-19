// Copyright (c) 2018 The Open-Transactions developers
// This Source Code Form is subject to the terms of the Mozilla Public
// License, v. 2.0. If a copy of the MPL was not distributed with this
// file, You can obtain one at http://mozilla.org/MPL/2.0/.

#include "opentxs-proto/Types.hpp"
#include "opentxs-proto/Check.hpp"

#include <iostream>

#define PROTO_NAME "storage contact nym index"

namespace opentxs::proto
{
bool CheckProto_1(const StorageContactNymIndex& input, const bool silent)
{
    if (false == input.has_contact()) {
        FAIL("storage contact nym index", "missing contact")
    }

    if (MIN_PLAUSIBLE_IDENTIFIER > input.contact().size()) {
        FAIL2("storage contact nym index", "invalid contact", input.contact())
    }

    if (MAX_PLAUSIBLE_IDENTIFIER < input.contact().size()) {
        FAIL2("storage contact nym index", "invalid contact", input.contact())
    }

    for (const auto& it : input.nym()) {
        if (MIN_PLAUSIBLE_IDENTIFIER > it.size()) {
            FAIL2("storage contact nym index", "invalid nym", it)
        }

        if (MAX_PLAUSIBLE_IDENTIFIER < it.size()) {
            FAIL2("storage contact nym index", "invalid nym", it)
        }
    }

    return true;
}

bool CheckProto_2(const StorageContactNymIndex& input, const bool silent)
{
    UNDEFINED_VERSION("storage contact nym index", 2)
}

bool CheckProto_3(const StorageContactNymIndex& input, const bool silent)
{
    UNDEFINED_VERSION("storage contact nym index", 3)
}

bool CheckProto_4(const StorageContactNymIndex& input, const bool silent)
{
    UNDEFINED_VERSION("storage contact nym index", 4)
}

bool CheckProto_5(const StorageContactNymIndex& input, const bool silent)
{
    UNDEFINED_VERSION("storage contact nym index", 5)
}

bool CheckProto_6(const StorageContactNymIndex& input, const bool silent)
{
    UNDEFINED_VERSION2(6)
}

bool CheckProto_7(const StorageContactNymIndex& input, const bool silent)
{
    UNDEFINED_VERSION2(7)
}

bool CheckProto_8(const StorageContactNymIndex& input, const bool silent)
{
    UNDEFINED_VERSION2(8)
}

bool CheckProto_9(const StorageContactNymIndex& input, const bool silent)
{
    UNDEFINED_VERSION2(9)
}

bool CheckProto_10(const StorageContactNymIndex& input, const bool silent)
{
    UNDEFINED_VERSION2(10)
}

bool CheckProto_11(const StorageContactNymIndex& input, const bool silent)
{
    UNDEFINED_VERSION2(11)
}

bool CheckProto_12(const StorageContactNymIndex& input, const bool silent)
{
    UNDEFINED_VERSION2(12)
}

bool CheckProto_13(const StorageContactNymIndex& input, const bool silent)
{
    UNDEFINED_VERSION2(13)
}

bool CheckProto_14(const StorageContactNymIndex& input, const bool silent)
{
    UNDEFINED_VERSION2(14)
}

bool CheckProto_15(const StorageContactNymIndex& input, const bool silent)
{
    UNDEFINED_VERSION2(15)
}

bool CheckProto_16(const StorageContactNymIndex& input, const bool silent)
{
    UNDEFINED_VERSION2(16)
}

bool CheckProto_17(const StorageContactNymIndex& input, const bool silent)
{
    UNDEFINED_VERSION2(17)
}

bool CheckProto_18(const StorageContactNymIndex& input, const bool silent)
{
    UNDEFINED_VERSION2(18)
}

bool CheckProto_19(const StorageContactNymIndex& input, const bool silent)
{
    UNDEFINED_VERSION2(19)
}

bool CheckProto_20(const StorageContactNymIndex& input, const bool silent)
{
    UNDEFINED_VERSION2(20)
}
}  // namespace opentxs::proto
