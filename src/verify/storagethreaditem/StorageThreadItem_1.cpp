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

bool CheckProto_1(const StorageThreadItem& item, const bool silent)
{
    if (!item.has_id()) {
        FAIL("storage thread item", "missing id")
    }

    if (MIN_PLAUSIBLE_IDENTIFIER > item.id().size()) {
        FAIL("storage thread item", "invalid id")
    }

    if (0 == item.box()) {
        FAIL("storage thread item", "invalid box")
    }

    const bool hasAccount = (0 < item.account().size());
    const bool invalidAccount =
        (MIN_PLAUSIBLE_IDENTIFIER > item.account().size());

    if (hasAccount && invalidAccount) {
        FAIL("storage thread item", "invalid account")
    }

    return true;
}

bool CheckProto_2(const StorageThreadItem&, const bool) { return false; }
bool CheckProto_3(const StorageThreadItem&, const bool) { return false; }
bool CheckProto_4(const StorageThreadItem&, const bool) { return false; }
bool CheckProto_5(const StorageThreadItem&, const bool) { return false; }
}  // namespace proto
}  // namespace opentxs
