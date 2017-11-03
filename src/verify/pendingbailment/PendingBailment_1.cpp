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

bool CheckProto_1(const PendingBailment& input, const bool silent)
{
    if (!input.has_unitid()) {
        FAIL("pending bailment", "missing unit id")
    }

    if (MIN_PLAUSIBLE_IDENTIFIER > input.unitid().size()) {
        FAIL2("pending bailment", "invalid unit id", input.unitid())
    }

    if (MAX_PLAUSIBLE_IDENTIFIER < input.unitid().size()) {
        FAIL2("pending bailment", "invalid unit id", input.unitid())
    }

    if (!input.has_serverid()) {
        FAIL("pending bailment", "missing server id")
    }

    if (MIN_PLAUSIBLE_IDENTIFIER > input.serverid().size()) {
        FAIL2("pending bailment", "invalid server id", input.serverid())
    }

    if (MAX_PLAUSIBLE_IDENTIFIER < input.serverid().size()) {
        FAIL2("pending bailment", "invalid server id", input.serverid())
    }

    if (!input.has_txid()) {
        FAIL("pending bailment", "missing txid")
    }

    if (MIN_PLAUSIBLE_IDENTIFIER > input.txid().size()) {
        FAIL2("pending bailment", "invalid txid", input.txid())
    }

    if (MAX_PLAUSIBLE_IDENTIFIER < input.txid().size()) {
        FAIL2("pending bailment", "invalid txid", input.txid())
    }

    return true;
}

bool CheckProto_2(const PendingBailment& input, const bool silent)
{
    return CheckProto_1(input, silent);
}

bool CheckProto_3(const PendingBailment& input, const bool silent)
{
    return CheckProto_1(input, silent);
}

bool CheckProto_4(const PendingBailment& input, const bool silent)
{
    return CheckProto_1(input, silent);
}

bool CheckProto_5(const PendingBailment& input, const bool silent)
{
    UNDEFINED_VERSION("pending bailment", 5)
}
}  // namespace proto
}  // namespace opentxs
