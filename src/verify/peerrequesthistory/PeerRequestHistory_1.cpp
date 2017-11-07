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
 *       -- Scripted smart paramss.
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

#define PROTO_NAME "peer request history"

namespace opentxs
{
namespace proto
{
bool CheckProto_1(const PeerRequestHistory& input, const bool silent)
{
    switch (input.type()) {
        case PEERREQUEST_BAILMENT:
        case PEERREQUEST_OUTBAILMENT:
        case PEERREQUEST_PENDINGBAILMENT:
        case PEERREQUEST_CONNECTIONINFO:
        case PEERREQUEST_STORESECRET:
        case PEERREQUEST_VERIFICATIONOFFER:
        case PEERREQUEST_FAUCET:
            break;
        default: {
            FAIL(PROTO_NAME, "Unsupported type.")
        }
    }

    CHECK_SUBOBJECTS(workflow, PeerRequestHistoryAllowedPeerRequestWorkflow);

    return true;
}

bool CheckProto_2(const PeerRequestHistory& input, const bool silent)
{
    UNDEFINED_VERSION2(2)
}

bool CheckProto_3(const PeerRequestHistory& input, const bool silent)
{
    UNDEFINED_VERSION2(3)
}

bool CheckProto_4(const PeerRequestHistory& input, const bool silent)
{
    UNDEFINED_VERSION2(4)
}

bool CheckProto_5(const PeerRequestHistory& input, const bool silent)
{
    UNDEFINED_VERSION2(5)
}
}  // namespace proto
}  // namespace opentxs
