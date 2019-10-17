// Copyright (c) 2019 The Open-Transactions developers
// This Source Code Form is subject to the terms of the Mozilla Public
// License, v. 2.0. If a copy of the MPL was not distributed with this
// file, You can obtain one at http://mozilla.org/MPL/2.0/.

#include "opentxs-proto/Types.hpp"
#include "verify/Check.hpp"

#define PROTO_NAME "verification offer"

namespace opentxs
{
namespace proto
{
bool CheckProto_1(const VerificationOffer& input, const bool silent)
{
    UNDEFINED_VERSION(1)
}

bool CheckProto_2(const VerificationOffer& input, const bool silent)
{
    UNDEFINED_VERSION(2)
}

bool CheckProto_3(const VerificationOffer& input, const bool silent)
{
    if (!input.has_offeringnym()) { FAIL_1("missing sender nym id") }

    if (MIN_PLAUSIBLE_IDENTIFIER > input.offeringnym().size()) {
        FAIL_1("invalid sender nym id")
    }

    if (MAX_PLAUSIBLE_IDENTIFIER < input.offeringnym().size()) {
        FAIL_1("invalid sender nym id")
    }

    if (!input.has_recipientnym()) { FAIL_1("missing recipient nym id") }

    if (MIN_PLAUSIBLE_IDENTIFIER > input.recipientnym().size()) {
        FAIL_1("invalid recipient nym id")
    }

    if (MAX_PLAUSIBLE_IDENTIFIER < input.recipientnym().size()) {
        FAIL_1("invalid recipient nym id")
    }

    try {
        const bool validClaim = Check(
            input.claim(),
            VerificationOfferAllowedClaim.at(input.version()).first,
            VerificationOfferAllowedClaim.at(input.version()).second,
            silent);

        if (!validClaim) { FAIL_1("invalid claim") }
    } catch (const std::out_of_range&) {
        FAIL_2("allowed claim version not defined for version", input.version())
    }

    if (input.claim().nymid() != input.recipientnym()) {
        FAIL_1("claim nym does not match recipient nym")
    }

    try {
        const bool validVerification = Check(
            input.verification(),
            VerificationOfferAllowedVerification.at(input.version()).first,
            VerificationOfferAllowedVerification.at(input.version()).second,
            silent,
            VERIFICATIONS_NORMAL);

        if (!validVerification) { FAIL_1("invalid verification") }
    } catch (const std::out_of_range&) {
        FAIL_2(
            "allowed verification version not defined for version",
            input.version())
    }

    return true;
}

bool CheckProto_4(const VerificationOffer& input, const bool silent)
{
    return CheckProto_3(input, silent);
}

bool CheckProto_5(const VerificationOffer& input, const bool silent)
{
    UNDEFINED_VERSION(5)
}

bool CheckProto_6(const VerificationOffer& input, const bool silent)
{
    UNDEFINED_VERSION(6)
}

bool CheckProto_7(const VerificationOffer& input, const bool silent)
{
    UNDEFINED_VERSION(7)
}

bool CheckProto_8(const VerificationOffer& input, const bool silent)
{
    UNDEFINED_VERSION(8)
}

bool CheckProto_9(const VerificationOffer& input, const bool silent)
{
    UNDEFINED_VERSION(9)
}

bool CheckProto_10(const VerificationOffer& input, const bool silent)
{
    UNDEFINED_VERSION(10)
}

bool CheckProto_11(const VerificationOffer& input, const bool silent)
{
    UNDEFINED_VERSION(11)
}

bool CheckProto_12(const VerificationOffer& input, const bool silent)
{
    UNDEFINED_VERSION(12)
}

bool CheckProto_13(const VerificationOffer& input, const bool silent)
{
    UNDEFINED_VERSION(13)
}

bool CheckProto_14(const VerificationOffer& input, const bool silent)
{
    UNDEFINED_VERSION(14)
}

bool CheckProto_15(const VerificationOffer& input, const bool silent)
{
    UNDEFINED_VERSION(15)
}

bool CheckProto_16(const VerificationOffer& input, const bool silent)
{
    UNDEFINED_VERSION(16)
}

bool CheckProto_17(const VerificationOffer& input, const bool silent)
{
    UNDEFINED_VERSION(17)
}

bool CheckProto_18(const VerificationOffer& input, const bool silent)
{
    UNDEFINED_VERSION(18)
}

bool CheckProto_19(const VerificationOffer& input, const bool silent)
{
    UNDEFINED_VERSION(19)
}

bool CheckProto_20(const VerificationOffer& input, const bool silent)
{
    UNDEFINED_VERSION(20)
}
}  // namespace proto
}  // namespace opentxs
