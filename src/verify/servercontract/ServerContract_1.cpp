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

bool CheckProto_1(const ServerContract& contract, const bool silent)
{
    if (!contract.has_id()) {
        FAIL("server contract", " missing id")
    }

    if (MIN_PLAUSIBLE_IDENTIFIER > contract.id().size()) {
        FAIL2("server contract", "invalid id", contract.id())
    }

    if (!contract.has_nymid()) {
        FAIL("server contract", "missing nym id")
    }

    if (!contract.has_name()) {
        FAIL("server contract", "missing name")
    }

    if (1 > contract.name().size()) {
        FAIL2("server contract", "invalid name", contract.name())
    }

    if (MIN_PLAUSIBLE_IDENTIFIER > contract.nymid().size()) {
        FAIL2("server contract", "invalid nym id", contract.nymid())
    }

    if (contract.has_publicnym()) {
        try {
            const bool validNym = Check(
                contract.publicnym(),
                ServerContractAllowedCredentialIndex.at(contract.version())
                    .first,
                ServerContractAllowedCredentialIndex.at(contract.version())
                    .second,
                silent);

            if (false == validNym) {
                FAIL("server contract", "invalid nym")
            }
        } catch (const std::out_of_range&) {
            FAIL2(
                "server contract",
                "allowed credential index version not defined for version",
                contract.version())
        }
    }

    if (0 == contract.address().size()) {
        FAIL("server contract", "no listen addresses")
    }

    try {
        const bool validAddress = Check(
            contract.address(0),
            ServerContractAllowedListenAddress.at(contract.version()).first,
            ServerContractAllowedListenAddress.at(contract.version()).second,
            silent);

        if (false == validAddress) {
            FAIL("server contract", "invalid listen address")
        }
    } catch (const std::out_of_range&) {
        FAIL2(
            "server contract",
            "allowed listen address version not defined for version",
            contract.version())
    }

    if (!contract.has_transportkey()) {
        FAIL("server contract", "missing transport key")
    }

    if (MIN_PLAUSIBLE_KEYSIZE > contract.transportkey().size()) {
        FAIL("server contract", "invalid transport key")
    }

    if (!contract.has_signature()) {
        FAIL("server contract", "missing signature")
    }

    try {
        const bool validSig = Check(
            contract.signature(),
            ServerContractAllowedSignature.at(contract.version()).first,
            ServerContractAllowedSignature.at(contract.version()).second,
            silent,
            SIGROLE_SERVERCONTRACT);

        if (false == validSig) {
            FAIL("server contract", "invalid signature")
        }
    } catch (const std::out_of_range&) {
        FAIL2(
            "server contract",
            "allowed signature version not defined for version",
            contract.version())
    }

    return true;
}
bool CheckProto_2(const ServerContract&, const bool) { return false; }
bool CheckProto_3(const ServerContract&, const bool) { return false; }
bool CheckProto_4(const ServerContract&, const bool) { return false; }
bool CheckProto_5(const ServerContract&, const bool) { return false; }
}  // namespace proto
}  // namespace opentxs
