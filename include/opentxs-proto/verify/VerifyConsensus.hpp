// Copyright (c) 2018 The Open-Transactions developers
// This Source Code Form is subject to the terms of the Mozilla Public
// License, v. 2.0. If a copy of the MPL was not distributed with this
// file, You can obtain one at http://mozilla.org/MPL/2.0/.

#ifndef OPENTXS_PROTO_VERIFYCONSENSUS_HPP
#define OPENTXS_PROTO_VERIFYCONSENSUS_HPP

#include "opentxs-proto/Basic.hpp"

namespace opentxs
{
namespace proto
{
static const VersionMap ContextAllowedServer = {
    {1, {1, 1}},
    {2, {2, 2}},
};
static const VersionMap ContextAllowedClient = {
    {1, {1, 1}},
    {2, {1, 2}},
};
static const VersionMap ContextAllowedSignature = {
    {1, {2, 2}},
    {2, {2, 2}},
};
}  // namespace proto
}  // namespace opentxs
#endif  // OPENTXS_PROTO_VERIFYCONSENSUS_HPP
