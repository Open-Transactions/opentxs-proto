// Copyright (c) 2018 The Open-Transactions developers
// This Source Code Form is subject to the terms of the Mozilla Public
// License, v. 2.0. If a copy of the MPL was not distributed with this
// file, You can obtain one at http://mozilla.org/MPL/2.0/.

#include "opentxs-proto/Types.hpp"
#include "opentxs-proto/Check.hpp"

#define PROTO_NAME "seed"

namespace opentxs
{
namespace proto
{
bool CheckProto_2(const Seed& input, const bool silent)
{
    if (!input.has_words()) { FAIL_1("missing words") }

    try {
        const bool validWords = Check(
            input.words(),
            SeedAllowedCiphertext.at(input.version()).first,
            SeedAllowedCiphertext.at(input.version()).second,
            silent,
            false);

        if (!validWords) { FAIL_1("invalid words") }
    } catch (const std::out_of_range&) {
        FAIL_2(
            "allowed ciphertext version not defined for version",
            input.version())
    }

    if (input.has_passphrase()) {
        try {
            const bool validWords = Check(
                input.passphrase(),
                SeedAllowedCiphertext.at(input.version()).first,
                SeedAllowedCiphertext.at(input.version()).second,
                silent,
                false);

            if (!validWords) { FAIL_1("invalid passphrase") }
        } catch (const std::out_of_range&) {
            FAIL_2(
                "allowed ciphertext version not defined for version",
                input.version())
        }

        if (input.passphrase().has_key()) {
            FAIL_1("passphrase not allowed to have embedded symmetric key")
        }
    }

    if (!input.has_fingerprint()) { FAIL_1("missing fingerprint") }

    if (MIN_PLAUSIBLE_IDENTIFIER > input.fingerprint().size()) {
        FAIL_1("invalid fingerprint")
    }

    if (!input.has_index()) { FAIL_1("missing index") }

    return true;
}

bool CheckProto_3(const Seed& input, const bool silent) { UNDEFINED_VERSION(3) }

bool CheckProto_4(const Seed& input, const bool silent) { UNDEFINED_VERSION(4) }

bool CheckProto_5(const Seed& input, const bool silent) { UNDEFINED_VERSION(5) }

bool CheckProto_6(const Seed& input, const bool silent) { UNDEFINED_VERSION(6) }

bool CheckProto_7(const Seed& input, const bool silent) { UNDEFINED_VERSION(7) }

bool CheckProto_8(const Seed& input, const bool silent) { UNDEFINED_VERSION(8) }

bool CheckProto_9(const Seed& input, const bool silent) { UNDEFINED_VERSION(9) }

bool CheckProto_10(const Seed& input, const bool silent)
{
    UNDEFINED_VERSION(10)
}

bool CheckProto_11(const Seed& input, const bool silent)
{
    UNDEFINED_VERSION(11)
}

bool CheckProto_12(const Seed& input, const bool silent)
{
    UNDEFINED_VERSION(12)
}

bool CheckProto_13(const Seed& input, const bool silent)
{
    UNDEFINED_VERSION(13)
}

bool CheckProto_14(const Seed& input, const bool silent)
{
    UNDEFINED_VERSION(14)
}

bool CheckProto_15(const Seed& input, const bool silent)
{
    UNDEFINED_VERSION(15)
}

bool CheckProto_16(const Seed& input, const bool silent)
{
    UNDEFINED_VERSION(16)
}

bool CheckProto_17(const Seed& input, const bool silent)
{
    UNDEFINED_VERSION(17)
}

bool CheckProto_18(const Seed& input, const bool silent)
{
    UNDEFINED_VERSION(18)
}

bool CheckProto_19(const Seed& input, const bool silent)
{
    UNDEFINED_VERSION(19)
}

bool CheckProto_20(const Seed& input, const bool silent)
{
    UNDEFINED_VERSION(20)
}
}  // namespace proto
}  // namespace opentxs
