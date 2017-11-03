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

bool CheckProto_1(const StorageThread& input, const bool silent)
{
    if (!input.has_id()) {
        FAIL("storage thread", "missing id")
    }

    if (MIN_PLAUSIBLE_IDENTIFIER > input.id().size()) {
        FAIL("storage thread", "invalid id")
    }

    for (auto& nym : input.participant()) {
        if (MIN_PLAUSIBLE_IDENTIFIER > nym.size()) {
            FAIL("storage thread", "invalid participant")
        }
    }

    if (0 == input.participant_size()) {
        FAIL("storage thread", "no patricipants")
    }

    for (auto& item : input.item()) {
        try {
            const bool valid = Check(
                item,
                StorageThreadAllowedItem.at(input.version()).first,
                StorageThreadAllowedItem.at(input.version()).second,
                silent);

            if (false == valid) {
                FAIL("storage thread", "invalid item")
            }
        } catch (const std::out_of_range&) {
            FAIL2(
                "storage thread",
                "allowed storage item hash version not defined for version",
                input.version())
        }
    }

    return true;
}

bool CheckProto_2(const StorageThread& input, const bool silent)
{
    UNDEFINED_VERSION("storage thread", 2)
}

bool CheckProto_3(const StorageThread& input, const bool silent)
{
    UNDEFINED_VERSION("storage thread", 3)
}

bool CheckProto_4(const StorageThread& input, const bool silent)
{
    UNDEFINED_VERSION("storage thread", 4)
}

bool CheckProto_5(const StorageThread& input, const bool silent)
{
    UNDEFINED_VERSION("storage thread", 5)
}
}  // namespace proto
}  // namespace opentxs
