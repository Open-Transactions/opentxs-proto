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
#else
#include <opentxs-proto/Enums.pb.h>
#include <opentxs-proto/Credential.pb.h>
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
    static const uint32_t MIN_PLAUSIBLE_SOURCE = 12;
    static const uint32_t MIN_PLAUSIBLE_SIGNATURE = 32;

    static const VersionMap CredentialAllowedKeyCredentials =
        {
            { 1, {1, 1}},
        };
    static const VersionMap CredentialAllowedSignatures =
        {
            { 1, {1, 1}},
        };
    static const VersionMap KeyCredentialAllowedMasterParams =
        {
            { 1, {1, 1}},
        };
    static const VersionMap KeyCredentialAllowedChildParams =
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

    bool Verify(
        const Credential serializedCred,
        const proto::CredentialRole role,
        const bool withSigs = true);

    bool Verify(
        KeyCredential serializedKeyCred,
        const uint32_t minVersion,
        const uint32_t maxVersion,
        const proto::CredentialRole role,
        const proto::CredentialType credType,
        const proto::KeyMode mode,
        const proto::SourceType sourceType);

    bool Verify(
        const ChildCredentialParameters serializedChildParams,
        const uint32_t minVersion,
        const uint32_t maxVersion);

    bool Verify(
        const MasterCredentialParameters serializedMasterParams,
        const uint32_t minVersion,
        const uint32_t maxVersion,
        const proto::SourceType sourceType);

    bool Verify(
        const nymIDSource serializedNymIDSource,
        const uint32_t minVersion,
        const uint32_t maxVersion,
        const proto::SourceType type);

    bool Verify(
        const AsymmetricKey serializedAsymmetricKey,
        const uint32_t minVersion,
        const uint32_t maxVersion,
        const proto::CredentialType type,
        const proto::KeyMode mode,
        const proto::KeyRole role);

    bool Verify(
        const Signature serializedSignature,
        const uint32_t minVersion,
        const uint32_t maxVersion,
        const std::string selfID,
        const std::string masterID,
        uint32_t& selfPublic,
        uint32_t& selfPrivate,
        uint32_t& masterPublic);

} // namespace proto
} // namespace opentxs

#endif // OPENTXS_PROTO_VERIFY_HPP
