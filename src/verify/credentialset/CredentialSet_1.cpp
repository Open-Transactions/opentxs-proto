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

#include "opentxs-proto/verify/CredentialSet.hpp"

#include <iostream>

namespace opentxs { namespace proto
{

bool CredentialSet_1(
    const CredentialSet& serializedCredSet,
    const std::string& nymID)
{
    if (!serializedCredSet.has_nymid()) {
        std::cerr << "Verify serialized credential set failed: missing nym identifier." << std::endl;
        return false;
    }

    if (nymID != serializedCredSet.nymid()) {
        std::cerr << "Verify serialized credential set failed: wrong nym identifier." << std::endl;
        return false;
    }

    if (MIN_PLAUSIBLE_IDENTIFIER > serializedCredSet.nymid().size()) {
        std::cerr << "Verify serialized credential set failed: invalid nym identifier ("
                << serializedCredSet.nymid() << ")." << std::endl;
        return false;
    }

    if (!serializedCredSet.has_masterid()) {
        std::cerr << "Verify serialized credential set failed: missing master credential identifier." << std::endl;
        return false;
    }

    if (MIN_PLAUSIBLE_IDENTIFIER > serializedCredSet.masterid().size()) {
        std::cerr << "Verify serialized credential set failed: invalid master credential identifier ("
        << serializedCredSet.masterid() << ")." << std::endl;
        return false;
    }

    if (!serializedCredSet.has_mode()) {
        std::cerr << "Verify serialized credential set failed: missing mode." << std::endl;
        return false;
    }

    switch (serializedCredSet.mode()) {
        case CREDSETMODE_INDEX :
            if (serializedCredSet.has_mastercredential()) {
                std::cerr << "Verify serialized credential set failed: full master credential included in index mode." << std::endl;
                return false;
            }

            if (0 < serializedCredSet.activechildren_size()) {
                std::cerr << "Verify serialized credential set failed: full active credentials included in index mode ("
                << serializedCredSet.activechildren_size() << ")." << std::endl;
                return false;
            }

            if (0 < serializedCredSet.revokedchildren_size()) {
                std::cerr << "Verify serialized credential set failed: full revoked credentials included in index mode ("
                << serializedCredSet.revokedchildren_size() << ")." << std::endl;
                return false;
            }

            for (auto& it: serializedCredSet.activechildids()) {
                if (MIN_PLAUSIBLE_IDENTIFIER > it.size()) {
                    std::cerr << "Verify serialized credential set failed: invalid active child credential identifier ("
                    << it.size() << ")." << std::endl;
                    return false;
                }
            }

            for (auto& it: serializedCredSet.revokedchildids()) {
                if (MIN_PLAUSIBLE_IDENTIFIER > it.size()) {
                    std::cerr << "Verify serialized credential set failed: invalid revoked child credential identifier ("
                    << it.size() << ")." << std::endl;
                    return false;
                }
            }
            break;
        case CREDSETMODE_FULL :
            if (!serializedCredSet.has_mastercredential()) {
                std::cerr << "Verify serialized credential set failed: missing master credential." << std::endl;
                return false;
            }

            if (!Verify(serializedCredSet.mastercredential(), CREDROLE_MASTERKEY, true)) {
                std::cerr << "Verify serialized credential set failed: invalid master credential." << std::endl;
                return false;
            }

            if (serializedCredSet.mastercredential().id() != serializedCredSet.masterid()) {
                std::cerr << "Verify serialized credential set failed: wrong master credential ("
                << serializedCredSet.mastercredential().id() << ")." << std::endl;
                return false;
            }

            if (0 < serializedCredSet.activechildids_size()) {
                std::cerr << "Verify serialized credential set failed: active credential IDs included in full mode ("
                << serializedCredSet.activechildids_size() << ")." << std::endl;
                return false;
            }

            if (0 < serializedCredSet.revokedchildids_size()) {
                std::cerr << "Verify serialized credential set failed: revoked credential IDs included in full mode ("
                << serializedCredSet.revokedchildids_size() << ")." << std::endl;
                return false;
            }

            for (auto& it: serializedCredSet.activechildren()) {
                if (!Verify(it, CREDROLE_ERROR, true)) {
                    std::cerr << "Verify serialized credential set failed: invalid active child credential." << std::endl;
                    return false;
                }
                if (CREDROLE_MASTERKEY == it.role()) {
                    std::cerr << "Verify serialized credential set failed: unexpected master credential." << std::endl;
                    return false;
                }
            }

            for (auto& it: serializedCredSet.revokedchildren()) {
                if (!Verify(it, CREDROLE_ERROR, true)) {
                    std::cerr << "Verify serialized credential set failed: invalid revoked child credential." << std::endl;
                    return false;
                }
                if (CREDROLE_MASTERKEY == it.role()) {
                    std::cerr << "Verify serialized credential set failed: unexpected master credential." << std::endl;
                    return false;
                }
            }
            break;
        default :
            std::cerr << "Verify serialized credential set failed: unknown mode ("
                  << serializedCredSet.mode() << ")." << std::endl;

            return false;
    }

    return true;
}

} // namespace proto
} // namespace opentxs
