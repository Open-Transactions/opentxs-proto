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

#include "opentxs-proto/verify/PeerRequest.hpp"

#include <iostream>

namespace opentxs { namespace proto
{

bool CheckProto_1(
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
        (peerRequest.type() > PEERREQUEST_OUTBAILMENT)) {
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
        default : {}
    }

    return true;
}

} // namespace proto
} // namespace opentxs
