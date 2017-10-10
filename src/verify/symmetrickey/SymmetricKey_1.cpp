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

bool CheckProto_1(const SymmetricKey& key, const bool silent)
{
    try {
        const bool validKey = Check(
            key.key(),
            SymmetricKeyAllowedCiphertext.at(key.version()).first,
            SymmetricKeyAllowedCiphertext.at(key.version()).second,
            silent,
            true);

        if (!validKey) {
            FAIL("symmetric key", "invalid encrypted key")
        }
    } catch (const std::out_of_range&) {
        FAIL2(
            "symmetric key",
            "allowed ciphertext version not defined for version",
            key.version())
    }

    if (!key.has_size()) {
        FAIL("symmetric key", "missing size")
    }

    if (!key.has_type()) {
        FAIL("symmetric key", "missing type")
    }

    switch (key.type()) {
        case (SKEYTYPE_RAW):
        case (SKEYTYPE_ECDH): {
            break;
        }
        case (SKEYTYPE_ARGON2): {
            if (!key.has_salt()) {
                FAIL("symmetric key", "missing salt")
            }

            if (1 > key.operations()) {
                FAIL("symmetric key", "missing operations")
            }

            if (1 > key.difficulty()) {
                FAIL("symmetric key", "missing difficulty")
            }

            break;
        }
        default: {
            FAIL2("symmetric key", "invalid type", key.type())
        }
    }

    return true;
}
bool CheckProto_2(const SymmetricKey&, const bool) { return false; }
bool CheckProto_3(const SymmetricKey&, const bool) { return false; }
bool CheckProto_4(const SymmetricKey&, const bool) { return false; }
bool CheckProto_5(const SymmetricKey&, const bool) { return false; }
}  // namespace proto
}  // namespace opentxs
