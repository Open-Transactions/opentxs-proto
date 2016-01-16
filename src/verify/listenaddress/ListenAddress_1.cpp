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
 *       -- Scripted smart addresss.
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

#include "opentxs-proto/verify/ListenAddress.hpp"

#include <iostream>

namespace opentxs { namespace proto
{

bool ListenAddress_1(
    const ListenAddress& address)
{
    if (!address.has_type()) {
        std::cerr << "Verify serialized listen address failed: missing type" << std::endl;
        return false;
    }

    if ((ADDRESSTYPE_ERROR == address.type()) || (ADDRESSTYPE_IPV4 < address.type())) {
        std::cerr << "Verify serialized listen address failed: invalid type" << std::endl;
        return false;
    }

    if (!address.has_host()) {
        std::cerr << "Verify serialized listen address failed: missing host" << std::endl;
        return false;
    }

    if (!address.has_port()) {
        std::cerr << "Verify serialized listen address failed: missing port" << std::endl;
        return false;
    }

    return true;
}

} // namespace proto
} // namespace opentxs
