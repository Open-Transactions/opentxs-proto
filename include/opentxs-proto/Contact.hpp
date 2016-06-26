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
#include "opentxs-proto/ContactEnums.pb.h" // IWYU pragma: export
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
                CONTACTSECTION_SCOPE,
                CONTACTSECTION_IDENTIFIER,
                CONTACTSECTION_ADDRESS,
                CONTACTSECTION_COMMUNICATION,
                CONTACTSECTION_PROFILE,
                CONTACTSECTION_RELATIONSHIP,
                CONTACTSECTION_DESCRIPTOR,
                CONTACTSECTION_EVENT,
                CONTACTSECTION_CONTRACT
            }
        },
    };
    static const ContactItemMap AllowedItemTypes =
    {
        {
            {1, CONTACTSECTION_SCOPE},
            {
                CITEMTYPE_INDIVIDUAL,
                CITEMTYPE_ORGANIZATION,
                CITEMTYPE_BUSINESS,
                CITEMTYPE_GOVERNMENT,
                CITEMTYPE_SERVER
            }
        },
        {
            {1, CONTACTSECTION_IDENTIFIER},
            {
                CITEMTYPE_PREFIX,
                CITEMTYPE_FORENAME,
                CITEMTYPE_MIDDLENAME,
                CITEMTYPE_SURNAME,
                CITEMTYPE_PEDIGREE,
                CITEMTYPE_SUFFIX,
                CITEMTYPE_NICKNAME,
                CITEMTYPE_COMMONNAME,
                CITEMTYPE_PASSPORT,
                CITEMTYPE_NATIONAL,
                CITEMTYPE_PROVINCIAL,
                CITEMTYPE_MILITARY,
                CITEMTYPE_PGP,
                CITEMTYPE_OTR,
                CITEMTYPE_SSL,
                CITEMTYPE_SKYPE,
                CITEMTYPE_QQ,
                CITEMTYPE_VK,
                CITEMTYPE_ONENAME,
                CITEMTYPE_TWITTER,
                CITEMTYPE_MEDIUM,
                CITEMTYPE_TUMBLR,
                CITEMTYPE_YAHOO,
                CITEMTYPE_MYSPACE,
                CITEMTYPE_MEETUP,
                CITEMTYPE_REDDIT,
                CITEMTYPE_HACKERNEWS,
                CITEMTYPE_WIKIPEDIA,
                CITEMTYPE_ANGELLIST,
                CITEMTYPE_GITHUB,
                CITEMTYPE_BITBUCKET,
                CITEMTYPE_YOUTUBE,
                CITEMTYPE_VIMEO,
                CITEMTYPE_TWITCH,
                CITEMTYPE_SNAPCHAT,
                CITEMTYPE_VINE,
                CITEMTYPE_INSTAGRAM,
                CITEMTYPE_PINTREST,
                CITEMTYPE_IMGUR,
                CITEMTYPE_FLICKR,
                CITEMTYPE_DRIBBLE,
                CITEMTYPE_BEHANCE,
                CITEMTYPE_DEVIANTART,
                CITEMTYPE_SPOTIFY,
                CITEMTYPE_ITUNES,
                CITEMTYPE_SOUNDCLOUD,
                CITEMTYPE_ASKFM,
                CITEMTYPE_EBAY,
                CITEMTYPE_ETSY,
                CITEMTYPE_OPENBAZAAR,
                CITEMTYPE_XBOXLIVE,
                CITEMTYPE_PLAYSTATION,
                CITEMTYPE_SECONDLIFE,
                CITEMTYPE_WARCRAFT,
                CITEMTYPE_EMPLOYEE,

            }
        },
        {
            {1, CONTACTSECTION_ADDRESS},
            {
                CITEMTYPE_PHYSICAL,
                CITEMTYPE_OFFICIAL,
                CITEMTYPE_BIRTHPLACE,
                CITEMTYPE_HOME,
                CITEMTYPE_WEBSITE,
                CITEMTYPE_OPENTXS,
                CITEMTYPE_BTC,
                CITEMTYPE_ETH,
                CITEMTYPE_XRP,
                CITEMTYPE_LTC,
                CITEMTYPE_DAO,
                CITEMTYPE_XEM,
                CITEMTYPE_DASH,
                CITEMTYPE_MAID,
                CITEMTYPE_LSK,
                CITEMTYPE_DOGE,
                CITEMTYPE_DGD,
                CITEMTYPE_XMR,
                CITEMTYPE_WAVES,
                CITEMTYPE_NXT,
                CITEMTYPE_SC,
                CITEMTYPE_STEEM,
                CITEMTYPE_AMP,
                CITEMTYPE_XLM,
                CITEMTYPE_FCT,
                CITEMTYPE_BTS
            }
        },
        {
            {1, CONTACTSECTION_COMMUNICATION},
            {
                CITEMTYPE_OPENTXS,
                CITEMTYPE_PHONE,
                CITEMTYPE_EMAIL,
                CITEMTYPE_SKYPE,
                CITEMTYPE_WIRE,
                CITEMTYPE_QQ,
                CITEMTYPE_BITMESSAGE,
                CITEMTYPE_WHATSAPP,
                CITEMTYPE_TELEGRAM,
                CITEMTYPE_KIK,
                CITEMTYPE_BBM,
                CITEMTYPE_WECHAT,
                CITEMTYPE_KAKAOTALK,
                CITEMTYPE_FACEBOOK,
                CITEMTYPE_GOGGLE,
                CITEMTYPE_LINKEDIN,
                CITEMTYPE_VK,
                CITEMTYPE_TWITTER,
                CITEMTYPE_SNAPCHAT,
                CITEMTYPE_VINE,
                CITEMTYPE_INSTAGRAM,
                CITEMTYPE_PINTREST,
                CITEMTYPE_IMGUR,
                CITEMTYPE_FLICKR,
                CITEMTYPE_DRIBBLE,
                CITEMTYPE_BEHANCE,
                CITEMTYPE_DEVIANTART,
                CITEMTYPE_SPOTIFY,
                CITEMTYPE_ITUNES,
                CITEMTYPE_SOUNDCLOUD,
                CITEMTYPE_ASKFM,
                CITEMTYPE_EBAY,
                CITEMTYPE_ETSY,
                CITEMTYPE_OPENBAZAAR,
                CITEMTYPE_XBOXLIVE,
                CITEMTYPE_PLAYSTATION,
                CITEMTYPE_SECONDLIFE,
                CITEMTYPE_WARCRAFT
            }
        },
        {
            {1, CONTACTSECTION_PROFILE},
            {
                CITEMTYPE_FACEBOOK,
                CITEMTYPE_GOGGLE,
                CITEMTYPE_LINKEDIN,
                CITEMTYPE_VK,
                CITEMTYPE_ABOUTME,
                CITEMTYPE_ONENAME,
                CITEMTYPE_TWITTER,
                CITEMTYPE_MEDIUM,
                CITEMTYPE_TUMBLR,
                CITEMTYPE_YAHOO,
                CITEMTYPE_MYSPACE,
                CITEMTYPE_MEETUP,
                CITEMTYPE_REDDIT,
                CITEMTYPE_HACKERNEWS,
                CITEMTYPE_WIKIPEDIA,
                CITEMTYPE_ANGELLIST,
                CITEMTYPE_GITHUB,
                CITEMTYPE_BITBUCKET,
                CITEMTYPE_YOUTUBE,
                CITEMTYPE_VIMEO,
                CITEMTYPE_TWITCH,
                CITEMTYPE_SNAPCHAT
            }
        },
        {
            {1, CONTACTSECTION_RELATIONSHIP},
            {
                CITEMTYPE_ORGANIZATION,
                CITEMTYPE_GOVERNMENT,
                CITEMTYPE_ALIAS,
                CITEMTYPE_ACQUAINTANCE,
                CITEMTYPE_FRIEND,
                CITEMTYPE_SPOUSE,
                CITEMTYPE_SIBLING,
                CITEMTYPE_MEMBER,
                CITEMTYPE_COLLEGUE,
                CITEMTYPE_PARENT,
                CITEMTYPE_CHILD,
                CITEMTYPE_EMPLOYER,
                CITEMTYPE_EMPLOYEE,
                CITEMTYPE_CITIZEN
            }
        },
        {
            {1, CONTACTSECTION_DESCRIPTOR},
            {
                CITEMTYPE_PHOTO,
                CITEMTYPE_GENDER,
                CITEMTYPE_HEIGHT,
                CITEMTYPE_WEIGHT,
                CITEMTYPE_HAIR,
                CITEMTYPE_EYE,
                CITEMTYPE_SKIN,
                CITEMTYPE_ETHNICITY,
                CITEMTYPE_LANGUAGE,
                CITEMTYPE_DEGREE,
                CITEMTYPE_CERTIFICATION,
                CITEMTYPE_TITLE,
                CITEMTYPE_SKILL,
                CITEMTYPE_AWARD,
                CITEMTYPE_LIKES,
                CITEMTYPE_SEXUAL,
                CITEMTYPE_POLIGICAL,
                CITEMTYPE_RELIGIOUS
            }
        },
        {
            {1, CONTACTSECTION_EVENT},
            {
                CITEMTYPE_BIRTH,
                CITEMTYPE_SECONDARYGRADUATION,
                CITEMTYPE_UNIVERSITYGRADUTATION,
                CITEMTYPE_WEDDING,
                CITEMTYPE_ACCOMPLISHMENT
            }
        },
        {
            {1, CONTACTSECTION_CONTRACT},
            {
                CITEMTYPE_BTC,
                CITEMTYPE_ETH,
                CITEMTYPE_XRP,
                CITEMTYPE_LTC,
                CITEMTYPE_DAO,
                CITEMTYPE_XEM,
                CITEMTYPE_DASH,
                CITEMTYPE_MAID,
                CITEMTYPE_LSK,
                CITEMTYPE_DOGE,
                CITEMTYPE_DGD,
                CITEMTYPE_XMR,
                CITEMTYPE_WAVES,
                CITEMTYPE_NXT,
                CITEMTYPE_SC,
                CITEMTYPE_STEEM,
                CITEMTYPE_AMP,
                CITEMTYPE_XLM,
                CITEMTYPE_FCT,
                CITEMTYPE_BTS,
                CITEMTYPE_USD,
                CITEMTYPE_EUR,
                CITEMTYPE_GBP,
                CITEMTYPE_INR,
                CITEMTYPE_AUD,
                CITEMTYPE_CAD,
                CITEMTYPE_SGD,
                CITEMTYPE_CHF,
                CITEMTYPE_MYR,
                CITEMTYPE_JPY,
                CITEMTYPE_CNY,
                CITEMTYPE_NZD,
                CITEMTYPE_THB,
                CITEMTYPE_HUF,
                CITEMTYPE_AED,
                CITEMTYPE_HKD,
                CITEMTYPE_MXN,
                CITEMTYPE_ZAR,
                CITEMTYPE_PHP,
                CITEMTYPE_SEK
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
        {{CONTACTSECTION_SCOPE, "en"}, "Names"},
        {{CONTACTSECTION_IDENTIFIER, "en"}, "Messaging"},
        {{CONTACTSECTION_ADDRESS, "en"}, "Profile"},
        {{CONTACTSECTION_COMMUNICATION, "en"}, "URL"},
        {{CONTACTSECTION_PROFILE, "en"}, "Accomplishments"},
        {{CONTACTSECTION_RELATIONSHIP, "en"}, "Relationships"},
        {{CONTACTSECTION_DESCRIPTOR, "en"}, "Fingerprints"},
        {{CONTACTSECTION_EVENT, "en"}, "Contracts"},
        {{CONTACTSECTION_CONTRACT, "en"}, "Contracts"}
    };
    static const EnumTranslation ContactItemTypes =
    {
        {{CITEMTYPE_INDIVIDUAL, "en"}, "Individual"},
        {{CITEMTYPE_ORGANIZATION, "en"}, "Organization"},
        {{CITEMTYPE_BUSINESS, "en"}, "Business"},
        {{CITEMTYPE_GOVERNMENT, "en"}, "Government"},
        {{CITEMTYPE_PREFIX, "en"}, "Prefix title"},
        {{CITEMTYPE_FORENAME, "en"}, "Forename"},
        {{CITEMTYPE_MIDDLENAME, "en"}, "Middle name"},
        {{CITEMTYPE_SURNAME, "en"}, "Surname"},
        {{CITEMTYPE_PEDIGREE, "en"}, "Pedigree"},
        {{CITEMTYPE_SUFFIX, "en"}, "Suffix title"},
        {{CITEMTYPE_NICKNAME, "en"}, "Name"},
        {{CITEMTYPE_COMMONNAME, "en"}, "Common name"},
        {{CITEMTYPE_PASSPORT, "en"}, "Passport ID"},
        {{CITEMTYPE_NATIONAL, "en"}, "National ID"},
        {{CITEMTYPE_PROVINCIAL, "en"}, "Provincial ID"},
        {{CITEMTYPE_MILITARY, "en"}, "Military ID"},
        {{CITEMTYPE_PGP, "en"}, "PGP"},
        {{CITEMTYPE_OTR, "en"}, "OTR"},
        {{CITEMTYPE_SSL, "en"}, "SSL"},
        {{CITEMTYPE_PHYSICAL, "en"}, "Physical"},
        {{CITEMTYPE_OFFICIAL, "en"}, "Official"},
        {{CITEMTYPE_BIRTHPLACE, "en"}, "Birthplace"},
        {{CITEMTYPE_HOME, "en"}, "Hometown"},
        {{CITEMTYPE_WEBSITE, "en"}, "Website"},
        {{CITEMTYPE_PHONE, "en"}, "Phone"},
        {{CITEMTYPE_EMAIL, "en"}, "Email"},
        {{CITEMTYPE_SKYPE, "en"}, "Skype"},
        {{CITEMTYPE_WIRE, "en"}, "Wire"},
        {{CITEMTYPE_QQ, "en"}, "QQ"},
        {{CITEMTYPE_BITMESSAGE, "en"}, "Bitmessage"},
        {{CITEMTYPE_WHATSAPP, "en"}, "WhatsApp"},
        {{CITEMTYPE_TELEGRAM, "en"}, "Telegram"},
        {{CITEMTYPE_KIK, "en"}, "Kik"},
        {{CITEMTYPE_BBM, "en"}, "BBM"},
        {{CITEMTYPE_WECHAT, "en"}, "WeChat"},
        {{CITEMTYPE_KAKAOTALK, "en"}, "KakaoTalk"},
        {{CITEMTYPE_FACEBOOK, "en"}, "Facebook"},
        {{CITEMTYPE_GOGGLE, "en"}, "Google+"},
        {{CITEMTYPE_LINKEDIN, "en"}, "LinkedIn"},
        {{CITEMTYPE_VK, "en"}, "VK"},
        {{CITEMTYPE_ABOUTME, "en"}, "About.me"},
        {{CITEMTYPE_ONENAME, "en"}, "Onename"},
        {{CITEMTYPE_TWITTER, "en"}, "Twitter"},
        {{CITEMTYPE_MEDIUM, "en"}, "Medium"},
        {{CITEMTYPE_TUMBLR, "en"}, "Tumblr"},
        {{CITEMTYPE_YAHOO, "en"}, "Yahoo"},
        {{CITEMTYPE_MYSPACE, "en"}, "NySpace"},
        {{CITEMTYPE_MEETUP, "en"}, "Meetup"},
        {{CITEMTYPE_REDDIT, "en"}, "Reddit"},
        {{CITEMTYPE_HACKERNEWS, "en"}, "Hacker News"},
        {{CITEMTYPE_WIKIPEDIA, "en"}, "Wikipedia"},
        {{CITEMTYPE_ANGELLIST, "en"}, "AngelList"},
        {{CITEMTYPE_GITHUB, "en"}, "Github"},
        {{CITEMTYPE_BITBUCKET, "en"}, "BitBucket"},
        {{CITEMTYPE_YOUTUBE, "en"}, "YouTube"},
        {{CITEMTYPE_VIMEO, "en"}, "Vimeo"},
        {{CITEMTYPE_TWITCH, "en"}, "Twitch"},
        {{CITEMTYPE_SNAPCHAT, "en"}, "Snapchat"},
        {{CITEMTYPE_VINE, "en"}, "Vine"},
        {{CITEMTYPE_INSTAGRAM, "en"}, "Instagram"},
        {{CITEMTYPE_PINTREST, "en"}, "Pintrest"},
        {{CITEMTYPE_IMGUR, "en"}, "Imgur"},
        {{CITEMTYPE_FLICKR, "en"}, "Flickr"},
        {{CITEMTYPE_DRIBBLE, "en"}, "Dribble"},
        {{CITEMTYPE_BEHANCE, "en"}, "Behance"},
        {{CITEMTYPE_DEVIANTART, "en"}, "Deviant Art"},
        {{CITEMTYPE_SPOTIFY, "en"}, "Spotofy"},
        {{CITEMTYPE_ITUNES, "en"}, "iTunes"},
        {{CITEMTYPE_SOUNDCLOUD, "en"}, "Soundcloud"},
        {{CITEMTYPE_ASKFM, "en"}, "Ask.fm"},
        {{CITEMTYPE_EBAY, "en"}, "EBay"},
        {{CITEMTYPE_ETSY, "en"}, "Etsy"},
        {{CITEMTYPE_OPENBAZAAR, "en"}, "Open Bazaar"},
        {{CITEMTYPE_XBOXLIVE, "en"}, "Xbox Live"},
        {{CITEMTYPE_PLAYSTATION, "en"}, "Playstation Network"},
        {{CITEMTYPE_SECONDLIFE, "en"}, "Second Life"},
        {{CITEMTYPE_WARCRAFT, "en"}, "Warcraft Social"},
        {{CITEMTYPE_ALIAS, "en"}, "Alias of"},
        {{CITEMTYPE_ACQUAINTANCE, "en"}, "Acquaintance of"},
        {{CITEMTYPE_FRIEND, "en"}, "Friend of"},
        {{CITEMTYPE_SPOUSE, "en"}, "Spouse of"},
        {{CITEMTYPE_SIBLING, "en"}, "Sibling of"},
        {{CITEMTYPE_MEMBER, "en"}, "Member of"},
        {{CITEMTYPE_COLLEGUE, "en"}, "Collegue of"},
        {{CITEMTYPE_PARENT, "en"}, "Parent of"},
        {{CITEMTYPE_CHILD, "en"}, "Child of"},
        {{CITEMTYPE_EMPLOYER, "en"}, "Employer of"},
        {{CITEMTYPE_EMPLOYEE, "en"}, "Employee of"},
        {{CITEMTYPE_CITIZEN, "en"}, "Citizen of"},
        {{CITEMTYPE_PHOTO, "en"}, "Photo"},
        {{CITEMTYPE_GENDER, "en"}, "Gender"},
        {{CITEMTYPE_HEIGHT, "en"}, "Height"},
        {{CITEMTYPE_WEIGHT, "en"}, "Weight"},
        {{CITEMTYPE_HAIR, "en"}, "Hair color"},
        {{CITEMTYPE_EYE, "en"}, "Eye color"},
        {{CITEMTYPE_SKIN, "en"}, "Skin color"},
        {{CITEMTYPE_ETHNICITY, "en"}, "Ethnicity"},
        {{CITEMTYPE_LANGUAGE, "en"}, "Language"},
        {{CITEMTYPE_DEGREE, "en"}, "Degree"},
        {{CITEMTYPE_CERTIFICATION, "en"}, "Certification"},
        {{CITEMTYPE_TITLE, "en"}, "Title"},
        {{CITEMTYPE_SKILL, "en"}, "Skill"},
        {{CITEMTYPE_AWARD, "en"}, "Award"},
        {{CITEMTYPE_LIKES, "en"}, "Like"},
        {{CITEMTYPE_SEXUAL, "en"}, "Sexual preference"},
        {{CITEMTYPE_POLIGICAL, "en"}, "Political view"},
        {{CITEMTYPE_RELIGIOUS, "en"}, "Religious affiliation"},
        {{CITEMTYPE_BIRTH, "en"}, "Birth date"},
        {{CITEMTYPE_SECONDARYGRADUATION, "en"}, "Secondary school graduation"},
        {{CITEMTYPE_UNIVERSITYGRADUTATION, "en"}, "University graduation"},
        {{CITEMTYPE_WEDDING, "en"}, "Wedding"},
        {{CITEMTYPE_ACCOMPLISHMENT, "en"}, "Accomplishment"},
        {{CITEMTYPE_BTC, "en"}, "Bitcoin"},
        {{CITEMTYPE_ETH, "en"}, "Ethereum"},
        {{CITEMTYPE_XRP, "en"}, "Ripple"},
        {{CITEMTYPE_LTC, "en"}, "Litecoin"},
        {{CITEMTYPE_DAO, "en"}, "The DAO"},
        {{CITEMTYPE_XEM, "en"}, "NEM"},
        {{CITEMTYPE_DASH, "en"}, "Dash"},
        {{CITEMTYPE_MAID, "en"}, "MaidSafeCoin"},
        {{CITEMTYPE_LSK, "en"}, "Lisk"},
        {{CITEMTYPE_DOGE, "en"}, "Dogecoin"},
        {{CITEMTYPE_DGD, "en"}, "DigixDAO"},
        {{CITEMTYPE_XMR, "en"}, "Monero"},
        {{CITEMTYPE_WAVES, "en"}, "Waves"},
        {{CITEMTYPE_NXT, "en"}, "Nxt"},
        {{CITEMTYPE_SC, "en"}, "Siacoin"},
        {{CITEMTYPE_STEEM, "en"}, "Steem"},
        {{CITEMTYPE_AMP, "en"}, "Synereo"},
        {{CITEMTYPE_XLM, "en"}, "Stellar"},
        {{CITEMTYPE_FCT, "en"}, "Factom"},
        {{CITEMTYPE_BTS, "en"}, "BitShares"},
        {{CITEMTYPE_USD, "en"}, "US Dollar"},
        {{CITEMTYPE_EUR, "en"}, "Euro"},
        {{CITEMTYPE_GBP, "en"}, "British Pound"},
        {{CITEMTYPE_INR, "en"}, "Indian Rupee"},
        {{CITEMTYPE_AUD, "en"}, "Australian Dollar"},
        {{CITEMTYPE_CAD, "en"}, "Canadian Dollar"},
        {{CITEMTYPE_SGD, "en"}, "Singapore Dollar"},
        {{CITEMTYPE_CHF, "en"}, "Swiss Franc"},
        {{CITEMTYPE_MYR, "en"}, "Malaysian Ringgit"},
        {{CITEMTYPE_JPY, "en"}, "Japanese Yen"},
        {{CITEMTYPE_CNY, "en"}, "Chinese Yuan Renminbi"},
        {{CITEMTYPE_NZD, "en"}, "New Zealand Dollar"},
        {{CITEMTYPE_THB, "en"}, "Thai Baht"},
        {{CITEMTYPE_HUF, "en"}, "Hungarian Forint"},
        {{CITEMTYPE_AED, "en"}, "Emirati Dirham"},
        {{CITEMTYPE_HKD, "en"}, "Hong Kong Dollar"},
        {{CITEMTYPE_MXN, "en"}, "Mexican Peso"},
        {{CITEMTYPE_ZAR, "en"}, "South African Rand"},
        {{CITEMTYPE_PHP, "en"}, "Philippine Peso"},
        {{CITEMTYPE_SEK, "en"}, "Swedish Krona"},
    };
    static const EnumTranslation ContactItemAttributes =
    {
        {{CITEMATTR_ACTIVE, "en"}, "Active"},
        {{CITEMATTR_PRIMARY, "en"}, "Primary"}
    };
    static const RelationshipReciprocity RelationshipMap =
    {
        {CITEMTYPE_ORGANIZATION, CITEMTYPE_MEMBER},
        {CITEMTYPE_GOVERNMENT, CITEMTYPE_CITIZEN},
        {CITEMTYPE_ALIAS, CITEMTYPE_ALIAS},
        {CITEMTYPE_ACQUAINTANCE, CITEMTYPE_ACQUAINTANCE},
        {CITEMTYPE_FRIEND, CITEMTYPE_FRIEND},
        {CITEMTYPE_SPOUSE, CITEMTYPE_SPOUSE},
        {CITEMTYPE_SIBLING, CITEMTYPE_SIBLING},
        {CITEMTYPE_MEMBER, CITEMTYPE_ORGANIZATION},
        {CITEMTYPE_COLLEGUE, CITEMTYPE_COLLEGUE},
        {CITEMTYPE_PARENT, CITEMTYPE_CHILD},
        {CITEMTYPE_CHILD, CITEMTYPE_PARENT},
        {CITEMTYPE_EMPLOYER, CITEMTYPE_EMPLOYEE},
        {CITEMTYPE_EMPLOYEE, CITEMTYPE_EMPLOYER},
        {CITEMTYPE_CITIZEN, CITEMTYPE_GOVERNMENT}
    };
} // namespace proto
} // namespace opentxs
#endif // OPENTXS_PROTO_CONTACT
