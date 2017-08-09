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
#include "opentxs-proto/Contact.hpp"

#include <iostream>

namespace opentxs
{
namespace proto
{

bool CheckProto_1(const BlockchainTransaction& transaction, const bool silent)
{
    const bool validChain = ValidContactItemType(
        {CONTACT_VERSION, CONTACTSECTION_CONTRACT}, transaction.chain());

    if (false == validChain) {
        FAIL("transaction", "invalid chain")
    }

    if (MIN_PLAUSIBLE_IDENTIFIER > transaction.txid().size()) {
        FAIL("transaction", "invalid txid")
    }

    if (MAX_PLAUSIBLE_IDENTIFIER < transaction.txid().size()) {
        FAIL("transaction", "invalid txid")
    }

    if (transaction.has_serialized()) {
        if (MIN_PLAUSIBLE_SCRIPT > transaction.serialized().size()) {
            FAIL("transaction", "invalid serialized")
        }

        if (MAX_PLAUSIBLE_SCRIPT < transaction.serialized().size()) {
            FAIL("transaction", "invalid serialized")
        }
    }

    for (const auto& input : transaction.input()) {
        const bool validInput = Check(
            input,
            BlockchainTransactionAllowedInput.at(transaction.version()).first,
            BlockchainTransactionAllowedInput.at(transaction.version()).second,
            silent);

        if (false == validInput) {
            FAIL("transaction", "invalid input")
        }
    }

    for (const auto& output : transaction.output()) {
        const bool validOutput = Check(
            output,
            BlockchainTransactionAllowedOutput.at(transaction.version()).first,
            BlockchainTransactionAllowedOutput.at(transaction.version()).second,
            silent);

        if (false == validOutput) {
            FAIL("transaction", "invalid output")
        }
    }

    if (transaction.has_blockhash()) {
        if (MIN_PLAUSIBLE_IDENTIFIER > transaction.blockhash().size()) {
            FAIL("transaction", "invalid blockhash")
        }

        if (MIN_PLAUSIBLE_IDENTIFIER < transaction.blockhash().size()) {
            FAIL("transaction", "invalid blockhash")
        }
    }

    for (const auto& conflict : transaction.conflicts()) {
        if (MIN_PLAUSIBLE_IDENTIFIER > conflict.size()) {
            FAIL("transaction", "invalid conflict")
        }

        if (MIN_PLAUSIBLE_IDENTIFIER < conflict.size()) {
            FAIL("transaction", "invalid conflict")
        }
    }

    if (MAX_VALID_CONTACT_VALUE > transaction.memo().size()) {
        FAIL("transaction", "invalid memo")
    }

    return true;
}

bool CheckProto_2(const BlockchainTransaction&, const bool) { return false; }
bool CheckProto_3(const BlockchainTransaction&, const bool) { return false; }
bool CheckProto_4(const BlockchainTransaction&, const bool) { return false; }
bool CheckProto_5(const BlockchainTransaction&, const bool) { return false; }
}  // namespace proto
}  // namespace opentxs
