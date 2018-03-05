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
#include <sstream>

#ifdef ANDROID
#include <android/log.h>
#endif

#ifdef ANDROID
#define WRITE_LOG()                                                            \
    {                                                                          \
        __android_log_write(                                                   \
            ANDROID_LOG_INFO, "opentxs-proto", out.str().c_str());             \
    }
#else
#define WRITE_LOG()                                                            \
    {                                                                          \
        std::cerr << out.str();                                                \
    }
#endif

#define FAIL(a, b)                                                             \
    {                                                                          \
        if (false == silent) {                                                 \
            std::stringstream out{};                                           \
            out << "Verify version " << input.version() << " " << a            \
                << " failed: " << b << std::endl;                              \
            WRITE_LOG()                                                        \
        }                                                                      \
                                                                               \
        return false;                                                          \
    }

#define FAIL2(a, b, c)                                                         \
    {                                                                          \
        if (false == silent) {                                                 \
            std::stringstream out{};                                           \
            out << "Verify version " << input.version() << " " << a            \
                << " failed: " << b << "(" << c << ")." << std::endl;          \
            WRITE_LOG()                                                        \
        }                                                                      \
                                                                               \
        return false;                                                          \
    }

#define FAIL3(a, b, c, d, e)                                                   \
    {                                                                          \
        if (false == silent) {                                                 \
            std::stringstream out{};                                           \
            out << "Verify version " << input.version() << " " << a            \
                << " failed: " << b << "(" << c << ")" << d << "(" << e << ")" \
                << std::endl;                                                  \
            WRITE_LOG()                                                        \
        }                                                                      \
                                                                               \
        return false;                                                          \
    }

#define FAIL4(b)                                                               \
    {                                                                          \
        if (false == silent) {                                                 \
            std::stringstream out{};                                           \
            out << "Verify version " << input.version() << " " << PROTO_NAME   \
                << " failed: " << b << std::endl;                              \
            WRITE_LOG()                                                        \
        }                                                                      \
                                                                               \
        return false;                                                          \
    }

#define FAIL5(b, c)                                                            \
    {                                                                          \
        if (false == silent) {                                                 \
            std::stringstream out{};                                           \
            out << "Verify version " << input.version() << " " << PROTO_NAME   \
                << " failed: " << b << "(" << c << ")." << std::endl;          \
            WRITE_LOG()                                                        \
        }                                                                      \
                                                                               \
        return false;                                                          \
    }

#define FAIL6(b, c, d, e)                                                      \
    {                                                                          \
        if (false == silent) {                                                 \
            std::stringstream out{};                                           \
            out << "Verify version " << input.version() << " " << PROTO_NAME   \
                << " failed: " << b << "(" << c << ")" << d << "(" << e << ")" \
                << std::endl;                                                  \
            WRITE_LOG()                                                        \
        }                                                                      \
                                                                               \
        return false;                                                          \
    }

#define UNDEFINED_VERSION(a, b)                                                \
    {                                                                          \
        FAIL2(a, "undefined version", b)                                       \
    }

#define UNDEFINED_VERSION2(b)                                                  \
    {                                                                          \
        FAIL2(PROTO_NAME, "undefined version", b)                              \
    }

#define CHECK_EXISTS(a)                                                        \
    {                                                                          \
        if (false == input.has_##a()) {                                        \
            FAIL4("missing ##a")                                               \
        }                                                                      \
    }

#define CHECK_EXCLUDED(a)                                                      \
    {                                                                          \
        if (true == input.has_##a()) {                                         \
            FAIL4("unexpected ##a present")                                    \
        }                                                                      \
    }

#define CHECK_NONE(a)                                                          \
    {                                                                          \
        if (0 < input.a().size()) {                                            \
            FAIL4("unexpected ##a present")                                    \
        }                                                                      \
    }

#define CHECK_IDENTIFIER(a)                                                    \
    {                                                                          \
        CHECK_EXISTS(a)                                                        \
                                                                               \
        if ((MIN_PLAUSIBLE_IDENTIFIER > input.a().size()) ||                   \
            (MAX_PLAUSIBLE_IDENTIFIER < input.a().size())) {                   \
            const auto fail = std::string("invalid ") + #a + " size";          \
            FAIL5(fail, input.a().size())                                      \
        }                                                                      \
    }

#define OPTIONAL_IDENTIFIER(a)                                                 \
    {                                                                          \
        if (true == input.has_##a()) {                                         \
            if ((MIN_PLAUSIBLE_IDENTIFIER > input.a().size()) ||               \
                (MAX_PLAUSIBLE_IDENTIFIER < input.a().size())) {               \
                const auto fail = std::string("invalid ") + #a + " size";      \
                                                                               \
                if (0 != input.a().size()) {                                   \
                    FAIL5(fail, input.a().size())                              \
                }                                                              \
            }                                                                  \
        }                                                                      \
    }

#define CHECK_SUBOBJECT0(a, b, c)                                              \
    {                                                                          \
        CHECK_EXISTS(a)                                                        \
                                                                               \
        try {                                                                  \
            const bool valid##a = Check(                                       \
                input.a(),                                                     \
                b.at(input.version()).first,                                   \
                b.at(input.version()).second,                                  \
                c);                                                            \
                                                                               \
            if (false == valid##a) {                                           \
                const auto fail = std::string("invalid ") + #a;                \
                FAIL4(fail)                                                    \
            }                                                                  \
        } catch (const std::out_of_range&) {                                   \
            const auto fail = std::string("allowed ") + #a +                   \
                              " version not defined for version";              \
            FAIL5(fail, input.version())                                       \
        }                                                                      \
    }

#define CHECK_SUBOBJECT(a, b)                                                  \
    {                                                                          \
        CHECK_SUBOBJECT0(a, b, "silent")                                       \
    }

#define CHECK_SUBOBJECT2(a, b, c)                                              \
    {                                                                          \
        CHECK_SUBOBJECT0(a, b, "silent##c")                                    \
    }

#define CHECK_SUBOBJECTS(a, b)                                                 \
    {                                                                          \
        for (const auto& it : input.a()) {                                     \
            try {                                                              \
                const bool valid##a = Check(                                   \
                    it,                                                        \
                    b.at(input.version()).first,                               \
                    b.at(input.version()).second,                              \
                    silent);                                                   \
                                                                               \
                if (false == valid##a) {                                       \
                    FAIL4("invalid ##a")                                       \
                }                                                              \
            } catch (const std::out_of_range&) {                               \
                const auto fail = std::string("allowed ") + #a +               \
                                  " version not defined for version";          \
                FAIL5(fail, input.version())                                   \
            }                                                                  \
        }                                                                      \
    }

#define OPTIONAL_SUBOBJECT0(a, b, c)                                           \
    {                                                                          \
        if (input.has_##a()) {                                                 \
            try {                                                              \
                const bool valid##a = Check(                                   \
                    input.a(),                                                 \
                    b.at(input.version()).first,                               \
                    b.at(input.version()).second,                              \
                    c);                                                        \
                                                                               \
                if (false == valid##a) {                                       \
                    const auto fail = std::string("invalid ") + #a;            \
                    FAIL4(fail)                                                \
                }                                                              \
            } catch (const std::out_of_range&) {                               \
                const auto fail = std::string("allowed ") + #a +               \
                                  " version not defined for version";          \
                FAIL5(fail, input.version())                                   \
            }                                                                  \
        }                                                                      \
    }

#define OPTIONAL_SUBOBJECT(a, b)                                               \
    {                                                                          \
        OPTIONAL_SUBOBJECT0(a, b, "silent")                                    \
    }

namespace opentxs
{
namespace proto
{
template <typename T, typename... Args>
bool Check(
    const T& input,
    const std::uint32_t minVersion,
    const std::uint32_t maxVersion,
    const bool silent,
    Args&&... params)
{
    if (!input.has_version()) {
        FAIL("protobuf", "missing version.")
    }

    const std::uint32_t version = input.version();

    if ((version < minVersion) || (version > maxVersion)) {
        FAIL2("protobuf", "incorrect version", input.version())
    }

    switch (version) {
        case 1: {
            return CheckProto_1(input, silent, params...);
        }
        case 2: {
            return CheckProto_2(input, silent, params...);
        }
        case 3: {
            return CheckProto_3(input, silent, params...);
        }
        case 4: {
            return CheckProto_4(input, silent, params...);
        }
        case 5: {
            return CheckProto_5(input, silent, params...);
        }
        case 6: {
            return CheckProto_6(input, silent, params...);
        }
        case 7: {
            return CheckProto_7(input, silent, params...);
        }
        case 8: {
            return CheckProto_8(input, silent, params...);
        }
        case 9: {
            return CheckProto_9(input, silent, params...);
        }
        case 10: {
            return CheckProto_10(input, silent, params...);
        }
        case 11: {
            return CheckProto_11(input, silent, params...);
        }
        case 12: {
            return CheckProto_12(input, silent, params...);
        }
        case 13: {
            return CheckProto_13(input, silent, params...);
        }
        case 14: {
            return CheckProto_14(input, silent, params...);
        }
        case 15: {
            return CheckProto_15(input, silent, params...);
        }
        case 16: {
            return CheckProto_16(input, silent, params...);
        }
        case 17: {
            return CheckProto_17(input, silent, params...);
        }
        case 18: {
            return CheckProto_18(input, silent, params...);
        }
        case 19: {
            return CheckProto_19(input, silent, params...);
        }
        case 20: {
            return CheckProto_20(input, silent, params...);
        }
        default: {
            FAIL2("protobuf", "unknown version", input.version())
        }
    }

    return true;
}

template <typename T, typename... Args>
bool Validate(const T& input, const bool silent, Args&&... params)
{

    if (!input.has_version()) {
        FAIL("protobuf", "missing version")
    }

    const std::uint32_t version = input.version();

    return Check<T>(input, version, version, silent, params...);
}
}  // namespace proto
}  // namespace opentxs
#endif  // OPENTXS_PROTO_VERIFY
