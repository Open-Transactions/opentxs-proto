// Copyright (c) 2018 The Open-Transactions developers
// This Source Code Form is subject to the terms of the Mozilla Public
// License, v. 2.0. If a copy of the MPL was not distributed with this
// file, You can obtain one at http://mozilla.org/MPL/2.0/.

#include "opentxs-proto/Types.hpp"
#include "opentxs-proto/Check.hpp"

#include <iostream>

#define PROTO_NAME "contact section"

namespace opentxs
{
namespace proto
{

bool CheckProto_1(
    const ContactSection& input,
    const bool silent,
    const ClaimType indexed,
    const uint32_t parentVersion)
{
    if (!input.has_name()) { FAIL("contact section", "missing name") }

    if (!ValidContactSectionName(parentVersion, input.name())) {
        FAIL2("contact section", "invalid name", input.name())
    }

    for (auto& it : input.item()) {
        try {
            bool validItem = Check(
                it,
                ContactSectionAllowedItem.at(input.version()).first,
                ContactSectionAllowedItem.at(input.version()).second,
                silent,
                indexed,
                ContactSectionVersion{input.version(), input.name()});

            if (!validItem) { FAIL("contact section", "invalid item") }
        } catch (const std::out_of_range&) {
            FAIL2(
                "contact section",
                "allowed contact item version not defined for version",
                input.version())
        }
    }

    return true;
}

bool CheckProto_2(
    const ContactSection& input,
    const bool silent,
    const ClaimType indexed,
    const uint32_t parentVersion)
{
    return CheckProto_1(input, silent, indexed, parentVersion);
}

bool CheckProto_3(
    const ContactSection& input,
    const bool silent,
    const ClaimType indexed,
    const uint32_t parentVersion)
{
    return CheckProto_1(input, silent, indexed, parentVersion);
}

bool CheckProto_4(
    const ContactSection& input,
    const bool silent,
    const ClaimType indexed,
    const uint32_t parentVersion)
{
    return CheckProto_1(input, silent, indexed, parentVersion);
}

bool CheckProto_5(
    const ContactSection& input,
    const bool silent,
    const ClaimType indexed,
    const uint32_t parentVersion)
{
    return CheckProto_1(input, silent, indexed, parentVersion);
}

bool CheckProto_6(
    const ContactSection& input,
    const bool silent,
    const ClaimType indexed,
    const uint32_t parentVersion)
{
    // TODO: Remove the next line when version 6 is added.
    UNDEFINED_VERSION2(6)

    if (!input.has_name()) { FAIL("contact section", "missing name") }

    if (!ValidContactSectionName(parentVersion, input.name())) {
        FAIL2("contact section", "invalid name", input.name())
    }

    if (0 == input.item_size()) { FAIL("contact section", "empty section") }

    for (auto& it : input.item()) {
        try {
            bool validItem = Check(
                it,
                ContactSectionAllowedItem.at(input.version()).first,
                ContactSectionAllowedItem.at(input.version()).second,
                silent,
                indexed,
                ContactSectionVersion{input.version(), input.name()});

            if (!validItem) { FAIL("contact section", "invalid item") }
        } catch (const std::out_of_range&) {
            FAIL2(
                "contact section",
                "allowed contact item version not defined for version",
                input.version())
        }
    }

    return true;
}

bool CheckProto_7(
    const ContactSection& input,
    const bool silent,
    const ClaimType indexed,
    const uint32_t parentVersion)
{
    UNDEFINED_VERSION2(7)
}

bool CheckProto_8(
    const ContactSection& input,
    const bool silent,
    const ClaimType indexed,
    const uint32_t parentVersion)
{
    UNDEFINED_VERSION2(8)
}

bool CheckProto_9(
    const ContactSection& input,
    const bool silent,
    const ClaimType indexed,
    const uint32_t parentVersion)
{
    UNDEFINED_VERSION2(9)
}

bool CheckProto_10(
    const ContactSection& input,
    const bool silent,
    const ClaimType indexed,
    const uint32_t parentVersion)
{
    UNDEFINED_VERSION2(10)
}

bool CheckProto_11(
    const ContactSection& input,
    const bool silent,
    const ClaimType indexed,
    const uint32_t parentVersion)
{
    UNDEFINED_VERSION2(11)
}

bool CheckProto_12(
    const ContactSection& input,
    const bool silent,
    const ClaimType indexed,
    const uint32_t parentVersion)
{
    UNDEFINED_VERSION2(12)
}

bool CheckProto_13(
    const ContactSection& input,
    const bool silent,
    const ClaimType indexed,
    const uint32_t parentVersion)
{
    UNDEFINED_VERSION2(13)
}

bool CheckProto_14(
    const ContactSection& input,
    const bool silent,
    const ClaimType indexed,
    const uint32_t parentVersion)
{
    UNDEFINED_VERSION2(14)
}

bool CheckProto_15(
    const ContactSection& input,
    const bool silent,
    const ClaimType indexed,
    const uint32_t parentVersion)
{
    UNDEFINED_VERSION2(15)
}

bool CheckProto_16(
    const ContactSection& input,
    const bool silent,
    const ClaimType indexed,
    const uint32_t parentVersion)
{
    UNDEFINED_VERSION2(16)
}

bool CheckProto_17(
    const ContactSection& input,
    const bool silent,
    const ClaimType indexed,
    const uint32_t parentVersion)
{
    UNDEFINED_VERSION2(17)
}

bool CheckProto_18(
    const ContactSection& input,
    const bool silent,
    const ClaimType indexed,
    const uint32_t parentVersion)
{
    UNDEFINED_VERSION2(18)
}

bool CheckProto_19(
    const ContactSection& input,
    const bool silent,
    const ClaimType indexed,
    const uint32_t parentVersion)
{
    UNDEFINED_VERSION2(19)
}

bool CheckProto_20(
    const ContactSection& input,
    const bool silent,
    const ClaimType indexed,
    const uint32_t parentVersion)
{
    UNDEFINED_VERSION2(20)
}
}  // namespace proto
}  // namespace opentxs
