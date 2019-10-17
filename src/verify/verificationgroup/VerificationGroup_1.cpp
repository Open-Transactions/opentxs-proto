// Copyright (c) 2019 The Open-Transactions developers
// This Source Code Form is subject to the terms of the Mozilla Public
// License, v. 2.0. If a copy of the MPL was not distributed with this
// file, You can obtain one at http://mozilla.org/MPL/2.0/.

#include "opentxs-proto/Types.hpp"
#include "verify/Check.hpp"

#define PROTO_NAME "verification group"

namespace opentxs
{
namespace proto
{

bool CheckProto_1(
    const VerificationGroup& input,
    const bool silent,
    const VerificationType indexed)
{
    VerificationNymMap nymMap;

    for (auto& it : input.identity()) {
        try {
            const bool validIdentity = Check(
                it,
                VerificationGroupAllowedIdentity.at(input.version()).first,
                VerificationGroupAllowedIdentity.at(input.version()).second,
                silent,
                nymMap,
                indexed);

            if (!validIdentity) { FAIL_2("invalid identity", it.nym()) }
        } catch (const std::out_of_range&) {
            FAIL_2(
                "allowed verification identity version not defined for version",
                input.version())
        }
    }

    for (auto& nym : nymMap) {
        if (nym.second > 1) { FAIL_2("duplicate identity", nym.first) }
    }

    return true;
}

bool CheckProto_2(
    const VerificationGroup& input,
    const bool silent,
    const VerificationType)
{
    UNDEFINED_VERSION(2)
}

bool CheckProto_3(
    const VerificationGroup& input,
    const bool silent,
    const VerificationType)
{
    UNDEFINED_VERSION(3)
}

bool CheckProto_4(
    const VerificationGroup& input,
    const bool silent,
    const VerificationType)
{
    UNDEFINED_VERSION(4)
}

bool CheckProto_5(
    const VerificationGroup& input,
    const bool silent,
    const VerificationType)
{
    UNDEFINED_VERSION(5)
}

bool CheckProto_6(
    const VerificationGroup& input,
    const bool silent,
    const VerificationType)
{
    UNDEFINED_VERSION(6)
}

bool CheckProto_7(
    const VerificationGroup& input,
    const bool silent,
    const VerificationType)
{
    UNDEFINED_VERSION(7)
}

bool CheckProto_8(
    const VerificationGroup& input,
    const bool silent,
    const VerificationType)
{
    UNDEFINED_VERSION(8)
}

bool CheckProto_9(
    const VerificationGroup& input,
    const bool silent,
    const VerificationType)
{
    UNDEFINED_VERSION(9)
}

bool CheckProto_10(
    const VerificationGroup& input,
    const bool silent,
    const VerificationType)
{
    UNDEFINED_VERSION(10)
}

bool CheckProto_11(
    const VerificationGroup& input,
    const bool silent,
    const VerificationType)
{
    UNDEFINED_VERSION(11)
}

bool CheckProto_12(
    const VerificationGroup& input,
    const bool silent,
    const VerificationType)
{
    UNDEFINED_VERSION(12)
}

bool CheckProto_13(
    const VerificationGroup& input,
    const bool silent,
    const VerificationType)
{
    UNDEFINED_VERSION(13)
}

bool CheckProto_14(
    const VerificationGroup& input,
    const bool silent,
    const VerificationType)
{
    UNDEFINED_VERSION(14)
}

bool CheckProto_15(
    const VerificationGroup& input,
    const bool silent,
    const VerificationType)
{
    UNDEFINED_VERSION(15)
}

bool CheckProto_16(
    const VerificationGroup& input,
    const bool silent,
    const VerificationType)
{
    UNDEFINED_VERSION(16)
}

bool CheckProto_17(
    const VerificationGroup& input,
    const bool silent,
    const VerificationType)
{
    UNDEFINED_VERSION(17)
}

bool CheckProto_18(
    const VerificationGroup& input,
    const bool silent,
    const VerificationType)
{
    UNDEFINED_VERSION(18)
}

bool CheckProto_19(
    const VerificationGroup& input,
    const bool silent,
    const VerificationType)
{
    UNDEFINED_VERSION(19)
}

bool CheckProto_20(
    const VerificationGroup& input,
    const bool silent,
    const VerificationType)
{
    UNDEFINED_VERSION(20)
}
}  // namespace proto
}  // namespace opentxs
