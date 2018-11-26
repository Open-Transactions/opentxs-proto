// Copyright (c) 2018 The Open-Transactions developers
// This Source Code Form is subject to the terms of the Mozilla Public
// License, v. 2.0. If a copy of the MPL was not distributed with this
// file, You can obtain one at http://mozilla.org/MPL/2.0/.

#include "opentxs-proto/Types.hpp"
#include "opentxs-proto/Check.hpp"

#define PROTO_NAME "contact item"

namespace opentxs
{
namespace proto
{

bool CheckProto_1(
    const ContactItem& input,
    const bool silent,
    const ClaimType indexed,
    const ContactSectionVersion parentVersion)
{
    if (indexed) {
        if (!input.has_id()) { FAIL_1("missing id") }

        if (MIN_PLAUSIBLE_IDENTIFIER > input.id().size()) {
            FAIL_1("invalid id")
        }

        if (MAX_PLAUSIBLE_IDENTIFIER < input.id().size()) {
            FAIL_1("invalid id")
        }
    } else {
        if (input.has_id()) { FAIL_1("id not blank") }
    }

    if (!input.has_type()) { FAIL_1("missing type") }

    if (!ValidContactItemType(parentVersion, input.type())) {
        FAIL_1("invalid type")
    }

    if (!input.has_value()) { FAIL_1("missing value") }

    for (auto& it : input.attribute()) {
        if (!ValidContactItemAttribute(
                input.version(), static_cast<ContactItemAttribute>(it))) {
            FAIL_1("invalid attribute")
        }
    }

    if (input.has_subtype()) {
        if (3 > input.version()) { FAIL_1("Subtype present but not allowed") }

        const auto& section = parentVersion.second;

        if (0 == AllowedSubtypes.count(section)) {
            FAIL_1("Subtype present but not allowed")
        }
    }

    return true;
}

bool CheckProto_2(
    const ContactItem& input,
    const bool silent,
    const ClaimType indexed,
    const ContactSectionVersion parentVersion)
{
    return CheckProto_1(input, silent, indexed, parentVersion);
}

bool CheckProto_3(
    const ContactItem& input,
    const bool silent,
    const ClaimType indexed,
    const ContactSectionVersion parentVersion)
{
    return CheckProto_1(input, silent, indexed, parentVersion);
}

bool CheckProto_4(
    const ContactItem& input,
    const bool silent,
    const ClaimType indexed,
    const ContactSectionVersion parentVersion)
{
    return CheckProto_1(input, silent, indexed, parentVersion);
}

bool CheckProto_5(
    const ContactItem& input,
    const bool silent,
    const ClaimType indexed,
    const ContactSectionVersion parentVersion)
{
    return CheckProto_1(input, silent, indexed, parentVersion);
}

bool CheckProto_6(
    const ContactItem& input,
    const bool silent,
    const ClaimType indexed,
    const ContactSectionVersion parentVersion)
{
    return CheckProto_1(input, silent, indexed, parentVersion);
}

bool CheckProto_7(
    const ContactItem& input,
    const bool silent,
    const ClaimType indexed,
    const ContactSectionVersion parentVersion)
{
    UNDEFINED_VERSION(7)
}

bool CheckProto_8(
    const ContactItem& input,
    const bool silent,
    const ClaimType indexed,
    const ContactSectionVersion parentVersion)
{
    UNDEFINED_VERSION(8)
}

bool CheckProto_9(
    const ContactItem& input,
    const bool silent,
    const ClaimType indexed,
    const ContactSectionVersion parentVersion)
{
    UNDEFINED_VERSION(9)
}

bool CheckProto_10(
    const ContactItem& input,
    const bool silent,
    const ClaimType indexed,
    const ContactSectionVersion parentVersion)
{
    UNDEFINED_VERSION(10)
}

bool CheckProto_11(
    const ContactItem& input,
    const bool silent,
    const ClaimType indexed,
    const ContactSectionVersion parentVersion)
{
    UNDEFINED_VERSION(11)
}

bool CheckProto_12(
    const ContactItem& input,
    const bool silent,
    const ClaimType indexed,
    const ContactSectionVersion parentVersion)
{
    UNDEFINED_VERSION(12)
}

bool CheckProto_13(
    const ContactItem& input,
    const bool silent,
    const ClaimType indexed,
    const ContactSectionVersion parentVersion)
{
    UNDEFINED_VERSION(13)
}

bool CheckProto_14(
    const ContactItem& input,
    const bool silent,
    const ClaimType indexed,
    const ContactSectionVersion parentVersion)
{
    UNDEFINED_VERSION(14)
}

bool CheckProto_15(
    const ContactItem& input,
    const bool silent,
    const ClaimType indexed,
    const ContactSectionVersion parentVersion)
{
    UNDEFINED_VERSION(15)
}

bool CheckProto_16(
    const ContactItem& input,
    const bool silent,
    const ClaimType indexed,
    const ContactSectionVersion parentVersion)
{
    UNDEFINED_VERSION(16)
}

bool CheckProto_17(
    const ContactItem& input,
    const bool silent,
    const ClaimType indexed,
    const ContactSectionVersion parentVersion)
{
    UNDEFINED_VERSION(17)
}

bool CheckProto_18(
    const ContactItem& input,
    const bool silent,
    const ClaimType indexed,
    const ContactSectionVersion parentVersion)
{
    UNDEFINED_VERSION(18)
}

bool CheckProto_19(
    const ContactItem& input,
    const bool silent,
    const ClaimType indexed,
    const ContactSectionVersion parentVersion)
{
    UNDEFINED_VERSION(19)
}

bool CheckProto_20(
    const ContactItem& input,
    const bool silent,
    const ClaimType indexed,
    const ContactSectionVersion parentVersion)
{
    UNDEFINED_VERSION(20)
}
}  // namespace proto
}  // namespace opentxs
