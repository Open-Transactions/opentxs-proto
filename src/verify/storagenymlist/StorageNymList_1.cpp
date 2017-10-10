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

bool CheckProto_1(const StorageNymList& nymList, const bool silent)
{
    for (auto& nym : nymList.nym()) {
        try {
            const bool validList = Check(
                nym,
                StorageNymListAllowedHash.at(nymList.version()).first,
                StorageNymListAllowedHash.at(nymList.version()).second,
                silent);

            if (false == validList) {
                FAIL("nym index", "invalid nym")
            }
        } catch (const std::out_of_range&) {
            FAIL2(
                "nym index",
                "allowed storage item hash version not defined for version",
                nymList.version())
        }
    }

    return true;
}
bool CheckProto_2(const StorageNymList& nymList, const bool silent)
{
    return CheckProto_1(nymList, silent);
}
bool CheckProto_3(const StorageNymList&, const bool) { return false; }
bool CheckProto_4(const StorageNymList&, const bool) { return false; }
bool CheckProto_5(const StorageNymList&, const bool) { return false; }
}  // namespace proto
}  // namespace opentxs
