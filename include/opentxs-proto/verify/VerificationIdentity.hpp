// Copyright (c) 2019 The Open-Transactions developers
// This Source Code Form is subject to the terms of the Mozilla Public
// License, v. 2.0. If a copy of the MPL was not distributed with this
// file, You can obtain one at http://mozilla.org/MPL/2.0/.

#ifndef OPENTXS_PROTO_VERIFICATIONIDENTITY_HPP
#define OPENTXS_PROTO_VERIFICATIONIDENTITY_HPP

#include "VerifyContacts.hpp"

#include <map>

namespace opentxs
{
namespace proto
{
using VerificationNymMap = std::map<std::string, std::uint64_t>;

OPENTXS_PROTO_EXPORT bool CheckProto_1(
    const VerificationIdentity& verificationIdentity,
    const bool silent,
    VerificationNymMap& map,
    const VerificationType indexed);
OPENTXS_PROTO_EXPORT bool CheckProto_2(
    const VerificationIdentity&,
    const bool,
    VerificationNymMap&,
    const VerificationType);
OPENTXS_PROTO_EXPORT bool CheckProto_3(
    const VerificationIdentity&,
    const bool,
    VerificationNymMap&,
    const VerificationType);
OPENTXS_PROTO_EXPORT bool CheckProto_4(
    const VerificationIdentity&,
    const bool,
    VerificationNymMap&,
    const VerificationType);
OPENTXS_PROTO_EXPORT bool CheckProto_5(
    const VerificationIdentity&,
    const bool,
    VerificationNymMap&,
    const VerificationType);
OPENTXS_PROTO_EXPORT bool CheckProto_6(
    const VerificationIdentity&,
    const bool,
    VerificationNymMap&,
    const VerificationType);
OPENTXS_PROTO_EXPORT bool CheckProto_7(
    const VerificationIdentity&,
    const bool,
    VerificationNymMap&,
    const VerificationType);
OPENTXS_PROTO_EXPORT bool CheckProto_8(
    const VerificationIdentity&,
    const bool,
    VerificationNymMap&,
    const VerificationType);
OPENTXS_PROTO_EXPORT bool CheckProto_9(
    const VerificationIdentity&,
    const bool,
    VerificationNymMap&,
    const VerificationType);
OPENTXS_PROTO_EXPORT bool CheckProto_10(
    const VerificationIdentity&,
    const bool,
    VerificationNymMap&,
    const VerificationType);
OPENTXS_PROTO_EXPORT bool CheckProto_11(
    const VerificationIdentity&,
    const bool,
    VerificationNymMap&,
    const VerificationType);
OPENTXS_PROTO_EXPORT bool CheckProto_12(
    const VerificationIdentity&,
    const bool,
    VerificationNymMap&,
    const VerificationType);
OPENTXS_PROTO_EXPORT bool CheckProto_13(
    const VerificationIdentity&,
    const bool,
    VerificationNymMap&,
    const VerificationType);
OPENTXS_PROTO_EXPORT bool CheckProto_14(
    const VerificationIdentity&,
    const bool,
    VerificationNymMap&,
    const VerificationType);
OPENTXS_PROTO_EXPORT bool CheckProto_15(
    const VerificationIdentity&,
    const bool,
    VerificationNymMap&,
    const VerificationType);
OPENTXS_PROTO_EXPORT bool CheckProto_16(
    const VerificationIdentity&,
    const bool,
    VerificationNymMap&,
    const VerificationType);
OPENTXS_PROTO_EXPORT bool CheckProto_17(
    const VerificationIdentity&,
    const bool,
    VerificationNymMap&,
    const VerificationType);
OPENTXS_PROTO_EXPORT bool CheckProto_18(
    const VerificationIdentity&,
    const bool,
    VerificationNymMap&,
    const VerificationType);
OPENTXS_PROTO_EXPORT bool CheckProto_19(
    const VerificationIdentity&,
    const bool,
    VerificationNymMap&,
    const VerificationType);
OPENTXS_PROTO_EXPORT bool CheckProto_20(
    const VerificationIdentity&,
    const bool,
    VerificationNymMap&,
    const VerificationType);
}  // namespace proto
}  // namespace opentxs

#endif  // OPENTXS_PROTO_VERIFICATIONIDENTITY_HPP
