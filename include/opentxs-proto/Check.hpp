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

#ifndef OPENTXS_PROTO_VERIFY
#define OPENTXS_PROTO_VERIFY

#include <cstdint>
#include <iostream>

#define FAIL(a, b)                                                             \
    {                                                                          \
        if (false == silent) {                                                 \
            std::cerr << "Verify serialized " << a << " failed: " << b         \
                      << std::endl;                                            \
        }                                                                      \
                                                                               \
        return false;                                                          \
    }

#define FAIL2(a, b, c)                                                         \
    {                                                                          \
        if (false == silent) {                                                 \
            std::cerr << "Verify serialized " << a << " failed: " << b << "("  \
                      << c << ")." << std::endl;                               \
        }                                                                      \
                                                                               \
        return false;                                                          \
    }

#define FAIL3(a, b, c, d, e)                                                   \
    {                                                                          \
        if (false == silent) {                                                 \
            std::cerr << "Verify serialized " << a << " failed: " << b << "("  \
                      << c << ")" << d << "(" << e << ")" << std::endl;        \
        }                                                                      \
                                                                               \
        return false;                                                          \
    }

namespace opentxs
{
namespace proto
{
template <typename T, typename... Args>
bool Check(
    const T& serialized,
    const std::uint32_t minVersion,
    const std::uint32_t maxVersion,
    const bool silent,
    Args&&... params)
{
    if (!serialized.has_version()) {
        FAIL("protobuf", "missing version.")
    }

    const std::uint32_t version = serialized.version();

    if ((version < minVersion) || (version > maxVersion)) {
        FAIL2("protobuf", "incorrect version", serialized.version())
    }

    switch (version) {
        case 1: {
            return CheckProto_1(serialized, silent, params...);
        }
        case 2: {
            return CheckProto_2(serialized, silent, params...);
        }
        case 3: {
            return CheckProto_3(serialized, silent, params...);
        }
        case 4: {
            return CheckProto_4(serialized, silent, params...);
        }
        case 5: {
            return CheckProto_5(serialized, silent, params...);
        }
        default: {
            FAIL2("protobuf", "unknown version", serialized.version())
        }
    }

    return true;
}

template <typename T, typename... Args>
bool Validate(const T& serialized, const bool silent, Args&&... params)
{

    if (!serialized.has_version()) {
        FAIL("protobuf", "missing version")
    }

    const std::uint32_t version = serialized.version();

    return Check<T>(serialized, version, version, silent, params...);
}
}  // namespace proto
}  // namespace opentxs
#endif  // OPENTXS_PROTO_VERIFY
