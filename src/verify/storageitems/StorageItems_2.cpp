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

bool CheckProto_2(const StorageItems& input, const bool silent)
{
    if (input.has_creds()) {
        if (MIN_PLAUSIBLE_IDENTIFIER > input.creds().size()) {
            FAIL2("storage item index", "invalid credentials", input.creds())
        }

        if (MAX_PLAUSIBLE_IDENTIFIER < input.creds().size()) {
            FAIL2("storage item index", "invalid credentials", input.creds())
        }
    }

    if (input.has_nyms()) {
        if (MIN_PLAUSIBLE_IDENTIFIER > input.nyms().size()) {
            FAIL2("storage item index", "invalid nym list", input.nyms())
        }

        if (MAX_PLAUSIBLE_IDENTIFIER < input.nyms().size()) {
            FAIL2("storage item index", "invalid nym list", input.nyms())
        }
    }

    if (input.has_servers()) {
        if (MIN_PLAUSIBLE_IDENTIFIER > input.servers().size()) {
            FAIL2("storage item index", "invalid server list", input.servers())
        }

        if (MAX_PLAUSIBLE_IDENTIFIER < input.servers().size()) {
            FAIL2("storage item index", "invalid server list", input.servers())
        }
    }

    if (input.has_units()) {
        if (MIN_PLAUSIBLE_IDENTIFIER > input.units().size()) {
            FAIL2("storage item index", "invalid unit list", input.units())
        }

        if (MAX_PLAUSIBLE_IDENTIFIER < input.units().size()) {
            FAIL2("storage item index", "invalid unit list", input.units())
        }
    }

    if (input.has_seeds()) {
        if (MIN_PLAUSIBLE_IDENTIFIER > input.seeds().size()) {
            FAIL2("storage item index", "invalid seed list", input.seeds())
        }

        if (MAX_PLAUSIBLE_IDENTIFIER < input.seeds().size()) {
            FAIL2("storage item index", "invalid seed list", input.seeds())
        }
    }

    if (input.has_contacts()) {
        if (MIN_PLAUSIBLE_IDENTIFIER > input.contacts().size()) {
            FAIL2(
                "storage item index", "invalid contact list", input.contacts())
        }

        if (MAX_PLAUSIBLE_IDENTIFIER < input.contacts().size()) {
            FAIL2(
                "storage item index", "invalid contact list", input.contacts())
        }
    }

    if (input.has_blockchaintransactions()) {
        FAIL(
            "storage item index",
            "unexpected blockchaintransactions field found")
    }

    return true;
}
}  // namespace proto
}  // namespace opentxs
