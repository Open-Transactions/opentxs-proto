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

#include "opentxs-proto/verify/SymmetricKey.hpp"

#include <iostream>

namespace opentxs { namespace proto
{

    bool CheckProto_1(const SymmetricKey& key)
{
    const bool validKey = Check(
        key.key(),
        SymmetricKeyAllowedCiphertext.at(key.version()).first,
        SymmetricKeyAllowedCiphertext.at(key.version()).second,
        true);

    if (!validKey) {
        std::cerr << "Verify serialized symmetric key failed: invalid "
                    << "encrypted key." <<  std::endl;

        return false;
    }

    if (!key.has_size()) {
        std::cerr << "Verify serialized symmetric key failed: missing size."
                  << std::endl;

        return false;
    }

    if (!key.has_type()) {
        std::cerr << "Verify serialized symmetric key failed: missing type."
                  << std::endl;

        return false;
    }

    switch (key.type()) {
        case (SKEYTYPE_RAW) :
        case (SKEYTYPE_ECDH) : { break; }
        case (SKEYTYPE_ARGON2) : {
            if (!key.has_salt()) {
                std::cerr << "Verify serialized symmetric key failed: missing "
                          << " salt." << std::endl;

                return false;
            }

            if (1 > key.operations()) {
                std::cerr << "Verify serialized symmetric key failed: missing "
                          << " operations." << std::endl;

                return false;
            }

            if (1 > key.difficulty()) {
                std::cerr << "Verify serialized symmetric key failed: missing "
                          << " difficulty." << std::endl;

                return false;
            }

            break;
        }
        default : {
            std::cerr << "Verify serialized symmetric key failed: invalid type ("
                      << key.type() << ")" << std::endl;

            return false;
        }
    }

    return true;
}
bool CheckProto_2(const SymmetricKey&) { return false; }
} // namespace proto
} // namespace opentxs
