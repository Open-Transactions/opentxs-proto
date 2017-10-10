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

bool CheckProto_3(const StorageItems& items, const bool silent)
{
    if (items.has_creds()) {
        if (MIN_PLAUSIBLE_IDENTIFIER > items.creds().size()) {
            FAIL2("storage item index", "invalid credentials", items.creds())
        }

        if (MAX_PLAUSIBLE_IDENTIFIER < items.creds().size()) {
            FAIL2("storage item index", "invalid credentials", items.creds())
        }
    }

    if (items.has_nyms()) {
        if (MIN_PLAUSIBLE_IDENTIFIER > items.nyms().size()) {
            FAIL2("storage item index", "invalid nym list", items.nyms())
        }

        if (MAX_PLAUSIBLE_IDENTIFIER < items.nyms().size()) {
            FAIL2("storage item index", "invalid nym list", items.nyms())
        }
    }

    if (items.has_servers()) {
        if (MIN_PLAUSIBLE_IDENTIFIER > items.servers().size()) {
            FAIL2("storage item index", "invalid server list", items.servers())
        }

        if (MAX_PLAUSIBLE_IDENTIFIER < items.servers().size()) {
            FAIL2("storage item index", "invalid server list", items.servers())
        }
    }

    if (items.has_units()) {
        if (MIN_PLAUSIBLE_IDENTIFIER > items.units().size()) {
            FAIL2("storage item index", "invalid unit list", items.units())
        }

        if (MAX_PLAUSIBLE_IDENTIFIER < items.units().size()) {
            FAIL2("storage item index", "invalid unit list", items.units())
        }
    }

    if (items.has_seeds()) {
        if (MIN_PLAUSIBLE_IDENTIFIER > items.seeds().size()) {
            FAIL2("storage item index", "invalid seed list", items.seeds())
        }

        if (MAX_PLAUSIBLE_IDENTIFIER < items.seeds().size()) {
            FAIL2("storage item index", "invalid seed list", items.seeds())
        }
    }

    if (items.has_contacts()) {
        if (MIN_PLAUSIBLE_IDENTIFIER > items.contacts().size()) {
            FAIL2(
                "storage item index", "invalid contact list", items.contacts())
        }

        if (MAX_PLAUSIBLE_IDENTIFIER < items.contacts().size()) {
            FAIL2(
                "storage item index", "invalid contact list", items.contacts())
        }
    }

    if (items.has_blockchaintransactions()) {
        if (MIN_PLAUSIBLE_IDENTIFIER > items.blockchaintransactions().size()) {
            FAIL2(
                "storage item index",
                "invalid blockchain transaction list",
                items.blockchaintransactions())
        }

        if (MAX_PLAUSIBLE_IDENTIFIER < items.blockchaintransactions().size()) {
            FAIL2(
                "storage item index",
                "invalid blockchain transaction list",
                items.blockchaintransactions())
        }
    }

    return true;
}

bool CheckProto_4(const StorageItems&, const bool silent)
{
    UNDEFINED_VERSION("storage item index", 4)
}

bool CheckProto_5(const StorageItems&, const bool silent)
{
    UNDEFINED_VERSION("storage item index", 5)
}
}  // namespace proto
}  // namespace opentxs
