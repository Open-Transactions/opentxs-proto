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
    const VerificationSet& verificationSet,
    const bool silent,
    const VerificationType indexed)
{
    if (verificationSet.has_internal()) {
        bool validInternal = Check(
            verificationSet.internal(),
            VerificationSetAllowedGroup.at(verificationSet.version()).first,
            VerificationSetAllowedGroup.at(verificationSet.version()).second,
            silent,
            indexed);

        if (!validInternal) {
            FAIL("verification set", "invalid internal group")
        }
    }
    if (verificationSet.has_external()) {
        bool validExternal = Check(
            verificationSet.external(),
            VerificationSetAllowedGroup.at(verificationSet.version()).first,
            VerificationSetAllowedGroup.at(verificationSet.version()).second,
            silent,
            indexed);

        if (!validExternal) {
            FAIL("verification set", "invalid external group")
        }
    }

    for (auto& it : verificationSet.repudiated()) {
        if (MIN_PLAUSIBLE_IDENTIFIER < it.size()) {
            FAIL("verification set", "invalid repudiation")
        }
    }

    return true;
}
bool CheckProto_2(const VerificationSet&, const bool, const VerificationType)
{
    return false;
}
bool CheckProto_3(const VerificationSet&, const bool, const VerificationType)
{
    return false;
}
bool CheckProto_4(const VerificationSet&, const bool, const VerificationType)
{
    return false;
}
bool CheckProto_5(const VerificationSet&, const bool, const VerificationType)
{
    return false;
}
}  // namespace proto
}  // namespace opentxs
