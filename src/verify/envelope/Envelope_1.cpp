// Copyright (c) 2018 The Open-Transactions developers
// This Source Code Form is subject to the terms of the Mozilla Public
// License, v. 2.0. If a copy of the MPL was not distributed with this
// file, You can obtain one at http://mozilla.org/MPL/2.0/.

#include "opentxs-proto/Types.hpp"
#include "opentxs-proto/Check.hpp"

#define PROTO_NAME "envelope"

namespace opentxs
{
namespace proto
{

bool CheckProto_1(const Envelope& input, const bool silent)
{
    for (const auto& dhKey : input.dhkey()) {
        try {
            const bool validDHKey = Check(
                dhKey,
                EnvelopeAllowedAsymmetricKey.at(input.version()).first,
                EnvelopeAllowedAsymmetricKey.at(input.version()).second,
                silent,
                CREDTYPE_LEGACY,
                KEYMODE_PUBLIC,
                KEYROLE_ENCRYPT);

            if (false == validDHKey) { FAIL_1("invalid dhkey") }
        } catch (const std::out_of_range&) {
            FAIL_2(
                "allowed asymmetric key version not defined for version",
                input.version())
        }
    }

    for (const auto& sessionKey : input.sessionkey()) {
        try {
            const bool validSessionKey = Check(
                sessionKey,
                EnvelopeAllowedCiphertext.at(input.version()).first,
                EnvelopeAllowedCiphertext.at(input.version()).second,
                silent);

            if (false == validSessionKey) { FAIL_1("invalid session key") }
        } catch (const std::out_of_range&) {
            FAIL_2(
                "allowed ciphertext version not defined for version",
                input.version())
        }
    }

    try {
        const bool validCiphertext = Check(
            input.ciphertext(),
            EnvelopeAllowedCiphertext.at(input.version()).first,
            EnvelopeAllowedCiphertext.at(input.version()).second,
            silent,
            false);

        if (false == validCiphertext) { FAIL_1("invalid ciphertext") }
    } catch (const std::out_of_range&) {
        FAIL_2(
            "allowed ciphertext version not defined for version",
            input.version())
    }

    return true;
}

bool CheckProto_2(const Envelope& input, const bool silent)
{
    return CheckProto_1(input, silent);
}

bool CheckProto_3(const Envelope& input, const bool silent)
{
    UNDEFINED_VERSION(3)
}

bool CheckProto_4(const Envelope& input, const bool silent)
{
    UNDEFINED_VERSION(4)
}

bool CheckProto_5(const Envelope& input, const bool silent)
{
    UNDEFINED_VERSION(5)
}

bool CheckProto_6(const Envelope& input, const bool silent)
{
    UNDEFINED_VERSION(6)
}

bool CheckProto_7(const Envelope& input, const bool silent)
{
    UNDEFINED_VERSION(7)
}

bool CheckProto_8(const Envelope& input, const bool silent)
{
    UNDEFINED_VERSION(8)
}

bool CheckProto_9(const Envelope& input, const bool silent)
{
    UNDEFINED_VERSION(9)
}

bool CheckProto_10(const Envelope& input, const bool silent)
{
    UNDEFINED_VERSION(10)
}

bool CheckProto_11(const Envelope& input, const bool silent)
{
    UNDEFINED_VERSION(11)
}

bool CheckProto_12(const Envelope& input, const bool silent)
{
    UNDEFINED_VERSION(12)
}

bool CheckProto_13(const Envelope& input, const bool silent)
{
    UNDEFINED_VERSION(13)
}

bool CheckProto_14(const Envelope& input, const bool silent)
{
    UNDEFINED_VERSION(14)
}

bool CheckProto_15(const Envelope& input, const bool silent)
{
    UNDEFINED_VERSION(15)
}

bool CheckProto_16(const Envelope& input, const bool silent)
{
    UNDEFINED_VERSION(16)
}

bool CheckProto_17(const Envelope& input, const bool silent)
{
    UNDEFINED_VERSION(17)
}

bool CheckProto_18(const Envelope& input, const bool silent)
{
    UNDEFINED_VERSION(18)
}

bool CheckProto_19(const Envelope& input, const bool silent)
{
    UNDEFINED_VERSION(19)
}

bool CheckProto_20(const Envelope& input, const bool silent)
{
    UNDEFINED_VERSION(20)
}
}  // namespace proto
}  // namespace opentxs
