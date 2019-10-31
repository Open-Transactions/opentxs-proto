// Copyright (c) 2019 The Open-Transactions developers
// This Source Code Form is subject to the terms of the Mozilla Public
// License, v. 2.0. If a copy of the MPL was not distributed with this
// file, You can obtain one at http://mozilla.org/MPL/2.0/.

#include "opentxs-proto/verify/VerifyOTX.hpp"

namespace opentxs::proto
{
const VersionMap& ServerReplyAllowedOTXPush() noexcept
{
    static const auto output = VersionMap{
        {1, {1, 1}},
        {2, {1, 1}},
    };

    return output;
}
const VersionMap& ServerReplyAllowedSignature() noexcept
{
    static const auto output = VersionMap{
        {1, {3, 3}},
        {2, {3, 3}},
    };

    return output;
}
const VersionMap& ServerRequestAllowedNym() noexcept
{
    static const auto output = VersionMap{
        {1, {1, 5}},
        {2, {1, 6}},
    };

    return output;
}
const VersionMap& ServerRequestAllowedSignature() noexcept
{
    static const auto output = VersionMap{
        {1, {3, 3}},
        {2, {3, 3}},
    };

    return output;
}
}  // namespace opentxs::proto
