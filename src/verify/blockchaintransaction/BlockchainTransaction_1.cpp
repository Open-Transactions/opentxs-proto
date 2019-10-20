// Copyright (c) 2019 The Open-Transactions developers
// This Source Code Form is subject to the terms of the Mozilla Public
// License, v. 2.0. If a copy of the MPL was not distributed with this
// file, You can obtain one at http://mozilla.org/MPL/2.0/.

#include "opentxs-proto/Types.hpp"
#include "verify/Check.hpp"
#include "opentxs-proto/Contact.hpp"

#define PROTO_NAME "blockchain transaction"

namespace opentxs
{
namespace proto
{

bool CheckProto_1(const BlockchainTransaction& input, const bool silent)
{
    const bool validChain = ValidContactItemType(
        {CONTACT_VERSION, CONTACTSECTION_CONTRACT}, input.chain());

    if (false == validChain) { FAIL_1("invalid chain") }

    if (MIN_PLAUSIBLE_IDENTIFIER > input.txid().size()) {
        FAIL_1("invalid txid")
    }

    if (MAX_PLAUSIBLE_IDENTIFIER < input.txid().size()) {
        FAIL_1("invalid txid")
    }

    if (input.has_serialized()) {
        if (MIN_PLAUSIBLE_SCRIPT > input.serialized().size()) {
            FAIL_1("invalid serialized")
        }

        if (MAX_PLAUSIBLE_SCRIPT < input.serialized().size()) {
            FAIL_1("invalid serialized")
        }
    }

    for (const auto& txin : input.input()) {
        try {
            const bool validInput = Check(
                txin,
                BlockchainTransactionAllowedInput.at(txin.version()).first,
                BlockchainTransactionAllowedInput.at(txin.version()).second,
                silent);

            if (false == validInput) { FAIL_1("invalid input") }
        } catch (const std::out_of_range&) {
            FAIL_2(
                "allowed input version not defined for version", txin.version())
        }
    }

    for (const auto& output : input.output()) {
        try {
            const bool validOutput = Check(
                output,
                BlockchainTransactionAllowedOutput.at(input.version()).first,
                BlockchainTransactionAllowedOutput.at(input.version()).second,
                silent);

            if (false == validOutput) { FAIL_1("invalid output") }
        } catch (const std::out_of_range&) {
            FAIL_2(
                "allowed output version not defined for version",
                input.version())
        }
    }

    if (input.has_blockhash()) {
        if (MIN_PLAUSIBLE_IDENTIFIER > input.blockhash().size()) {
            FAIL_1("invalid blockhash")
        }

        if (MIN_PLAUSIBLE_IDENTIFIER < input.blockhash().size()) {
            FAIL_1("invalid blockhash")
        }
    }

    for (const auto& conflict : input.conflicts()) {
        if (MIN_PLAUSIBLE_IDENTIFIER > conflict.size()) {
            FAIL_1("invalid conflict")
        }

        if (MIN_PLAUSIBLE_IDENTIFIER < conflict.size()) {
            FAIL_1("invalid conflict")
        }
    }

    if (MAX_TRANSACTION_MEMO_SIZE < input.memo().size()) {
        FAIL_1("invalid memo")
    }

    return true;
}

bool CheckProto_2(const BlockchainTransaction& input, const bool silent)
{
    UNDEFINED_VERSION(2)
}

bool CheckProto_3(const BlockchainTransaction& input, const bool silent)
{
    UNDEFINED_VERSION(3)
}

bool CheckProto_4(const BlockchainTransaction& input, const bool silent)
{
    UNDEFINED_VERSION(4)
}

bool CheckProto_5(const BlockchainTransaction& input, const bool silent)
{
    UNDEFINED_VERSION(5)
}

bool CheckProto_6(const BlockchainTransaction& input, const bool silent)
{
    UNDEFINED_VERSION(6)
}

bool CheckProto_7(const BlockchainTransaction& input, const bool silent)
{
    UNDEFINED_VERSION(7)
}

bool CheckProto_8(const BlockchainTransaction& input, const bool silent)
{
    UNDEFINED_VERSION(8)
}

bool CheckProto_9(const BlockchainTransaction& input, const bool silent)
{
    UNDEFINED_VERSION(9)
}

bool CheckProto_10(const BlockchainTransaction& input, const bool silent)
{
    UNDEFINED_VERSION(10)
}

bool CheckProto_11(const BlockchainTransaction& input, const bool silent)
{
    UNDEFINED_VERSION(11)
}

bool CheckProto_12(const BlockchainTransaction& input, const bool silent)
{
    UNDEFINED_VERSION(12)
}

bool CheckProto_13(const BlockchainTransaction& input, const bool silent)
{
    UNDEFINED_VERSION(13)
}

bool CheckProto_14(const BlockchainTransaction& input, const bool silent)
{
    UNDEFINED_VERSION(14)
}

bool CheckProto_15(const BlockchainTransaction& input, const bool silent)
{
    UNDEFINED_VERSION(15)
}

bool CheckProto_16(const BlockchainTransaction& input, const bool silent)
{
    UNDEFINED_VERSION(16)
}

bool CheckProto_17(const BlockchainTransaction& input, const bool silent)
{
    UNDEFINED_VERSION(17)
}

bool CheckProto_18(const BlockchainTransaction& input, const bool silent)
{
    UNDEFINED_VERSION(18)
}

bool CheckProto_19(const BlockchainTransaction& input, const bool silent)
{
    UNDEFINED_VERSION(19)
}

bool CheckProto_20(const BlockchainTransaction& input, const bool silent)
{
    UNDEFINED_VERSION(20)
}
}  // namespace proto
}  // namespace opentxs
