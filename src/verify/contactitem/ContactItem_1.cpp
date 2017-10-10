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

bool CheckProto_1(
    const ContactItem& contactItem,
    const bool silent,
    const ClaimType indexed,
    const ContactSectionVersion parentVersion)
{
    if (indexed) {
        if (!contactItem.has_id()) {
            FAIL("contact item", "missing id")
        }

        if (MIN_PLAUSIBLE_IDENTIFIER > contactItem.id().size()) {
            FAIL("contact item", "invalid id")
        }

        if (MAX_PLAUSIBLE_IDENTIFIER < contactItem.id().size()) {
            FAIL("contact item", "invalid id")
        }
    } else {
        if (contactItem.has_id()) {
            FAIL("contact item", "id not blank")
        }
    }

    if (!contactItem.has_type()) {
        FAIL("contact item", "missing type")
    }

    if (!ValidContactItemType(parentVersion, contactItem.type())) {
        FAIL("contact item", "invalid type")
    }

    if (!contactItem.has_value()) {
        FAIL("contact item", "missing value")
    }

    for (auto& it : contactItem.attribute()) {
        if (!ValidContactItemAttribute(
                contactItem.version(), static_cast<ContactItemAttribute>(it))) {
            FAIL("contact item", "invalid attribute")
        }
    }

    if (contactItem.has_subtype()) {
        if (3 > contactItem.version()) {
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
    const ContactItem& contactItem,
    const bool silent,
    const ClaimType indexed,
    const ContactSectionVersion parentVersion)
{
    return CheckProto_1(contactItem, silent, indexed, parentVersion);
}

bool CheckProto_3(
    const ContactItem& contactItem,
    const bool silent,
    const ClaimType indexed,
    const ContactSectionVersion parentVersion)
{
    return CheckProto_1(contactItem, silent, indexed, parentVersion);
}

bool CheckProto_4(
    const ContactItem& contactItem,
    const bool silent,
    const ClaimType indexed,
    const ContactSectionVersion parentVersion)
{
    return CheckProto_1(contactItem, silent, indexed, parentVersion);
}

bool CheckProto_5(
    const ContactItem& contactItem,
    const bool silent,
    const ClaimType indexed,
    const ContactSectionVersion parentVersion)
{
    return CheckProto_1(contactItem, silent, indexed, parentVersion);
}
}  // namespace proto
}  // namespace opentxs
