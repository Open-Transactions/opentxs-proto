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

namespace opentxs { namespace proto
{

bool CheckProto_1(const VerificationOffer& offer)
{
    if (!offer.has_offeringnym()) {
        std::cerr << "Verify serialized offer failed: missing sender nym id."
                  << std::endl;

        return false;
    }

    if (MIN_PLAUSIBLE_IDENTIFIER > offer.offeringnym().size()) {
        std::cerr << "Verify serialized offer failed: invalid sender nym id."
                  << std::endl;

        return false;
    }

    if (MAX_PLAUSIBLE_IDENTIFIER < offer.offeringnym().size()) {
        std::cerr << "Verify serialized offer failed: invalid sender nym id."
                  << std::endl;

        return false;
    }

    if (!offer.has_recipientnym()) {
        std::cerr << "Verify serialized offer failed: missing recipient nym id."
                  << std::endl;

        return false;
    }

    if (MIN_PLAUSIBLE_IDENTIFIER > offer.recipientnym().size()) {
        std::cerr << "Verify serialized offer failed: invalid recipient nym id."
                  << std::endl;

        return false;
    }

    if (MAX_PLAUSIBLE_IDENTIFIER < offer.recipientnym().size()) {
        std::cerr << "Verify serialized offer failed: invalid recipient nym id."
                  << std::endl;

        return false;
    }

    const bool validClaim = Check(
        offer.claim(),
        VerificationOfferAllowedClaim.at(offer.version()).first,
        VerificationOfferAllowedClaim.at(offer.version()).second);

    if (!validClaim) {
        std::cerr << "Verify serialized offer failed: invalid claim."
                  << std::endl;

        return false;
    }

    if (offer.claim().nymid() != offer.recipientnym()) {
        std::cerr << "Verify serialized offer failed: claim nym does not match "
                  << "recipient nym." << std::endl;

        return false;
    }

    const bool validVerification = Check(
        offer.verification(),
        VerificationOfferAllowedVerification.at(offer.version()).first,
        VerificationOfferAllowedVerification.at(offer.version()).second,
        VERIFICATIONS_NORMAL);

    if (!validVerification) {
        std::cerr << "Verify serialized offer failed: invalid verification."
                  << std::endl;

        return false;
    }

    return true;
}
bool CheckProto_2(const VerificationOffer&) { return false; }
bool CheckProto_3(const VerificationOffer&) { return false; }
bool CheckProto_4(const VerificationOffer&) { return false; }
bool CheckProto_5(const VerificationOffer&) { return false; }
} // namespace proto
} // namespace opentxs
