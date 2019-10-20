// Copyright (c) 2019 The Open-Transactions developers
// This Source Code Form is subject to the terms of the Mozilla Public
// License, v. 2.0. If a copy of the MPL was not distributed with this
// file, You can obtain one at http://mozilla.org/MPL/2.0/.

#include "opentxs-proto/Types.hpp"
#include "verify/Check.hpp"

#define PROTO_NAME "master parameters"

namespace opentxs
{
namespace proto
{

bool CheckProto_1(
    const MasterCredentialParameters& input,
    const bool silent,
    bool& expectSourceSignature)
{
    if (false == input.has_source()) { FAIL_1("missing nym id source") }

    try {
        const bool validSource = Check(
            input.source(),
            MasterParamsAllowedNymIDSource.at(input.version()).first,
            MasterParamsAllowedNymIDSource.at(input.version()).second,
            silent);

        if (!validSource) { FAIL_1("invalid nym id source") }
    } catch (const std::out_of_range&) {
        FAIL_2(
            "allowed nym ID source version not defined for version",
            input.version())
    }

    if (!input.has_sourceproof()) { FAIL_1("missing nym id source proof") }

    try {
        const bool validProof = Check(
            input.sourceproof(),
            MasterParamsAllowedSourceProof.at(input.version()).first,
            MasterParamsAllowedSourceProof.at(input.version()).second,
            silent,
            expectSourceSignature);

        if (!validProof) { FAIL_1("invalid nym id source proof") }
    } catch (const std::out_of_range&) {
        FAIL_2(
            "allowed source proof version not defined for version",
            input.version())
    }

    return true;
}

bool CheckProto_2(
    const MasterCredentialParameters& input,
    const bool silent,
    bool& expectSourceSignature)
{
    return CheckProto_1(input, silent, expectSourceSignature);
}

bool CheckProto_3(
    const MasterCredentialParameters& input,
    const bool silent,
    bool&)
{
    UNDEFINED_VERSION(3)
}

bool CheckProto_4(
    const MasterCredentialParameters& input,
    const bool silent,
    bool&)
{
    UNDEFINED_VERSION(4)
}

bool CheckProto_5(
    const MasterCredentialParameters& input,
    const bool silent,
    bool&)
{
    UNDEFINED_VERSION(5)
}

bool CheckProto_6(
    const MasterCredentialParameters& input,
    const bool silent,
    bool&)
{
    UNDEFINED_VERSION(6)
}

bool CheckProto_7(
    const MasterCredentialParameters& input,
    const bool silent,
    bool&)
{
    UNDEFINED_VERSION(7)
}

bool CheckProto_8(
    const MasterCredentialParameters& input,
    const bool silent,
    bool&)
{
    UNDEFINED_VERSION(8)
}

bool CheckProto_9(
    const MasterCredentialParameters& input,
    const bool silent,
    bool&)
{
    UNDEFINED_VERSION(9)
}

bool CheckProto_10(
    const MasterCredentialParameters& input,
    const bool silent,
    bool&)
{
    UNDEFINED_VERSION(10)
}

bool CheckProto_11(
    const MasterCredentialParameters& input,
    const bool silent,
    bool&)
{
    UNDEFINED_VERSION(11)
}

bool CheckProto_12(
    const MasterCredentialParameters& input,
    const bool silent,
    bool&)
{
    UNDEFINED_VERSION(12)
}

bool CheckProto_13(
    const MasterCredentialParameters& input,
    const bool silent,
    bool&)
{
    UNDEFINED_VERSION(13)
}

bool CheckProto_14(
    const MasterCredentialParameters& input,
    const bool silent,
    bool&)
{
    UNDEFINED_VERSION(14)
}

bool CheckProto_15(
    const MasterCredentialParameters& input,
    const bool silent,
    bool&)
{
    UNDEFINED_VERSION(15)
}

bool CheckProto_16(
    const MasterCredentialParameters& input,
    const bool silent,
    bool&)
{
    UNDEFINED_VERSION(16)
}

bool CheckProto_17(
    const MasterCredentialParameters& input,
    const bool silent,
    bool&)
{
    UNDEFINED_VERSION(17)
}

bool CheckProto_18(
    const MasterCredentialParameters& input,
    const bool silent,
    bool&)
{
    UNDEFINED_VERSION(18)
}

bool CheckProto_19(
    const MasterCredentialParameters& input,
    const bool silent,
    bool&)
{
    UNDEFINED_VERSION(19)
}

bool CheckProto_20(
    const MasterCredentialParameters& input,
    const bool silent,
    bool&)
{
    UNDEFINED_VERSION(20)
}
}  // namespace proto
}  // namespace opentxs
