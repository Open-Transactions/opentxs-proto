// Copyright (c) 2019 The Open-Transactions developers
// This Source Code Form is subject to the terms of the Mozilla Public
// License, v. 2.0. If a copy of the MPL was not distributed with this
// file, You can obtain one at http://mozilla.org/MPL/2.0/.

#ifndef OPENTXS_PROTO_SIGNATURE_HPP
#define OPENTXS_PROTO_SIGNATURE_HPP

#include "VerifyCredentials.hpp"

namespace opentxs
{
namespace proto
{
EXPORT bool CheckProto_1(
    const Signature& signature,
    const bool silent,
    const std::string& selfID,
    const std::string& masterID,
    std::uint32_t& selfPublic,
    std::uint32_t& selfPrivate,
    std::uint32_t& masterPublic,
    std::uint32_t& sourcePublic,
    const SignatureRole role = SIGROLE_ERROR);
EXPORT bool CheckProto_1(
    const Signature& signature,
    const bool silent,
    const SignatureRole role = SIGROLE_ERROR);
EXPORT bool CheckProto_2(
    const Signature& signature,
    const bool silent,
    const std::string& selfID,
    const std::string& masterID,
    std::uint32_t& selfPublic,
    std::uint32_t& selfPrivate,
    std::uint32_t& masterPublic,
    std::uint32_t& sourcePublic,
    const SignatureRole role = SIGROLE_ERROR);
EXPORT bool CheckProto_2(
    const Signature& signature,
    const bool silent,
    const SignatureRole role = SIGROLE_ERROR);
EXPORT bool CheckProto_3(
    const Signature&,
    const bool,
    const std::string&,
    const std::string&,
    std::uint32_t&,
    std::uint32_t&,
    std::uint32_t&,
    std::uint32_t&,
    const SignatureRole role = SIGROLE_ERROR);
EXPORT bool CheckProto_3(
    const Signature&,
    const bool,
    const SignatureRole role = SIGROLE_ERROR);
EXPORT bool CheckProto_4(
    const Signature&,
    const bool,
    const std::string&,
    const std::string&,
    std::uint32_t&,
    std::uint32_t&,
    std::uint32_t&,
    std::uint32_t&,
    const SignatureRole role = SIGROLE_ERROR);
EXPORT bool CheckProto_4(
    const Signature&,
    const bool,
    const SignatureRole role = SIGROLE_ERROR);
EXPORT bool CheckProto_5(
    const Signature&,
    const bool,
    const std::string&,
    const std::string&,
    std::uint32_t&,
    std::uint32_t&,
    std::uint32_t&,
    std::uint32_t&,
    const SignatureRole role = SIGROLE_ERROR);
EXPORT bool CheckProto_5(
    const Signature&,
    const bool,
    const SignatureRole role = SIGROLE_ERROR);

EXPORT bool CheckProto_6(
    const Signature&,
    const bool,
    const std::string&,
    const std::string&,
    std::uint32_t&,
    std::uint32_t&,
    std::uint32_t&,
    std::uint32_t&,
    const SignatureRole role = SIGROLE_ERROR);
EXPORT bool CheckProto_7(
    const Signature&,
    const bool,
    const std::string&,
    const std::string&,
    std::uint32_t&,
    std::uint32_t&,
    std::uint32_t&,
    std::uint32_t&,
    const SignatureRole role = SIGROLE_ERROR);
EXPORT bool CheckProto_8(
    const Signature&,
    const bool,
    const std::string&,
    const std::string&,
    std::uint32_t&,
    std::uint32_t&,
    std::uint32_t&,
    std::uint32_t&,
    const SignatureRole role = SIGROLE_ERROR);
EXPORT bool CheckProto_9(
    const Signature&,
    const bool,
    const std::string&,
    const std::string&,
    std::uint32_t&,
    std::uint32_t&,
    std::uint32_t&,
    std::uint32_t&,
    const SignatureRole role = SIGROLE_ERROR);
EXPORT bool CheckProto_10(
    const Signature&,
    const bool,
    const std::string&,
    const std::string&,
    std::uint32_t&,
    std::uint32_t&,
    std::uint32_t&,
    std::uint32_t&,
    const SignatureRole role = SIGROLE_ERROR);
EXPORT bool CheckProto_11(
    const Signature&,
    const bool,
    const std::string&,
    const std::string&,
    std::uint32_t&,
    std::uint32_t&,
    std::uint32_t&,
    std::uint32_t&,
    const SignatureRole role = SIGROLE_ERROR);
EXPORT bool CheckProto_12(
    const Signature&,
    const bool,
    const std::string&,
    const std::string&,
    std::uint32_t&,
    std::uint32_t&,
    std::uint32_t&,
    std::uint32_t&,
    const SignatureRole role = SIGROLE_ERROR);
EXPORT bool CheckProto_13(
    const Signature&,
    const bool,
    const std::string&,
    const std::string&,
    std::uint32_t&,
    std::uint32_t&,
    std::uint32_t&,
    std::uint32_t&,
    const SignatureRole role = SIGROLE_ERROR);
EXPORT bool CheckProto_14(
    const Signature&,
    const bool,
    const std::string&,
    const std::string&,
    std::uint32_t&,
    std::uint32_t&,
    std::uint32_t&,
    std::uint32_t&,
    const SignatureRole role = SIGROLE_ERROR);
EXPORT bool CheckProto_15(
    const Signature&,
    const bool,
    const std::string&,
    const std::string&,
    std::uint32_t&,
    std::uint32_t&,
    std::uint32_t&,
    std::uint32_t&,
    const SignatureRole role = SIGROLE_ERROR);
EXPORT bool CheckProto_16(
    const Signature&,
    const bool,
    const std::string&,
    const std::string&,
    std::uint32_t&,
    std::uint32_t&,
    std::uint32_t&,
    std::uint32_t&,
    const SignatureRole role = SIGROLE_ERROR);
EXPORT bool CheckProto_17(
    const Signature&,
    const bool,
    const std::string&,
    const std::string&,
    std::uint32_t&,
    std::uint32_t&,
    std::uint32_t&,
    std::uint32_t&,
    const SignatureRole role = SIGROLE_ERROR);
EXPORT bool CheckProto_18(
    const Signature&,
    const bool,
    const std::string&,
    const std::string&,
    std::uint32_t&,
    std::uint32_t&,
    std::uint32_t&,
    std::uint32_t&,
    const SignatureRole role = SIGROLE_ERROR);
EXPORT bool CheckProto_19(
    const Signature&,
    const bool,
    const std::string&,
    const std::string&,
    std::uint32_t&,
    std::uint32_t&,
    std::uint32_t&,
    std::uint32_t&,
    const SignatureRole role = SIGROLE_ERROR);
EXPORT bool CheckProto_20(
    const Signature&,
    const bool,
    const std::string&,
    const std::string&,
    std::uint32_t&,
    std::uint32_t&,
    std::uint32_t&,
    std::uint32_t&,
    const SignatureRole role = SIGROLE_ERROR);

EXPORT bool CheckProto_6(
    const Signature&,
    const bool,
    const SignatureRole role = SIGROLE_ERROR);
EXPORT bool CheckProto_7(
    const Signature&,
    const bool,
    const SignatureRole role = SIGROLE_ERROR);
EXPORT bool CheckProto_8(
    const Signature&,
    const bool,
    const SignatureRole role = SIGROLE_ERROR);
EXPORT bool CheckProto_9(
    const Signature&,
    const bool,
    const SignatureRole role = SIGROLE_ERROR);
EXPORT bool CheckProto_10(
    const Signature&,
    const bool,
    const SignatureRole role = SIGROLE_ERROR);
EXPORT bool CheckProto_11(
    const Signature&,
    const bool,
    const SignatureRole role = SIGROLE_ERROR);
EXPORT bool CheckProto_12(
    const Signature&,
    const bool,
    const SignatureRole role = SIGROLE_ERROR);
EXPORT bool CheckProto_13(
    const Signature&,
    const bool,
    const SignatureRole role = SIGROLE_ERROR);
EXPORT bool CheckProto_14(
    const Signature&,
    const bool,
    const SignatureRole role = SIGROLE_ERROR);
EXPORT bool CheckProto_15(
    const Signature&,
    const bool,
    const SignatureRole role = SIGROLE_ERROR);
EXPORT bool CheckProto_16(
    const Signature&,
    const bool,
    const SignatureRole role = SIGROLE_ERROR);
EXPORT bool CheckProto_17(
    const Signature&,
    const bool,
    const SignatureRole role = SIGROLE_ERROR);
EXPORT bool CheckProto_18(
    const Signature&,
    const bool,
    const SignatureRole role = SIGROLE_ERROR);
EXPORT bool CheckProto_19(
    const Signature&,
    const bool,
    const SignatureRole role = SIGROLE_ERROR);
EXPORT bool CheckProto_20(
    const Signature&,
    const bool,
    const SignatureRole role = SIGROLE_ERROR);
}  // namespace proto
}  // namespace opentxs

#endif  // OPENTXS_PROTO_SIGNATURE_HPP
