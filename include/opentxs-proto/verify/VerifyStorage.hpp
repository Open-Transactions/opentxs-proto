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
static const VersionMap BlindedSeriesListAllowedStorageItemHash = {
    {1, {1, 2}},
};
static const VersionMap StorageAccountsAllowedStorageAccountIndex = {
    {1, {1, 1}},
};
static const VersionMap StorageAccountsAllowedStorageItemHash = {
    {1, {1, 2}},
};
static const VersionMap StorageAccountsAllowedStorageIDList = {
    {1, {1, 1}},
};
static const VersionMap StorageBip47ContextsAllowedStorageBip47AddressIndex = {
    {1, {1, 1}}};
static const VersionMap StorageBip47ContextsAllowedStorageItemHash = {
    {1, {1, 2}}};
static const VersionMap StorageBip47ContextsAllowedStorageBip47ChannelList = {
    {1, {1, 1}}};
static const VersionMap StorageBlockchainTransactionsAllowedStorageItemHash = {
    {1, {1, 2}},
    {2, {1, 2}},
};
static const VersionMap
    StorageBlockchainTransactionsAllowedStorageContactNymIndex = {
        {2, {1, 1}},
};
static const VersionMap StorageBlockchainTxoAllowedBlockchainPreviousOutput = {
    {1, {1, 1}}};
static const VersionMap StorageContactsAllowedAddress = {
    {1, {1, 1}},
    {2, {1, 1}},
};
static const VersionMap StorageContactsAllowedStorageItemHash = {
    {1, {1, 2}},
    {2, {1, 2}},
};
static const VersionMap StorageContactsAllowedList = {
    {1, {1, 1}},
    {2, {1, 1}},
};
static const VersionMap StorageContactsAllowedStorageContactNymIndex = {
    {2, {1, 1}},
};
static const VersionMap StorageCredentialAllowedStorageItemHash = {
    {1, {1, 1}},
    {2, {1, 2}},
};
static const VersionMap StorageItemsAllowedSymmetricKey = {
    {6, {1, 1}},
};
static const VersionMap StorageNotaryAllowedBlindedSeriesList = {
    {1, {1, 1}},
};
static const VersionMap StorageNymAllowedStorageItemHash = {
    {1, {1, 1}},
    {2, {1, 2}},
    {3, {2, 3}},
    {4, {2, 4}},
    {5, {2, 5}},
    {6, {2, 6}},
    {7, {2, 7}},
    {8, {2, 8}},
    {9, {2, 9}},
};
static const VersionMap StorageNymAllowedHDAccount{
    {4, {1, 1}},
    {5, {1, 1}},
    {6, {1, 1}},
    {7, {1, 1}},
    {8, {1, 1}},
    {9, {1, 1}},
};
static const VersionMap StorageNymAllowedStorageBip47AddressIndex{
    {7, {1, 1}},
    {8, {1, 1}},
    {9, {1, 1}},
};
static const VersionMap StorageNymAllowedBlockchainAccountList{
    {4, {1, 1}},
    {5, {1, 1}},
    {6, {1, 1}},
    {7, {1, 1}},
    {8, {1, 1}},
    {9, {1, 1}},
};
static const VersionMap StorageNymAllowedStoragePurse{
    {8, {1, 1}},
    {9, {1, 1}},
};
static const VersionMap StorageNymListAllowedStorageBip47NymAddressIndex = {
    {4, {1, 1}},
};
static const VersionMap StorageNymListAllowedStorageItemHash = {
    {1, {1, 1}},
    {2, {1, 2}},
    {3, {1, 3}},
    {4, {1, 4}},
};
static const VersionMap StoragePaymentWorkflowsAllowedStorageItemHash = {
    {1, {1, 2}},
    {2, {1, 2}},
    {3, {1, 2}},
};
static const VersionMap StoragePaymentWorkflowsAllowedStorageWorkflowIndex = {
    {1, {1, 1}},
    {2, {1, 1}},
    {3, {1, 1}},
};
static const VersionMap
    StoragePaymentWorkflowsAllowedStoragePaymentWorkflowType = {
        {1, {1, 1}},
        {2, {1, 2}},
        {3, {3, 3}},
};
static const VersionMap StoragePurseAllowedStorageItemHash = {
    {1, {1, 2}},
};
static const VersionMap StorageServersAllowedStorageItemHash = {
    {1, {1, 1}},
    {2, {1, 2}},
};
static const VersionMap StorageThreadAllowedItem = {
    {1, {1, 1}},
};
static const VersionMap StorageTxoIndexAllowedStorageBlockchainTxo = {
    {1, {1, 1}},
};
static const VersionMap StorageUnitsAllowedStorageItemHash = {
    {1, {1, 1}},
    {2, {1, 2}},
};
static const VersionMap StorageSeedsAllowedStorageItemHash = {
    {1, {1, 1}},
    {2, {1, 2}},
};
static const VersionMap StorageIssuerAllowedStorageItemHash = {
    {1, {1, 2}},
};
}  // namespace proto
}  // namespace opentxs
#endif  // OPENTXS_PROTO_VERIFYSTORAGE_HPP
