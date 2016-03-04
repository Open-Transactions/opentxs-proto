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

#include <algorithm>
#include <utility>

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
#include "opentxs-proto/Claim.pb.h"
#include "opentxs-proto/ContactData.pb.h"
#include "opentxs-proto/ContactEnums.pb.h"
#include "opentxs-proto/VerificationSet.pb.h"
#ifdef _WIN32
#pragma warning(pop)
#else
#pragma GCC diagnostic pop
#endif

#include "opentxs-proto/Contact.hpp"
#include "opentxs-proto/Verify.hpp"
#include "opentxs-proto/verify/Claim.hpp"
#include "opentxs-proto/verify/ContactData.hpp"
#include "opentxs-proto/verify/ContactItem.hpp"
#include "opentxs-proto/verify/ContactSection.hpp"
#include "opentxs-proto/verify/Verification.hpp"
#include "opentxs-proto/verify/VerificationGroup.hpp"
#include "opentxs-proto/verify/VerificationIdentity.hpp"
#include "opentxs-proto/verify/VerificationSet.hpp"

namespace opentxs { namespace proto
{
    static const VersionMap ContactDataAllowedSection =
        {
            { 1, {1, 1}},
        };
    static const VersionMap ContactSectionAllowedItem =
        {
            { 1, {1, 1}},
        };
    static const VersionMap VerificationSetAllowedGroup =
        {
            { 1, {1, 1}},
        };
    static const VersionMap VerificationGroupAllowedIdentity =
        {
            { 1, {1, 1}},
        };
    static const VersionMap VerificationIdentityAllowedVerification =
        {
            { 1, {1, 1}},
        };
    static const VersionMap VerificationAllowedSignature =
        {
            { 1, {1, 1}},
        };

    bool ValidContactSectionName(
        const uint32_t version,
        const ContactSectionName name);
    bool ValidContactItemType(
        const ContactSectionVersion version,
        const ContactItemType itemType);
    bool ValidContactItemAttribute(
        const uint32_t version,
        const ContactItemAttribute attribute);

    std::string TranslateSectionName(
        const uint32_t enumValue,
        const std::string& lang = "en");
    std::string TranslateItemType(
        const uint32_t enumValue,
        const std::string& lang = "en");
    std::string TranslateItemAttributes(
        const uint32_t enumValue,
        const std::string& lang = "en");
    uint32_t ReciprocalRelationship(const uint32_t relationship);

} // namespace proto
} // namespace opentxs
#endif // OPENTXS_PROTO_VERIFYCONTACTS_HPP
