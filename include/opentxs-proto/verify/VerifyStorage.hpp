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

#ifdef OPENTXS_PROTO_INTERNAL_BUILD
#include "StorageRoot.pb.h"
#include "StorageItems.pb.h"
#include "StorageNymList.pb.h"
#include "StorageNym.pb.h"
#include "StorageServers.pb.h"
#include "StorageCredentials.pb.h"
#include "VerifyCredentials.hpp"
#else
#include <opentxs-proto/StorageRoot.pb.h>
#include <opentxs-proto/StorageItems.pb.h>
#include <opentxs-proto/StorageNymList.pb.h>
#include <opentxs-proto/StorageNym.pb.h>
#include <opentxs-proto/StorageServers.pb.h>
#include <opentxs-proto/StorageCredentials.pb.h>
#include <opentxs-proto/verify/VerifyCredentials.hpp>
#endif

#ifdef _WIN32
#pragma warning(pop)
#else
#pragma GCC diagnostic pop
#endif

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

    bool Verify(
        const StorageRoot& root,
        const uint32_t minVersion = 0,
        const uint32_t maxVersion = 0xffffffff);
    bool Verify(
        const StorageItems& items,
        const uint32_t minVersion = 0,
        const uint32_t maxVersion = 0xffffffff);
    bool Verify(
        const StorageCredentials& creds,
        const uint32_t minVersion = 0,
        const uint32_t maxVersion = 0xffffffff);
    bool Verify(
        const StorageNymList& nymList,
        const uint32_t minVersion = 0,
        const uint32_t maxVersion = 0xffffffff);
    bool Verify(
        const StorageNym& nym,
        const uint32_t minVersion = 0,
        const uint32_t maxVersion = 0xffffffff);
    bool Verify(
        const StorageServers& servers,
        const uint32_t minVersion = 0,
        const uint32_t maxVersion = 0xffffffff);
    bool Verify(
        const StorageItemHash& hash,
        const uint32_t minVersion = 0,
        const uint32_t maxVersion = 0xffffffff);

} // namespace proto
} // namespace opentxs
#endif // OPENTXS_PROTO_VERIFYSTORAGE_HPP
