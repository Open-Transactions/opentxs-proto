// Copyright (c) 2020 The Open-Transactions developers
// This Source Code Form is subject to the terms of the Mozilla Public
// License, v. 2.0. If a copy of the MPL was not distributed with this
// file, You can obtain one at http://mozilla.org/MPL/2.0/.

#ifndef OPENTXS_PROTO_VERIFYOTX_HPP
#define OPENTXS_PROTO_VERIFYOTX_HPP

#include "opentxs-proto/Basic.hpp"

namespace opentxs
{
namespace proto
{
OPENTXS_PROTO_EXPORT const VersionMap& ServerReplyAllowedOTXPush() noexcept;
OPENTXS_PROTO_EXPORT const VersionMap& ServerReplyAllowedSignature() noexcept;
OPENTXS_PROTO_EXPORT const VersionMap& ServerRequestAllowedNym() noexcept;
OPENTXS_PROTO_EXPORT const VersionMap& ServerRequestAllowedSignature() noexcept;
}  // namespace proto
}  // namespace opentxs
#endif  // OPENTXS_PROTO_VERIFYOTX_HPP
