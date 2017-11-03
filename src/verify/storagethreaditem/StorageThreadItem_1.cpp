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

bool CheckProto_1(const StorageThreadItem& input, const bool silent)
{
    if (!input.has_id()) {
        FAIL("storage thread item", "missing id")
    }

    if (MIN_PLAUSIBLE_IDENTIFIER > input.id().size()) {
        FAIL("storage thread item", "invalid id")
    }

    if (0 == input.box()) {
        FAIL("storage thread item", "invalid box")
    }

    const bool hasAccount = (0 < input.account().size());
    const bool invalidAccount =
        (MIN_PLAUSIBLE_IDENTIFIER > input.account().size());

    if (hasAccount && invalidAccount) {
        FAIL("storage thread item", "invalid account")
    }

    return true;
}

bool CheckProto_2(const StorageThreadItem& input, const bool silent)
{
    UNDEFINED_VERSION("storage thread item", 2)
}

bool CheckProto_3(const StorageThreadItem& input, const bool silent)
{
    UNDEFINED_VERSION("storage thread item", 3)
}

bool CheckProto_4(const StorageThreadItem& input, const bool silent)
{
    UNDEFINED_VERSION("storage thread item", 4)
}

bool CheckProto_5(const StorageThreadItem& input, const bool silent)
{
    UNDEFINED_VERSION("storage thread item", 5)
}
}  // namespace proto
}  // namespace opentxs
