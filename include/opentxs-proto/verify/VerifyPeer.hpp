// Copyright (c) 2018 The Open-Transactions developers
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
static const VersionMap PeerObjectAllowedReply = {
    {1, {1, 1}},
    {2, {2, 2}},
    {3, {3, 3}},
    {4, {4, 4}},
    {5, {4, 5}},
    {6, {4, 5}},
    {7, {4, 5}},
};
static const VersionMap PeerObjectAllowedRequest = {
    {1, {1, 2}},
    {2, {2, 2}},
    {3, {3, 3}},
    {4, {4, 4}},
    {5, {4, 5}},
    {6, {4, 6}},
    {7, {4, 6}},
};
static const VersionMap PeerObjectAllowedCredentialIndex = {
    {1, {1, 3}},
    {2, {1, 3}},
    {3, {1, 3}},
    {4, {1, 4}},
    {5, {1, 4}},
    {6, {1, 5}},
    {7, {1, 6}},
};
static const VersionMap PeerReplyAllowedSignature = {
    {1, {1, 1}},
    {2, {1, 1}},
    {3, {1, 1}},
    {4, {1, 1}},
    {5, {1, 1}},
};
static const VersionMap PeerReplyAllowedBailment = {
    {1, {1, 1}},
    {2, {2, 2}},
    {3, {3, 3}},
    {4, {4, 4}},
};
static const VersionMap PeerReplyAllowedNotice = {
    {1, {1, 1}},
    {2, {2, 2}},
    {3, {3, 3}},
    {4, {4, 4}},
    {5, {4, 5}},
};
static const VersionMap PeerReplyAllowedOutBailment = {
    {1, {1, 1}},
    {2, {2, 2}},
    {3, {3, 3}},
    {4, {4, 4}},
};
static const VersionMap PeerReplyAllowedConnectionInfo = {
    {1, {1, 1}},
    {2, {2, 2}},
    {3, {3, 3}},
    {4, {4, 4}},
};
static const VersionMap PeerRequestAllowedSignature = {
    {1, {1, 1}},
    {2, {1, 1}},
    {3, {1, 1}},
    {4, {1, 1}},
    {5, {1, 1}},
    {6, {1, 1}},
};
static const VersionMap PeerRequestAllowedBailment = {
    {1, {1, 1}},
    {2, {2, 2}},
    {3, {3, 3}},
    {4, {4, 4}},
};
static const VersionMap PeerRequestAllowedOutBailment = {
    {1, {1, 1}},
    {2, {2, 2}},
    {3, {3, 3}},
    {4, {4, 4}},
    {5, {5, 5}},
};
static const VersionMap PeerRequestAllowedPendingBailment = {
    {1, {1, 1}},
    {2, {2, 2}},
    {3, {3, 3}},
    {4, {4, 4}},
    {5, {5, 5}},
    {6, {6, 6}},
};
static const VersionMap PeerRequestAllowedConnectionInfo = {
    {1, {1, 1}},
    {2, {2, 2}},
    {3, {3, 3}},
    {4, {4, 4}},
};
static const VersionMap PeerRequestAllowedStoreSecret = {
    {1, {1, 1}},
    {2, {2, 2}},
    {3, {3, 3}},
    {4, {4, 4}},
};
static const VersionMap PeerRequestAllowedVerificationOffer = {
    {1, {0, 0}},
    {2, {0, 0}},
    {3, {3, 3}},
    {4, {4, 4}},
};
static const VersionMap PeerRequestAllowedFaucet = {
    {1, {0, 0}},
    {2, {0, 0}},
    {3, {0, 0}},
    {4, {4, 4}},
};
}  // namespace proto
}  // namespace opentxs
#endif  // OPENTXS_PROTO_VERIFYPEER_HPP
