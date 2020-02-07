// Copyright (c) 2020 The Open-Transactions developers
// This Source Code Form is subject to the terms of the Mozilla Public
// License, v. 2.0. If a copy of the MPL was not distributed with this
// file, You can obtain one at http://mozilla.org/MPL/2.0/.

#include "opentxs-proto/verify/VerifyCredentials.hpp"

namespace opentxs::proto
{
const VersionMap& AsymmetricKeyAllowedCiphertext() noexcept
{
    static const auto output = VersionMap{
        {1, {1, 1}},
        {2, {1, 1}},
    };

    return output;
}
const VersionMap& AsymmetricKeyAllowedHDPath() noexcept
{
    static const auto output = VersionMap{
        {1, {1, 1}},
        {2, {1, 1}},
    };

    return output;
}
const VersionMap& AuthorityAllowedCredential() noexcept
{
    static const auto output = VersionMap{
        {1, {1, 1}},
        {2, {1, 2}},
        {3, {1, 3}},
        {4, {1, 4}},
        {5, {1, 5}},
        {6, {1, 6}},
    };

    return output;
}
const VersionMap& CiphertextAllowedSymmetricKey() noexcept
{
    static const auto output = VersionMap{
        {1, {1, 1}},
    };

    return output;
}
const VersionMap& CredentialAllowedChildParams() noexcept
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
const VersionMap& CredentialAllowedContactData() noexcept
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
const VersionMap& CredentialAllowedKeyCredential() noexcept
{
    static const auto output = VersionMap{
        {1, {1, 1}},
        {2, {1, 1}},
        {3, {1, 1}},
        {4, {1, 1}},
        {5, {1, 1}},
        {6, {1, 2}},
    };

    return output;
}
const VersionMap& CredentialAllowedMasterParams() noexcept
{
    static const auto output = VersionMap{
        {1, {1, 1}},
        {2, {1, 1}},
        {3, {1, 1}},
        {4, {1, 1}},
        {5, {1, 1}},
        {6, {1, 2}},
    };

    return output;
}
const VersionMap& CredentialAllowedSignatures() noexcept
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
const VersionMap& CredentialAllowedVerification() noexcept
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
const VersionMap& EnvelopeAllowedAsymmetricKey() noexcept
{
    static const auto output = VersionMap{
        {1, {1, 1}},
        {2, {1, 2}},
    };

    return output;
}
const VersionMap& EnvelopeAllowedCiphertext() noexcept
{
    static const auto output = VersionMap{
        {1, {1, 1}},
        {2, {1, 1}},
    };

    return output;
}
const VersionMap& EnvelopeAllowedTaggedKey() noexcept
{
    static const auto output = VersionMap{
        {1, {1, 1}},
        {2, {1, 1}},
    };

    return output;
}
const VersionMap& KeyCredentialAllowedAsymmetricKey() noexcept
{
    static const auto output = VersionMap{
        {1, {1, 1}},
        {2, {1, 2}},
    };

    return output;
}
const VersionMap& MasterParamsAllowedNymIDSource() noexcept
{
    static const auto output = VersionMap{
        {1, {1, 1}},
        {2, {1, 2}},
    };

    return output;
}
const VersionMap& MasterParamsAllowedSourceProof() noexcept
{
    static const auto output = VersionMap{
        {1, {1, 1}},
        {2, {1, 1}},
    };

    return output;
}
const VersionMap& NymAllowedAuthority() noexcept
{
    static const auto output = VersionMap{
        {1, {1, 1}},
        {2, {1, 2}},
        {3, {1, 3}},
        {4, {1, 4}},
        {5, {1, 5}},
        {6, {1, 6}},
    };

    return output;
}
const VersionMap& NymAllowedNymIDSource() noexcept
{
    static const auto output = VersionMap{
        {1, {1, 1}},
        {2, {1, 1}},
        {3, {1, 1}},
        {4, {1, 1}},
        {5, {1, 1}},
        {6, {1, 2}},
    };

    return output;
}
const VersionMap& NymIDSourceAllowedAsymmetricKey() noexcept
{
    static const auto output = VersionMap{
        {1, {1, 1}},
        {2, {1, 2}},
    };

    return output;
}
const VersionMap& NymIDSourceAllowedPaymentCode() noexcept
{
    static const auto output = VersionMap{
        {1, {1, 1}},
    };

    return output;
}
const VersionMap& SeedAllowedCiphertext() noexcept
{
    static const auto output = VersionMap{
        {1, {1, 1}},
        {2, {1, 1}},
        {3, {1, 1}},
    };

    return output;
}
const VersionMap& SymmetricKeyAllowedCiphertext() noexcept
{
    static const auto output = VersionMap{
        {1, {1, 1}},
    };

    return output;
}
const VersionMap& TaggedKeyAllowedSymmetricKey() noexcept
{
    static const auto output = VersionMap{
        {1, {1, 1}},
    };

    return output;
}
}  // namespace opentxs::proto
