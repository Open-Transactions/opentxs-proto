/************************************************************
 *
 *                 OPEN TRANSACTIONS
 *
 *       Financial Cryptography and Digital Cash
 *       Library, Protocol, API, Server, CLI, GUI
 *
 *       -- Anotransactionous Numbered Accounts.
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

bool CheckProto_1(
    const StorageBlockchainTransactions& transactions,
    const bool silent)
{
    for (auto& transaction : transactions.transaction()) {
        try {
            const bool validHash = Check(
                transaction,
                StorageBlockchainTransactionsAllowedHash
                    .at(transactions.version())
                    .first,
                StorageBlockchainTransactionsAllowedHash
                    .at(transactions.version())
                    .second,
                silent);

            if (false == validHash) {
                FAIL("storage blockchain transactions", "invalid hash")
            }
        } catch (const std::out_of_range&) {
            FAIL2(
                "storage blockchain transactions",
                "allowed storage hash version not defined for version",
                transactions.version())
        }
    }

    return true;
}

bool CheckProto_2(const StorageBlockchainTransactions&, const bool silent)
{
    UNDEFINED_VERSION("storage blockchain transactions", 2)
}

bool CheckProto_3(const StorageBlockchainTransactions&, const bool silent)
{
    UNDEFINED_VERSION("storage blockchain transactions", 3)
}

bool CheckProto_4(const StorageBlockchainTransactions&, const bool silent)
{
    UNDEFINED_VERSION("storage blockchain transactions", 4)
}

bool CheckProto_5(const StorageBlockchainTransactions&, const bool silent)
{
    UNDEFINED_VERSION("storage blockchain transactions", 5)
}
}  // namespace proto
}  // namespace opentxs
