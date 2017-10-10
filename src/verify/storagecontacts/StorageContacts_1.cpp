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

bool CheckProto_1(const StorageContacts& contact, const bool silent)
{
    for (auto& merge : contact.merge()) {
        try {
            const bool valid = Check(
                merge,
                StorageContactsAllowedList.at(contact.version()).first,
                StorageContactsAllowedList.at(contact.version()).second,
                silent);

            if (!valid) {
                FAIL("contact storage index", "invalid merge")
            }
        } catch (const std::out_of_range&) {
            FAIL2(
                "contact storage index",
                "allowed storage id list version not defined for version",
                contact.version())
        }
    }

    for (auto& hash : contact.contact()) {
        try {
            const bool valid = Check(
                hash,
                StorageContactsAllowedHash.at(contact.version()).first,
                StorageContactsAllowedHash.at(contact.version()).second,
                silent);

            if (!valid) {
                FAIL("contact storage index", "invalid hash")
            }
        } catch (const std::out_of_range&) {
            FAIL2(
                "contact storage index",
                "allowed storage item hash version not defined for version",
                contact.version())
        }
    }

    for (auto& index : contact.address()) {
        try {
            const bool valid = Check(
                index,
                StorageContactsAllowedAddress.at(contact.version()).first,
                StorageContactsAllowedAddress.at(contact.version()).second,
                silent);

            if (!valid) {
                FAIL("contact storage index", "invalid address index")
            }
        } catch (const std::out_of_range&) {
            FAIL2(
                "contact storage index",
                "allowed address index version not defined for version",
                contact.version())
        }
    }

    return true;
}

bool CheckProto_2(const StorageContacts&, const bool silent)
{
    UNDEFINED_VERSION("contact storage index", 2)
}

bool CheckProto_3(const StorageContacts&, const bool silent)
{
    UNDEFINED_VERSION("contact storage index", 3)
}

bool CheckProto_4(const StorageContacts&, const bool silent)
{
    UNDEFINED_VERSION("contact storage index", 4)
}

bool CheckProto_5(const StorageContacts&, const bool silent)
{
    UNDEFINED_VERSION("contact storage index", 5)
}
}  // namespace proto
}  // namespace opentxs
