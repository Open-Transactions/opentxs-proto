// Copyright (c) 2018 The Open-Transactions developers
// This Source Code Form is subject to the terms of the Mozilla Public
// License, v. 2.0. If a copy of the MPL was not distributed with this
// file, You can obtain one at http://mozilla.org/MPL/2.0/.

#ifndef OPENTXS_PROTO_CONTACTDATA_HPP
#define OPENTXS_PROTO_CONTACTDATA_HPP

#include "VerifyContacts.hpp"

namespace opentxs
{
namespace proto
{
bool CheckProto_1(
    const ContactData& contactData,
    const bool silent,
    const ClaimType indexed);
bool CheckProto_2(
    const ContactData& contactData,
    const bool silent,
    const ClaimType indexed);
bool CheckProto_3(
    const ContactData& contactData,
    const bool silent,
    const ClaimType indexed);
bool CheckProto_4(
    const ContactData& contactData,
    const bool silent,
    const ClaimType indexed);
bool CheckProto_5(const ContactData&, const bool, const ClaimType);
bool CheckProto_6(const ContactData&, const bool, const ClaimType);
bool CheckProto_7(const ContactData&, const bool, const ClaimType);
bool CheckProto_8(const ContactData&, const bool, const ClaimType);
bool CheckProto_9(const ContactData&, const bool, const ClaimType);
bool CheckProto_10(const ContactData&, const bool, const ClaimType);
bool CheckProto_11(const ContactData&, const bool, const ClaimType);
bool CheckProto_12(const ContactData&, const bool, const ClaimType);
bool CheckProto_13(const ContactData&, const bool, const ClaimType);
bool CheckProto_14(const ContactData&, const bool, const ClaimType);
bool CheckProto_15(const ContactData&, const bool, const ClaimType);
bool CheckProto_16(const ContactData&, const bool, const ClaimType);
bool CheckProto_17(const ContactData&, const bool, const ClaimType);
bool CheckProto_18(const ContactData&, const bool, const ClaimType);
bool CheckProto_19(const ContactData&, const bool, const ClaimType);
bool CheckProto_20(const ContactData&, const bool, const ClaimType);
}  // namespace proto
}  // namespace opentxs

#endif  // OPENTXS_PROTO_CONTACTDATA_HPP
