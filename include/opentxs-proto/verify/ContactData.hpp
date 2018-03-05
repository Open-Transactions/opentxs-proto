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
