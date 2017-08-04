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

bool CheckProto_1(const BlockchainTransactionInput& input, const bool silent)
{
    if (false == input.has_index()) {
        FAIL("input", "missing index")
    }

    if (false == input.has_serializedscript()) {
        FAIL("input", "missing serializedscript")
    }

    if (MIN_PLAUSIBLE_SCRIPT > input.serializedscript().size()) {
        FAIL("input", "invalid serializedscript")
    }

    if (MAX_PLAUSIBLE_SCRIPT < input.serializedscript().size()) {
        FAIL("input", "invalid serializedscript")
    }

    for (const auto& address : input.address()) {
        if (MIN_PLAUSIBLE_IDENTIFIER > address.size()) {
            FAIL("input", "invalid serializedscript")
        }

        if (MAX_PLAUSIBLE_IDENTIFIER < address.size()) {
            FAIL("input", "invalid serializedscript")
        }
    }

    return true;
}

bool CheckProto_2(const BlockchainTransactionInput&, const bool)
{
    return false;
}
bool CheckProto_3(const BlockchainTransactionInput&, const bool)
{
    return false;
}
bool CheckProto_4(const BlockchainTransactionInput&, const bool)
{
    return false;
}
bool CheckProto_5(const BlockchainTransactionInput&, const bool)
{
    return false;
}
}  // namespace proto
}  // namespace opentxs
