// Copyright (c) 2020 The Open-Transactions developers
// This Source Code Form is subject to the terms of the Mozilla Public
// License, v. 2.0. If a copy of the MPL was not distributed with this
// file, You can obtain one at http://mozilla.org/MPL/2.0/.

#include "opentxs-proto/Types.hpp"
#include "verify/Check.hpp"

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
    if (VerificationType::Indexed == indexed) {
        if (!input.has_id()) { FAIL_1("missing ID") }

        if (MIN_PLAUSIBLE_IDENTIFIER > input.id().size()) {
            FAIL_1("invalid ID")
        }
    } else {
        if (input.has_id()) { FAIL_1("ID field not empty") }
    }

    if (!input.has_claim()) { FAIL_1("missing claim") }

    if (MIN_PLAUSIBLE_IDENTIFIER > input.claim().size()) {
        FAIL_1("invalid claim")
    }

    if (!input.has_valid()) { FAIL_1("missing validity") }

    if (!input.has_start()) { FAIL_1("missing start time") }

    if (!input.has_end()) { FAIL_1("missing end time") }

    if (input.end() < input.start()) { FAIL_1("invalid end time") }

    if (!input.has_sig()) { FAIL_1("missing signature") }

    try {
        const bool validSignature = Check(
            input.sig(),
            VerificationAllowedSignature().at(input.version()).first,
            VerificationAllowedSignature().at(input.version()).second,
            silent,
            proto::SIGROLE_CLAIM);

        if (!validSignature) { FAIL_1("invalid signature") }
    } catch (const std::out_of_range&) {
        FAIL_2(
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
    UNDEFINED_VERSION(2)
}

bool CheckProto_3(
    const Verification& input,
    const bool silent,
    const VerificationType)
{
    UNDEFINED_VERSION(3)
}

bool CheckProto_4(
    const Verification& input,
    const bool silent,
    const VerificationType)
{
    UNDEFINED_VERSION(4)
}

bool CheckProto_5(
    const Verification& input,
    const bool silent,
    const VerificationType)
{
    UNDEFINED_VERSION(5)
}

bool CheckProto_6(
    const Verification& input,
    const bool silent,
    const VerificationType)
{
    UNDEFINED_VERSION(6)
}

bool CheckProto_7(
    const Verification& input,
    const bool silent,
    const VerificationType)
{
    UNDEFINED_VERSION(7)
}

bool CheckProto_8(
    const Verification& input,
    const bool silent,
    const VerificationType)
{
    UNDEFINED_VERSION(8)
}

bool CheckProto_9(
    const Verification& input,
    const bool silent,
    const VerificationType)
{
    UNDEFINED_VERSION(9)
}

bool CheckProto_10(
    const Verification& input,
    const bool silent,
    const VerificationType)
{
    UNDEFINED_VERSION(10)
}

bool CheckProto_11(
    const Verification& input,
    const bool silent,
    const VerificationType)
{
    UNDEFINED_VERSION(11)
}

bool CheckProto_12(
    const Verification& input,
    const bool silent,
    const VerificationType)
{
    UNDEFINED_VERSION(12)
}

bool CheckProto_13(
    const Verification& input,
    const bool silent,
    const VerificationType)
{
    UNDEFINED_VERSION(13)
}

bool CheckProto_14(
    const Verification& input,
    const bool silent,
    const VerificationType)
{
    UNDEFINED_VERSION(14)
}

bool CheckProto_15(
    const Verification& input,
    const bool silent,
    const VerificationType)
{
    UNDEFINED_VERSION(15)
}

bool CheckProto_16(
    const Verification& input,
    const bool silent,
    const VerificationType)
{
    UNDEFINED_VERSION(16)
}

bool CheckProto_17(
    const Verification& input,
    const bool silent,
    const VerificationType)
{
    UNDEFINED_VERSION(17)
}

bool CheckProto_18(
    const Verification& input,
    const bool silent,
    const VerificationType)
{
    UNDEFINED_VERSION(18)
}

bool CheckProto_19(
    const Verification& input,
    const bool silent,
    const VerificationType)
{
    UNDEFINED_VERSION(19)
}

bool CheckProto_20(
    const Verification& input,
    const bool silent,
    const VerificationType)
{
    UNDEFINED_VERSION(20)
}
}  // namespace proto
}  // namespace opentxs
