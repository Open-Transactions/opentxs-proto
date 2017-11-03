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

bool CheckProto_1(const BlockchainTransactionOutput& input, const bool silent)
{
    if (false == input.has_index()) {
        FAIL("blockchain transaction output", "missing index")
    }

    if (input.has_serializedscript()) {
        if (MIN_PLAUSIBLE_SCRIPT > input.serializedscript().size()) {
            FAIL("blockchain transaction output", "invalid serializedscript")
        }

        if (MAX_PLAUSIBLE_SCRIPT < input.serializedscript().size()) {
            FAIL("blockchain transaction output", "invalid serializedscript")
        }
    }

    if (input.has_address()) {
        if (MIN_PLAUSIBLE_IDENTIFIER > input.address().size()) {
            FAIL("blockchain transaction output", "invalid address")
        }

        if (MAX_PLAUSIBLE_IDENTIFIER < input.address().size()) {
            FAIL("blockchain transaction output", "invalid address")
        }
    }

    if (input.has_confirmedspend()) {
        if (MIN_PLAUSIBLE_IDENTIFIER > input.confirmedspend().size()) {
            FAIL("blockchain transaction output", "invalid confirmedspend")
        }

        if (MAX_PLAUSIBLE_IDENTIFIER < input.confirmedspend().size()) {
            FAIL("blockchain transaction output", "invalid confirmedspend")
        }
    }

    for (const auto& orphan : input.orphanedspend()) {
        if (MIN_PLAUSIBLE_IDENTIFIER > orphan.size()) {
            FAIL("blockchain transaction output", "invalid orphanedspend")
        }

        if (MAX_PLAUSIBLE_IDENTIFIER < orphan.size()) {
            FAIL("blockchain transaction output", "invalid orphanedspend")
        }
    }

    return true;
}

bool CheckProto_2(const BlockchainTransactionOutput& input, const bool silent)
{
    UNDEFINED_VERSION("blockchain transaction output", 2)
}

bool CheckProto_3(const BlockchainTransactionOutput& input, const bool silent)
{
    UNDEFINED_VERSION("blockchain transaction output", 3)
}

bool CheckProto_4(const BlockchainTransactionOutput& input, const bool silent)
{
    UNDEFINED_VERSION("blockchain transaction output", 4)
}

bool CheckProto_5(const BlockchainTransactionOutput& input, const bool silent)
{
    UNDEFINED_VERSION("blockchain transaction output", 5)
}
}  // namespace proto
}  // namespace opentxs
