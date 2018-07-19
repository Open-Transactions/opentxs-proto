// Copyright (c) 2018 The Open-Transactions developers
// This Source Code Form is subject to the terms of the Mozilla Public
// License, v. 2.0. If a copy of the MPL was not distributed with this
// file, You can obtain one at http://mozilla.org/MPL/2.0/.

#include "opentxs-proto/Types.hpp"
#include "opentxs-proto/Check.hpp"

#include <iostream>

#define PROTO_NAME "contact storage index"

namespace opentxs::proto
{
bool CheckProto_2(const StorageContacts& input, const bool silent)
{
    for (auto& merge : input.merge()) {
        try {
            const bool valid = Check(
                merge,
                StorageContactsAllowedList.at(input.version()).first,
                StorageContactsAllowedList.at(input.version()).second,
                silent);

            if (!valid) {
                FAIL("contact storage index", "invalid merge")
            }
        } catch (const std::out_of_range&) {
            FAIL2(
                "contact storage index",
                "allowed storage id list version not defined for version",
                input.version())
        }
    }

    for (auto& hash : input.contact()) {
        try {
            const bool valid = Check(
                hash,
                StorageContactsAllowedHash.at(input.version()).first,
                StorageContactsAllowedHash.at(input.version()).second,
                silent);

            if (!valid) {
                FAIL("contact storage index", "invalid hash")
            }
        } catch (const std::out_of_range&) {
            FAIL2(
                "contact storage index",
                "allowed storage item hash version not defined for version",
                input.version())
        }
    }

    for (auto& index : input.address()) {
        try {
            const bool valid = Check(
                index,
                StorageContactsAllowedAddress.at(input.version()).first,
                StorageContactsAllowedAddress.at(input.version()).second,
                silent);

            if (!valid) {
                FAIL("contact storage index", "invalid address index")
            }
        } catch (const std::out_of_range&) {
            FAIL2(
                "contact storage index",
                "allowed address index version not defined for version",
                input.version())
        }
    }

    for (auto& index : input.nym()) {
        try {
            const bool valid = Check(
                index,
                StorageContactsAllowedNym.at(input.version()).first,
                StorageContactsAllowedNym.at(input.version()).second,
                silent);

            if (!valid) {
                FAIL("contact storage index", "invalid nym index")
            }
        } catch (const std::out_of_range&) {
            FAIL2(
                "contact storage index",
                "allowed nym index version not defined for version",
                input.version())
        }
    }

    return true;
}

bool CheckProto_3(const StorageContacts& input, const bool silent)
{
    UNDEFINED_VERSION("contact storage index", 3)
}

bool CheckProto_4(const StorageContacts& input, const bool silent)
{
    UNDEFINED_VERSION("contact storage index", 4)
}

bool CheckProto_5(const StorageContacts& input, const bool silent)
{
    UNDEFINED_VERSION("contact storage index", 5)
}

bool CheckProto_6(const StorageContacts& input, const bool silent)
{
    UNDEFINED_VERSION2(6)
}

bool CheckProto_7(const StorageContacts& input, const bool silent)
{
    UNDEFINED_VERSION2(7)
}

bool CheckProto_8(const StorageContacts& input, const bool silent)
{
    UNDEFINED_VERSION2(8)
}

bool CheckProto_9(const StorageContacts& input, const bool silent)
{
    UNDEFINED_VERSION2(9)
}

bool CheckProto_10(const StorageContacts& input, const bool silent)
{
    UNDEFINED_VERSION2(10)
}

bool CheckProto_11(const StorageContacts& input, const bool silent)
{
    UNDEFINED_VERSION2(11)
}

bool CheckProto_12(const StorageContacts& input, const bool silent)
{
    UNDEFINED_VERSION2(12)
}

bool CheckProto_13(const StorageContacts& input, const bool silent)
{
    UNDEFINED_VERSION2(13)
}

bool CheckProto_14(const StorageContacts& input, const bool silent)
{
    UNDEFINED_VERSION2(14)
}

bool CheckProto_15(const StorageContacts& input, const bool silent)
{
    UNDEFINED_VERSION2(15)
}

bool CheckProto_16(const StorageContacts& input, const bool silent)
{
    UNDEFINED_VERSION2(16)
}

bool CheckProto_17(const StorageContacts& input, const bool silent)
{
    UNDEFINED_VERSION2(17)
}

bool CheckProto_18(const StorageContacts& input, const bool silent)
{
    UNDEFINED_VERSION2(18)
}

bool CheckProto_19(const StorageContacts& input, const bool silent)
{
    UNDEFINED_VERSION2(19)
}

bool CheckProto_20(const StorageContacts& input, const bool silent)
{
    UNDEFINED_VERSION2(20)
}
}  // namespace opentxs::proto
