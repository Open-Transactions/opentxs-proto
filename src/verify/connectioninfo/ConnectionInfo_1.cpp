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

#include "opentxs-proto/verify/ConnectionInfo.hpp"

#include <iostream>

namespace opentxs { namespace proto
{
bool CheckProto_1(
    const ConnectionInfo& ConnectionInfo)
{
    if (!ConnectionInfo.has_type()) {
        std::cerr << "Verify ConnectionInfo failed: missing type."
                  << std::endl;

        return false;
    }

    if ((CONNECTIONINFO_BITCOIN > ConnectionInfo.type()) ||
        (CONNECTIONINFO_BITMESSAGERPC < ConnectionInfo.type())) {
        std::cerr << "Verify ConnectionInfo failed: invalid type ("
                << ConnectionInfo.type() << ")." << std::endl;

        return false;
    }

    return true;
}
bool CheckProto_2(const ConnectionInfo&) { return false; }
} // namespace proto
} // namespace opentxs
