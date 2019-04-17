// Copyright (c) 2018 The Open-Transactions developers
// This Source Code Form is subject to the terms of the Mozilla Public
// License, v. 2.0. If a copy of the MPL was not distributed with this
// file, You can obtain one at http://mozilla.org/MPL/2.0/.

#include "opentxs-proto/Types.hpp"
#include "opentxs-proto/Check.hpp"

#define PROTO_NAME "nym id source"

namespace opentxs
{
namespace proto
{

bool CheckProto_1(const NymIDSource& input, const bool silent)
{
    if (!input.has_type()) { FAIL_1("missing type") }

    bool validSourcePubkey{false};
    bool validPaymentCode{false};

    switch (input.type()) {
        case SOURCETYPE_PUBKEY:
            if (!input.has_key()) { FAIL_1("missing key") }

            if (input.has_paymentcode()) {
                FAIL_1("pubkey source includes payment code")
            }

            try {
                validSourcePubkey = Check(
                    input.key(),
                    NymIDSourceAllowedAsymmetricKey.at(input.version()).first,
                    NymIDSourceAllowedAsymmetricKey.at(input.version()).second,
                    silent,
                    CREDTYPE_LEGACY,
                    KEYMODE_PUBLIC,
                    KEYROLE_SIGN);

                if (!validSourcePubkey) { FAIL_1("invalid public key") }
            } catch (const std::out_of_range&) {
                FAIL_2(
                    "allowed asymmetric key version not defined for version",
                    input.version())
            }

            break;
        case SOURCETYPE_BIP47:
            if (!input.has_paymentcode()) { FAIL_1("missing payment code") }

            if (input.has_key()) { FAIL_1("bip47 source includes public key") }

            try {
                validPaymentCode = Check(
                    input.paymentcode(),
                    NymIDSourceAllowedPaymentCode.at(input.version()).first,
                    NymIDSourceAllowedPaymentCode.at(input.version()).second,
                    silent);

                if (!validPaymentCode) { FAIL_1("invalid payment code") }
            } catch (const std::out_of_range&) {
                FAIL_2(
                    "allowed payment code version not defined for version",
                    input.version())
            }

            break;
        default:
            FAIL_2("incorrect or unknown type", input.type())
    }

    return true;
}

bool CheckProto_2(const NymIDSource& input, const bool silent)
{
    return CheckProto_1(input, silent);
}

bool CheckProto_3(const NymIDSource& input, const bool silent)
{
    UNDEFINED_VERSION(3)
}

bool CheckProto_4(const NymIDSource& input, const bool silent)
{
    UNDEFINED_VERSION(4)
}

bool CheckProto_5(const NymIDSource& input, const bool silent)
{
    UNDEFINED_VERSION(5)
}

bool CheckProto_6(const NymIDSource& input, const bool silent)
{
    UNDEFINED_VERSION(6)
}

bool CheckProto_7(const NymIDSource& input, const bool silent)
{
    UNDEFINED_VERSION(7)
}

bool CheckProto_8(const NymIDSource& input, const bool silent)
{
    UNDEFINED_VERSION(8)
}

bool CheckProto_9(const NymIDSource& input, const bool silent)
{
    UNDEFINED_VERSION(9)
}

bool CheckProto_10(const NymIDSource& input, const bool silent)
{
    UNDEFINED_VERSION(10)
}

bool CheckProto_11(const NymIDSource& input, const bool silent)
{
    UNDEFINED_VERSION(11)
}

bool CheckProto_12(const NymIDSource& input, const bool silent)
{
    UNDEFINED_VERSION(12)
}

bool CheckProto_13(const NymIDSource& input, const bool silent)
{
    UNDEFINED_VERSION(13)
}

bool CheckProto_14(const NymIDSource& input, const bool silent)
{
    UNDEFINED_VERSION(14)
}

bool CheckProto_15(const NymIDSource& input, const bool silent)
{
    UNDEFINED_VERSION(15)
}

bool CheckProto_16(const NymIDSource& input, const bool silent)
{
    UNDEFINED_VERSION(16)
}

bool CheckProto_17(const NymIDSource& input, const bool silent)
{
    UNDEFINED_VERSION(17)
}

bool CheckProto_18(const NymIDSource& input, const bool silent)
{
    UNDEFINED_VERSION(18)
}

bool CheckProto_19(const NymIDSource& input, const bool silent)
{
    UNDEFINED_VERSION(19)
}

bool CheckProto_20(const NymIDSource& input, const bool silent)
{
    UNDEFINED_VERSION(20)
}
}  // namespace proto
}  // namespace opentxs
