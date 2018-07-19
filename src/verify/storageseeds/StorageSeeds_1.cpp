// Copyright (c) 2018 The Open-Transactions developers
// This Source Code Form is subject to the terms of the Mozilla Public
// License, v. 2.0. If a copy of the MPL was not distributed with this
// file, You can obtain one at http://mozilla.org/MPL/2.0/.

#include "opentxs-proto/Types.hpp"
#include "opentxs-proto/Check.hpp"

#include <iostream>

#define PROTO_NAME "seed storage index"

namespace opentxs
{
namespace proto
{

bool CheckProto_1(const StorageSeeds& input, const bool silent)
{
    if (!input.has_defaultseed()) {
        FAIL("seed storage index", "missing default seed")
    }

    if (MIN_PLAUSIBLE_IDENTIFIER > input.defaultseed().size()) {
        FAIL("seed storage index", "invalid default seed")
    }

    for (auto& hash : input.seed()) {
        try {
            const bool valid = Check(
                hash,
                StorageSeedsAllowedHash.at(input.version()).first,
                StorageSeedsAllowedHash.at(input.version()).second,
                silent);

            if (!valid) {
                FAIL("seed storage index", "invalid has")
            }
        } catch (const std::out_of_range&) {
            FAIL2(
                "seed storage index",
                "allowed storage item hash version not defined for version",
                input.version())
        }
    }

    return true;
}

bool CheckProto_2(const StorageSeeds& input, const bool silent)
{
    return CheckProto_1(input, silent);
}

bool CheckProto_3(const StorageSeeds& input, const bool silent)
{
    UNDEFINED_VERSION("seed storage index", 3)
}

bool CheckProto_4(const StorageSeeds& input, const bool silent)
{
    UNDEFINED_VERSION("seed storage index", 4)
}

bool CheckProto_5(const StorageSeeds& input, const bool silent)
{
    UNDEFINED_VERSION("seed storage index", 5)
}

bool CheckProto_6(const StorageSeeds& input, const bool silent)
{
    UNDEFINED_VERSION2(6)
}

bool CheckProto_7(const StorageSeeds& input, const bool silent)
{
    UNDEFINED_VERSION2(7)
}

bool CheckProto_8(const StorageSeeds& input, const bool silent)
{
    UNDEFINED_VERSION2(8)
}

bool CheckProto_9(const StorageSeeds& input, const bool silent)
{
    UNDEFINED_VERSION2(9)
}

bool CheckProto_10(const StorageSeeds& input, const bool silent)
{
    UNDEFINED_VERSION2(10)
}

bool CheckProto_11(const StorageSeeds& input, const bool silent)
{
    UNDEFINED_VERSION2(11)
}

bool CheckProto_12(const StorageSeeds& input, const bool silent)
{
    UNDEFINED_VERSION2(12)
}

bool CheckProto_13(const StorageSeeds& input, const bool silent)
{
    UNDEFINED_VERSION2(13)
}

bool CheckProto_14(const StorageSeeds& input, const bool silent)
{
    UNDEFINED_VERSION2(14)
}

bool CheckProto_15(const StorageSeeds& input, const bool silent)
{
    UNDEFINED_VERSION2(15)
}

bool CheckProto_16(const StorageSeeds& input, const bool silent)
{
    UNDEFINED_VERSION2(16)
}

bool CheckProto_17(const StorageSeeds& input, const bool silent)
{
    UNDEFINED_VERSION2(17)
}

bool CheckProto_18(const StorageSeeds& input, const bool silent)
{
    UNDEFINED_VERSION2(18)
}

bool CheckProto_19(const StorageSeeds& input, const bool silent)
{
    UNDEFINED_VERSION2(19)
}

bool CheckProto_20(const StorageSeeds& input, const bool silent)
{
    UNDEFINED_VERSION2(20)
}
}  // namespace proto
}  // namespace opentxs
