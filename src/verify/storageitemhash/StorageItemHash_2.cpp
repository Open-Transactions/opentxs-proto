// Copyright (c) 2020 The Open-Transactions developers
// This Source Code Form is subject to the terms of the Mozilla Public
// License, v. 2.0. If a copy of the MPL was not distributed with this
// file, You can obtain one at http://mozilla.org/MPL/2.0/.

#include "opentxs-proto/Types.hpp"
#include "verify/Check.hpp"

#define PROTO_NAME "storage item hash"

namespace opentxs
{
namespace proto
{
bool CheckProto_2(const StorageItemHash& input, const bool silent)
{
    if (!input.has_itemid()) { FAIL_1("missing id") }

    if (MIN_PLAUSIBLE_IDENTIFIER > input.itemid().size()) {
        FAIL_1("invalid id")
    }

    if (!input.has_hash()) { FAIL_1("missing hash") }

    if (MIN_PLAUSIBLE_IDENTIFIER > input.hash().size()) {
        FAIL_1("invalid hash")
    }

    if (!input.has_type()) { FAIL_1("missing type") }

    switch (input.type()) {
        case STORAGEHASH_PROTO:
        case STORAGEHASH_RAW: {
        } break;
        case STORAGEHASH_ERROR:
        default: {
            FAIL_1("invalid type")
        }
    }

    return true;
}

bool CheckProto_3(const StorageItemHash& input, const bool silent)
{
    return CheckProto_2(input, silent);
}

bool CheckProto_4(const StorageItemHash& input, const bool silent)
{
    return CheckProto_2(input, silent);
}

bool CheckProto_5(const StorageItemHash& input, const bool silent)
{
    return CheckProto_2(input, silent);
}

bool CheckProto_6(const StorageItemHash& input, const bool silent)
{
    return CheckProto_2(input, silent);
}

bool CheckProto_7(const StorageItemHash& input, const bool silent)
{
    return CheckProto_2(input, silent);
}

bool CheckProto_8(const StorageItemHash& input, const bool silent)
{
    return CheckProto_2(input, silent);
}

bool CheckProto_9(const StorageItemHash& input, const bool silent)
{
    return CheckProto_2(input, silent);
}

bool CheckProto_10(const StorageItemHash& input, const bool silent)
{
    UNDEFINED_VERSION(10)
}

bool CheckProto_11(const StorageItemHash& input, const bool silent)
{
    UNDEFINED_VERSION(11)
}

bool CheckProto_12(const StorageItemHash& input, const bool silent)
{
    UNDEFINED_VERSION(12)
}

bool CheckProto_13(const StorageItemHash& input, const bool silent)
{
    UNDEFINED_VERSION(13)
}

bool CheckProto_14(const StorageItemHash& input, const bool silent)
{
    UNDEFINED_VERSION(14)
}

bool CheckProto_15(const StorageItemHash& input, const bool silent)
{
    UNDEFINED_VERSION(15)
}

bool CheckProto_16(const StorageItemHash& input, const bool silent)
{
    UNDEFINED_VERSION(16)
}

bool CheckProto_17(const StorageItemHash& input, const bool silent)
{
    UNDEFINED_VERSION(17)
}

bool CheckProto_18(const StorageItemHash& input, const bool silent)
{
    UNDEFINED_VERSION(18)
}

bool CheckProto_19(const StorageItemHash& input, const bool silent)
{
    UNDEFINED_VERSION(19)
}

bool CheckProto_20(const StorageItemHash& input, const bool silent)
{
    UNDEFINED_VERSION(20)
}
}  // namespace proto
}  // namespace opentxs
