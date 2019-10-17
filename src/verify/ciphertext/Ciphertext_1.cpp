// Copyright (c) 2019 The Open-Transactions developers
// This Source Code Form is subject to the terms of the Mozilla Public
// License, v. 2.0. If a copy of the MPL was not distributed with this
// file, You can obtain one at http://mozilla.org/MPL/2.0/.

#include "opentxs-proto/Types.hpp"
#include "verify/Check.hpp"

#define PROTO_NAME "ciphertext"

namespace opentxs
{
namespace proto
{

bool CheckProto_1(const Ciphertext& input, const bool silent, const bool nested)
{
    if (!input.has_mode()) { FAIL_1("missing mode") }

    switch (input.mode()) {
        case SMODE_CHACHA20POLY1305: {
            break;
        }
        case SMODE_ERROR:
        default: {
            FAIL_2("invalid mode", input.mode())
        }
    }

    if (nested) {
        if (input.has_key()) { FAIL_1("key present in nested ciphertext") }
    } else {
        if (input.has_key()) {
            try {
                const bool validKey = Check(
                    input.key(),
                    CiphertextAllowedSymmetricKey.at(input.version()).first,
                    CiphertextAllowedSymmetricKey.at(input.version()).second,
                    silent);

                if (!validKey) { FAIL_1("invalid key") }
            } catch (const std::out_of_range&) {
                FAIL_2(
                    "allowed symmetric key version not defined for version",
                    input.version())
            }
        }
    }

    if (!input.has_iv()) { FAIL_1("missing iv") }

    if (1 > input.iv().size()) { FAIL_1("invalid iv") }

    if (!input.has_tag()) { FAIL_1("missing tag") }

    if (1 > input.tag().size()) { FAIL_1("invalid tag") }

    if (!input.has_data()) { FAIL_1("missing data") }

    return true;
}
bool CheckProto_2(const Ciphertext& input, const bool silent, const bool)
{
    UNDEFINED_VERSION(2)
}

bool CheckProto_3(const Ciphertext& input, const bool silent, const bool)
{
    UNDEFINED_VERSION(3)
}

bool CheckProto_4(const Ciphertext& input, const bool silent, const bool)
{
    UNDEFINED_VERSION(4)
}

bool CheckProto_5(const Ciphertext& input, const bool silent, const bool)
{
    UNDEFINED_VERSION(5)
}

bool CheckProto_6(const Ciphertext& input, const bool silent, const bool)
{
    UNDEFINED_VERSION(6)
}

bool CheckProto_7(const Ciphertext& input, const bool silent, const bool)
{
    UNDEFINED_VERSION(7)
}

bool CheckProto_8(const Ciphertext& input, const bool silent, const bool)
{
    UNDEFINED_VERSION(8)
}

bool CheckProto_9(const Ciphertext& input, const bool silent, const bool)
{
    UNDEFINED_VERSION(9)
}

bool CheckProto_10(const Ciphertext& input, const bool silent, const bool)
{
    UNDEFINED_VERSION(10)
}

bool CheckProto_11(const Ciphertext& input, const bool silent, const bool)
{
    UNDEFINED_VERSION(11)
}

bool CheckProto_12(const Ciphertext& input, const bool silent, const bool)
{
    UNDEFINED_VERSION(12)
}

bool CheckProto_13(const Ciphertext& input, const bool silent, const bool)
{
    UNDEFINED_VERSION(13)
}

bool CheckProto_14(const Ciphertext& input, const bool silent, const bool)
{
    UNDEFINED_VERSION(14)
}

bool CheckProto_15(const Ciphertext& input, const bool silent, const bool)
{
    UNDEFINED_VERSION(15)
}

bool CheckProto_16(const Ciphertext& input, const bool silent, const bool)
{
    UNDEFINED_VERSION(16)
}

bool CheckProto_17(const Ciphertext& input, const bool silent, const bool)
{
    UNDEFINED_VERSION(17)
}

bool CheckProto_18(const Ciphertext& input, const bool silent, const bool)
{
    UNDEFINED_VERSION(18)
}

bool CheckProto_19(const Ciphertext& input, const bool silent, const bool)
{
    UNDEFINED_VERSION(19)
}

bool CheckProto_20(const Ciphertext& input, const bool silent, const bool)
{
    UNDEFINED_VERSION(20)
}
}  // namespace proto
}  // namespace opentxs
