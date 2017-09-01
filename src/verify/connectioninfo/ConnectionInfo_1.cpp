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
bool CheckProto_1(const ConnectionInfo& request, const bool silent)
{
    if (!request.has_type()) {
        FAIL("ConnectionInfo", "missing type")
    }

    if ((CONNECTIONINFO_BITCOIN > request.type()) ||
        (CONNECTIONINFO_BITMESSAGERPC < request.type())) {
        FAIL2("ConnectionInfo", "invalid type", request.type())
    }

    if (request.has_nym()) {
        FAIL("ConnectionInfo", "unexpected 'for' field present")
    }

    return true;
}

bool CheckProto_2(const ConnectionInfo& request, const bool silent)
{
    return CheckProto_1(request, silent);
}

bool CheckProto_3(const ConnectionInfo& request, const bool silent)
{
    if (!request.has_type()) {
        FAIL("ConnectionInfo", "missing type")
    }

    if ((CONNECTIONINFO_BITCOIN > request.type()) ||
        (CONNECTIONINFO_CJDNS < request.type())) {
        FAIL2("ConnectionInfo", "invalid type", request.type())
    }

    return true;
}

bool CheckProto_4(const ConnectionInfo& request, const bool silent)
{
    return CheckProto_3(request, silent);
}

bool CheckProto_5(const ConnectionInfo&, const bool) { return false; }
}  // namespace proto
}  // namespace opentxs
