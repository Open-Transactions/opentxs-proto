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

#include "opentxs-proto/Basic.hpp"

namespace opentxs { namespace proto
{
    class AsymmetricKey;
    class ChildCredentialParameters;
    class Ciphertext;
    class Credential;
    class CredentialIndex;
    class CredentialSet;
    class Envelope;
    class HDPath;
    class KeyCredential;
    class MasterCredentialParameters;
    class NymIDSource;
    class PaymentCode;
    class Seed;
    class Signature;
    class SourceProof;
    class SymmetricKey;

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
            { 2, {1, 1}},
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
