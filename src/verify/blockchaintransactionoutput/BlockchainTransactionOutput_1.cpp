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

bool CheckProto_1(const BlockchainTransactionOutput& output, const bool silent)
{
    if (false == output.has_index()) {
        FAIL("output", "missing index")
    }

    if (output.has_serializedscript()) {
        if (MIN_PLAUSIBLE_SCRIPT > output.serializedscript().size()) {
            FAIL("output", "invalid serializedscript")
        }

        if (MAX_PLAUSIBLE_SCRIPT < output.serializedscript().size()) {
            FAIL("output", "invalid serializedscript")
        }
    }

    if (output.has_address()) {
        if (MIN_PLAUSIBLE_IDENTIFIER > output.address().size()) {
            FAIL("output", "invalid address")
        }

        if (MAX_PLAUSIBLE_IDENTIFIER < output.address().size()) {
            FAIL("output", "invalid address")
        }
    }

    if (output.has_confirmedspend()) {
        if (MIN_PLAUSIBLE_IDENTIFIER > output.confirmedspend().size()) {
            FAIL("output", "invalid confirmedspend")
        }

        if (MAX_PLAUSIBLE_IDENTIFIER < output.confirmedspend().size()) {
            FAIL("output", "invalid confirmedspend")
        }
    }

    for (const auto& orphan : output.orphanedspend()) {
        if (MIN_PLAUSIBLE_IDENTIFIER > orphan.size()) {
            FAIL("output", "invalid orphanedspend")
        }

        if (MAX_PLAUSIBLE_IDENTIFIER < orphan.size()) {
            FAIL("output", "invalid orphanedspend")
        }
    }

    return true;
}

bool CheckProto_2(const BlockchainTransactionOutput&, const bool)
{
    return false;
}
bool CheckProto_3(const BlockchainTransactionOutput&, const bool)
{
    return false;
}
bool CheckProto_4(const BlockchainTransactionOutput&, const bool)
{
    return false;
}
bool CheckProto_5(const BlockchainTransactionOutput&, const bool)
{
    return false;
}
}  // namespace proto
}  // namespace opentxs
