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

bool CheckProto_2(
    const PeerRequest& peerRequest)
{
    if (!peerRequest.has_id()) {
        std::cerr << "Verify peer request failed: missing identifier."
                  << std::endl;
        return false;
    }

    if (MIN_PLAUSIBLE_IDENTIFIER > peerRequest.id().size()) {
        std::cerr << "Verify peer request failed: invalid identifier ("
                << peerRequest.id() << ")." << std::endl;
        return false;
    }

    if (!peerRequest.has_initiator()) {
        std::cerr << "Verify peer reply failed: missing initiator."
                  << std::endl;
        return false;
    }

    if (MIN_PLAUSIBLE_IDENTIFIER > peerRequest.initiator().size()) {
        std::cerr << "Verify peer reply failed: invalid initiator ("
                  << peerRequest.initiator() << ")." << std::endl;
        return false;
    }

    if (!peerRequest.has_recipient()) {
        std::cerr << "Verify peer reply failed: missing recipient."
                  << std::endl;
        return false;
    }

    if (MIN_PLAUSIBLE_IDENTIFIER > peerRequest.recipient().size()) {
        std::cerr << "Verify peer reply failed: invalid recipient ("
                  << peerRequest.recipient() << ")." << std::endl;
        return false;
    }

    if (!peerRequest.has_type()) {
        std::cerr << "Verify peer request failed: missing type." << std::endl;

        return false;
    }

    if ((peerRequest.type() < PEERREQUEST_BAILMENT) ||
        (peerRequest.type() > PEERREQUEST_STORESECRET)) {
            std::cerr << "Verify peer request failed: invalid type."
                      << std::endl;

            return false;
    }

    if (!peerRequest.has_cookie()) {
        std::cerr << "Verify peer request failed: missing cookie." << std::endl;

        return false;
    }

    bool validSig = Check(
        peerRequest.signature(),
        PeerRequestAllowedSignature.at(peerRequest.version()).first,
        PeerRequestAllowedSignature.at(peerRequest.version()).second,
        SIGROLE_PEERREQUEST);

    if (!validSig) {
        std::cerr << "Verify peer request failed: invalid signature."
                  << std::endl;

        return false;
    }

    switch (peerRequest.type()) {
        case PEERREQUEST_BAILMENT : {
            if (!peerRequest.has_bailment()) {
                std::cerr << "Verify peer request failed: missing bailment."
                          << std::endl;

                return false;
            }

            bool validbailment = Check(
                peerRequest.bailment(),
                PeerRequestAllowedBailment.at(peerRequest.version()).first,
                PeerRequestAllowedBailment.at(peerRequest.version()).second);

            if (!validbailment) {
                std::cerr << "Verify peer request failed: invalid bailment."
                          << std::endl;

                return false;
            }

            break;
        }
        case PEERREQUEST_OUTBAILMENT : {
            if (!peerRequest.has_outbailment()) {
                std::cerr << "Verify peer request failed: missing outbailment."
                          << std::endl;

                return false;
            }

            bool validoutbailment = Check(
                peerRequest.outbailment(),
                PeerRequestAllowedOutBailment.at(peerRequest.version()).first,
                PeerRequestAllowedOutBailment.at(peerRequest.version()).second);

            if (!validoutbailment) {
                std::cerr << "Verify peer request failed: invalid outbailment."
                          << std::endl;

                return false;
            }

            break;
        }
        case PEERREQUEST_PENDINGBAILMENT : {
            if (!peerRequest.has_pendingbailment()) {
                std::cerr << "Verify peer request failed: missing "
                          << "pendingbailment." << std::endl;

                return false;
            }

            bool validoutbailment = Check(
                peerRequest.pendingbailment(),
                PeerRequestAllowedPendingBailment.at(
                    peerRequest.version()).first,
                PeerRequestAllowedPendingBailment.at(
                    peerRequest.version()).second);

            if (!validoutbailment) {
                std::cerr << "Verify peer request failed: invalid "
                          << "pendingbailment." << std::endl;

                return false;
            }

            break;
        }
        case PEERREQUEST_CONNECTIONINFO : {
            if (!peerRequest.has_connectioninfo()) {
                std::cerr << "Verify peer request failed: missing "
                          << "connectioninfo." << std::endl;

                return false;
            }

            bool validconnectioninfo = Check(
                peerRequest.connectioninfo(),
                PeerRequestAllowedConnectionInfo.at(
                    peerRequest.version()).first,
                PeerRequestAllowedConnectionInfo.at(
                    peerRequest.version()).second);

            if (!validconnectioninfo) {
                std::cerr << "Verify peer request failed: invalid "
                          << "connectioninfo." << std::endl;

                return false;
            }

            break;
        }
        case PEERREQUEST_STORESECRET : {
            if (!peerRequest.has_storesecret()) {
                std::cerr << "Verify peer request failed: missing "
                          << "storesecret." << std::endl;

                return false;
            }

            bool validstoresecret = Check(
                peerRequest.storesecret(),
                PeerRequestAllowedStoreSecret.at(
                    peerRequest.version()).first,
                PeerRequestAllowedStoreSecret.at(
                    peerRequest.version()).second);

            if (!validstoresecret) {
                std::cerr << "Verify peer request failed: invalid "
                          << "storesecret." << std::endl;

                return false;
            }

            break;
        }
        default : {}
    }

    if (!peerRequest.has_server()) {
        std::cerr << "Verify peer reply failed: missing server."
                  << std::endl;
        return false;
    }

    if (MIN_PLAUSIBLE_IDENTIFIER > peerRequest.server().size()) {
        std::cerr << "Verify peer reply failed: invalid server ("
                  << peerRequest.server() << ")." << std::endl;
        return false;
    }

    return true;
}
} // namespace proto
} // namespace opentxs
