// Copyright (c) 2018 The Open-Transactions developers
// This Source Code Form is subject to the terms of the Mozilla Public
// License, v. 2.0. If a copy of the MPL was not distributed with this
// file, You can obtain one at http://mozilla.org/MPL/2.0/.

#include "opentxs-proto/Types.hpp"
#include "opentxs-proto/Check.hpp"

#define PROTO_NAME "asymmetric key"

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
    if (!input.has_type()) { FAIL_1("missing key type") }

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
            FAIL_2("incorrect key type", input.type())
        }
    }

    if (!input.has_mode()) { FAIL_1("missing key mode") }

    if (input.mode() != mode) { FAIL_2("incorrect key mode", input.mode()) }

    if (!input.has_role()) { FAIL_1("missing key role") }

    if (input.role() != role) { FAIL_2("incorrect key role", input.role()) }

    if (KEYMODE_PUBLIC == mode) {
        if (!input.has_key()) { FAIL_1("missing key") }

        if (MIN_PLAUSIBLE_KEYSIZE > input.key().size()) {
            FAIL_2("invalid key", input.key())
        }
        if (input.has_encryptedkey()) {
            FAIL_1("encrypted data present in public key")
        }
    } else {
        if (AKEYTYPE_LEGACY == input.type()) {
            if (!input.has_key()) { FAIL_1("missing key") }

            if (MIN_PLAUSIBLE_KEYSIZE > input.key().size()) {
                FAIL_2("invalid key", input.key())
            }

            if (input.has_encryptedkey()) {
                FAIL_1("encrypted data present in legacy key")
            }
        } else {
            if (!input.has_encryptedkey()) { FAIL_1("missing encrypted key") }

            try {
                const bool validEncryptedKey = Check(
                    input.encryptedkey(),
                    AsymmetricKeyAllowedCiphertext.at(input.version()).first,
                    AsymmetricKeyAllowedCiphertext.at(input.version()).second,
                    silent,
                    false);

                if (!validEncryptedKey) { FAIL_1("invalid encrypted key") }
            } catch (const std::out_of_range&) {
                FAIL_2(
                    "allowed ciphertext version not defined for version",
                    input.version())
            }

            if (input.has_key()) {
                FAIL_1("plaintext data found in private key")
            }
        }
    }

    switch (type) {
        case CREDTYPE_LEGACY:
            if (input.has_chaincode()) {
                FAIL_1("chain code not allowed in legacy credentials")
            }

            if (input.has_path()) {
                FAIL_1("HD path not allowed in legacy credentials")
            }

            break;
        case CREDTYPE_HD:
            if (KEYMODE_PUBLIC == mode) {
                if (input.has_chaincode()) {
                    FAIL_1("chain code not allowed in public credentials")
                }

                if (input.has_path()) {
                    FAIL_1("HD path not allowed in public credentials")
                }
            } else {
                if (!input.has_chaincode()) { FAIL_1("missing chain code") }

                try {
                    const bool validChainCode = Check(
                        input.chaincode(),
                        AsymmetricKeyAllowedCiphertext.at(input.version())
                            .first,
                        AsymmetricKeyAllowedCiphertext.at(input.version())
                            .second,
                        silent,
                        false);

                    if (!validChainCode) { FAIL_1("invalid chain code") }
                } catch (const std::out_of_range&) {
                    FAIL_2(
                        "allowed ciphertext version not defined for version",
                        input.version())
                }

                if (!input.has_path()) { FAIL_1("missing HD path") }

                try {
                    bool validPath = Check(
                        input.path(),
                        AsymmetricKeyAllowedHDPath.at(input.version()).first,
                        AsymmetricKeyAllowedHDPath.at(input.version()).second,
                        silent);

                    if (!validPath) { FAIL_1("invalid HD path") }
                } catch (const std::out_of_range&) {
                    FAIL_2(
                        "allowed HD path version not defined for version",
                        input.version())
                }
            }

            break;
        default:
            FAIL_2("incorrect or unknown type", type)
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
    UNDEFINED_VERSION(2)
}

bool CheckProto_3(
    const AsymmetricKey& input,
    const bool silent,
    const CredentialType,
    const KeyMode,
    const KeyRole)
{
    UNDEFINED_VERSION(3)
}

bool CheckProto_4(
    const AsymmetricKey& input,
    const bool silent,
    const CredentialType,
    const KeyMode,
    const KeyRole)
{
    UNDEFINED_VERSION(4)
}

bool CheckProto_5(
    const AsymmetricKey& input,
    const bool silent,
    const CredentialType,
    const KeyMode,
    const KeyRole)
{
    UNDEFINED_VERSION(5)
}

bool CheckProto_6(
    const AsymmetricKey& input,
    const bool silent,
    const CredentialType,
    const KeyMode,
    const KeyRole)
{
    UNDEFINED_VERSION(6)
}

bool CheckProto_7(
    const AsymmetricKey& input,
    const bool silent,
    const CredentialType,
    const KeyMode,
    const KeyRole)
{
    UNDEFINED_VERSION(7)
}

bool CheckProto_8(
    const AsymmetricKey& input,
    const bool silent,
    const CredentialType,
    const KeyMode,
    const KeyRole)
{
    UNDEFINED_VERSION(8)
}

bool CheckProto_9(
    const AsymmetricKey& input,
    const bool silent,
    const CredentialType,
    const KeyMode,
    const KeyRole)
{
    UNDEFINED_VERSION(9)
}

bool CheckProto_10(
    const AsymmetricKey& input,
    const bool silent,
    const CredentialType,
    const KeyMode,
    const KeyRole)
{
    UNDEFINED_VERSION(10)
}

bool CheckProto_11(
    const AsymmetricKey& input,
    const bool silent,
    const CredentialType,
    const KeyMode,
    const KeyRole)
{
    UNDEFINED_VERSION(11)
}

bool CheckProto_12(
    const AsymmetricKey& input,
    const bool silent,
    const CredentialType,
    const KeyMode,
    const KeyRole)
{
    UNDEFINED_VERSION(12)
}

bool CheckProto_13(
    const AsymmetricKey& input,
    const bool silent,
    const CredentialType,
    const KeyMode,
    const KeyRole)
{
    UNDEFINED_VERSION(13)
}

bool CheckProto_14(
    const AsymmetricKey& input,
    const bool silent,
    const CredentialType,
    const KeyMode,
    const KeyRole)
{
    UNDEFINED_VERSION(14)
}

bool CheckProto_15(
    const AsymmetricKey& input,
    const bool silent,
    const CredentialType,
    const KeyMode,
    const KeyRole)
{
    UNDEFINED_VERSION(15)
}

bool CheckProto_16(
    const AsymmetricKey& input,
    const bool silent,
    const CredentialType,
    const KeyMode,
    const KeyRole)
{
    UNDEFINED_VERSION(16)
}

bool CheckProto_17(
    const AsymmetricKey& input,
    const bool silent,
    const CredentialType,
    const KeyMode,
    const KeyRole)
{
    UNDEFINED_VERSION(17)
}

bool CheckProto_18(
    const AsymmetricKey& input,
    const bool silent,
    const CredentialType,
    const KeyMode,
    const KeyRole)
{
    UNDEFINED_VERSION(18)
}

bool CheckProto_19(
    const AsymmetricKey& input,
    const bool silent,
    const CredentialType,
    const KeyMode,
    const KeyRole)
{
    UNDEFINED_VERSION(19)
}

bool CheckProto_20(
    const AsymmetricKey& input,
    const bool silent,
    const CredentialType,
    const KeyMode,
    const KeyRole)
{
    UNDEFINED_VERSION(20)
}
}  // namespace proto
}  // namespace opentxs
