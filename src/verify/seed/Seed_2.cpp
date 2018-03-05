/************************************************************
 *
 *                 OPEN TRANSACTIONS
 *
 *       Financial Cryptography and Digital Cash
 *       Library, Protocol, API, Server, CLI, GUI
 *
 *       -- Anonymous Numbered Accounts.
 *       -- Untraceable Digital Cash.
 *       -- Triple-Signed Receipts.
 *       -- Cheques, Vouchers, Transfers, Inboxes.
 *       -- Basket Currencies, Markets, Payment Plans.
 *       -- Signed, XML, Ricardian-style Contracts.
 *       -- Scripted smart contracts.
 *
 *  EMAIL:
 *  fellowtraveler@opentransactions.org
 *
 *  WEBSITE:
 *  http://www.opentransactions.org/
 *
 *  -----------------------------------------------------
 *
 *   LICENSE:
 *   This Source Code Form is subject to the terms of the
 *   Mozilla Public License, v. 2.0. If a copy of the MPL
 *   was not distributed with this file, You can obtain one
 *   at http://mozilla.org/MPL/2.0/.
 *
 *   DISCLAIMER:
 *   This program is distributed in the hope that it will
 *   be useful, but WITHOUT ANY WARRANTY; without even the
 *   implied warranty of MERCHANTABILITY or FITNESS FOR A
 *   PARTICULAR PURPOSE.  See the Mozilla Public License
 *   for more details.
 *
 ************************************************************/

#include "opentxs-proto/Types.hpp"
#include "opentxs-proto/Check.hpp"

#include <iostream>

#define PROTO_NAME "seed"

namespace opentxs
{
namespace proto
{

bool CheckProto_2(const Seed& input, const bool silent)
{
    if (!input.has_words()) {
        FAIL("seed", "missing words")
    }

    try {
        const bool validWords = Check(
            input.words(),
            SeedAllowedCiphertext.at(input.version()).first,
            SeedAllowedCiphertext.at(input.version()).second,
            silent,
            false);

        if (!validWords) {
            FAIL("seed", "invalid words")
        }
    } catch (const std::out_of_range&) {
        FAIL2(
            "seed",
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

            if (!validWords) {
                FAIL("seed", "invalid passphrase")
            }
        } catch (const std::out_of_range&) {
            FAIL2(
                "seed",
                "allowed ciphertext version not defined for version",
                input.version())
        }

        if (input.passphrase().has_key()) {
            FAIL(
                "seed", "passphrase not allowed to have embedded symmetric key")
        }
    }

    if (!input.has_fingerprint()) {
        FAIL("seed", "missing fingerprint")
    }

    if (MIN_PLAUSIBLE_IDENTIFIER > input.fingerprint().size()) {
        FAIL("seed", "invalid fingerprint")
    }

    if (!input.has_index()) {
        FAIL("seed", "missing index")
    }

    return true;
}

bool CheckProto_3(const Seed& input, const bool silent)
{
    UNDEFINED_VERSION("seed", 3)
}

bool CheckProto_4(const Seed& input, const bool silent)
{
    UNDEFINED_VERSION("seed", 4)
}

bool CheckProto_5(const Seed& input, const bool silent)
{
    UNDEFINED_VERSION("seed", 5)
}

bool CheckProto_6(const Seed& input, const bool silent)
{
    UNDEFINED_VERSION2(6)
}

bool CheckProto_7(const Seed& input, const bool silent)
{
    UNDEFINED_VERSION2(7)
}

bool CheckProto_8(const Seed& input, const bool silent)
{
    UNDEFINED_VERSION2(8)
}

bool CheckProto_9(const Seed& input, const bool silent)
{
    UNDEFINED_VERSION2(9)
}

bool CheckProto_10(const Seed& input, const bool silent)
{
    UNDEFINED_VERSION2(10)
}

bool CheckProto_11(const Seed& input, const bool silent)
{
    UNDEFINED_VERSION2(11)
}

bool CheckProto_12(const Seed& input, const bool silent)
{
    UNDEFINED_VERSION2(12)
}

bool CheckProto_13(const Seed& input, const bool silent)
{
    UNDEFINED_VERSION2(13)
}

bool CheckProto_14(const Seed& input, const bool silent)
{
    UNDEFINED_VERSION2(14)
}

bool CheckProto_15(const Seed& input, const bool silent)
{
    UNDEFINED_VERSION2(15)
}

bool CheckProto_16(const Seed& input, const bool silent)
{
    UNDEFINED_VERSION2(16)
}

bool CheckProto_17(const Seed& input, const bool silent)
{
    UNDEFINED_VERSION2(17)
}

bool CheckProto_18(const Seed& input, const bool silent)
{
    UNDEFINED_VERSION2(18)
}

bool CheckProto_19(const Seed& input, const bool silent)
{
    UNDEFINED_VERSION2(19)
}

bool CheckProto_20(const Seed& input, const bool silent)
{
    UNDEFINED_VERSION2(20)
}
}  // namespace proto
}  // namespace opentxs
