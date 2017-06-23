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

bool CheckProto_1(const Envelope& data, const bool silent)
{
    for (const auto& dhKey : data.dhkey()) {
        if (!Check(
                dhKey,
                EnvelopeAllowedAsymmetricKey.at(data.version()).first,
                EnvelopeAllowedAsymmetricKey.at(data.version()).second,
                silent,
                CREDTYPE_LEGACY,
                KEYMODE_PUBLIC,
                KEYROLE_ENCRYPT)) {
            FAIL("envelope", "invalid dhkey")
        }
    }

    for (const auto& sessionKey : data.sessionkey()) {
        if (!Check(
                sessionKey,
                EnvelopeAllowedCiphertext.at(data.version()).first,
                EnvelopeAllowedCiphertext.at(data.version()).second,
                silent)) {
            FAIL("envelope", "invalid session key")
        }
    }

    if (!Check(
            data.ciphertext(),
            EnvelopeAllowedCiphertext.at(data.version()).first,
            EnvelopeAllowedCiphertext.at(data.version()).second,
            silent,
            false)) {
        FAIL("envelope", "invalid ciphertext")
    }

    return true;
}
bool CheckProto_2(const Envelope&, const bool) { return false; }
bool CheckProto_3(const Envelope&, const bool) { return false; }
bool CheckProto_4(const Envelope&, const bool) { return false; }
bool CheckProto_5(const Envelope&, const bool) { return false; }
}  // namespace proto
}  // namespace opentxs
