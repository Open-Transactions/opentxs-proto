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

#include "opentxs-proto/Basic.hpp"

namespace opentxs { namespace proto
{
    class StorageCredentials;
    class StorageItemHash;
    class StorageItems;
    class StorageNym;
    class StorageNymList;
    class StorageRoot;
    class StorageSeeds;
    class StorageServers;
    class StorageThread;
    class StorageThreadItem;
    class StorageUnits;

    static const VersionMap StorageCredentialAllowedHash =
        {
            { 1, {1, 1}},
            { 2, {1, 2}},
        };
    static const VersionMap StorageNymListAllowedHash =
        {
            { 1, {1, 1}},
            { 2, {1, 2}},
        };
    static const VersionMap StorageNymAllowedHash =
        {
            { 1, {1, 1}},
            { 2, {1, 2}},
            { 3, {2, 3}},
        };
    static const VersionMap StorageServersAllowedHash =
        {
            { 1, {1, 1}},
            { 2, {1, 2}},
        };
    static const VersionMap StorageThreadAllowedItem =
        {
            { 1, {1, 1}},
        };
    static const VersionMap StorageUnitsAllowedHash =
        {
            { 1, {1, 1}},
            { 2, {1, 2}},
        };
    static const VersionMap StorageSeedsAllowedHash =
        {
            { 1, {1, 1}},
            { 2, {1, 2}},
        };
} // namespace proto
} // namespace opentxs
#endif // OPENTXS_PROTO_VERIFYSTORAGE_HPP
