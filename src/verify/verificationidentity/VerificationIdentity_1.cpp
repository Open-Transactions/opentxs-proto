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
    const VerificationIdentity& identity,
    const bool silent,
    VerificationNymMap& map,
    const VerificationType indexed)
{
    if (!identity.has_nym()) {
        FAIL("verification identity", "missing nym")
    }

    if (MIN_PLAUSIBLE_IDENTIFIER > identity.nym().size()) {
        FAIL2("verification identity", "invalid nym", identity.nym())
    }

    map[identity.nym()] += 1;

    for (auto& it : identity.verification()) {
        try {
            const bool verification = Check(
                it,
                VerificationIdentityAllowedVerification.at(identity.version())
                    .first,
                VerificationIdentityAllowedVerification.at(identity.version())
                    .second,
                silent,
                indexed);

            if (!verification) {
                FAIL("verification identity", "invalid verification")
            }
        } catch (const std::out_of_range&) {
            FAIL2(
                "verification identity",
                "allowed verification version not defined for version",
                identity.version())
        }
    }

    return true;
}

bool CheckProto_2(
    const VerificationIdentity&,
    const bool silent,
    VerificationNymMap&,
    const VerificationType)
{
    UNDEFINED_VERSION("verification identity", 2)
}

bool CheckProto_3(
    const VerificationIdentity&,
    const bool silent,
    VerificationNymMap&,
    const VerificationType)
{
    UNDEFINED_VERSION("verification identity", 3)
}

bool CheckProto_4(
    const VerificationIdentity&,
    const bool silent,
    VerificationNymMap&,
    const VerificationType)
{
    UNDEFINED_VERSION("verification identity", 4)
}

bool CheckProto_5(
    const VerificationIdentity&,
    const bool silent,
    VerificationNymMap&,
    const VerificationType)
{
    UNDEFINED_VERSION("verification identity", 5)
}
}  // namespace proto
}  // namespace opentxs
