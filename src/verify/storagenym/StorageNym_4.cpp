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

namespace opentxs
{
namespace proto
{

bool CheckProto_4(const StorageNym& nym, const bool silent)
{
    if (nym.has_credlist()) {
        bool valid = Check(
            nym.credlist(),
            StorageNymAllowedHash.at(nym.version()).first,
            StorageNymAllowedHash.at(nym.version()).second,
            silent);

        if (!valid) {
            FAIL("storage nym", "invalid credential list")
        }
    }

    if (nym.has_sentpeerrequests()) {
        bool valid = Check(
            nym.sentpeerrequests(),
            StorageNymAllowedHash.at(nym.version()).first,
            StorageNymAllowedHash.at(nym.version()).second,
            silent);

        if (!valid) {
            FAIL("storage nym", "invalid sentpeerrequests")
        }
    }

    if (nym.has_incomingpeerrequests()) {
        bool valid = Check(
            nym.incomingpeerrequests(),
            StorageNymAllowedHash.at(nym.version()).first,
            StorageNymAllowedHash.at(nym.version()).second,
            silent);

        if (!valid) {
            FAIL("storage nym", "invalid incomingpeerrequests")
        }
    }

    if (nym.has_sentpeerreply()) {
        bool valid = Check(
            nym.sentpeerreply(),
            StorageNymAllowedHash.at(nym.version()).first,
            StorageNymAllowedHash.at(nym.version()).second,
            silent);

        if (!valid) {
            FAIL("storage nym", "invalid sentpeerreply")
        }
    }

    if (nym.has_incomingpeerreply()) {
        bool valid = Check(
            nym.incomingpeerreply(),
            StorageNymAllowedHash.at(nym.version()).first,
            StorageNymAllowedHash.at(nym.version()).second,
            silent);

        if (!valid) {
            FAIL("storage nym", "invalid incomingpeerreply")
        }
    }

    if (nym.has_finishedpeerrequest()) {
        bool valid = Check(
            nym.finishedpeerrequest(),
            StorageNymAllowedHash.at(nym.version()).first,
            StorageNymAllowedHash.at(nym.version()).second,
            silent);

        if (!valid) {
            FAIL("storage nym", "invalid finishedpeerrequest")
        }
    }

    if (nym.has_finishedpeerreply()) {
        bool valid = Check(
            nym.finishedpeerreply(),
            StorageNymAllowedHash.at(nym.version()).first,
            StorageNymAllowedHash.at(nym.version()).second,
            silent);

        if (!valid) {
            FAIL("storage nym", "invalid finishedpeerreply")
        }
    }

    if (nym.has_processedpeerrequest()) {
        bool valid = Check(
            nym.processedpeerrequest(),
            StorageNymAllowedHash.at(nym.version()).first,
            StorageNymAllowedHash.at(nym.version()).second,
            silent);

        if (!valid) {
            FAIL("storage nym", "invalid processedpeerrequest")
        }
    }

    if (nym.has_processedpeerreply()) {
        bool valid = Check(
            nym.processedpeerreply(),
            StorageNymAllowedHash.at(nym.version()).first,
            StorageNymAllowedHash.at(nym.version()).second,
            silent);

        if (!valid) {
            FAIL("storage nym", "invalid processedpeerreply")
        }
    }

    if (nym.has_mailinbox()) {
        bool valid = Check(
            nym.mailinbox(),
            StorageNymAllowedHash.at(nym.version()).first,
            StorageNymAllowedHash.at(nym.version()).second,
            silent);

        if (!valid) {
            FAIL("storage nym", "invalid mailinbox")
        }
    }

    if (nym.has_mailoutbox()) {
        bool valid = Check(
            nym.mailoutbox(),
            StorageNymAllowedHash.at(nym.version()).first,
            StorageNymAllowedHash.at(nym.version()).second,
            silent);

        if (!valid) {
            FAIL("storage nym", "invalid mailoutbox")
        }
    }

    if (nym.has_threads()) {
        bool valid = Check(
            nym.threads(),
            StorageNymAllowedHash.at(nym.version()).first,
            StorageNymAllowedHash.at(nym.version()).second,
            silent);

        if (!valid) {
            FAIL("storage nym", "invalid threads")
        }
    }

    if (nym.has_contexts()) {
        bool valid = Check(
            nym.contexts(),
            StorageNymAllowedHash.at(nym.version()).first,
            StorageNymAllowedHash.at(nym.version()).second,
            silent);

        if (!valid) {
            FAIL("storage nym", "invalid contexts")
        }
    }

    if (nym.has_accounts()) {
        bool valid = Check(
            nym.accounts(),
            StorageNymAllowedHash.at(nym.version()).first,
            StorageNymAllowedHash.at(nym.version()).second,
            silent);

        if (!valid) {
            FAIL("storage nym", "invalid accounts")
        }
    }

    for (const auto& index : nym.blockchainaccountindex()) {
        bool valid = Check(
            index,
            StorageNymAllowedBlockchainAccountList.at(nym.version()).first,
            StorageNymAllowedBlockchainAccountList.at(nym.version()).second,
            silent);

        if (!valid) {
            FAIL("storage nym", "invalid blockchain account index")
        }
    }

    for (const auto& bip44 : nym.blockchainaccount()) {
        bool valid = Check(
            bip44,
            StorageNymAllowedBip44Account.at(nym.version()).first,
            StorageNymAllowedBip44Account.at(nym.version()).second,
            silent);

        if (!valid) {
            FAIL("storage nym", "invalid blockchain account")
        }
    }

    return true;
}

bool CheckProto_5(const StorageNym&, const bool) { return false; }
}  // namespace proto
}  // namespace opentxs
