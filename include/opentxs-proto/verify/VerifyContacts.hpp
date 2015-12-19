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

#ifndef OPENTXS_PROTO_VERIFYCONTACTS_HPP
#define OPENTXS_PROTO_VERIFYCONTACTS_HPP

#ifdef _WIN32
#pragma warning(push)
#pragma warning(disable : 4244)
#pragma warning(disable : 4267)
#else
#pragma GCC diagnostic push
#pragma GCC diagnostic ignored "-Wshadow"
#ifndef __clang__
// -Wuseless-cast does not exist in clang
#pragma GCC diagnostic ignored "-Wuseless-cast"
#endif
#endif

#ifdef OPENTXS_PROTO_INTERNAL_BUILD
#include "ContactEnums.pb.h"
#include "ContactData.pb.h"
#include "VerifyCredentials.hpp"
#else
#include <opentxs-proto/ContactEnums.pb.h>
#include <opentxs-proto/ContactData.pb.h>
#include <opentxs-proto/verify/VerifyCredentials.hpp>
#endif

#ifdef _WIN32
#pragma warning(pop)
#else
#pragma GCC diagnostic pop
#endif

#include <algorithm>
#include <map>
#include <set>
#include <utility>

namespace opentxs { namespace proto
{
    // A map of allowed section names by ContactData version
    typedef std::map<uint32_t, std::set<ContactSectionName>> ContactSectionMap;

    // A map of allowed item types by ContactSection version
    typedef std::pair<uint32_t, ContactSectionName> ContactSectionVersion;
    typedef std::map<ContactSectionVersion, std::set<ContactItemType>> ContactItemMap;

    // A map of allowed item attributes by ContactItem version
    typedef std::map<uint32_t, std::set<ContactItemAttribute>> ItemAttributeMap;

    // Maps for converting enum values to human-readable names
    typedef std::pair<uint32_t, std::string> EnumLang;
    typedef std::map<EnumLang, std::string> EnumTranslation;

    static const VersionMap ContactDataAllowedSection =
        {
            { 1, {1, 1}},
        };
    static const VersionMap ContactSectionAllowedItem =
        {
            { 1, {1, 1}},
        };

    static const ContactSectionMap AllowedSectionNames =
        {
            {
                1,
                {
                    CONTACTSECTION_NAME,
                    CONTACTSECTION_EMAIL,
                    CONTACTSECTION_PHONE,
                    CONTACTSECTION_BITMESSAGE,
                    CONTACTSECTION_PROFILE,
                    CONTACTSECTION_URL,
                    CONTACTSECTION_ACCOMPLISHMENTS
                }
            },
        };
    static const ContactItemMap AllowedItemTypes =
        {
            {
                {1, CONTACTSECTION_NAME},
                {
                    CITEMTYPE_PERSONAL,
                    CITEMTYPE_BUSINESS,
                    CITEMTYPE_NICKNAME,
                }
            },
            {
                {1, CONTACTSECTION_EMAIL},
                {
                    CITEMTYPE_PERSONAL,
                    CITEMTYPE_BUSINESS
                }
            },
            {
                {1, CONTACTSECTION_PHONE},
                {
                    CITEMTYPE_PERSONAL,
                    CITEMTYPE_BUSINESS
                }
            },
            {
                {1, CONTACTSECTION_BITMESSAGE},
                {
                    CITEMTYPE_PERSONAL,
                    CITEMTYPE_BUSINESS
                }
            },
            {
                {1, CONTACTSECTION_PROFILE},
                {
                    CITEMTYPE_FACEBOOK,
                    CITEMTYPE_TWITTER,
                    CITEMTYPE_GOOGLE
                }
            },
            {
                {1, CONTACTSECTION_URL},
                {
                    CITEMTYPE_PERSONAL,
                    CITEMTYPE_BUSINESS
                }
            },
            {
                {1, CONTACTSECTION_ACCOMPLISHMENTS},
                {
                    CITEMTYPE_PERSONAL,
                    CITEMTYPE_PROFESSIONAL
                }
            }
        };
    static const ItemAttributeMap AllowedItemAttributes =
        {
            {
                1,
                {
                    CITEMATTR_ACTIVE,
                    CITEMATTR_PRIMARY
                }
            },
        };

    static const EnumTranslation ContactSectionNames =
        {
            {{CONTACTSECTION_NAME, "en"}, "Names"},
            {{CONTACTSECTION_EMAIL, "en"}, "Email"},
            {{CONTACTSECTION_PHONE, "en"}, "Phone"},
            {{CONTACTSECTION_BITMESSAGE, "en"}, "Bitmessage"},
            {{CONTACTSECTION_PROFILE, "en"}, "Profile"},
            {{CONTACTSECTION_URL, "en"}, "URL"},
            {{CONTACTSECTION_ACCOMPLISHMENTS, "en"}, "Accomplishments"}
        };
    static const EnumTranslation ContactItemTypes =
        {
            {{CITEMTYPE_PERSONAL, "en"}, "Personal"},
            {{CITEMTYPE_BUSINESS, "en"}, "Business"},
            {{CITEMTYPE_NICKNAME, "en"}, "Nickname"},
            {{CITEMTYPE_FACEBOOK, "en"}, "Facebook"},
            {{CITEMTYPE_TWITTER, "en"}, "Twitter"},
            {{CITEMTYPE_GOOGLE, "en"}, "Google"},
            {{CITEMTYPE_PROFESSIONAL, "en"}, "Professional"}
        };
    static const EnumTranslation ContactItemAttributes =
        {
            {{CITEMATTR_ACTIVE, "en"}, "Active"},
            {{CITEMATTR_PRIMARY, "en"}, "Primary"}
        };

    bool Verify(
        const ContactData& contactData,
        const uint32_t minVersion = 0,
        const uint32_t maxVersion = 0xffffffff);

    bool Verify(
        const ContactSection& contactSection,
        const uint32_t minVersion = 0,
        const uint32_t maxVersion = 0xffffffff,
        const uint32_t parentVersion = 0xffffffff);

    bool Verify(
        const ContactItem& contactItem,
        const ContactSectionVersion parentVersion,
        const uint32_t minVersion = 0,
        const uint32_t maxVersion = 0xffffffff);

    bool ValidContactSectionName(
        const uint32_t version,
        const ContactSectionName name);
    bool ValidContactItemType(
        const ContactSectionVersion version,
        const ContactItemType itemType);
    bool ValidContactItemAttribute(
        const uint32_t version,
        const ContactItemAttribute attribute);

    std::string TranslateSectionName(uint32_t enumValue, std::string lang = "en");
    std::string TranslateItemType(uint32_t enumValue, std::string lang = "en");
    std::string TranslateItemAttributes(uint32_t enumValue, std::string lang = "en");

} // namespace proto
} // namespace opentxs
#endif // OPENTXS_PROTO_VERIFYCONTACTS_HPP
