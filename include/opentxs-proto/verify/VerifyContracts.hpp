// Copyright (c) 2020 The Open-Transactions developers
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
OPENTXS_PROTO_EXPORT const VersionMap& BasketParamsAllowedBasketItem() noexcept;
OPENTXS_PROTO_EXPORT const VersionMap&
IssuerAllowedPeerRequestHistory() noexcept;
OPENTXS_PROTO_EXPORT const VersionMap& IssuerAllowedUnitAccountMap() noexcept;
OPENTXS_PROTO_EXPORT const VersionMap&
PeerRequestHistoryAllowedPeerRequestWorkflow() noexcept;
OPENTXS_PROTO_EXPORT const VersionMap&
ServerContractAllowedListenAddress() noexcept;
OPENTXS_PROTO_EXPORT const VersionMap& ServerContractAllowedNym() noexcept;
OPENTXS_PROTO_EXPORT const VersionMap&
ServerContractAllowedSignature() noexcept;
OPENTXS_PROTO_EXPORT const VersionMap&
UnitDefinitionAllowedBasketParams() noexcept;
OPENTXS_PROTO_EXPORT const VersionMap&
UnitDefinitionAllowedCurrencyParams() noexcept;
OPENTXS_PROTO_EXPORT const VersionMap& UnitDefinitionAllowedNym() noexcept;
OPENTXS_PROTO_EXPORT const VersionMap&
UnitDefinitionAllowedSecurityParams() noexcept;
OPENTXS_PROTO_EXPORT const VersionMap&
UnitDefinitionAllowedSignature() noexcept;
}  // namespace proto
}  // namespace opentxs
#endif  // OPENTXS_PROTO_VERIFYCONTRACTS_HPP
