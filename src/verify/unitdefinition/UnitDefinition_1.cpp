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
    const UnitDefinition& contract,
    const bool silent,
    const bool checkSig)
{
    if (!contract.has_id()) {
        FAIL("unit definition", "missing id")
    }

    if (MIN_PLAUSIBLE_IDENTIFIER > contract.id().size()) {
        FAIL2("unit definition", "invalid id", contract.id())
    }

    if (!contract.has_nymid()) {
        FAIL("unit definition", "missing nym id")
    }

    if (MIN_PLAUSIBLE_IDENTIFIER > contract.nymid().size()) {
        FAIL2("unit definition", "invalid nym id", contract.nymid())
    }

    if (contract.has_publicnym()) {
        bool goodPublicNym = Check(
            contract.publicnym(),
            UnitDefinitionAllowedCredentialIndex.at(contract.version()).first,
            UnitDefinitionAllowedCredentialIndex.at(contract.version()).second,
            silent);

        if (!goodPublicNym) {
            FAIL("unit definition", "invalid nym")
        }

        if (contract.nymid() != contract.publicnym().nymid()) {
            FAIL("unit definition", "wrong nym")
        }
    }

    if (!contract.has_shortname()) {
        FAIL("unit definition", "missing shortname")
    }

    if (1 > contract.shortname().size()) {
        FAIL2("unit definition", "invalid shortname", contract.shortname())
    }

    if (!contract.has_terms()) {
        FAIL("unit definition", "missing terms")
    }

    if (1 > contract.terms().size()) {
        FAIL2("unit definition", "invalid terms", contract.terms())
    }

    if (!contract.has_name()) {
        FAIL("unit definition", "missing name")
    }

    if (1 > contract.name().size()) {
        FAIL2("unit definition", "invalid name", contract.name())
    }

    if (!contract.has_symbol()) {
        FAIL("unit definition", "missing symbol")
    }

    if (1 > contract.symbol().size()) {
        FAIL2("unit definition", "invalid symbol", contract.symbol())
    }

    if (!contract.has_type()) {
        FAIL("unit definition", "missing type")
    }

    bool goodParams = false;

    switch (contract.type()) {
        case (UNITTYPE_CURRENCY): {
            if (!contract.has_currency()) {
                FAIL("unit definition", "missing currency params")
            }

            goodParams = Check(
                contract.currency(),
                UnitDefinitionAllowedCurrencyParams.at(contract.version())
                    .first,
                UnitDefinitionAllowedCurrencyParams.at(contract.version())
                    .second,
                silent);

            if (!goodParams) {
                FAIL("unit definition", "invalid currency params")
            }

        } break;
        case (UNITTYPE_SECURITY): {
            if (!contract.has_security()) {
                FAIL("unit definition", "missing security params")
            }

            goodParams = Check(
                contract.security(),
                UnitDefinitionAllowedSecurityParams.at(contract.version())
                    .first,
                UnitDefinitionAllowedSecurityParams.at(contract.version())
                    .second,
                silent);

            if (!goodParams) {
                FAIL("unit definition", "invalid security params")
            }

        } break;
        case (UNITTYPE_BASKET): {
            if (!contract.has_basket()) {
                FAIL("unit definition", "missing currency params")
            }

            goodParams = Check(
                contract.basket(),
                UnitDefinitionAllowedBasketParams.at(contract.version()).first,
                UnitDefinitionAllowedBasketParams.at(contract.version()).second,
                silent);

            if (!goodParams) {
                FAIL("unit definition", "invalid basket params")
            }

        } break;
        default: {
            FAIL("unit definition", "invalid type")
        }
    }

    if (checkSig) {
        if (!Check(
                contract.signature(),
                UnitDefinitionAllowedSignature.at(contract.version()).first,
                UnitDefinitionAllowedSignature.at(contract.version()).second,
                silent,
                SIGROLE_UNITDEFINITION)) {
            FAIL("nit definition", "invalid signature")
        }
    }

    return true;
}
bool CheckProto_2(const UnitDefinition&, const bool, const bool)
{
    return false;
}
bool CheckProto_3(const UnitDefinition&, const bool, const bool)
{
    return false;
}
bool CheckProto_4(const UnitDefinition&, const bool, const bool)
{
    return false;
}
bool CheckProto_5(const UnitDefinition&, const bool, const bool)
{
    return false;
}
}  // namespace proto
}  // namespace opentxs
