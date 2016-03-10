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

#include "opentxs-proto/verify/CredentialIndex.hpp"

#include <iostream>

namespace opentxs { namespace proto
{

bool CheckProto_1(
    const CredentialIndex& serializedCredIndex)
{
    bool validSource = false;

    if (!serializedCredIndex.has_nymid()) {
        std::cerr << "Verify serialized credential index failed: missing nym identifier." << std::endl;
        return false;
    }

    if (MIN_PLAUSIBLE_IDENTIFIER > serializedCredIndex.nymid().size()) {
        std::cerr << "Verify serialized credential index failed: invalid nym identifier ("
                << serializedCredIndex.nymid() << ")." << std::endl;
        return false;
    }

    if (!serializedCredIndex.has_source()) {
        std::cerr << "Verify serialized credential index failed: missing private nym source." << std::endl;
        return false;
    }

    validSource = Check(
        serializedCredIndex.source(),
        CredentialIndexAllowedNymIDSource.at(serializedCredIndex.version()).first,
        CredentialIndexAllowedNymIDSource.at(serializedCredIndex.version()).second);

    if (!validSource) {
        std::cerr << "Verify serialized credential index failed: invalid source." << std::endl;
        return false;
    }

    for (auto& it: serializedCredIndex.activecredentials()) {
        if (!Check(
                it,
                CredentialIndexAllowedCredentialSets.at(serializedCredIndex.version()).first,
                CredentialIndexAllowedCredentialSets.at(serializedCredIndex.version()).second,
                serializedCredIndex.nymid())) {
            std::cerr << "Verify serialized credential index failed: invalid credential set." << std::endl;
            return false;
        }
    }

    for (auto& it: serializedCredIndex.revokedcredentials()) {
        if (!Check(
                it,
                CredentialIndexAllowedCredentialSets.at(serializedCredIndex.version()).first,
                CredentialIndexAllowedCredentialSets.at(serializedCredIndex.version()).second,
                serializedCredIndex.nymid())) {
            std::cerr << "Verify serialized credential index failed: invalid credential set." << std::endl;
            return false;
        }
    }

    if (!serializedCredIndex.has_revision()) {
        std::cerr << "Verify serialized credential index failed: missing revision." << std::endl;
        return false;
    }

    if (1 > serializedCredIndex.revision()) {
        std::cerr << "Verify serialized credential index failed: invalid"
                  << " revision (" << serializedCredIndex.revision() << ")."
                  << std::endl;
        return false;
    }


    return true;
}

} // namespace proto
} // namespace opentxs
