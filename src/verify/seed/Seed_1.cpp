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
bool CheckProto_1(const Seed& input, const bool silent)
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

    if (input.has_index()) { FAIL_1("index not allowed in this version") }

    return true;
}

}  // namespace proto
}  // namespace opentxs
