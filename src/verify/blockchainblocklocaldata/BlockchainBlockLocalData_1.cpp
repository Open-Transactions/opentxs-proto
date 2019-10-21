// Copyright (c) 2018 The Open-Transactions developers
// This Source Code Form is subject to the terms of the Mozilla Public
// License, v. 2.0. If a copy of the MPL was not distributed with this
// file, You can obtain one at http://mozilla.org/MPL/2.0/.

#include "opentxs-proto/Types.hpp"
#include "verify/Check.hpp"

#define PROTO_NAME "blockchain block header local data"

namespace opentxs
{
namespace proto
{
bool CheckProto_1(const BlockchainBlockLocalData& input, const bool silent)
{
    if (input.has_work()) { _CHECK_STRING(work, 0, MAX_PLAUSIBLE_WORK); }
    if (input.has_inherit_work()) {
        _CHECK_STRING(inherit_work, 0, MAX_PLAUSIBLE_WORK);
    }

    return true;
}

bool CheckProto_2(const BlockchainBlockLocalData& input, const bool silent)
{
    UNDEFINED_VERSION(2)
}

bool CheckProto_3(const BlockchainBlockLocalData& input, const bool silent)
{
    UNDEFINED_VERSION(3)
}

bool CheckProto_4(const BlockchainBlockLocalData& input, const bool silent)
{
    UNDEFINED_VERSION(4)
}

bool CheckProto_5(const BlockchainBlockLocalData& input, const bool silent)
{
    UNDEFINED_VERSION(5)
}

bool CheckProto_6(const BlockchainBlockLocalData& input, const bool silent)
{
    UNDEFINED_VERSION(6)
}

bool CheckProto_7(const BlockchainBlockLocalData& input, const bool silent)
{
    UNDEFINED_VERSION(7)
}

bool CheckProto_8(const BlockchainBlockLocalData& input, const bool silent)
{
    UNDEFINED_VERSION(8)
}

bool CheckProto_9(const BlockchainBlockLocalData& input, const bool silent)
{
    UNDEFINED_VERSION(9)
}

bool CheckProto_10(const BlockchainBlockLocalData& input, const bool silent)
{
    UNDEFINED_VERSION(10)
}

bool CheckProto_11(const BlockchainBlockLocalData& input, const bool silent)
{
    UNDEFINED_VERSION(11)
}

bool CheckProto_12(const BlockchainBlockLocalData& input, const bool silent)
{
    UNDEFINED_VERSION(12)
}

bool CheckProto_13(const BlockchainBlockLocalData& input, const bool silent)
{
    UNDEFINED_VERSION(13)
}

bool CheckProto_14(const BlockchainBlockLocalData& input, const bool silent)
{
    UNDEFINED_VERSION(14)
}

bool CheckProto_15(const BlockchainBlockLocalData& input, const bool silent)
{
    UNDEFINED_VERSION(15)
}

bool CheckProto_16(const BlockchainBlockLocalData& input, const bool silent)
{
    UNDEFINED_VERSION(16)
}

bool CheckProto_17(const BlockchainBlockLocalData& input, const bool silent)
{
    UNDEFINED_VERSION(17)
}

bool CheckProto_18(const BlockchainBlockLocalData& input, const bool silent)
{
    UNDEFINED_VERSION(18)
}

bool CheckProto_19(const BlockchainBlockLocalData& input, const bool silent)
{
    UNDEFINED_VERSION(19)
}

bool CheckProto_20(const BlockchainBlockLocalData& input, const bool silent)
{
    UNDEFINED_VERSION(20)
}
}  // namespace proto
}  // namespace opentxs
