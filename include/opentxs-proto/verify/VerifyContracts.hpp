// Copyright (c) 2019 The Open-Transactions developers
// This Source Code Form is subject to the terms of the Mozilla Public
// License, v. 2.0. If a copy of the MPL was not distributed with this
// file, You can obtain one at http://mozilla.org/MPL/2.0/.

#ifndef OPENTXS_PROTO_VERIFYCONTRACTS_HPP
#define OPENTXS_PROTO_VERIFYCONTRACTS_HPP

#include "opentxs-proto/Basic.hpp"

namespace opentxs
{
namespace proto
{
static const VersionMap ServerContractAllowedNym = {
    {1, {1, 5}},
    {2, {1, 6}},
};
static const VersionMap ServerContractAllowedListenAddress = {
    {1, {1, 1}},
    {2, {1, 2}},
};
static const VersionMap ServerContractAllowedSignature = {
    {1, {1, 1}},
    {2, {1, 1}},
};
static const VersionMap UnitDefinitionAllowedNym = {
    {1, {1, 6}},
    {2, {1, 6}},
};
static const VersionMap UnitDefinitionAllowedCurrencyParams = {
    {1, {1, 1}},
    {2, {1, 1}},
};
static const VersionMap UnitDefinitionAllowedBasketParams = {
    {1, {1, 1}},
    {2, {1, 1}},
};
static const VersionMap UnitDefinitionAllowedSecurityParams = {
    {1, {1, 1}},
    {2, {1, 1}},
};
static const VersionMap UnitDefinitionAllowedSignature = {
    {1, {1, 1}},
    {2, {1, 1}},
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
