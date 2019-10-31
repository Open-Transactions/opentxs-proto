// Copyright (c) 2019 The Open-Transactions developers
// This Source Code Form is subject to the terms of the Mozilla Public
// License, v. 2.0. If a copy of the MPL was not distributed with this
// file, You can obtain one at http://mozilla.org/MPL/2.0/.

#ifndef OPENTXS_PROTO_CONTACT
#define OPENTXS_PROTO_CONTACT

#include <map>
#include <set>

#pragma GCC diagnostic push
#pragma GCC diagnostic ignored "-Wlanguage-extension-token"
#pragma GCC diagnostic ignored "-Wundef"
#pragma GCC diagnostic ignored "-Wdeprecated-dynamic-exception-spec"
#pragma GCC diagnostic ignored "-Wzero-as-null-pointer-constant"
#pragma GCC diagnostic ignored "-Wsign-conversion"
#pragma GCC diagnostic ignored "-Winconsistent-missing-destructor-override¶"
#include "opentxs-proto/ContactEnums.pb.h"  // IWYU pragma: export
#pragma GCC diagnostic pop

namespace opentxs
{
namespace proto
{
// A map of allowed section names by ContactData version
using ContactSectionMap = std::map<uint32_t, std::set<ContactSectionName>>;
// A map of allowed item types by ContactSection version
using ContactSectionVersion = std::pair<uint32_t, ContactSectionName>;
using ContactItemMap =
    std::map<ContactSectionVersion, std::set<ContactItemType>>;
// A map of allowed item attributes by ContactItem version
using ItemAttributeMap = std::map<uint32_t, std::set<ContactItemAttribute>>;
// Maps for converting enum values to human-readable names
using EnumLang = std::pair<uint32_t, std::string>;
using EnumTranslation = std::map<EnumLang, std::string>;
// A map for storing relationship reciprocities
using RelationshipReciprocity = std::map<ContactItemType, ContactItemType>;

OPENTXS_PROTO_EXPORT const ContactSectionMap& AllowedSectionNames() noexcept;
OPENTXS_PROTO_EXPORT const ContactItemMap& AllowedItemTypes() noexcept;
OPENTXS_PROTO_EXPORT const ItemAttributeMap& AllowedItemAttributes() noexcept;
OPENTXS_PROTO_EXPORT const std::set<ContactSectionName>&
AllowedSubtypes() noexcept;
OPENTXS_PROTO_EXPORT const EnumTranslation& ContactSectionNames() noexcept;
OPENTXS_PROTO_EXPORT const EnumTranslation& ContactItemTypes() noexcept;
OPENTXS_PROTO_EXPORT const EnumTranslation& ContactItemAttributes() noexcept;
OPENTXS_PROTO_EXPORT const RelationshipReciprocity& RelationshipMap() noexcept;
}  // namespace proto
}  // namespace opentxs
#endif  // OPENTXS_PROTO_CONTACT
