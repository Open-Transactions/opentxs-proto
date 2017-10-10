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
bool CheckProto_3(const PeerReply& reply, const bool silent)
{
    if (!reply.has_id()) {
        FAIL("peer reply", "missing id")
    }

    if (MIN_PLAUSIBLE_IDENTIFIER > reply.id().size()) {
        FAIL("peer reply", "invalid id")
    }

    if (!reply.has_initiator()) {
        FAIL("peer reply", "missing initiator")
    }

    if (MIN_PLAUSIBLE_IDENTIFIER > reply.initiator().size()) {
        FAIL2("peer reply", "invalid initiator", reply.initiator())
    }

    if (!reply.has_recipient()) {
        FAIL("peer reply", "missing recipient")
    }

    if (MIN_PLAUSIBLE_IDENTIFIER > reply.recipient().size()) {
        FAIL2("peer reply", "invalid recipient", reply.recipient())
    }

    if (!reply.has_type()) {
        FAIL("peer reply", "missing type")
    }

    if (!reply.has_cookie()) {
        FAIL("peer reply", "missing cookie")
    }

    try {
        const bool validSig = Check(
            reply.signature(),
            PeerReplyAllowedSignature.at(reply.version()).first,
            PeerReplyAllowedSignature.at(reply.version()).second,
            silent,
            SIGROLE_PEERREPLY);

        if (!validSig) {
            FAIL("peer reply", "invalid signature")
        }
    } catch (const std::out_of_range&) {
        FAIL2(
            "peer reply",
            "allowed signature version not defined for version",
            reply.version())
    }

    if (!reply.has_server()) {
        FAIL("peer reply", "missing server")
    }

    if (MIN_PLAUSIBLE_IDENTIFIER > reply.server().size()) {
        FAIL2("peer reply", "invalid server", reply.server())
    }

    switch (reply.type()) {
        case PEERREQUEST_BAILMENT: {
            if (!reply.has_bailment()) {
                FAIL("peer reply", "missing bailment")
            }

            try {
                const bool validbailment = Check(
                    reply.bailment(),
                    PeerReplyAllowedBailment.at(reply.version()).first,
                    PeerReplyAllowedBailment.at(reply.version()).second,
                    silent);

                if (!validbailment) {
                    FAIL("peer reply", "invalid bailment")
                }
            } catch (const std::out_of_range&) {
                FAIL2(
                    "peer reply",
                    "allowed bailment version not defined for version",
                    reply.version())
            }
        } break;
        case PEERREQUEST_OUTBAILMENT: {
            if (!reply.has_outbailment()) {
                FAIL("peer reply", "missing outbailment")
            }

            try {
                const bool validoutbailment = Check(
                    reply.outbailment(),
                    PeerReplyAllowedOutBailment.at(reply.version()).first,
                    PeerReplyAllowedOutBailment.at(reply.version()).second,
                    silent);

                if (!validoutbailment) {
                    FAIL("peer reply", "invalid outbailment")
                }
            } catch (const std::out_of_range&) {
                FAIL2(
                    "peer reply",
                    "allowed outbailment version not defined for version",
                    reply.version())
            }
        } break;
        case PEERREQUEST_PENDINGBAILMENT:
        case PEERREQUEST_STORESECRET:
        case PEERREQUEST_VERIFICATIONOFFER: {
            if (!reply.has_notice()) {
                FAIL("peer reply", "missing notice")
            }

            try {
                const bool validnotice = Check(
                    reply.notice(),
                    PeerReplyAllowedNotice.at(reply.version()).first,
                    PeerReplyAllowedNotice.at(reply.version()).second,
                    silent);

                if (!validnotice) {
                    FAIL("peer reply", "invalid notice")
                }
            } catch (const std::out_of_range&) {
                FAIL2(
                    "peer reply",
                    "allowed peer notice version not defined for version",
                    reply.version())
            }
        } break;
        case PEERREQUEST_CONNECTIONINFO: {
            if (!reply.has_connectioninfo()) {
                FAIL("peer reply", "missing connectioninfo")
            }

            try {
                const bool validconnectioninfo = Check(
                    reply.connectioninfo(),
                    PeerReplyAllowedConnectionInfo.at(reply.version()).first,
                    PeerReplyAllowedConnectionInfo.at(reply.version()).second,
                    silent);

                if (!validconnectioninfo) {
                    FAIL("peer reply", "invalid connectioninfo")
                }
            } catch (const std::out_of_range&) {
                FAIL2(
                    "peer reply",
                    "allowed connection info version not defined for version",
                    reply.version())
            }
        } break;
        default: {
            FAIL("peer reply", "invalid type")
        }
    }

    return true;
}
}  // namespace proto
}  // namespace opentxs
