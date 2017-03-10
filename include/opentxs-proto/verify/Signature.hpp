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

#ifndef OPENTXS_PROTO_SIGNATURE_HPP
#define OPENTXS_PROTO_SIGNATURE_HPP

#include "VerifyCredentials.hpp"

namespace opentxs { namespace proto
{
    bool CheckProto_1(
        const Signature& serializedSignature,
        const std::string& selfID,
        const std::string& masterID,
        std::uint32_t& selfPublic,
        std::uint32_t& selfPrivate,
        std::uint32_t& masterPublic,
        std::uint32_t& sourcePublic,
        const SignatureRole role = SIGROLE_ERROR);
    bool CheckProto_1(
        const Signature& serializedSignature,
        const SignatureRole role = SIGROLE_ERROR);
    bool CheckProto_2(
        const Signature& serializedSignature,
        const std::string& selfID,
        const std::string& masterID,
        std::uint32_t& selfPublic,
        std::uint32_t& selfPrivate,
        std::uint32_t& masterPublic,
        std::uint32_t& sourcePublic,
        const SignatureRole role = SIGROLE_ERROR);
    bool CheckProto_2(
        const Signature& serializedSignature,
        const SignatureRole role = SIGROLE_ERROR);
    bool CheckProto_3(
        const Signature&,
        const std::string&,
        const std::string&,
        std::uint32_t&,
        std::uint32_t&,
        std::uint32_t&,
        std::uint32_t&,
        const SignatureRole role = SIGROLE_ERROR);
    bool CheckProto_3(
        const Signature&,
        const SignatureRole role = SIGROLE_ERROR);
    bool CheckProto_4(
        const Signature&,
        const std::string&,
        const std::string&,
        std::uint32_t&,
        std::uint32_t&,
        std::uint32_t&,
        std::uint32_t&,
        const SignatureRole role = SIGROLE_ERROR);
    bool CheckProto_4(
        const Signature&,
        const SignatureRole role = SIGROLE_ERROR);
    bool CheckProto_5(
        const Signature&,
        const std::string&,
        const std::string&,
        std::uint32_t&,
        std::uint32_t&,
        std::uint32_t&,
        std::uint32_t&,
        const SignatureRole role = SIGROLE_ERROR);
    bool CheckProto_5(
        const Signature&,
        const SignatureRole role = SIGROLE_ERROR);
} // namespace proto
} // namespace opentxs

#endif // OPENTXS_PROTO_SIGNATURE_HPP
