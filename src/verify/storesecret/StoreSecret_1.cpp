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
bool CheckProto_1(const StoreSecret& request)
{
    if (!request.has_type()) {
        std::cerr << "Verify StoreSecret failed: missing type."
                  << std::endl;

        return false;
    }

    if ((SECRETTYPE_BIP39 > request.type()) ||
        (SECRETTYPE_BIP39 < request.type()))
    {
        std::cerr << "Verify StoreSecret failed: invalid type ("
                  << request.type() << ")." << std::endl;

        return false;
    }

    return true;
}

bool CheckProto_2(const StoreSecret& request) { return CheckProto_1(request); }

bool CheckProto_3(const StoreSecret& request) { return CheckProto_1(request); }

bool CheckProto_4(const StoreSecret&) { return false; }
bool CheckProto_5(const StoreSecret&) { return false; }
} // namespace proto
} // namespace opentxs
