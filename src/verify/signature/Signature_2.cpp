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

#include <iostream>

namespace opentxs { namespace proto
{
bool CheckProto_2(
    const Signature& sig,
    const std::string& selfID,
    const std::string& masterID,
    std::uint32_t& selfPublic,
    std::uint32_t& selfPrivate,
    std::uint32_t& masterPublic,
    std::uint32_t& sourcePublic,
    const SignatureRole role)
{
    if (!sig.has_role()) {
        std::cerr << "Verify serialized signature failed: missing role."
                  << std::endl;

        return false;
    }

    switch (sig.role()) {
        case SIGROLE_PUBCREDENTIAL :
        case SIGROLE_PRIVCREDENTIAL :
        case SIGROLE_NYMIDSOURCE :
        case SIGROLE_CLAIM :
        case SIGROLE_SERVERCONTRACT :
        case SIGROLE_UNITDEFINITION :
        case SIGROLE_PEERREQUEST :
        case SIGROLE_PEERREPLY :
        case SIGROLE_CONTEXT :
        case SIGROLE_ACCOUNT : { break; }
        default : {
            std::cerr << "Verify serialized signature failed: invalid role ("
                    << sig.role() << ")." << std::endl;

            return false;
        }
    }

    if ((SIGROLE_ERROR != role) && (role != sig.role())) {
        std::cerr << "Verify serialized signature failed: incorrect role ("
                  << sig.role() << "). Specified: (" << role
                  << ")" <<  std::endl;

        return false;
    }

    if (proto::SIGROLE_NYMIDSOURCE != sig.role()) {

        if (!sig.has_credentialid()) {
            std::cerr << "Verify serialized signature failed: missing "
                      << "credential identifier." << std::endl;

            return false;
        }

        if (MIN_PLAUSIBLE_IDENTIFIER > sig.credentialid().size()) {
            std::cerr << "Verify serialized signature failed: invalid "
                      << "identifier (" << sig.credentialid() << ")."
                      << std::endl;

            return false;
        }
    }

    if (!sig.has_hashtype()) {
        std::cerr << "Verify serialized signature failed: missing hashtype."
                  << std::endl;

        return false;
    }

    if (sig.hashtype() > proto::HASHTYPE_BLAKE2B512) {
        std::cerr << "Verify serialized signature failed: invalid hash type ("
                  << sig.hashtype() << ")." << std::endl;

        return false;
    }

    if (!sig.has_signature()) {
        std::cerr << "Verify serialized signature failed: missing signature."
                  << std::endl;

        return false;
    }

    if (MIN_PLAUSIBLE_SIGNATURE > sig.signature().size()) {
        std::cerr << "Verify serialized signature failed: invalid signature."
                  << std::endl;

        return false;
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
    const SignatureRole role)
{
    std::uint32_t unused = 0;

    return CheckProto_2(
        sig,
        "",
        "",
        unused,
        unused,
        unused,
        unused,
        role);
}

bool CheckProto_3(
    const Signature&,
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
    const SignatureRole role)
{
    std::uint32_t unused = 0;

    return CheckProto_3(
        sig,
        "",
        "",
        unused,
        unused,
        unused,
        unused,
        role);
}

bool CheckProto_4(
    const Signature&,
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
    const SignatureRole role)
{
    std::uint32_t unused = 0;

    return CheckProto_4(
        sig,
        "",
        "",
        unused,
        unused,
        unused,
        unused,
        role);
}

bool CheckProto_5(
    const Signature&,
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
    const SignatureRole role)
{
    std::uint32_t unused = 0;

    return CheckProto_5(
        sig,
        "",
        "",
        unused,
        unused,
        unused,
        unused,
        role);
}
} // namespace proto
} // namespace opentxs
