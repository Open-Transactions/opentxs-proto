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

#include <iostream>

namespace opentxs { namespace proto
{

bool CheckProto_1(
    const PaymentCode& serializedPaymentCode)
{
    if (!serializedPaymentCode.has_key()) {
        std::cerr << "Verify serialized payment code failed: missing pubkey." << std::endl;
        return false;
    }
    if (MIN_PLAUSIBLE_KEYSIZE > serializedPaymentCode.key().size()) {
        std::cerr << "Verify serialized payment code failed: invalid pubkey." << std::endl;
        return false;
    }
    if (!serializedPaymentCode.has_chaincode()) {
        std::cerr << "Verify serialized payment code failed: missing chaincode." << std::endl;
        return false;
    }
    if (MIN_PLAUSIBLE_KEYSIZE > serializedPaymentCode.chaincode().size()) {
        std::cerr << "Verify serialized payment code failed: invalid chaincode." << std::endl;
        return false;
    }

    if (serializedPaymentCode.has_bitmessage()) {
        if (!serializedPaymentCode.has_bitmessageversion()) {
            std::cerr << "Verify serialized payment code failed: missing Bitmessage address version." << std::endl;
            return false;
        }
        if (0xff < serializedPaymentCode.bitmessageversion()) {
            std::cerr << "Verify serialized payment code failed: invalid Bitmessage address version." << std::endl;
            return false;
        }
        if (!serializedPaymentCode.has_bitmessagestream()) {
            std::cerr << "Verify serialized payment code failed: missing Bitmessage address stream." << std::endl;
            return false;
        }
        if (0xff < serializedPaymentCode.bitmessagestream()) {
            std::cerr << "Verify serialized payment code failed: invalid Bitmessage address stream." << std::endl;
            return false;
        }
    }

    return true;
}
bool CheckProto_2(const PaymentCode&) { return false; }
} // namespace proto
} // namespace opentxs
