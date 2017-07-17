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

bool CheckProto_1(const StorageIDList& list, const bool silent)
{
    if (false == list.has_id()) {
        FAIL("storage id list", "missing id")
    }

    if (MIN_PLAUSIBLE_IDENTIFIER > list.id().size()) {
        FAIL2("storage id list", "invalid id", list.id())
    }

    if (MAX_PLAUSIBLE_IDENTIFIER < list.id().size()) {
        FAIL2("storage id list", "invalid id", list.id())
    }

    for (const auto& it : list.list()) {
        if (MIN_PLAUSIBLE_IDENTIFIER > it.size()) {
            FAIL2("storage id list", "invalid list item", it)
        }

        if (MAX_PLAUSIBLE_IDENTIFIER < it.size()) {
            FAIL2("storage id list", "invalid list item", it)
        }
    }

    return true;
}
bool CheckProto_2(const StorageIDList&, const bool) { return false; }
bool CheckProto_3(const StorageIDList&, const bool) { return false; }
bool CheckProto_4(const StorageIDList&, const bool) { return false; }
bool CheckProto_5(const StorageIDList&, const bool) { return false; }
}  // namespace proto
}  // namespace opentxs
