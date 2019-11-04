// Copyright (c) 2019 The Open-Transactions developers
// This Source Code Form is subject to the terms of the Mozilla Public
// License, v. 2.0. If a copy of the MPL was not distributed with this
// file, You can obtain one at http://mozilla.org/MPL/2.0/.

#include "opentxs-proto/verify/VerifyStorage.hpp"

namespace opentxs::proto
{
const VersionMap& BlindedSeriesListAllowedStorageItemHash() noexcept
{
    static const auto output = VersionMap{
        {1, {1, 2}},
    };

    return output;
}
const VersionMap& StorageAccountsAllowedStorageAccountIndex() noexcept
{
    static const auto output = VersionMap{
        {1, {1, 1}},
    };

    return output;
}
const VersionMap& StorageAccountsAllowedStorageItemHash() noexcept
{
    static const auto output = VersionMap{
        {1, {1, 2}},
    };

    return output;
}
const VersionMap& StorageAccountsAllowedStorageIDList() noexcept
{
    static const auto output = VersionMap{
        {1, {1, 1}},
    };

    return output;
}
const VersionMap& StorageBip47ContextsAllowedStorageBip47AddressIndex() noexcept
{
    static const auto output = VersionMap{{1, {1, 1}}};

    return output;
}
const VersionMap& StorageBip47ContextsAllowedStorageItemHash() noexcept
{
    static const auto output = VersionMap{{1, {1, 2}}};

    return output;
}
const VersionMap& StorageBip47ContextsAllowedStorageBip47ChannelList() noexcept
{
    static const auto output = VersionMap{{1, {1, 1}}};

    return output;
}
const VersionMap&
StorageBlockchainTransactionsAllowedStorageContactNymIndex() noexcept
{
    static const auto output = VersionMap{
        {2, {1, 1}},
    };

    return output;
}
const VersionMap& StorageBlockchainTransactionsAllowedStorageItemHash() noexcept
{
    static const auto output = VersionMap{
        {1, {1, 2}},
        {2, {1, 2}},
    };

    return output;
}
const VersionMap& StorageBlockchainTxoAllowedBlockchainPreviousOutput() noexcept
{
    static const auto output = VersionMap{{1, {1, 1}}};

    return output;
}
const VersionMap& StorageContactsAllowedAddress() noexcept
{
    static const auto output = VersionMap{
        {1, {1, 1}},
        {2, {1, 1}},
    };

    return output;
}
const VersionMap& StorageContactsAllowedList() noexcept
{
    static const auto output = VersionMap{
        {1, {1, 1}},
        {2, {1, 1}},
    };

    return output;
}
const VersionMap& StorageContactsAllowedStorageContactNymIndex() noexcept
{
    static const auto output = VersionMap{
        {2, {1, 1}},
    };

    return output;
}
const VersionMap& StorageContactsAllowedStorageItemHash() noexcept
{
    static const auto output = VersionMap{
        {1, {1, 2}},
        {2, {1, 2}},
    };

    return output;
}
const VersionMap& StorageCredentialAllowedStorageItemHash() noexcept
{
    static const auto output = VersionMap{
        {1, {1, 1}},
        {2, {1, 2}},
    };

    return output;
}
const VersionMap& StorageIssuerAllowedStorageItemHash() noexcept
{
    static const auto output = VersionMap{
        {1, {1, 2}},
    };

    return output;
}
const VersionMap& StorageItemsAllowedSymmetricKey() noexcept
{
    static const auto output = VersionMap{
        {6, {1, 1}},
    };

    return output;
}
const VersionMap& StorageNotaryAllowedBlindedSeriesList() noexcept
{
    static const auto output = VersionMap{
        {1, {1, 1}},
    };

    return output;
}
const VersionMap& StorageNymAllowedBlockchainAccountList() noexcept
{
    static const auto output = VersionMap{
        {4, {1, 1}},
        {5, {1, 1}},
        {6, {1, 1}},
        {7, {1, 1}},
        {8, {1, 1}},
        {9, {1, 1}},
    };

    return output;
}
const VersionMap& StorageNymAllowedHDAccount() noexcept
{
    static const auto output = VersionMap{
        {4, {1, 1}},
        {5, {1, 1}},
        {6, {1, 1}},
        {7, {1, 1}},
        {8, {1, 1}},
        {9, {1, 1}},
    };

    return output;
}
const VersionMap& StorageNymAllowedStorageBip47AddressIndex() noexcept
{
    static const auto output = VersionMap{
        {7, {1, 1}},
        {8, {1, 1}},
        {9, {1, 1}},
    };

    return output;
}
const VersionMap& StorageNymAllowedStorageItemHash() noexcept
{
    static const auto output = VersionMap{
        {1, {1, 1}},
        {2, {1, 2}},
        {3, {2, 3}},
        {4, {2, 4}},
        {5, {2, 5}},
        {6, {2, 6}},
        {7, {2, 7}},
        {8, {2, 8}},
        {9, {2, 9}},
    };

    return output;
}
const VersionMap& StorageNymAllowedStoragePurse() noexcept
{
    static const auto output = VersionMap{
        {8, {1, 1}},
        {9, {1, 1}},
    };

    return output;
}
const VersionMap& StorageNymListAllowedStorageBip47NymAddressIndex() noexcept
{
    static const auto output = VersionMap{
        {4, {1, 1}},
    };

    return output;
}
const VersionMap& StorageNymListAllowedStorageItemHash() noexcept
{
    static const auto output = VersionMap{
        {1, {1, 1}},
        {2, {1, 2}},
        {3, {1, 3}},
        {4, {1, 4}},
    };

    return output;
}
const VersionMap& StoragePaymentWorkflowsAllowedStorageItemHash() noexcept
{
    static const auto output = VersionMap{
        {1, {1, 2}},
        {2, {1, 2}},
        {3, {1, 2}},
    };

    return output;
}
const VersionMap&
StoragePaymentWorkflowsAllowedStoragePaymentWorkflowType() noexcept
{
    static const auto output = VersionMap{
        {1, {1, 1}},
        {2, {1, 2}},
        {3, {3, 3}},
    };

    return output;
}
const VersionMap& StoragePaymentWorkflowsAllowedStorageWorkflowIndex() noexcept
{
    static const auto output = VersionMap{
        {1, {1, 1}},
        {2, {1, 1}},
        {3, {1, 1}},
    };

    return output;
}
const VersionMap& StoragePurseAllowedStorageItemHash() noexcept
{
    static const auto output = VersionMap{
        {1, {1, 2}},
    };

    return output;
}
const VersionMap& StorageSeedsAllowedStorageItemHash() noexcept
{
    static const auto output = VersionMap{
        {1, {1, 1}},
        {2, {1, 2}},
    };

    return output;
}
const VersionMap& StorageServersAllowedStorageItemHash() noexcept
{
    static const auto output = VersionMap{
        {1, {1, 1}},
        {2, {1, 2}},
    };

    return output;
}
const VersionMap& StorageThreadAllowedItem() noexcept
{
    static const auto output = VersionMap{
        {1, {1, 1}},
    };

    return output;
}
const VersionMap& StorageTxoIndexAllowedStorageBlockchainTxo() noexcept
{
    static const auto output = VersionMap{
        {1, {1, 1}},
    };

    return output;
}
const VersionMap& StorageUnitsAllowedStorageItemHash() noexcept
{
    static const auto output = VersionMap{
        {1, {1, 1}},
        {2, {1, 2}},
    };

    return output;
}
}  // namespace opentxs::proto
