// Copyright (c) 2018 The Open-Transactions developers
// This Source Code Form is subject to the terms of the Mozilla Public
// License, v. 2.0. If a copy of the MPL was not distributed with this
// file, You can obtain one at http://mozilla.org/MPL/2.0/.

#include "opentxs-proto/Types.hpp"
#include "opentxs-proto/Check.hpp"

#define PROTO_NAME "signature"

namespace opentxs
{
namespace proto
{
bool CheckProto_3(
    const Signature& input,
    const bool silent,
    const std::string& selfID,
    const std::string& masterID,
    std::uint32_t& selfPublic,
    std::uint32_t& selfPrivate,
    std::uint32_t& masterPublic,
    std::uint32_t& sourcePublic,
    const SignatureRole role)
{
    if (!input.has_role()) { FAIL_1("missing role") }

    switch (input.role()) {
        case SIGROLE_PUBCREDENTIAL:
        case SIGROLE_PRIVCREDENTIAL:
        case SIGROLE_NYMIDSOURCE:
        case SIGROLE_CLAIM:
        case SIGROLE_SERVERCONTRACT:
        case SIGROLE_UNITDEFINITION:
        case SIGROLE_PEERREQUEST:
        case SIGROLE_PEERREPLY:
        case SIGROLE_CONTEXT:
        case SIGROLE_ACCOUNT:
        case SIGROLE_SERVERREQUEST:
        case SIGROLE_SERVERREPLY: {
            break;
        }
        default: {
            FAIL_2("invalid role", input.role())
        }
    }

    if ((SIGROLE_ERROR != role) && (role != input.role())) {
        FAIL_4("incorrect role", input.role(), " specified ", role)
    }

    if (proto::SIGROLE_NYMIDSOURCE != input.role()) {

        if (!input.has_credentialid()) {
            FAIL_1(" missing credential identifier")
        }

        if (MIN_PLAUSIBLE_IDENTIFIER > input.credentialid().size()) {
            FAIL_2("invalid credential id", input.credentialid())
        }
    }

    if (!input.has_hashtype()) { FAIL_1("missing hashtype") }

    if (input.hashtype() > proto::HASHTYPE_BLAKE2B512) {
        FAIL_2("invalid hash type", input.hashtype())
    }

    if (!input.has_signature()) { FAIL_1("missing signature") }

    if (MIN_PLAUSIBLE_SIGNATURE > input.signature().size()) {
        FAIL_1("invalid signature")
    }

    if ((SIGROLE_PUBCREDENTIAL == input.role()) &&
        (selfID == input.credentialid())) {
        selfPublic += 1;
    }

    if ((SIGROLE_PUBCREDENTIAL == input.role()) &&
        (masterID == input.credentialid())) {
        masterPublic += 1;
    }

    if ((SIGROLE_PRIVCREDENTIAL == input.role()) &&
        (selfID == input.credentialid())) {
        selfPrivate += 1;
    }

    if (SIGROLE_NYMIDSOURCE == input.role()) { sourcePublic += 1; }

    return true;
}

bool CheckProto_3(
    const Signature& input,
    const bool silent,
    const SignatureRole role)
{
    std::uint32_t unused = 0;

    return CheckProto_3(
        input, silent, "", "", unused, unused, unused, unused, role);
}

bool CheckProto_4(
    const Signature& input,
    const bool silent,
    const std::string&,
    const std::string&,
    std::uint32_t&,
    std::uint32_t&,
    std::uint32_t&,
    std::uint32_t&,
    const SignatureRole)
{
    UNDEFINED_VERSION(4)
}

bool CheckProto_4(
    const Signature& input,
    const bool silent,
    const SignatureRole role)
{
    std::uint32_t unused = 0;

    return CheckProto_4(
        input, silent, "", "", unused, unused, unused, unused, role);
}

bool CheckProto_5(
    const Signature& input,
    const bool silent,
    const std::string&,
    const std::string&,
    std::uint32_t&,
    std::uint32_t&,
    std::uint32_t&,
    std::uint32_t&,
    const SignatureRole)
{
    UNDEFINED_VERSION(5)
}

bool CheckProto_5(
    const Signature& input,
    const bool silent,
    const SignatureRole role)
{
    std::uint32_t unused = 0;

    return CheckProto_5(
        input, silent, "", "", unused, unused, unused, unused, role);
}

bool CheckProto_6(
    const Signature& input,
    const bool silent,
    const std::string&,
    const std::string&,
    std::uint32_t&,
    std::uint32_t&,
    std::uint32_t&,
    std::uint32_t&,
    const SignatureRole)
{
    UNDEFINED_VERSION(6)
}

bool CheckProto_7(
    const Signature& input,
    const bool silent,
    const std::string&,
    const std::string&,
    std::uint32_t&,
    std::uint32_t&,
    std::uint32_t&,
    std::uint32_t&,
    const SignatureRole)
{
    UNDEFINED_VERSION(7)
}

bool CheckProto_8(
    const Signature& input,
    const bool silent,
    const std::string&,
    const std::string&,
    std::uint32_t&,
    std::uint32_t&,
    std::uint32_t&,
    std::uint32_t&,
    const SignatureRole)
{
    UNDEFINED_VERSION(8)
}

bool CheckProto_9(
    const Signature& input,
    const bool silent,
    const std::string&,
    const std::string&,
    std::uint32_t&,
    std::uint32_t&,
    std::uint32_t&,
    std::uint32_t&,
    const SignatureRole)
{
    UNDEFINED_VERSION(9)
}

bool CheckProto_10(
    const Signature& input,
    const bool silent,
    const std::string&,
    const std::string&,
    std::uint32_t&,
    std::uint32_t&,
    std::uint32_t&,
    std::uint32_t&,
    const SignatureRole)
{
    UNDEFINED_VERSION(10)
}

bool CheckProto_11(
    const Signature& input,
    const bool silent,
    const std::string&,
    const std::string&,
    std::uint32_t&,
    std::uint32_t&,
    std::uint32_t&,
    std::uint32_t&,
    const SignatureRole)
{
    UNDEFINED_VERSION(11)
}

bool CheckProto_12(
    const Signature& input,
    const bool silent,
    const std::string&,
    const std::string&,
    std::uint32_t&,
    std::uint32_t&,
    std::uint32_t&,
    std::uint32_t&,
    const SignatureRole)
{
    UNDEFINED_VERSION(12)
}

bool CheckProto_13(
    const Signature& input,
    const bool silent,
    const std::string&,
    const std::string&,
    std::uint32_t&,
    std::uint32_t&,
    std::uint32_t&,
    std::uint32_t&,
    const SignatureRole)
{
    UNDEFINED_VERSION(13)
}

bool CheckProto_14(
    const Signature& input,
    const bool silent,
    const std::string&,
    const std::string&,
    std::uint32_t&,
    std::uint32_t&,
    std::uint32_t&,
    std::uint32_t&,
    const SignatureRole)
{
    UNDEFINED_VERSION(14)
}

bool CheckProto_15(
    const Signature& input,
    const bool silent,
    const std::string&,
    const std::string&,
    std::uint32_t&,
    std::uint32_t&,
    std::uint32_t&,
    std::uint32_t&,
    const SignatureRole)
{
    UNDEFINED_VERSION(15)
}

bool CheckProto_16(
    const Signature& input,
    const bool silent,
    const std::string&,
    const std::string&,
    std::uint32_t&,
    std::uint32_t&,
    std::uint32_t&,
    std::uint32_t&,
    const SignatureRole)
{
    UNDEFINED_VERSION(16)
}

bool CheckProto_17(
    const Signature& input,
    const bool silent,
    const std::string&,
    const std::string&,
    std::uint32_t&,
    std::uint32_t&,
    std::uint32_t&,
    std::uint32_t&,
    const SignatureRole)
{
    UNDEFINED_VERSION(17)
}

bool CheckProto_18(
    const Signature& input,
    const bool silent,
    const std::string&,
    const std::string&,
    std::uint32_t&,
    std::uint32_t&,
    std::uint32_t&,
    std::uint32_t&,
    const SignatureRole)
{
    UNDEFINED_VERSION(18)
}

bool CheckProto_19(
    const Signature& input,
    const bool silent,
    const std::string&,
    const std::string&,
    std::uint32_t&,
    std::uint32_t&,
    std::uint32_t&,
    std::uint32_t&,
    const SignatureRole)
{
    UNDEFINED_VERSION(19)
}

bool CheckProto_20(
    const Signature& input,
    const bool silent,
    const std::string&,
    const std::string&,
    std::uint32_t&,
    std::uint32_t&,
    std::uint32_t&,
    std::uint32_t&,
    const SignatureRole)
{
    UNDEFINED_VERSION(20)
}

bool CheckProto_6(
    const Signature& input,
    const bool silent,
    const SignatureRole role)
{
    UNDEFINED_VERSION(6)
}

bool CheckProto_7(
    const Signature& input,
    const bool silent,
    const SignatureRole role)
{
    UNDEFINED_VERSION(7)
}

bool CheckProto_8(
    const Signature& input,
    const bool silent,
    const SignatureRole role)
{
    UNDEFINED_VERSION(8)
}

bool CheckProto_9(
    const Signature& input,
    const bool silent,
    const SignatureRole role)
{
    UNDEFINED_VERSION(9)
}

bool CheckProto_10(
    const Signature& input,
    const bool silent,
    const SignatureRole role)
{
    UNDEFINED_VERSION(10)
}

bool CheckProto_11(
    const Signature& input,
    const bool silent,
    const SignatureRole role)
{
    UNDEFINED_VERSION(11)
}

bool CheckProto_12(
    const Signature& input,
    const bool silent,
    const SignatureRole role)
{
    UNDEFINED_VERSION(12)
}

bool CheckProto_13(
    const Signature& input,
    const bool silent,
    const SignatureRole role)
{
    UNDEFINED_VERSION(13)
}

bool CheckProto_14(
    const Signature& input,
    const bool silent,
    const SignatureRole role)
{
    UNDEFINED_VERSION(14)
}

bool CheckProto_15(
    const Signature& input,
    const bool silent,
    const SignatureRole role)
{
    UNDEFINED_VERSION(15)
}

bool CheckProto_16(
    const Signature& input,
    const bool silent,
    const SignatureRole role)
{
    UNDEFINED_VERSION(16)
}

bool CheckProto_17(
    const Signature& input,
    const bool silent,
    const SignatureRole role)
{
    UNDEFINED_VERSION(17)
}

bool CheckProto_18(
    const Signature& input,
    const bool silent,
    const SignatureRole role)
{
    UNDEFINED_VERSION(18)
}

bool CheckProto_19(
    const Signature& input,
    const bool silent,
    const SignatureRole role)
{
    UNDEFINED_VERSION(19)
}

bool CheckProto_20(
    const Signature& input,
    const bool silent,
    const SignatureRole role)
{
    UNDEFINED_VERSION(20)
}
}  // namespace proto
}  // namespace opentxs
