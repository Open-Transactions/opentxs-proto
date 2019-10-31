// Copyright (c) 2019 The Open-Transactions developers
// This Source Code Form is subject to the terms of the Mozilla Public
// License, v. 2.0. If a copy of the MPL was not distributed with this
// file, You can obtain one at http://mozilla.org/MPL/2.0/.

#include "opentxs-proto/Types.hpp"
#include "verify/Check.hpp"

#define PROTO_NAME "storage nym"

namespace opentxs::proto
{
bool CheckProto_8(const StorageNym& input, const bool silent)
{
    OPTIONAL_SUBOBJECT(credlist, StorageNymAllowedStorageItemHash());
    OPTIONAL_SUBOBJECT(sentpeerrequests, StorageNymAllowedStorageItemHash());
    OPTIONAL_SUBOBJECT(
        incomingpeerrequests, StorageNymAllowedStorageItemHash());
    OPTIONAL_SUBOBJECT(sentpeerreply, StorageNymAllowedStorageItemHash());
    OPTIONAL_SUBOBJECT(incomingpeerreply, StorageNymAllowedStorageItemHash());
    OPTIONAL_SUBOBJECT(finishedpeerrequest, StorageNymAllowedStorageItemHash());
    OPTIONAL_SUBOBJECT(finishedpeerreply, StorageNymAllowedStorageItemHash());
    OPTIONAL_SUBOBJECT(
        processedpeerrequest, StorageNymAllowedStorageItemHash());
    OPTIONAL_SUBOBJECT(processedpeerreply, StorageNymAllowedStorageItemHash());
    OPTIONAL_SUBOBJECT(mailinbox, StorageNymAllowedStorageItemHash());
    OPTIONAL_SUBOBJECT(mailoutbox, StorageNymAllowedStorageItemHash());
    OPTIONAL_SUBOBJECT(threads, StorageNymAllowedStorageItemHash());
    OPTIONAL_SUBOBJECT(contexts, StorageNymAllowedStorageItemHash());
    OPTIONAL_SUBOBJECT(accounts, StorageNymAllowedStorageItemHash());
    CHECK_SUBOBJECTS(
        blockchainaccountindex, StorageNymAllowedBlockchainAccountList());
    CHECK_SUBOBJECTS(hdaccount, StorageNymAllowedHDAccount());
    OPTIONAL_IDENTIFIER(issuers);
    OPTIONAL_IDENTIFIER(paymentworkflow);
    OPTIONAL_IDENTIFIER(bip47);
    OPTIONAL_SUBOBJECTS(purse, StorageNymAllowedStoragePurse());
    CHECK_EXCLUDED(txo);

    return true;
}
}  // namespace opentxs::proto
