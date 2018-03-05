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

#define PROTO_NAME "unit definition"

namespace opentxs
{
namespace proto
{

bool CheckProto_1(
    const UnitDefinition& input,
    const bool silent,
    const bool checkSig)
{
    if (!input.has_id()) {
        FAIL("unit definition", "missing id")
    }

    if (MIN_PLAUSIBLE_IDENTIFIER > input.id().size()) {
        FAIL2("unit definition", "invalid id", input.id())
    }

    if (!input.has_nymid()) {
        FAIL("unit definition", "missing nym id")
    }

    if (MIN_PLAUSIBLE_IDENTIFIER > input.nymid().size()) {
        FAIL2("unit definition", "invalid nym id", input.nymid())
    }

    if (input.has_publicnym()) {
        try {
            const bool goodPublicNym = Check(
                input.publicnym(),
                UnitDefinitionAllowedCredentialIndex.at(input.version()).first,
                UnitDefinitionAllowedCredentialIndex.at(input.version()).second,
                silent);

            if (!goodPublicNym) {
                FAIL("unit definition", "invalid nym")
            }
        } catch (const std::out_of_range&) {
            FAIL2(
                "unit definition",
                "allowed credential index version not defined for version",
                input.version())
        }

        if (input.nymid() != input.publicnym().nymid()) {
            FAIL("unit definition", "wrong nym")
        }
    }

    if (!input.has_shortname()) {
        FAIL("unit definition", "missing shortname")
    }

    if (1 > input.shortname().size()) {
        FAIL2("unit definition", "invalid shortname", input.shortname())
    }

    if (!input.has_terms()) {
        FAIL("unit definition", "missing terms")
    }

    if (1 > input.terms().size()) {
        FAIL2("unit definition", "invalid terms", input.terms())
    }

    if (!input.has_name()) {
        FAIL("unit definition", "missing name")
    }

    if (1 > input.name().size()) {
        FAIL2("unit definition", "invalid name", input.name())
    }

    if (!input.has_symbol()) {
        FAIL("unit definition", "missing symbol")
    }

    if (1 > input.symbol().size()) {
        FAIL2("unit definition", "invalid symbol", input.symbol())
    }

    if (!input.has_type()) {
        FAIL("unit definition", "missing type")
    }

    bool goodParams = false;

    switch (input.type()) {
        case (UNITTYPE_CURRENCY): {
            if (!input.has_currency()) {
                FAIL("unit definition", "missing currency params")
            }

            try {
                goodParams = Check(
                    input.currency(),
                    UnitDefinitionAllowedCurrencyParams.at(input.version())
                        .first,
                    UnitDefinitionAllowedCurrencyParams.at(input.version())
                        .second,
                    silent);
            } catch (const std::out_of_range&) {
                FAIL2(
                    "unit definition",
                    "allowed currency params version not defined for version",
                    input.version())
            }

            if (!goodParams) {
                FAIL("unit definition", "invalid currency params")
            }

        } break;
        case (UNITTYPE_SECURITY): {
            if (!input.has_security()) {
                FAIL("unit definition", "missing security params")
            }

            try {
                goodParams = Check(
                    input.security(),
                    UnitDefinitionAllowedSecurityParams.at(input.version())
                        .first,
                    UnitDefinitionAllowedSecurityParams.at(input.version())
                        .second,
                    silent);
            } catch (const std::out_of_range&) {
                FAIL2(
                    "unit definition",
                    "allowed security params version not defined for version",
                    input.version())
            }

            if (!goodParams) {
                FAIL("unit definition", "invalid security params")
            }

        } break;
        case (UNITTYPE_BASKET): {
            if (!input.has_basket()) {
                FAIL("unit definition", "missing currency params")
            }

            try {
                goodParams = Check(
                    input.basket(),
                    UnitDefinitionAllowedBasketParams.at(input.version()).first,
                    UnitDefinitionAllowedBasketParams.at(input.version())
                        .second,
                    silent);
            } catch (const std::out_of_range&) {
                FAIL2(
                    "unit definition",
                    "allowed basket params version not defined for version",
                    input.version())
            }

            if (!goodParams) {
                FAIL("unit definition", "invalid basket params")
            }

        } break;
        default: {
            FAIL("unit definition", "invalid type")
        }
    }

    if (checkSig) {
        try {
            const bool valid = Check(
                input.signature(),
                UnitDefinitionAllowedSignature.at(input.version()).first,
                UnitDefinitionAllowedSignature.at(input.version()).second,
                silent,
                SIGROLE_UNITDEFINITION);

            if (false == valid) {
                FAIL("unit definition", "invalid signature")
            }
        } catch (const std::out_of_range&) {
            FAIL2(
                "unit definition",
                "allowed signature version not defined for version",
                input.version())
        }
    }

    return true;
}

bool CheckProto_2(const UnitDefinition& input, const bool silent, const bool)
{
    UNDEFINED_VERSION("unit definition", 2)
}

bool CheckProto_3(const UnitDefinition& input, const bool silent, const bool)
{
    UNDEFINED_VERSION("unit definition", 3)
}

bool CheckProto_4(const UnitDefinition& input, const bool silent, const bool)
{
    UNDEFINED_VERSION("unit definition", 4)
}

bool CheckProto_5(const UnitDefinition& input, const bool silent, const bool)
{
    UNDEFINED_VERSION("unit definition", 5)
}

bool CheckProto_6(const UnitDefinition& input, const bool silent, const bool)
{
    UNDEFINED_VERSION2(6)
}

bool CheckProto_7(const UnitDefinition& input, const bool silent, const bool)
{
    UNDEFINED_VERSION2(7)
}

bool CheckProto_8(const UnitDefinition& input, const bool silent, const bool)
{
    UNDEFINED_VERSION2(8)
}

bool CheckProto_9(const UnitDefinition& input, const bool silent, const bool)
{
    UNDEFINED_VERSION2(9)
}

bool CheckProto_10(const UnitDefinition& input, const bool silent, const bool)
{
    UNDEFINED_VERSION2(10)
}

bool CheckProto_11(const UnitDefinition& input, const bool silent, const bool)
{
    UNDEFINED_VERSION2(11)
}

bool CheckProto_12(const UnitDefinition& input, const bool silent, const bool)
{
    UNDEFINED_VERSION2(12)
}

bool CheckProto_13(const UnitDefinition& input, const bool silent, const bool)
{
    UNDEFINED_VERSION2(13)
}

bool CheckProto_14(const UnitDefinition& input, const bool silent, const bool)
{
    UNDEFINED_VERSION2(14)
}

bool CheckProto_15(const UnitDefinition& input, const bool silent, const bool)
{
    UNDEFINED_VERSION2(15)
}

bool CheckProto_16(const UnitDefinition& input, const bool silent, const bool)
{
    UNDEFINED_VERSION2(16)
}

bool CheckProto_17(const UnitDefinition& input, const bool silent, const bool)
{
    UNDEFINED_VERSION2(17)
}

bool CheckProto_18(const UnitDefinition& input, const bool silent, const bool)
{
    UNDEFINED_VERSION2(18)
}

bool CheckProto_19(const UnitDefinition& input, const bool silent, const bool)
{
    UNDEFINED_VERSION2(19)
}

bool CheckProto_20(const UnitDefinition& input, const bool silent, const bool)
{
    UNDEFINED_VERSION2(20)
}
}  // namespace proto
}  // namespace opentxs
