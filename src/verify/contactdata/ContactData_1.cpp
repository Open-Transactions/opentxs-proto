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
    const ContactData& contactData,
    const bool silent,
    const ClaimType indexed)
{
    std::map<ContactSectionName, uint32_t> sectionCount;

    for (auto& it : contactData.section()) {
        try {
            bool validSection = Check(
                it,
                ContactDataAllowedSection.at(contactData.version()).first,
                ContactDataAllowedSection.at(contactData.version()).second,
                silent,
                indexed,
                contactData.version());

            if (!validSection) {
                FAIL("contact data", "invalid section")
            }
        } catch (const std::out_of_range&) {
            FAIL2(
                "contact data",
                "allowed contact section version not defined for version",
                contactData.version())
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
    const ContactData& contactData,
    const bool silent,
    const ClaimType indexed)
{
    return CheckProto_1(contactData, silent, indexed);
}

bool CheckProto_3(
    const ContactData& contactData,
    const bool silent,
    const ClaimType indexed)
{
    return CheckProto_1(contactData, silent, indexed);
}

bool CheckProto_4(
    const ContactData& contactData,
    const bool silent,
    const ClaimType indexed)
{
    return CheckProto_1(contactData, silent, indexed);
}

bool CheckProto_5(const ContactData&, const bool, const ClaimType)
{
    return false;
}
}  // namespace proto
}  // namespace opentxs
