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

bool CheckProto_1(
    const SourceProof& proot,
    const bool silent,
    bool& ExpectSourceSignature)
{
    if (!proot.has_type()) {
        FAIL("source proof", "missing type")
    }

    switch (proot.type()) {
        case SOURCEPROOFTYPE_SELF_SIGNATURE:
            ExpectSourceSignature = false;

            break;
        case SOURCEPROOFTYPE_SIGNATURE:
            ExpectSourceSignature = true;

            break;
        default:
            FAIL2("source proof", "incorrect or unknown type", proot.type())
    }

    return true;
}
bool CheckProto_2(const SourceProof&, const bool, bool&) { return false; }
bool CheckProto_3(const SourceProof&, const bool, bool&) { return false; }
bool CheckProto_4(const SourceProof&, const bool, bool&) { return false; }
bool CheckProto_5(const SourceProof&, const bool, bool&) { return false; }
}  // namespace proto
}  // namespace opentxs
