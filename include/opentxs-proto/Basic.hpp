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

#ifndef OPENTXS_PROTO_BASIC_HPP
#define OPENTXS_PROTO_BASIC_HPP

#include <cstdint>
#include <map>
#include <tuple>

namespace opentxs
{
namespace proto
{
// This defined a map between the version of the parent object
// and the (minimum, maximum) acceptable versions of a child object.
typedef std::map<std::uint32_t, std::pair<std::uint32_t, std::uint32_t>>
    VersionMap;

static const std::uint32_t MIN_PLAUSIBLE_IDENTIFIER = 20;
static const std::uint32_t MAX_PLAUSIBLE_IDENTIFIER = 80;
static const std::uint32_t MIN_PLAUSIBLE_KEYSIZE = 16;
static const std::uint32_t MIN_PLAUSIBLE_SIGNATURE = 32;
static const std::uint32_t MAX_VALID_PORT = 65535;
}  // namespace proto
}  // namespace opentxs

#endif  // OPENTXS_PROTO_BASIC_HPP
