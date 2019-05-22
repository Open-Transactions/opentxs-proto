// Copyright (c) 2018 The Open-Transactions developers
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
static const VersionMap LucreTokenDataAllowedCiphertext = {
    {1, {1, 1}},
};
static const VersionMap PurseAllowedCiphertext = {
    {1, {1, 1}},
};
static const VersionMap PurseAllowedSessionKey = {
    {1, {1, 1}},
};
static const VersionMap PurseAllowedSymmetricKey = {
    {1, {1, 1}},
};
static const VersionMap PurseAllowedToken = {
    {1, {1, 1}},
};
static const VersionMap PurseExchangeAllowedPurse = {
    {1, {1, 1}},
};
static const VersionMap SessionKeyAllowedAsymmetricKey = {
    {1, {1, 2}},
};
static const VersionMap SessionKeyAllowedCiphertext = {
    {1, {1, 1}},
};
static const VersionMap TokenAllowedLucreTokenData = {
    {1, {1, 1}},
};
}  // namespace proto
}  // namespace opentxs
#endif  // OPENTXS_PROTO_VERIFYCASH_HPP
