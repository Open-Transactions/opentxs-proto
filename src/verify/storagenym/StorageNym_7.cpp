// Copyright (c) 2018 The Open-Transactions developers
// This Source Code Form is subject to the terms of the Mozilla Public
// License, v. 2.0. If a copy of the MPL was not distributed with this
// file, You can obtain one at http://mozilla.org/MPL/2.0/.

#include "opentxs-proto/Types.hpp"
#include "opentxs-proto/Check.hpp"

#define PROTO_NAME "storage nym"

namespace opentxs::proto
{
bool CheckProto_7(const StorageNym& input, const bool silent)
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
    OPTIONAL_SUBOBJECT(contexts, StorageNymAllowedHash)
    OPTIONAL_SUBOBJECT(accounts, StorageNymAllowedHash)
    CHECK_SUBOBJECTS(
        blockchainaccountindex, StorageNymAllowedBlockchainAccountList)
    CHECK_SUBOBJECTS(blockchainaccount, StorageNymAllowedBip44Account)
    OPTIONAL_IDENTIFIER(issuers)
    OPTIONAL_IDENTIFIER(paymentworkflow)
    OPTIONAL_IDENTIFIER(bip47)

    return true;
}

bool CheckProto_8(const StorageNym& input, const bool silent)
{
    UNDEFINED_VERSION(8)
}

bool CheckProto_9(const StorageNym& input, const bool silent)
{
    UNDEFINED_VERSION(9)
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
