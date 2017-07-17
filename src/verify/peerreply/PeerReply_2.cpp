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
bool CheckProto_2(const PeerReply& reply, const bool silent)
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

    bool validSig = Check(
        reply.signature(),
        PeerReplyAllowedSignature.at(reply.version()).first,
        PeerReplyAllowedSignature.at(reply.version()).second,
        silent,
        SIGROLE_PEERREPLY);

    if (!validSig) {
        FAIL("peer reply", "invalid signature")
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

            bool validbailment = Check(
                reply.bailment(),
                PeerReplyAllowedBailment.at(reply.version()).first,
                PeerReplyAllowedBailment.at(reply.version()).second,
                silent);

            if (!validbailment) {
                FAIL("peer reply", "invalid bailment")
            }
        } break;
        case PEERREQUEST_OUTBAILMENT: {
            if (!reply.has_outbailment()) {
                FAIL("peer reply", "missing outbailment")
            }

            bool validoutbailment = Check(
                reply.outbailment(),
                PeerReplyAllowedOutBailment.at(reply.version()).first,
                PeerReplyAllowedOutBailment.at(reply.version()).second,
                silent);

            if (!validoutbailment) {
                FAIL("peer reply", "invalid outbailment")
            }
        } break;
        case PEERREQUEST_PENDINGBAILMENT:
        case PEERREQUEST_STORESECRET: {
            if (!reply.has_notice()) {
                FAIL("peer reply", "missing notice")
            }

            bool validnotice = Check(
                reply.notice(),
                PeerReplyAllowedNotice.at(reply.version()).first,
                PeerReplyAllowedNotice.at(reply.version()).second,
                silent);

            if (!validnotice) {
                FAIL("peer reply", "invalid notice")
            }
        } break;
        case PEERREQUEST_CONNECTIONINFO: {
            if (!reply.has_connectioninfo()) {
                FAIL("peer reply", "missing connectioninfo")
            }

            bool validconnectioninfo = Check(
                reply.connectioninfo(),
                PeerReplyAllowedConnectionInfo.at(reply.version()).first,
                PeerReplyAllowedConnectionInfo.at(reply.version()).second,
                silent);

            if (!validconnectioninfo) {
                FAIL("peer reply", "invalid connectioninfo")
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
