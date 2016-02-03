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

#include "opentxs-proto/verify/VerificationSet.hpp"

#include <iostream>

namespace opentxs { namespace proto
{

bool CheckProto_1(
    const VerificationSet& verificationSet)
{
    if (verificationSet.has_internal()) {
        bool validInternal = Check<VerificationGroup>(
            verificationSet.internal(),
            VerificationSetAllowedGroup.at(verificationSet.version()).first,
            VerificationSetAllowedGroup.at(verificationSet.version()).second);

        if (!validInternal) {
            std::cerr << "Verify serialized verification set failed: invalid internal group." << std::endl;
            return false;
        }
    }
    if (verificationSet.has_external()) {
        bool validExternal = Check<VerificationGroup>(
            verificationSet.external(),
            VerificationSetAllowedGroup.at(verificationSet.version()).first,
            VerificationSetAllowedGroup.at(verificationSet.version()).second);

        if (!validExternal) {
            std::cerr << "Verify serialized verification set failed: invalid external group." << std::endl;
            return false;
        }
    }

    for (auto& it: verificationSet.repudiated()) {
        if (MIN_PLAUSIBLE_IDENTIFIER < it.size()) {
            std::cerr << "Verify serialized verification set failed: invalid repudiation."
            << std::endl;
            return false;
        }
    }

    return true;
}

} // namespace proto
} // namespace opentxs
