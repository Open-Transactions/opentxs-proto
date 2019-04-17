// Copyright (c) 2018 The Open-Transactions developers
// This Source Code Form is subject to the terms of the Mozilla Public
// License, v. 2.0. If a copy of the MPL was not distributed with this
// file, You can obtain one at http://mozilla.org/MPL/2.0/.

#include "opentxs-proto/Types.hpp"
#include "opentxs-proto/Check.hpp"

#define PROTO_NAME "HD path"

namespace opentxs
{
namespace proto
{

bool CheckProto_1(const HDPath& input, const bool silent)
{
    CHECK_EXISTS_STRING(root);

    if (0xff < input.child_size()) { FAIL_1("path too long") }

    return true;
}

bool CheckProto_2(const HDPath& input, const bool silent)
{
    UNDEFINED_VERSION(2)
}

bool CheckProto_3(const HDPath& input, const bool silent)
{
    UNDEFINED_VERSION(3)
}

bool CheckProto_4(const HDPath& input, const bool silent)
{
    UNDEFINED_VERSION(4)
}

bool CheckProto_5(const HDPath& input, const bool silent)
{
    UNDEFINED_VERSION(5)
}

bool CheckProto_6(const HDPath& input, const bool silent)
{
    UNDEFINED_VERSION(6)
}

bool CheckProto_7(const HDPath& input, const bool silent)
{
    UNDEFINED_VERSION(7)
}

bool CheckProto_8(const HDPath& input, const bool silent)
{
    UNDEFINED_VERSION(8)
}

bool CheckProto_9(const HDPath& input, const bool silent)
{
    UNDEFINED_VERSION(9)
}

bool CheckProto_10(const HDPath& input, const bool silent)
{
    UNDEFINED_VERSION(10)
}

bool CheckProto_11(const HDPath& input, const bool silent)
{
    UNDEFINED_VERSION(11)
}

bool CheckProto_12(const HDPath& input, const bool silent)
{
    UNDEFINED_VERSION(12)
}

bool CheckProto_13(const HDPath& input, const bool silent)
{
    UNDEFINED_VERSION(13)
}

bool CheckProto_14(const HDPath& input, const bool silent)
{
    UNDEFINED_VERSION(14)
}

bool CheckProto_15(const HDPath& input, const bool silent)
{
    UNDEFINED_VERSION(15)
}

bool CheckProto_16(const HDPath& input, const bool silent)
{
    UNDEFINED_VERSION(16)
}

bool CheckProto_17(const HDPath& input, const bool silent)
{
    UNDEFINED_VERSION(17)
}

bool CheckProto_18(const HDPath& input, const bool silent)
{
    UNDEFINED_VERSION(18)
}

bool CheckProto_19(const HDPath& input, const bool silent)
{
    UNDEFINED_VERSION(19)
}

bool CheckProto_20(const HDPath& input, const bool silent)
{
    UNDEFINED_VERSION(20)
}
}  // namespace proto
}  // namespace opentxs
