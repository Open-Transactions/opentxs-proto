// Copyright (c) 2019 The Open-Transactions developers
// This Source Code Form is subject to the terms of the Mozilla Public
// License, v. 2.0. If a copy of the MPL was not distributed with this
// file, You can obtain one at http://mozilla.org/MPL/2.0/.

#include "opentxs-proto/Types.hpp"
#include "verify/Check.hpp"

#define PROTO_NAME "nym"

namespace opentxs
{
namespace proto
{

bool CheckProto_1(const Nym& input, const bool silent)
{
    bool validSource = false;

    if (!input.has_nymid()) { FAIL_1("missing nym id") }

    if (MIN_PLAUSIBLE_IDENTIFIER > input.nymid().size()) {
        FAIL_2("invalid nym id", input.nymid())
    }

    if (!input.has_mode()) { FAIL_1("missing mode") }

    const auto actualMode = input.mode();

    if (!input.has_revision()) { FAIL_1("missing revision") }

    if (1 > input.revision()) { FAIL_2("invalid revision", input.revision()) }

    if (!input.has_source()) { FAIL_1("missing nym id source") }

    try {
        validSource = Check(
            input.source(),
            NymAllowedNymIDSource.at(input.version()).first,
            NymAllowedNymIDSource.at(input.version()).second,
            silent);

        if (!validSource) { FAIL_1("invalid nym id source") }
    } catch (const std::out_of_range&) {
        FAIL_2(
            "allowed nym ID source version not defined for version",
            input.version())
    }

    bool haveHD = false;

    for (auto& it : input.activecredentials()) {
        try {
            const KeyMode mode =
                (NYM_PRIVATE == actualMode) ? KEYMODE_PRIVATE : KEYMODE_PUBLIC;
            const bool validSet = Check(
                it,
                NymAllowedAuthority.at(input.version()).first,
                NymAllowedAuthority.at(input.version()).second,
                silent,
                input.nymid(),
                mode,
                haveHD);

            if (false == validSet) { FAIL_1("invalid credential set") }
        } catch (const std::out_of_range&) {
            FAIL_2(
                "allowed credential set version not defined for version",
                input.version())
        }
    }

    for (auto& it : input.revokedcredentials()) {
        try {
            const KeyMode mode =
                (NYM_PRIVATE == actualMode) ? KEYMODE_PRIVATE : KEYMODE_PUBLIC;
            const bool validSet = Check(
                it,
                NymAllowedAuthority.at(input.version()).first,
                NymAllowedAuthority.at(input.version()).second,
                silent,
                input.nymid(),
                mode,
                haveHD);

            if (false == validSet) { FAIL_1("invalid credential set") }
        } catch (const std::out_of_range&) {
            FAIL_2(
                "allowed credential set version not defined for version",
                input.version())
        }
    }

    switch (actualMode) {
        case NYM_PRIVATE: {
            if (haveHD) {
                if (1 > input.index()) { FAIL_1("missing index") }
            }

            break;
        }
        case NYM_PUBLIC: {
            if (input.has_index()) { FAIL_1("index present in public mode") }

            break;
        }
        case NYM_ERROR:
        default: {
            FAIL_2("invalid mode", actualMode)
        }
    }

    return true;
}

bool CheckProto_2(const Nym& input, const bool silent)
{
    return CheckProto_1(input, silent);
}

bool CheckProto_3(const Nym& input, const bool silent)
{
    return CheckProto_1(input, silent);
}

bool CheckProto_4(const Nym& input, const bool silent)
{
    return CheckProto_1(input, silent);
}

bool CheckProto_5(const Nym& input, const bool silent)
{
    return CheckProto_1(input, silent);
}

bool CheckProto_6(const Nym& input, const bool silent)
{
    return CheckProto_1(input, silent);
}

bool CheckProto_7(const Nym& input, const bool silent) { UNDEFINED_VERSION(7) }

bool CheckProto_8(const Nym& input, const bool silent) { UNDEFINED_VERSION(8) }

bool CheckProto_9(const Nym& input, const bool silent) { UNDEFINED_VERSION(9) }

bool CheckProto_10(const Nym& input, const bool silent)
{
    UNDEFINED_VERSION(10)
}

bool CheckProto_11(const Nym& input, const bool silent)
{
    UNDEFINED_VERSION(11)
}

bool CheckProto_12(const Nym& input, const bool silent)
{
    UNDEFINED_VERSION(12)
}

bool CheckProto_13(const Nym& input, const bool silent)
{
    UNDEFINED_VERSION(13)
}

bool CheckProto_14(const Nym& input, const bool silent)
{
    UNDEFINED_VERSION(14)
}

bool CheckProto_15(const Nym& input, const bool silent)
{
    UNDEFINED_VERSION(15)
}

bool CheckProto_16(const Nym& input, const bool silent)
{
    UNDEFINED_VERSION(16)
}

bool CheckProto_17(const Nym& input, const bool silent)
{
    UNDEFINED_VERSION(17)
}

bool CheckProto_18(const Nym& input, const bool silent)
{
    UNDEFINED_VERSION(18)
}

bool CheckProto_19(const Nym& input, const bool silent)
{
    UNDEFINED_VERSION(19)
}

bool CheckProto_20(const Nym& input, const bool silent)
{
    UNDEFINED_VERSION(20)
}
}  // namespace proto
}  // namespace opentxs
