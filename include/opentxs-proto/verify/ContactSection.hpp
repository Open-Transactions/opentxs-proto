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

#ifndef OPENTXS_PROTO_CONTACTSECTION_HPP
#define OPENTXS_PROTO_CONTACTSECTION_HPP

#include "VerifyContacts.hpp"

namespace opentxs
{
namespace proto
{
bool CheckProto_1(
    const ContactSection& contactSection,
    const bool silent,
    const ClaimType indexed,
    const uint32_t parentVersion = 0xffffffff);
bool CheckProto_2(
    const ContactSection& contactSection,
    const bool silent,
    const ClaimType indexed,
    const uint32_t parentVersion = 0xffffffff);
bool CheckProto_3(
    const ContactSection& contactSection,
    const bool silent,
    const ClaimType indexed,
    const uint32_t parentVersion = 0xffffffff);
bool CheckProto_4(
    const ContactSection& contactSection,
    const bool silent,
    const ClaimType indexed,
    const uint32_t parentVersion = 0xffffffff);
bool CheckProto_5(
    const ContactSection&,
    const bool,
    const ClaimType,
    const uint32_t parentVersion = 0xffffffff);
}  // namespace proto
}  // namespace opentxs

#endif  // OPENTXS_PROTO_CONTACTSECTION_HPP
