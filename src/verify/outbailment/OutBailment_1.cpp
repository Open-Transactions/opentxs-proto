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

bool CheckProto_1(const OutBailment& request, const bool silent)
{
    if (!request.has_unitid()) {
        FAIL("outbailment", "missing unit id")
    }

    if (MIN_PLAUSIBLE_IDENTIFIER > request.unitid().size()) {
        FAIL2("outbailment", "invalid unit id", request.unitid())
    }

    if (MAX_PLAUSIBLE_IDENTIFIER < request.unitid().size()) {
        FAIL2("outbailment", "invalid unit id", request.unitid())
    }

    if (!request.has_serverid()) {
        FAIL("outbailment", "missing server id")
    }

    if (MIN_PLAUSIBLE_IDENTIFIER > request.serverid().size()) {
        FAIL2("outbailment", "invalid server id", request.serverid())
    }

    if (MAX_PLAUSIBLE_IDENTIFIER < request.serverid().size()) {
        FAIL2("outbailment", "invalid server id", request.serverid())
    }

    if (!request.has_amount()) {
        FAIL("outbailment", "missing amount")
    }

    if (!request.has_instructions()) {
        FAIL("outbailment", "missing instructions")
    }

    return true;
}

bool CheckProto_2(const OutBailment& request, const bool silent)
{

    return CheckProto_1(request, silent);
}

bool CheckProto_3(const OutBailment& request, const bool silent)
{

    return CheckProto_1(request, silent);
}

bool CheckProto_4(const OutBailment& request, const bool silent)
{

    return CheckProto_1(request, silent);
}

bool CheckProto_5(const OutBailment&, const bool silent)
{
    UNDEFINED_VERSION("outbailment", 5)
}
}  // namespace proto
}  // namespace opentxs
