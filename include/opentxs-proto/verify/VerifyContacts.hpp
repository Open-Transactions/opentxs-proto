// Copyright (c) 2018 The Open-Transactions developers
// This Source Code Form is subject to the terms of the Mozilla Public
// License, v. 2.0. If a copy of the MPL was not distributed with this
// file, You can obtain one at http://mozilla.org/MPL/2.0/.

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
}  // namespace proto
}  // namespace opentxs

#include "opentxs-proto/Basic.hpp"
#include "opentxs-proto/Contact.hpp"

#define MAX_CONTACT_VERSION 5

namespace opentxs
{
namespace proto
{
static const VersionMap ContactAllowedContactData = {
    {1, {1, 4}},
    {2, {5, 5}},
};
static const VersionMap ContactDataAllowedSection = {
    {1, {1, 1}},
    {2, {1, 2}},
    {3, {1, 3}},
    {4, {4, 4}},
    {5, {5, 5}},
};
static const VersionMap ContactSectionAllowedItem = {
    {1, {1, 1}},
    {2, {1, 2}},
    {3, {1, 3}},
    {4, {4, 4}},
    {5, {5, 5}},
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
std::uint32_t RequiredVersion(
    const ContactSectionName section,
    const ContactItemType type,
    const std::uint32_t hint = 1);
std::uint32_t NymRequiredVersion(
    const std::uint32_t contactDataVersion,
    const std::uint32_t hint);
std::uint32_t RequiredCredentialSetVersion(
    const std::uint32_t contactDataVersion,
    const std::uint32_t hint);
}  // namespace proto
}  // namespace opentxs
#endif  // OPENTXS_PROTO_VERIFYCONTACTS_HPP
