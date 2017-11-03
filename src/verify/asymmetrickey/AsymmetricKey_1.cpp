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

bool CheckProto_1(
    const AsymmetricKey& input,
    const bool silent,
    const CredentialType type,
    const KeyMode mode,
    const KeyRole role)
{
    if (!input.has_type()) {
        FAIL("asymmetric key", "missing key type")
    }

    switch (input.type()) {
        case (AKEYTYPE_LEGACY): {
            break;
        }
        case (AKEYTYPE_SECP256K1): {
            break;
        }
        case (AKEYTYPE_ED25519): {
            break;
        }
        default: {
            FAIL2("asymmetric key", "incorrect key type", input.type())
        }
    }

    if (!input.has_mode()) {
        FAIL("asymmetric key", "missing key mode")
    }

    if (input.mode() != mode) {
        FAIL2("asymmetric key", "incorrect key mode", input.mode())
    }

    if (!input.has_role()) {
        FAIL("asymmetric key", "missing key role")
    }

    if (input.role() != role) {
        FAIL2("asymmetric key", "incorrect key role", input.role())
    }

    if (KEYMODE_PUBLIC == mode) {
        if (!input.has_key()) {
            FAIL("asymmetric key", "missing key")
        }

        if (MIN_PLAUSIBLE_KEYSIZE > input.key().size()) {
            FAIL2("asymmetric key", "invalid key", input.key())
        }
        if (input.has_encryptedkey()) {
            FAIL("asymmetric key", "encrypted data present in public key")
        }
    } else {
        if (AKEYTYPE_LEGACY == input.type()) {
            if (!input.has_key()) {
                FAIL("asymmetric key", "missing key")
            }

            if (MIN_PLAUSIBLE_KEYSIZE > input.key().size()) {
                FAIL2("asymmetric key", "invalid key", input.key())
            }

            if (input.has_encryptedkey()) {
                FAIL("asymmetric key", "encrypted data present in legacy key")
            }
        } else {
            if (!input.has_encryptedkey()) {
                FAIL("asymmetric key", "missing encrypted key")
            }

            try {
                const bool validEncryptedKey = Check(
                    input.encryptedkey(),
                    AsymmetricKeyAllowedCiphertext.at(input.version()).first,
                    AsymmetricKeyAllowedCiphertext.at(input.version()).second,
                    silent,
                    false);

                if (!validEncryptedKey) {
                    FAIL("asymmetric key", "invalid encrypted key")
                }
            } catch (const std::out_of_range&) {
                FAIL2(
                    "asymmetric key",
                    "allowed ciphertext version not defined for version",
                    input.version())
            }

            if (input.has_key()) {
                FAIL("asymmetric key", "plaintext data found in private key")
            }
        }
    }

    switch (type) {
        case CREDTYPE_LEGACY:
            if (input.has_chaincode()) {
                FAIL(
                    "asymmetric key",
                    "chain code not allowed in legacy credentials")
            }

            if (input.has_path()) {
                FAIL(
                    "asymmetric key",
                    "HD path not allowed in legacy credentials")
            }

            break;
        case CREDTYPE_HD:
            if (KEYMODE_PUBLIC == mode) {
                if (input.has_chaincode()) {
                    FAIL(
                        "asymmetric key",
                        "chain code not allowed in public credentials")
                }

                if (input.has_path()) {
                    FAIL(
                        "asymmetric key",
                        "HD path not allowed in public credentials")
                }
            } else {
                if (!input.has_chaincode()) {
                    FAIL("asymmetric key", "missing chain code")
                }

                try {
                    const bool validChainCode = Check(
                        input.chaincode(),
                        AsymmetricKeyAllowedCiphertext.at(input.version())
                            .first,
                        AsymmetricKeyAllowedCiphertext.at(input.version())
                            .second,
                        silent,
                        false);

                    if (!validChainCode) {
                        FAIL("asymmetric key", "invalid chain code")
                    }
                } catch (const std::out_of_range&) {
                    FAIL2(
                        "asymmetric key",
                        "allowed ciphertext version not defined for version",
                        input.version())
                }

                if (!input.has_path()) {
                    FAIL("asymmetric key", "missing HD path")
                }

                try {
                    bool validPath = Check(
                        input.path(),
                        AsymmetricKeyAllowedHDPath.at(input.version()).first,
                        AsymmetricKeyAllowedHDPath.at(input.version()).second,
                        silent);

                    if (!validPath) {
                        FAIL("asymmetric key", "invalid HD path")
                    }
                } catch (const std::out_of_range&) {
                    FAIL2(
                        "asymmetric key",
                        "allowed HD path version not defined for version",
                        input.version())
                }
            }

            break;
        default:
            FAIL2("asymmetric key", "incorrect or unknown type", type)
    }

    return true;
}

bool CheckProto_2(
    const AsymmetricKey& input,
    const bool silent,
    const CredentialType,
    const KeyMode,
    const KeyRole)
{
    UNDEFINED_VERSION("asymmetric key", 2)
}

bool CheckProto_3(
    const AsymmetricKey& input,
    const bool silent,
    const CredentialType,
    const KeyMode,
    const KeyRole)
{
    UNDEFINED_VERSION("asymmetric key", 3)
}

bool CheckProto_4(
    const AsymmetricKey& input,
    const bool silent,
    const CredentialType,
    const KeyMode,
    const KeyRole)
{
    UNDEFINED_VERSION("asymmetric key", 4)
}

bool CheckProto_5(
    const AsymmetricKey& input,
    const bool silent,
    const CredentialType,
    const KeyMode,
    const KeyRole)
{
    UNDEFINED_VERSION("asymmetric key", 5)
}
}  // namespace proto
}  // namespace opentxs
