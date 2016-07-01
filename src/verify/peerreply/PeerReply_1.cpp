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

#include "opentxs-proto/verify/PeerReply.hpp"

#include <iostream>

namespace opentxs { namespace proto
{

bool CheckProto_1(
    const PeerReply& peerReply)
{
    if (!peerReply.has_type()) {
        std::cerr << "Verify peer reply failed: missing type." << std::endl;

        return false;
    }

    if ((peerReply.type() < PEERREQUEST_BAILMENT) ||
        (peerReply.type() > PEERREQUEST_OUTBAILMENT)) {
            std::cerr << "Verify peer reply failed: invalid type."
                      << std::endl;

            return false;
    }

    if (!peerReply.has_cookie()) {
        std::cerr << "Verify peer reply failed: missing cookie." << std::endl;

        return false;
    }

    bool validSig = Check(
        peerReply.signature(),
        PeerReplyAllowedSignature.at(peerReply.version()).first,
        PeerReplyAllowedSignature.at(peerReply.version()).second,
        SIGROLE_PEERREQUEST);

    if (!validSig) {
        std::cerr << "Verify peer reply failed: invalid signature."
                  << std::endl;

        return false;
    }

    switch (peerReply.type()) {
        case PEERREQUEST_BAILMENT : {
            if (!peerReply.has_bailment()) {
                std::cerr << "Verify peer reply failed: missing bailment."
                          << std::endl;

                return false;
            }

            bool validbailment = Check(
                peerReply.bailment(),
                PeerReplyAllowedBailment.at(peerReply.version()).first,
                PeerReplyAllowedBailment.at(peerReply.version()).second);

            if (!validbailment) {
                std::cerr << "Verify peer reply failed: invalid bailment."
                          << std::endl;

                return false;
            }

            break;
        }
        case PEERREQUEST_OUTBAILMENT : {
            if (!peerReply.has_outbailment()) {
                std::cerr << "Verify peer reply failed: missing outbailment."
                          << std::endl;

                return false;
            }

            bool validoutbailment = Check(
                peerReply.outbailment(),
                PeerReplyAllowedOutBailment.at(peerReply.version()).first,
                PeerReplyAllowedOutBailment.at(peerReply.version()).second);

            if (!validoutbailment) {
                std::cerr << "Verify peer reply failed: invalid outbailment."
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
