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

#include "opentxs-proto/Types.hpp"

#include <iostream>

namespace opentxs { namespace proto
{

bool CheckProto_1(
    const ListenAddress& address)
{
    if (!address.has_type()) {
        std::cerr << "Verify serialized listen address failed: missing type" << std::endl;
        return false;
    }

    if ((ADDRESSTYPE_ERROR == address.type()) || (ADDRESSTYPE_EEP < address.type())) {
        std::cerr << "Verify serialized listen address failed: invalid type" << std::endl;
        return false;
    }

    if (!address.has_protocol()) {
        std::cerr << "Verify serialized listen address failed: missing protocol" << std::endl;
        return false;
    }

    if ((PROTOCOLVERSION_ERROR == address.protocol()) || (PROTOCOLVERSION_NOTIFY < address.protocol())) {
        std::cerr << "Verify serialized listen address failed: invalid protocol" << std::endl;
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

    if (65535 < address.port()) {
        std::cerr << "Verify serialized listen address failed: invalid port" << std::endl;
        return false;
    }

    return true;
}
bool CheckProto_2(const ListenAddress&) { return false; }
bool CheckProto_3(const ListenAddress&) { return false; }
bool CheckProto_4(const ListenAddress&) { return false; }
bool CheckProto_5(const ListenAddress&) { return false; }
} // namespace proto
} // namespace opentxs
