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

#define PROTO_NAME "credential index"

namespace opentxs
{
namespace proto
{

bool CheckProto_1(const CredentialIndex& input, const bool silent)
{
    bool validSource = false;

    if (!input.has_nymid()) {
        FAIL("credential index", "missing nym id")
    }

    if (MIN_PLAUSIBLE_IDENTIFIER > input.nymid().size()) {
        FAIL2("credential index", "invalid nym id", input.nymid())
    }

    if (!input.has_mode()) {
        FAIL("credential index", "missing mode")
    }

    const auto actualMode = input.mode();

    if (!input.has_revision()) {
        FAIL("credential index", "missing revision")
    }

    if (1 > input.revision()) {
        FAIL2("credential index", "invalid revision", input.revision())
    }

    if (!input.has_source()) {
        FAIL("credential index", "missing nym id source")
    }

    try {
        validSource = Check(
            input.source(),
            CredentialIndexAllowedNymIDSource.at(input.version()).first,
            CredentialIndexAllowedNymIDSource.at(input.version()).second,
            silent);

        if (!validSource) {
            FAIL("credential index", "invalid nym id source")
        }
    } catch (const std::out_of_range&) {
        FAIL2(
            "credential index",
            "allowed nym ID source version not defined for version",
            input.version())
    }

    bool haveHD = false;

    for (auto& it : input.activecredentials()) {
        try {
            const KeyMode mode = (CREDINDEX_PRIVATE == actualMode)
                                     ? KEYMODE_PRIVATE
                                     : KEYMODE_PUBLIC;
            const bool validSet = Check(
                it,
                CredentialIndexAllowedCredentialSets.at(input.version()).first,
                CredentialIndexAllowedCredentialSets.at(input.version()).second,
                silent,
                input.nymid(),
                mode,
                haveHD);

            if (false == validSet) {
                FAIL("credential index", "invalid credential set")
            }
        } catch (const std::out_of_range&) {
            FAIL2(
                "credential index",
                "allowed credential set version not defined for version",
                input.version())
        }
    }

    for (auto& it : input.revokedcredentials()) {
        try {
            const KeyMode mode = (CREDINDEX_PRIVATE == actualMode)
                                     ? KEYMODE_PRIVATE
                                     : KEYMODE_PUBLIC;
            const bool validSet = Check(
                it,
                CredentialIndexAllowedCredentialSets.at(input.version()).first,
                CredentialIndexAllowedCredentialSets.at(input.version()).second,
                silent,
                input.nymid(),
                mode,
                haveHD);

            if (false == validSet) {
                FAIL("credential index", "invalid credential set")
            }
        } catch (const std::out_of_range&) {
            FAIL2(
                "credential index",
                "allowed credential set version not defined for version",
                input.version())
        }
    }

    switch (actualMode) {
        case (CREDINDEX_PRIVATE): {
            if (haveHD) {
                if (1 > input.index()) {
                    FAIL("credential index", "missing index")
                }
            }

            break;
        }
        case (CREDINDEX_PUBLIC): {
            if (input.has_index()) {
                FAIL("credential index", "index present in public mode")
            }

            break;
        }
        default: {
            FAIL2("credential index", "invalid mode", actualMode)
        }
    }

    return true;
}

bool CheckProto_2(const CredentialIndex& input, const bool silent)
{
    return CheckProto_1(input, silent);
}

bool CheckProto_3(const CredentialIndex& input, const bool silent)
{
    return CheckProto_1(input, silent);
}

bool CheckProto_4(const CredentialIndex& input, const bool silent)
{
    return CheckProto_1(input, silent);
}

bool CheckProto_5(const CredentialIndex& input, const bool silent)
{
    UNDEFINED_VERSION("credential index", 5)
}

bool CheckProto_6(const CredentialIndex& input, const bool silent)
{
    UNDEFINED_VERSION2(6)
}

bool CheckProto_7(const CredentialIndex& input, const bool silent)
{
    UNDEFINED_VERSION2(7)
}

bool CheckProto_8(const CredentialIndex& input, const bool silent)
{
    UNDEFINED_VERSION2(8)
}

bool CheckProto_9(const CredentialIndex& input, const bool silent)
{
    UNDEFINED_VERSION2(9)
}

bool CheckProto_10(const CredentialIndex& input, const bool silent)
{
    UNDEFINED_VERSION2(10)
}

bool CheckProto_11(const CredentialIndex& input, const bool silent)
{
    UNDEFINED_VERSION2(11)
}

bool CheckProto_12(const CredentialIndex& input, const bool silent)
{
    UNDEFINED_VERSION2(12)
}

bool CheckProto_13(const CredentialIndex& input, const bool silent)
{
    UNDEFINED_VERSION2(13)
}

bool CheckProto_14(const CredentialIndex& input, const bool silent)
{
    UNDEFINED_VERSION2(14)
}

bool CheckProto_15(const CredentialIndex& input, const bool silent)
{
    UNDEFINED_VERSION2(15)
}

bool CheckProto_16(const CredentialIndex& input, const bool silent)
{
    UNDEFINED_VERSION2(16)
}

bool CheckProto_17(const CredentialIndex& input, const bool silent)
{
    UNDEFINED_VERSION2(17)
}

bool CheckProto_18(const CredentialIndex& input, const bool silent)
{
    UNDEFINED_VERSION2(18)
}

bool CheckProto_19(const CredentialIndex& input, const bool silent)
{
    UNDEFINED_VERSION2(19)
}

bool CheckProto_20(const CredentialIndex& input, const bool silent)
{
    UNDEFINED_VERSION2(20)
}
}  // namespace proto
}  // namespace opentxs
