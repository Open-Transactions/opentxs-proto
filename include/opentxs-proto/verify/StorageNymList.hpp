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

#ifndef OPENTXS_PROTO_STORAGENYMLIST_HPP
#define OPENTXS_PROTO_STORAGENYMLIST_HPP

#include "VerifyStorage.hpp"

namespace opentxs
{
namespace proto
{
bool CheckProto_1(const StorageNymList& creds, const bool silent);
bool CheckProto_2(const StorageNymList&, const bool);
bool CheckProto_3(const StorageNymList&, const bool);
bool CheckProto_4(const StorageNymList&, const bool);
bool CheckProto_5(const StorageNymList&, const bool);
}  // namespace proto
}  // namespace opentxs

#endif  // OPENTXS_PROTO_STORAGENYMLIST_HPP
