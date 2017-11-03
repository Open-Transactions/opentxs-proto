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
bool CheckProto_3(const PeerReply& input, const bool silent)
{
    if (!input.has_id()) {
        FAIL("peer reply", "missing id")
    }

    if (MIN_PLAUSIBLE_IDENTIFIER > input.id().size()) {
        FAIL("peer reply", "invalid id")
    }

    if (!input.has_initiator()) {
        FAIL("peer reply", "missing initiator")
    }

    if (MIN_PLAUSIBLE_IDENTIFIER > input.initiator().size()) {
        FAIL2("peer reply", "invalid initiator", input.initiator())
    }

    if (!input.has_recipient()) {
        FAIL("peer reply", "missing recipient")
    }

    if (MIN_PLAUSIBLE_IDENTIFIER > input.recipient().size()) {
        FAIL2("peer reply", "invalid recipient", input.recipient())
    }

    if (!input.has_type()) {
        FAIL("peer reply", "missing type")
    }

    if (!input.has_cookie()) {
        FAIL("peer reply", "missing cookie")
    }

    try {
        const bool validSig = Check(
            input.signature(),
            PeerReplyAllowedSignature.at(input.version()).first,
            PeerReplyAllowedSignature.at(input.version()).second,
            silent,
            SIGROLE_PEERREPLY);

        if (!validSig) {
            FAIL("peer reply", "invalid signature")
        }
    } catch (const std::out_of_range&) {
        FAIL2(
            "peer reply",
            "allowed signature version not defined for version",
            input.version())
    }

    if (!input.has_server()) {
        FAIL("peer reply", "missing server")
    }

    if (MIN_PLAUSIBLE_IDENTIFIER > input.server().size()) {
        FAIL2("peer reply", "invalid server", input.server())
    }

    switch (input.type()) {
        case PEERREQUEST_BAILMENT: {
            if (!input.has_bailment()) {
                FAIL("peer reply", "missing bailment")
            }

            try {
                const bool validbailment = Check(
                    input.bailment(),
                    PeerReplyAllowedBailment.at(input.version()).first,
                    PeerReplyAllowedBailment.at(input.version()).second,
                    silent);

                if (!validbailment) {
                    FAIL("peer reply", "invalid bailment")
                }
            } catch (const std::out_of_range&) {
                FAIL2(
                    "peer reply",
                    "allowed bailment version not defined for version",
                    input.version())
            }
        } break;
        case PEERREQUEST_OUTBAILMENT: {
            if (!input.has_outbailment()) {
                FAIL("peer reply", "missing outbailment")
            }

            try {
                const bool validoutbailment = Check(
                    input.outbailment(),
                    PeerReplyAllowedOutBailment.at(input.version()).first,
                    PeerReplyAllowedOutBailment.at(input.version()).second,
                    silent);

                if (!validoutbailment) {
                    FAIL("peer reply", "invalid outbailment")
                }
            } catch (const std::out_of_range&) {
                FAIL2(
                    "peer reply",
                    "allowed outbailment version not defined for version",
                    input.version())
            }
        } break;
        case PEERREQUEST_PENDINGBAILMENT:
        case PEERREQUEST_STORESECRET:
        case PEERREQUEST_VERIFICATIONOFFER: {
            if (!input.has_notice()) {
                FAIL("peer reply", "missing notice")
            }

            try {
                const bool validnotice = Check(
                    input.notice(),
                    PeerReplyAllowedNotice.at(input.version()).first,
                    PeerReplyAllowedNotice.at(input.version()).second,
                    silent);

                if (!validnotice) {
                    FAIL("peer reply", "invalid notice")
                }
            } catch (const std::out_of_range&) {
                FAIL2(
                    "peer reply",
                    "allowed peer notice version not defined for version",
                    input.version())
            }
        } break;
        case PEERREQUEST_CONNECTIONINFO: {
            if (!input.has_connectioninfo()) {
                FAIL("peer reply", "missing connectioninfo")
            }

            try {
                const bool validconnectioninfo = Check(
                    input.connectioninfo(),
                    PeerReplyAllowedConnectionInfo.at(input.version()).first,
                    PeerReplyAllowedConnectionInfo.at(input.version()).second,
                    silent);

                if (!validconnectioninfo) {
                    FAIL("peer reply", "invalid connectioninfo")
                }
            } catch (const std::out_of_range&) {
                FAIL2(
                    "peer reply",
                    "allowed connection info version not defined for version",
                    input.version())
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
