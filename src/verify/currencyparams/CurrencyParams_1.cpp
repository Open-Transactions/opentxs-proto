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

#include "opentxs-proto/verify/CurrencyParams.hpp"

#include <iostream>

 namespace opentxs { namespace proto
{

bool CheckProto_1(
    const CurrencyParams& params)
{
    if (!params.has_tla()) {
        std::cerr << __FUNCTION__
                  << ": Verify currency params failed: missing TLA."
                  << std::endl;

        return false;
    }

    if (3 != params.tla().size()) {
        std::cerr << __FUNCTION__
                  << ": Verify currency params failed: invalid TLA ("
                  << params.tla() << ")." << std::endl;

        return false;
    }

    if (!params.has_fraction()) {
        std::cerr << __FUNCTION__
                  << ": Verify currency params failed: missing fraction."
                  << std::endl;

        return false;
    }

    if (1 > params.fraction().size()) {
        std::cerr << __FUNCTION__
                  << ": Verify currency params failed: invalid fraction ("
                  << params.fraction() << ")." << std::endl;

        return false;
    }

    if (!params.has_power()) {
        std::cerr << __FUNCTION__
                  << ": Verify currency params failed: missing power."
                  << std::endl;

        return false;
    }

    return true;
}
bool CheckProto_2(const CurrencyParams&) { return false; }
} // namespace proto
} // namespace opentxs
