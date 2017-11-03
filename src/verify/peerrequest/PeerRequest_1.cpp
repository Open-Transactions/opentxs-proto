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
bool CheckProto_1(const PeerRequest& input, const bool silent)
{
    if (!input.has_id()) {
        FAIL("peer request", "missing id")
    }

    if (MIN_PLAUSIBLE_IDENTIFIER > input.id().size()) {
        FAIL("peer request", "invalid id")
    }

    if (!input.has_initiator()) {
        FAIL("peer request", "missing initiato")
    }

    if (MIN_PLAUSIBLE_IDENTIFIER > input.initiator().size()) {
        FAIL2("peer request", "invalid initiator", input.initiator())
    }

    if (!input.has_recipient()) {
        FAIL("peer request", " missing recipient")
    }

    if (MIN_PLAUSIBLE_IDENTIFIER > input.recipient().size()) {
        FAIL2("peer request", "invalid recipient", input.recipient())
    }

    if (!input.has_type()) {
        FAIL("peer request", "missing type")
    }

    if (!input.has_cookie()) {
        FAIL("peer request", "missing cookie")
    }

    try {
        const bool validSig = Check(
            input.signature(),
            PeerReplyAllowedSignature.at(input.version()).first,
            PeerReplyAllowedSignature.at(input.version()).second,
            silent,
            SIGROLE_PEERREQUEST);

        if (!validSig) {
            FAIL("peer request", "invalid signature")
        }
    } catch (const std::out_of_range&) {
        FAIL2(
            "peer request",
            "allowed signature version not defined for version",
            input.version())
    }

    switch (input.type()) {
        case PEERREQUEST_BAILMENT: {
            if (!input.has_bailment()) {
                FAIL("peer request", "missing bailment")
            }

            try {
                const bool validbailment = Check(
                    input.bailment(),
                    PeerRequestAllowedBailment.at(input.version()).first,
                    PeerRequestAllowedBailment.at(input.version()).second,
                    silent);

                if (!validbailment) {
                    FAIL("peer request", "invalid bailment")
                }
            } catch (const std::out_of_range&) {
                FAIL2(
                    "peer request",
                    "allowed bailment version not defined for version",
                    input.version())
            }
        } break;
        case PEERREQUEST_OUTBAILMENT: {
            if (!input.has_outbailment()) {
                FAIL("peer request", "missing outbailment")
            }

            try {
                const bool validoutbailment = Check(
                    input.outbailment(),
                    PeerRequestAllowedOutBailment.at(input.version()).first,
                    PeerRequestAllowedOutBailment.at(input.version()).second,
                    silent);

                if (!validoutbailment) {
                    FAIL("peer request", "invalid outbailment")
                }
            } catch (const std::out_of_range&) {
                FAIL2(
                    "peer request",
                    "allowed outbailment version not defined for version",
                    input.version())
            }
        } break;
        case PEERREQUEST_PENDINGBAILMENT: {
            if (!input.has_pendingbailment()) {
                FAIL("peer request", "missing pendingbailment")
            }

            try {
                const bool validoutbailment = Check(
                    input.pendingbailment(),
                    PeerRequestAllowedPendingBailment.at(input.version()).first,
                    PeerRequestAllowedPendingBailment.at(input.version())
                        .second,
                    silent);

                if (!validoutbailment) {
                    FAIL("peer request", "invalid pendingbailment")
                }
            } catch (const std::out_of_range&) {
                FAIL2(
                    "peer request",
                    "allowed pending bailment version not defined for version",
                    input.version())
            }
        } break;
        case PEERREQUEST_CONNECTIONINFO: {
            if (!input.has_connectioninfo()) {
                FAIL("peer request", "missing connectioninfo")
            }

            try {
                const bool validconnectioninfo = Check(
                    input.connectioninfo(),
                    PeerRequestAllowedConnectionInfo.at(input.version()).first,
                    PeerRequestAllowedConnectionInfo.at(input.version()).second,
                    silent);

                if (!validconnectioninfo) {
                    FAIL("peer request", "invalid connectioninfo")
                }
            } catch (const std::out_of_range&) {
                FAIL2(
                    "peer request",
                    "allowed connectioninfo version not defined for version",
                    input.version())
            }
        } break;
        case PEERREQUEST_STORESECRET: {
            if (!input.has_storesecret()) {
                FAIL("peer request", "missing storesecret")
            }

            try {
                const bool validstoresecret = Check(
                    input.storesecret(),
                    PeerRequestAllowedStoreSecret.at(input.version()).first,
                    PeerRequestAllowedStoreSecret.at(input.version()).second,
                    silent);

                if (!validstoresecret) {
                    FAIL("peer request", "invalid storesecret")
                }
            } catch (const std::out_of_range&) {
                FAIL2(
                    "peer request",
                    "allowed storesecret version not defined for version",
                    input.version())
            }
        } break;
        default: {
            FAIL("peer request", "invalid type")
        }
    }

    return true;
}
}  // namespace proto
}  // namespace opentxs
