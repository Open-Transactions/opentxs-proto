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

bool CheckProto_1(
    const Verification& verification,
    const VerificationType indexed)
{
    if (indexed) {
        if (!verification.has_id()) {
            std::cerr << "Verify serialized verification failed: missing ID."
                      << std::endl;
            return false;
        }

        if (MIN_PLAUSIBLE_IDENTIFIER > verification.id().size()) {
            std::cerr << "Verify serialized verification failed: invalid ID."
                      << std::endl;
            return false;
        }
    } else {
        if (verification.has_id()) {
            std::cerr << "Verify serialized verification failed: ID field not "
                      << "empty." << std::endl;
            return false;
        }
    }

    if (!verification.has_claim()) {
        std::cerr << "Verify serialized verification failed: missing claim."
        << std::endl;
        return false;
    }

    if (MIN_PLAUSIBLE_IDENTIFIER > verification.claim().size()) {
        std::cerr << "Verify serialized verification failed: invalid claim."
        << std::endl;
        return false;
    }

    if (!verification.has_valid()) {
        std::cerr << "Verify serialized verification failed: missing validity."
        << std::endl;
        return false;
    }

    if (!verification.has_start()) {
        std::cerr << "Verify serialized verification failed: missing start time."
        << std::endl;
        return false;
    }

    if (!verification.has_end()) {
        std::cerr << "Verify serialized verification failed: missing end time."
        << std::endl;
        return false;
    }

    if (verification.end() < verification.start()) {
        std::cerr << "Verify serialized verification failed: invalid end time."
        << std::endl;
        return false;
    }

    if (!verification.has_sig()) {
        std::cerr << "Verify serialized verification failed: missing signature."
        << std::endl;
        return false;
    }

    bool validSignature = Check(
        verification.sig(),
        VerificationAllowedSignature.at(verification.version()).first,
        VerificationAllowedSignature.at(verification.version()).second,
        proto::SIGROLE_CLAIM);

    if (!validSignature) {
        std::cerr << "Verify serialized verification failed: invalid signature."
                  << std::endl;
        return false;
    }

    return true;
}
bool CheckProto_2(const Verification&, const VerificationType) { return false; }
bool CheckProto_3(const Verification&, const VerificationType) { return false; }
bool CheckProto_4(const Verification&, const VerificationType) { return false; }
bool CheckProto_5(const Verification&, const VerificationType) { return false; }
} // namespace proto
} // namespace opentxs
