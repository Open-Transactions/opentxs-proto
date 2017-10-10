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

bool CheckProto_1(const NymIDSource& source, const bool silent)
{
    if (!source.has_type()) {
        FAIL("nym id source", "missing type")
    }

    bool validSourcePubkey{false};
    bool validPaymentCode{false};

    switch (source.type()) {
        case SOURCETYPE_PUBKEY:
            if (!source.has_key()) {
                FAIL("nym id source", "missing key")
            }

            if (source.has_paymentcode()) {
                FAIL("nym id source", "pubkey source includes payment code")
            }

            try {
                validSourcePubkey = Check(
                    source.key(),
                    NymIDSourceAllowedAsymmetricKey.at(source.version()).first,
                    NymIDSourceAllowedAsymmetricKey.at(source.version()).second,
                    silent,
                    CREDTYPE_LEGACY,
                    KEYMODE_PUBLIC,
                    KEYROLE_SIGN);

                if (!validSourcePubkey) {
                    FAIL("nym id source", "invalid public key")
                }
            } catch (const std::out_of_range&) {
                FAIL2(
                    "nym id source",
                    "allowed asymmetric key version not defined for version",
                    source.version())
            }

            break;
        case SOURCETYPE_BIP47:
            if (!source.has_paymentcode()) {
                FAIL("nym id source", "missing payment code")
            }

            if (source.has_key()) {
                FAIL("nym id source", "bip47 source includes public key")
            }

            try {
                validPaymentCode = Check(
                    source.paymentcode(),
                    NymIDSourceAllowedPaymentCode.at(source.version()).first,
                    NymIDSourceAllowedPaymentCode.at(source.version()).second,
                    silent);

                if (!validPaymentCode) {
                    FAIL("nym id source", "invalid payment code")
                }
            } catch (const std::out_of_range&) {
                FAIL2(
                    "nym id source",
                    "allowed payment code version not defined for version",
                    source.version())
            }

            break;
        default:
            FAIL2("nym id source", "incorrect or unknown type", source.type())
    }

    return true;
}
bool CheckProto_2(const NymIDSource&, const bool) { return false; }
bool CheckProto_3(const NymIDSource&, const bool) { return false; }
bool CheckProto_4(const NymIDSource&, const bool) { return false; }
bool CheckProto_5(const NymIDSource&, const bool) { return false; }
}  // namespace proto
}  // namespace opentxs
