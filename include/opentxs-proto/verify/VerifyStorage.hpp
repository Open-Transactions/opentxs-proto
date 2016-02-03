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

#ifndef OPENTXS_PROTO_VERIFYSTORAGE_HPP
#define OPENTXS_PROTO_VERIFYSTORAGE_HPP

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
#include "opentxs-proto/StorageCredentials.pb.h"
#include "opentxs-proto/StorageItems.pb.h"
#include "opentxs-proto/StorageNym.pb.h"
#include "opentxs-proto/StorageNymList.pb.h"
#include "opentxs-proto/StorageRoot.pb.h"
#include "opentxs-proto/StorageServers.pb.h"
#ifdef _WIN32
#pragma warning(pop)
#else
#pragma GCC diagnostic pop
#endif

#include "opentxs-proto/Verify.hpp"
#include "opentxs-proto/verify/StorageCredentials.hpp"
#include "opentxs-proto/verify/StorageItemHash.hpp"
#include "opentxs-proto/verify/StorageItems.hpp"
#include "opentxs-proto/verify/StorageNym.hpp"
#include "opentxs-proto/verify/StorageNymList.hpp"
#include "opentxs-proto/verify/StorageRoot.hpp"
#include "opentxs-proto/verify/StorageServers.hpp"

namespace opentxs { namespace proto
{
    static const VersionMap StorageItemsAllowedCredential =
        {
            { 1, {1, 1}},
        };
    static const VersionMap StorageCredentialAllowedHash =
        {
            { 1, {1, 1}},
        };
    static const VersionMap StorageNymListAllowedHash =
        {
            { 1, {1, 1}},
        };
    static const VersionMap StorageNymAllowedHash =
        {
            { 1, {1, 1}},
        };
    static const VersionMap StorageServersAllowedHash =
        {
            { 1, {1, 1}},
        };
} // namespace proto
} // namespace opentxs
#endif // OPENTXS_PROTO_VERIFYSTORAGE_HPP
