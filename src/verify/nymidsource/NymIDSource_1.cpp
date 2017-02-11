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

namespace opentxs { namespace proto
{

bool CheckProto_1(
    const NymIDSource& serializedNymIDSource)
{
    if (!serializedNymIDSource.has_type()) {
        std::cerr << "Verify serialized nym source failed: missing type." << std::endl;
        return false;
    }

    bool validSourcePubkey = false;
    bool validPaymentCode = false;
    AsymmetricKey sourcePubkey;

    switch (serializedNymIDSource.type()) {
        case SOURCETYPE_PUBKEY :
            if (!serializedNymIDSource.has_key()) {
                std::cerr << "Verify serialized nym source failed: missing source." << std::endl;
                return false;
            }
            if (serializedNymIDSource.has_paymentcode()) {
                std::cerr << "Verify serialized nym source failed: pubkey source includes payment code." << std::endl;
                return false;
            }

            sourcePubkey = serializedNymIDSource.key();

            validSourcePubkey = Check(
                sourcePubkey,
                NymIDSourceAllowedAsymmetricKey.at(serializedNymIDSource.version()).first,
                NymIDSourceAllowedAsymmetricKey.at(serializedNymIDSource.version()).second,
                CREDTYPE_LEGACY,
                KEYMODE_PUBLIC,
                KEYROLE_SIGN);

            if (!validSourcePubkey) {
                std::cerr << "Verify nym source failed: invalid public key." << std::endl;
                return false;
            }

            break;
        case SOURCETYPE_BIP47 :
            if (!serializedNymIDSource.has_paymentcode()) {
                std::cerr << "Verify serialized nym source failed: missing payment code." << std::endl;
                return false;
            }
            if (serializedNymIDSource.has_key()) {
                std::cerr << "Verify serialized nym source failed: bip47 source includes public key." << std::endl;
                return false;
            }
            validPaymentCode = Check(
                serializedNymIDSource.paymentcode(),
                NymIDSourceAllowedPaymentCode.at(serializedNymIDSource.version()).first,
                NymIDSourceAllowedPaymentCode.at(serializedNymIDSource.version()).second);

            if (!validPaymentCode) {
                std::cerr << "Verify nym source failed: invalid payment code." << std::endl;
                return false;
            }

            break;
        default :
            std::cerr << "Verify nym source failed: incorrect or unknown type ("
                    << serializedNymIDSource.type() << ")." << std::endl;

            return false;
    }

    return true;
}
bool CheckProto_2(const NymIDSource&) { return false; }
} // namespace proto
} // namespace opentxs
