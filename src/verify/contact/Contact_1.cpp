/************************************************************
 *
 *                 OPEN TRANSACTIONS
 *
 *       Financial Cryptography and Digital Cash
 *       Library, Protocol, API, Server, CLI, GUI
 *
 *       -- Anonymous Numbered Accounts.
 *       -- Untraceable Digital Cash.
 *       -- Triple-Signed Receipts.
 *       -- Cheques, Vouchers, Transfers, Inboxes.
 *       -- Basket Currencies, Markets, Payment Plans.
 *       -- Signed, XML, Ricardian-style Contracts.
 *       -- Scripted smart contracts.
 *
 *  EMAIL:
 *  fellowtraveler@opentransactions.org
 *
 *  WEBSITE:
 *  http://www.opentransactions.org/
 *
 *  -----------------------------------------------------
 *
 *   LICENSE:
 *   This Source Code Form is subject to the terms of the
 *   Mozilla Public License, v. 2.0. If a copy of the MPL
 *   was not distributed with this file, You can obtain one
 *   at http://mozilla.org/MPL/2.0/.
 *
 *   DISCLAIMER:
 *   This program is distributed in the hope that it will
 *   be useful, but WITHOUT ANY WARRANTY; without even the
 *   implied warranty of MERCHANTABILITY or FITNESS FOR A
 *   PARTICULAR PURPOSE.  See the Mozilla Public License
 *   for more details.
 *
 ************************************************************/

#include "opentxs-proto/Types.hpp"
#include "opentxs-proto/Check.hpp"

#include <iostream>

#define PROTO_NAME "contact"

namespace opentxs
{
namespace proto
{

bool CheckProto_1(const Contact& input, const bool silent)
{
    if (false == input.has_id()) {
        FAIL("contact", "missing id")
    }

    if (MIN_PLAUSIBLE_IDENTIFIER > input.id().size()) {
        FAIL2("contact", "invalid id", input.id())
    }

    if (MAX_PLAUSIBLE_IDENTIFIER < input.id().size()) {
        FAIL2("contact", "invalid id", input.id())
    }

    if (input.has_label()) {
        if (MAX_VALID_CONTACT_VALUE < input.label().size()) {
            FAIL2("contact", "invalid label", input.id())
        }
    }

    if (input.has_contactdata()) {
        try {
            const auto validContactData = Check(
                input.contactdata(),
                ContactAllowedContactData.at(input.version()).first,
                ContactAllowedContactData.at(input.version()).second,
                silent,
                CLAIMS_NORMAL);

            if (!validContactData) {
                FAIL("contact", "invalid contact data")
            }
        } catch (const std::out_of_range&) {
            FAIL2(
                "contact",
                "allowed contact data not defined for version",
                input.version())
        }
    }

    const bool merged = 0 < input.mergedto().size();
    const bool hasMerges = 0 < input.merged().size();

    if (merged && hasMerges) {
        FAIL("contact", "merged contact may not contain child merges")
    }

    if (merged) {
        if (MIN_PLAUSIBLE_IDENTIFIER > input.mergedto().size()) {
            FAIL2("contact", "invalid mergedto", input.mergedto())
        }

        if (MAX_PLAUSIBLE_IDENTIFIER < input.mergedto().size()) {
            FAIL2("contact", "invalid mergedto", input.mergedto())
        }
    }

    if (hasMerges) {
        for (const auto& merge : input.merged()) {
            if (MIN_PLAUSIBLE_IDENTIFIER > merge.size()) {
                FAIL2("contact", "invalid merge", merge)
            }

            if (MAX_PLAUSIBLE_IDENTIFIER < merge.size()) {
                FAIL2("contact", "invalid merge", merge)
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
    UNDEFINED_VERSION("contact", 3)
}

bool CheckProto_4(const Contact& input, const bool silent)
{
    UNDEFINED_VERSION("contact", 4)
}

bool CheckProto_5(const Contact& input, const bool silent)
{
    UNDEFINED_VERSION("contact", 5)
}

bool CheckProto_6(const Contact& input, const bool silent)
{
    UNDEFINED_VERSION2(6)
}

bool CheckProto_7(const Contact& input, const bool silent)
{
    UNDEFINED_VERSION2(7)
}

bool CheckProto_8(const Contact& input, const bool silent)
{
    UNDEFINED_VERSION2(8)
}

bool CheckProto_9(const Contact& input, const bool silent)
{
    UNDEFINED_VERSION2(9)
}

bool CheckProto_10(const Contact& input, const bool silent)
{
    UNDEFINED_VERSION2(10)
}

bool CheckProto_11(const Contact& input, const bool silent)
{
    UNDEFINED_VERSION2(11)
}

bool CheckProto_12(const Contact& input, const bool silent)
{
    UNDEFINED_VERSION2(12)
}

bool CheckProto_13(const Contact& input, const bool silent)
{
    UNDEFINED_VERSION2(13)
}

bool CheckProto_14(const Contact& input, const bool silent)
{
    UNDEFINED_VERSION2(14)
}

bool CheckProto_15(const Contact& input, const bool silent)
{
    UNDEFINED_VERSION2(15)
}

bool CheckProto_16(const Contact& input, const bool silent)
{
    UNDEFINED_VERSION2(16)
}

bool CheckProto_17(const Contact& input, const bool silent)
{
    UNDEFINED_VERSION2(17)
}

bool CheckProto_18(const Contact& input, const bool silent)
{
    UNDEFINED_VERSION2(18)
}

bool CheckProto_19(const Contact& input, const bool silent)
{
    UNDEFINED_VERSION2(19)
}

bool CheckProto_20(const Contact& input, const bool silent)
{
    UNDEFINED_VERSION2(20)
}
}  // namespace proto
}  // namespace opentxs
