// Copyright (c) 2018 The Open-Transactions developers
// This Source Code Form is subject to the terms of the Mozilla Public
// License, v. 2.0. If a copy of the MPL was not distributed with this
// file, You can obtain one at http://mozilla.org/MPL/2.0/.

#include "opentxs-proto/Types.hpp"
#include "opentxs-proto/Check.hpp"

#include <iostream>

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
        if (!input.has_id()) {
            FAIL("contact item", "missing id")
        }

        if (MIN_PLAUSIBLE_IDENTIFIER > input.id().size()) {
            FAIL("contact item", "invalid id")
        }

        if (MAX_PLAUSIBLE_IDENTIFIER < input.id().size()) {
            FAIL("contact item", "invalid id")
        }
    } else {
        if (input.has_id()) {
            FAIL("contact item", "id not blank")
        }
    }

    if (!input.has_type()) {
        FAIL("contact item", "missing type")
    }

    if (!ValidContactItemType(parentVersion, input.type())) {
        FAIL("contact item", "invalid type")
    }

    if (!input.has_value()) {
        FAIL("contact item", "missing value")
    }

    for (auto& it : input.attribute()) {
        if (!ValidContactItemAttribute(
                input.version(), static_cast<ContactItemAttribute>(it))) {
            FAIL("contact item", "invalid attribute")
        }
    }

    if (input.has_subtype()) {
        if (3 > input.version()) {
            FAIL("contact item", "Subtype present but not allowed")
        }

        const auto& section = parentVersion.second;

        if (0 == AllowedSubtypes.count(section)) {
            FAIL("contact item", "Subtype present but not allowed")
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
    UNDEFINED_VERSION2(6)
}

bool CheckProto_7(
    const ContactItem& input,
    const bool silent,
    const ClaimType indexed,
    const ContactSectionVersion parentVersion)
{
    UNDEFINED_VERSION2(7)
}

bool CheckProto_8(
    const ContactItem& input,
    const bool silent,
    const ClaimType indexed,
    const ContactSectionVersion parentVersion)
{
    UNDEFINED_VERSION2(8)
}

bool CheckProto_9(
    const ContactItem& input,
    const bool silent,
    const ClaimType indexed,
    const ContactSectionVersion parentVersion)
{
    UNDEFINED_VERSION2(9)
}

bool CheckProto_10(
    const ContactItem& input,
    const bool silent,
    const ClaimType indexed,
    const ContactSectionVersion parentVersion)
{
    UNDEFINED_VERSION2(10)
}

bool CheckProto_11(
    const ContactItem& input,
    const bool silent,
    const ClaimType indexed,
    const ContactSectionVersion parentVersion)
{
    UNDEFINED_VERSION2(11)
}

bool CheckProto_12(
    const ContactItem& input,
    const bool silent,
    const ClaimType indexed,
    const ContactSectionVersion parentVersion)
{
    UNDEFINED_VERSION2(12)
}

bool CheckProto_13(
    const ContactItem& input,
    const bool silent,
    const ClaimType indexed,
    const ContactSectionVersion parentVersion)
{
    UNDEFINED_VERSION2(13)
}

bool CheckProto_14(
    const ContactItem& input,
    const bool silent,
    const ClaimType indexed,
    const ContactSectionVersion parentVersion)
{
    UNDEFINED_VERSION2(14)
}

bool CheckProto_15(
    const ContactItem& input,
    const bool silent,
    const ClaimType indexed,
    const ContactSectionVersion parentVersion)
{
    UNDEFINED_VERSION2(15)
}

bool CheckProto_16(
    const ContactItem& input,
    const bool silent,
    const ClaimType indexed,
    const ContactSectionVersion parentVersion)
{
    UNDEFINED_VERSION2(16)
}

bool CheckProto_17(
    const ContactItem& input,
    const bool silent,
    const ClaimType indexed,
    const ContactSectionVersion parentVersion)
{
    UNDEFINED_VERSION2(17)
}

bool CheckProto_18(
    const ContactItem& input,
    const bool silent,
    const ClaimType indexed,
    const ContactSectionVersion parentVersion)
{
    UNDEFINED_VERSION2(18)
}

bool CheckProto_19(
    const ContactItem& input,
    const bool silent,
    const ClaimType indexed,
    const ContactSectionVersion parentVersion)
{
    UNDEFINED_VERSION2(19)
}

bool CheckProto_20(
    const ContactItem& input,
    const bool silent,
    const ClaimType indexed,
    const ContactSectionVersion parentVersion)
{
    UNDEFINED_VERSION2(20)
}
}  // namespace proto
}  // namespace opentxs
