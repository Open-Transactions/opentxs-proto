// Copyright (c) 2018 The Open-Transactions developers
// This Source Code Form is subject to the terms of the Mozilla Public
// License, v. 2.0. If a copy of the MPL was not distributed with this
// file, You can obtain one at http://mozilla.org/MPL/2.0/.

#include "opentxs-proto/Types.hpp"
#include "opentxs-proto/Check.hpp"

#include <iostream>

#define PROTO_NAME "verification"

namespace opentxs
{
namespace proto
{

bool CheckProto_1(
    const Verification& input,
    const bool silent,
    const VerificationType indexed)
{
    if (indexed) {
        if (!input.has_id()) {
            FAIL("verification", "missing ID")
        }

        if (MIN_PLAUSIBLE_IDENTIFIER > input.id().size()) {
            FAIL("verification", "invalid ID")
        }
    } else {
        if (input.has_id()) {
            FAIL("verification", "ID field not empty")
        }
    }

    if (!input.has_claim()) {
        FAIL("verification", "missing claim")
    }

    if (MIN_PLAUSIBLE_IDENTIFIER > input.claim().size()) {
        FAIL("verification", "invalid claim")
    }

    if (!input.has_valid()) {
        FAIL("verification", "missing validity")
    }

    if (!input.has_start()) {
        FAIL("verification", "missing start time")
    }

    if (!input.has_end()) {
        FAIL("verification", "missing end time")
    }

    if (input.end() < input.start()) {
        FAIL("verification", "invalid end time")
    }

    if (!input.has_sig()) {
        FAIL("verification", "missing signature")
    }

    try {
        const bool validSignature = Check(
            input.sig(),
            VerificationAllowedSignature.at(input.version()).first,
            VerificationAllowedSignature.at(input.version()).second,
            silent,
            proto::SIGROLE_CLAIM);

        if (!validSignature) {
            FAIL("verification", "invalid signature")
        }
    } catch (const std::out_of_range&) {
        FAIL2(
            "verification",
            "allowed signature version not defined for version",
            input.version())
    }

    return true;
}

bool CheckProto_2(
    const Verification& input,
    const bool silent,
    const VerificationType)
{
    UNDEFINED_VERSION("verification", 2)
}

bool CheckProto_3(
    const Verification& input,
    const bool silent,
    const VerificationType)
{
    UNDEFINED_VERSION("verification", 3)
}

bool CheckProto_4(
    const Verification& input,
    const bool silent,
    const VerificationType)
{
    UNDEFINED_VERSION("verification", 4)
}

bool CheckProto_5(
    const Verification& input,
    const bool silent,
    const VerificationType)
{
    UNDEFINED_VERSION("verification", 5)
}

bool CheckProto_6(
    const Verification& input,
    const bool silent,
    const VerificationType)
{
    UNDEFINED_VERSION2(6)
}

bool CheckProto_7(
    const Verification& input,
    const bool silent,
    const VerificationType)
{
    UNDEFINED_VERSION2(7)
}

bool CheckProto_8(
    const Verification& input,
    const bool silent,
    const VerificationType)
{
    UNDEFINED_VERSION2(8)
}

bool CheckProto_9(
    const Verification& input,
    const bool silent,
    const VerificationType)
{
    UNDEFINED_VERSION2(9)
}

bool CheckProto_10(
    const Verification& input,
    const bool silent,
    const VerificationType)
{
    UNDEFINED_VERSION2(10)
}

bool CheckProto_11(
    const Verification& input,
    const bool silent,
    const VerificationType)
{
    UNDEFINED_VERSION2(11)
}

bool CheckProto_12(
    const Verification& input,
    const bool silent,
    const VerificationType)
{
    UNDEFINED_VERSION2(12)
}

bool CheckProto_13(
    const Verification& input,
    const bool silent,
    const VerificationType)
{
    UNDEFINED_VERSION2(13)
}

bool CheckProto_14(
    const Verification& input,
    const bool silent,
    const VerificationType)
{
    UNDEFINED_VERSION2(14)
}

bool CheckProto_15(
    const Verification& input,
    const bool silent,
    const VerificationType)
{
    UNDEFINED_VERSION2(15)
}

bool CheckProto_16(
    const Verification& input,
    const bool silent,
    const VerificationType)
{
    UNDEFINED_VERSION2(16)
}

bool CheckProto_17(
    const Verification& input,
    const bool silent,
    const VerificationType)
{
    UNDEFINED_VERSION2(17)
}

bool CheckProto_18(
    const Verification& input,
    const bool silent,
    const VerificationType)
{
    UNDEFINED_VERSION2(18)
}

bool CheckProto_19(
    const Verification& input,
    const bool silent,
    const VerificationType)
{
    UNDEFINED_VERSION2(19)
}

bool CheckProto_20(
    const Verification& input,
    const bool silent,
    const VerificationType)
{
    UNDEFINED_VERSION2(20)
}
}  // namespace proto
}  // namespace opentxs
