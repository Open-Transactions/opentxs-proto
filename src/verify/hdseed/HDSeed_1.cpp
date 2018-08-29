// Copyright (c) 2018 The Open-Transactions developers
// This Source Code Form is subject to the terms of the Mozilla Public
// License, v. 2.0. If a copy of the MPL was not distributed with this
// file, You can obtain one at http://mozilla.org/MPL/2.0/.

#include "opentxs-proto/Types.hpp"
#include "opentxs-proto/Check.hpp"

#define PROTO_NAME "hd seed"

namespace opentxs
{
namespace proto
{

bool CheckProto_1(const HDSeed& input, const bool silent)
{
    OPTIONAL_IDENTIFIER(id);
    CHECK_EXISTS(words);

    // 12 three-letter words
    if (47 > input.words().size()) { FAIL_1("Invalid word list") }

    // 24 eight-letter words
    if (215 < input.words().size()) { FAIL_1("Invalid word list") }

    if (1024 < input.passphrase().size()) { FAIL_1("Invalid passphrase") }

    return true;
}

bool CheckProto_2(const HDSeed& input, const bool silent)
{
    UNDEFINED_VERSION(2)
}

bool CheckProto_3(const HDSeed& input, const bool silent)
{
    UNDEFINED_VERSION(3)
}

bool CheckProto_4(const HDSeed& input, const bool silent)
{
    UNDEFINED_VERSION(4)
}

bool CheckProto_5(const HDSeed& input, const bool silent)
{
    UNDEFINED_VERSION(5)
}

bool CheckProto_6(const HDSeed& input, const bool silent)
{
    UNDEFINED_VERSION(6)
}

bool CheckProto_7(const HDSeed& input, const bool silent)
{
    UNDEFINED_VERSION(7)
}

bool CheckProto_8(const HDSeed& input, const bool silent)
{
    UNDEFINED_VERSION(8)
}

bool CheckProto_9(const HDSeed& input, const bool silent)
{
    UNDEFINED_VERSION(9)
}

bool CheckProto_10(const HDSeed& input, const bool silent)
{
    UNDEFINED_VERSION(10)
}

bool CheckProto_11(const HDSeed& input, const bool silent)
{
    UNDEFINED_VERSION(11)
}

bool CheckProto_12(const HDSeed& input, const bool silent)
{
    UNDEFINED_VERSION(12)
}

bool CheckProto_13(const HDSeed& input, const bool silent)
{
    UNDEFINED_VERSION(13)
}

bool CheckProto_14(const HDSeed& input, const bool silent)
{
    UNDEFINED_VERSION(14)
}

bool CheckProto_15(const HDSeed& input, const bool silent)
{
    UNDEFINED_VERSION(15)
}

bool CheckProto_16(const HDSeed& input, const bool silent)
{
    UNDEFINED_VERSION(16)
}

bool CheckProto_17(const HDSeed& input, const bool silent)
{
    UNDEFINED_VERSION(17)
}

bool CheckProto_18(const HDSeed& input, const bool silent)
{
    UNDEFINED_VERSION(18)
}

bool CheckProto_19(const HDSeed& input, const bool silent)
{
    UNDEFINED_VERSION(19)
}

bool CheckProto_20(const HDSeed& input, const bool silent)
{
    UNDEFINED_VERSION(20)
}
}  // namespace proto
}  // namespace opentxs
