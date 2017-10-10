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

namespace opentxs
{
namespace proto
{

bool CheckProto_1(const Bip44Account& account, const bool silent)
{
    if (false == account.has_id()) {
        FAIL("blockchain account", "missing id")
    }

    if (MIN_PLAUSIBLE_IDENTIFIER > account.id().size()) {
        FAIL("blockchain account", "invalid id")
    }

    if (MAX_PLAUSIBLE_IDENTIFIER < account.id().size()) {
        FAIL("blockchain account", "invalid id")
    }

    const bool validChain = ValidContactItemType(
        {CONTACT_VERSION, CONTACTSECTION_CONTRACT}, account.type());

    if (false == validChain) {
        FAIL("blockchain account", "invalid type")
    }

    if (false == account.has_path()) {
        FAIL("blockchain account", "missing path")
    }

    try {
        const bool validPath = Check(
            account.path(),
            Bip44AccountAllowedHDPath.at(account.version()).first,
            Bip44AccountAllowedHDPath.at(account.version()).second,
            silent);

        if (false == validPath) {
            FAIL("blockchain account", "invalid path")
        }
    } catch (const std::out_of_range&) {
        FAIL2(
            "blockchain account",
            "allowed HD path version not defined for version",
            account.version())
    }

    for (const auto& address : account.internaladdress()) {
        try {
            const bool validAddress = Check(
                address,
                Bip44AccountAllowedBip44Address.at(account.version()).first,
                Bip44AccountAllowedBip44Address.at(account.version()).second,
                silent);

            if (false == validAddress) {
                FAIL("blockchain account", "invalid address")
            }
        } catch (const std::out_of_range&) {
            FAIL2(
                "blockchain account",
                "allowed Bip44 address version not defined for version",
                account.version())
        }
    }

    for (const auto& txid : account.outgoing()) {
        if (MIN_PLAUSIBLE_IDENTIFIER > txid.size()) {
            FAIL("blockchain account", "invalid txid")
        }

        if (MAX_PLAUSIBLE_IDENTIFIER < txid.size()) {
            FAIL("blockchain account", "invalid txid")
        }
    }

    return true;
}

bool CheckProto_2(const Bip44Account&, const bool silent)
{
    UNDEFINED_VERSION("blockchain account", 2)
}

bool CheckProto_3(const Bip44Account&, const bool silent)
{
    UNDEFINED_VERSION("blockchain account", 3)
}

bool CheckProto_4(const Bip44Account&, const bool silent)
{
    UNDEFINED_VERSION("blockchain account", 4)
}

bool CheckProto_5(const Bip44Account&, const bool silent)
{
    UNDEFINED_VERSION("blockchain account", 5)
}
}  // namespace proto
}  // namespace opentxs
