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

bool CheckProto_1(const Seed& seed, const bool silent)
{
    if (!seed.has_words()) {
        FAIL("seed", "missing words")
    }

    const bool validWords = Check(
        seed.words(),
        SeedAllowedCiphertext.at(seed.version()).first,
        SeedAllowedCiphertext.at(seed.version()).second,
        silent,
        false);

    if (!validWords) {
        FAIL("seed", "invalid words")
    }

    if (seed.has_passphrase()) {
        const bool validWords = Check(
            seed.passphrase(),
            SeedAllowedCiphertext.at(seed.version()).first,
            SeedAllowedCiphertext.at(seed.version()).second,
            silent,
            false);

        if (!validWords) {
            FAIL("seed", "invalid passphrase")
        }

        if (seed.passphrase().has_key()) {
            FAIL(
                "seed", "passphrase not allowed to have embedded symmetric key")
        }
    }

    if (!seed.has_fingerprint()) {
        FAIL("seed", "missing fingerprint")
    }

    if (MIN_PLAUSIBLE_IDENTIFIER > seed.fingerprint().size()) {
        FAIL("seed", "invalid fingerprint")
    }

    if (seed.has_index()) {
        FAIL("seed", "index not allowed in this version")
    }

    return true;
}

}  // namespace proto
}  // namespace opentxs
