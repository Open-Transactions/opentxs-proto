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

#ifndef OPENTXS_PROTO_VERIFYCREDENTIALS_HPP
#define OPENTXS_PROTO_VERIFYCREDENTIALS_HPP

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
// IWYU pragma: begin_exports
#include "opentxs-proto/Enums.pb.h"
#include "opentxs-proto/Credential.pb.h"
#include "opentxs-proto/CredentialIndex.pb.h"
#include "opentxs-proto/Envelope.pb.h"
#include "opentxs-proto/Seed.pb.h"
// IWYU pragma: end_exports
#ifdef _WIN32
#pragma warning(pop)
#else
#pragma GCC diagnostic pop
#endif

// IWYU pragma: begin_exports
#include "opentxs-proto/Verify.hpp"
#include "opentxs-proto/verify/AsymmetricKey.hpp"
#include "opentxs-proto/verify/ChildCredentialParameters.hpp"
#include "opentxs-proto/verify/Ciphertext.hpp"
#include "opentxs-proto/verify/Credential.hpp"
#include "opentxs-proto/verify/CredentialIndex.hpp"
#include "opentxs-proto/verify/CredentialSet.hpp"
#include "opentxs-proto/verify/Envelope.hpp"
#include "opentxs-proto/verify/HDPath.hpp"
#include "opentxs-proto/verify/KeyCredential.hpp"
#include "opentxs-proto/verify/MasterCredentialParameters.hpp"
#include "opentxs-proto/verify/NymIDSource.hpp"
#include "opentxs-proto/verify/PaymentCode.hpp"
#include "opentxs-proto/verify/Seed.hpp"
#include "opentxs-proto/verify/Signature.hpp"
#include "opentxs-proto/verify/SourceProof.hpp"
#include "opentxs-proto/verify/SymmetricKey.hpp"
// IWYU pragma: end_exports

namespace opentxs { namespace proto
{
    static const VersionMap CredentialAllowedKeyCredentials =
        {
            { 1, {1, 1}},
        };
    static const VersionMap CredentialAllowedContactData =
        {
            { 1, {1, 1}},
        };
    static const VersionMap CredentialAllowedVerification =
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
    static const VersionMap CredentialSetAllowedCredentials =
        {
            { 1, {1, 1}},
        };
    static const VersionMap AsymmetricKeyAllowedHDPath =
        {
            { 1, {1, 1}},
        };
    static const VersionMap AsymmetricKeyAllowedCiphertext =
        {
            { 1, {1, 1}},
        };
    static const VersionMap SeedAllowedCiphertext =
        {
            { 1, {1, 1}},
        };
    static const VersionMap CiphertextAllowedSymmetricKey =
        {
            { 1, {1, 1}},
        };
    static const VersionMap SymmetricKeyAllowedCiphertext =
        {
            { 1, {1, 1}},
        };
    static const VersionMap EnvelopeAllowedAsymmetricKey =
        {
            { 1, {1, 1}},
        };
    static const VersionMap EnvelopeAllowedCiphertext =
        {
            { 1, {1, 1}},
        };
} // namespace proto
} // namespace opentxs
#endif // OPENTXS_PROTO_VERIFYCREDENTIALS_HPP
