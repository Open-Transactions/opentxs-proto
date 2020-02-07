// Copyright (c) 2020 The Open-Transactions developers
// This Source Code Form is subject to the terms of the Mozilla Public
// License, v. 2.0. If a copy of the MPL was not distributed with this
// file, You can obtain one at http://mozilla.org/MPL/2.0/.

#include "opentxs-proto/Types.hpp"
#include "verify/Check.hpp"

#define PROTO_NAME "contact storage index"

namespace opentxs::proto
{
bool CheckProto_2(const StorageContacts& input, const bool silent)
{
    for (auto& merge : input.merge()) {
        try {
            const bool valid = Check(
                merge,
                StorageContactsAllowedList().at(input.version()).first,
                StorageContactsAllowedList().at(input.version()).second,
                silent);

            if (!valid) { FAIL_1("invalid merge") }
        } catch (const std::out_of_range&) {
            FAIL_2(
                "allowed storage id list version not defined for version",
                input.version())
        }
    }

    for (auto& hash : input.contact()) {
        try {
            const bool valid = Check(
                hash,
                StorageContactsAllowedStorageItemHash()
                    .at(input.version())
                    .first,
                StorageContactsAllowedStorageItemHash()
                    .at(input.version())
                    .second,
                silent);

            if (!valid) { FAIL_1("invalid hash") }
        } catch (const std::out_of_range&) {
            FAIL_2(
                "allowed storage item hash version not defined for version",
                input.version())
        }
    }

    for (auto& index : input.address()) {
        try {
            const bool valid = Check(
                index,
                StorageContactsAllowedAddress().at(input.version()).first,
                StorageContactsAllowedAddress().at(input.version()).second,
                silent);

            if (!valid) { FAIL_1("invalid address index") }
        } catch (const std::out_of_range&) {
            FAIL_2(
                "allowed address index version not defined for version",
                input.version())
        }
    }

    for (auto& index : input.nym()) {
        try {
            const bool valid = Check(
                index,
                StorageContactsAllowedStorageContactNymIndex()
                    .at(input.version())
                    .first,
                StorageContactsAllowedStorageContactNymIndex()
                    .at(input.version())
                    .second,
                silent);

            if (!valid) { FAIL_1("invalid nym index") }
        } catch (const std::out_of_range&) {
            FAIL_2(
                "allowed nym index version not defined for version",
                input.version())
        }
    }

    return true;
}

bool CheckProto_3(const StorageContacts& input, const bool silent)
{
    UNDEFINED_VERSION(3)
}

bool CheckProto_4(const StorageContacts& input, const bool silent)
{
    UNDEFINED_VERSION(4)
}

bool CheckProto_5(const StorageContacts& input, const bool silent)
{
    UNDEFINED_VERSION(5)
}

bool CheckProto_6(const StorageContacts& input, const bool silent)
{
    UNDEFINED_VERSION(6)
}

bool CheckProto_7(const StorageContacts& input, const bool silent)
{
    UNDEFINED_VERSION(7)
}

bool CheckProto_8(const StorageContacts& input, const bool silent)
{
    UNDEFINED_VERSION(8)
}

bool CheckProto_9(const StorageContacts& input, const bool silent)
{
    UNDEFINED_VERSION(9)
}

bool CheckProto_10(const StorageContacts& input, const bool silent)
{
    UNDEFINED_VERSION(10)
}

bool CheckProto_11(const StorageContacts& input, const bool silent)
{
    UNDEFINED_VERSION(11)
}

bool CheckProto_12(const StorageContacts& input, const bool silent)
{
    UNDEFINED_VERSION(12)
}

bool CheckProto_13(const StorageContacts& input, const bool silent)
{
    UNDEFINED_VERSION(13)
}

bool CheckProto_14(const StorageContacts& input, const bool silent)
{
    UNDEFINED_VERSION(14)
}

bool CheckProto_15(const StorageContacts& input, const bool silent)
{
    UNDEFINED_VERSION(15)
}

bool CheckProto_16(const StorageContacts& input, const bool silent)
{
    UNDEFINED_VERSION(16)
}

bool CheckProto_17(const StorageContacts& input, const bool silent)
{
    UNDEFINED_VERSION(17)
}

bool CheckProto_18(const StorageContacts& input, const bool silent)
{
    UNDEFINED_VERSION(18)
}

bool CheckProto_19(const StorageContacts& input, const bool silent)
{
    UNDEFINED_VERSION(19)
}

bool CheckProto_20(const StorageContacts& input, const bool silent)
{
    UNDEFINED_VERSION(20)
}
}  // namespace opentxs::proto
