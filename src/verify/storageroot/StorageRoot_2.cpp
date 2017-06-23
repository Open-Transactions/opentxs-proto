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

bool CheckProto_2(const StorageRoot& root, const bool silent)
{
    if (!root.has_items()) {
        FAIL("storage root", "missing hash")
    }

    if (MIN_PLAUSIBLE_IDENTIFIER > root.items().size()) {
        FAIL("storage root", "invalid hash")
    }

    if (MAX_PLAUSIBLE_IDENTIFIER < root.items().size()) {
        FAIL("storage root", "invalid hash")
    }

    if (!root.has_sequence()) {
        FAIL("storage root", "missing sequence")
    }

    return true;
}

bool CheckProto_3(const StorageRoot&, const bool) { return false; }
bool CheckProto_4(const StorageRoot&, const bool) { return false; }
bool CheckProto_5(const StorageRoot&, const bool) { return false; }
}  // namespace proto
}  // namespace opentxs
