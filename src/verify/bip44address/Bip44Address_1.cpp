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

bool CheckProto_1(const Bip44Address& address, const bool silent)
{
    if (false == address.has_address()) {
        FAIL("address", "missing index")
    }

    if (address.has_address()) {
        if (MIN_PLAUSIBLE_SCRIPT > address.address().size()) {
            FAIL("address", "invalid address")
        }

        if (MAX_PLAUSIBLE_SCRIPT < address.address().size()) {
            FAIL("address", "invalid address")
        }
    }

    if (MAX_VALID_CONTACT_VALUE > address.label().size()) {
        FAIL("transaction", "invalid label")
    }

    if (address.has_contact()) {
        if (MIN_PLAUSIBLE_IDENTIFIER > address.contact().size()) {
            FAIL("address", "invalid contact")
        }

        if (MAX_PLAUSIBLE_IDENTIFIER < address.contact().size()) {
            FAIL("address", "invalid contact")
        }
    }

    for (const auto& txid : address.incoming()) {
        if (MIN_PLAUSIBLE_IDENTIFIER > txid.size()) {
            FAIL("address", "invalid txid")
        }

        if (MAX_PLAUSIBLE_IDENTIFIER < txid.size()) {
            FAIL("address", "invalid txid")
        }
    }

    return true;
}

bool CheckProto_2(const Bip44Address&, const bool) { return false; }
bool CheckProto_3(const Bip44Address&, const bool) { return false; }
bool CheckProto_4(const Bip44Address&, const bool) { return false; }
bool CheckProto_5(const Bip44Address&, const bool) { return false; }
}  // namespace proto
}  // namespace opentxs
