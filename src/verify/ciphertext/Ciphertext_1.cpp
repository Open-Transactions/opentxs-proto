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

namespace opentxs
{
namespace proto
{

bool CheckProto_1(const Ciphertext& data, const bool silent, const bool nested)
{
    if (!data.has_mode()) {
        FAIL("ciphertext", "missing mode")
    }

    switch (data.mode()) {
        case (SMODE_CHACHA20POLY1305): {
            break;
        }
        default: {
            FAIL2("ciphertext", "invalid mode", data.mode())
        }
    }

    if (nested) {
        if (data.has_key()) {
            FAIL("ciphertext", "key present in nested ciphertext")
        }
    } else {
        if (data.has_key()) {
            try {
                const bool validKey = Check(
                    data.key(),
                    CiphertextAllowedSymmetricKey.at(data.version()).first,
                    CiphertextAllowedSymmetricKey.at(data.version()).second,
                    silent);

                if (!validKey) {
                    FAIL("ciphertext", "invalid key")
                }
            } catch (const std::out_of_range&) {
                FAIL2(
                    "ciphertext",
                    "allowed symmetric key version not defined for version",
                    data.version())
            }
        }
    }

    if (!data.has_iv()) {
        FAIL("ciphertext", "missing iv")
    }

    if (1 > data.iv().size()) {
        FAIL("ciphertext", "invalid iv")
    }

    if (!data.has_tag()) {
        FAIL("ciphertext", "missing tag")
    }

    if (1 > data.tag().size()) {
        FAIL("ciphertext", "invalid tag")
    }

    if (!data.has_data()) {
        FAIL("ciphertext", "missing data")
    }

    return true;
}
bool CheckProto_2(const Ciphertext&, const bool, const bool silent)
{
    UNDEFINED_VERSION("ciphertext", 2)
}

bool CheckProto_3(const Ciphertext&, const bool, const bool silent)
{
    UNDEFINED_VERSION("ciphertext", 3)
}

bool CheckProto_4(const Ciphertext&, const bool, const bool silent)
{
    UNDEFINED_VERSION("ciphertext", 4)
}

bool CheckProto_5(const Ciphertext&, const bool, const bool silent)
{
    UNDEFINED_VERSION("ciphertext", 5)
}
}  // namespace proto
}  // namespace opentxs
