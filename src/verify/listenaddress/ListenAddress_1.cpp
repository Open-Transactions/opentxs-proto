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
#include "opentxs-proto/Check.hpp"

#include <iostream>

namespace opentxs
{
namespace proto
{

bool CheckProto_1(const ListenAddress& address, const bool silent)
{
    if (!address.has_type()) {
        FAIL("listen address", "missing type")
    }

    if ((ADDRESSTYPE_ERROR == address.type()) ||
        (ADDRESSTYPE_EEP < address.type())) {
        FAIL("listen address", "invalid type")
    }

    if (!address.has_protocol()) {
        FAIL("listen address", "missing protocol")
    }

    if ((PROTOCOLVERSION_ERROR == address.protocol()) ||
        (PROTOCOLVERSION_NOTIFY < address.protocol())) {
        FAIL("listen address", "invalid protocol")
    }

    if (!address.has_host()) {
        FAIL("listen address", "missing host")
    }

    if (!address.has_port()) {
        FAIL("listen address", "missing port")
    }

    if (MAX_VALID_PORT < address.port()) {
        FAIL("listen address", "invalid port")
    }

    return true;
}

bool CheckProto_2(const ListenAddress&, const bool silent)
{
    UNDEFINED_VERSION("listen address", 2)
}

bool CheckProto_3(const ListenAddress&, const bool silent)
{
    UNDEFINED_VERSION("listen address", 3)
}

bool CheckProto_4(const ListenAddress&, const bool silent)
{
    UNDEFINED_VERSION("listen address", 4)
}

bool CheckProto_5(const ListenAddress&, const bool silent)
{
    UNDEFINED_VERSION("listen address", 5)
}
}  // namespace proto
}  // namespace opentxs
