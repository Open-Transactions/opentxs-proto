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
bool CheckProto_1(const VerificationOffer&, const bool) { return false; }
bool CheckProto_2(const VerificationOffer&, const bool) { return false; }

bool CheckProto_3(const VerificationOffer& offer, const bool silent)
{
    if (!offer.has_offeringnym()) {
        FAIL("verification offer", "missing sender nym id")
    }

    if (MIN_PLAUSIBLE_IDENTIFIER > offer.offeringnym().size()) {
        FAIL("verification offer", "invalid sender nym id")
    }

    if (MAX_PLAUSIBLE_IDENTIFIER < offer.offeringnym().size()) {
        FAIL("verification offer", "invalid sender nym id")
    }

    if (!offer.has_recipientnym()) {
        FAIL("verification offer", "missing recipient nym id")
    }

    if (MIN_PLAUSIBLE_IDENTIFIER > offer.recipientnym().size()) {
        FAIL("verification offer", "invalid recipient nym id")
    }

    if (MAX_PLAUSIBLE_IDENTIFIER < offer.recipientnym().size()) {
        FAIL("verification offer", "invalid recipient nym id")
    }

    try {
        const bool validClaim = Check(
            offer.claim(),
            VerificationOfferAllowedClaim.at(offer.version()).first,
            VerificationOfferAllowedClaim.at(offer.version()).second,
            silent);

        if (!validClaim) {
            FAIL("verification offer", "invalid claim")
        }
    } catch (const std::out_of_range&) {
        FAIL2(
            "verification offer",
            "allowed claim version not defined for version",
            offer.version())
    }

    if (offer.claim().nymid() != offer.recipientnym()) {
        FAIL("verification offer", "claim nym does not match recipient nym")
    }

    try {
        const bool validVerification = Check(
            offer.verification(),
            VerificationOfferAllowedVerification.at(offer.version()).first,
            VerificationOfferAllowedVerification.at(offer.version()).second,
            silent,
            VERIFICATIONS_NORMAL);

        if (!validVerification) {
            FAIL("verification offer", "invalid verification")
        }
    } catch (const std::out_of_range&) {
        FAIL2(
            "verification offer",
            "allowed verification version not defined for version",
            offer.version())
    }

    return true;
}

bool CheckProto_4(const VerificationOffer& offer, const bool silent)
{
    return CheckProto_3(offer, silent);
}

bool CheckProto_5(const VerificationOffer&, const bool) { return false; }
}  // namespace proto
}  // namespace opentxs
