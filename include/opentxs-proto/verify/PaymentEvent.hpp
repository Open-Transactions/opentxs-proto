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

#ifndef OPENTXS_PROTO_PAYMENTEVENT_HPP
#define OPENTXS_PROTO_PAYMENTEVENT_HPP

#include "VerifyWorkflows.hpp"

namespace opentxs
{
namespace proto
{
bool CheckProto_1(
    const PaymentEvent& input,
    const bool silent,
    const std::uint32_t parentVersion,
    const PaymentWorkflowType parent,
    std::map<PaymentEventType, std::size_t>& events);
bool CheckProto_2(
    const PaymentEvent& input,
    const bool silent,
    const std::uint32_t parentVersion,
    const PaymentWorkflowType parent,
    std::map<PaymentEventType, std::size_t>& events);
bool CheckProto_3(
    const PaymentEvent& input,
    const bool silent,
    const std::uint32_t parentVersion,
    const PaymentWorkflowType parent,
    std::map<PaymentEventType, std::size_t>& events);
bool CheckProto_4(
    const PaymentEvent& input,
    const bool silent,
    const std::uint32_t parentVersion,
    const PaymentWorkflowType parent,
    std::map<PaymentEventType, std::size_t>& events);
bool CheckProto_5(
    const PaymentEvent& input,
    const bool silent,
    const std::uint32_t parentVersion,
    const PaymentWorkflowType parent,
    std::map<PaymentEventType, std::size_t>& events);
bool CheckProto_6(
    const PaymentEvent& input,
    const bool silent,
    const std::uint32_t parentVersion,
    const PaymentWorkflowType parent,
    std::map<PaymentEventType, std::size_t>& events);
bool CheckProto_7(
    const PaymentEvent& input,
    const bool silent,
    const std::uint32_t parentVersion,
    const PaymentWorkflowType parent,
    std::map<PaymentEventType, std::size_t>& events);
bool CheckProto_8(
    const PaymentEvent& input,
    const bool silent,
    const std::uint32_t parentVersion,
    const PaymentWorkflowType parent,
    std::map<PaymentEventType, std::size_t>& events);
bool CheckProto_9(
    const PaymentEvent& input,
    const bool silent,
    const std::uint32_t parentVersion,
    const PaymentWorkflowType parent,
    std::map<PaymentEventType, std::size_t>& events);
bool CheckProto_10(
    const PaymentEvent& input,
    const bool silent,
    const std::uint32_t parentVersion,
    const PaymentWorkflowType parent,
    std::map<PaymentEventType, std::size_t>& events);
bool CheckProto_11(
    const PaymentEvent& input,
    const bool silent,
    const std::uint32_t parentVersion,
    const PaymentWorkflowType parent,
    std::map<PaymentEventType, std::size_t>& events);
bool CheckProto_12(
    const PaymentEvent& input,
    const bool silent,
    const std::uint32_t parentVersion,
    const PaymentWorkflowType parent,
    std::map<PaymentEventType, std::size_t>& events);
bool CheckProto_13(
    const PaymentEvent& input,
    const bool silent,
    const std::uint32_t parentVersion,
    const PaymentWorkflowType parent,
    std::map<PaymentEventType, std::size_t>& events);
bool CheckProto_14(
    const PaymentEvent& input,
    const bool silent,
    const std::uint32_t parentVersion,
    const PaymentWorkflowType parent,
    std::map<PaymentEventType, std::size_t>& events);
bool CheckProto_15(
    const PaymentEvent& input,
    const bool silent,
    const std::uint32_t parentVersion,
    const PaymentWorkflowType parent,
    std::map<PaymentEventType, std::size_t>& events);
bool CheckProto_16(
    const PaymentEvent& input,
    const bool silent,
    const std::uint32_t parentVersion,
    const PaymentWorkflowType parent,
    std::map<PaymentEventType, std::size_t>& events);
bool CheckProto_17(
    const PaymentEvent& input,
    const bool silent,
    const std::uint32_t parentVersion,
    const PaymentWorkflowType parent,
    std::map<PaymentEventType, std::size_t>& events);
bool CheckProto_18(
    const PaymentEvent& input,
    const bool silent,
    const std::uint32_t parentVersion,
    const PaymentWorkflowType parent,
    std::map<PaymentEventType, std::size_t>& events);
bool CheckProto_19(
    const PaymentEvent& input,
    const bool silent,
    const std::uint32_t parentVersion,
    const PaymentWorkflowType parent,
    std::map<PaymentEventType, std::size_t>& events);
bool CheckProto_20(
    const PaymentEvent& input,
    const bool silent,
    const std::uint32_t parentVersion,
    const PaymentWorkflowType parent,
    std::map<PaymentEventType, std::size_t>& events);
}  // namespace proto
}  // namespace opentxs
#endif  // OPENTXS_PROTO_PAYMENTEVENT_HPP
