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

#define PROTO_NAME "payment workflow storage index"

namespace opentxs::proto
{
bool CheckProto_1(const StoragePaymentWorkflows& input, const bool silent)
{
    CHECK_SUBOBJECTS(workflow, StoragePaymentWorkflowsAllowedHash)
    CHECK_SUBOBJECTS(items, StoragePaymentWorkflowsAllowedIndex)
    CHECK_SUBOBJECTS(accounts, StoragePaymentWorkflowsAllowedIndex)
    CHECK_SUBOBJECTS(units, StoragePaymentWorkflowsAllowedIndex)
    CHECK_IDENTIFIERS(archived)
    CHECK_SUBOBJECTS(types, StoragePaymentWorkflowsAllowedType)

    if (input.workflow_size() != input.types_size()) {
        FAIL6(
            "Wrong number of index objects. Workflows: ",
            input.workflow_size(),
            " Index objects: ",
            input.types_size())
    }

    return true;
}

bool CheckProto_2(const StoragePaymentWorkflows& input, const bool silent)
{
    UNDEFINED_VERSION2(2)
}

bool CheckProto_3(const StoragePaymentWorkflows& input, const bool silent)
{
    UNDEFINED_VERSION2(3)
}

bool CheckProto_4(const StoragePaymentWorkflows& input, const bool silent)
{
    UNDEFINED_VERSION2(4)
}

bool CheckProto_5(const StoragePaymentWorkflows& input, const bool silent)
{
    UNDEFINED_VERSION2(5)
}

bool CheckProto_6(const StoragePaymentWorkflows& input, const bool silent)
{
    UNDEFINED_VERSION2(6)
}

bool CheckProto_7(const StoragePaymentWorkflows& input, const bool silent)
{
    UNDEFINED_VERSION2(7)
}

bool CheckProto_8(const StoragePaymentWorkflows& input, const bool silent)
{
    UNDEFINED_VERSION2(8)
}

bool CheckProto_9(const StoragePaymentWorkflows& input, const bool silent)
{
    UNDEFINED_VERSION2(9)
}

bool CheckProto_10(const StoragePaymentWorkflows& input, const bool silent)
{
    UNDEFINED_VERSION2(10)
}

bool CheckProto_11(const StoragePaymentWorkflows& input, const bool silent)
{
    UNDEFINED_VERSION2(11)
}

bool CheckProto_12(const StoragePaymentWorkflows& input, const bool silent)
{
    UNDEFINED_VERSION2(12)
}

bool CheckProto_13(const StoragePaymentWorkflows& input, const bool silent)
{
    UNDEFINED_VERSION2(13)
}

bool CheckProto_14(const StoragePaymentWorkflows& input, const bool silent)
{
    UNDEFINED_VERSION2(14)
}

bool CheckProto_15(const StoragePaymentWorkflows& input, const bool silent)
{
    UNDEFINED_VERSION2(15)
}

bool CheckProto_16(const StoragePaymentWorkflows& input, const bool silent)
{
    UNDEFINED_VERSION2(16)
}

bool CheckProto_17(const StoragePaymentWorkflows& input, const bool silent)
{
    UNDEFINED_VERSION2(17)
}

bool CheckProto_18(const StoragePaymentWorkflows& input, const bool silent)
{
    UNDEFINED_VERSION2(18)
}

bool CheckProto_19(const StoragePaymentWorkflows& input, const bool silent)
{
    UNDEFINED_VERSION2(19)
}

bool CheckProto_20(const StoragePaymentWorkflows& input, const bool silent)
{
    UNDEFINED_VERSION2(20)
}
}  // namespace opentxs::proto
