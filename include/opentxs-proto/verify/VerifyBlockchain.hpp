// Copyright (c) 2018 The Open-Transactions developers
// This Source Code Form is subject to the terms of the Mozilla Public
// License, v. 2.0. If a copy of the MPL was not distributed with this
// file, You can obtain one at http://mozilla.org/MPL/2.0/.

#ifndef OPENTXS_PROTO_VERIFYBLOCKCHAIN_HPP
#define OPENTXS_PROTO_VERIFYBLOCKCHAIN_HPP

#include "opentxs-proto/Basic.hpp"

namespace opentxs
{
namespace proto
{
static const VersionMap Bip44AccountAllowedBip44Address = {
    {1, {1, 1}},
};
static const VersionMap Bip44AccountAllowedHDPath = {
    {1, {1, 1}},
};
static const VersionMap Bip47ChainAllowedBip47Channel = {
    {1, {1, 1}},
};
static const VersionMap Bip47ChannelAllowedBip47Direction = {
    {1, {1, 1}},
};
static const VersionMap Bip47ContextAllowedBip47Chain = {
    {1, {1, 1}},
};
static const VersionMap Bip47DirectionAllowedBip47Address = {
    {1, {1, 1}},
};
static const VersionMap BlockchainTransactionAllowedInput = {
    {1, {1, 1}},
};
static const VersionMap BlockchainTransactionAllowedOutput = {
    {1, {1, 1}},
};
static const VersionMap StorageBlockchainTransactionsAllowedStorageItemHash = {
    {1, {1, 2}},
};
}  // namespace proto
}  // namespace opentxs
#endif  // OPENTXS_PROTO_VERIFYBLOCKCHAIN_HPP
