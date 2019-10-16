// Copyright (c) 2019 The Open-Transactions developers
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
EXPORT bool CheckProto_1(
    const ContactData& contactData,
    const bool silent,
    const ClaimType indexed);
EXPORT bool CheckProto_2(
    const ContactData& contactData,
    const bool silent,
    const ClaimType indexed);
EXPORT bool CheckProto_3(
    const ContactData& contactData,
    const bool silent,
    const ClaimType indexed);
EXPORT bool CheckProto_4(
    const ContactData& contactData,
    const bool silent,
    const ClaimType indexed);
EXPORT bool CheckProto_5(const ContactData&, const bool, const ClaimType);
EXPORT bool CheckProto_6(const ContactData&, const bool, const ClaimType);
EXPORT bool CheckProto_7(const ContactData&, const bool, const ClaimType);
EXPORT bool CheckProto_8(const ContactData&, const bool, const ClaimType);
EXPORT bool CheckProto_9(const ContactData&, const bool, const ClaimType);
EXPORT bool CheckProto_10(const ContactData&, const bool, const ClaimType);
EXPORT bool CheckProto_11(const ContactData&, const bool, const ClaimType);
EXPORT bool CheckProto_12(const ContactData&, const bool, const ClaimType);
EXPORT bool CheckProto_13(const ContactData&, const bool, const ClaimType);
EXPORT bool CheckProto_14(const ContactData&, const bool, const ClaimType);
EXPORT bool CheckProto_15(const ContactData&, const bool, const ClaimType);
EXPORT bool CheckProto_16(const ContactData&, const bool, const ClaimType);
EXPORT bool CheckProto_17(const ContactData&, const bool, const ClaimType);
EXPORT bool CheckProto_18(const ContactData&, const bool, const ClaimType);
EXPORT bool CheckProto_19(const ContactData&, const bool, const ClaimType);
EXPORT bool CheckProto_20(const ContactData&, const bool, const ClaimType);
}  // namespace proto
}  // namespace opentxs

#endif  // OPENTXS_PROTO_CONTACTDATA_HPP
