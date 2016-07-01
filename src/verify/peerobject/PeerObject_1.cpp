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

#include "opentxs-proto/verify/PeerObject.hpp"

#include <iostream>

namespace opentxs { namespace proto
{

bool CheckProto_1(
    const PeerObject& peerObject)
{
    if (!peerObject.has_type()) {
        std::cerr << "Verify peer object failed: missing type." << std::endl;

        return false;
    }

    if ((peerObject.type() < PEEROBJECT_MESSAGE) ||
        (peerObject.type() > PEEROBJECT_RESPONSE)) {
            std::cerr << "Verify peer object failed: invalid type."
                      << std::endl;

            return false;
    }

    switch (peerObject.type()) {
        case PEEROBJECT_MESSAGE : {
            if (!peerObject.has_otmessage()) {
                std::cerr << "Verify peer object failed: missing otmessage."
                          << std::endl;

                return false;
            }

            if (peerObject.has_otrequest()) {
                std::cerr << "Verify peer object failed: otrequest not empty."
                          << std::endl;

                return false;
            }

            if (peerObject.has_otreply()) {
                std::cerr << "Verify peer object failed: otreply not empty."
                          << std::endl;

                return false;
            }

            break;
        }
        case PEEROBJECT_REQUEST : {
            if (!peerObject.has_otrequest()) {
                std::cerr << "Verify peer object failed: missing otrequest."
                          << std::endl;

                return false;
            }

            bool validrequest = Check(
                peerObject.otrequest(),
                PeerObjectAllowedRequest.at(peerObject.version()).first,
                PeerObjectAllowedRequest.at(peerObject.version()).second);

            if (!validrequest) {
                std::cerr << "Verify peer object failed: invalid otrequest."
                          << std::endl;

                return false;
            }

            if (peerObject.has_otmessage()) {
                std::cerr << "Verify peer object failed: otmessage not empty."
                          << std::endl;

                return false;
            }

            if (peerObject.has_otreply()) {
                std::cerr << "Verify peer object failed: otreply not empty."
                          << std::endl;

                return false;
            }

            break;
        }
        case PEEROBJECT_RESPONSE : {
            if (!peerObject.has_otrequest()) {
                std::cerr << "Verify peer object failed: missing otrequest."
                          << std::endl;

                return false;
            }

            bool validrequest = Check(
                peerObject.otrequest(),
                PeerObjectAllowedRequest.at(peerObject.version()).first,
                PeerObjectAllowedRequest.at(peerObject.version()).second);

            if (!validrequest) {
                std::cerr << "Verify peer object failed: invalid otrequest."
                          << std::endl;

                return false;
            }

            if (!peerObject.has_otreply()) {
                std::cerr << "Verify peer object failed: missing otreply."
                          << std::endl;

                return false;
            }

            bool validreply = Check(
                peerObject.otreply(),
                PeerObjectAllowedReply.at(peerObject.version()).first,
                PeerObjectAllowedReply.at(peerObject.version()).second);

            if (!validreply) {
                std::cerr << "Verify peer object failed: invalid otreply."
                          << std::endl;

                return false;
            }

            if (peerObject.has_otmessage()) {
                std::cerr << "Verify peer object failed: otmessage not empty."
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
