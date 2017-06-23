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

bool CheckProto_1(const StorageItems& items, const bool silent)
{
    if (items.has_creds()) {
        if (MIN_PLAUSIBLE_IDENTIFIER > items.creds().size()) {
            FAIL("storage item index", "invalid credentials")
        }
    }

    if (items.has_nyms()) {
        if (MIN_PLAUSIBLE_IDENTIFIER > items.nyms().size()) {
            FAIL("storage item index", "invalid nym list")
        }
    }

    if (items.has_servers()) {
        if (MIN_PLAUSIBLE_IDENTIFIER > items.servers().size()) {
            FAIL("storage item index", "invalid server list")
        }
    }

    if (items.has_units()) {
        if (MIN_PLAUSIBLE_IDENTIFIER > items.units().size()) {
            FAIL("storage item index", "invalid unit list")
        }
    }

    if (items.has_seeds()) {
        if (MIN_PLAUSIBLE_IDENTIFIER > items.seeds().size()) {
            FAIL("storage item index", "invalid seed list")
        }
    }

    return true;
}
bool CheckProto_2(const StorageItems&, const bool) { return false; }
bool CheckProto_3(const StorageItems&, const bool) { return false; }
bool CheckProto_4(const StorageItems&, const bool) { return false; }
bool CheckProto_5(const StorageItems&, const bool) { return false; }
}  // namespace proto
}  // namespace opentxs
