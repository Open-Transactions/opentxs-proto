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
    const ContactSection& input,
    const bool silent,
    const ClaimType indexed,
    const uint32_t parentVersion)
{
    if (!input.has_name()) {
        FAIL("contact section", "missing name")
    }

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

            if (!validItem) {
                FAIL("contact section", "invalid item")
            }
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
}  // namespace proto
}  // namespace opentxs
