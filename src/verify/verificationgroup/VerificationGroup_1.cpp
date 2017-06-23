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
    const VerificationGroup& verificationGroup,
    const bool silent,
    const VerificationType indexed)
{
    VerificationNymMap nymMap;

    for (auto& it : verificationGroup.identity()) {
        bool validIdentity = Check(
            it,
            VerificationGroupAllowedIdentity.at(verificationGroup.version())
                .first,
            VerificationGroupAllowedIdentity.at(verificationGroup.version())
                .second,
            silent,
            nymMap,
            indexed);

        if (!validIdentity) {
            FAIL2("verification group", "invalid identity", it.nym())
        }
    }

    for (auto& nym : nymMap) {
        if (nym.second > 1) {
            FAIL2("verification group", "duplicate identity", nym.first)
        }
    }

    return true;
}
bool CheckProto_2(const VerificationGroup&, const bool, const VerificationType)
{
    return false;
}
bool CheckProto_3(const VerificationGroup&, const bool, const VerificationType)
{
    return false;
}
bool CheckProto_4(const VerificationGroup&, const bool, const VerificationType)
{
    return false;
}
bool CheckProto_5(const VerificationGroup&, const bool, const VerificationType)
{
    return false;
}
}  // namespace proto
}  // namespace opentxs
