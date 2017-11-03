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

bool CheckProto_1(const Envelope& input, const bool silent)
{
    for (const auto& dhKey : input.dhkey()) {
        try {
            const bool validDHKey = Check(
                dhKey,
                EnvelopeAllowedAsymmetricKey.at(input.version()).first,
                EnvelopeAllowedAsymmetricKey.at(input.version()).second,
                silent,
                CREDTYPE_LEGACY,
                KEYMODE_PUBLIC,
                KEYROLE_ENCRYPT);

            if (false == validDHKey) {
                FAIL("envelope", "invalid dhkey")
            }
        } catch (const std::out_of_range&) {
            FAIL2(
                "envelope",
                "allowed asymmetric key version not defined for version",
                input.version())
        }
    }

    for (const auto& sessionKey : input.sessionkey()) {
        try {
            const bool validSessionKey = Check(
                sessionKey,
                EnvelopeAllowedCiphertext.at(input.version()).first,
                EnvelopeAllowedCiphertext.at(input.version()).second,
                silent);

            if (false == validSessionKey) {
                FAIL("envelope", "invalid session key")
            }
        } catch (const std::out_of_range&) {
            FAIL2(
                "envelope",
                "allowed ciphertext version not defined for version",
                input.version())
        }
    }

    try {
        const bool validCiphertext = Check(
            input.ciphertext(),
            EnvelopeAllowedCiphertext.at(input.version()).first,
            EnvelopeAllowedCiphertext.at(input.version()).second,
            silent,
            false);

        if (false == validCiphertext) {
            FAIL("envelope", "invalid ciphertext")
        }
    } catch (const std::out_of_range&) {
        FAIL2(
            "envelope",
            "allowed ciphertext version not defined for version",
            input.version())
    }

    return true;
}

bool CheckProto_2(const Envelope& input, const bool silent)
{
    UNDEFINED_VERSION("envelope", 2)
}

bool CheckProto_3(const Envelope& input, const bool silent)
{
    UNDEFINED_VERSION("envelope", 3)
}

bool CheckProto_4(const Envelope& input, const bool silent)
{
    UNDEFINED_VERSION("envelope", 4)
}

bool CheckProto_5(const Envelope& input, const bool silent)
{
    UNDEFINED_VERSION("envelope", 5)
}
}  // namespace proto
}  // namespace opentxs
