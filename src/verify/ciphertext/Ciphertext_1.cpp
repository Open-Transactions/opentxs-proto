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

#include "opentxs-proto/verify/Ciphertext.hpp"

#include <iostream>

namespace opentxs { namespace proto
{

    bool CheckProto_1(const Ciphertext& data , const bool nested)
{
    if (!data.has_mode()) {
        std::cerr << "Verify serialized ciphertext failed: missing mode."
                  << std::endl;

        return false;
    }

    switch (data.mode()) {
        case (SMODE_CHACHA20POLY1305) : { break; }
        default : {
            std::cerr << "Verify serialized ciphertext failed: invalid mode ("
                      << data.mode() << ")" << std::endl;

            return false;
        }
    }

    if (nested) {
        if (data.has_key()) {
            std::cerr << "Verify serialized ciphertext failed: key present in "
                      << "nested ciphertext." <<  std::endl;

            return false;
        }
    } else {
        if (data.has_key()) {
            const bool validKey = Check(
                data.key(),
                CiphertextAllowedSymmetricKey.at(data.version()).first,
                CiphertextAllowedSymmetricKey.at(data.version()).second);

            if (!validKey) {
                std::cerr << "Verify serialized ciphertext failed: invalid "
                          << "key." <<  std::endl;

                return false;
            }
        }
    }

    if (!data.has_iv()) {
        std::cerr << "Verify serialized ciphertext failed: missing iv."
                  << std::endl;

        return false;
    }

    if (1 > data.iv().size()) {
        std::cerr << "Verify serialized ciphertext failed: invalid iv."
                  << std::endl;

        return false;
    }

    if (!data.has_tag()) {
        std::cerr << "Verify serialized ciphertext failed: missing tag."
                  << std::endl;

        return false;
    }

    if (1 > data.tag().size()) {
        std::cerr << "Verify serialized ciphertext failed: invalid tag."
                  << std::endl;

        return false;
    }

    if (!data.has_data()) {
        std::cerr << "Verify serialized ciphertext failed: missing data."
                  << std::endl;

        return false;
    }

    return true;
}

} // namespace proto
} // namespace opentxs
