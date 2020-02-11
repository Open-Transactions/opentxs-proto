// Copyright (c) 2020 The Open-Transactions developers
// This Source Code Form is subject to the terms of the Mozilla Public
// License, v. 2.0. If a copy of the MPL was not distributed with this
// file, You can obtain one at http://mozilla.org/MPL/2.0/.

#include "opentxs-proto/Types.hpp"
#include "verify/Check.hpp"

#define PROTO_NAME "contact"

namespace opentxs
{
namespace proto
{

bool CheckProto_1(const Contact& input, const bool silent)
{
    if (false == input.has_id()) { FAIL_1("missing id") }

    if (MIN_PLAUSIBLE_IDENTIFIER > input.id().size()) {
        FAIL_2("invalid id", input.id())
    }

    if (MAX_PLAUSIBLE_IDENTIFIER < input.id().size()) {
        FAIL_2("invalid id", input.id())
    }

    if (input.has_label()) {
        if (MAX_VALID_CONTACT_VALUE < input.label().size()) {
            FAIL_2("invalid label", input.id())
        }
    }

    if (input.has_contactdata()) {
        try {
            const auto validContactData = Check(
                input.contactdata(),
                ContactAllowedContactData().at(input.version()).first,
                ContactAllowedContactData().at(input.version()).second,
                silent,
                ClaimType::Normal);

            if (!validContactData) { FAIL_1("invalid contact data") }
        } catch (const std::out_of_range&) {
            FAIL_2(
                "allowed contact data not defined for version", input.version())
        }
    }

    const bool merged = 0 < input.mergedto().size();
    const bool hasMerges = 0 < input.merged().size();

    if (merged && hasMerges) {
        FAIL_1("merged contact may not contain child merges")
    }

    if (merged) {
        if (MIN_PLAUSIBLE_IDENTIFIER > input.mergedto().size()) {
            FAIL_2("invalid mergedto", input.mergedto())
        }

        if (MAX_PLAUSIBLE_IDENTIFIER < input.mergedto().size()) {
            FAIL_2("invalid mergedto", input.mergedto())
        }
    }

    if (hasMerges) {
        for (const auto& merge : input.merged()) {
            if (MIN_PLAUSIBLE_IDENTIFIER > merge.size()) {
                FAIL_2("invalid merge", merge)
            }

            if (MAX_PLAUSIBLE_IDENTIFIER < merge.size()) {
                FAIL_2("invalid merge", merge)
            }
        }
    }

    return true;
}

bool CheckProto_2(const Contact& input, const bool silent)
{
    return CheckProto_1(input, silent);
}

bool CheckProto_3(const Contact& input, const bool silent)
{
    return CheckProto_1(input, silent);
}

bool CheckProto_4(const Contact& input, const bool silent)
{
    UNDEFINED_VERSION(4)
}

bool CheckProto_5(const Contact& input, const bool silent)
{
    UNDEFINED_VERSION(5)
}

bool CheckProto_6(const Contact& input, const bool silent)
{
    UNDEFINED_VERSION(6)
}

bool CheckProto_7(const Contact& input, const bool silent)
{
    UNDEFINED_VERSION(7)
}

bool CheckProto_8(const Contact& input, const bool silent)
{
    UNDEFINED_VERSION(8)
}

bool CheckProto_9(const Contact& input, const bool silent)
{
    UNDEFINED_VERSION(9)
}

bool CheckProto_10(const Contact& input, const bool silent)
{
    UNDEFINED_VERSION(10)
}

bool CheckProto_11(const Contact& input, const bool silent)
{
    UNDEFINED_VERSION(11)
}

bool CheckProto_12(const Contact& input, const bool silent)
{
    UNDEFINED_VERSION(12)
}

bool CheckProto_13(const Contact& input, const bool silent)
{
    UNDEFINED_VERSION(13)
}

bool CheckProto_14(const Contact& input, const bool silent)
{
    UNDEFINED_VERSION(14)
}

bool CheckProto_15(const Contact& input, const bool silent)
{
    UNDEFINED_VERSION(15)
}

bool CheckProto_16(const Contact& input, const bool silent)
{
    UNDEFINED_VERSION(16)
}

bool CheckProto_17(const Contact& input, const bool silent)
{
    UNDEFINED_VERSION(17)
}

bool CheckProto_18(const Contact& input, const bool silent)
{
    UNDEFINED_VERSION(18)
}

bool CheckProto_19(const Contact& input, const bool silent)
{
    UNDEFINED_VERSION(19)
}

bool CheckProto_20(const Contact& input, const bool silent)
{
    UNDEFINED_VERSION(20)
}
}  // namespace proto
}  // namespace opentxs
