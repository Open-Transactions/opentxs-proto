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

#ifndef OPENTXS_PROTO_VERIFYCONTRACTS_HPP
#define OPENTXS_PROTO_VERIFYCONTRACTS_HPP

#ifdef _WIN32
#pragma warning(push)
#pragma warning(disable : 4244)
#pragma warning(disable : 4267)
#else
#pragma GCC diagnostic push
#pragma GCC diagnostic ignored "-Wshadow"
#ifndef __clang__
// -Wuseless-cast does not exist in clang
#pragma GCC diagnostic ignored "-Wuseless-cast"
#endif
#endif
#include "opentxs-proto/ServerContract.pb.h"
#include "opentxs-proto/UnitDefinition.pb.h"
#ifdef _WIN32
#pragma warning(pop)
#else
#pragma GCC diagnostic pop
#endif

#include "opentxs-proto/Verify.hpp"
#include "opentxs-proto/verify/ListenAddress.hpp"
#include "opentxs-proto/verify/VerifyCredentials.hpp"
#include "opentxs-proto/verify/ServerContract.hpp"

namespace opentxs { namespace proto
{
    static const VersionMap ServerContractAllowedCredentialIndex =
        {
            { 1, {1, 1}},
        };
    static const VersionMap ServerContractAllowedListenAddress =
        {
            { 1, {1, 1}},
        };
    static const VersionMap ServerContractAllowedSignatures =
        {
            { 1, {1, 1}},
        };
} // namespace proto
} // namespace opentxs
#endif // OPENTXS_PROTO_VERIFYCONTRACTS_HPP
