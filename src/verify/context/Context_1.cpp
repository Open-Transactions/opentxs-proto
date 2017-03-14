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

namespace opentxs { namespace proto
{
bool CheckProto_1(const Context& context)
{
    if (!context.has_localnym()) {
        std::cerr << "Verify context failed: missing local nym." << std::endl;

        return false;
    }

    if ((MIN_PLAUSIBLE_IDENTIFIER > context.localnym().size()) ||
        (MAX_PLAUSIBLE_IDENTIFIER < context.localnym().size())) {
            std::cerr << "Verify context failed: invalid local nym."
                    << std::endl;

            return false;
    }

    if (!context.has_remotenym()) {
        std::cerr << "Verify context failed: missing remote nym." << std::endl;

        return false;
    }

    if ((MIN_PLAUSIBLE_IDENTIFIER > context.remotenym().size()) ||
        (MAX_PLAUSIBLE_IDENTIFIER < context.remotenym().size())) {
            std::cerr << "Verify context failed: invalid remote nym."
                    << std::endl;

            return false;
    }

    if (!context.has_type()) {
        std::cerr << "Verify context failed: missing type." << std::endl;

        return false;
    }

    switch (context.type()) {
        case CONSENSUSTYPE_SERVER : {
            if (!context.has_servercontext()) {
                std::cerr << "Verify context failed: missing server data."
                          << std::endl;

                return false;
            }

            if (context.has_clientcontext()) {
                std::cerr << "Verify context failed: client data in server "
                          << "context." << std::endl;

                return false;
            }

            const bool validServer = Check(
                context.servercontext(),
                ContextAllowedServer.at(context.version()).first,
                ContextAllowedServer.at(context.version()).second);

            if (!validServer) {
                std::cerr << "Verify context failed: invalid server data."
                          << std::endl;

                return false;
            }
        } break;
        case CONSENSUSTYPE_CLIENT : {
            if (!context.has_clientcontext()) {
                std::cerr << "Verify context failed: missing client data."
                          << std::endl;

                return false;
            }

            if (context.has_servercontext()) {
                std::cerr << "Verify context failed: client data in server "
                          << "context." << std::endl;

                return false;
            }

            const bool validClient = Check(
                context.clientcontext(),
                ContextAllowedClient.at(context.version()).first,
                ContextAllowedClient.at(context.version()).second);

            if (!validClient) {
                std::cerr << "Verify context failed: invalid client data."
                          << std::endl;

                return false;
            }
        } break;
        default : {
            std::cerr << "Verify context failed: invalid type." << std::endl;

            return false;
        }
    }

    if (!context.has_signature()) {
        std::cerr << "Verify context failed: missing signature." << std::endl;

        return false;
    }

    const bool validSig = Check(
        context.signature(),
        ContextAllowedSignature.at(context.version()).first,
        ContextAllowedSignature.at(context.version()).first,
        SIGROLE_CONTEXT);

    if (!validSig) {
        std::cerr << "Verify context failed: invalid signature." << std::endl;

        return false;
    }

    return true;
}

bool CheckProto_2(const Context&) { return false; }
bool CheckProto_3(const Context&) { return false; }
bool CheckProto_4(const Context&) { return false; }
bool CheckProto_5(const Context&) { return false; }
} // namespace proto
} // namespace opentxs
