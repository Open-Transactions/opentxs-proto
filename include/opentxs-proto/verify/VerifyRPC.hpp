// Copyright (c) 2018 The Open-Transactions developers
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
static const VersionMap AddClaimAllowedContactItem = {
    {1, {1, 5}},
    {2, {1, 6}},
};
static const VersionMap ContactEventAllowedAccountEvent = {
    {1, {1, 1}},
    {2, {1, 2}},
};
static const VersionMap CreateNymAllowedAddClaim = {
    {1, {1, 1}},
    {2, {1, 2}},
};
static const VersionMap RPCCommandAllowedAcceptPendingPayment = {
    {1, {1, 1}},
    {2, {1, 1}},
};
static const VersionMap RPCCommandAllowedAddContact = {
    {1, {1, 1}},
    {2, {1, 1}},
};
static const VersionMap RPCCommandAllowedAPIArgument = {
    {1, {1, 1}},
    {2, {1, 1}},
};
static const VersionMap RPCCommandAllowedAddClaim = {
    {1, {1, 1}},
    {2, {1, 2}},
};
static const VersionMap RPCCommandAllowedCreateInstrumentDefinition = {
    {1, {1, 1}},
    {2, {1, 1}},
};
static const VersionMap RPCCommandAllowedCreateNym = {
    {1, {1, 1}},
    {2, {1, 2}},
};
static const VersionMap RPCCommandAllowedGetWorkflow = {
    {1, {1, 1}},
    {2, {1, 1}},
};
static const VersionMap RPCCommandAllowedHDSeed = {
    {1, {1, 1}},
    {2, {1, 1}},
};
static const VersionMap RPCCommandAllowedModifyAccount = {
    {2, {1, 1}},
};
static const VersionMap RPCCommandAllowedSendMessage = {
    {1, {1, 1}},
    {2, {1, 1}},
};
static const VersionMap RPCCommandAllowedSendPayment = {
    {1, {1, 1}},
    {2, {1, 1}},
};
static const VersionMap RPCCommandAllowedServerContract = {
    {1, {1, 2}},
    {2, {1, 2}},
};
static const VersionMap RPCCommandAllowedVerification = {
    {1, {1, 1}},
    {2, {1, 1}},
};
static const VersionMap RPCCommandAllowedVerifyClaim = {
    {1, {1, 1}},
    {2, {1, 1}},
};
static const VersionMap RPCPushAllowedAccountEvent = {
    {1, {1, 1}},
    {2, {1, 2}},
    {3, {1, 2}},
};
static const VersionMap RPCPushAllowedContactEvent = {
    {1, {1, 1}},
    {2, {1, 2}},
    {3, {1, 2}},
};
static const VersionMap RPCPushAllowedTaskComplete = {
    {1, {1, 1}},
    {2, {1, 1}},
    {3, {1, 2}},
};
static const VersionMap RPCResponseAllowedAccountData = {
    {1, {1, 1}},
    {2, {1, 2}},
};
static const VersionMap RPCResponseAllowedAccountEvent = {
    {1, {1, 1}},
    {2, {1, 2}},
};
static const VersionMap RPCResponseAllowedContact = {
    {1, {1, 2}},
    {2, {1, 3}},
};
static const VersionMap RPCResponseAllowedContactEvent = {
    {1, {1, 2}},
    {2, {1, 2}},
};
static const VersionMap RPCResponseAllowedCredentialIndex = {
    {1, {1, 5}},
    {2, {1, 6}},
};
static const VersionMap RPCResponseAllowedHDSeed = {
    {1, {1, 1}},
    {2, {1, 1}},
};
static const VersionMap RPCResponseAllowedRPCStatus = {
    {1, {1, 1}},
    {2, {1, 2}},
};
static const VersionMap RPCResponseAllowedRPCTask = {
    {1, {1, 1}},
    {2, {1, 1}},
};
static const VersionMap RPCResponseAllowedServerContract = {
    {1, {1, 2}},
    {2, {1, 2}},
};
static const VersionMap RPCResponseAllowedSessionData = {
    {1, {1, 1}},
    {2, {1, 1}},
};
static const VersionMap RPCResponseAllowedTransactionData = {
    {2, {1, 1}},
};
static const VersionMap RPCResponseAllowedUnitDefinition = {
    {2, {1, 1}},
};
static const VersionMap RPCResponseAllowedWorkflow = {
    {1, {1, 2}},
    {2, {1, 2}},
};
}  // namespace proto
}  // namespace opentxs
#endif  // OPENTXS_PROTO_VERIFYRPC_HPP
