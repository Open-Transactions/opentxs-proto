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
    const ContactSection& contactSection,
    const ClaimType indexed,
    const uint32_t parentVersion)
{
    if (!contactSection.has_name()) {
        std::cerr << "Verify serialized contact section failed: "
                  << "missing name." << std::endl;

        return false;
    }

    if (!ValidContactSectionName(parentVersion, contactSection.name())) {
        std::cerr << "Verify serialized contact section failed: "
                  << "invalid name." << std::endl;

        return false;
    }

    for (auto& it: contactSection.item()) {
        bool validItem = Check(
            it,
            ContactSectionAllowedItem.at(contactSection.version()).first,
            ContactSectionAllowedItem.at(contactSection.version()).second,
            indexed,
            ContactSectionVersion{
                contactSection.version(), contactSection.name()});

        if (!validItem) {
            std::cerr << "Verify serialized contact section failed: "
                      << "invalid item." << std::endl;

            return false;
        }
    }

    return true;
}

bool CheckProto_2(
    const ContactSection& contactSection,
    const ClaimType indexed,
    const uint32_t parentVersion)
{
    return CheckProto_1(contactSection, indexed, parentVersion);
}

bool CheckProto_3(
    const ContactSection&,
    const ClaimType,
    const uint32_t)
{
    return false;
}

bool CheckProto_4(
    const ContactSection&,
    const ClaimType,
    const uint32_t)
{
    return false;
}

bool CheckProto_5(
    const ContactSection&,
    const ClaimType,
    const uint32_t)
{
    return false;
}
} // namespace proto
} // namespace opentxs
