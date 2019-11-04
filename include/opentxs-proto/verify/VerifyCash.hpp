// Copyright (c) 2019 The Open-Transactions developers
// This Source Code Form is subject to the terms of the Mozilla Public
// License, v. 2.0. If a copy of the MPL was not distributed with this
// file, You can obtain one at http://mozilla.org/MPL/2.0/.

#ifndef OPENTXS_PROTO_VERIFYCASH_HPP
#define OPENTXS_PROTO_VERIFYCASH_HPP

#include "opentxs-proto/Basic.hpp"

namespace opentxs
{
namespace proto
{
OPENTXS_PROTO_EXPORT const VersionMap&
LucreTokenDataAllowedCiphertext() noexcept;
OPENTXS_PROTO_EXPORT const VersionMap& PurseAllowedCiphertext() noexcept;
OPENTXS_PROTO_EXPORT const VersionMap& PurseAllowedSessionKey() noexcept;
OPENTXS_PROTO_EXPORT const VersionMap& PurseAllowedSymmetricKey() noexcept;
OPENTXS_PROTO_EXPORT const VersionMap& PurseAllowedToken() noexcept;
OPENTXS_PROTO_EXPORT const VersionMap& PurseExchangeAllowedPurse() noexcept;
OPENTXS_PROTO_EXPORT const VersionMap&
SessionKeyAllowedAsymmetricKey() noexcept;
OPENTXS_PROTO_EXPORT const VersionMap& SessionKeyAllowedCiphertext() noexcept;
OPENTXS_PROTO_EXPORT const VersionMap& TokenAllowedLucreTokenData() noexcept;
}  // namespace proto
}  // namespace opentxs
#endif  // OPENTXS_PROTO_VERIFYCASH_HPP
