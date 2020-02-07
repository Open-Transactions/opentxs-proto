// Copyright (c) 2020 The Open-Transactions developers
// This Source Code Form is subject to the terms of the Mozilla Public
// License, v. 2.0. If a copy of the MPL was not distributed with this
// file, You can obtain one at http://mozilla.org/MPL/2.0/.

#include "opentxs-proto/Types.hpp"
#include "verify/Check.hpp"

#define PROTO_NAME "envelope"

namespace opentxs
{
namespace proto
{
const std::map<std::uint32_t, std::set<AsymmetricKeyType>> allowed_types_{
    {1, {AKEYTYPE_LEGACY, AKEYTYPE_SECP256K1, AKEYTYPE_ED25519}},
    {2, {AKEYTYPE_LEGACY, AKEYTYPE_SECP256K1, AKEYTYPE_ED25519}},
};

bool CheckProto_1(const Envelope& input, const bool silent)
{
    CHECK_SUBOBJECTS_VA(
        dhkey,
        EnvelopeAllowedAsymmetricKey(),
        CREDTYPE_LEGACY,
        KEYMODE_PUBLIC,
        KEYROLE_ENCRYPT)
    CHECK_SUBOBJECTS(sessionkey, EnvelopeAllowedTaggedKey())
    CHECK_SUBOBJECT_VA(ciphertext, EnvelopeAllowedCiphertext(), false)

    auto dh = std::map<AsymmetricKeyType, int>{};

    for (const auto& key : input.dhkey()) {
        const auto type = key.type();

        try {
            if (0 == allowed_types_.at(input.version()).count(type)) {
                FAIL_1("Invalid dh key type")
            }
        } catch (...) {
            FAIL_1("Unknown version")
        }

        ++dh[type];
    }

    for (const auto& [type, count] : dh) {
        if ((1 != count) && (AKEYTYPE_LEGACY != type)) {
            FAIL_1("Duplicate dh key type")
        }
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
