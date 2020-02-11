// Copyright (c) 2020 The Open-Transactions developers
// This Source Code Form is subject to the terms of the Mozilla Public
// License, v. 2.0. If a copy of the MPL was not distributed with this
// file, You can obtain one at http://mozilla.org/MPL/2.0/.

#include "opentxs-proto/verify/VerifyContacts.hpp"
#include "opentxs-proto/verify/VerifyCredentials.hpp"

namespace opentxs
{
namespace proto
{
const VersionMap& ContactAllowedContactData() noexcept
{
    static const auto output = VersionMap{
        {1, {1, 4}},
        {2, {5, 5}},
        {3, {6, 6}},
    };

    return output;
}
const VersionMap& ContactDataAllowedContactSection() noexcept
{
    static const auto output = VersionMap{
        {1, {1, 1}},
        {2, {1, 2}},
        {3, {1, 3}},
        {4, {4, 4}},
        {5, {5, 5}},
        {6, {6, 6}},
    };

    return output;
}
const VersionMap& ContactSectionAllowedItem() noexcept
{
    static const auto output = VersionMap{
        {1, {1, 1}},
        {2, {1, 2}},
        {3, {1, 3}},
        {4, {4, 4}},
        {5, {5, 5}},
        {6, {6, 6}},
    };

    return output;
}
const VersionMap& VerificationAllowedSignature() noexcept
{
    static const auto output = VersionMap{
        {1, {1, 1}},
    };

    return output;
}
const VersionMap& VerificationGroupAllowedIdentity() noexcept
{
    static const auto output = VersionMap{
        {1, {1, 1}},
    };

    return output;
}
const VersionMap& VerificationIdentityAllowedVerification() noexcept
{
    static const auto output = VersionMap{
        {1, {1, 1}},
    };

    return output;
}
const VersionMap& VerificationOfferAllowedClaim() noexcept
{
    static const auto output = VersionMap{
        {1, {1, 1}},
    };

    return output;
}
const VersionMap& VerificationOfferAllowedVerification() noexcept
{
    static const auto output = VersionMap{
        {1, {1, 1}},
    };

    return output;
}
const VersionMap& VerificationSetAllowedGroup() noexcept
{
    static const auto output = VersionMap{
        {1, {1, 1}},
    };

    return output;
}
bool ValidContactSectionName(
    const std::uint32_t version,
    const ContactSectionName name)
{
    std::set<ContactSectionName> allowedNames =
        AllowedSectionNames().at(version);

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
    std::set<ContactItemType> allowedTypes = AllowedItemTypes().at(version);

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
    const auto allowedAttributes = AllowedItemAttributes().at(version);

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

    for (auto& it : ContactSectionNames()) {
        if (langPair == it.first) { return it.second; }
    }

    return "";
}
std::string TranslateItemType(
    const std::uint32_t enumValue,
    const std::string& lang)
{
    EnumLang langPair{enumValue, lang};

    for (auto& it : ContactItemTypes()) {
        if (langPair == it.first) { return it.second; }
    }

    return "";
}
std::string TranslateItemAttributes(
    const std::uint32_t enumValue,
    const std::string& lang)
{
    EnumLang langPair{enumValue, lang};

    for (auto& it : ContactItemAttributes()) {
        if (langPair == it.first) { return it.second; }
    }

    return "";
}

std::uint32_t ReciprocalRelationship(const std::uint32_t relationship)
{
    auto input = static_cast<ContactItemType>(relationship);

    bool found = (RelationshipMap().find(input) != RelationshipMap().end());

    if (found) {
        try {
            return static_cast<std::uint32_t>(RelationshipMap().at(input));
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
    const auto it = AllowedItemTypes().find(key);
    const bool keyExists = AllowedItemTypes().end() != it;

    if (keyExists) {
        for (const auto& allowedType : it->second) {
            if (type == allowedType) { return true; }
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
    for (std::uint32_t n = hint;
         n <= ContactSectionAllowedItem().rbegin()->first;
         ++n) {
        try {
            const auto exists = AllowedItemTypes().at({n, section}).count(type);

            if (1 == exists) { return n; }
        } catch (const std::out_of_range&) {
        }
    }

    return 0;
}

std::uint32_t NymRequiredVersion(
    const std::uint32_t contactDataVersion,
    const std::uint32_t hint)
{
    for (std::uint32_t n = hint;
         n <= ContactSectionAllowedItem().rbegin()->first;
         ++n) {
        try {
            const auto maxAuthority = NymAllowedAuthority().at(n).second;
            const auto maxCredential =
                AuthorityAllowedCredential().at(maxAuthority).second;
            const auto maxContactData =
                CredentialAllowedContactData().at(maxCredential).second;

            if (maxContactData >= contactDataVersion) { return n; }
        } catch (const std::out_of_range&) {

            return 0;
        }
    }

    return 0;
}

std::uint32_t RequiredAuthorityVersion(
    const std::uint32_t contactDataVersion,
    const std::uint32_t hint)
{
    for (std::uint32_t n = hint;
         n <= ContactSectionAllowedItem().rbegin()->first;
         ++n) {
        try {
            const auto maxCredential =
                AuthorityAllowedCredential().at(n).second;
            const auto maxContactData =
                CredentialAllowedContactData().at(maxCredential).second;

            if (maxContactData >= contactDataVersion) { return n; }
        } catch (const std::out_of_range&) {
        }
    }

    return 0;
}
}  // namespace proto
}  // namespace opentxs
