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

bool CheckProto_1(const ChildCredentialParameters& input, const bool silent)
{
    if (!input.has_masterid()) {
        FAIL("child parameters", "missing master identifier")
    }

    if (MIN_PLAUSIBLE_IDENTIFIER > input.masterid().size()) {
        FAIL2("child parameters", "invalid master identifier", input.masterid())
    }

    return true;
}

bool CheckProto_2(const ChildCredentialParameters& input, const bool silent)
{
    UNDEFINED_VERSION("child parameters", 2)
}

bool CheckProto_3(const ChildCredentialParameters& input, const bool silent)
{
    UNDEFINED_VERSION("child parameters", 3)
}

bool CheckProto_4(const ChildCredentialParameters& input, const bool silent)
{
    UNDEFINED_VERSION("child parameters", 4)
}

bool CheckProto_5(const ChildCredentialParameters& input, const bool silent)
{
    UNDEFINED_VERSION("child parameters", 5)
}
}  // namespace proto
}  // namespace opentxs
