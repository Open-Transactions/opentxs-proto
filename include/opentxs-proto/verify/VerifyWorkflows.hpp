// Copyright (c) 2020 The Open-Transactions developers
// This Source Code Form is subject to the terms of the Mozilla Public
// License, v. 2.0. If a copy of the MPL was not distributed with this
// file, You can obtain one at http://mozilla.org/MPL/2.0/.

#ifndef OPENTXS_PROTO_VERIFYWORKFLOWS_HPP
#define OPENTXS_PROTO_VERIFYWORKFLOWS_HPP

#include "opentxs-proto/Basic.hpp"

#include <cstdint>
#include <map>
#include <set>
#include <tuple>

namespace opentxs
{
namespace proto
{
using PaymentWorkflowVersion = std::pair<std::uint32_t, PaymentWorkflowType>;
using WorkflowEventMap =
    std::map<PaymentWorkflowVersion, std::set<PaymentEventType>>;
using PaymentTypeVersion = std::pair<std::uint32_t, PaymentWorkflowType>;
using WorkflowStateMap =
    std::map<PaymentTypeVersion, std::set<PaymentWorkflowState>>;
using PaymentEventVersion = std::pair<std::uint32_t, PaymentEventType>;
using EventTransportMap =
    std::map<PaymentEventVersion, std::set<EventTransportMethod>>;

OPENTXS_PROTO_EXPORT const EventTransportMap&
PaymentEventAllowedTransportMethod() noexcept;
OPENTXS_PROTO_EXPORT const WorkflowEventMap&
PaymentWorkflowAllowedEventTypes() noexcept;
OPENTXS_PROTO_EXPORT const VersionMap&
PaymentWorkflowAllowedInstrumentRevision() noexcept;
OPENTXS_PROTO_EXPORT const VersionMap&
PaymentWorkflowAllowedPaymentEvent() noexcept;
OPENTXS_PROTO_EXPORT const WorkflowStateMap&
PaymentWorkflowAllowedState() noexcept;
}  // namespace proto
}  // namespace opentxs
#endif  // OPENTXS_PROTO_VERIFYWORKFLOWS_HPP
