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

#include "opentxs-proto/verify/VerificationIdentity.hpp"

#include <iostream>

namespace opentxs { namespace proto
{

bool CheckProto_1(const VerificationIdentity& verificationIdentity)
{
    if (!verificationIdentity.has_nym()) {
        std::cerr << "Verify serialized verification identity failed: missing nym."
        << std::endl;
        return false;
    }

    if (MIN_PLAUSIBLE_IDENTIFIER > verificationIdentity.nym().size()) {
        std::cerr << "Verify serialized verification identity failed: invalid nym ("
        << verificationIdentity.nym() << ")." << std::endl;
        return false;
    }

    for (auto& it : verificationIdentity.verification()) {
        bool verification = Check<Verification>(
            it,
            VerificationIdentityAllowedVerification.at(verificationIdentity.version()).first,
            VerificationIdentityAllowedVerification.at(verificationIdentity.version()).second);

        if (!verification) {
            std::cerr << "Verify serialized verification identity failed: invalid verification." << std::endl;
            return false;
        }
    }

    return true;
}

} // namespace proto
} // namespace opentxs
