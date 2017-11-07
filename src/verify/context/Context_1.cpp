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

#include "opentxs-proto/Check.hpp"
#include "opentxs-proto/Types.hpp"

#include <iostream>

#define PROTO_NAME "context"

namespace opentxs
{
namespace proto
{
bool CheckProto_1(const Context& input, const bool silent)
{
    CHECK_IDENTIFIER(localnym)
    CHECK_IDENTIFIER(remotenym)
    CHECK_EXISTS(type)

    switch (input.type()) {
        case CONSENSUSTYPE_SERVER: {
            CHECK_EXCLUDED(clientcontext)
            CHECK_SUBOBJECT(servercontext, ContextAllowedServer)
        } break;
        case CONSENSUSTYPE_CLIENT: {
            CHECK_EXCLUDED(servercontext)
            CHECK_SUBOBJECT(clientcontext, ContextAllowedServer)
        } break;
        default: {
            FAIL4("invalid type")
        }
    }

    CHECK_SUBOBJECT2(signature, ContextAllowedSignature, ", SIGROLE_CONTEXT")

    return true;
}

bool CheckProto_2(const Context& input, const bool silent)
{
    return CheckProto_1(input, silent);
}

bool CheckProto_3(const Context& input, const bool silent)
{
    UNDEFINED_VERSION("context", 3)
}

bool CheckProto_4(const Context& input, const bool silent)
{
    UNDEFINED_VERSION("context", 4)
}

bool CheckProto_5(const Context& input, const bool silent)
{
    UNDEFINED_VERSION("context", 5)
}
}  // namespace proto
}  // namespace opentxs
