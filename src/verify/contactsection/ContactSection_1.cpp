// Copyright (c) 2020 The Open-Transactions developers
// This Source Code Form is subject to the terms of the Mozilla Public
// License, v. 2.0. If a copy of the MPL was not distributed with this
// file, You can obtain one at http://mozilla.org/MPL/2.0/.

#include "opentxs-proto/Types.hpp"
#include "verify/Check.hpp"

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
    if (!input.has_name()) { FAIL_1("missing name") }

    if (!ValidContactSectionName(parentVersion, input.name())) {
        FAIL_2("invalid name", input.name())
    }

    for (auto& it : input.item()) {
        try {
            bool validItem = Check(
                it,
                ContactSectionAllowedItem().at(input.version()).first,
                ContactSectionAllowedItem().at(input.version()).second,
                silent,
                indexed,
                ContactSectionVersion{input.version(), input.name()});

            if (!validItem) { FAIL_1("invalid item") }
        } catch (const std::out_of_range&) {
            FAIL_2(
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
    if (!input.has_name()) { FAIL_1("missing name") }

    if (!ValidContactSectionName(parentVersion, input.name())) {
        FAIL_2("invalid name", input.name())
    }

    if (0 == input.item_size()) { FAIL_1("empty section") }

    for (auto& it : input.item()) {
        try {
            bool validItem = Check(
                it,
                ContactSectionAllowedItem().at(input.version()).first,
                ContactSectionAllowedItem().at(input.version()).second,
                silent,
                indexed,
                ContactSectionVersion{input.version(), input.name()});

            if (!validItem) { FAIL_1("invalid item") }
        } catch (const std::out_of_range&) {
            FAIL_2(
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
    UNDEFINED_VERSION(7)
}

bool CheckProto_8(
    const ContactSection& input,
    const bool silent,
    const ClaimType indexed,
    const uint32_t parentVersion)
{
    UNDEFINED_VERSION(8)
}

bool CheckProto_9(
    const ContactSection& input,
    const bool silent,
    const ClaimType indexed,
    const uint32_t parentVersion)
{
    UNDEFINED_VERSION(9)
}

bool CheckProto_10(
    const ContactSection& input,
    const bool silent,
    const ClaimType indexed,
    const uint32_t parentVersion)
{
    UNDEFINED_VERSION(10)
}

bool CheckProto_11(
    const ContactSection& input,
    const bool silent,
    const ClaimType indexed,
    const uint32_t parentVersion)
{
    UNDEFINED_VERSION(11)
}

bool CheckProto_12(
    const ContactSection& input,
    const bool silent,
    const ClaimType indexed,
    const uint32_t parentVersion)
{
    UNDEFINED_VERSION(12)
}

bool CheckProto_13(
    const ContactSection& input,
    const bool silent,
    const ClaimType indexed,
    const uint32_t parentVersion)
{
    UNDEFINED_VERSION(13)
}

bool CheckProto_14(
    const ContactSection& input,
    const bool silent,
    const ClaimType indexed,
    const uint32_t parentVersion)
{
    UNDEFINED_VERSION(14)
}

bool CheckProto_15(
    const ContactSection& input,
    const bool silent,
    const ClaimType indexed,
    const uint32_t parentVersion)
{
    UNDEFINED_VERSION(15)
}

bool CheckProto_16(
    const ContactSection& input,
    const bool silent,
    const ClaimType indexed,
    const uint32_t parentVersion)
{
    UNDEFINED_VERSION(16)
}

bool CheckProto_17(
    const ContactSection& input,
    const bool silent,
    const ClaimType indexed,
    const uint32_t parentVersion)
{
    UNDEFINED_VERSION(17)
}

bool CheckProto_18(
    const ContactSection& input,
    const bool silent,
    const ClaimType indexed,
    const uint32_t parentVersion)
{
    UNDEFINED_VERSION(18)
}

bool CheckProto_19(
    const ContactSection& input,
    const bool silent,
    const ClaimType indexed,
    const uint32_t parentVersion)
{
    UNDEFINED_VERSION(19)
}

bool CheckProto_20(
    const ContactSection& input,
    const bool silent,
    const ClaimType indexed,
    const uint32_t parentVersion)
{
    UNDEFINED_VERSION(20)
}
}  // namespace proto
}  // namespace opentxs
