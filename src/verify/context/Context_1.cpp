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

namespace opentxs
{
namespace proto
{
bool CheckProto_1(const Context& context, const bool silent)
{
    if (!context.has_localnym()) {
        FAIL("context", " missing local nym")
    }

    if ((MIN_PLAUSIBLE_IDENTIFIER > context.localnym().size()) ||
        (MAX_PLAUSIBLE_IDENTIFIER < context.localnym().size())) {
        FAIL("context", "invalid local nym")
    }

    if (!context.has_remotenym()) {
        FAIL("context", "missing remote nym")
    }

    if ((MIN_PLAUSIBLE_IDENTIFIER > context.remotenym().size()) ||
        (MAX_PLAUSIBLE_IDENTIFIER < context.remotenym().size())) {
        FAIL("context", "invalid remote nym")
    }

    if (!context.has_type()) {
        FAIL("context", "missing type")
    }

    switch (context.type()) {
        case CONSENSUSTYPE_SERVER: {
            if (!context.has_servercontext()) {
                FAIL("context", "missing server data")
            }

            if (context.has_clientcontext()) {
                FAIL("context", "client data in server context")
            }

            const bool validServer = Check(
                context.servercontext(),
                ContextAllowedServer.at(context.version()).first,
                ContextAllowedServer.at(context.version()).second,
                silent);

            if (!validServer) {
                FAIL("context", "invalid server data")
            }
        } break;
        case CONSENSUSTYPE_CLIENT: {
            if (!context.has_clientcontext()) {
                FAIL("context", "missing client data")
            }

            if (context.has_servercontext()) {
                FAIL("context", "client data in server context")
            }

            const bool validClient = Check(
                context.clientcontext(),
                ContextAllowedClient.at(context.version()).first,
                ContextAllowedClient.at(context.version()).second,
                silent);

            if (!validClient) {
                FAIL("context", "invalid client data")
            }
        } break;
        default: {
            FAIL("context", "invalid type")
        }
    }

    if (!context.has_signature()) {
        FAIL("context", "missing signature")
    }

    const bool validSig = Check(
        context.signature(),
        ContextAllowedSignature.at(context.version()).first,
        ContextAllowedSignature.at(context.version()).first,
        silent,
        SIGROLE_CONTEXT);

    if (!validSig) {
        FAIL("context", "invalid signature")
    }

    return true;
}

bool CheckProto_2(const Context& context, const bool silent)
{
    return CheckProto_1(context, silent);
}

bool CheckProto_3(const Context&, const bool) { return false; }
bool CheckProto_4(const Context&, const bool) { return false; }
bool CheckProto_5(const Context&, const bool) { return false; }
}  // namespace proto
}  // namespace opentxs
