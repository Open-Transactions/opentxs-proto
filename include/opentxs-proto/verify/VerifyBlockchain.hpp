// Copyright (c) 2020 The Open-Transactions developers
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
OPENTXS_PROTO_EXPORT const VersionMap& Bip47ChainAllowedBip47Channel() noexcept;
OPENTXS_PROTO_EXPORT const VersionMap&
Bip47ChannelAllowedBip47Direction() noexcept;
OPENTXS_PROTO_EXPORT const VersionMap& Bip47ContextAllowedBip47Chain() noexcept;
OPENTXS_PROTO_EXPORT const VersionMap&
Bip47DirectionAllowedBip47Address() noexcept;
OPENTXS_PROTO_EXPORT const VersionMap&
BlockchainAddressAllowedAsymmetricKey() noexcept;
OPENTXS_PROTO_EXPORT const VersionMap&
BlockchainBlockHeaderAllowedBitcoinBlockHeaderFields() noexcept;
OPENTXS_PROTO_EXPORT const VersionMap&
BlockchainBlockHeaderAllowedBlockchainBlockLocalData() noexcept;
OPENTXS_PROTO_EXPORT const VersionMap&
BlockchainBlockHeaderAllowedEthereumBlockHeaderFields() noexcept;
OPENTXS_PROTO_EXPORT const VersionMap&
BlockchainTransactionAllowedInput() noexcept;
OPENTXS_PROTO_EXPORT const VersionMap&
BlockchainTransactionAllowedOutput() noexcept;
OPENTXS_PROTO_EXPORT const VersionMap&
BlockchainTransactionInputAllowedBlockchainInputWitness() noexcept;
OPENTXS_PROTO_EXPORT const VersionMap&
BlockchainTransactionInputAllowedBlockchainPreviousOutput() noexcept;
OPENTXS_PROTO_EXPORT const VersionMap&
BlockchainTransactionOutputAllowedBlockchainExternalAddress() noexcept;
OPENTXS_PROTO_EXPORT const VersionMap&
BlockchainTransactionOutputAllowedBlockchainWalletKey() noexcept;
OPENTXS_PROTO_EXPORT const VersionMap&
HDAccountAllowedBlockchainActivity() noexcept;
OPENTXS_PROTO_EXPORT const VersionMap&
HDAccountAllowedBlockchainAddress() noexcept;
OPENTXS_PROTO_EXPORT const VersionMap& HDAccountAllowedHDPath() noexcept;
}  // namespace proto
}  // namespace opentxs
#endif  // OPENTXS_PROTO_VERIFYBLOCKCHAIN_HPP
