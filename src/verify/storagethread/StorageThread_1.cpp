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

namespace opentxs { namespace proto
{

bool CheckProto_1(const StorageThread& thread)
{
    if (!thread.has_id()) {
        std::cerr << "Verify serialized storage thread failed: missing "
                  << "identifier." << std::endl;

        return false;
    }

    if (MIN_PLAUSIBLE_IDENTIFIER > thread.id().size()) {
        std::cerr << "Verify serialized storage thread failed: invalid "
                  << "identifier." << std::endl;

        return false;
    }

    for (auto& nym: thread.participant()) {
        if (MIN_PLAUSIBLE_IDENTIFIER > nym.size()) {
            std::cerr << "Verify serialized storage thread failed: invalid "
                      << "participant." << std::endl;

            return false;
        }
    }

    switch (thread.participant_size()) {
        case 0 : {
                std::cerr << "Verify serialized storage thread failed: no "
                          << "participants." << std::endl;

                return false;
        } break;
        case 1 : {
            if (thread.id() != thread.participant(0)) {
                std::cerr << "Verify serialized storage thread failed: "
                          << "incorrect id." << std::endl;

                return false;
            }
        } break;
        default : {}
    }

    for (auto& item: thread.item()) {
        if (!Check(
            item,
            StorageThreadAllowedItem.at(thread.version()).first,
            StorageThreadAllowedItem.at(thread.version()).second)) {
                std::cerr << "Verify serialized storage thread failed: invalid "
                          << "item." << std::endl;

                return false;
        }
    }

    return true;
}

bool CheckProto_2(const StorageThread& nymList) { return false; }
bool CheckProto_3(const StorageThread& nymList) { return false; }
bool CheckProto_4(const StorageThread& nymList) { return false; }
bool CheckProto_5(const StorageThread& nymList) { return false; }
} // namespace proto
} // namespace opentxs
