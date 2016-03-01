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

#include "opentxs-proto/verify/ServerContract.hpp"

#include <iostream>

 namespace opentxs { namespace proto
{

bool CheckProto_1(
    const ServerContract& contract)
{
    if (!contract.has_id()) {
        std::cerr << "Verify serialized server contract failed: missing identifier." << std::endl;
        return false;
    }

    if (MIN_PLAUSIBLE_IDENTIFIER > contract.id().size()) {
        std::cerr << "Verify serialized server contract failed: invalid identifier ("
        << contract.id() << ")." << std::endl;
        return false;
    }

    if (!contract.has_nymid()) {
        std::cerr << "Verify serialized server contract failed: missing nym identifier." << std::endl;
        return false;
    }

    if (!contract.has_name()) {
        std::cerr << "Verify serialized server contract failed: missing name." << std::endl;
        return false;
    }

    if (1 > contract.name().size()) {
        std::cerr << "Verify serialized server contract failed: invalid name ("
        << contract.name() << ")." << std::endl;
        return false;
    }

    if (MIN_PLAUSIBLE_IDENTIFIER > contract.nymid().size()) {
        std::cerr << "Verify serialized server contract failed: invalid nym identifier ("
        << contract.nymid() << ")." << std::endl;
        return false;
    }

    if (contract.has_publicnym()) {
        if (!Check(contract.publicnym(), 0, 0xFFFFFFFF)) {
                std::cerr << "Verify serialized server contract failed: invalid public nym" << std::endl;
                return false;
        }
    }

    if (1 !=contract.address().size()) {
        std::cerr << "Verify serialized server contract failed: wrong number of addresses ("
        << contract.address().size() << ") of 1 found." << std::endl;
        return false;
    }

    if (!Check(
        contract.address(0),
        ServerContractAllowedListenAddress.at(contract.version()).first,
        ServerContractAllowedListenAddress.at(contract.version()).second)) {
            std::cerr << "Verify serialized server contract failed: invalid address" << std::endl;
            return false;
    }

    if (!contract.has_transportkey()) {
        std::cerr << "Verify serialized server contract failed: missing transport key" << std::endl;
        return false;
    }

    if (MIN_PLAUSIBLE_KEYSIZE > contract.transportkey().size()) {
        std::cerr << "Verify serialized server contract failed: invalid transport key" << std::endl;
        return false;
    }

    if (!contract.has_signature()) {
        std::cerr << "Verify serialized server contract failed: missing signature" << std::endl;
        return false;
    }

    if (!Check(
        contract.signature(),
        ServerContractAllowedSignature.at(contract.version()).first,
        ServerContractAllowedSignature.at(contract.version()).second,
        SIGROLE_SERVERCONTRACT)) {
            std::cerr << "Verify serialized server contract failed: invalid"
                      << " signature" << std::endl;
            return false;
    }

    return true;
}

} // namespace proto
} // namespace opentxs
