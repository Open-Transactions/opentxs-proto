// Copyright (c) 2018 The Open-Transactions developers
// This Source Code Form is subject to the terms of the Mozilla Public
// License, v. 2.0. If a copy of the MPL was not distributed with this
// file, You can obtain one at http://mozilla.org/MPL/2.0/.

#include "opentxs-proto/Types.hpp"
#include "opentxs-proto/Check.hpp"

#define PROTO_NAME "verification set"

namespace opentxs
{
namespace proto
{

bool CheckProto_1(
    const VerificationSet& input,
    const bool silent,
    const VerificationType indexed)
{
    if (input.has_internal()) {
        try {
            const bool validInternal = Check(
                input.internal(),
                VerificationSetAllowedGroup.at(input.version()).first,
                VerificationSetAllowedGroup.at(input.version()).second,
                silent,
                indexed);

            if (!validInternal) { FAIL_1("invalid internal group") }
        } catch (const std::out_of_range&) {
            FAIL_2(
                "allowed verification group version not defined for version",
                input.version())
        }
    }

    if (input.has_external()) {
        try {
            const bool validExternal = Check(
                input.external(),
                VerificationSetAllowedGroup.at(input.version()).first,
                VerificationSetAllowedGroup.at(input.version()).second,
                silent,
                indexed);

            if (!validExternal) { FAIL_1("invalid external group") }
        } catch (const std::out_of_range&) {
            FAIL_2(
                "allowed verification group version not defined for version",
                input.version())
        }
    }

    for (auto& it : input.repudiated()) {
        if (MIN_PLAUSIBLE_IDENTIFIER < it.size()) {
            FAIL_1("invalid repudiation")
        }
    }

    return true;
}

bool CheckProto_2(
    const VerificationSet& input,
    const bool silent,
    const VerificationType)
{
    UNDEFINED_VERSION(2)
}

bool CheckProto_3(
    const VerificationSet& input,
    const bool silent,
    const VerificationType)
{
    UNDEFINED_VERSION(3)
}

bool CheckProto_4(
    const VerificationSet& input,
    const bool silent,
    const VerificationType)
{
    UNDEFINED_VERSION(4)
}

bool CheckProto_5(
    const VerificationSet& input,
    const bool silent,
    const VerificationType)
{
    UNDEFINED_VERSION(5)
}

bool CheckProto_6(
    const VerificationSet& input,
    const bool silent,
    const VerificationType)
{
    UNDEFINED_VERSION(6)
}

bool CheckProto_7(
    const VerificationSet& input,
    const bool silent,
    const VerificationType)
{
    UNDEFINED_VERSION(7)
}

bool CheckProto_8(
    const VerificationSet& input,
    const bool silent,
    const VerificationType)
{
    UNDEFINED_VERSION(8)
}

bool CheckProto_9(
    const VerificationSet& input,
    const bool silent,
    const VerificationType)
{
    UNDEFINED_VERSION(9)
}

bool CheckProto_10(
    const VerificationSet& input,
    const bool silent,
    const VerificationType)
{
    UNDEFINED_VERSION(10)
}

bool CheckProto_11(
    const VerificationSet& input,
    const bool silent,
    const VerificationType)
{
    UNDEFINED_VERSION(11)
}

bool CheckProto_12(
    const VerificationSet& input,
    const bool silent,
    const VerificationType)
{
    UNDEFINED_VERSION(12)
}

bool CheckProto_13(
    const VerificationSet& input,
    const bool silent,
    const VerificationType)
{
    UNDEFINED_VERSION(13)
}

bool CheckProto_14(
    const VerificationSet& input,
    const bool silent,
    const VerificationType)
{
    UNDEFINED_VERSION(14)
}

bool CheckProto_15(
    const VerificationSet& input,
    const bool silent,
    const VerificationType)
{
    UNDEFINED_VERSION(15)
}

bool CheckProto_16(
    const VerificationSet& input,
    const bool silent,
    const VerificationType)
{
    UNDEFINED_VERSION(16)
}

bool CheckProto_17(
    const VerificationSet& input,
    const bool silent,
    const VerificationType)
{
    UNDEFINED_VERSION(17)
}

bool CheckProto_18(
    const VerificationSet& input,
    const bool silent,
    const VerificationType)
{
    UNDEFINED_VERSION(18)
}

bool CheckProto_19(
    const VerificationSet& input,
    const bool silent,
    const VerificationType)
{
    UNDEFINED_VERSION(19)
}

bool CheckProto_20(
    const VerificationSet& input,
    const bool silent,
    const VerificationType)
{
    UNDEFINED_VERSION(20)
}
}  // namespace proto
}  // namespace opentxs
