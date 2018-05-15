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

#define PROTO_NAME "blockchain transaction"

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

    if (MAX_TRANSACTION_MEMO_SIZE < input.memo().size()) {
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

bool CheckProto_6(const BlockchainTransaction& input, const bool silent)
{
    UNDEFINED_VERSION2(6)
}

bool CheckProto_7(const BlockchainTransaction& input, const bool silent)
{
    UNDEFINED_VERSION2(7)
}

bool CheckProto_8(const BlockchainTransaction& input, const bool silent)
{
    UNDEFINED_VERSION2(8)
}

bool CheckProto_9(const BlockchainTransaction& input, const bool silent)
{
    UNDEFINED_VERSION2(9)
}

bool CheckProto_10(const BlockchainTransaction& input, const bool silent)
{
    UNDEFINED_VERSION2(10)
}

bool CheckProto_11(const BlockchainTransaction& input, const bool silent)
{
    UNDEFINED_VERSION2(11)
}

bool CheckProto_12(const BlockchainTransaction& input, const bool silent)
{
    UNDEFINED_VERSION2(12)
}

bool CheckProto_13(const BlockchainTransaction& input, const bool silent)
{
    UNDEFINED_VERSION2(13)
}

bool CheckProto_14(const BlockchainTransaction& input, const bool silent)
{
    UNDEFINED_VERSION2(14)
}

bool CheckProto_15(const BlockchainTransaction& input, const bool silent)
{
    UNDEFINED_VERSION2(15)
}

bool CheckProto_16(const BlockchainTransaction& input, const bool silent)
{
    UNDEFINED_VERSION2(16)
}

bool CheckProto_17(const BlockchainTransaction& input, const bool silent)
{
    UNDEFINED_VERSION2(17)
}

bool CheckProto_18(const BlockchainTransaction& input, const bool silent)
{
    UNDEFINED_VERSION2(18)
}

bool CheckProto_19(const BlockchainTransaction& input, const bool silent)
{
    UNDEFINED_VERSION2(19)
}

bool CheckProto_20(const BlockchainTransaction& input, const bool silent)
{
    UNDEFINED_VERSION2(20)
}
}  // namespace proto
}  // namespace opentxs
