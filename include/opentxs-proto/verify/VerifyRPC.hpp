// Copyright (c) 2019 The Open-Transactions developers
// This Source Code Form is subject to the terms of the Mozilla Public
// License, v. 2.0. If a copy of the MPL was not distributed with this
// file, You can obtain one at http://mozilla.org/MPL/2.0/.

#ifndef OPENTXS_PROTO_VERIFYRPC_HPP
#define OPENTXS_PROTO_VERIFYRPC_HPP

#include "opentxs-proto/Basic.hpp"

namespace opentxs
{
namespace proto
{
OPENTXS_PROTO_EXPORT const VersionMap& AddClaimAllowedContactItem() noexcept;
OPENTXS_PROTO_EXPORT const VersionMap&
ContactEventAllowedAccountEvent() noexcept;
OPENTXS_PROTO_EXPORT const VersionMap& CreateNymAllowedAddClaim() noexcept;
OPENTXS_PROTO_EXPORT const VersionMap& RPCCommandAllowedAPIArgument() noexcept;
OPENTXS_PROTO_EXPORT const VersionMap&
RPCCommandAllowedAcceptPendingPayment() noexcept;
OPENTXS_PROTO_EXPORT const VersionMap& RPCCommandAllowedAddClaim() noexcept;
OPENTXS_PROTO_EXPORT const VersionMap& RPCCommandAllowedAddContact() noexcept;
OPENTXS_PROTO_EXPORT const VersionMap&
RPCCommandAllowedCreateInstrumentDefinition() noexcept;
OPENTXS_PROTO_EXPORT const VersionMap& RPCCommandAllowedCreateNym() noexcept;
OPENTXS_PROTO_EXPORT const VersionMap& RPCCommandAllowedGetWorkflow() noexcept;
OPENTXS_PROTO_EXPORT const VersionMap& RPCCommandAllowedHDSeed() noexcept;
OPENTXS_PROTO_EXPORT const VersionMap&
RPCCommandAllowedModifyAccount() noexcept;
OPENTXS_PROTO_EXPORT const VersionMap& RPCCommandAllowedSendMessage() noexcept;
OPENTXS_PROTO_EXPORT const VersionMap& RPCCommandAllowedSendPayment() noexcept;
OPENTXS_PROTO_EXPORT const VersionMap&
RPCCommandAllowedServerContract() noexcept;
OPENTXS_PROTO_EXPORT const VersionMap& RPCCommandAllowedVerification() noexcept;
OPENTXS_PROTO_EXPORT const VersionMap& RPCCommandAllowedVerifyClaim() noexcept;
OPENTXS_PROTO_EXPORT const VersionMap& RPCPushAllowedAccountEvent() noexcept;
OPENTXS_PROTO_EXPORT const VersionMap& RPCPushAllowedContactEvent() noexcept;
OPENTXS_PROTO_EXPORT const VersionMap& RPCPushAllowedTaskComplete() noexcept;
OPENTXS_PROTO_EXPORT const VersionMap& RPCResponseAllowedAccountData() noexcept;
OPENTXS_PROTO_EXPORT const VersionMap&
RPCResponseAllowedAccountEvent() noexcept;
OPENTXS_PROTO_EXPORT const VersionMap& RPCResponseAllowedContact() noexcept;
OPENTXS_PROTO_EXPORT const VersionMap&
RPCResponseAllowedContactEvent() noexcept;
OPENTXS_PROTO_EXPORT const VersionMap& RPCResponseAllowedHDSeed() noexcept;
OPENTXS_PROTO_EXPORT const VersionMap& RPCResponseAllowedNym() noexcept;
OPENTXS_PROTO_EXPORT const VersionMap& RPCResponseAllowedRPCStatus() noexcept;
OPENTXS_PROTO_EXPORT const VersionMap& RPCResponseAllowedRPCTask() noexcept;
OPENTXS_PROTO_EXPORT const VersionMap&
RPCResponseAllowedServerContract() noexcept;
OPENTXS_PROTO_EXPORT const VersionMap& RPCResponseAllowedSessionData() noexcept;
OPENTXS_PROTO_EXPORT const VersionMap&
RPCResponseAllowedTransactionData() noexcept;
OPENTXS_PROTO_EXPORT const VersionMap&
RPCResponseAllowedUnitDefinition() noexcept;
OPENTXS_PROTO_EXPORT const VersionMap& RPCResponseAllowedWorkflow() noexcept;
}  // namespace proto
}  // namespace opentxs
#endif  // OPENTXS_PROTO_VERIFYRPC_HPP
