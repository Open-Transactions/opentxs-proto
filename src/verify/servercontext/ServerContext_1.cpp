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

#include <iostream>

namespace opentxs { namespace proto
{
bool CheckProto_1(const ServerContext& context)
{
    if (!context.has_serverid()) {
        std::cerr << "Verify server context failed: missing server id."
                  << std::endl;

        return false;
    }

    if ((MIN_PLAUSIBLE_IDENTIFIER > context.serverid().size()) ||
        (MAX_PLAUSIBLE_IDENTIFIER < context.serverid().size())) {
            std::cerr << "Verify server context failed: invalid server id."
                    << std::endl;

            return false;
    }

    return true;
}

bool CheckProto_2(const ServerContext&) { return false; }
bool CheckProto_3(const ServerContext&) { return false; }
bool CheckProto_4(const ServerContext&) { return false; }
bool CheckProto_5(const ServerContext&) { return false; }
} // namespace proto
} // namespace opentxs
