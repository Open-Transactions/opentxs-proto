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

#define PROTO_NAME "outbailment"

namespace opentxs
{
namespace proto
{

bool CheckProto_1(const OutBailment& input, const bool silent)
{
    if (!input.has_unitid()) { FAIL("outbailment", "missing unit id") }

    if (MIN_PLAUSIBLE_IDENTIFIER > input.unitid().size()) {
        FAIL2("outbailment", "invalid unit id", input.unitid())
    }

    if (MAX_PLAUSIBLE_IDENTIFIER < input.unitid().size()) {
        FAIL2("outbailment", "invalid unit id", input.unitid())
    }

    if (!input.has_serverid()) { FAIL("outbailment", "missing server id") }

    if (MIN_PLAUSIBLE_IDENTIFIER > input.serverid().size()) {
        FAIL2("outbailment", "invalid server id", input.serverid())
    }

    if (MAX_PLAUSIBLE_IDENTIFIER < input.serverid().size()) {
        FAIL2("outbailment", "invalid server id", input.serverid())
    }

    if (!input.has_amount()) { FAIL("outbailment", "missing amount") }

    if (!input.has_instructions()) {
        FAIL("outbailment", "missing instructions")
    }

    CHECK_NONE(payment)

    return true;
}

bool CheckProto_2(const OutBailment& input, const bool silent)
{

    return CheckProto_1(input, silent);
}

bool CheckProto_3(const OutBailment& input, const bool silent)
{

    return CheckProto_1(input, silent);
}

bool CheckProto_4(const OutBailment& input, const bool silent)
{

    return CheckProto_1(input, silent);
}

bool CheckProto_5(const OutBailment& input, const bool silent)
{
    if (!input.has_unitid()) { FAIL("outbailment", "missing unit id") }

    if (MIN_PLAUSIBLE_IDENTIFIER > input.unitid().size()) {
        FAIL2("outbailment", "invalid unit id", input.unitid())
    }

    if (MAX_PLAUSIBLE_IDENTIFIER < input.unitid().size()) {
        FAIL2("outbailment", "invalid unit id", input.unitid())
    }

    if (!input.has_serverid()) { FAIL("outbailment", "missing server id") }

    if (MIN_PLAUSIBLE_IDENTIFIER > input.serverid().size()) {
        FAIL2("outbailment", "invalid server id", input.serverid())
    }

    if (MAX_PLAUSIBLE_IDENTIFIER < input.serverid().size()) {
        FAIL2("outbailment", "invalid server id", input.serverid())
    }

    if (!input.has_amount()) { FAIL("outbailment", "missing amount") }

    if (!input.has_instructions()) {
        FAIL("outbailment", "missing instructions")
    }

    return true;
}

bool CheckProto_6(const OutBailment& input, const bool silent)
{
    UNDEFINED_VERSION2(6)
}

bool CheckProto_7(const OutBailment& input, const bool silent)
{
    UNDEFINED_VERSION2(7)
}

bool CheckProto_8(const OutBailment& input, const bool silent)
{
    UNDEFINED_VERSION2(8)
}

bool CheckProto_9(const OutBailment& input, const bool silent)
{
    UNDEFINED_VERSION2(9)
}

bool CheckProto_10(const OutBailment& input, const bool silent)
{
    UNDEFINED_VERSION2(10)
}

bool CheckProto_11(const OutBailment& input, const bool silent)
{
    UNDEFINED_VERSION2(11)
}

bool CheckProto_12(const OutBailment& input, const bool silent)
{
    UNDEFINED_VERSION2(12)
}

bool CheckProto_13(const OutBailment& input, const bool silent)
{
    UNDEFINED_VERSION2(13)
}

bool CheckProto_14(const OutBailment& input, const bool silent)
{
    UNDEFINED_VERSION2(14)
}

bool CheckProto_15(const OutBailment& input, const bool silent)
{
    UNDEFINED_VERSION2(15)
}

bool CheckProto_16(const OutBailment& input, const bool silent)
{
    UNDEFINED_VERSION2(16)
}

bool CheckProto_17(const OutBailment& input, const bool silent)
{
    UNDEFINED_VERSION2(17)
}

bool CheckProto_18(const OutBailment& input, const bool silent)
{
    UNDEFINED_VERSION2(18)
}

bool CheckProto_19(const OutBailment& input, const bool silent)
{
    UNDEFINED_VERSION2(19)
}

bool CheckProto_20(const OutBailment& input, const bool silent)
{
    UNDEFINED_VERSION2(20)
}
}  // namespace proto
}  // namespace opentxs
