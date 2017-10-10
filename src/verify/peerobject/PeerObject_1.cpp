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

bool CheckProto_1(const PeerObject& peerObject, const bool silent)
{
    if (!peerObject.has_type()) {
        FAIL("peer object", "missing type")
    }

    if ((peerObject.type() < PEEROBJECT_MESSAGE) ||
        (peerObject.type() > PEEROBJECT_RESPONSE)) {
        FAIL("peer object", "invalid type")
    }

    switch (peerObject.type()) {
        case PEEROBJECT_MESSAGE: {
            if (!peerObject.has_otmessage()) {
                FAIL("peer object", "missing otmessage")
            }

            if (peerObject.has_otrequest()) {
                FAIL("peer object", "otrequest not empty")
            }

            if (peerObject.has_otreply()) {
                FAIL("peer object", "otreply not empty")
            }
        } break;
        case PEEROBJECT_REQUEST: {
            if (!peerObject.has_otrequest()) {
                FAIL("peer object", "missing otrequest")
            }

            try {
                const bool validrequest = Check(
                    peerObject.otrequest(),
                    PeerObjectAllowedRequest.at(peerObject.version()).first,
                    PeerObjectAllowedRequest.at(peerObject.version()).second,
                    silent);

                if (!validrequest) {
                    FAIL("peer object", "invalid otrequest")
                }
            } catch (const std::out_of_range&) {
                FAIL2(
                    "peer object",
                    "allowed peer request version not defined for version",
                    peerObject.version())
            }

            if (!peerObject.has_nym()) {
                FAIL("peer object", " missing nym")
            }

            try {
                const bool validnym = Check(
                    peerObject.nym(),
                    PeerObjectAllowedCredentialIndex.at(peerObject.version())
                        .first,
                    PeerObjectAllowedCredentialIndex.at(peerObject.version())
                        .second,
                    silent);

                if (!validnym) {
                    FAIL("peer object", "invalid nym")
                }
            } catch (const std::out_of_range&) {
                FAIL2(
                    "peer object",
                    "allowed credential index version not defined for version",
                    peerObject.version())
            }

            if (peerObject.has_otmessage()) {
                FAIL("peer object", "otmessage not empty")
            }

            if (peerObject.has_otreply()) {
                FAIL("peer object", "otreply not empty")
            }
        } break;
        case PEEROBJECT_RESPONSE: {
            if (!peerObject.has_otrequest()) {
                FAIL("peer object", "missing otrequest")
            }

            try {
                const bool validrequest = Check(
                    peerObject.otrequest(),
                    PeerObjectAllowedRequest.at(peerObject.version()).first,
                    PeerObjectAllowedRequest.at(peerObject.version()).second,
                    silent);

                if (!validrequest) {
                    FAIL("peer object", "invalid otrequest")
                }
            } catch (const std::out_of_range&) {
                FAIL2(
                    "peer object",
                    "allowed peer request version not defined for version",
                    peerObject.version())
            }

            if (!peerObject.has_otreply()) {
                FAIL("peer object", "missing otreply")
            }

            try {
                const bool validreply = Check(
                    peerObject.otreply(),
                    PeerObjectAllowedReply.at(peerObject.version()).first,
                    PeerObjectAllowedReply.at(peerObject.version()).second,
                    silent);

                if (!validreply) {
                    FAIL("peer object", "invalid otreply")
                }
            } catch (const std::out_of_range&) {
                FAIL2(
                    "peer object",
                    "allowed peer reply version not defined for version",
                    peerObject.version())
            }

            const bool matchingID =
                (peerObject.otrequest().id() == peerObject.otreply().cookie());

            if (!matchingID) {
                FAIL("peer object", "reply cookie does not match request id")
            }

            const bool matchingtype =
                (peerObject.otrequest().type() == peerObject.otreply().type());

            if (!matchingtype) {
                FAIL("peer object", "eply type does not match request type")
            }

            const bool matchingInitiator =
                (peerObject.otrequest().initiator() ==
                 peerObject.otreply().initiator());

            if (!matchingInitiator) {
                FAIL(
                    "peer object",
                    "reply initiator does not match request initiator")
            }

            const bool matchingRecipient =
                (peerObject.otrequest().recipient() ==
                 peerObject.otreply().recipient());

            if (!matchingRecipient) {
                FAIL(
                    "peer object",
                    "reply recipient does not match request recipient")
            }

            if (peerObject.has_otmessage()) {
                FAIL("peer object", "otmessage not empty")
            }
        } break;
        default: {
        }
    }

    return true;
}
bool CheckProto_2(const PeerObject& object, const bool silent)
{
    return CheckProto_1(object, silent);
}
bool CheckProto_3(const PeerObject& object, const bool silent)
{
    return CheckProto_1(object, silent);
}

bool CheckProto_4(const PeerObject&, const bool silent)
{
    UNDEFINED_VERSION("peer object", 4)
}

bool CheckProto_5(const PeerObject&, const bool silent)
{
    UNDEFINED_VERSION("peer object", 5)
}
}  // namespace proto
}  // namespace opentxs
