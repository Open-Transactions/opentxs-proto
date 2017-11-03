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
bool CheckProto_1(const Context& input, const bool silent)
{
    if (!input.has_localnym()) {
        FAIL("context", " missing local nym")
    }

    if ((MIN_PLAUSIBLE_IDENTIFIER > input.localnym().size()) ||
        (MAX_PLAUSIBLE_IDENTIFIER < input.localnym().size())) {
        FAIL("context", "invalid local nym")
    }

    if (!input.has_remotenym()) {
        FAIL("context", "missing remote nym")
    }

    if ((MIN_PLAUSIBLE_IDENTIFIER > input.remotenym().size()) ||
        (MAX_PLAUSIBLE_IDENTIFIER < input.remotenym().size())) {
        FAIL("context", "invalid remote nym")
    }

    if (!input.has_type()) {
        FAIL("context", "missing type")
    }

    switch (input.type()) {
        case CONSENSUSTYPE_SERVER: {
            if (!input.has_servercontext()) {
                FAIL("context", "missing server data")
            }

            if (input.has_clientcontext()) {
                FAIL("context", "client data in server context")
            }

            try {
                const bool validServer = Check(
                    input.servercontext(),
                    ContextAllowedServer.at(input.version()).first,
                    ContextAllowedServer.at(input.version()).second,
                    silent);

                if (!validServer) {
                    FAIL("context", "invalid server data")
                }
            } catch (const std::out_of_range&) {
                FAIL2(
                    "context",
                    "allowed server data version not defined for version",
                    input.version())
            }
        } break;
        case CONSENSUSTYPE_CLIENT: {
            if (!input.has_clientcontext()) {
                FAIL("context", "missing client data")
            }

            if (input.has_servercontext()) {
                FAIL("context", "client data in server context")
            }

            try {
                const bool validClient = Check(
                    input.clientcontext(),
                    ContextAllowedClient.at(input.version()).first,
                    ContextAllowedClient.at(input.version()).second,
                    silent);

                if (!validClient) {
                    FAIL("context", "invalid client data")
                }
            } catch (const std::out_of_range&) {
                FAIL2(
                    "context",
                    "allowed client data version not defined for version",
                    input.version())
            }
        } break;
        default: {
            FAIL("context", "invalid type")
        }
    }

    if (!input.has_signature()) {
        FAIL("context", "missing signature")
    }

    try {
        const bool validSig = Check(
            input.signature(),
            ContextAllowedSignature.at(input.version()).first,
            ContextAllowedSignature.at(input.version()).first,
            silent,
            SIGROLE_CONTEXT);

        if (!validSig) {
            FAIL("context", "invalid signature")
        }
    } catch (const std::out_of_range&) {
        FAIL2(
            "context",
            "allowed signature version not defined for version",
            input.version())
    }

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
