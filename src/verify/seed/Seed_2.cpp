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

namespace opentxs { namespace proto
{

bool CheckProto_2(const Seed& seed)
{
    if (!seed.has_words()) {
        std::cerr << "Verify serialized seed failed: missing words."
                  << std::endl;

        return false;
    }

    const bool validWords = Check(
        seed.words(),
        SeedAllowedCiphertext.at(seed.version()).first,
        SeedAllowedCiphertext.at(seed.version()).second,
        false);

    if (!validWords) {
        std::cerr << "Verify serialized seed failed: invalid words."
                  <<  std::endl;

        return false;
    }

    if (seed.has_passphrase()) {
        const bool validWords = Check(
            seed.passphrase(),
            SeedAllowedCiphertext.at(seed.version()).first,
            SeedAllowedCiphertext.at(seed.version()).second,
            false);

        if (!validWords) {
            std::cerr << "Verify serialized seed failed: invalid passphrase."
                      <<  std::endl;

            return false;
        }

        if (seed.passphrase().has_key()) {
            std::cerr << "Verify serialized seed failed: passphrase not "
                      << "allowed to have embedded symmetric key."
                      <<  std::endl;
        }
    }

    if (!seed.has_fingerprint()) {
        std::cerr << "Verify serialized seed failed: missing fingerprint."
                  << std::endl;

        return false;
    }

    if (MIN_PLAUSIBLE_IDENTIFIER > seed.fingerprint().size()) {
        std::cerr << "Verify serialized seed failed: invalid fingerprint."
                  << std::endl;

        return false;
    }

    if (!seed.has_index()) {
        std::cerr << "Verify serialized seed failed: missing index."
                  << std::endl;

        return false;
    }

    return true;
}
bool CheckProto_3(const Seed&) { return false; }
bool CheckProto_4(const Seed&) { return false; }
bool CheckProto_5(const Seed&) { return false; }
} // namespace proto
} // namespace opentxs
