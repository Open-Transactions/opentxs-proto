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

bool CheckProto_1(
    const AsymmetricKey& serializedAsymmetricKey,
    const CredentialType type,
    const KeyMode mode,
    const KeyRole role)
{
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

    switch (type) {
        case CREDTYPE_LEGACY :
            if (serializedAsymmetricKey.has_chaincode()) {
                std::cerr << "Verify serialized asymmetric key failed: chain code not allowed in legacy credentials." << std::endl;
                return false;
            }

            if (serializedAsymmetricKey.has_path()) {
                std::cerr << "Verify serialized asymmetric key failed: HD path not allowed in legacy credentials." << std::endl;
                return false;
            }

            break;
        case CREDTYPE_HD :
            if (KEYMODE_PUBLIC == mode) {
                if (serializedAsymmetricKey.has_chaincode()) {
                    std::cerr << "Verify serialized asymmetric key failed: chain code not allowed in public credentials." << std::endl;
                    return false;
                }

                if (serializedAsymmetricKey.has_path()) {
                    std::cerr << "Verify serialized asymmetric key failed: HD path not allowed in public credentials." << std::endl;
                    return false;
                }
            } else {
                if (!serializedAsymmetricKey.has_chaincode()) {
                    std::cerr << "Verify serialized asymmetric key failed: Missing chain code." << std::endl;
                    return false;
                }
                if (MIN_PLAUSIBLE_KEYSIZE > serializedAsymmetricKey.chaincode().size()) {
                    std::cerr << "Verify serialized asymmetric key failed: invalid chain code ("
                    << serializedAsymmetricKey.chaincode() << ")." << std::endl;
                    return false;
                }
            }

            break;
        default :
            std::cerr << "Verify asymmetric key failed: incorrect or unknown credential type ("
                    << type << ")." << std::endl;

            return false;
    }

    return true;
}

} // namespace proto
} // namespace opentxs
