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

#include "opentxs-proto/verify/UnitDefinition.hpp"

#include <iostream>

#include "opentxs-proto/verify/BasketParams.hpp"
#include "opentxs-proto/verify/CurrencyParams.hpp"
#include "opentxs-proto/verify/EquityParams.hpp"


 namespace opentxs { namespace proto
{

bool CheckProto_1(
    const UnitDefinition& contract,
    const bool checkSig)
{
    if (!contract.has_id()) {
        std::cerr << __FUNCTION__
                  << ": Verify unit definition failed: missing identifier."
                  << std::endl;

        return false;
    }

    if (MIN_PLAUSIBLE_IDENTIFIER > contract.id().size()) {
        std::cerr << __FUNCTION__
                  << ": Verify unit definition failed: invalid identifier ("
                  << contract.id() << ")." << std::endl;

        return false;
    }

    if (!contract.has_nymid()) {
        std::cerr << __FUNCTION__
                  << ": Verify unit definition failed: missing nymid."
                  << std::endl;

        return false;
    }

    if (MIN_PLAUSIBLE_IDENTIFIER > contract.nymid().size()) {
        std::cerr << __FUNCTION__
                  << ": Verify unit definition failed: invalid nymid ("
                  << contract.nymid() << ")." << std::endl;

        return false;
    }

    if (contract.has_publicnym()) {
        bool goodPublicNym = Check(
            contract.publicnym(),
            UnitDefinitionAllowedPublicNym.at(contract.version()).first,
            UnitDefinitionAllowedPublicNym.at(contract.version()).second);

        if (!goodPublicNym) {
            std::cerr << __FUNCTION__
                      << ": Verify unit definition failed: invalid nym."
                      << std::endl;

            return false;
        }

        if (contract.nymid() != contract.publicnym().nymid()) {
            std::cerr << __FUNCTION__
                      << ": Verify unit definition failed: wrong nym."
                      << std::endl;

            return false;
        }
    }

    if (!contract.has_shortname()) {
        std::cerr << __FUNCTION__
                  << ": Verify unit definition failed: missing shortname."
                  << std::endl;

        return false;
    }

    if (1 > contract.shortname().size()) {
        std::cerr << __FUNCTION__
                  << ": Verify unit definition failed: invalid shortname ("
                  << contract.shortname() << ")." << std::endl;

        return false;
    }

    if (!contract.has_terms()) {
        std::cerr << __FUNCTION__
                  << ": Verify unit definition failed: missing terms."
                  << std::endl;

        return false;
    }

    if (1 > contract.terms().size()) {
        std::cerr << __FUNCTION__
                  << ": Verify unit definition failed: invalid terms ("
                  << contract.terms() << ")." << std::endl;

        return false;
    }

    if (!contract.has_name()) {
        std::cerr << __FUNCTION__
                  << ": Verify unit definition failed: missing name."
                  << std::endl;

        return false;
    }

    if (1 > contract.name().size()) {
        std::cerr << __FUNCTION__
                  << ": Verify unit definition failed: invalid name ("
                  << contract.name() << ")." << std::endl;

        return false;
    }

    if (!contract.has_symbol()) {
        std::cerr << __FUNCTION__
                  << ": Verify unit definition failed: missing symbol."
                  << std::endl;

        return false;
    }

    if (1 > contract.symbol().size()) {
        std::cerr << __FUNCTION__
                  << ": Verify unit definition failed: invalid symbol ("
                  << contract.symbol() << ")." << std::endl;

        return false;
    }

    if (!contract.has_type()) {
        std::cerr << __FUNCTION__
                  << ": Verify unit definition failed: missing type."
                  << std::endl;

        return false;
    }

    bool goodParams = false;

    switch (contract.type()) {
        case (UNITTYPE_CURRENCY) :
            if (!contract.has_currency()) {
                std::cerr << __FUNCTION__
                        << ": Verify unit definition failed: missing"
                        << " currency params." << std::endl;

                return false;
            }

            goodParams = Check(
                contract.currency(),
                UnitDefinitionAllowedCurrencyParams.at(contract.version()).first,
                UnitDefinitionAllowedCurrencyParams.at(contract.version()).second);

            if (!goodParams) {
                std::cerr << __FUNCTION__
                        << ": Verify unit definition failed: invalid currency"
                        << " params." << std::endl;

                return false;
            }

            break;
        case (UNITTYPE_SECURITY) :
            if (!contract.has_security()) {
                std::cerr << __FUNCTION__
                << ": Verify unit definition failed: missing"
                << " security params." << std::endl;

                return false;
            }

            goodParams = Check(
                contract.security(),
                UnitDefinitionAllowedSecurityParams.at(contract.version()).first,
                UnitDefinitionAllowedSecurityParams.at(contract.version()).second);

            if (!goodParams) {
                std::cerr << __FUNCTION__
                        << ": Verify unit definition failed: invalid security"
                        << " params." << std::endl;

                return false;
            }

            break;
        case (UNITTYPE_BASKET) :
            if (!contract.has_basket()) {
                std::cerr << __FUNCTION__
                << ": Verify unit definition failed: missing"
                << " currency params." << std::endl;

                return false;
            }

            goodParams = Check(
                contract.basket(),
                UnitDefinitionAllowedBasketParams.at(contract.version()).first,
                UnitDefinitionAllowedBasketParams.at(contract.version()).second);

            if (!goodParams) {
                std::cerr << __FUNCTION__
                        << ": Verify unit definition failed: invalid basket"
                        << " params." << std::endl;

                return false;
            }

            break;
        default :
            std::cerr << __FUNCTION__
                    << ": Verify unit definition failed: invalid type."
                    << std::endl;

            return false;
    }

    if (checkSig) {
        if (!Check(
            contract.signature(),
            UnitDefinitionAllowedSignature.at(contract.version()).first,
            UnitDefinitionAllowedSignature.at(contract.version()).second,
            SIGROLE_UNITDEFINITION)) {
                std::cerr << __FUNCTION__
                << ": Verify unit definition failed: invalid signature"
                << " params." << std::endl;

                return false;
        }
    }

    return true;
}

} // namespace proto
} // namespace opentxs
