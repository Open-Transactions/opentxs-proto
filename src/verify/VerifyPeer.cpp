// Copyright (c) 2020 The Open-Transactions developers
// This Source Code Form is subject to the terms of the Mozilla Public
// License, v. 2.0. If a copy of the MPL was not distributed with this
// file, You can obtain one at http://mozilla.org/MPL/2.0/.

#include "opentxs-proto/verify/VerifyPeer.hpp"

namespace opentxs::proto
{
const VersionMap& PeerObjectAllowedNym() noexcept
{
    static const auto output = VersionMap{
        {1, {1, 3}},
        {2, {1, 3}},
        {3, {1, 3}},
        {4, {1, 4}},
        {5, {1, 4}},
        {6, {1, 5}},
        {7, {1, 6}},
    };

    return output;
}
const VersionMap& PeerObjectAllowedPeerReply() noexcept
{
    static const auto output = VersionMap{
        {1, {1, 1}},
        {2, {2, 2}},
        {3, {3, 3}},
        {4, {4, 4}},
        {5, {4, 5}},
        {6, {4, 5}},
        {7, {4, 5}},
    };

    return output;
}
const VersionMap& PeerObjectAllowedPeerRequest() noexcept
{
    static const auto output = VersionMap{
        {1, {1, 2}},
        {2, {2, 2}},
        {3, {3, 3}},
        {4, {4, 4}},
        {5, {4, 5}},
        {6, {4, 6}},
        {7, {4, 6}},
    };

    return output;
}
const VersionMap& PeerObjectAllowedPurse() noexcept
{
    static const auto output = VersionMap{
        {7, {1, 1}},
    };

    return output;
}
const VersionMap& PeerReplyAllowedBailment() noexcept
{
    static const auto output = VersionMap{
        {1, {1, 1}},
        {2, {2, 2}},
        {3, {3, 3}},
        {4, {4, 4}},
    };

    return output;
}
const VersionMap& PeerReplyAllowedConnectionInfo() noexcept
{
    static const auto output = VersionMap{
        {1, {1, 1}},
        {2, {2, 2}},
        {3, {3, 3}},
        {4, {4, 4}},
    };

    return output;
}
const VersionMap& PeerReplyAllowedNotice() noexcept
{
    static const auto output = VersionMap{
        {1, {1, 1}},
        {2, {2, 2}},
        {3, {3, 3}},
        {4, {4, 4}},
        {5, {4, 5}},
    };

    return output;
}
const VersionMap& PeerReplyAllowedOutBailment() noexcept
{
    static const auto output = VersionMap{
        {1, {1, 1}},
        {2, {2, 2}},
        {3, {3, 3}},
        {4, {4, 4}},
    };

    return output;
}
const VersionMap& PeerReplyAllowedSignature() noexcept
{
    static const auto output = VersionMap{
        {1, {1, 1}},
        {2, {1, 1}},
        {3, {1, 1}},
        {4, {1, 1}},
        {5, {1, 1}},
    };

    return output;
}
const VersionMap& PeerRequestAllowedBailment() noexcept
{
    static const auto output = VersionMap{
        {1, {1, 1}},
        {2, {2, 2}},
        {3, {3, 3}},
        {4, {4, 4}},
    };

    return output;
}
const VersionMap& PeerRequestAllowedConnectionInfo() noexcept
{
    static const auto output = VersionMap{
        {1, {1, 1}},
        {2, {2, 2}},
        {3, {3, 3}},
        {4, {4, 4}},
    };

    return output;
}
const VersionMap& PeerRequestAllowedFaucet() noexcept
{
    static const auto output = VersionMap{
        {1, {0, 0}},
        {2, {0, 0}},
        {3, {0, 0}},
        {4, {4, 4}},
    };

    return output;
}
const VersionMap& PeerRequestAllowedOutBailment() noexcept
{
    static const auto output = VersionMap{
        {1, {1, 1}},
        {2, {2, 2}},
        {3, {3, 3}},
        {4, {4, 4}},
        {5, {5, 5}},
    };

    return output;
}
const VersionMap& PeerRequestAllowedPendingBailment() noexcept
{
    static const auto output = VersionMap{
        {1, {1, 1}},
        {2, {2, 2}},
        {3, {3, 3}},
        {4, {4, 4}},
        {5, {5, 5}},
        {6, {6, 6}},
    };

    return output;
}
const VersionMap& PeerRequestAllowedSignature() noexcept
{
    static const auto output = VersionMap{
        {1, {1, 1}},
        {2, {1, 1}},
        {3, {1, 1}},
        {4, {1, 1}},
        {5, {1, 1}},
        {6, {1, 1}},
    };

    return output;
}
const VersionMap& PeerRequestAllowedStoreSecret() noexcept
{
    static const auto output = VersionMap{
        {1, {1, 1}},
        {2, {2, 2}},
        {3, {3, 3}},
        {4, {4, 4}},
    };

    return output;
}
const VersionMap& PeerRequestAllowedVerificationOffer() noexcept
{
    static const auto output = VersionMap{
        {1, {0, 0}},
        {2, {0, 0}},
        {3, {3, 3}},
        {4, {4, 4}},
    };

    return output;
}
}  // namespace opentxs::proto
