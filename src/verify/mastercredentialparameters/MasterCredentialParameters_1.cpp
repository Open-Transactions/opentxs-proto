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

namespace opentxs { namespace proto
{

bool CheckProto_1(
    const MasterCredentialParameters& serializedMasterParams,
    bool& expectSourceSignature)
{
    bool validSource = false;
    bool validProof = false;

    validSource = Check(
        serializedMasterParams.source(),
        MasterParamsAllowedNymIDSource.at(serializedMasterParams.version()).first,
        MasterParamsAllowedNymIDSource.at(serializedMasterParams.version()).second);

    if (!validSource) {
        std::cerr << "Verify serialized master parameters failed: invalid nym id source." << std::endl;
        return false;
    }

    if (!serializedMasterParams.has_sourceproof()) {
        std::cerr << "Verify serialized master parameters failed: missing source proof." << std::endl;
        return false;
    }

    validProof = Check(
        serializedMasterParams.sourceproof(),
        MasterParamsAllowedSourceProof.at(serializedMasterParams.version()).first,
        MasterParamsAllowedSourceProof.at(serializedMasterParams.version()).second,
        expectSourceSignature);

    if (!validProof) {
        std::cerr << "Verify serialized master parameters failed: invalid nym id source proof." << std::endl;
        return false;
    }

    return true;
}
bool CheckProto_2(const MasterCredentialParameters&, bool&) { return false; }
} // namespace proto
} // namespace opentxs
