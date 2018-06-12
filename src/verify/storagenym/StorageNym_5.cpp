/************************************************************
 *
 *                 OPEN TRANSACTIONS
 *
 *       Financial Cryptography and Digital Cash
 *       Library, Protocol, API, Server, CLI, GUI
 *
 *       -- Anonymous Numbered Accounts.
 *       -- Untraceable Digital Cash.
 *       -- Triple-Signed Receipts.
 *       -- Cheques, Vouchers, Transfers, Inboxes.
 *       -- Basket Currencies, Markets, Payment Plans.
 *       -- Signed, XML, Ricardian-style Contracts.
 *       -- Scripted smart contracts.
 *
 *  EMAIL:
 *  fellowtraveler@opentransactions.org
 *
 *  WEBSITE:
 *  http://www.opentransactions.org/
 *
 *  -----------------------------------------------------
 *
 *   LICENSE:
 *   This Source Code Form is subject to the terms of the
 *   Mozilla Public License, v. 2.0. If a copy of the MPL
 *   was not distributed with this file, You can obtain one
 *   at http://mozilla.org/MPL/2.0/.
 *
 *   DISCLAIMER:
 *   This program is distributed in the hope that it will
 *   be useful, but WITHOUT ANY WARRANTY; without even the
 *   implied warranty of MERCHANTABILITY or FITNESS FOR A
 *   PARTICULAR PURPOSE.  See the Mozilla Public License
 *   for more details.
 *
 ************************************************************/

#include "opentxs-proto/Types.hpp"
#include "opentxs-proto/Check.hpp"

#define PROTO_NAME "storage nym"

namespace opentxs::proto
{
bool CheckProto_5(const StorageNym& input, const bool silent)
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
    CHECK_EXCLUDED(paymentworkflow)
    CHECK_NONE(bip47channelindex)
    CHECK_NONE(bip47context)
    return true;
}
}  // namespace opentxs::proto
