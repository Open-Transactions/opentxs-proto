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
    const Verification& verification,
    const bool silent,
    const VerificationType indexed)
{
    if (indexed) {
        if (!verification.has_id()) {
            FAIL("verification", "missing ID")
        }

        if (MIN_PLAUSIBLE_IDENTIFIER > verification.id().size()) {
            FAIL("verification", "invalid ID")
        }
    } else {
        if (verification.has_id()) {
            FAIL("verification", "ID field not empty")
        }
    }

    if (!verification.has_claim()) {
        FAIL("verification", "missing claim")
    }

    if (MIN_PLAUSIBLE_IDENTIFIER > verification.claim().size()) {
        FAIL("verification", "invalid claim")
    }

    if (!verification.has_valid()) {
        FAIL("verification", "missing validity")
    }

    if (!verification.has_start()) {
        FAIL("verification", "missing start time")
    }

    if (!verification.has_end()) {
        FAIL("verification", "missing end time")
    }

    if (verification.end() < verification.start()) {
        FAIL("verification", "invalid end time")
    }

    if (!verification.has_sig()) {
        FAIL("verification", "missing signature")
    }

    bool validSignature = Check(
        verification.sig(),
        VerificationAllowedSignature.at(verification.version()).first,
        VerificationAllowedSignature.at(verification.version()).second,
        silent,
        proto::SIGROLE_CLAIM);

    if (!validSignature) {
        FAIL("verification", "invalid signature")
    }

    return true;
}
bool CheckProto_2(const Verification&, const bool, const VerificationType)
{
    return false;
}
bool CheckProto_3(const Verification&, const bool, const VerificationType)
{
    return false;
}
bool CheckProto_4(const Verification&, const bool, const VerificationType)
{
    return false;
}
bool CheckProto_5(const Verification&, const bool, const VerificationType)
{
    return false;
}
}  // namespace proto
}  // namespace opentxs
