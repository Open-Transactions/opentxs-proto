// Copyright (c) 2019 The Open-Transactions developers
// This Source Code Form is subject to the terms of the Mozilla Public
// License, v. 2.0. If a copy of the MPL was not distributed with this
// file, You can obtain one at http://mozilla.org/MPL/2.0/.

#include "opentxs-proto/Types.hpp"
#include "verify/Check.hpp"

#define PROTO_NAME "storage nym"

namespace opentxs::proto
{
bool CheckProto_9(const StorageNym& input, const bool silent)
{
    OPTIONAL_SUBOBJECT(credlist, StorageNymAllowedStorageItemHash);
    OPTIONAL_SUBOBJECT(sentpeerrequests, StorageNymAllowedStorageItemHash);
    OPTIONAL_SUBOBJECT(incomingpeerrequests, StorageNymAllowedStorageItemHash);
    OPTIONAL_SUBOBJECT(sentpeerreply, StorageNymAllowedStorageItemHash);
    OPTIONAL_SUBOBJECT(incomingpeerreply, StorageNymAllowedStorageItemHash);
    OPTIONAL_SUBOBJECT(finishedpeerrequest, StorageNymAllowedStorageItemHash);
    OPTIONAL_SUBOBJECT(finishedpeerreply, StorageNymAllowedStorageItemHash);
    OPTIONAL_SUBOBJECT(processedpeerrequest, StorageNymAllowedStorageItemHash);
    OPTIONAL_SUBOBJECT(processedpeerreply, StorageNymAllowedStorageItemHash);
    OPTIONAL_SUBOBJECT(mailinbox, StorageNymAllowedStorageItemHash);
    OPTIONAL_SUBOBJECT(mailoutbox, StorageNymAllowedStorageItemHash);
    OPTIONAL_SUBOBJECT(threads, StorageNymAllowedStorageItemHash);
    OPTIONAL_SUBOBJECT(contexts, StorageNymAllowedStorageItemHash);
    OPTIONAL_SUBOBJECT(accounts, StorageNymAllowedStorageItemHash);
    CHECK_SUBOBJECTS(
        blockchainaccountindex, StorageNymAllowedBlockchainAccountList);
    CHECK_SUBOBJECTS(hdaccount, StorageNymAllowedHDAccount);
    OPTIONAL_IDENTIFIER(issuers);
    OPTIONAL_IDENTIFIER(paymentworkflow);
    OPTIONAL_IDENTIFIER(bip47);
    OPTIONAL_SUBOBJECTS(purse, StorageNymAllowedStoragePurse);
    OPTIONAL_SUBOBJECT(txo, StorageNymAllowedStorageItemHash);

    return true;
}

bool CheckProto_10(const StorageNym& input, const bool silent)
{
    UNDEFINED_VERSION(10)
}

bool CheckProto_11(const StorageNym& input, const bool silent)
{
    UNDEFINED_VERSION(11)
}

bool CheckProto_12(const StorageNym& input, const bool silent)
{
    UNDEFINED_VERSION(12)
}

bool CheckProto_13(const StorageNym& input, const bool silent)
{
    UNDEFINED_VERSION(13)
}

bool CheckProto_14(const StorageNym& input, const bool silent)
{
    UNDEFINED_VERSION(14)
}

bool CheckProto_15(const StorageNym& input, const bool silent)
{
    UNDEFINED_VERSION(15)
}

bool CheckProto_16(const StorageNym& input, const bool silent)
{
    UNDEFINED_VERSION(16)
}

bool CheckProto_17(const StorageNym& input, const bool silent)
{
    UNDEFINED_VERSION(17)
}

bool CheckProto_18(const StorageNym& input, const bool silent)
{
    UNDEFINED_VERSION(18)
}

bool CheckProto_19(const StorageNym& input, const bool silent)
{
    UNDEFINED_VERSION(19)
}

bool CheckProto_20(const StorageNym& input, const bool silent)
{
    UNDEFINED_VERSION(20)
}
}  // namespace opentxs::proto
