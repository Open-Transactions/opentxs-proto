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

#include "opentxs-proto/verify/StorageItemHash.hpp"

#include <iostream>

namespace opentxs { namespace proto
{

bool CheckProto_1(
    const StorageItemHash& hash)
{
    if (!hash.has_itemid()) {
        std::cerr << "Verify serialized storage item hash failed: missing identifier." << std::endl;
        return false;
    }
    if (MIN_PLAUSIBLE_IDENTIFIER > hash.itemid().size()) {
        std::cerr << "Verify serialized storage item hash failed: invalid identifier." << std::endl;
        return false;
    }
    if (!hash.has_hash()) {
        std::cerr << "Verify serialized storage item hash failed: missing hash." << std::endl;
        return false;
    }
    if (MIN_PLAUSIBLE_IDENTIFIER > hash.hash().size()) {
        std::cerr << "Verify serialized storage item hash failed: invalid hash." << std::endl;
        return false;
    }

    return true;
}

} // namespace proto
} // namespace opentxs
