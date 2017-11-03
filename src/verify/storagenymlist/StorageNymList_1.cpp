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

bool CheckProto_1(const StorageNymList& input, const bool silent)
{
    for (auto& nym : input.nym()) {
        try {
            const bool validList = Check(
                nym,
                StorageNymListAllowedHash.at(input.version()).first,
                StorageNymListAllowedHash.at(input.version()).second,
                silent);

            if (false == validList) {
                FAIL("nym index", "invalid nym")
            }
        } catch (const std::out_of_range&) {
            FAIL2(
                "nym index",
                "allowed storage item hash version not defined for version",
                input.version())
        }
    }

    return true;
}

bool CheckProto_2(const StorageNymList& input, const bool silent)
{
    return CheckProto_1(input, silent);
}

bool CheckProto_3(const StorageNymList& input, const bool silent)
{
    UNDEFINED_VERSION("nym index", 3)
}

bool CheckProto_4(const StorageNymList& input, const bool silent)
{
    UNDEFINED_VERSION("nym index", 4)
}

bool CheckProto_5(const StorageNymList& input, const bool silent)
{
    UNDEFINED_VERSION("nym index", 5)
}
}  // namespace proto
}  // namespace opentxs
