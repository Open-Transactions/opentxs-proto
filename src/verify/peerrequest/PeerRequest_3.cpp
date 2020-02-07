// Copyright (c) 2020 The Open-Transactions developers
// This Source Code Form is subject to the terms of the Mozilla Public
// License, v. 2.0. If a copy of the MPL was not distributed with this
// file, You can obtain one at http://mozilla.org/MPL/2.0/.

#include "opentxs-proto/Types.hpp"
#include "verify/Check.hpp"

#define PROTO_NAME "peer request"

namespace opentxs::proto
{
bool CheckProto_3(const PeerRequest& input, const bool silent)
{
    CHECK_IDENTIFIER(id)
    CHECK_IDENTIFIER(initiator)
    CHECK_IDENTIFIER(recipient)
    CHECK_EXISTS(type)
    CHECK_IDENTIFIER(cookie)
    CHECK_SUBOBJECT_VA(
        signature, PeerRequestAllowedSignature(), SIGROLE_PEERREQUEST)
    CHECK_IDENTIFIER(server)

    switch (input.type()) {
        case PEERREQUEST_BAILMENT: {
            CHECK_EXCLUDED(outbailment)
            CHECK_EXCLUDED(pendingbailment)
            CHECK_EXCLUDED(connectioninfo)
            CHECK_EXCLUDED(storesecret)
            CHECK_EXCLUDED(verificationoffer)
            CHECK_SUBOBJECT(bailment, PeerRequestAllowedBailment())
        } break;
        case PEERREQUEST_OUTBAILMENT: {
            CHECK_EXCLUDED(bailment)
            CHECK_EXCLUDED(pendingbailment)
            CHECK_EXCLUDED(connectioninfo)
            CHECK_EXCLUDED(storesecret)
            CHECK_EXCLUDED(verificationoffer)
            CHECK_SUBOBJECT(outbailment, PeerRequestAllowedOutBailment())
        } break;
        case PEERREQUEST_PENDINGBAILMENT: {
            CHECK_EXCLUDED(bailment)
            CHECK_EXCLUDED(outbailment)
            CHECK_EXCLUDED(connectioninfo)
            CHECK_EXCLUDED(storesecret)
            CHECK_EXCLUDED(verificationoffer)
            CHECK_SUBOBJECT(
                pendingbailment, PeerRequestAllowedPendingBailment())
        } break;
        case PEERREQUEST_CONNECTIONINFO: {
            CHECK_EXCLUDED(bailment)
            CHECK_EXCLUDED(outbailment)
            CHECK_EXCLUDED(pendingbailment)
            CHECK_EXCLUDED(storesecret)
            CHECK_EXCLUDED(verificationoffer)
            CHECK_SUBOBJECT(connectioninfo, PeerRequestAllowedConnectionInfo())
        } break;
        case PEERREQUEST_STORESECRET: {
            CHECK_EXCLUDED(bailment)
            CHECK_EXCLUDED(outbailment)
            CHECK_EXCLUDED(pendingbailment)
            CHECK_EXCLUDED(connectioninfo)
            CHECK_EXCLUDED(verificationoffer)
            CHECK_SUBOBJECT(storesecret, PeerRequestAllowedStoreSecret())
        } break;
        case PEERREQUEST_VERIFICATIONOFFER: {
            CHECK_EXCLUDED(bailment)
            CHECK_EXCLUDED(outbailment)
            CHECK_EXCLUDED(pendingbailment)
            CHECK_EXCLUDED(connectioninfo)
            CHECK_EXCLUDED(storesecret)
            CHECK_SUBOBJECT(
                verificationoffer, PeerRequestAllowedVerificationOffer())
        } break;
        case PEERREQUEST_FAUCET:
        case PEERREQUEST_ERROR:
        default: {
            FAIL_1("invalid type")
        }
    }

    CHECK_EXCLUDED(faucet)

    return true;
}
}  // namespace opentxs::proto
