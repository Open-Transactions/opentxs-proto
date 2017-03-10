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

#ifndef OPENTXS_PROTO_VERIFICATIONIDENTITY_HPP
#define OPENTXS_PROTO_VERIFICATIONIDENTITY_HPP

#include <map>

#include "VerifyContacts.hpp"

namespace opentxs { namespace proto
{
    typedef std::map<std::string, uint64_t> VerificationNymMap;

    bool CheckProto_1(
        const VerificationIdentity& verificationIdentity,
        VerificationNymMap& map,
        const VerificationType indexed);
    bool CheckProto_2(
        const VerificationIdentity&,
        VerificationNymMap&,
        const VerificationType);
    bool CheckProto_3(
        const VerificationIdentity&,
        VerificationNymMap&,
        const VerificationType);
    bool CheckProto_4(
        const VerificationIdentity&,
        VerificationNymMap&,
        const VerificationType);
    bool CheckProto_5(
        const VerificationIdentity&,
        VerificationNymMap&,
        const VerificationType);
} // namespace proto
} // namespace opentxs

#endif // OPENTXS_PROTO_VERIFICATIONIDENTITY_HPP
