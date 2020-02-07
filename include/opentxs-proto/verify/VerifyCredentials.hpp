// Copyright (c) 2020 The Open-Transactions developers
// This Source Code Form is subject to the terms of the Mozilla Public
// License, v. 2.0. If a copy of the MPL was not distributed with this
// file, You can obtain one at http://mozilla.org/MPL/2.0/.

#ifndef OPENTXS_PROTO_VERIFYCREDENTIALS_HPP
#define OPENTXS_PROTO_VERIFYCREDENTIALS_HPP

#include "opentxs-proto/Basic.hpp"

namespace opentxs
{
namespace proto
{
OPENTXS_PROTO_EXPORT const VersionMap&
AsymmetricKeyAllowedCiphertext() noexcept;
OPENTXS_PROTO_EXPORT const VersionMap& AsymmetricKeyAllowedHDPath() noexcept;
OPENTXS_PROTO_EXPORT const VersionMap& AuthorityAllowedCredential() noexcept;
OPENTXS_PROTO_EXPORT const VersionMap& CiphertextAllowedSymmetricKey() noexcept;
OPENTXS_PROTO_EXPORT const VersionMap& CredentialAllowedChildParams() noexcept;
OPENTXS_PROTO_EXPORT const VersionMap& CredentialAllowedContactData() noexcept;
OPENTXS_PROTO_EXPORT const VersionMap&
CredentialAllowedKeyCredential() noexcept;
OPENTXS_PROTO_EXPORT const VersionMap& CredentialAllowedMasterParams() noexcept;
OPENTXS_PROTO_EXPORT const VersionMap& CredentialAllowedSignatures() noexcept;
OPENTXS_PROTO_EXPORT const VersionMap& CredentialAllowedVerification() noexcept;
OPENTXS_PROTO_EXPORT const VersionMap& EnvelopeAllowedAsymmetricKey() noexcept;
OPENTXS_PROTO_EXPORT const VersionMap& EnvelopeAllowedCiphertext() noexcept;
OPENTXS_PROTO_EXPORT const VersionMap& EnvelopeAllowedTaggedKey() noexcept;
OPENTXS_PROTO_EXPORT const VersionMap&
KeyCredentialAllowedAsymmetricKey() noexcept;
OPENTXS_PROTO_EXPORT const VersionMap&
MasterParamsAllowedNymIDSource() noexcept;
OPENTXS_PROTO_EXPORT const VersionMap&
MasterParamsAllowedSourceProof() noexcept;
OPENTXS_PROTO_EXPORT const VersionMap& NymAllowedAuthority() noexcept;
OPENTXS_PROTO_EXPORT const VersionMap& NymAllowedNymIDSource() noexcept;
OPENTXS_PROTO_EXPORT const VersionMap&
NymIDSourceAllowedAsymmetricKey() noexcept;
OPENTXS_PROTO_EXPORT const VersionMap& NymIDSourceAllowedPaymentCode() noexcept;
OPENTXS_PROTO_EXPORT const VersionMap& SeedAllowedCiphertext() noexcept;
OPENTXS_PROTO_EXPORT const VersionMap& SymmetricKeyAllowedCiphertext() noexcept;
OPENTXS_PROTO_EXPORT const VersionMap& TaggedKeyAllowedSymmetricKey() noexcept;
}  // namespace proto
}  // namespace opentxs
#endif  // OPENTXS_PROTO_VERIFYCREDENTIALS_HPP
