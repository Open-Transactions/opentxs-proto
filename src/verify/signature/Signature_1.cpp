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

#include "opentxs-proto/verify/Signature.hpp"

#include <iostream>

namespace opentxs { namespace proto
{

bool CheckProto_1(
    const Signature& serializedSignature,
    const std::string& selfID,
    const std::string& masterID,
    uint32_t& selfPublic,
    uint32_t& selfPrivate,
    uint32_t& masterPublic,
    uint32_t& sourcePublic,
    const SignatureRole role)
{
    if (!serializedSignature.has_role()) {
        std::cerr << "Verify serialized signature failed: missing role." << std::endl;
        return false;
    }

    if (serializedSignature.role() > proto::SIGROLE_PEERREPLY) {
        std::cerr << "Verify serialized signature failed: invalid role ("
        << serializedSignature.role() << ")." << std::endl;
        return false;
    }

    bool roleSpecified = (proto::SIGROLE_ERROR != role);

    if (roleSpecified && (role != serializedSignature.role())) {
        std::cerr << "Verify serialized signature failed: incorrect role ("
                  << serializedSignature.role() << "). Specified: (" << role
                  << ")" <<  std::endl;
        return false;
    }

    if (proto::SIGROLE_NYMIDSOURCE != serializedSignature.role()) {

        if (!serializedSignature.has_credentialid()) {
            std::cerr << "Verify serialized signature failed: missing credential identifier." << std::endl;
            return false;
        }

        if (MIN_PLAUSIBLE_IDENTIFIER > serializedSignature.credentialid().size()) {
            std::cerr << "Verify serialized signature failed: invalid credential identifier ("
                << serializedSignature.credentialid() << ")." << std::endl;
            return false;
        }
    }

    if (!serializedSignature.has_hashtype()) {
        std::cerr << "Verify serialized signature failed: missing hashtype." << std::endl;
        return false;
    }

    if (serializedSignature.hashtype() > proto::HASHTYPE_BLAKE2B512) {
        std::cerr << "Verify serialized signature failed: invalid hash type ("
                  << serializedSignature.hashtype() << ")." << std::endl;
        return false;
    }

    if (!serializedSignature.has_signature()) {
        std::cerr << "Verify serialized signature failed: missing signature." << std::endl;
        return false;
    }

    if (MIN_PLAUSIBLE_SIGNATURE > serializedSignature.signature().size()) {
        std::cerr << "Verify serialized signature failed: invalid signature." << std::endl;
        return false;
    }

    if ((SIGROLE_PUBCREDENTIAL == serializedSignature.role()) && (selfID == serializedSignature.credentialid())) {
        selfPublic += 1;
    }

    if ((SIGROLE_PUBCREDENTIAL == serializedSignature.role()) && (masterID == serializedSignature.credentialid())) {
        masterPublic += 1;
    }

    if ((SIGROLE_PRIVCREDENTIAL == serializedSignature.role()) && (selfID == serializedSignature.credentialid())) {
        selfPrivate += 1;
    }

    if (SIGROLE_NYMIDSOURCE == serializedSignature.role()) {
        sourcePublic += 1;
    }

    return true;
}

bool CheckProto_1(
    const Signature& serializedSignature,
    const SignatureRole role)
{
    uint32_t unused = 0;

    return CheckProto_1(
        serializedSignature,
        "",
        "",
        unused,
        unused,
        unused,
        unused,
        role);
}
bool CheckProto_2(
    const Signature&,
    const std::string&,
    const std::string&,
    uint32_t&,
    uint32_t&,
    uint32_t&,
    uint32_t&,
    const SignatureRole)
{
    return false;
}
bool CheckProto_2(
    const Signature&,
    const SignatureRole)
{
    return false;
}
} // namespace proto
} // namespace opentxs
