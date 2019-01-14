// Copyright (c) 2018 The Open-Transactions developers
// This Source Code Form is subject to the terms of the Mozilla Public
// License, v. 2.0. If a copy of the MPL was not distributed with this
// file, You can obtain one at http://mozilla.org/MPL/2.0/.

#include "opentxs-proto/Types.hpp"
#include "opentxs-proto/Check.hpp"

#define PROTO_NAME "peer object"

namespace opentxs::proto
{
bool CheckProto_7(const PeerObject& input, const bool silent)
{
    if (!input.has_type()) { FAIL_1("missing type") }

    switch (input.type()) {
        case PEEROBJECT_MESSAGE: {
            CHECK_EXISTS(otmessage);
            CHECK_EXCLUDED(otrequest);
            CHECK_EXCLUDED(otreply);
            CHECK_EXCLUDED(otpayment);
            CHECK_EXCLUDED(purse);
            OPTIONAL_SUBOBJECT(nym, PeerObjectAllowedCredentialIndex);
        } break;
        case PEEROBJECT_REQUEST: {
            CHECK_EXCLUDED(otmessage);
            CHECK_SUBOBJECT(otrequest, PeerObjectAllowedPeerRequest);
            CHECK_EXCLUDED(otreply);
            CHECK_EXCLUDED(otpayment);
            CHECK_EXCLUDED(purse);
            CHECK_SUBOBJECT(nym, PeerObjectAllowedCredentialIndex);
        } break;
        case PEEROBJECT_RESPONSE: {
            CHECK_EXCLUDED(otmessage);
            CHECK_SUBOBJECT(otrequest, PeerObjectAllowedPeerRequest);
            CHECK_SUBOBJECT(otreply, PeerObjectAllowedPeerReply);
            CHECK_EXCLUDED(otpayment);
            CHECK_EXCLUDED(purse);
            OPTIONAL_SUBOBJECT(nym, PeerObjectAllowedCredentialIndex);

            const bool matchingID =
                (input.otrequest().id() == input.otreply().cookie());

            if (!matchingID) {
                FAIL_1("reply cookie does not match request id")
            }

            const bool matchingtype =
                (input.otrequest().type() == input.otreply().type());

            if (!matchingtype) {
                FAIL_1("reply type does not match request type")
            }

            const bool matchingInitiator =
                (input.otrequest().initiator() == input.otreply().initiator());

            if (!matchingInitiator) {
                FAIL_1("reply initiator does not match request initiator")
            }

            const bool matchingRecipient =
                (input.otrequest().recipient() == input.otreply().recipient());

            if (!matchingRecipient) {
                FAIL_1("reply recipient does not match request recipient")
            }
        } break;
        case PEEROBJECT_PAYMENT: {
            CHECK_EXCLUDED(otmessage);
            CHECK_EXCLUDED(otrequest);
            CHECK_EXCLUDED(otreply);
            CHECK_EXISTS(otpayment);
            CHECK_EXCLUDED(purse);
            OPTIONAL_SUBOBJECT(nym, PeerObjectAllowedCredentialIndex);
        } break;
        case PEEROBJECT_CASH: {
            CHECK_EXCLUDED(otmessage);
            CHECK_EXCLUDED(otrequest);
            CHECK_EXCLUDED(otreply);
            CHECK_EXCLUDED(otpayment);
            CHECK_SUBOBJECT(purse, PeerObjectAllowedPurse);
            OPTIONAL_SUBOBJECT(nym, PeerObjectAllowedCredentialIndex);
        } break;
        default: {
            FAIL_1("invalid type")
        }
    }

    return true;
}

bool CheckProto_8(const PeerObject& input, const bool silent)
{
    UNDEFINED_VERSION(8)
}

bool CheckProto_9(const PeerObject& input, const bool silent)
{
    UNDEFINED_VERSION(9)
}

bool CheckProto_10(const PeerObject& input, const bool silent)
{
    UNDEFINED_VERSION(10)
}

bool CheckProto_11(const PeerObject& input, const bool silent)
{
    UNDEFINED_VERSION(11)
}

bool CheckProto_12(const PeerObject& input, const bool silent)
{
    UNDEFINED_VERSION(12)
}

bool CheckProto_13(const PeerObject& input, const bool silent)
{
    UNDEFINED_VERSION(13)
}

bool CheckProto_14(const PeerObject& input, const bool silent)
{
    UNDEFINED_VERSION(14)
}

bool CheckProto_15(const PeerObject& input, const bool silent)
{
    UNDEFINED_VERSION(15)
}

bool CheckProto_16(const PeerObject& input, const bool silent)
{
    UNDEFINED_VERSION(16)
}

bool CheckProto_17(const PeerObject& input, const bool silent)
{
    UNDEFINED_VERSION(17)
}

bool CheckProto_18(const PeerObject& input, const bool silent)
{
    UNDEFINED_VERSION(18)
}

bool CheckProto_19(const PeerObject& input, const bool silent)
{
    UNDEFINED_VERSION(19)
}

bool CheckProto_20(const PeerObject& input, const bool silent)
{
    UNDEFINED_VERSION(20)
}
}  // namespace opentxs::proto
