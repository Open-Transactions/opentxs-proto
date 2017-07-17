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
bool CheckProto_2(const PeerRequest& request, const bool silent)
{
    if (!request.has_id()) {
        FAIL("peer request", "missing id")
    }

    if (MIN_PLAUSIBLE_IDENTIFIER > request.id().size()) {
        FAIL("peer request", "invalid id")
    }

    if (!request.has_initiator()) {
        FAIL("peer request", "missing initiato")
    }

    if (MIN_PLAUSIBLE_IDENTIFIER > request.initiator().size()) {
        FAIL2("peer request", "invalid initiator", request.initiator())
    }

    if (!request.has_recipient()) {
        FAIL("peer request", " missing recipient")
    }

    if (MIN_PLAUSIBLE_IDENTIFIER > request.recipient().size()) {
        FAIL2("peer request", "invalid recipient", request.recipient())
    }

    if (!request.has_type()) {
        FAIL("peer request", "missing type")
    }

    if (!request.has_cookie()) {
        FAIL("peer request", "missing cookie")
    }

    bool validSig = Check(
        request.signature(),
        PeerRequestAllowedSignature.at(request.version()).first,
        PeerRequestAllowedSignature.at(request.version()).second,
        silent,
        SIGROLE_PEERREQUEST);

    if (!validSig) {
        FAIL("peer request", "invalid signature")
    }

    if (!request.has_server()) {
        FAIL("peer request", "missing server")
    }

    if (MIN_PLAUSIBLE_IDENTIFIER > request.server().size()) {
        FAIL2("peer request", "invalid server", request.server())
    }

    switch (request.type()) {
        case PEERREQUEST_BAILMENT: {
            if (!request.has_bailment()) {
                FAIL("peer request", "missing bailment")
            }

            bool validbailment = Check(
                request.bailment(),
                PeerRequestAllowedBailment.at(request.version()).first,
                PeerRequestAllowedBailment.at(request.version()).second,
                silent);

            if (!validbailment) {
                FAIL("peer request", "invalid bailment")
            }
        } break;
        case PEERREQUEST_OUTBAILMENT: {
            if (!request.has_outbailment()) {
                FAIL("peer request", "missing outbailment")
            }

            bool validoutbailment = Check(
                request.outbailment(),
                PeerRequestAllowedOutBailment.at(request.version()).first,
                PeerRequestAllowedOutBailment.at(request.version()).second,
                silent);

            if (!validoutbailment) {
                FAIL("peer request", "invalid outbailment")
            }
        } break;
        case PEERREQUEST_PENDINGBAILMENT: {
            if (!request.has_pendingbailment()) {
                FAIL("peer request", "missing pendingbailment")
            }

            bool validoutbailment = Check(
                request.pendingbailment(),
                PeerRequestAllowedPendingBailment.at(request.version()).first,
                PeerRequestAllowedPendingBailment.at(request.version()).second,
                silent);

            if (!validoutbailment) {
                FAIL("peer request", "invalid pendingbailment")
            }
        } break;
        case PEERREQUEST_CONNECTIONINFO: {
            if (!request.has_connectioninfo()) {
                FAIL("peer request", "missing connectioninfo")
            }

            bool validconnectioninfo = Check(
                request.connectioninfo(),
                PeerRequestAllowedConnectionInfo.at(request.version()).first,
                PeerRequestAllowedConnectionInfo.at(request.version()).second,
                silent);

            if (!validconnectioninfo) {
                FAIL("peer request", "invalid connectioninfo")
            }
        } break;
        case PEERREQUEST_STORESECRET: {
            if (!request.has_storesecret()) {
                FAIL("peer request", "missing storesecret")
            }

            bool validstoresecret = Check(
                request.storesecret(),
                PeerRequestAllowedStoreSecret.at(request.version()).first,
                PeerRequestAllowedStoreSecret.at(request.version()).second,
                silent);

            if (!validstoresecret) {
                FAIL("peer request", "invalid storesecret")
            }
        } break;
        default: {
        }
    }

    return true;
}
}  // namespace proto
}  // namespace opentxs
