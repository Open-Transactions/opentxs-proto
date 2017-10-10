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
    const KeyCredential& keyCredential,
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

    if (!keyCredential.has_mode()) {
        FAIL("key credential", "missing mode")
    }

    if (keyCredential.mode() != mode) {
        FAIL2("key credential", "incorrect mode", keyCredential.mode())
    }

    if (3 != keyCredential.key_size()) {
        FAIL3(
            "key credential",
            "wrong number of keys",
            keyCredential.key_size(),
            " required: ",
            "3")
    }

    authKey = keyCredential.key(KEYROLE_AUTH - 1);
    encryptKey = keyCredential.key(KEYROLE_ENCRYPT - 1);
    signKey = keyCredential.key(KEYROLE_SIGN - 1);

    try {
        validAuthKey = Check(
            authKey,
            KeyCredentialAllowedAsymmetricKey.at(keyCredential.version()).first,
            KeyCredentialAllowedAsymmetricKey.at(keyCredential.version())
                .second,
            silent,
            credType,
            mode,
            KEYROLE_AUTH);
        validEncryptKey = Check(
            encryptKey,
            KeyCredentialAllowedAsymmetricKey.at(keyCredential.version()).first,
            KeyCredentialAllowedAsymmetricKey.at(keyCredential.version())
                .second,
            silent,
            credType,
            mode,
            KEYROLE_ENCRYPT);
        validSignKey = Check(
            signKey,
            KeyCredentialAllowedAsymmetricKey.at(keyCredential.version()).first,
            KeyCredentialAllowedAsymmetricKey.at(keyCredential.version())
                .second,
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
            keyCredential.version())
    }

    return true;
}
bool CheckProto_2(
    const KeyCredential&,
    const bool,
    const CredentialType,
    const KeyMode)
{
    return false;
}
bool CheckProto_3(
    const KeyCredential&,
    const bool,
    const CredentialType,
    const KeyMode)
{
    return false;
}
bool CheckProto_4(
    const KeyCredential&,
    const bool,
    const CredentialType,
    const KeyMode)
{
    return false;
}
bool CheckProto_5(
    const KeyCredential&,
    const bool,
    const CredentialType,
    const KeyMode)
{
    return false;
}
}  // namespace proto
}  // namespace opentxs
