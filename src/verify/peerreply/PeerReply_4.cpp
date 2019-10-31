// Copyright (c) 2019 The Open-Transactions developers
// This Source Code Form is subject to the terms of the Mozilla Public
// License, v. 2.0. If a copy of the MPL was not distributed with this
// file, You can obtain one at http://mozilla.org/MPL/2.0/.

#include "opentxs-proto/Types.hpp"
#include "verify/Check.hpp"

#define PROTO_NAME "peer reply"

namespace opentxs
{
namespace proto
{
bool CheckProto_4(const PeerReply& input, const bool silent)
{
    if (!input.has_id()) { FAIL_1("missing id") }

    if (MIN_PLAUSIBLE_IDENTIFIER > input.id().size()) { FAIL_1("invalid id") }

    if (!input.has_initiator()) { FAIL_1("missing initiator") }

    if (MIN_PLAUSIBLE_IDENTIFIER > input.initiator().size()) {
        FAIL_2("invalid initiator", input.initiator())
    }

    if (!input.has_recipient()) { FAIL_1("missing recipient") }

    if (MIN_PLAUSIBLE_IDENTIFIER > input.recipient().size()) {
        FAIL_2("invalid recipient", input.recipient())
    }

    if (!input.has_type()) { FAIL_1("missing type") }

    if (!input.has_cookie()) { FAIL_1("missing cookie") }

    try {
        const bool validSig = Check(
            input.signature(),
            PeerReplyAllowedSignature().at(input.version()).first,
            PeerReplyAllowedSignature().at(input.version()).second,
            silent,
            SIGROLE_PEERREPLY);

        if (!validSig) { FAIL_1("invalid signature") }
    } catch (const std::out_of_range&) {
        FAIL_2(
            "allowed signature version not defined for version",
            input.version())
    }

    if (!input.has_server()) { FAIL_1("missing server") }

    if (MIN_PLAUSIBLE_IDENTIFIER > input.server().size()) {
        FAIL_2("invalid server", input.server())
    }

    switch (input.type()) {
        case PEERREQUEST_BAILMENT: {
            if (!input.has_bailment()) { FAIL_1("missing bailment") }

            try {
                const bool validbailment = Check(
                    input.bailment(),
                    PeerReplyAllowedBailment().at(input.version()).first,
                    PeerReplyAllowedBailment().at(input.version()).second,
                    silent);

                if (!validbailment) { FAIL_1("invalid bailment") }
            } catch (const std::out_of_range&) {
                FAIL_2(
                    "allowed bailment version not defined for version",
                    input.version())
            }
        } break;
        case PEERREQUEST_OUTBAILMENT: {
            if (!input.has_outbailment()) { FAIL_1("missing outbailment") }

            try {
                const bool validoutbailment = Check(
                    input.outbailment(),
                    PeerReplyAllowedOutBailment().at(input.version()).first,
                    PeerReplyAllowedOutBailment().at(input.version()).second,
                    silent);

                if (!validoutbailment) { FAIL_1("invalid outbailment") }
            } catch (const std::out_of_range&) {
                FAIL_2(
                    "allowed outbailment version not defined for version",
                    input.version())
            }
        } break;
        case PEERREQUEST_PENDINGBAILMENT:
        case PEERREQUEST_STORESECRET:
        case PEERREQUEST_VERIFICATIONOFFER:
        case PEERREQUEST_FAUCET: {
            if (!input.has_notice()) { FAIL_1("missing notice") }

            try {
                const bool validnotice = Check(
                    input.notice(),
                    PeerReplyAllowedNotice().at(input.version()).first,
                    PeerReplyAllowedNotice().at(input.version()).second,
                    silent);

                if (!validnotice) { FAIL_1("invalid notice") }
            } catch (const std::out_of_range&) {
                FAIL_2(
                    "allowed peer notice version not defined for version",
                    input.version())
            }
        } break;
        case PEERREQUEST_CONNECTIONINFO: {
            if (!input.has_connectioninfo()) {
                FAIL_1("missing connectioninfo")
            }

            try {
                const bool validconnectioninfo = Check(
                    input.connectioninfo(),
                    PeerReplyAllowedConnectionInfo().at(input.version()).first,
                    PeerReplyAllowedConnectionInfo().at(input.version()).second,
                    silent);

                if (!validconnectioninfo) { FAIL_1("invalid connectioninfo") }
            } catch (const std::out_of_range&) {
                FAIL_2(
                    "allowed connection info version not defined for version",
                    input.version())
            }
        } break;
        case PEERREQUEST_ERROR:
        default: {
            FAIL_1("invalid type")
        }
    }

    return true;
}

bool CheckProto_5(const PeerReply& input, const bool silent)
{
    UNDEFINED_VERSION(5)
}

bool CheckProto_6(const PeerReply& input, const bool silent)
{
    UNDEFINED_VERSION(6)
}

bool CheckProto_7(const PeerReply& input, const bool silent)
{
    UNDEFINED_VERSION(7)
}

bool CheckProto_8(const PeerReply& input, const bool silent)
{
    UNDEFINED_VERSION(8)
}

bool CheckProto_9(const PeerReply& input, const bool silent)
{
    UNDEFINED_VERSION(9)
}

bool CheckProto_10(const PeerReply& input, const bool silent)
{
    UNDEFINED_VERSION(10)
}

bool CheckProto_11(const PeerReply& input, const bool silent)
{
    UNDEFINED_VERSION(11)
}

bool CheckProto_12(const PeerReply& input, const bool silent)
{
    UNDEFINED_VERSION(12)
}

bool CheckProto_13(const PeerReply& input, const bool silent)
{
    UNDEFINED_VERSION(13)
}

bool CheckProto_14(const PeerReply& input, const bool silent)
{
    UNDEFINED_VERSION(14)
}

bool CheckProto_15(const PeerReply& input, const bool silent)
{
    UNDEFINED_VERSION(15)
}

bool CheckProto_16(const PeerReply& input, const bool silent)
{
    UNDEFINED_VERSION(16)
}

bool CheckProto_17(const PeerReply& input, const bool silent)
{
    UNDEFINED_VERSION(17)
}

bool CheckProto_18(const PeerReply& input, const bool silent)
{
    UNDEFINED_VERSION(18)
}

bool CheckProto_19(const PeerReply& input, const bool silent)
{
    UNDEFINED_VERSION(19)
}

bool CheckProto_20(const PeerReply& input, const bool silent)
{
    UNDEFINED_VERSION(20)
}
}  // namespace proto
}  // namespace opentxs
