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

#define PROTO_NAME "pair event"

namespace opentxs
{
namespace proto
{

bool CheckProto_1(const PairEvent& input, const bool silent)
{
    CHECK_EXISTS(type)

    switch (input.type()) {
        case PAIREVENT_RENAME:
        case PAIREVENT_STORESECRET: {
        } break;
        default: {
            FAIL4("invalid type")
        }
    }

    CHECK_IDENTIFIER(issuer)

    return true;
}

bool CheckProto_2(const PairEvent& input, const bool silent)
{
    UNDEFINED_VERSION2(2)
}

bool CheckProto_3(const PairEvent& input, const bool silent)
{
    UNDEFINED_VERSION2(3)
}

bool CheckProto_4(const PairEvent& input, const bool silent)
{
    UNDEFINED_VERSION2(4)
}

bool CheckProto_5(const PairEvent& input, const bool silent)
{
    UNDEFINED_VERSION2(5)
}

bool CheckProto_6(const PairEvent& input, const bool silent)
{
    UNDEFINED_VERSION2(6)
}

bool CheckProto_7(const PairEvent& input, const bool silent)
{
    UNDEFINED_VERSION2(7)
}

bool CheckProto_8(const PairEvent& input, const bool silent)
{
    UNDEFINED_VERSION2(8)
}

bool CheckProto_9(const PairEvent& input, const bool silent)
{
    UNDEFINED_VERSION2(9)
}

bool CheckProto_10(const PairEvent& input, const bool silent)
{
    UNDEFINED_VERSION2(10)
}

bool CheckProto_11(const PairEvent& input, const bool silent)
{
    UNDEFINED_VERSION2(11)
}

bool CheckProto_12(const PairEvent& input, const bool silent)
{
    UNDEFINED_VERSION2(12)
}

bool CheckProto_13(const PairEvent& input, const bool silent)
{
    UNDEFINED_VERSION2(13)
}

bool CheckProto_14(const PairEvent& input, const bool silent)
{
    UNDEFINED_VERSION2(14)
}

bool CheckProto_15(const PairEvent& input, const bool silent)
{
    UNDEFINED_VERSION2(15)
}

bool CheckProto_16(const PairEvent& input, const bool silent)
{
    UNDEFINED_VERSION2(16)
}

bool CheckProto_17(const PairEvent& input, const bool silent)
{
    UNDEFINED_VERSION2(17)
}

bool CheckProto_18(const PairEvent& input, const bool silent)
{
    UNDEFINED_VERSION2(18)
}

bool CheckProto_19(const PairEvent& input, const bool silent)
{
    UNDEFINED_VERSION2(19)
}

bool CheckProto_20(const PairEvent& input, const bool silent)
{
    UNDEFINED_VERSION2(20)
}
}  // namespace proto
}  // namespace opentxs
