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

#define PROTO_NAME "server contract"

namespace opentxs
{
namespace proto
{

bool CheckProto_1(const ServerContract& input, const bool silent)
{
    if (!input.has_id()) {
        FAIL("server contract", " missing id")
    }

    if (MIN_PLAUSIBLE_IDENTIFIER > input.id().size()) {
        FAIL2("server contract", "invalid id", input.id())
    }

    if (!input.has_nymid()) {
        FAIL("server contract", "missing nym id")
    }

    if (!input.has_name()) {
        FAIL("server contract", "missing name")
    }

    if (1 > input.name().size()) {
        FAIL2("server contract", "invalid name", input.name())
    }

    if (MIN_PLAUSIBLE_IDENTIFIER > input.nymid().size()) {
        FAIL2("server contract", "invalid nym id", input.nymid())
    }

    if (input.has_publicnym()) {
        try {
            const bool validNym = Check(
                input.publicnym(),
                ServerContractAllowedCredentialIndex.at(input.version()).first,
                ServerContractAllowedCredentialIndex.at(input.version()).second,
                silent);

            if (false == validNym) {
                FAIL("server contract", "invalid nym")
            }
        } catch (const std::out_of_range&) {
            FAIL2(
                "server contract",
                "allowed credential index version not defined for version",
                input.version())
        }
    }

    if (0 == input.address().size()) {
        FAIL("server contract", "no listen addresses")
    }

    try {
        const bool validAddress = Check(
            input.address(0),
            ServerContractAllowedListenAddress.at(input.version()).first,
            ServerContractAllowedListenAddress.at(input.version()).second,
            silent);

        if (false == validAddress) {
            FAIL("server contract", "invalid listen address")
        }
    } catch (const std::out_of_range&) {
        FAIL2(
            "server contract",
            "allowed listen address version not defined for version",
            input.version())
    }

    if (!input.has_transportkey()) {
        FAIL("server contract", "missing transport key")
    }

    if (MIN_PLAUSIBLE_KEYSIZE > input.transportkey().size()) {
        FAIL("server contract", "invalid transport key")
    }

    if (!input.has_signature()) {
        FAIL("server contract", "missing signature")
    }

    try {
        const bool validSig = Check(
            input.signature(),
            ServerContractAllowedSignature.at(input.version()).first,
            ServerContractAllowedSignature.at(input.version()).second,
            silent,
            SIGROLE_SERVERCONTRACT);

        if (false == validSig) {
            FAIL("server contract", "invalid signature")
        }
    } catch (const std::out_of_range&) {
        FAIL2(
            "server contract",
            "allowed signature version not defined for version",
            input.version())
    }

    return true;
}

bool CheckProto_2(const ServerContract& input, const bool silent)
{
    UNDEFINED_VERSION("server contract", 2)
}

bool CheckProto_3(const ServerContract& input, const bool silent)
{
    UNDEFINED_VERSION("server contract", 3)
}

bool CheckProto_4(const ServerContract& input, const bool silent)
{
    UNDEFINED_VERSION("server contract", 4)
}

bool CheckProto_5(const ServerContract& input, const bool silent)
{
    UNDEFINED_VERSION("server contract", 5)
}

bool CheckProto_6(const ServerContract& input, const bool silent)
{
    UNDEFINED_VERSION2(6)
}

bool CheckProto_7(const ServerContract& input, const bool silent)
{
    UNDEFINED_VERSION2(7)
}

bool CheckProto_8(const ServerContract& input, const bool silent)
{
    UNDEFINED_VERSION2(8)
}

bool CheckProto_9(const ServerContract& input, const bool silent)
{
    UNDEFINED_VERSION2(9)
}

bool CheckProto_10(const ServerContract& input, const bool silent)
{
    UNDEFINED_VERSION2(10)
}

bool CheckProto_11(const ServerContract& input, const bool silent)
{
    UNDEFINED_VERSION2(11)
}

bool CheckProto_12(const ServerContract& input, const bool silent)
{
    UNDEFINED_VERSION2(12)
}

bool CheckProto_13(const ServerContract& input, const bool silent)
{
    UNDEFINED_VERSION2(13)
}

bool CheckProto_14(const ServerContract& input, const bool silent)
{
    UNDEFINED_VERSION2(14)
}

bool CheckProto_15(const ServerContract& input, const bool silent)
{
    UNDEFINED_VERSION2(15)
}

bool CheckProto_16(const ServerContract& input, const bool silent)
{
    UNDEFINED_VERSION2(16)
}

bool CheckProto_17(const ServerContract& input, const bool silent)
{
    UNDEFINED_VERSION2(17)
}

bool CheckProto_18(const ServerContract& input, const bool silent)
{
    UNDEFINED_VERSION2(18)
}

bool CheckProto_19(const ServerContract& input, const bool silent)
{
    UNDEFINED_VERSION2(19)
}

bool CheckProto_20(const ServerContract& input, const bool silent)
{
    UNDEFINED_VERSION2(20)
}
}  // namespace proto
}  // namespace opentxs
