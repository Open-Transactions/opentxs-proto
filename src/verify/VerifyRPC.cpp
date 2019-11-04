// Copyright (c) 2019 The Open-Transactions developers
// This Source Code Form is subject to the terms of the Mozilla Public
// License, v. 2.0. If a copy of the MPL was not distributed with this
// file, You can obtain one at http://mozilla.org/MPL/2.0/.

#include "opentxs-proto/verify/VerifyRPC.hpp"

namespace opentxs::proto
{
const VersionMap& AddClaimAllowedContactItem() noexcept
{
    static const auto output = VersionMap{
        {1, {1, 5}},
        {2, {1, 6}},
    };

    return output;
}

const VersionMap& ContactEventAllowedAccountEvent() noexcept
{
    static const auto output = VersionMap{
        {1, {1, 1}},
        {2, {1, 2}},
    };

    return output;
}

const VersionMap& CreateNymAllowedAddClaim() noexcept
{
    static const auto output = VersionMap{
        {1, {1, 1}},
        {2, {1, 2}},
    };

    return output;
}

const VersionMap& RPCCommandAllowedAPIArgument() noexcept
{
    static const auto output = VersionMap{
        {1, {1, 1}},
        {2, {1, 1}},
        {3, {1, 1}},
    };

    return output;
}

const VersionMap& RPCCommandAllowedAcceptPendingPayment() noexcept
{
    static const auto output = VersionMap{
        {1, {1, 1}},
        {2, {1, 1}},
        {3, {1, 1}},
    };

    return output;
}

const VersionMap& RPCCommandAllowedAddClaim() noexcept
{
    static const auto output = VersionMap{
        {1, {1, 1}},
        {2, {1, 2}},
        {3, {1, 2}},
    };

    return output;
}

const VersionMap& RPCCommandAllowedAddContact() noexcept
{
    static const auto output = VersionMap{
        {1, {1, 1}},
        {2, {1, 1}},
        {3, {1, 1}},
    };

    return output;
}

const VersionMap& RPCCommandAllowedCreateInstrumentDefinition() noexcept
{
    static const auto output = VersionMap{
        {1, {1, 1}},
        {2, {1, 1}},
        {3, {1, 1}},
    };

    return output;
}

const VersionMap& RPCCommandAllowedCreateNym() noexcept
{
    static const auto output = VersionMap{
        {1, {1, 1}},
        {2, {1, 2}},
        {3, {1, 2}},
    };

    return output;
}

const VersionMap& RPCCommandAllowedGetWorkflow() noexcept
{
    static const auto output = VersionMap{
        {1, {1, 1}},
        {2, {1, 1}},
        {3, {1, 1}},
    };

    return output;
}

const VersionMap& RPCCommandAllowedHDSeed() noexcept
{
    static const auto output = VersionMap{
        {1, {1, 1}},
        {2, {1, 1}},
        {3, {1, 1}},
    };

    return output;
}

const VersionMap& RPCCommandAllowedModifyAccount() noexcept
{
    static const auto output = VersionMap{
        {2, {1, 1}},
        {3, {1, 1}},
    };

    return output;
}

const VersionMap& RPCCommandAllowedSendMessage() noexcept
{
    static const auto output = VersionMap{
        {1, {1, 1}},
        {2, {1, 1}},
        {3, {1, 1}},
    };

    return output;
}

const VersionMap& RPCCommandAllowedSendPayment() noexcept
{
    static const auto output = VersionMap{
        {1, {1, 1}},
        {2, {1, 1}},
        {3, {1, 1}},
    };

    return output;
}

const VersionMap& RPCCommandAllowedServerContract() noexcept
{
    static const auto output = VersionMap{
        {1, {1, 2}},
        {2, {1, 2}},
        {3, {1, 2}},
    };

    return output;
}

const VersionMap& RPCCommandAllowedVerification() noexcept
{
    static const auto output = VersionMap{
        {1, {1, 1}},
        {2, {1, 1}},
        {3, {1, 1}},
    };

    return output;
}

const VersionMap& RPCCommandAllowedVerifyClaim() noexcept
{
    static const auto output = VersionMap{
        {1, {1, 1}},
        {2, {1, 1}},
        {3, {1, 1}},
    };

    return output;
}

const VersionMap& RPCPushAllowedAccountEvent() noexcept
{
    static const auto output = VersionMap{
        {1, {1, 1}},
        {2, {1, 2}},
        {3, {1, 2}},
    };

    return output;
}

const VersionMap& RPCPushAllowedContactEvent() noexcept
{
    static const auto output = VersionMap{
        {1, {1, 1}},
        {2, {1, 2}},
        {3, {1, 2}},
    };

    return output;
}

const VersionMap& RPCPushAllowedTaskComplete() noexcept
{
    static const auto output = VersionMap{
        {1, {1, 1}},
        {2, {1, 1}},
        {3, {1, 2}},
    };

    return output;
}

const VersionMap& RPCResponseAllowedAccountData() noexcept
{
    static const auto output = VersionMap{
        {1, {1, 1}},
        {2, {1, 2}},
        {3, {1, 2}},
    };

    return output;
}

const VersionMap& RPCResponseAllowedAccountEvent() noexcept
{
    static const auto output = VersionMap{
        {1, {1, 1}},
        {2, {1, 2}},
        {3, {1, 2}},
    };

    return output;
}

const VersionMap& RPCResponseAllowedContact() noexcept
{
    static const auto output = VersionMap{
        {1, {1, 2}},
        {2, {1, 3}},
        {3, {1, 3}},
    };

    return output;
}

const VersionMap& RPCResponseAllowedContactEvent() noexcept
{
    static const auto output = VersionMap{
        {1, {1, 2}},
        {2, {1, 2}},
        {3, {1, 2}},
    };

    return output;
}

const VersionMap& RPCResponseAllowedHDSeed() noexcept
{
    static const auto output = VersionMap{
        {1, {1, 1}},
        {2, {1, 1}},
        {3, {1, 1}},
    };

    return output;
}

const VersionMap& RPCResponseAllowedNym() noexcept
{
    static const auto output = VersionMap{
        {1, {1, 5}},
        {2, {1, 6}},
        {3, {1, 6}},
    };

    return output;
}

const VersionMap& RPCResponseAllowedRPCStatus() noexcept
{
    static const auto output = VersionMap{
        {1, {1, 1}},
        {2, {1, 2}},
        {3, {1, 2}},
    };

    return output;
}

const VersionMap& RPCResponseAllowedRPCTask() noexcept
{
    static const auto output = VersionMap{
        {1, {1, 1}},
        {2, {1, 1}},
        {3, {1, 1}},
    };

    return output;
}

const VersionMap& RPCResponseAllowedServerContract() noexcept
{
    static const auto output = VersionMap{
        {1, {1, 2}},
        {2, {1, 2}},
        {3, {1, 2}},
    };

    return output;
}

const VersionMap& RPCResponseAllowedSessionData() noexcept
{
    static const auto output = VersionMap{
        {1, {1, 1}},
        {2, {1, 1}},
        {3, {1, 1}},
    };

    return output;
}

const VersionMap& RPCResponseAllowedTransactionData() noexcept
{
    static const auto output = VersionMap{
        {2, {1, 1}},
        {3, {1, 1}},
    };

    return output;
}

const VersionMap& RPCResponseAllowedUnitDefinition() noexcept
{
    static const auto output = VersionMap{
        {2, {1, 1}},
        {3, {1, 2}},
    };

    return output;
}

const VersionMap& RPCResponseAllowedWorkflow() noexcept
{
    static const auto output = VersionMap{
        {1, {1, 2}},
        {2, {1, 2}},
        {3, {1, 2}},
    };

    return output;
}
}  // namespace opentxs::proto
