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

#define PROTO_NAME "verification set"

namespace opentxs
{
namespace proto
{

bool CheckProto_1(
    const VerificationSet& input,
    const bool silent,
    const VerificationType indexed)
{
    if (input.has_internal()) {
        try {
            const bool validInternal = Check(
                input.internal(),
                VerificationSetAllowedGroup.at(input.version()).first,
                VerificationSetAllowedGroup.at(input.version()).second,
                silent,
                indexed);

            if (!validInternal) {
                FAIL("verification set", "invalid internal group")
            }
        } catch (const std::out_of_range&) {
            FAIL2(
                "verification set",
                "allowed verification group version not defined for version",
                input.version())
        }
    }

    if (input.has_external()) {
        try {
            const bool validExternal = Check(
                input.external(),
                VerificationSetAllowedGroup.at(input.version()).first,
                VerificationSetAllowedGroup.at(input.version()).second,
                silent,
                indexed);

            if (!validExternal) {
                FAIL("verification set", "invalid external group")
            }
        } catch (const std::out_of_range&) {
            FAIL2(
                "verification set",
                "allowed verification group version not defined for version",
                input.version())
        }
    }

    for (auto& it : input.repudiated()) {
        if (MIN_PLAUSIBLE_IDENTIFIER < it.size()) {
            FAIL("verification set", "invalid repudiation")
        }
    }

    return true;
}

bool CheckProto_2(
    const VerificationSet& input,
    const bool silent,
    const VerificationType)
{
    UNDEFINED_VERSION("verification set", 2)
}

bool CheckProto_3(
    const VerificationSet& input,
    const bool silent,
    const VerificationType)
{
    UNDEFINED_VERSION("verification set", 3)
}

bool CheckProto_4(
    const VerificationSet& input,
    const bool silent,
    const VerificationType)
{
    UNDEFINED_VERSION("verification set", 4)
}

bool CheckProto_5(
    const VerificationSet& input,
    const bool silent,
    const VerificationType)
{
    UNDEFINED_VERSION("verification set", 5)
}

bool CheckProto_6(
    const VerificationSet& input,
    const bool silent,
    const VerificationType)
{
    UNDEFINED_VERSION2(6)
}

bool CheckProto_7(
    const VerificationSet& input,
    const bool silent,
    const VerificationType)
{
    UNDEFINED_VERSION2(7)
}

bool CheckProto_8(
    const VerificationSet& input,
    const bool silent,
    const VerificationType)
{
    UNDEFINED_VERSION2(8)
}

bool CheckProto_9(
    const VerificationSet& input,
    const bool silent,
    const VerificationType)
{
    UNDEFINED_VERSION2(9)
}

bool CheckProto_10(
    const VerificationSet& input,
    const bool silent,
    const VerificationType)
{
    UNDEFINED_VERSION2(10)
}

bool CheckProto_11(
    const VerificationSet& input,
    const bool silent,
    const VerificationType)
{
    UNDEFINED_VERSION2(11)
}

bool CheckProto_12(
    const VerificationSet& input,
    const bool silent,
    const VerificationType)
{
    UNDEFINED_VERSION2(12)
}

bool CheckProto_13(
    const VerificationSet& input,
    const bool silent,
    const VerificationType)
{
    UNDEFINED_VERSION2(13)
}

bool CheckProto_14(
    const VerificationSet& input,
    const bool silent,
    const VerificationType)
{
    UNDEFINED_VERSION2(14)
}

bool CheckProto_15(
    const VerificationSet& input,
    const bool silent,
    const VerificationType)
{
    UNDEFINED_VERSION2(15)
}

bool CheckProto_16(
    const VerificationSet& input,
    const bool silent,
    const VerificationType)
{
    UNDEFINED_VERSION2(16)
}

bool CheckProto_17(
    const VerificationSet& input,
    const bool silent,
    const VerificationType)
{
    UNDEFINED_VERSION2(17)
}

bool CheckProto_18(
    const VerificationSet& input,
    const bool silent,
    const VerificationType)
{
    UNDEFINED_VERSION2(18)
}

bool CheckProto_19(
    const VerificationSet& input,
    const bool silent,
    const VerificationType)
{
    UNDEFINED_VERSION2(19)
}

bool CheckProto_20(
    const VerificationSet& input,
    const bool silent,
    const VerificationType)
{
    UNDEFINED_VERSION2(20)
}
}  // namespace proto
}  // namespace opentxs
