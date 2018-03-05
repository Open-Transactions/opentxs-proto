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

#define PROTO_NAME "peer request"

namespace opentxs::proto
{
bool CheckProto_4(const PeerRequest& input, const bool silent)
{
    CHECK_IDENTIFIER(id)
    CHECK_IDENTIFIER(initiator)
    CHECK_IDENTIFIER(recipient)
    CHECK_EXISTS(type)
    CHECK_IDENTIFIER(cookie)
    CHECK_SUBOBJECT2(
        signature, PeerRequestAllowedSignature, ", SIGROLE_PEERREQUEST")
    CHECK_IDENTIFIER(server)

    switch (input.type()) {
        case PEERREQUEST_BAILMENT: {
            CHECK_EXCLUDED(outbailment)
            CHECK_EXCLUDED(pendingbailment)
            CHECK_EXCLUDED(connectioninfo)
            CHECK_EXCLUDED(storesecret)
            CHECK_EXCLUDED(verificationoffer)
            CHECK_EXCLUDED(faucet)
            CHECK_SUBOBJECT(bailment, PeerRequestAllowedBailment)
        } break;
        case PEERREQUEST_OUTBAILMENT: {
            CHECK_EXCLUDED(bailment)
            CHECK_EXCLUDED(pendingbailment)
            CHECK_EXCLUDED(connectioninfo)
            CHECK_EXCLUDED(storesecret)
            CHECK_EXCLUDED(verificationoffer)
            CHECK_EXCLUDED(faucet)
            CHECK_SUBOBJECT(outbailment, PeerRequestAllowedOutBailment)
        } break;
        case PEERREQUEST_PENDINGBAILMENT: {
            CHECK_EXCLUDED(bailment)
            CHECK_EXCLUDED(outbailment)
            CHECK_EXCLUDED(connectioninfo)
            CHECK_EXCLUDED(storesecret)
            CHECK_EXCLUDED(verificationoffer)
            CHECK_EXCLUDED(faucet)
            CHECK_SUBOBJECT(pendingbailment, PeerRequestAllowedPendingBailment)
        } break;
        case PEERREQUEST_CONNECTIONINFO: {
            CHECK_EXCLUDED(bailment)
            CHECK_EXCLUDED(outbailment)
            CHECK_EXCLUDED(pendingbailment)
            CHECK_EXCLUDED(storesecret)
            CHECK_EXCLUDED(verificationoffer)
            CHECK_EXCLUDED(faucet)
            CHECK_SUBOBJECT(connectioninfo, PeerRequestAllowedConnectionInfo)
        } break;
        case PEERREQUEST_STORESECRET: {
            CHECK_EXCLUDED(bailment)
            CHECK_EXCLUDED(outbailment)
            CHECK_EXCLUDED(pendingbailment)
            CHECK_EXCLUDED(connectioninfo)
            CHECK_EXCLUDED(verificationoffer)
            CHECK_EXCLUDED(faucet)
            CHECK_SUBOBJECT(storesecret, PeerRequestAllowedStoreSecret)
        } break;
        case PEERREQUEST_VERIFICATIONOFFER: {
            CHECK_EXCLUDED(bailment)
            CHECK_EXCLUDED(outbailment)
            CHECK_EXCLUDED(pendingbailment)
            CHECK_EXCLUDED(connectioninfo)
            CHECK_EXCLUDED(storesecret)
            CHECK_EXCLUDED(faucet)
            CHECK_SUBOBJECT(
                verificationoffer, PeerRequestAllowedVerificationOffer)
        } break;
        case PEERREQUEST_FAUCET: {
            CHECK_EXCLUDED(bailment)
            CHECK_EXCLUDED(outbailment)
            CHECK_EXCLUDED(pendingbailment)
            CHECK_EXCLUDED(connectioninfo)
            CHECK_EXCLUDED(storesecret)
            CHECK_EXCLUDED(verificationoffer)
            CHECK_SUBOBJECT(faucet, PeerRequestAllowedFaucet)
        } break;
        default: {
            FAIL4("invalid type")
        }
    }

    return true;
}

bool CheckProto_5(const PeerRequest& input, const bool silent)
{
    return CheckProto_4(input, silent);
}

bool CheckProto_6(const PeerRequest& input, const bool silent)
{
    return CheckProto_4(input, silent);
}

bool CheckProto_7(const PeerRequest& input, const bool silent)
{
    UNDEFINED_VERSION2(7)
}

bool CheckProto_8(const PeerRequest& input, const bool silent)
{
    UNDEFINED_VERSION2(8)
}

bool CheckProto_9(const PeerRequest& input, const bool silent)
{
    UNDEFINED_VERSION2(9)
}

bool CheckProto_10(const PeerRequest& input, const bool silent)
{
    UNDEFINED_VERSION2(10)
}

bool CheckProto_11(const PeerRequest& input, const bool silent)
{
    UNDEFINED_VERSION2(11)
}

bool CheckProto_12(const PeerRequest& input, const bool silent)
{
    UNDEFINED_VERSION2(12)
}

bool CheckProto_13(const PeerRequest& input, const bool silent)
{
    UNDEFINED_VERSION2(13)
}

bool CheckProto_14(const PeerRequest& input, const bool silent)
{
    UNDEFINED_VERSION2(14)
}

bool CheckProto_15(const PeerRequest& input, const bool silent)
{
    UNDEFINED_VERSION2(15)
}

bool CheckProto_16(const PeerRequest& input, const bool silent)
{
    UNDEFINED_VERSION2(16)
}

bool CheckProto_17(const PeerRequest& input, const bool silent)
{
    UNDEFINED_VERSION2(17)
}

bool CheckProto_18(const PeerRequest& input, const bool silent)
{
    UNDEFINED_VERSION2(18)
}

bool CheckProto_19(const PeerRequest& input, const bool silent)
{
    UNDEFINED_VERSION2(19)
}

bool CheckProto_20(const PeerRequest& input, const bool silent)
{
    UNDEFINED_VERSION2(20)
}
}  // namespace opentxs::proto
