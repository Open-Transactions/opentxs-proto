// Copyright (c) 2019 The Open-Transactions developers
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
static const VersionMap ServerReplyAllowedOTXPush = {
    {1, {1, 1}},
    {2, {1, 1}},
};
static const VersionMap ServerReplyAllowedSignature = {
    {1, {3, 3}},
    {2, {3, 3}},
};
static const VersionMap ServerRequestAllowedNym = {
    {1, {1, 5}},
    {2, {1, 6}},
};
static const VersionMap ServerRequestAllowedSignature = {
    {1, {3, 3}},
    {2, {3, 3}},
};
}  // namespace proto
}  // namespace opentxs
#endif  // OPENTXS_PROTO_VERIFYOTX_HPP
