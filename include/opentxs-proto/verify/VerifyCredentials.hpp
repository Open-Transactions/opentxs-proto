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

#ifndef OPENTXS_PROTO_VERIFY_HPP
#define OPENTXS_PROTO_VERIFY_HPP

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
#include "Enums.pb.h"
#include "Credential.pb.h"
#include "CredentialIndex.pb.h"
#else
#include <opentxs-proto/Enums.pb.h>
#include <opentxs-proto/Credential.pb.h>
#include <opentxs-proto/CredentialIndex.pb.h>
#endif

#ifdef _WIN32
#pragma warning(pop)
#else
#pragma GCC diagnostic pop
#endif

#include <map>
#include <utility>

namespace opentxs { namespace proto
{
    // This defined a map between the version of the parent object
    // and the (minimum, maximum) acceptable versions of a child object.
    typedef std::map<uint32_t, std::pair<uint32_t, uint32_t> > VersionMap;

    static const uint32_t MIN_PLAUSIBLE_IDENTIFIER = 20;
    static const uint32_t MIN_PLAUSIBLE_KEYSIZE = 16;
    static const uint32_t MIN_PLAUSIBLE_SIGNATURE = 32;

    static const VersionMap CredentialAllowedKeyCredentials =
        {
            { 1, {1, 1}},
        };
    static const VersionMap CredentialAllowedContactData =
        {
            { 1, {1, 1}},
        };
    static const VersionMap CredentialAllowedSignatures =
        {
            { 1, {1, 1}},
        };
    static const VersionMap CredentialAllowedMasterParams =
        {
            { 1, {1, 1}},
        };
    static const VersionMap CredentialAllowedChildParams =
        {
            { 1, {1, 1}},
        };
    static const VersionMap KeyCredentialAllowedAsymmetricKey =
        {
            { 1, {1, 1}},
        };
    static const VersionMap MasterParamsAllowedNymIDSource =
        {
            { 1, {1, 1}},
        };
    static const VersionMap MasterParamsAllowedSourceProof =
        {
            { 1, {1, 1}},
        };
    static const VersionMap NymIDSourceAllowedAsymmetricKey =
        {
            { 1, {1, 1}},
        };
    static const VersionMap NymIDSourceAllowedPaymentCode =
        {
            { 1, {1, 1}},
        };
    static const VersionMap CredentialIndexAllowedNymIDSource =
        {
            { 1, {1, 1}},
        };
    static const VersionMap CredentialIndexAllowedCredentialSets =
        {
            { 1, {1, 1}},
        };
    static const VersionMap AsymmetricKeyAllowedHDPath =
        {
            { 1, {1, 1}},
        };

    bool Verify(
        const Credential& serializedCred,
        const CredentialRole role,
        const bool withSigs = true);

    bool Verify(
        const KeyCredential& serializedKeyCred,
        const uint32_t minVersion,
        const uint32_t maxVersion,
        const CredentialType credType,
        const KeyMode mode);

    bool Verify(
        const ChildCredentialParameters& serializedChildParams,
        const uint32_t minVersion,
        const uint32_t maxVersion);

    bool Verify(
        const MasterCredentialParameters& serializedMasterParams,
        const uint32_t minVersion,
        const uint32_t maxVersion,
        bool expectSourceSignature);

    bool Verify(
        const NymIDSource& serializedNymIDSource,
        const uint32_t minVersion,
        const uint32_t maxVersion);

    bool Verify(
        const SourceProof& serializedSourceProof,
        const uint32_t minVersion,
        const uint32_t maxVersion,
        bool expectSourceSignature);

    bool Verify(
        const AsymmetricKey& serializedAsymmetricKey,
        const uint32_t minVersion,
        const uint32_t maxVersion,
        const CredentialType type,
        const KeyMode mode,
        const KeyRole role);

    bool Verify(
        const HDPath& serializedHDPath,
        const uint32_t minVersion,
        const uint32_t maxVersion);

    bool Verify(
        const Signature& serializedSignature,
        const uint32_t minVersion,
        const uint32_t maxVersion,
        const std::string& selfID,
        const std::string& masterID,
        uint32_t& selfPublic,
        uint32_t& selfPrivate,
        uint32_t& masterPublic,
        uint32_t& sourcePublic);

    bool Verify(
        const CredentialIndex& serializedCredIndex);

    bool Verify(
        const CredentialSet& serializedCredSet,
        const uint32_t minVersion,
        const uint32_t maxVersion,
        const std::string& nymID);

    bool Verify(
        const PaymentCode& serializedPaymentCode,
        const uint8_t minVersion,
        const uint8_t maxVersion);

} // namespace proto
} // namespace opentxs
#endif // OPENTXS_PROTO_VERIFY_HPP
