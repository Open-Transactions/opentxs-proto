// Copyright (c) 2018 The Open-Transactions developers
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
static const VersionMap StorageContactsAllowedAddress = {
    {1, {1, 1}},
    {2, {1, 1}},
};
static const VersionMap StorageContactsAllowedHash = {
    {1, {1, 2}},
    {2, {1, 2}},
};
static const VersionMap StorageContactsAllowedList = {
    {1, {1, 1}},
    {2, {1, 1}},
};
static const VersionMap StorageContactsAllowedNym = {
    {2, {1, 1}},
};
static const VersionMap StorageCredentialAllowedHash = {
    {1, {1, 1}},
    {2, {1, 2}},
};
static const VersionMap StorageNymAllowedHash = {
    {1, {1, 1}},
    {2, {1, 2}},
    {3, {2, 3}},
    {4, {2, 4}},
    {5, {2, 5}},
    {6, {2, 6}},
    {7, {2, 7}},
};
static const VersionMap StorageNymAllowedBip44Account{
    {4, {1, 1}},
    {5, {1, 1}},
    {6, {1, 1}},
    {7, {1, 1}},
};
static const VersionMap StorageNymAllowedStorageBip47AddressIndex{
    {7, {1, 1}},
};
static const VersionMap StorageNymAllowedBlockchainAccountList{
    {4, {1, 1}},
    {5, {1, 1}},
    {6, {1, 1}},
    {7, {1, 1}},
};
static const VersionMap StorageNymListAllowedStorageBip47NymAddressIndex = {
    {4, {1, 1}},
};
static const VersionMap StorageNymListAllowedHash = {
    {1, {1, 1}},
    {2, {1, 2}},
    {3, {1, 3}},
    {4, {1, 4}},
};
static const VersionMap StoragePaymentWorkflowsAllowedHash = {
    {1, {1, 2}},
};
static const VersionMap StoragePaymentWorkflowsAllowedIndex = {
    {1, {1, 1}},
};
static const VersionMap StoragePaymentWorkflowsAllowedType = {
    {1, {1, 1}},
};
static const VersionMap StorageServersAllowedHash = {
    {1, {1, 1}},
    {2, {1, 2}},
};
static const VersionMap StorageThreadAllowedItem = {
    {1, {1, 1}},
};
static const VersionMap StorageUnitsAllowedHash = {
    {1, {1, 1}},
    {2, {1, 2}},
};
static const VersionMap StorageSeedsAllowedHash = {
    {1, {1, 1}},
    {2, {1, 2}},
};
static const VersionMap StorageIssuerAllowedHash = {
    {1, {1, 2}},
};
}  // namespace proto
}  // namespace opentxs
#endif  // OPENTXS_PROTO_VERIFYSTORAGE_HPP
