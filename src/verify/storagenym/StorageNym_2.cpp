// Copyright (c) 2018 The Open-Transactions developers
// This Source Code Form is subject to the terms of the Mozilla Public
// License, v. 2.0. If a copy of the MPL was not distributed with this
// file, You can obtain one at http://mozilla.org/MPL/2.0/.

#include "opentxs-proto/Types.hpp"
#include "opentxs-proto/Check.hpp"

#define PROTO_NAME "storage nym"

namespace opentxs::proto
{
bool CheckProto_2(const StorageNym& input, const bool silent)
{
    OPTIONAL_SUBOBJECT(credlist, StorageNymAllowedHash)
    OPTIONAL_SUBOBJECT(sentpeerrequests, StorageNymAllowedHash)
    OPTIONAL_SUBOBJECT(incomingpeerrequests, StorageNymAllowedHash)
    OPTIONAL_SUBOBJECT(sentpeerreply, StorageNymAllowedHash)
    OPTIONAL_SUBOBJECT(incomingpeerreply, StorageNymAllowedHash)
    OPTIONAL_SUBOBJECT(finishedpeerrequest, StorageNymAllowedHash)
    OPTIONAL_SUBOBJECT(finishedpeerreply, StorageNymAllowedHash)
    OPTIONAL_SUBOBJECT(processedpeerrequest, StorageNymAllowedHash)
    OPTIONAL_SUBOBJECT(processedpeerreply, StorageNymAllowedHash)
    OPTIONAL_SUBOBJECT(mailinbox, StorageNymAllowedHash)
    OPTIONAL_SUBOBJECT(mailoutbox, StorageNymAllowedHash)
    OPTIONAL_SUBOBJECT(threads, StorageNymAllowedHash)
    CHECK_EXCLUDED(contexts)
    CHECK_EXCLUDED(accounts)
    CHECK_NONE(blockchainaccountindex)
    CHECK_NONE(blockchainaccount)
    CHECK_EXCLUDED(issuers)
    CHECK_EXCLUDED(paymentworkflow)
    CHECK_EXCLUDED(bip47)

    return true;
}
}  // namespace opentxs::proto
