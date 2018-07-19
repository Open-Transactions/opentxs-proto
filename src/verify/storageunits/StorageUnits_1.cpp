// Copyright (c) 2018 The Open-Transactions developers
// This Source Code Form is subject to the terms of the Mozilla Public
// License, v. 2.0. If a copy of the MPL was not distributed with this
// file, You can obtain one at http://mozilla.org/MPL/2.0/.

#include "opentxs-proto/Types.hpp"
#include "opentxs-proto/Check.hpp"

#include <iostream>

#define PROTO_NAME "unit storage index"

namespace opentxs
{
namespace proto
{

bool CheckProto_1(const StorageUnits& input, const bool silent)
{
    for (auto& hash : input.unit()) {
        try {
            const bool valid = Check(
                hash,
                StorageUnitsAllowedHash.at(input.version()).first,
                StorageUnitsAllowedHash.at(input.version()).second,
                silent);

            if (!valid) {
                FAIL("unit storage index", "invalid hash")
            }
        } catch (const std::out_of_range&) {
            FAIL2(
                "unit storage index",
                "allowed storage item hash version not defined for version",
                input.version())
        }
    }

    return true;
}

bool CheckProto_2(const StorageUnits& input, const bool silent)
{
    return CheckProto_1(input, silent);
}

bool CheckProto_3(const StorageUnits& input, const bool silent)
{
    UNDEFINED_VERSION("unit storage index", 3)
}

bool CheckProto_4(const StorageUnits& input, const bool silent)
{
    UNDEFINED_VERSION("unit storage index", 4)
}

bool CheckProto_5(const StorageUnits& input, const bool silent)
{
    UNDEFINED_VERSION("unit storage index", 5)
}

bool CheckProto_6(const StorageUnits& input, const bool silent)
{
    UNDEFINED_VERSION2(6)
}

bool CheckProto_7(const StorageUnits& input, const bool silent)
{
    UNDEFINED_VERSION2(7)
}

bool CheckProto_8(const StorageUnits& input, const bool silent)
{
    UNDEFINED_VERSION2(8)
}

bool CheckProto_9(const StorageUnits& input, const bool silent)
{
    UNDEFINED_VERSION2(9)
}

bool CheckProto_10(const StorageUnits& input, const bool silent)
{
    UNDEFINED_VERSION2(10)
}

bool CheckProto_11(const StorageUnits& input, const bool silent)
{
    UNDEFINED_VERSION2(11)
}

bool CheckProto_12(const StorageUnits& input, const bool silent)
{
    UNDEFINED_VERSION2(12)
}

bool CheckProto_13(const StorageUnits& input, const bool silent)
{
    UNDEFINED_VERSION2(13)
}

bool CheckProto_14(const StorageUnits& input, const bool silent)
{
    UNDEFINED_VERSION2(14)
}

bool CheckProto_15(const StorageUnits& input, const bool silent)
{
    UNDEFINED_VERSION2(15)
}

bool CheckProto_16(const StorageUnits& input, const bool silent)
{
    UNDEFINED_VERSION2(16)
}

bool CheckProto_17(const StorageUnits& input, const bool silent)
{
    UNDEFINED_VERSION2(17)
}

bool CheckProto_18(const StorageUnits& input, const bool silent)
{
    UNDEFINED_VERSION2(18)
}

bool CheckProto_19(const StorageUnits& input, const bool silent)
{
    UNDEFINED_VERSION2(19)
}

bool CheckProto_20(const StorageUnits& input, const bool silent)
{
    UNDEFINED_VERSION2(20)
}
}  // namespace proto
}  // namespace opentxs
