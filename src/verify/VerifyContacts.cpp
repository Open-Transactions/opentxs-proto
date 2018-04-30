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
#include "opentxs-proto/verify/VerifyCredentials.hpp"

namespace opentxs
{
namespace proto
{
bool ValidContactSectionName(
    const std::uint32_t version,
    const ContactSectionName name)
{
    std::set<ContactSectionName> allowedNames = AllowedSectionNames.at(version);

    try {
        return (
            std::find(allowedNames.begin(), allowedNames.end(), name) !=
            allowedNames.end());
    } catch (const std::out_of_range&) {
        return false;
    }
}

bool ValidContactItemType(
    const ContactSectionVersion version,
    const ContactItemType itemType)
{
    std::set<ContactItemType> allowedTypes = AllowedItemTypes.at(version);

    try {
        return (
            std::find(allowedTypes.begin(), allowedTypes.end(), itemType) !=
            allowedTypes.end());
    } catch (const std::out_of_range&) {
        return false;
    }
}
bool ValidContactItemAttribute(
    const std::uint32_t version,
    const ContactItemAttribute attribute)
{
    std::set<ContactItemAttribute> allowedAttributes =
        AllowedItemAttributes.at(version);

    try {
        return (
            std::find(
                allowedAttributes.begin(),
                allowedAttributes.end(),
                attribute) != allowedAttributes.end());
    } catch (const std::out_of_range&) {
        return false;
    }
}

std::string TranslateSectionName(
    const std::uint32_t enumValue,
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
    const std::uint32_t enumValue,
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
    const std::uint32_t enumValue,
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

std::uint32_t ReciprocalRelationship(const std::uint32_t relationship)
{
    auto input = static_cast<ContactItemType>(relationship);

    bool found = (RelationshipMap.find(input) != RelationshipMap.end());

    if (found) {
        try {
            return RelationshipMap.at(input);
        } catch (const std::out_of_range&) {
        }
    }

    return CITEMTYPE_ERROR;
}

bool CheckCombination(
    const ContactSectionName section,
    const ContactItemType type,
    const std::uint32_t version)
{
    const ContactSectionVersion key{version, section};
    const auto it = AllowedItemTypes.find(key);
    const bool keyExists = AllowedItemTypes.end() != it;

    if (keyExists) {
        for (const auto& allowedType : it->second) {
            if (type == allowedType) {

                return true;
            }
        }
    }

    return false;
}

// 0 means not a valid combination for any version
std::uint32_t RequiredVersion(
    const ContactSectionName section,
    const ContactItemType type,
    const std::uint32_t hint)
{
    for (std::uint32_t n = hint; n <= MAX_CONTACT_VERSION; ++n) {
        try {
            const auto exists = AllowedItemTypes.at({n, section}).count(type);

            if (1 == exists) {

                return n;
            }
        } catch (const std::out_of_range&) {
        }
    }

    return 0;
}

std::uint32_t NymRequiredVersion(
    const std::uint32_t contactDataVersion,
    const std::uint32_t hint)
{
    for (std::uint32_t n = hint; n <= MAX_CONTACT_VERSION; ++n) {
        try {
            const auto maxCredentialSet =
                CredentialIndexAllowedCredentialSets.at(n).second;
            const auto maxCredential =
                CredentialSetAllowedCredentials.at(maxCredentialSet).second;
            const auto maxContactData =
                CredentialAllowedContactData.at(maxCredential).second;

            if (maxContactData >= contactDataVersion) {

                return n;
            }
        } catch (const std::out_of_range&) {

            return 0;
        }
    }

    return 0;
}

std::uint32_t RequiredCredentialSetVersion(
    const std::uint32_t contactDataVersion,
    const std::uint32_t hint)
{
    for (std::uint32_t n = hint; n <= MAX_CONTACT_VERSION; ++n) {
        try {
            const auto maxCredential =
                CredentialSetAllowedCredentials.at(n).second;
            const auto maxContactData =
                CredentialAllowedContactData.at(maxCredential).second;

            if (maxContactData >= contactDataVersion) {

                return n;
            }
        } catch (const std::out_of_range&) {
        }
    }

    return 0;
}

}  // namespace proto
}  // namespace opentxs
