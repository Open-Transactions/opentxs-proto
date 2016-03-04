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

#include "opentxs-proto/verify/VerifyContacts.hpp"

namespace opentxs { namespace proto
{
bool ValidContactSectionName(
    const uint32_t version,
    const ContactSectionName name)
{
    std::set<ContactSectionName> allowedNames = AllowedSectionNames.at(version);

    return (std::find(allowedNames.begin(), allowedNames.end(), name) != allowedNames.end());
}
bool ValidContactItemType(
    const ContactSectionVersion version,
    const ContactItemType itemType)
{
    std::set<ContactItemType> allowedTypes = AllowedItemTypes.at(version);

    return (std::find(allowedTypes.begin(), allowedTypes.end(), itemType) != allowedTypes.end());
}
bool ValidContactItemAttribute(
    const uint32_t version,
    const ContactItemAttribute attribute)
{
    std::set<ContactItemAttribute> allowedAttributes = AllowedItemAttributes.at(version);

    return (std::find(allowedAttributes.begin(), allowedAttributes.end(), attribute) != allowedAttributes.end());
}

std::string TranslateSectionName(
    const uint32_t enumValue,
    const std::string& lang)
{
    EnumLang langPair{enumValue, lang};

    for (auto& it : ContactSectionNames) {
        if (langPair == it.first) {
            return it.second;
        }
    }

    return "";
}
std::string TranslateItemType(
    const uint32_t enumValue,
    const std::string& lang)
{
    EnumLang langPair{enumValue, lang};

    for (auto& it : ContactItemTypes) {
        if (langPair == it.first) {
            return it.second;
        }
    }

    return "";
}
std::string TranslateItemAttributes(
    const uint32_t enumValue,
    const std::string& lang)
{
    EnumLang langPair{enumValue, lang};

    for (auto& it : ContactItemAttributes) {
        if (langPair == it.first) {
            return it.second;
        }
    }

    return "";
}

uint32_t ReciprocalRelationship(const uint32_t relationship)
{
    auto input = static_cast<ContactItemType>(relationship);

    bool found = (RelationshipMap.find(input) != RelationshipMap.end());

    if (found) {
        return RelationshipMap.at(input);
    }

    return CITEMTYPE_ERROR;
}

} // namespace proto
} // namespace opentxs
