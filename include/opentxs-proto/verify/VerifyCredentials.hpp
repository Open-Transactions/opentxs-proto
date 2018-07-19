// Copyright (c) 2018 The Open-Transactions developers
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
static const VersionMap CredentialAllowedKeyCredentials = {
    {1, {1, 1}},
    {2, {1, 1}},
    {3, {1, 1}},
    {4, {1, 1}},
    {5, {1, 1}},
};
static const VersionMap CredentialAllowedContactData = {
    {1, {1, 1}},
    {2, {2, 2}},
    {3, {3, 3}},
    {4, {4, 4}},
    {5, {5, 5}},
};
static const VersionMap CredentialAllowedVerification = {
    {1, {1, 1}},
    {2, {1, 1}},
    {3, {1, 1}},
    {4, {1, 1}},
    {5, {1, 1}},
};
static const VersionMap CredentialAllowedSignatures = {
    {1, {1, 1}},
    {2, {1, 1}},
    {3, {1, 1}},
    {4, {1, 1}},
    {5, {1, 1}},
};
static const VersionMap CredentialAllowedMasterParams = {
    {1, {1, 1}},
    {2, {1, 1}},
    {3, {1, 1}},
    {4, {1, 1}},
    {5, {1, 1}},
};
static const VersionMap CredentialAllowedChildParams = {
    {1, {1, 1}},
    {2, {1, 1}},
    {3, {1, 1}},
    {4, {1, 1}},
    {5, {1, 1}},
};
static const VersionMap KeyCredentialAllowedAsymmetricKey = {
    {1, {1, 1}},
};
static const VersionMap MasterParamsAllowedNymIDSource = {
    {1, {1, 1}},
};
static const VersionMap MasterParamsAllowedSourceProof = {
    {1, {1, 1}},
};
static const VersionMap NymIDSourceAllowedAsymmetricKey = {
    {1, {1, 1}},
};
static const VersionMap NymIDSourceAllowedPaymentCode = {
    {1, {1, 1}},
};
static const VersionMap CredentialIndexAllowedNymIDSource = {
    {1, {1, 1}},
    {2, {1, 1}},
    {3, {1, 1}},
    {4, {1, 1}},
    {5, {1, 1}},
};
static const VersionMap CredentialIndexAllowedCredentialSets = {
    {1, {1, 1}},
    {2, {1, 2}},
    {3, {1, 3}},
    {4, {1, 4}},
    {5, {1, 5}},
};
static const VersionMap CredentialSetAllowedCredentials = {
    {1, {1, 1}},
    {2, {1, 2}},
    {3, {1, 3}},
    {4, {1, 4}},
    {5, {1, 5}},
};
static const VersionMap AsymmetricKeyAllowedHDPath = {
    {1, {1, 1}},
};
static const VersionMap AsymmetricKeyAllowedCiphertext = {
    {1, {1, 1}},
};
static const VersionMap SeedAllowedCiphertext = {
    {1, {1, 1}},
    {2, {1, 1}},
};
static const VersionMap CiphertextAllowedSymmetricKey = {
    {1, {1, 1}},
};
static const VersionMap SymmetricKeyAllowedCiphertext = {
    {1, {1, 1}},
};
static const VersionMap EnvelopeAllowedAsymmetricKey = {
    {1, {1, 1}},
};
static const VersionMap EnvelopeAllowedCiphertext = {
    {1, {1, 1}},
};
}  // namespace proto
}  // namespace opentxs
#endif  // OPENTXS_PROTO_VERIFYCREDENTIALS_HPP
