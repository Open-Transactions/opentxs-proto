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
bool CheckProto_1(const StorageItemHash& hash, const bool silent)
{
    if (!hash.has_itemid()) {
        FAIL("storage item hash", "missing id")
    }

    if (MIN_PLAUSIBLE_IDENTIFIER > hash.itemid().size()) {
        FAIL("storage item hash", "invalid id")
    }

    if (!hash.has_hash()) {
        FAIL("storage item hash", "missing hash")
    }

    if (MIN_PLAUSIBLE_IDENTIFIER > hash.hash().size()) {
        FAIL("storage item hash", "invalid has")
    }

    if (hash.has_type() && (STORAGEHASH_ERROR != hash.type())) {
        FAIL("storage item hash", "unexpected type field present")
    }

    return true;
}
}  // namespace proto
}  // namespace opentxs
