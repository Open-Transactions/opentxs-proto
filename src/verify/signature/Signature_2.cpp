/************************************************************
 *
 *                 OPEN TRANSACTIONS
 *
 *       Financial Cryptography and Digital Cash
 *       Library, Protocol, API, Server, CLI, GUI
 *
 *       -- Anonymous Numbered Accounts.
 *       -- Untraceable Digital Cash.
 *       -- Triple-Signed Receipts.
 *       -- Cheques, Vouchers, Transfers, Inboxes.
 *       -- Basket Currencies, Markets, Payment Plans.
 *       -- Signed, XML, Ricardian-style Contracts.
 *       -- Scripted smart contracts.
 *
 *  EMAIL:
 *  fellowtraveler@opentransactions.org
 *
 *  WEBSITE:
 *  http://www.opentransactions.org/
 *
 *  -----------------------------------------------------
 *
 *   LICENSE:
 *   This Source Code Form is subject to the terms of the
 *   Mozilla Public License, v. 2.0. If a copy of the MPL
 *   was not distributed with this file, You can obtain one
 *   at http://mozilla.org/MPL/2.0/.
 *
 *   DISCLAIMER:
 *   This program is distributed in the hope that it will
 *   be useful, but WITHOUT ANY WARRANTY; without even the
 *   implied warranty of MERCHANTABILITY or FITNESS FOR A
 *   PARTICULAR PURPOSE.  See the Mozilla Public License
 *   for more details.
 *
 ************************************************************/

#include "opentxs-proto/Types.hpp"
#include "opentxs-proto/Check.hpp"

#include <iostream>

namespace opentxs
{
namespace proto
{
bool CheckProto_2(
    const Signature& sig,
    const bool silent,
    const std::string& selfID,
    const std::string& masterID,
    std::uint32_t& selfPublic,
    std::uint32_t& selfPrivate,
    std::uint32_t& masterPublic,
    std::uint32_t& sourcePublic,
    const SignatureRole role)
{
    if (!sig.has_role()) {
        FAIL("signature", "missing role")
    }

    switch (sig.role()) {
        case SIGROLE_PUBCREDENTIAL:
        case SIGROLE_PRIVCREDENTIAL:
        case SIGROLE_NYMIDSOURCE:
        case SIGROLE_CLAIM:
        case SIGROLE_SERVERCONTRACT:
        case SIGROLE_UNITDEFINITION:
        case SIGROLE_PEERREQUEST:
        case SIGROLE_PEERREPLY:
        case SIGROLE_CONTEXT:
        case SIGROLE_ACCOUNT: {
            break;
        }
        default: {
            FAIL2("signature", "invalid role", sig.role())
        }
    }

    if ((SIGROLE_ERROR != role) && (role != sig.role())) {
        FAIL3("signature", "incorrect role", sig.role(), " specified ", role)
    }

    if (proto::SIGROLE_NYMIDSOURCE != sig.role()) {

        if (!sig.has_credentialid()) {
            FAIL("signature", " missing credential identifier")
        }

        if (MIN_PLAUSIBLE_IDENTIFIER > sig.credentialid().size()) {
            FAIL2("signature", "invalid credential id", sig.credentialid())
        }
    }

    if (!sig.has_hashtype()) {
        FAIL("signature", "missing hashtype")
    }

    if (sig.hashtype() > proto::HASHTYPE_BLAKE2B512) {
        FAIL2("signature", "invalid hash type", sig.hashtype())
    }

    if (!sig.has_signature()) {
        FAIL("signature", "missing signature")
    }

    if (MIN_PLAUSIBLE_SIGNATURE > sig.signature().size()) {
        FAIL("signature", "invalid signature")
    }

    if ((SIGROLE_PUBCREDENTIAL == sig.role()) &&
        (selfID == sig.credentialid())) {
        selfPublic += 1;
    }

    if ((SIGROLE_PUBCREDENTIAL == sig.role()) &&
        (masterID == sig.credentialid())) {
        masterPublic += 1;
    }

    if ((SIGROLE_PRIVCREDENTIAL == sig.role()) &&
        (selfID == sig.credentialid())) {
        selfPrivate += 1;
    }

    if (SIGROLE_NYMIDSOURCE == sig.role()) {
        sourcePublic += 1;
    }

    return true;
}

bool CheckProto_2(
    const Signature& sig,
    const bool silent,
    const SignatureRole role)
{
    std::uint32_t unused = 0;

    return CheckProto_2(
        sig, silent, "", "", unused, unused, unused, unused, role);
}

bool CheckProto_3(
    const Signature&,
    const bool,
    const std::string&,
    const std::string&,
    std::uint32_t&,
    std::uint32_t&,
    std::uint32_t&,
    std::uint32_t&,
    const SignatureRole)
{
    return false;
}

bool CheckProto_3(
    const Signature& sig,
    const bool silent,
    const SignatureRole role)
{
    std::uint32_t unused = 0;

    return CheckProto_3(
        sig, silent, "", "", unused, unused, unused, unused, role);
}

bool CheckProto_4(
    const Signature&,
    const bool,
    const std::string&,
    const std::string&,
    std::uint32_t&,
    std::uint32_t&,
    std::uint32_t&,
    std::uint32_t&,
    const SignatureRole)
{
    return false;
}

bool CheckProto_4(
    const Signature& sig,
    const bool silent,
    const SignatureRole role)
{
    std::uint32_t unused = 0;

    return CheckProto_4(
        sig, silent, "", "", unused, unused, unused, unused, role);
}

bool CheckProto_5(
    const Signature&,
    const bool,
    const std::string&,
    const std::string&,
    std::uint32_t&,
    std::uint32_t&,
    std::uint32_t&,
    std::uint32_t&,
    const SignatureRole)
{
    return false;
}

bool CheckProto_5(
    const Signature& sig,
    const bool silent,
    const SignatureRole role)
{
    std::uint32_t unused = 0;

    return CheckProto_5(
        sig, silent, "", "", unused, unused, unused, unused, role);
}
}  // namespace proto
}  // namespace opentxs
