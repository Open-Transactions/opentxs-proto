// Copyright (c) 2018 The Open-Transactions developers
// This Source Code Form is subject to the terms of the Mozilla Public
// License, v. 2.0. If a copy of the MPL was not distributed with this
// file, You can obtain one at http://mozilla.org/MPL/2.0/.

#include "opentxs-proto/Types.hpp"
#include "opentxs-proto/Check.hpp"

#include <iostream>

#define PROTO_NAME "key credential"

namespace opentxs
{
namespace proto
{

bool CheckProto_1(
    const KeyCredential& input,
    const bool silent,
    const CredentialType credType,
    const KeyMode mode)
{
    AsymmetricKey authKey;
    AsymmetricKey encryptKey;
    AsymmetricKey signKey;
    bool validAuthKey = false;
    bool validEncryptKey = false;
    bool validSignKey = false;

    if (!input.has_mode()) {
        FAIL("key credential", "missing mode")
    }

    if (input.mode() != mode) {
        FAIL2("key credential", "incorrect mode", input.mode())
    }

    if (3 != input.key_size()) {
        FAIL3(
            "key credential",
            "wrong number of keys",
            input.key_size(),
            " required: ",
            "3")
    }

    authKey = input.key(KEYROLE_AUTH - 1);
    encryptKey = input.key(KEYROLE_ENCRYPT - 1);
    signKey = input.key(KEYROLE_SIGN - 1);

    try {
        validAuthKey = Check(
            authKey,
            KeyCredentialAllowedAsymmetricKey.at(input.version()).first,
            KeyCredentialAllowedAsymmetricKey.at(input.version()).second,
            silent,
            credType,
            mode,
            KEYROLE_AUTH);
        validEncryptKey = Check(
            encryptKey,
            KeyCredentialAllowedAsymmetricKey.at(input.version()).first,
            KeyCredentialAllowedAsymmetricKey.at(input.version()).second,
            silent,
            credType,
            mode,
            KEYROLE_ENCRYPT);
        validSignKey = Check(
            signKey,
            KeyCredentialAllowedAsymmetricKey.at(input.version()).first,
            KeyCredentialAllowedAsymmetricKey.at(input.version()).second,
            silent,
            credType,
            mode,
            KEYROLE_SIGN);

        if (!validAuthKey) {
            FAIL("key credential", "invalid auth key")
        }

        if (!validEncryptKey) {
            FAIL("key credential", "invalid encrypt key")
        }

        if (!validSignKey) {
            FAIL("key credential", "invalid sign key")
        }
    } catch (const std::out_of_range&) {
        FAIL2(
            "key credential",
            "allowed asymmetric key version not defined for version",
            input.version())
    }

    return true;
}

bool CheckProto_2(
    const KeyCredential& input,
    const bool silent,
    const CredentialType,
    const KeyMode)
{
    UNDEFINED_VERSION("key credential", 2)
}

bool CheckProto_3(
    const KeyCredential& input,
    const bool silent,
    const CredentialType,
    const KeyMode)
{
    UNDEFINED_VERSION("key credential", 3)
}

bool CheckProto_4(
    const KeyCredential& input,
    const bool silent,
    const CredentialType,
    const KeyMode)
{
    UNDEFINED_VERSION("key credential", 4)
}

bool CheckProto_5(
    const KeyCredential& input,
    const bool silent,
    const CredentialType,
    const KeyMode)
{
    UNDEFINED_VERSION("key credential", 5)
}

bool CheckProto_6(
    const KeyCredential& input,
    const bool silent,
    const CredentialType,
    const KeyMode)
{
    UNDEFINED_VERSION2(6)
}

bool CheckProto_7(
    const KeyCredential& input,
    const bool silent,
    const CredentialType,
    const KeyMode)
{
    UNDEFINED_VERSION2(7)
}

bool CheckProto_8(
    const KeyCredential& input,
    const bool silent,
    const CredentialType,
    const KeyMode)
{
    UNDEFINED_VERSION2(8)
}

bool CheckProto_9(
    const KeyCredential& input,
    const bool silent,
    const CredentialType,
    const KeyMode)
{
    UNDEFINED_VERSION2(9)
}

bool CheckProto_10(
    const KeyCredential& input,
    const bool silent,
    const CredentialType,
    const KeyMode)
{
    UNDEFINED_VERSION2(10)
}

bool CheckProto_11(
    const KeyCredential& input,
    const bool silent,
    const CredentialType,
    const KeyMode)
{
    UNDEFINED_VERSION2(11)
}

bool CheckProto_12(
    const KeyCredential& input,
    const bool silent,
    const CredentialType,
    const KeyMode)
{
    UNDEFINED_VERSION2(12)
}

bool CheckProto_13(
    const KeyCredential& input,
    const bool silent,
    const CredentialType,
    const KeyMode)
{
    UNDEFINED_VERSION2(13)
}

bool CheckProto_14(
    const KeyCredential& input,
    const bool silent,
    const CredentialType,
    const KeyMode)
{
    UNDEFINED_VERSION2(14)
}

bool CheckProto_15(
    const KeyCredential& input,
    const bool silent,
    const CredentialType,
    const KeyMode)
{
    UNDEFINED_VERSION2(15)
}

bool CheckProto_16(
    const KeyCredential& input,
    const bool silent,
    const CredentialType,
    const KeyMode)
{
    UNDEFINED_VERSION2(16)
}

bool CheckProto_17(
    const KeyCredential& input,
    const bool silent,
    const CredentialType,
    const KeyMode)
{
    UNDEFINED_VERSION2(17)
}

bool CheckProto_18(
    const KeyCredential& input,
    const bool silent,
    const CredentialType,
    const KeyMode)
{
    UNDEFINED_VERSION2(18)
}

bool CheckProto_19(
    const KeyCredential& input,
    const bool silent,
    const CredentialType,
    const KeyMode)
{
    UNDEFINED_VERSION2(19)
}

bool CheckProto_20(
    const KeyCredential& input,
    const bool silent,
    const CredentialType,
    const KeyMode)
{
    UNDEFINED_VERSION2(20)
}
}  // namespace proto
}  // namespace opentxs
