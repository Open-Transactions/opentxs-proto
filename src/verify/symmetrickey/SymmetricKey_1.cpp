// Copyright (c) 2020 The Open-Transactions developers
// This Source Code Form is subject to the terms of the Mozilla Public
// License, v. 2.0. If a copy of the MPL was not distributed with this
// file, You can obtain one at http://mozilla.org/MPL/2.0/.

#include "opentxs-proto/Types.hpp"
#include "verify/Check.hpp"

#define PROTO_NAME "symmetric key"

namespace opentxs
{
namespace proto
{

bool CheckProto_1(const SymmetricKey& input, const bool silent)
{
    try {
        const bool validKey = Check(
            input.key(),
            SymmetricKeyAllowedCiphertext().at(input.version()).first,
            SymmetricKeyAllowedCiphertext().at(input.version()).second,
            silent,
            true);

        if (!validKey) { FAIL_1("invalid encrypted key") }
    } catch (const std::out_of_range&) {
        FAIL_2(
            "allowed ciphertext version not defined for version",
            input.version())
    }

    if (!input.has_size()) { FAIL_1("missing size") }

    if (!input.has_type()) { FAIL_1("missing type") }

    switch (input.type()) {
        case SKEYTYPE_RAW:
        case SKEYTYPE_ECDH: {
        } break;
        case SKEYTYPE_ARGON2: {
            if (!input.has_salt()) { FAIL_1("missing salt") }

            if (1 > input.operations()) { FAIL_1("missing operations") }

            if (1 > input.difficulty()) { FAIL_1("missing difficulty") }
        } break;
        case SKEYTYPE_ERROR:
        default: {
            FAIL_2("invalid type", input.type())
        }
    }

    return true;
}

bool CheckProto_2(const SymmetricKey& input, const bool silent)
{
    UNDEFINED_VERSION(2)
}

bool CheckProto_3(const SymmetricKey& input, const bool silent)
{
    UNDEFINED_VERSION(3)
}

bool CheckProto_4(const SymmetricKey& input, const bool silent)
{
    UNDEFINED_VERSION(4)
}

bool CheckProto_5(const SymmetricKey& input, const bool silent)
{
    UNDEFINED_VERSION(5)
}

bool CheckProto_6(const SymmetricKey& input, const bool silent)
{
    UNDEFINED_VERSION(6)
}

bool CheckProto_7(const SymmetricKey& input, const bool silent)
{
    UNDEFINED_VERSION(7)
}

bool CheckProto_8(const SymmetricKey& input, const bool silent)
{
    UNDEFINED_VERSION(8)
}

bool CheckProto_9(const SymmetricKey& input, const bool silent)
{
    UNDEFINED_VERSION(9)
}

bool CheckProto_10(const SymmetricKey& input, const bool silent)
{
    UNDEFINED_VERSION(10)
}

bool CheckProto_11(const SymmetricKey& input, const bool silent)
{
    UNDEFINED_VERSION(11)
}

bool CheckProto_12(const SymmetricKey& input, const bool silent)
{
    UNDEFINED_VERSION(12)
}

bool CheckProto_13(const SymmetricKey& input, const bool silent)
{
    UNDEFINED_VERSION(13)
}

bool CheckProto_14(const SymmetricKey& input, const bool silent)
{
    UNDEFINED_VERSION(14)
}

bool CheckProto_15(const SymmetricKey& input, const bool silent)
{
    UNDEFINED_VERSION(15)
}

bool CheckProto_16(const SymmetricKey& input, const bool silent)
{
    UNDEFINED_VERSION(16)
}

bool CheckProto_17(const SymmetricKey& input, const bool silent)
{
    UNDEFINED_VERSION(17)
}

bool CheckProto_18(const SymmetricKey& input, const bool silent)
{
    UNDEFINED_VERSION(18)
}

bool CheckProto_19(const SymmetricKey& input, const bool silent)
{
    UNDEFINED_VERSION(19)
}

bool CheckProto_20(const SymmetricKey& input, const bool silent)
{
    UNDEFINED_VERSION(20)
}
}  // namespace proto
}  // namespace opentxs
