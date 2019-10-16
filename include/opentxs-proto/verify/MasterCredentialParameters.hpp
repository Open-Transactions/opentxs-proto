// Copyright (c) 2019 The Open-Transactions developers
// This Source Code Form is subject to the terms of the Mozilla Public
// License, v. 2.0. If a copy of the MPL was not distributed with this
// file, You can obtain one at http://mozilla.org/MPL/2.0/.

#ifndef OPENTXS_PROTO_MASTERCREDENTIALPARAMETERS_HPP
#define OPENTXS_PROTO_MASTERCREDENTIALPARAMETERS_HPP

#include "VerifyCredentials.hpp"

namespace opentxs
{
namespace proto
{
EXPORT bool CheckProto_1(
    const MasterCredentialParameters& master,
    const bool silent,
    bool& expectSourceSignature);
EXPORT bool CheckProto_2(const MasterCredentialParameters&, const bool, bool&);
EXPORT bool CheckProto_3(const MasterCredentialParameters&, const bool, bool&);
EXPORT bool CheckProto_4(const MasterCredentialParameters&, const bool, bool&);
EXPORT bool CheckProto_5(const MasterCredentialParameters&, const bool, bool&);
EXPORT bool CheckProto_6(const MasterCredentialParameters&, const bool, bool&);
EXPORT bool CheckProto_7(const MasterCredentialParameters&, const bool, bool&);
EXPORT bool CheckProto_8(const MasterCredentialParameters&, const bool, bool&);
EXPORT bool CheckProto_9(const MasterCredentialParameters&, const bool, bool&);
EXPORT bool CheckProto_10(const MasterCredentialParameters&, const bool, bool&);
EXPORT bool CheckProto_11(const MasterCredentialParameters&, const bool, bool&);
EXPORT bool CheckProto_12(const MasterCredentialParameters&, const bool, bool&);
EXPORT bool CheckProto_13(const MasterCredentialParameters&, const bool, bool&);
EXPORT bool CheckProto_14(const MasterCredentialParameters&, const bool, bool&);
EXPORT bool CheckProto_15(const MasterCredentialParameters&, const bool, bool&);
EXPORT bool CheckProto_16(const MasterCredentialParameters&, const bool, bool&);
EXPORT bool CheckProto_17(const MasterCredentialParameters&, const bool, bool&);
EXPORT bool CheckProto_18(const MasterCredentialParameters&, const bool, bool&);
EXPORT bool CheckProto_19(const MasterCredentialParameters&, const bool, bool&);
EXPORT bool CheckProto_20(const MasterCredentialParameters&, const bool, bool&);
}  // namespace proto
}  // namespace opentxs

#endif  // OPENTXS_PROTO_MASTERCREDENTIALPARAMETERS_HPP
