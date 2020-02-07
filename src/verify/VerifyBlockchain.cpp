// Copyright (c) 2020 The Open-Transactions developers
// This Source Code Form is subject to the terms of the Mozilla Public
// License, v. 2.0. If a copy of the MPL was not distributed with this
// file, You can obtain one at http://mozilla.org/MPL/2.0/.

#include "opentxs-proto/verify/VerifyBlockchain.hpp"

namespace opentxs::proto
{
const VersionMap& Bip47ChainAllowedBip47Channel() noexcept
{
    static const auto output = VersionMap{
        {1, {1, 1}},
    };

    return output;
}
const VersionMap& Bip47ChannelAllowedBip47Direction() noexcept
{
    static const auto output = VersionMap{
        {1, {1, 1}},
    };

    return output;
}
const VersionMap& Bip47ContextAllowedBip47Chain() noexcept
{
    static const auto output = VersionMap{
        {1, {1, 1}},
    };

    return output;
}
const VersionMap& Bip47DirectionAllowedBip47Address() noexcept
{
    static const auto output = VersionMap{
        {1, {1, 1}},
    };

    return output;
}
const VersionMap& BlockchainAddressAllowedAsymmetricKey() noexcept
{
    static const auto output = VersionMap{
        {1, {2, 2}},
    };

    return output;
}
const VersionMap&
BlockchainBlockHeaderAllowedBitcoinBlockHeaderFields() noexcept
{
    static const auto output = VersionMap{
        {1, {1, 1}},
    };

    return output;
}
const VersionMap&
BlockchainBlockHeaderAllowedBlockchainBlockLocalData() noexcept
{
    static const auto output = VersionMap{
        {1, {1, 1}},
    };

    return output;
}
const VersionMap&
BlockchainBlockHeaderAllowedEthereumBlockHeaderFields() noexcept
{
    static const auto output = VersionMap{
        {1, {1, 1}},
    };

    return output;
}
const VersionMap& BlockchainTransactionAllowedInput() noexcept
{
    static const auto output = VersionMap{
        {1, {1, 1}},
    };

    return output;
}
const VersionMap& BlockchainTransactionAllowedOutput() noexcept
{
    static const auto output = VersionMap{
        {1, {1, 1}},
    };

    return output;
}
const VersionMap&
BlockchainTransactionInputAllowedBlockchainPreviousOutput() noexcept
{
    static const auto output = VersionMap{
        {1, {1, 1}},
    };

    return output;
}
const VersionMap&
BlockchainTransactionOutputAllowedBlockchainExternalAddress() noexcept
{
    static const auto output = VersionMap{
        {1, {1, 1}},
    };

    return output;
}
const VersionMap&
BlockchainTransactionOutputAllowedBlockchainWalletKey() noexcept
{
    static const auto output = VersionMap{
        {1, {1, 1}},
    };

    return output;
}
const VersionMap& HDAccountAllowedBlockchainActivity() noexcept
{
    static const auto output = VersionMap{
        {1, {1, 1}},
    };

    return output;
}
const VersionMap& HDAccountAllowedBlockchainAddress() noexcept
{
    static const auto output = VersionMap{
        {1, {1, 1}},
    };

    return output;
}
const VersionMap& HDAccountAllowedHDPath() noexcept
{
    static const auto output = VersionMap{
        {1, {1, 1}},
    };

    return output;
}
}  // namespace opentxs::proto
