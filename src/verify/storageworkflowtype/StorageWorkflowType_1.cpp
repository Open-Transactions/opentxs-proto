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

#define PROTO_NAME "storage workflow type index"

namespace opentxs::proto
{
bool CheckProto_1(const StorageWorkflowType& input, const bool silent)
{
    CHECK_IDENTIFIER(workflow)

    switch (input.type()) {
        case PAYMENTWORKFLOWTYPE_OUTGOINGCHEQUE: {
            switch (input.state()) {
                case PAYMENTWORKFLOWSTATE_UNSENT:
                case PAYMENTWORKFLOWSTATE_CONVEYED:
                case PAYMENTWORKFLOWSTATE_CANCELLED:
                case PAYMENTWORKFLOWSTATE_ACCEPTED:
                case PAYMENTWORKFLOWSTATE_COMPLETED:
                case PAYMENTWORKFLOWSTATE_EXPIRED: {
                } break;
                case PAYMENTWORKFLOWSTATE_ERROR:
                default: {
                    FAIL5(
                        "invalid state",
                        static_cast<std::uint32_t>(input.state()))
                }
            }
        } break;
        case PAYMENTWORKFLOWTYPE_INCOMINGCHEQUE: {
            switch (input.state()) {
                case PAYMENTWORKFLOWSTATE_CONVEYED:
                case PAYMENTWORKFLOWSTATE_COMPLETED:
                case PAYMENTWORKFLOWSTATE_EXPIRED: {
                } break;
                case PAYMENTWORKFLOWSTATE_UNSENT:
                case PAYMENTWORKFLOWSTATE_CANCELLED:
                case PAYMENTWORKFLOWSTATE_ACCEPTED:
                case PAYMENTWORKFLOWSTATE_ERROR:
                default: {
                    FAIL5(
                        "invalid state",
                        static_cast<std::uint32_t>(input.state()))
                }
            }
        } break;
        case PAYMENTWORKFLOWTYPE_OUTGOINGINVOICE: {
            switch (input.state()) {
                case PAYMENTWORKFLOWSTATE_UNSENT:
                case PAYMENTWORKFLOWSTATE_CONVEYED:
                case PAYMENTWORKFLOWSTATE_CANCELLED:
                case PAYMENTWORKFLOWSTATE_ACCEPTED:
                case PAYMENTWORKFLOWSTATE_COMPLETED:
                case PAYMENTWORKFLOWSTATE_EXPIRED: {
                } break;
                case PAYMENTWORKFLOWSTATE_ERROR:
                default: {
                    FAIL5(
                        "invalid state",
                        static_cast<std::uint32_t>(input.state()))
                }
            }
        } break;
        case PAYMENTWORKFLOWTYPE_INCOMINGINVOICE: {
            switch (input.state()) {
                case PAYMENTWORKFLOWSTATE_CONVEYED:
                case PAYMENTWORKFLOWSTATE_COMPLETED:
                case PAYMENTWORKFLOWSTATE_EXPIRED: {
                } break;
                case PAYMENTWORKFLOWSTATE_UNSENT:
                case PAYMENTWORKFLOWSTATE_CANCELLED:
                case PAYMENTWORKFLOWSTATE_ACCEPTED:
                case PAYMENTWORKFLOWSTATE_ERROR:
                default: {
                    FAIL5(
                        "invalid state",
                        static_cast<std::uint32_t>(input.state()))
                }
            }
        } break;
        case PAYMENTWORKFLOWTYPE_ERROR:
        default: {
            FAIL5("invalid type", static_cast<std::uint32_t>(input.type()))
        }
    }

    return true;
}

bool CheckProto_2(const StorageWorkflowType& input, const bool silent)
{
    UNDEFINED_VERSION2(2)
}

bool CheckProto_3(const StorageWorkflowType& input, const bool silent)
{
    UNDEFINED_VERSION2(3)
}

bool CheckProto_4(const StorageWorkflowType& input, const bool silent)
{
    UNDEFINED_VERSION2(4)
}

bool CheckProto_5(const StorageWorkflowType& input, const bool silent)
{
    UNDEFINED_VERSION2(5)
}

bool CheckProto_6(const StorageWorkflowType& input, const bool silent)
{
    UNDEFINED_VERSION2(6)
}

bool CheckProto_7(const StorageWorkflowType& input, const bool silent)
{
    UNDEFINED_VERSION2(7)
}

bool CheckProto_8(const StorageWorkflowType& input, const bool silent)
{
    UNDEFINED_VERSION2(8)
}

bool CheckProto_9(const StorageWorkflowType& input, const bool silent)
{
    UNDEFINED_VERSION2(9)
}

bool CheckProto_10(const StorageWorkflowType& input, const bool silent)
{
    UNDEFINED_VERSION2(10)
}

bool CheckProto_11(const StorageWorkflowType& input, const bool silent)
{
    UNDEFINED_VERSION2(11)
}

bool CheckProto_12(const StorageWorkflowType& input, const bool silent)
{
    UNDEFINED_VERSION2(12)
}

bool CheckProto_13(const StorageWorkflowType& input, const bool silent)
{
    UNDEFINED_VERSION2(13)
}

bool CheckProto_14(const StorageWorkflowType& input, const bool silent)
{
    UNDEFINED_VERSION2(14)
}

bool CheckProto_15(const StorageWorkflowType& input, const bool silent)
{
    UNDEFINED_VERSION2(15)
}

bool CheckProto_16(const StorageWorkflowType& input, const bool silent)
{
    UNDEFINED_VERSION2(16)
}

bool CheckProto_17(const StorageWorkflowType& input, const bool silent)
{
    UNDEFINED_VERSION2(17)
}

bool CheckProto_18(const StorageWorkflowType& input, const bool silent)
{
    UNDEFINED_VERSION2(18)
}

bool CheckProto_19(const StorageWorkflowType& input, const bool silent)
{
    UNDEFINED_VERSION2(19)
}

bool CheckProto_20(const StorageWorkflowType& input, const bool silent)
{
    UNDEFINED_VERSION2(20)
}
}  // namespace opentxs::proto
