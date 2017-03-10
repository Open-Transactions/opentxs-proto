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

#include <iostream>

namespace opentxs { namespace proto
{

bool CheckProto_1(const StorageThreadItem& item)
{
    if (!item.has_id()) {
        std::cerr << "Verify serialized storage thread item failed: missing "
                  << "identifier." << std::endl;

        return false;
    }

    if (MIN_PLAUSIBLE_IDENTIFIER > item.id().size()) {
        std::cerr << "Verify serialized storage thread item failed: invalid "
                  << "identifier." << std::endl;

        return false;
    }

    if (0 == item.box()) {
        std::cerr << "Verify serialized storage thread item failed: invalid "
                  << "box." << std::endl;

        return false;
    }

    const bool hasAccount = (0 < item.account().size());
    const bool invalidAccount =
        (MIN_PLAUSIBLE_IDENTIFIER > item.account().size());

    if (hasAccount && invalidAccount) {
        std::cerr << "Verify serialized storage thread item failed: invalid "
                  << "account." << std::endl;

        return false;
    }


    return true;
}

bool CheckProto_2(const StorageThreadItem&) { return false; }
bool CheckProto_3(const StorageThreadItem&) { return false; }
bool CheckProto_4(const StorageThreadItem&) { return false; }
bool CheckProto_5(const StorageThreadItem&) { return false; }
} // namespace proto
} // namespace opentxs
