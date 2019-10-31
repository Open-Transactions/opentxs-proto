// Copyright (c) 2019 The Open-Transactions developers
// This Source Code Form is subject to the terms of the Mozilla Public
// License, v. 2.0. If a copy of the MPL was not distributed with this
// file, You can obtain one at http://mozilla.org/MPL/2.0/.

#ifndef OPENTXS_PROTO_VERIFYCONSENSUS_HPP
#define OPENTXS_PROTO_VERIFYCONSENSUS_HPP

#include "opentxs-proto/Basic.hpp"

#include <map>
#include <set>

namespace opentxs
{
namespace proto
{
OPENTXS_PROTO_EXPORT const VersionMap& ContextAllowedServer() noexcept;
OPENTXS_PROTO_EXPORT const VersionMap& ContextAllowedClient() noexcept;
OPENTXS_PROTO_EXPORT const VersionMap& ContextAllowedSignature() noexcept;
OPENTXS_PROTO_EXPORT const VersionMap&
ServerContextAllowedPendingCommand() noexcept;
OPENTXS_PROTO_EXPORT const std::map<std::uint32_t, std::set<int>>&
ServerContextAllowedState() noexcept;
OPENTXS_PROTO_EXPORT const std::map<std::uint32_t, std::set<int>>&
ServerContextAllowedStatus() noexcept;
}  // namespace proto
}  // namespace opentxs
#endif  // OPENTXS_PROTO_VERIFYCONSENSUS_HPP
