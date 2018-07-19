// Copyright (c) 2018 The Open-Transactions developers
// This Source Code Form is subject to the terms of the Mozilla Public
// License, v. 2.0. If a copy of the MPL was not distributed with this
// file, You can obtain one at http://mozilla.org/MPL/2.0/.

#include "opentxs-proto/Types.hpp"
#include "opentxs-proto/Check.hpp"

#include <iostream>

#define PROTO_NAME "contact data"

namespace opentxs
{
namespace proto
{

bool CheckProto_1(
    const ContactData& input,
    const bool silent,
    const ClaimType indexed)
{
    std::map<ContactSectionName, uint32_t> sectionCount;

    for (auto& it : input.section()) {
        try {
            bool validSection = Check(
                it,
                ContactDataAllowedSection.at(input.version()).first,
                ContactDataAllowedSection.at(input.version()).second,
                silent,
                indexed,
                input.version());

            if (!validSection) {
                FAIL("contact data", "invalid section")
            }
        } catch (const std::out_of_range&) {
            FAIL2(
                "contact data",
                "allowed contact section version not defined for version",
                input.version())
        }

        ContactSectionName name = it.name();

        if (sectionCount.count(name) > 0) {
            FAIL("contact data", "duplicate section")
        } else {
            sectionCount.insert({name, 1});
        }
    }

    return true;
}

bool CheckProto_2(
    const ContactData& input,
    const bool silent,
    const ClaimType indexed)
{
    return CheckProto_1(input, silent, indexed);
}

bool CheckProto_3(
    const ContactData& input,
    const bool silent,
    const ClaimType indexed)
{
    return CheckProto_1(input, silent, indexed);
}

bool CheckProto_4(
    const ContactData& input,
    const bool silent,
    const ClaimType indexed)
{
    return CheckProto_1(input, silent, indexed);
}

bool CheckProto_5(
    const ContactData& input,
    const bool silent,
    const ClaimType indexed)
{
    return CheckProto_1(input, silent, indexed);
}

bool CheckProto_6(
    const ContactData& input,
    const bool silent,
    const ClaimType indexed)
{
    UNDEFINED_VERSION2(6)
}

bool CheckProto_7(
    const ContactData& input,
    const bool silent,
    const ClaimType indexed)
{
    UNDEFINED_VERSION2(7)
}

bool CheckProto_8(
    const ContactData& input,
    const bool silent,
    const ClaimType indexed)
{
    UNDEFINED_VERSION2(8)
}

bool CheckProto_9(
    const ContactData& input,
    const bool silent,
    const ClaimType indexed)
{
    UNDEFINED_VERSION2(9)
}

bool CheckProto_10(
    const ContactData& input,
    const bool silent,
    const ClaimType indexed)
{
    UNDEFINED_VERSION2(10)
}

bool CheckProto_11(
    const ContactData& input,
    const bool silent,
    const ClaimType indexed)
{
    UNDEFINED_VERSION2(11)
}

bool CheckProto_12(
    const ContactData& input,
    const bool silent,
    const ClaimType indexed)
{
    UNDEFINED_VERSION2(12)
}

bool CheckProto_13(
    const ContactData& input,
    const bool silent,
    const ClaimType indexed)
{
    UNDEFINED_VERSION2(13)
}

bool CheckProto_14(
    const ContactData& input,
    const bool silent,
    const ClaimType indexed)
{
    UNDEFINED_VERSION2(14)
}

bool CheckProto_15(
    const ContactData& input,
    const bool silent,
    const ClaimType indexed)
{
    UNDEFINED_VERSION2(15)
}

bool CheckProto_16(
    const ContactData& input,
    const bool silent,
    const ClaimType indexed)
{
    UNDEFINED_VERSION2(16)
}

bool CheckProto_17(
    const ContactData& input,
    const bool silent,
    const ClaimType indexed)
{
    UNDEFINED_VERSION2(17)
}

bool CheckProto_18(
    const ContactData& input,
    const bool silent,
    const ClaimType indexed)
{
    UNDEFINED_VERSION2(18)
}

bool CheckProto_19(
    const ContactData& input,
    const bool silent,
    const ClaimType indexed)
{
    UNDEFINED_VERSION2(19)
}

bool CheckProto_20(
    const ContactData& input,
    const bool silent,
    const ClaimType indexed)
{
    UNDEFINED_VERSION2(20)
}
}  // namespace proto
}  // namespace opentxs
