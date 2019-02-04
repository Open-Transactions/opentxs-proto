// Copyright (c) 2018 The Open-Transactions developers
// This Source Code Form is subject to the terms of the Mozilla Public
// License, v. 2.0. If a copy of the MPL was not distributed with this
// file, You can obtain one at http://mozilla.org/MPL/2.0/.

#ifndef OPENTXS_PROTO_VERIFY
#define OPENTXS_PROTO_VERIFY

#include <cstdint>
#include <iostream>
#include <sstream>

#ifdef ANDROID
#include <android/log.h>
#endif

#ifdef ANDROID
#define _WRITE_LOG()                                                           \
    {                                                                          \
        __android_log_write(                                                   \
            ANDROID_LOG_INFO, "opentxs-proto", out.str().c_str());             \
    }
#else
#define _WRITE_LOG()                                                           \
    {                                                                          \
        std::cerr << out.str();                                                \
    }
#endif

#define _FAIL_1(a, b)                                                          \
    {                                                                          \
        if (false == silent) {                                                 \
            std::stringstream out{};                                           \
            out << "Verify version " << input.version() << " " << a            \
                << " failed: " << b << std::endl;                              \
            _WRITE_LOG()                                                       \
        }                                                                      \
                                                                               \
        return false;                                                          \
    }

#define _FAIL_2(a, b, c)                                                       \
    {                                                                          \
        if (false == silent) {                                                 \
            std::stringstream out{};                                           \
            out << "Verify version " << input.version() << " " << a            \
                << " failed: " << b << "(" << c << ")." << std::endl;          \
            _WRITE_LOG()                                                       \
        }                                                                      \
                                                                               \
        return false;                                                          \
    }

#define FAIL_1(b)                                                              \
    {                                                                          \
        _FAIL_1(PROTO_NAME, b);                                                \
    }

#define FAIL_2(b, c)                                                           \
    {                                                                          \
        if (false == silent) {                                                 \
            std::stringstream out{};                                           \
            out << "Verify version " << input.version() << " " << PROTO_NAME   \
                << " failed: " << b << "(" << c << ")." << std::endl;          \
            _WRITE_LOG()                                                       \
        }                                                                      \
                                                                               \
        return false;                                                          \
    }

#define FAIL_4(b, c, d, e)                                                     \
    {                                                                          \
        if (false == silent) {                                                 \
            std::stringstream out{};                                           \
            out << "Verify version " << input.version() << " " << PROTO_NAME   \
                << " failed: " << b << "(" << c << ")" << d << "(" << e << ")" \
                << std::endl;                                                  \
            _WRITE_LOG()                                                       \
        }                                                                      \
                                                                               \
        return false;                                                          \
    }

#define FAIL_6(b, c, d, e, f, g)                                               \
    {                                                                          \
        if (false == silent) {                                                 \
            std::stringstream out{};                                           \
            out << "Verify version " << input.version() << " " << PROTO_NAME   \
                << " failed: " << b << "(" << c << ")" << d << "(" << e << ")" \
                << f << "(" << g << ")" << std::endl;                          \
            _WRITE_LOG()                                                       \
        }                                                                      \
                                                                               \
        return false;                                                          \
    }

#define UNDEFINED_VERSION(b)                                                   \
    {                                                                          \
        _FAIL_2(PROTO_NAME, "undefined version", b)                            \
    }

#define CHECK_EXISTS(a)                                                        \
    {                                                                          \
        if (false == input.has_##a()) {                                        \
            const auto fail = std::string("missing ") + #a;                    \
            FAIL_1(fail)                                                       \
        }                                                                      \
    }

#define CHECK_EXISTS_STRING(a)                                                 \
    {                                                                          \
        if ((false == input.has_##a()) || (0 == input.a().size())) {           \
            const auto fail = std::string("missing ") + #a;                    \
            FAIL_1(fail)                                                       \
        }                                                                      \
    }

#define CHECK_EXCLUDED(a)                                                      \
    {                                                                          \
        if (true == input.has_##a()) {                                         \
            const auto fail = std::string("unexpected ") + #a + " present";    \
            FAIL_1(fail)                                                       \
        }                                                                      \
    }

#define CHECK_HAVE(a)                                                          \
    {                                                                          \
        if (0 == input.a().size()) {                                           \
            const auto fail = std::string("missing ") + #a;                    \
            FAIL_1(fail)                                                       \
        }                                                                      \
    }

#define CHECK_NONE(a)                                                          \
    {                                                                          \
        if (0 < input.a().size()) {                                            \
            const auto fail = std::string("unexpected ") + #a + " present";    \
            FAIL_1(fail)                                                       \
        }                                                                      \
    }

#define CHECK_SIZE(a, b)                                                       \
    {                                                                          \
        if (b != input.a().size()) {                                           \
            const auto fail =                                                  \
                std::string("Wrong number of ") + #a + " present ";            \
            FAIL_2(fail, input.a().size());                                    \
        }                                                                      \
    }

#define _CHECK_STRING(a, min, max)                                             \
    {                                                                          \
        if (input.has_##a() && (0 < input.a().size())) {                       \
            if ((min > input.a().size()) || (max < input.a().size())) {        \
                const auto fail = std::string("invalid ") + #a + " size";      \
                FAIL_2(fail, input.a().size())                                 \
            }                                                                  \
        }                                                                      \
    }

#define OPTIONAL_IDENTIFIER(a)                                                 \
    {                                                                          \
        _CHECK_STRING(a, MIN_PLAUSIBLE_IDENTIFIER, MAX_PLAUSIBLE_IDENTIFIER);  \
    }

#define CHECK_IDENTIFIER(a)                                                    \
    {                                                                          \
        CHECK_EXISTS_STRING(a);                                                \
        OPTIONAL_IDENTIFIER(a);                                                \
    }

#define OPTIONAL_IDENTIFIERS(a)                                                \
    {                                                                          \
        for (const auto& it : input.a()) {                                     \
            if ((MIN_PLAUSIBLE_IDENTIFIER > it.size()) ||                      \
                (MAX_PLAUSIBLE_IDENTIFIER < it.size())) {                      \
                const auto fail = std::string("invalid ") + #a + " size";      \
                FAIL_2(fail, it.size())                                        \
            }                                                                  \
        }                                                                      \
    }

#define CHECK_IDENTIFIERS(a)                                                   \
    {                                                                          \
        /* CHECK_EXISTS(a); */                                                 \
        OPTIONAL_IDENTIFIERS(a);                                               \
    }

#define OPTIONAL_KEY(a)                                                        \
    {                                                                          \
        _CHECK_STRING(a, MIN_PLAUSIBLE_KEYSIZE, MAX_PLAUSIBLE_KEYSIZE);        \
    }

#define CHECK_KEY(a)                                                           \
    {                                                                          \
        CHECK_EXISTS_STRING(a);                                                \
        OPTIONAL_KEY(a);                                                       \
    }

#define OPTIONAL_NAME(a)                                                       \
    {                                                                          \
        _CHECK_STRING(a, 1, MAX_VALID_CONTACT_VALUE);                          \
    }

#define CHECK_NAME(a)                                                          \
    {                                                                          \
        CHECK_EXISTS_STRING(a);                                                \
        OPTIONAL_NAME(a);                                                      \
    }

#define OPTIONAL_NAMES(a)                                                      \
    {                                                                          \
        for (const auto& it : input.a()) {                                     \
            if ((1 > it.size()) || (MAX_VALID_CONTACT_VALUE < it.size())) {    \
                const auto fail = std::string("invalid ") + #a + " size";      \
                FAIL_2(fail, it.size())                                        \
            }                                                                  \
        }                                                                      \
    }

#define CHECK_NAMES(a)                                                         \
    {                                                                          \
        CHECK_EXISTS(a);                                                       \
        OPTIONAL_IDENTIFIERS(a);                                               \
    }

#define _CHECK_SUBOBJECT(a, b, ...)                                            \
    {                                                                          \
        if (input.has_##a()) {                                                 \
            try {                                                              \
                const bool valid##a = Check(                                   \
                    input.a(),                                                 \
                    b.at(input.version()).first,                               \
                    b.at(input.version()).second,                              \
                    __VA_ARGS__);                                              \
                                                                               \
                if (false == valid##a) {                                       \
                    const auto fail = std::string("invalid ") + #a;            \
                    FAIL_1(fail)                                               \
                }                                                              \
            } catch (const std::out_of_range&) {                               \
                const auto fail = std::string("allowed ") + #a +               \
                                  " version not defined for version";          \
                FAIL_2(fail, input.version())                                  \
            }                                                                  \
        }                                                                      \
    }

#define OPTIONAL_SUBOBJECT(a, b)                                               \
    {                                                                          \
        _CHECK_SUBOBJECT(a, b, silent);                                        \
    }

#define CHECK_SUBOBJECT(a, b)                                                  \
    {                                                                          \
        CHECK_EXISTS(a);                                                       \
        OPTIONAL_SUBOBJECT(a, b);                                              \
    }

#define OPTIONAL_SUBOBJECT_VA(a, b, ...)                                       \
    {                                                                          \
        _CHECK_SUBOBJECT(a, b, silent, __VA_ARGS__);                           \
    }

#define CHECK_SUBOBJECT_VA(a, b, ...)                                          \
    {                                                                          \
        CHECK_EXISTS(a);                                                       \
        OPTIONAL_SUBOBJECT_VA(a, b, __VA_ARGS__);                              \
    }

#define _CHECK_SUBOBJECTS(a, b, ...)                                           \
    {                                                                          \
        for (const auto& it : input.a()) {                                     \
            try {                                                              \
                const bool valid##a = Check(                                   \
                    it,                                                        \
                    b.at(input.version()).first,                               \
                    b.at(input.version()).second,                              \
                    __VA_ARGS__);                                              \
                                                                               \
                if (false == valid##a) {                                       \
                    const auto fail = std::string("invalid ") + #a;            \
                    FAIL_1(fail)                                               \
                }                                                              \
            } catch (const std::out_of_range&) {                               \
                const auto fail = std::string("allowed ") + #a +               \
                                  " version not defined for version";          \
                FAIL_2(fail, input.version())                                  \
            }                                                                  \
        }                                                                      \
    }

#define OPTIONAL_SUBOBJECTS(a, b)                                              \
    {                                                                          \
        _CHECK_SUBOBJECTS(a, b, silent);                                       \
    }

#define CHECK_SUBOBJECTS(a, b)                                                 \
    {                                                                          \
        /* CHECK_HAVE(a); */                                                   \
        OPTIONAL_SUBOBJECTS(a, b);                                             \
    }

#define OPTIONAL_SUBOBJECTS_VA(a, b, ...)                                      \
    {                                                                          \
        _CHECK_SUBOBJECTS(a, b, silent, __VA_ARGS__);                          \
    }

#define CHECK_SUBOBJECTS_VA(a, b, ...)                                         \
    {                                                                          \
        CHECK_HAVE(a);                                                         \
        OPTIONAL_SUBOBJECTS_VA(a, b, __VA_ARGS__);                             \
    }

#define CHECK_MEMBERSHIP(a, b)                                                 \
    {                                                                          \
        try {                                                                  \
            const bool valid##a = 1 == b.at(input.version()).count(input.a()); \
                                                                               \
            if (false == valid##a) {                                           \
                const auto fail = std::string("invalid ") + #a;                \
                FAIL_2(fail, input.a())                                        \
            }                                                                  \
        } catch (const std::out_of_range&) {                                   \
            const auto fail =                                                  \
                std::string("allowed ") + #a + " not defined for version";     \
            FAIL_2(fail, input.version())                                      \
        }                                                                      \
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
    if (!input.has_version()) { _FAIL_1("protobuf", "missing version.") }

    const std::uint32_t version = input.version();

    if ((version < minVersion) || (version > maxVersion)) {
        _FAIL_2("protobuf", "incorrect version", input.version());
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
            _FAIL_2("protobuf", "unknown version", input.version());
        }
    }

    return true;
}

template <typename T, typename... Args>
bool Validate(const T& input, const bool silent, Args&&... params)
{

    if (!input.has_version()) { _FAIL_1("protobuf", "missing version"); }

    const std::uint32_t version = input.version();

    return Check<T>(input, version, version, silent, params...);
}
}  // namespace proto
}  // namespace opentxs
#endif  // OPENTXS_PROTO_VERIFY
