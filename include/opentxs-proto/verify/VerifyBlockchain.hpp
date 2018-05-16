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

#ifndef OPENTXS_PROTO_VERIFYBLOCKCHAIN_HPP
#define OPENTXS_PROTO_VERIFYBLOCKCHAIN_HPP

#include "opentxs-proto/Basic.hpp"

namespace opentxs
{
namespace proto
{

class Bip44Account;
class Bip44Address;
class BlockchainInput;
class BlockchainOutput;
class BlockchainTransaction;
class StorageBlockchainAccountList;

static const VersionMap Bip44AccountAllowedBip44Address = {
    {1, {1, 1}},
};
static const VersionMap Bip44AccountAllowedHDPath = {
    {1, {1, 1}},
};
static const VersionMap BlockchainTransactionAllowedInput = {
    {1, {1, 1}},
};
static const VersionMap BlockchainTransactionAllowedOutput = {
    {1, {1, 1}},
};
static const VersionMap StorageBlockchainTransactionsAllowedHash = {
    {1, {1, 2}},
};
}  // namespace proto
}  // namespace opentxs
#endif  // OPENTXS_PROTO_VERIFYBLOCKCHAIN_HPP
