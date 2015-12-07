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

#include "opentxs-proto/verify/AsymmetricKey.hpp"

#include <iostream>

namespace opentxs { namespace proto
{

bool AsymmetricKey_1(
    const AsymmetricKey& serializedAsymmetricKey,
    const CredentialType type,
    const KeyMode mode,
    const KeyRole role)
{
    switch (type) {
        case CREDTYPE_LEGACY :
            if (!serializedAsymmetricKey.has_type()) {
                std::cerr << "Verify serialized asymmetric key failed: missing key type." << std::endl;
                return false;
            }

            if ((AKEYTYPE_LEGACY != serializedAsymmetricKey.type()) && (AKEYTYPE_SECP256K1 != serializedAsymmetricKey.type())) {
                std::cerr << "Verify serialized asymmetric key failed: incorrect key type ("
                << serializedAsymmetricKey.type() << ")." << std::endl;
                return false;
            }

            if (!serializedAsymmetricKey.has_mode()) {
                std::cerr << "Verify serialized asymmetric key failed: missing key mode." << std::endl;
                return false;
            }

            if (serializedAsymmetricKey.mode() != mode) {
                std::cerr << "Verify serialized asymmetric key failed: incorrect key mode ("
                << serializedAsymmetricKey.mode() << ")." << std::endl;
                return false;
            }

            if (!serializedAsymmetricKey.has_role()) {
                std::cerr << "Verify serialized asymmetric key failed: missing key role." << std::endl;
                return false;
            }

            if (serializedAsymmetricKey.role() != role) {
                std::cerr << "Verify serialized asymmetric key failed: incorrect key role ("
                << serializedAsymmetricKey.role() << ")." << std::endl;
                return false;
            }

            if (!serializedAsymmetricKey.has_key()) {
                std::cerr << "Verify serialized asymmetric key failed: missing key." << std::endl;
                return false;
            }

            if (MIN_PLAUSIBLE_KEYSIZE > serializedAsymmetricKey.key().size()) {
                std::cerr << "Verify serialized asymmetric key failed: invalid key ("
                << serializedAsymmetricKey.key() << ")." << std::endl;
                return false;
            }

            if (serializedAsymmetricKey.has_chaincode()) {
                std::cerr << "Verify serialized asymmetric key failed: chaincode not allowed for this key version." << std::endl;
                return false;
            }

            if (serializedAsymmetricKey.has_path()) {
                std::cerr << "Verify serialized asymmetric key failed: path not allowed for this key version." << std::endl;
                return false;
            }

            break;
        default :
            std::cerr << "Verify asymmetric key failed: incorrect or unknown credential; type ("
                    << serializedAsymmetricKey.type() << ")." << std::endl;

            return false;
    }

    return true;
}

} // namespace proto
} // namespace opentxs
