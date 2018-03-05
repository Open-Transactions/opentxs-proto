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

#define PROTO_NAME "ciphertext"

namespace opentxs
{
namespace proto
{

bool CheckProto_1(const Ciphertext& input, const bool silent, const bool nested)
{
    if (!input.has_mode()) {
        FAIL("ciphertext", "missing mode")
    }

    switch (input.mode()) {
        case (SMODE_CHACHA20POLY1305): {
            break;
        }
        default: {
            FAIL2("ciphertext", "invalid mode", input.mode())
        }
    }

    if (nested) {
        if (input.has_key()) {
            FAIL("ciphertext", "key present in nested ciphertext")
        }
    } else {
        if (input.has_key()) {
            try {
                const bool validKey = Check(
                    input.key(),
                    CiphertextAllowedSymmetricKey.at(input.version()).first,
                    CiphertextAllowedSymmetricKey.at(input.version()).second,
                    silent);

                if (!validKey) {
                    FAIL("ciphertext", "invalid key")
                }
            } catch (const std::out_of_range&) {
                FAIL2(
                    "ciphertext",
                    "allowed symmetric key version not defined for version",
                    input.version())
            }
        }
    }

    if (!input.has_iv()) {
        FAIL("ciphertext", "missing iv")
    }

    if (1 > input.iv().size()) {
        FAIL("ciphertext", "invalid iv")
    }

    if (!input.has_tag()) {
        FAIL("ciphertext", "missing tag")
    }

    if (1 > input.tag().size()) {
        FAIL("ciphertext", "invalid tag")
    }

    if (!input.has_data()) {
        FAIL("ciphertext", "missing data")
    }

    return true;
}
bool CheckProto_2(const Ciphertext& input, const bool silent, const bool)
{
    UNDEFINED_VERSION("ciphertext", 2)
}

bool CheckProto_3(const Ciphertext& input, const bool silent, const bool)
{
    UNDEFINED_VERSION("ciphertext", 3)
}

bool CheckProto_4(const Ciphertext& input, const bool silent, const bool)
{
    UNDEFINED_VERSION("ciphertext", 4)
}

bool CheckProto_5(const Ciphertext& input, const bool silent, const bool)
{
    UNDEFINED_VERSION("ciphertext", 5)
}

bool CheckProto_6(const Ciphertext& input, const bool silent, const bool)
{
    UNDEFINED_VERSION2(6)
}

bool CheckProto_7(const Ciphertext& input, const bool silent, const bool)
{
    UNDEFINED_VERSION2(7)
}

bool CheckProto_8(const Ciphertext& input, const bool silent, const bool)
{
    UNDEFINED_VERSION2(8)
}

bool CheckProto_9(const Ciphertext& input, const bool silent, const bool)
{
    UNDEFINED_VERSION2(9)
}

bool CheckProto_10(const Ciphertext& input, const bool silent, const bool)
{
    UNDEFINED_VERSION2(10)
}

bool CheckProto_11(const Ciphertext& input, const bool silent, const bool)
{
    UNDEFINED_VERSION2(11)
}

bool CheckProto_12(const Ciphertext& input, const bool silent, const bool)
{
    UNDEFINED_VERSION2(12)
}

bool CheckProto_13(const Ciphertext& input, const bool silent, const bool)
{
    UNDEFINED_VERSION2(13)
}

bool CheckProto_14(const Ciphertext& input, const bool silent, const bool)
{
    UNDEFINED_VERSION2(14)
}

bool CheckProto_15(const Ciphertext& input, const bool silent, const bool)
{
    UNDEFINED_VERSION2(15)
}

bool CheckProto_16(const Ciphertext& input, const bool silent, const bool)
{
    UNDEFINED_VERSION2(16)
}

bool CheckProto_17(const Ciphertext& input, const bool silent, const bool)
{
    UNDEFINED_VERSION2(17)
}

bool CheckProto_18(const Ciphertext& input, const bool silent, const bool)
{
    UNDEFINED_VERSION2(18)
}

bool CheckProto_19(const Ciphertext& input, const bool silent, const bool)
{
    UNDEFINED_VERSION2(19)
}

bool CheckProto_20(const Ciphertext& input, const bool silent, const bool)
{
    UNDEFINED_VERSION2(20)
}
}  // namespace proto
}  // namespace opentxs
