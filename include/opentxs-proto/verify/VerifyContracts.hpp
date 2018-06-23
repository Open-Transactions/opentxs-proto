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

#include "opentxs-proto/Basic.hpp"

namespace opentxs
{
namespace proto
{
static const VersionMap ServerContractAllowedCredentialIndex = {
    {1, {1, 5}},
};
static const VersionMap ServerContractAllowedListenAddress = {
    {1, {1, 1}},
};
static const VersionMap ServerContractAllowedSignature = {
    {1, {1, 1}},
};
static const VersionMap UnitDefinitionAllowedCredentialIndex = {
    {1, {1, 5}},
};
static const VersionMap UnitDefinitionAllowedCurrencyParams = {
    {1, {1, 1}},
};
static const VersionMap UnitDefinitionAllowedBasketParams = {
    {1, {1, 1}},
};
static const VersionMap UnitDefinitionAllowedSecurityParams = {
    {1, {1, 1}},
};
static const VersionMap UnitDefinitionAllowedSignature = {
    {1, {1, 1}},
};
static const VersionMap BasketParamsAllowedBasketItem = {
    {1, {1, 1}},
};
static const VersionMap IssuerAllowedUnitAccountMap = {
    {1, {1, 1}},
};
static const VersionMap IssuerAllowedPeerRequestHistory = {
    {1, {1, 1}},
};
static const VersionMap PeerRequestHistoryAllowedPeerRequestWorkflow = {
    {1, {1, 1}},
};
}  // namespace proto
}  // namespace opentxs
#endif  // OPENTXS_PROTO_VERIFYCONTRACTS_HPP
