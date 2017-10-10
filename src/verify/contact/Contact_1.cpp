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

namespace opentxs
{
namespace proto
{

bool CheckProto_1(const Contact& contact, const bool silent)
{
    if (false == contact.has_id()) {
        FAIL("contact", "missing id")
    }

    if (MIN_PLAUSIBLE_IDENTIFIER > contact.id().size()) {
        FAIL2("contact", "invalid id", contact.id())
    }

    if (MAX_PLAUSIBLE_IDENTIFIER < contact.id().size()) {
        FAIL2("contact", "invalid id", contact.id())
    }

    if (contact.has_label()) {
        if (MAX_VALID_CONTACT_VALUE < contact.label().size()) {
            FAIL2("contact", "invalid label", contact.id())
        }
    }

    if (contact.has_contactdata()) {
        try {
            const auto validContactData = Check(
                contact.contactdata(),
                ContactAllowedContactData.at(contact.version()).first,
                ContactAllowedContactData.at(contact.version()).second,
                silent,
                CLAIMS_NORMAL);

            if (!validContactData) {
                FAIL("contact", "invalid contact data")
            }
        } catch (const std::out_of_range&) {
            FAIL2(
                "contact",
                "allowed contact data not defined for version",
                contact.version())
        }
    }

    const bool merged = 0 < contact.mergedto().size();
    const bool hasMerges = 0 < contact.merged().size();

    if (merged && hasMerges) {
        FAIL("contact", "merged contact may not contain child merges")
    }

    if (merged) {
        if (MIN_PLAUSIBLE_IDENTIFIER > contact.mergedto().size()) {
            FAIL2("contact", "invalid mergedto", contact.mergedto())
        }

        if (MAX_PLAUSIBLE_IDENTIFIER < contact.mergedto().size()) {
            FAIL2("contact", "invalid mergedto", contact.mergedto())
        }
    }

    if (hasMerges) {
        for (const auto& merge : contact.merged()) {
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
bool CheckProto_2(const Contact&, const bool silent)
{
    UNDEFINED_VERSION("contact", 2)
}

bool CheckProto_3(const Contact&, const bool silent)
{
    UNDEFINED_VERSION("contact", 3)
}

bool CheckProto_4(const Contact&, const bool silent)
{
    UNDEFINED_VERSION("contact", 4)
}

bool CheckProto_5(const Contact&, const bool silent)
{
    UNDEFINED_VERSION("contact", 5)
}
}  // namespace proto
}  // namespace opentxs
