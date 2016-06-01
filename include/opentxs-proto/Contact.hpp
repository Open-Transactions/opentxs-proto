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

#ifndef OPENTXS_PROTO_CONTACT
#define OPENTXS_PROTO_CONTACT

#include <map>
#include <set>

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
#include "opentxs-proto/ContactEnums.pb.h"
#ifdef _WIN32
#pragma warning(pop)
#else
#pragma GCC diagnostic pop
#endif

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

    // A map for storing relationship reciprocities
    typedef std::map<ContactItemType, ContactItemType> RelationshipReciprocity;

    static const ContactSectionMap AllowedSectionNames =
    {
        {
            1,
            {
                CONTACTSECTION_NAME,
                CONTACTSECTION_MESSAGING,
                CONTACTSECTION_PROFILE,
                CONTACTSECTION_URL,
                CONTACTSECTION_ACCOMPLISHMENTS,
                CONTACTSECTION_RELATIONSHIPS,
                CONTACTSECTION_FINGERPRINTS,
                CONTACTSECTION_CONTRACTS
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
                CITEMTYPE_SERVICE,
                CITEMTYPE_ORGANIZATION
            }
        },
        {
            {1, CONTACTSECTION_MESSAGING},
            {
                CITEMTYPE_EMAIL,
                CITEMTYPE_PHONE,
                CITEMTYPE_BITMESSAGE,
                CITEMTYPE_OPENTXS
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
        },
        {
            {1, CONTACTSECTION_RELATIONSHIPS},
            {
                CITEMTYPE_PARENT,
                CITEMTYPE_CHILD,
                CITEMTYPE_SIBLING,
                CITEMTYPE_EMPLOYER,
                CITEMTYPE_EMPLOYEE,
                CITEMTYPE_MET,
                CITEMTYPE_ALIAS
            }
        },
        {
            {1, CONTACTSECTION_FINGERPRINTS},
            {
                CITEMTYPE_PGP,
                CITEMTYPE_OTR,
                CITEMTYPE_SSL
            }
        },
        {
            {1, CONTACTSECTION_CONTRACTS},
            {
                CITEMTYPE_BITCOIN
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
        {{CONTACTSECTION_MESSAGING, "en"}, "Messaging"},
        {{CONTACTSECTION_PROFILE, "en"}, "Profile"},
        {{CONTACTSECTION_URL, "en"}, "URL"},
        {{CONTACTSECTION_ACCOMPLISHMENTS, "en"}, "Accomplishments"},
        {{CONTACTSECTION_RELATIONSHIPS, "en"}, "Relationships"},
        {{CONTACTSECTION_FINGERPRINTS, "en"}, "Fingerprints"},
        {{CONTACTSECTION_CONTRACTS, "en"}, "Contracts"}
    };
    static const EnumTranslation ContactItemTypes =
    {
        {{CITEMTYPE_PERSONAL, "en"}, "Personal"},
        {{CITEMTYPE_BUSINESS, "en"}, "Business"},
        {{CITEMTYPE_NICKNAME, "en"}, "Nickname"},
        {{CITEMTYPE_EMAIL, "en"}, "Email"},
        {{CITEMTYPE_PHONE, "en"}, "Phone"},
        {{CITEMTYPE_BITMESSAGE, "en"}, "Bitmessage"},
        {{CITEMTYPE_OPENTXS, "en"}, "OT"},
        {{CITEMTYPE_FACEBOOK, "en"}, "Facebook"},
        {{CITEMTYPE_TWITTER, "en"}, "Twitter"},
        {{CITEMTYPE_GOOGLE, "en"}, "Google"},
        {{CITEMTYPE_PROFESSIONAL, "en"}, "Professional"},
        {{CITEMTYPE_PARENT, "en"}, "Parent of"},
        {{CITEMTYPE_CHILD, "en"}, "Child of"},
        {{CITEMTYPE_SIBLING, "en"}, "Sibling of"},
        {{CITEMTYPE_EMPLOYER, "en"}, "Employer of"},
        {{CITEMTYPE_EMPLOYEE, "en"}, "Employee of"},
        {{CITEMTYPE_MET, "en"}, "Have met"},
        {{CITEMTYPE_ALIAS, "en"}, "Alias of"},
        {{CITEMTYPE_PGP, "en"}, "PGP key"},
        {{CITEMTYPE_OTR, "en"}, "OTR key"},
        {{CITEMTYPE_SSL, "en"}, "SSL certificate"},
        {{CITEMTYPE_BITCOIN, "en"}, "Bitcoin"}
    };
    static const EnumTranslation ContactItemAttributes =
    {
        {{CITEMATTR_ACTIVE, "en"}, "Active"},
        {{CITEMATTR_PRIMARY, "en"}, "Primary"}
    };
    static const RelationshipReciprocity RelationshipMap =
    {
        {CITEMTYPE_PARENT, CITEMTYPE_CHILD},
        {CITEMTYPE_CHILD, CITEMTYPE_PARENT},
        {CITEMTYPE_SIBLING, CITEMTYPE_SIBLING},
        {CITEMTYPE_EMPLOYER, CITEMTYPE_EMPLOYEE},
        {CITEMTYPE_EMPLOYEE, CITEMTYPE_EMPLOYER},
        {CITEMTYPE_MET, CITEMTYPE_MET},
        {CITEMTYPE_ALIAS, CITEMTYPE_ALIAS}
    };
} // namespace proto
} // namespace opentxs
#endif // OPENTXS_PROTO_CONTACT
