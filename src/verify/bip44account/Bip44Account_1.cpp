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
 *  fellowtraveler@openaccounts.org
 *
 *  WEBSITE:
 *  http://www.openaccounts.org/
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

#define CONTACT_VERSION 3

namespace opentxs
{
namespace proto
{

bool CheckProto_1(const Bip44Account& account, const bool silent)
{
    if (false == account.has_id()) {
        FAIL("account", "missing id")
    }

    if (MIN_PLAUSIBLE_IDENTIFIER > account.id().size()) {
        FAIL("account", "invalid id")
    }

    if (MAX_PLAUSIBLE_IDENTIFIER < account.id().size()) {
        FAIL("account", "invalid id")
    }

    const bool validChain = ValidContactItemType(
        {CONTACT_VERSION, CONTACTSECTION_CONTRACT}, account.type());

    if (false == validChain) {
        FAIL("account", "invalid type")
    }

    if (false == account.has_path()) {
        FAIL("account", "missing path")
    }

    const bool validPath = Check(
        account.path(),
        Bip44AccountAllowedHDPath.at(account.version()).first,
        Bip44AccountAllowedHDPath.at(account.version()).second,
        silent);

    if (false == validPath) {
        FAIL("account", "invalid path")
    }

    for (const auto& address : account.internaladdress()) {
        const bool validAddress = Check(
            address,
            Bip44AccountAllowedBip44Address.at(account.version()).first,
            Bip44AccountAllowedBip44Address.at(account.version()).second,
            silent);

        if (false == validAddress) {
            FAIL("account", "invalid address")
        }
    }

    for (const auto& txid : account.outgoing()) {
        if (MIN_PLAUSIBLE_IDENTIFIER > txid.size()) {
            FAIL("account", "invalid txid")
        }

        if (MAX_PLAUSIBLE_IDENTIFIER < txid.size()) {
            FAIL("account", "invalid txid")
        }
    }

    return true;
}

bool CheckProto_2(const Bip44Account&, const bool) { return false; }
bool CheckProto_3(const Bip44Account&, const bool) { return false; }
bool CheckProto_4(const Bip44Account&, const bool) { return false; }
bool CheckProto_5(const Bip44Account&, const bool) { return false; }
}  // namespace proto
}  // namespace opentxs
