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
 *       -- Scripted smart paramss.
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

bool CheckProto_1(const CurrencyParams& params, const bool silent)
{
    if (!params.has_tla()) {
        FAIL("currency params", "missing TLA")
    }

    if (3 != params.tla().size()) {
        FAIL2("currency params", "invalid TLA", params.tla())
    }

    if (!params.has_fraction()) {
        FAIL("currency params", "missing fraction")
    }

    if (1 > params.fraction().size()) {
        FAIL2("currency params", "invalid fraction", params.fraction())
    }

    if (!params.has_power()) {
        FAIL("currency params", "missing power")
    }

    return true;
}
bool CheckProto_2(const CurrencyParams&, const bool silent)
{
    UNDEFINED_VERSION("currency params", 2)
}

bool CheckProto_3(const CurrencyParams&, const bool silent)
{
    UNDEFINED_VERSION("currency params", 3)
}

bool CheckProto_4(const CurrencyParams&, const bool silent)
{
    UNDEFINED_VERSION("currency params", 4)
}

bool CheckProto_5(const CurrencyParams&, const bool silent)
{
    UNDEFINED_VERSION("currency params", 5)
}

}  // namespace proto
}  // namespace opentxs
