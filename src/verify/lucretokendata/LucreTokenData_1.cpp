// Copyright (c) 2020 The Open-Transactions developers
// This Source Code Form is subject to the terms of the Mozilla Public
// License, v. 2.0. If a copy of the MPL was not distributed with this
// file, You can obtain one at http://mozilla.org/MPL/2.0/.

#include "opentxs-proto/Types.hpp"
#include "verify/Check.hpp"

#define PROTO_NAME "lucre token data"

namespace opentxs
{
namespace proto
{
bool CheckProto_1(
    const LucreTokenData& input,
    const bool silent,
    const TokenState state)
{
    switch (state) {
        case TokenState::TOKENSTATE_BLINDED: {
            CHECK_SUBOBJECT_VA(
                privateprototoken, LucreTokenDataAllowedCiphertext(), true);
            CHECK_SUBOBJECT_VA(
                publicprototoken, LucreTokenDataAllowedCiphertext(), true);
            CHECK_EXCLUDED(signature);
            CHECK_EXCLUDED(spendable);
        } break;
        case TokenState::TOKENSTATE_SIGNED: {
            CHECK_SUBOBJECT_VA(
                privateprototoken, LucreTokenDataAllowedCiphertext(), true);
            CHECK_SUBOBJECT_VA(
                publicprototoken, LucreTokenDataAllowedCiphertext(), true);
            CHECK_EXISTS(signature);
            CHECK_EXCLUDED(spendable);
        } break;
        case TokenState::TOKENSTATE_READY: {
            CHECK_EXCLUDED(privateprototoken);
            CHECK_EXCLUDED(publicprototoken);
            CHECK_EXCLUDED(signature);
            CHECK_SUBOBJECT_VA(
                spendable, LucreTokenDataAllowedCiphertext(), true);
        } break;
        case TokenState::TOKENSTATE_SPENT: {
            CHECK_EXCLUDED(privateprototoken);
            CHECK_EXCLUDED(publicprototoken);
            CHECK_EXCLUDED(signature);
            CHECK_SUBOBJECT_VA(
                spendable, LucreTokenDataAllowedCiphertext(), true);
        } break;
        case TokenState::TOKENSTATE_EXPIRED: {
            OPTIONAL_SUBOBJECT_VA(
                privateprototoken, LucreTokenDataAllowedCiphertext(), true);
            OPTIONAL_SUBOBJECT_VA(
                publicprototoken, LucreTokenDataAllowedCiphertext(), true);
            OPTIONAL_SUBOBJECT_VA(
                spendable, LucreTokenDataAllowedCiphertext(), true);
        } break;
        case TokenState::TOKENSTATE_ERROR:
        default: {
            FAIL_2("Invalid state", std::to_string(state));
        }
    }

    return true;
}
bool CheckProto_2(
    const LucreTokenData& input,
    const bool silent,
    const TokenState)
{
    UNDEFINED_VERSION(2)
}

bool CheckProto_3(
    const LucreTokenData& input,
    const bool silent,
    const TokenState)
{
    UNDEFINED_VERSION(3)
}

bool CheckProto_4(
    const LucreTokenData& input,
    const bool silent,
    const TokenState)
{
    UNDEFINED_VERSION(4)
}

bool CheckProto_5(
    const LucreTokenData& input,
    const bool silent,
    const TokenState)
{
    UNDEFINED_VERSION(5)
}

bool CheckProto_6(
    const LucreTokenData& input,
    const bool silent,
    const TokenState)
{
    UNDEFINED_VERSION(6)
}

bool CheckProto_7(
    const LucreTokenData& input,
    const bool silent,
    const TokenState)
{
    UNDEFINED_VERSION(7)
}

bool CheckProto_8(
    const LucreTokenData& input,
    const bool silent,
    const TokenState)
{
    UNDEFINED_VERSION(8)
}

bool CheckProto_9(
    const LucreTokenData& input,
    const bool silent,
    const TokenState)
{
    UNDEFINED_VERSION(9)
}

bool CheckProto_10(
    const LucreTokenData& input,
    const bool silent,
    const TokenState)
{
    UNDEFINED_VERSION(10)
}

bool CheckProto_11(
    const LucreTokenData& input,
    const bool silent,
    const TokenState)
{
    UNDEFINED_VERSION(11)
}

bool CheckProto_12(
    const LucreTokenData& input,
    const bool silent,
    const TokenState)
{
    UNDEFINED_VERSION(12)
}

bool CheckProto_13(
    const LucreTokenData& input,
    const bool silent,
    const TokenState)
{
    UNDEFINED_VERSION(13)
}

bool CheckProto_14(
    const LucreTokenData& input,
    const bool silent,
    const TokenState)
{
    UNDEFINED_VERSION(14)
}

bool CheckProto_15(
    const LucreTokenData& input,
    const bool silent,
    const TokenState)
{
    UNDEFINED_VERSION(15)
}

bool CheckProto_16(
    const LucreTokenData& input,
    const bool silent,
    const TokenState)
{
    UNDEFINED_VERSION(16)
}

bool CheckProto_17(
    const LucreTokenData& input,
    const bool silent,
    const TokenState)
{
    UNDEFINED_VERSION(17)
}

bool CheckProto_18(
    const LucreTokenData& input,
    const bool silent,
    const TokenState)
{
    UNDEFINED_VERSION(18)
}

bool CheckProto_19(
    const LucreTokenData& input,
    const bool silent,
    const TokenState)
{
    UNDEFINED_VERSION(19)
}

bool CheckProto_20(
    const LucreTokenData& input,
    const bool silent,
    const TokenState)
{
    UNDEFINED_VERSION(20)
}
}  // namespace proto
}  // namespace opentxs
