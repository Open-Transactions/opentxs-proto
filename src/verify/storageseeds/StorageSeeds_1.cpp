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

bool CheckProto_1(const StorageSeeds& seed, const bool silent)
{
    if (!seed.has_defaultseed()) {
        FAIL("seed storage index", "missing default seed")
    }

    if (MIN_PLAUSIBLE_IDENTIFIER > seed.defaultseed().size()) {
        FAIL("seed storage index", "invalid default seed")
    }

    for (auto& hash : seed.seed()) {
        bool valid = Check(
            hash,
            StorageSeedsAllowedHash.at(seed.version()).first,
            StorageSeedsAllowedHash.at(seed.version()).second,
            silent);

        if (!valid) {
            FAIL("seed storage index", "invalid has")
        }
    }

    return true;
}
bool CheckProto_2(const StorageSeeds& seed, const bool silent)
{
    return CheckProto_1(seed, silent);
}
bool CheckProto_3(const StorageSeeds&, const bool) { return false; }
bool CheckProto_4(const StorageSeeds&, const bool) { return false; }
bool CheckProto_5(const StorageSeeds&, const bool) { return false; }
}  // namespace proto
}  // namespace opentxs
