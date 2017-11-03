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

bool CheckProto_1(const BlockchainTransaction& input, const bool silent)
{
    const bool validChain = ValidContactItemType(
        {CONTACT_VERSION, CONTACTSECTION_CONTRACT}, input.chain());

    if (false == validChain) {
        FAIL("blockchain transaction", "invalid chain")
    }

    if (MIN_PLAUSIBLE_IDENTIFIER > input.txid().size()) {
        FAIL("blockchain transaction", "invalid txid")
    }

    if (MAX_PLAUSIBLE_IDENTIFIER < input.txid().size()) {
        FAIL("blockchain transaction", "invalid txid")
    }

    if (input.has_serialized()) {
        if (MIN_PLAUSIBLE_SCRIPT > input.serialized().size()) {
            FAIL("blockchain transaction", "invalid serialized")
        }

        if (MAX_PLAUSIBLE_SCRIPT < input.serialized().size()) {
            FAIL("blockchain transaction", "invalid serialized")
        }
    }

    for (const auto& input : input.input()) {
        try {
            const bool validInput = Check(
                input,
                BlockchainTransactionAllowedInput.at(input.version()).first,
                BlockchainTransactionAllowedInput.at(input.version()).second,
                silent);

            if (false == validInput) {
                FAIL("blockchain transaction", "invalid input")
            }
        } catch (const std::out_of_range&) {
            FAIL2(
                "blockchain transaction",
                "allowed input version not defined for version",
                input.version())
        }
    }

    for (const auto& output : input.output()) {
        try {
            const bool validOutput = Check(
                output,
                BlockchainTransactionAllowedOutput.at(input.version()).first,
                BlockchainTransactionAllowedOutput.at(input.version()).second,
                silent);

            if (false == validOutput) {
                FAIL("blockchain transaction", "invalid output")
            }
        } catch (const std::out_of_range&) {
            FAIL2(
                "blockchain transaction",
                "allowed output version not defined for version",
                input.version())
        }
    }

    if (input.has_blockhash()) {
        if (MIN_PLAUSIBLE_IDENTIFIER > input.blockhash().size()) {
            FAIL("blockchain transaction", "invalid blockhash")
        }

        if (MIN_PLAUSIBLE_IDENTIFIER < input.blockhash().size()) {
            FAIL("blockchain transaction", "invalid blockhash")
        }
    }

    for (const auto& conflict : input.conflicts()) {
        if (MIN_PLAUSIBLE_IDENTIFIER > conflict.size()) {
            FAIL("blockchain transaction", "invalid conflict")
        }

        if (MIN_PLAUSIBLE_IDENTIFIER < conflict.size()) {
            FAIL("blockchain transaction", "invalid conflict")
        }
    }

    if (MAX_VALID_CONTACT_VALUE > input.memo().size()) {
        FAIL("blockchain transaction", "invalid memo")
    }

    return true;
}

bool CheckProto_2(const BlockchainTransaction& input, const bool silent)
{
    UNDEFINED_VERSION("blockchain transaction", 2)
}

bool CheckProto_3(const BlockchainTransaction& input, const bool silent)
{
    UNDEFINED_VERSION("blockchain transaction", 3)
}

bool CheckProto_4(const BlockchainTransaction& input, const bool silent)
{
    UNDEFINED_VERSION("blockchain transaction", 4)
}

bool CheckProto_5(const BlockchainTransaction& input, const bool silent)
{
    UNDEFINED_VERSION("blockchain transaction", 5)
}
}  // namespace proto
}  // namespace opentxs
