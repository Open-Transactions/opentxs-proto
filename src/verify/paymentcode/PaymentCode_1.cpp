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

bool CheckProto_1(const PaymentCode& code, const bool silent)
{
    if (!code.has_key()) {
        FAIL("payment code", "missing pubkey")
    }

    if (MIN_PLAUSIBLE_KEYSIZE > code.key().size()) {
        FAIL("payment code", "invalid pubkey")
    }

    if (!code.has_chaincode()) {
        FAIL("payment code", "missing chaincode")
    }

    if (MIN_PLAUSIBLE_KEYSIZE > code.chaincode().size()) {
        FAIL("payment code", "invalid chaincode")
    }

    if (code.has_bitmessage()) {
        if (!code.has_bitmessageversion()) {
            FAIL("payment code", "missing Bitmessage address version")
        }

        if (0xff < code.bitmessageversion()) {
            FAIL("payment code", "invalid Bitmessage address version")
        }

        if (!code.has_bitmessagestream()) {
            FAIL("payment code", "missing Bitmessage address stream")
        }

        if (0xff < code.bitmessagestream()) {
            FAIL("payment code", "invalid Bitmessage address stream")
        }
    }

    return true;
}

bool CheckProto_2(const PaymentCode&, const bool silent)
{
    UNDEFINED_VERSION("payment code", 2)
}

bool CheckProto_3(const PaymentCode&, const bool silent)
{
    UNDEFINED_VERSION("payment code", 3)
}

bool CheckProto_4(const PaymentCode&, const bool silent)
{
    UNDEFINED_VERSION("payment code", 4)
}

bool CheckProto_5(const PaymentCode&, const bool silent)
{
    UNDEFINED_VERSION("payment code", 5)
}
}  // namespace proto
}  // namespace opentxs
