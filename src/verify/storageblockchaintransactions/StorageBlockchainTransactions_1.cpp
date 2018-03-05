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

#define PROTO_NAME "storage blockchain transactions"

namespace opentxs
{
namespace proto
{

bool CheckProto_1(const StorageBlockchainTransactions& input, const bool silent)
{
    for (auto& transaction : input.transaction()) {
        try {
            const bool validHash = Check(
                transaction,
                StorageBlockchainTransactionsAllowedHash.at(input.version())
                    .first,
                StorageBlockchainTransactionsAllowedHash.at(input.version())
                    .second,
                silent);

            if (false == validHash) {
                FAIL("storage blockchain transactions", "invalid hash")
            }
        } catch (const std::out_of_range&) {
            FAIL2(
                "storage blockchain transactions",
                "allowed storage hash version not defined for version",
                input.version())
        }
    }

    return true;
}

bool CheckProto_2(const StorageBlockchainTransactions& input, const bool silent)
{
    UNDEFINED_VERSION("storage blockchain transactions", 2)
}

bool CheckProto_3(const StorageBlockchainTransactions& input, const bool silent)
{
    UNDEFINED_VERSION("storage blockchain transactions", 3)
}

bool CheckProto_4(const StorageBlockchainTransactions& input, const bool silent)
{
    UNDEFINED_VERSION("storage blockchain transactions", 4)
}

bool CheckProto_5(const StorageBlockchainTransactions& input, const bool silent)
{
    UNDEFINED_VERSION("storage blockchain transactions", 5)
}

bool CheckProto_6(const StorageBlockchainTransactions& input, const bool silent)
{
    UNDEFINED_VERSION2(6)
}

bool CheckProto_7(const StorageBlockchainTransactions& input, const bool silent)
{
    UNDEFINED_VERSION2(7)
}

bool CheckProto_8(const StorageBlockchainTransactions& input, const bool silent)
{
    UNDEFINED_VERSION2(8)
}

bool CheckProto_9(const StorageBlockchainTransactions& input, const bool silent)
{
    UNDEFINED_VERSION2(9)
}

bool CheckProto_10(
    const StorageBlockchainTransactions& input,
    const bool silent)
{
    UNDEFINED_VERSION2(10)
}

bool CheckProto_11(
    const StorageBlockchainTransactions& input,
    const bool silent)
{
    UNDEFINED_VERSION2(11)
}

bool CheckProto_12(
    const StorageBlockchainTransactions& input,
    const bool silent)
{
    UNDEFINED_VERSION2(12)
}

bool CheckProto_13(
    const StorageBlockchainTransactions& input,
    const bool silent)
{
    UNDEFINED_VERSION2(13)
}

bool CheckProto_14(
    const StorageBlockchainTransactions& input,
    const bool silent)
{
    UNDEFINED_VERSION2(14)
}

bool CheckProto_15(
    const StorageBlockchainTransactions& input,
    const bool silent)
{
    UNDEFINED_VERSION2(15)
}

bool CheckProto_16(
    const StorageBlockchainTransactions& input,
    const bool silent)
{
    UNDEFINED_VERSION2(16)
}

bool CheckProto_17(
    const StorageBlockchainTransactions& input,
    const bool silent)
{
    UNDEFINED_VERSION2(17)
}

bool CheckProto_18(
    const StorageBlockchainTransactions& input,
    const bool silent)
{
    UNDEFINED_VERSION2(18)
}

bool CheckProto_19(
    const StorageBlockchainTransactions& input,
    const bool silent)
{
    UNDEFINED_VERSION2(19)
}

bool CheckProto_20(
    const StorageBlockchainTransactions& input,
    const bool silent)
{
    UNDEFINED_VERSION2(20)
}
}  // namespace proto
}  // namespace opentxs
