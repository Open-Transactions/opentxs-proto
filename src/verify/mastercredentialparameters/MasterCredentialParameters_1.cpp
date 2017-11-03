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
    const MasterCredentialParameters& input,
    const bool silent,
    bool& expectSourceSignature)
{
    if (false == input.has_source()) {
        FAIL("master parameters", "missing nym id source")
    }

    try {
        const bool validSource = Check(
            input.source(),
            MasterParamsAllowedNymIDSource.at(input.version()).first,
            MasterParamsAllowedNymIDSource.at(input.version()).second,
            silent);

        if (!validSource) {
            FAIL("master parameters", "invalid nym id source")
        }
    } catch (const std::out_of_range&) {
        FAIL2(
            "master parameters",
            "allowed nym ID source version not defined for version",
            input.version())
    }

    if (!input.has_sourceproof()) {
        FAIL("master parameters", "missing nym id source proof")
    }

    try {
        const bool validProof = Check(
            input.sourceproof(),
            MasterParamsAllowedSourceProof.at(input.version()).first,
            MasterParamsAllowedSourceProof.at(input.version()).second,
            silent,
            expectSourceSignature);

        if (!validProof) {
            FAIL("master parameters", "invalid nym id source proof")
        }
    } catch (const std::out_of_range&) {
        FAIL2(
            "master parameters",
            "allowed source proof version not defined for version",
            input.version())
    }

    return true;
}

bool CheckProto_2(
    const MasterCredentialParameters& input,
    const bool silent,
    bool&)
{
    UNDEFINED_VERSION("master parameters", 2)
}

bool CheckProto_3(
    const MasterCredentialParameters& input,
    const bool silent,
    bool&)
{
    UNDEFINED_VERSION("master parameters", 3)
}

bool CheckProto_4(
    const MasterCredentialParameters& input,
    const bool silent,
    bool&)
{
    UNDEFINED_VERSION("master parameters", 4)
}

bool CheckProto_5(
    const MasterCredentialParameters& input,
    const bool silent,
    bool&)
{
    UNDEFINED_VERSION("master parameters", 5)
}
}  // namespace proto
}  // namespace opentxs
