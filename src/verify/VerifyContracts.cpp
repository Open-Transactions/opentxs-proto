// Copyright (c) 2020 The Open-Transactions developers
// This Source Code Form is subject to the terms of the Mozilla Public
// License, v. 2.0. If a copy of the MPL was not distributed with this
// file, You can obtain one at http://mozilla.org/MPL/2.0/.

#include "opentxs-proto/verify/VerifyContracts.hpp"

namespace opentxs::proto
{
const VersionMap& BasketParamsAllowedBasketItem() noexcept
{
    static const auto output = VersionMap{
        {1, {1, 1}},
    };

    return output;
}
const VersionMap& IssuerAllowedPeerRequestHistory() noexcept
{
    static const auto output = VersionMap{
        {1, {1, 1}},
    };

    return output;
}
const VersionMap& IssuerAllowedUnitAccountMap() noexcept
{
    static const auto output = VersionMap{
        {1, {1, 1}},
    };

    return output;
}
const VersionMap& PeerRequestHistoryAllowedPeerRequestWorkflow() noexcept
{
    static const auto output = VersionMap{
        {1, {1, 1}},
    };

    return output;
}
const VersionMap& ServerContractAllowedListenAddress() noexcept
{
    static const auto output = VersionMap{
        {1, {1, 1}},
        {2, {1, 2}},
    };

    return output;
}
const VersionMap& ServerContractAllowedNym() noexcept
{
    static const auto output = VersionMap{
        {1, {1, 5}},
        {2, {1, 6}},
    };

    return output;
}
const VersionMap& ServerContractAllowedSignature() noexcept
{
    static const auto output = VersionMap{
        {1, {1, 1}},
        {2, {1, 1}},
    };

    return output;
}
const VersionMap& UnitDefinitionAllowedBasketParams() noexcept
{
    static const auto output = VersionMap{
        {1, {1, 1}},
        {2, {1, 1}},
    };

    return output;
}
const VersionMap& UnitDefinitionAllowedCurrencyParams() noexcept
{
    static const auto output = VersionMap{
        {1, {1, 1}},
        {2, {1, 1}},
    };

    return output;
}
const VersionMap& UnitDefinitionAllowedNym() noexcept
{
    static const auto output = VersionMap{
        {1, {1, 6}},
        {2, {1, 6}},
    };

    return output;
}
const VersionMap& UnitDefinitionAllowedSecurityParams() noexcept
{
    static const auto output = VersionMap{
        {1, {1, 1}},
        {2, {1, 1}},
    };

    return output;
}
const VersionMap& UnitDefinitionAllowedSignature() noexcept
{
    static const auto output = VersionMap{
        {1, {1, 1}},
        {2, {1, 1}},
    };

    return output;
}
}  // namespace opentxs::proto
