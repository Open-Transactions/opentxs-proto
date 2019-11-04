// Copyright (c) 2019 The Open-Transactions developers
// This Source Code Form is subject to the terms of the Mozilla Public
// License, v. 2.0. If a copy of the MPL was not distributed with this
// file, You can obtain one at http://mozilla.org/MPL/2.0/.

#ifndef OPENTXS_PROTO_VERIFYPEER_HPP
#define OPENTXS_PROTO_VERIFYPEER_HPP

#include "opentxs-proto/Basic.hpp"

namespace opentxs
{
namespace proto
{
OPENTXS_PROTO_EXPORT const VersionMap& PeerObjectAllowedNym() noexcept;
OPENTXS_PROTO_EXPORT const VersionMap& PeerObjectAllowedPeerReply() noexcept;
OPENTXS_PROTO_EXPORT const VersionMap& PeerObjectAllowedPeerRequest() noexcept;
OPENTXS_PROTO_EXPORT const VersionMap& PeerObjectAllowedPurse() noexcept;
OPENTXS_PROTO_EXPORT const VersionMap& PeerReplyAllowedBailment() noexcept;
OPENTXS_PROTO_EXPORT const VersionMap&
PeerReplyAllowedConnectionInfo() noexcept;
OPENTXS_PROTO_EXPORT const VersionMap& PeerReplyAllowedNotice() noexcept;
OPENTXS_PROTO_EXPORT const VersionMap& PeerReplyAllowedOutBailment() noexcept;
OPENTXS_PROTO_EXPORT const VersionMap& PeerReplyAllowedSignature() noexcept;
OPENTXS_PROTO_EXPORT const VersionMap& PeerRequestAllowedBailment() noexcept;
OPENTXS_PROTO_EXPORT const VersionMap&
PeerRequestAllowedConnectionInfo() noexcept;
OPENTXS_PROTO_EXPORT const VersionMap& PeerRequestAllowedFaucet() noexcept;
OPENTXS_PROTO_EXPORT const VersionMap& PeerRequestAllowedOutBailment() noexcept;
OPENTXS_PROTO_EXPORT const VersionMap&
PeerRequestAllowedPendingBailment() noexcept;
OPENTXS_PROTO_EXPORT const VersionMap& PeerRequestAllowedSignature() noexcept;
OPENTXS_PROTO_EXPORT const VersionMap& PeerRequestAllowedStoreSecret() noexcept;
OPENTXS_PROTO_EXPORT const VersionMap&
PeerRequestAllowedVerificationOffer() noexcept;
}  // namespace proto
}  // namespace opentxs
#endif  // OPENTXS_PROTO_VERIFYPEER_HPP
