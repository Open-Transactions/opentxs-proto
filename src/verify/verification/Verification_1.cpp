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

#include "opentxs-proto/Types.hpp"
#include "opentxs-proto/Check.hpp"

#include <iostream>

namespace opentxs
{
namespace proto
{

bool CheckProto_1(
    const Verification& input,
    const bool silent,
    const VerificationType indexed)
{
    if (indexed) {
        if (!input.has_id()) {
            FAIL("verification", "missing ID")
        }

        if (MIN_PLAUSIBLE_IDENTIFIER > input.id().size()) {
            FAIL("verification", "invalid ID")
        }
    } else {
        if (input.has_id()) {
            FAIL("verification", "ID field not empty")
        }
    }

    if (!input.has_claim()) {
        FAIL("verification", "missing claim")
    }

    if (MIN_PLAUSIBLE_IDENTIFIER > input.claim().size()) {
        FAIL("verification", "invalid claim")
    }

    if (!input.has_valid()) {
        FAIL("verification", "missing validity")
    }

    if (!input.has_start()) {
        FAIL("verification", "missing start time")
    }

    if (!input.has_end()) {
        FAIL("verification", "missing end time")
    }

    if (input.end() < input.start()) {
        FAIL("verification", "invalid end time")
    }

    if (!input.has_sig()) {
        FAIL("verification", "missing signature")
    }

    try {
        const bool validSignature = Check(
            input.sig(),
            VerificationAllowedSignature.at(input.version()).first,
            VerificationAllowedSignature.at(input.version()).second,
            silent,
            proto::SIGROLE_CLAIM);

        if (!validSignature) {
            FAIL("verification", "invalid signature")
        }
    } catch (const std::out_of_range&) {
        FAIL2(
            "verification",
            "allowed signature version not defined for version",
            input.version())
    }

    return true;
}

bool CheckProto_2(
    const Verification& input,
    const bool silent,
    const VerificationType)
{
    UNDEFINED_VERSION("verification", 2)
}

bool CheckProto_3(
    const Verification& input,
    const bool silent,
    const VerificationType)
{
    UNDEFINED_VERSION("verification", 3)
}

bool CheckProto_4(
    const Verification& input,
    const bool silent,
    const VerificationType)
{
    UNDEFINED_VERSION("verification", 4)
}

bool CheckProto_5(
    const Verification& input,
    const bool silent,
    const VerificationType)
{
    UNDEFINED_VERSION("verification", 5)
}
}  // namespace proto
}  // namespace opentxs
