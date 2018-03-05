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

#define PROTO_NAME "verification offer"

namespace opentxs
{
namespace proto
{
bool CheckProto_1(const VerificationOffer& input, const bool silent)
{
    UNDEFINED_VERSION("verification offer", 1)
}

bool CheckProto_2(const VerificationOffer& input, const bool silent)
{
    UNDEFINED_VERSION("verification offer", 2)
}

bool CheckProto_3(const VerificationOffer& input, const bool silent)
{
    if (!input.has_offeringnym()) {
        FAIL("verification offer", "missing sender nym id")
    }

    if (MIN_PLAUSIBLE_IDENTIFIER > input.offeringnym().size()) {
        FAIL("verification offer", "invalid sender nym id")
    }

    if (MAX_PLAUSIBLE_IDENTIFIER < input.offeringnym().size()) {
        FAIL("verification offer", "invalid sender nym id")
    }

    if (!input.has_recipientnym()) {
        FAIL("verification offer", "missing recipient nym id")
    }

    if (MIN_PLAUSIBLE_IDENTIFIER > input.recipientnym().size()) {
        FAIL("verification offer", "invalid recipient nym id")
    }

    if (MAX_PLAUSIBLE_IDENTIFIER < input.recipientnym().size()) {
        FAIL("verification offer", "invalid recipient nym id")
    }

    try {
        const bool validClaim = Check(
            input.claim(),
            VerificationOfferAllowedClaim.at(input.version()).first,
            VerificationOfferAllowedClaim.at(input.version()).second,
            silent);

        if (!validClaim) {
            FAIL("verification offer", "invalid claim")
        }
    } catch (const std::out_of_range&) {
        FAIL2(
            "verification offer",
            "allowed claim version not defined for version",
            input.version())
    }

    if (input.claim().nymid() != input.recipientnym()) {
        FAIL("verification offer", "claim nym does not match recipient nym")
    }

    try {
        const bool validVerification = Check(
            input.verification(),
            VerificationOfferAllowedVerification.at(input.version()).first,
            VerificationOfferAllowedVerification.at(input.version()).second,
            silent,
            VERIFICATIONS_NORMAL);

        if (!validVerification) {
            FAIL("verification offer", "invalid verification")
        }
    } catch (const std::out_of_range&) {
        FAIL2(
            "verification offer",
            "allowed verification version not defined for version",
            input.version())
    }

    return true;
}

bool CheckProto_4(const VerificationOffer& input, const bool silent)
{
    return CheckProto_3(input, silent);
}

bool CheckProto_5(const VerificationOffer& input, const bool silent)
{
    UNDEFINED_VERSION("verification offer", 5)
}

bool CheckProto_6(const VerificationOffer& input, const bool silent)
{
    UNDEFINED_VERSION2(6)
}

bool CheckProto_7(const VerificationOffer& input, const bool silent)
{
    UNDEFINED_VERSION2(7)
}

bool CheckProto_8(const VerificationOffer& input, const bool silent)
{
    UNDEFINED_VERSION2(8)
}

bool CheckProto_9(const VerificationOffer& input, const bool silent)
{
    UNDEFINED_VERSION2(9)
}

bool CheckProto_10(const VerificationOffer& input, const bool silent)
{
    UNDEFINED_VERSION2(10)
}

bool CheckProto_11(const VerificationOffer& input, const bool silent)
{
    UNDEFINED_VERSION2(11)
}

bool CheckProto_12(const VerificationOffer& input, const bool silent)
{
    UNDEFINED_VERSION2(12)
}

bool CheckProto_13(const VerificationOffer& input, const bool silent)
{
    UNDEFINED_VERSION2(13)
}

bool CheckProto_14(const VerificationOffer& input, const bool silent)
{
    UNDEFINED_VERSION2(14)
}

bool CheckProto_15(const VerificationOffer& input, const bool silent)
{
    UNDEFINED_VERSION2(15)
}

bool CheckProto_16(const VerificationOffer& input, const bool silent)
{
    UNDEFINED_VERSION2(16)
}

bool CheckProto_17(const VerificationOffer& input, const bool silent)
{
    UNDEFINED_VERSION2(17)
}

bool CheckProto_18(const VerificationOffer& input, const bool silent)
{
    UNDEFINED_VERSION2(18)
}

bool CheckProto_19(const VerificationOffer& input, const bool silent)
{
    UNDEFINED_VERSION2(19)
}

bool CheckProto_20(const VerificationOffer& input, const bool silent)
{
    UNDEFINED_VERSION2(20)
}
}  // namespace proto
}  // namespace opentxs
