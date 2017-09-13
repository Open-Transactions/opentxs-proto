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
#include <cstdint>
#include <string>
#include <utility>

namespace opentxs
{
namespace proto
{
typedef bool ClaimType;
static const ClaimType CLAIMS_INDEXED = true;
static const ClaimType CLAIMS_NORMAL = false;

typedef bool VerificationType;
static const VerificationType VERIFICATIONS_INDEXED = true;
static const VerificationType VERIFICATIONS_NORMAL = false;
}
}

#include "opentxs-proto/Basic.hpp"
#include "opentxs-proto/Contact.hpp"

namespace opentxs
{
namespace proto
{
class Claim;
class Contact;
class ContactData;
class ContactItem;
class ContactSection;
class Verification;
class VerificationGroup;
class VerificationIdentity;
class VerificationOffer;
class VerificationSet;

static const VersionMap ContactAllowedContactData = {
    {1, {1, 4}},
};
static const VersionMap ContactDataAllowedSection = {
    {1, {1, 1}},
    {2, {1, 2}},
    {3, {1, 3}},
    {4, {4, 4}},
};
static const VersionMap ContactSectionAllowedItem = {
    {1, {1, 1}},
    {2, {1, 2}},
    {3, {1, 3}},
    {4, {4, 4}},
};
static const VersionMap VerificationSetAllowedGroup = {
    {1, {1, 1}},
};
static const VersionMap VerificationGroupAllowedIdentity = {
    {1, {1, 1}},
};
static const VersionMap VerificationIdentityAllowedVerification = {
    {1, {1, 1}},
};
static const VersionMap VerificationAllowedSignature = {
    {1, {1, 1}},
};
static const VersionMap VerificationOfferAllowedClaim = {
    {1, {1, 1}},
};
static const VersionMap VerificationOfferAllowedVerification = {
    {1, {1, 1}},
};

bool ValidContactSectionName(
    const std::uint32_t version,
    const ContactSectionName name);
bool ValidContactItemType(
    const ContactSectionVersion version,
    const ContactItemType itemType);
bool ValidContactItemAttribute(
    const std::uint32_t version,
    const ContactItemAttribute attribute);

std::string TranslateSectionName(
    const std::uint32_t enumValue,
    const std::string& lang = "en");
std::string TranslateItemType(
    const std::uint32_t enumValue,
    const std::string& lang = "en");
std::string TranslateItemAttributes(
    const std::uint32_t enumValue,
    const std::string& lang = "en");
std::uint32_t ReciprocalRelationship(const std::uint32_t relationship);
bool CheckCombination(
    const ContactSectionName section,
    const ContactItemType type,
    const std::uint32_t version = 1);

}  // namespace proto
}  // namespace opentxs
#endif  // OPENTXS_PROTO_VERIFYCONTACTS_HPP
