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
 *  fellowtraveler@openaccounts.org
 *
 *  WEBSITE:
 *  http://www.openaccounts.org/
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

#define PROTO_NAME "blockchain account"

namespace opentxs
{
namespace proto
{

bool CheckProto_1(const Bip44Account& input, const bool silent)
{
    if (false == input.has_id()) {
        FAIL("blockchain account", "missing id")
    }

    if (MIN_PLAUSIBLE_IDENTIFIER > input.id().size()) {
        FAIL("blockchain account", "invalid id")
    }

    if (MAX_PLAUSIBLE_IDENTIFIER < input.id().size()) {
        FAIL("blockchain account", "invalid id")
    }

    const bool validChain = ValidContactItemType(
        {CONTACT_VERSION, CONTACTSECTION_CONTRACT}, input.type());

    if (false == validChain) {
        FAIL("blockchain account", "invalid type")
    }

    if (false == input.has_path()) {
        FAIL("blockchain account", "missing path")
    }

    try {
        const bool validPath = Check(
            input.path(),
            Bip44AccountAllowedHDPath.at(input.version()).first,
            Bip44AccountAllowedHDPath.at(input.version()).second,
            silent);

        if (false == validPath) {
            FAIL("blockchain account", "invalid path")
        }
    } catch (const std::out_of_range&) {
        FAIL2(
            "blockchain account",
            "allowed HD path version not defined for version",
            input.version())
    }

    for (const auto& address : input.internaladdress()) {
        try {
            const bool validAddress = Check(
                address,
                Bip44AccountAllowedBip44Address.at(input.version()).first,
                Bip44AccountAllowedBip44Address.at(input.version()).second,
                silent);

            if (false == validAddress) {
                FAIL("blockchain account", "invalid address")
            }
        } catch (const std::out_of_range&) {
            FAIL2(
                "blockchain account",
                "allowed Bip44 address version not defined for version",
                input.version())
        }
    }

    for (const auto& txid : input.outgoing()) {
        if (MIN_PLAUSIBLE_IDENTIFIER > txid.size()) {
            FAIL("blockchain account", "invalid txid")
        }

        if (MAX_PLAUSIBLE_IDENTIFIER < txid.size()) {
            FAIL("blockchain account", "invalid txid")
        }
    }

    return true;
}

bool CheckProto_2(const Bip44Account& input, const bool silent)
{
    UNDEFINED_VERSION("blockchain account", 2)
}

bool CheckProto_3(const Bip44Account& input, const bool silent)
{
    UNDEFINED_VERSION("blockchain account", 3)
}

bool CheckProto_4(const Bip44Account& input, const bool silent)
{
    UNDEFINED_VERSION("blockchain account", 4)
}

bool CheckProto_5(const Bip44Account& input, const bool silent)
{
    UNDEFINED_VERSION("blockchain account", 5)
}

bool CheckProto_6(const Bip44Account& input, const bool silent)
{
    UNDEFINED_VERSION2(6)
}

bool CheckProto_7(const Bip44Account& input, const bool silent)
{
    UNDEFINED_VERSION2(7)
}

bool CheckProto_8(const Bip44Account& input, const bool silent)
{
    UNDEFINED_VERSION2(8)
}

bool CheckProto_9(const Bip44Account& input, const bool silent)
{
    UNDEFINED_VERSION2(9)
}

bool CheckProto_10(const Bip44Account& input, const bool silent)
{
    UNDEFINED_VERSION2(10)
}

bool CheckProto_11(const Bip44Account& input, const bool silent)
{
    UNDEFINED_VERSION2(11)
}

bool CheckProto_12(const Bip44Account& input, const bool silent)
{
    UNDEFINED_VERSION2(12)
}

bool CheckProto_13(const Bip44Account& input, const bool silent)
{
    UNDEFINED_VERSION2(13)
}

bool CheckProto_14(const Bip44Account& input, const bool silent)
{
    UNDEFINED_VERSION2(14)
}

bool CheckProto_15(const Bip44Account& input, const bool silent)
{
    UNDEFINED_VERSION2(15)
}

bool CheckProto_16(const Bip44Account& input, const bool silent)
{
    UNDEFINED_VERSION2(16)
}

bool CheckProto_17(const Bip44Account& input, const bool silent)
{
    UNDEFINED_VERSION2(17)
}

bool CheckProto_18(const Bip44Account& input, const bool silent)
{
    UNDEFINED_VERSION2(18)
}

bool CheckProto_19(const Bip44Account& input, const bool silent)
{
    UNDEFINED_VERSION2(19)
}

bool CheckProto_20(const Bip44Account& input, const bool silent)
{
    UNDEFINED_VERSION2(20)
}
}  // namespace proto
}  // namespace opentxs
