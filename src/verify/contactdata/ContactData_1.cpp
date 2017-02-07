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

namespace opentxs { namespace proto
{

bool CheckProto_1(
    const ContactData& contactData,
    const ClaimType indexed)
{
    std::map <ContactSectionName, uint32_t> sectionCount;

    for (auto& it: contactData.section()) {
        bool validSection = Check(
            it,
            ContactDataAllowedSection.at(contactData.version()).first,
            ContactDataAllowedSection.at(contactData.version()).second,
            indexed,
            contactData.version());

        if (!validSection) {
            std::cerr << "Verify serialized contact data failed: invalid section." << std::endl;
            return false;
        }

        ContactSectionName name = it.name();

        if (sectionCount.count(name) > 0 ) {
            std::cerr << "Verify serialized contact data failed: duplicate section." << std::endl;
            return false;
        } else {
            sectionCount.insert({name, 1});
        }
    }

    return true;
}
bool CheckProto_2(const ContactData&, const ClaimType) { return false; }
} // namespace proto
} // namespace opentxs
