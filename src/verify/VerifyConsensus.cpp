// Copyright (c) 2019 The Open-Transactions developers
// This Source Code Form is subject to the terms of the Mozilla Public
// License, v. 2.0. If a copy of the MPL was not distributed with this
// file, You can obtain one at http://mozilla.org/MPL/2.0/.

#include "opentxs-proto/verify/VerifyConsensus.hpp"

namespace opentxs::proto
{
const VersionMap& ContextAllowedServer() noexcept
{
    static const auto output = VersionMap{
        {1, {1, 1}},
        {2, {2, 2}},
        {3, {3, 3}},
    };

    return output;
}
const VersionMap& ContextAllowedClient() noexcept
{
    static const auto output = VersionMap{
        {1, {1, 1}},
        {2, {1, 2}},
    };

    return output;
}
const VersionMap& ContextAllowedSignature() noexcept
{
    static const auto output = VersionMap{
        {1, {2, 2}},
        {2, {2, 2}},
        {3, {2, 2}},
    };

    return output;
}
const VersionMap& ServerContextAllowedPendingCommand() noexcept
{
    static const auto output = VersionMap{
        {3, {1, 1}},
    };

    return output;
}
const std::map<std::uint32_t, std::set<int>>&
ServerContextAllowedState() noexcept
{
    static const auto output =
        std::map<std::uint32_t, std::set<int>>{{3, {1, 2, 3, 4, 5}}};

    return output;
}
const std::map<std::uint32_t, std::set<int>>&
ServerContextAllowedStatus() noexcept
{
    static const auto output =
        std::map<std::uint32_t, std::set<int>>{{3, {1, 2, 3, 4, 5}}};

    return output;
}
}  // namespace opentxs::proto
