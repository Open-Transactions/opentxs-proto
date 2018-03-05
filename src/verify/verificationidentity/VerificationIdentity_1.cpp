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

#define PROTO_NAME "verification identity"

namespace opentxs
{
namespace proto
{

bool CheckProto_1(
    const VerificationIdentity& input,
    const bool silent,
    VerificationNymMap& map,
    const VerificationType indexed)
{
    if (!input.has_nym()) {
        FAIL("verification identity", "missing nym")
    }

    if (MIN_PLAUSIBLE_IDENTIFIER > input.nym().size()) {
        FAIL2("verification identity", "invalid nym", input.nym())
    }

    map[input.nym()] += 1;

    for (auto& it : input.verification()) {
        try {
            const bool verification = Check(
                it,
                VerificationIdentityAllowedVerification.at(input.version())
                    .first,
                VerificationIdentityAllowedVerification.at(input.version())
                    .second,
                silent,
                indexed);

            if (!verification) {
                FAIL("verification identity", "invalid verification")
            }
        } catch (const std::out_of_range&) {
            FAIL2(
                "verification identity",
                "allowed verification version not defined for version",
                input.version())
        }
    }

    return true;
}

bool CheckProto_2(
    const VerificationIdentity& input,
    const bool silent,
    VerificationNymMap&,
    const VerificationType)
{
    UNDEFINED_VERSION("verification identity", 2)
}

bool CheckProto_3(
    const VerificationIdentity& input,
    const bool silent,
    VerificationNymMap&,
    const VerificationType)
{
    UNDEFINED_VERSION("verification identity", 3)
}

bool CheckProto_4(
    const VerificationIdentity& input,
    const bool silent,
    VerificationNymMap&,
    const VerificationType)
{
    UNDEFINED_VERSION("verification identity", 4)
}

bool CheckProto_5(
    const VerificationIdentity& input,
    const bool silent,
    VerificationNymMap&,
    const VerificationType)
{
    UNDEFINED_VERSION("verification identity", 5)
}

bool CheckProto_6(
    const VerificationIdentity& input,
    const bool silent,
    VerificationNymMap&,
    const VerificationType)
{
    UNDEFINED_VERSION2(6)
}

bool CheckProto_7(
    const VerificationIdentity& input,
    const bool silent,
    VerificationNymMap&,
    const VerificationType)
{
    UNDEFINED_VERSION2(7)
}

bool CheckProto_8(
    const VerificationIdentity& input,
    const bool silent,
    VerificationNymMap&,
    const VerificationType)
{
    UNDEFINED_VERSION2(8)
}

bool CheckProto_9(
    const VerificationIdentity& input,
    const bool silent,
    VerificationNymMap&,
    const VerificationType)
{
    UNDEFINED_VERSION2(9)
}

bool CheckProto_10(
    const VerificationIdentity& input,
    const bool silent,
    VerificationNymMap&,
    const VerificationType)
{
    UNDEFINED_VERSION2(10)
}

bool CheckProto_11(
    const VerificationIdentity& input,
    const bool silent,
    VerificationNymMap&,
    const VerificationType)
{
    UNDEFINED_VERSION2(11)
}

bool CheckProto_12(
    const VerificationIdentity& input,
    const bool silent,
    VerificationNymMap&,
    const VerificationType)
{
    UNDEFINED_VERSION2(12)
}

bool CheckProto_13(
    const VerificationIdentity& input,
    const bool silent,
    VerificationNymMap&,
    const VerificationType)
{
    UNDEFINED_VERSION2(13)
}

bool CheckProto_14(
    const VerificationIdentity& input,
    const bool silent,
    VerificationNymMap&,
    const VerificationType)
{
    UNDEFINED_VERSION2(14)
}

bool CheckProto_15(
    const VerificationIdentity& input,
    const bool silent,
    VerificationNymMap&,
    const VerificationType)
{
    UNDEFINED_VERSION2(15)
}

bool CheckProto_16(
    const VerificationIdentity& input,
    const bool silent,
    VerificationNymMap&,
    const VerificationType)
{
    UNDEFINED_VERSION2(16)
}

bool CheckProto_17(
    const VerificationIdentity& input,
    const bool silent,
    VerificationNymMap&,
    const VerificationType)
{
    UNDEFINED_VERSION2(17)
}

bool CheckProto_18(
    const VerificationIdentity& input,
    const bool silent,
    VerificationNymMap&,
    const VerificationType)
{
    UNDEFINED_VERSION2(18)
}

bool CheckProto_19(
    const VerificationIdentity& input,
    const bool silent,
    VerificationNymMap&,
    const VerificationType)
{
    UNDEFINED_VERSION2(19)
}

bool CheckProto_20(
    const VerificationIdentity& input,
    const bool silent,
    VerificationNymMap&,
    const VerificationType)
{
    UNDEFINED_VERSION2(20)
}
}  // namespace proto
}  // namespace opentxs
