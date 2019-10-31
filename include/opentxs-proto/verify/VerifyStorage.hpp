// Copyright (c) 2019 The Open-Transactions developers
// This Source Code Form is subject to the terms of the Mozilla Public
// License, v. 2.0. If a copy of the MPL was not distributed with this
// file, You can obtain one at http://mozilla.org/MPL/2.0/.

#ifndef OPENTXS_PROTO_VERIFYSTORAGE_HPP
#define OPENTXS_PROTO_VERIFYSTORAGE_HPP

#include "opentxs-proto/Basic.hpp"

namespace opentxs
{
namespace proto
{
OPENTXS_PROTO_EXPORT const VersionMap&
BlindedSeriesListAllowedStorageItemHash() noexcept;
OPENTXS_PROTO_EXPORT const VersionMap&
StorageAccountsAllowedStorageAccountIndex() noexcept;
OPENTXS_PROTO_EXPORT const VersionMap&
StorageAccountsAllowedStorageItemHash() noexcept;
OPENTXS_PROTO_EXPORT const VersionMap&
StorageAccountsAllowedStorageIDList() noexcept;
OPENTXS_PROTO_EXPORT const VersionMap&
StorageBip47ContextsAllowedStorageBip47AddressIndex() noexcept;
OPENTXS_PROTO_EXPORT const VersionMap&
StorageBip47ContextsAllowedStorageItemHash() noexcept;
OPENTXS_PROTO_EXPORT const VersionMap&
StorageBip47ContextsAllowedStorageBip47ChannelList() noexcept;
OPENTXS_PROTO_EXPORT const VersionMap&
StorageBlockchainTransactionsAllowedStorageContactNymIndex() noexcept;
OPENTXS_PROTO_EXPORT const VersionMap&
StorageBlockchainTransactionsAllowedStorageItemHash() noexcept;
OPENTXS_PROTO_EXPORT const VersionMap&
StorageBlockchainTxoAllowedBlockchainPreviousOutput() noexcept;
OPENTXS_PROTO_EXPORT const VersionMap& StorageContactsAllowedAddress() noexcept;
OPENTXS_PROTO_EXPORT const VersionMap& StorageContactsAllowedList() noexcept;
OPENTXS_PROTO_EXPORT const VersionMap&
StorageContactsAllowedStorageContactNymIndex() noexcept;
OPENTXS_PROTO_EXPORT const VersionMap&
StorageContactsAllowedStorageItemHash() noexcept;
OPENTXS_PROTO_EXPORT const VersionMap&
StorageCredentialAllowedStorageItemHash() noexcept;
OPENTXS_PROTO_EXPORT const VersionMap&
StorageIssuerAllowedStorageItemHash() noexcept;
OPENTXS_PROTO_EXPORT const VersionMap&
StorageItemsAllowedSymmetricKey() noexcept;
OPENTXS_PROTO_EXPORT const VersionMap&
StorageNotaryAllowedBlindedSeriesList() noexcept;
OPENTXS_PROTO_EXPORT const VersionMap&
StorageNymAllowedBlockchainAccountList() noexcept;
OPENTXS_PROTO_EXPORT const VersionMap& StorageNymAllowedHDAccount() noexcept;
OPENTXS_PROTO_EXPORT const VersionMap&
StorageNymAllowedStorageBip47AddressIndex() noexcept;
OPENTXS_PROTO_EXPORT const VersionMap&
StorageNymAllowedStorageItemHash() noexcept;
OPENTXS_PROTO_EXPORT const VersionMap& StorageNymAllowedStoragePurse() noexcept;
OPENTXS_PROTO_EXPORT const VersionMap&
StorageNymListAllowedStorageBip47NymAddressIndex() noexcept;
OPENTXS_PROTO_EXPORT const VersionMap&
StorageNymListAllowedStorageItemHash() noexcept;
OPENTXS_PROTO_EXPORT const VersionMap&
StoragePaymentWorkflowsAllowedStorageItemHash() noexcept;
OPENTXS_PROTO_EXPORT const VersionMap&
StoragePaymentWorkflowsAllowedStoragePaymentWorkflowType() noexcept;
OPENTXS_PROTO_EXPORT const VersionMap&
StoragePaymentWorkflowsAllowedStorageWorkflowIndex() noexcept;
OPENTXS_PROTO_EXPORT const VersionMap&
StoragePurseAllowedStorageItemHash() noexcept;
OPENTXS_PROTO_EXPORT const VersionMap&
StorageSeedsAllowedStorageItemHash() noexcept;
OPENTXS_PROTO_EXPORT const VersionMap&
StorageServersAllowedStorageItemHash() noexcept;
OPENTXS_PROTO_EXPORT const VersionMap& StorageThreadAllowedItem() noexcept;
OPENTXS_PROTO_EXPORT const VersionMap&
StorageTxoIndexAllowedStorageBlockchainTxo() noexcept;
OPENTXS_PROTO_EXPORT const VersionMap&
StorageUnitsAllowedStorageItemHash() noexcept;
}  // namespace proto
}  // namespace opentxs
#endif  // OPENTXS_PROTO_VERIFYSTORAGE_HPP
