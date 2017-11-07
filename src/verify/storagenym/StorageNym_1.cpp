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

#include <iostream>

#define PROTO_NAME "storage nym"

namespace opentxs
{
namespace proto
{

bool CheckProto_1(const StorageNym& input, const bool silent)
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
    CHECK_EXCLUDED(mailinbox)
    CHECK_EXCLUDED(mailoutbox)
    CHECK_EXCLUDED(threads)
    CHECK_EXCLUDED(contexts)
    CHECK_EXCLUDED(accounts)
    CHECK_NONE(blockchainaccountindex)
    CHECK_NONE(blockchainaccount)
    CHECK_EXCLUDED(issuers)

    return true;
}
}  // namespace proto
}  // namespace opentxs
