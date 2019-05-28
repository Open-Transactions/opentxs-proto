// Copyright (c) 2018 The Open-Transactions developers
// This Source Code Form is subject to the terms of the Mozilla Public
// License, v. 2.0. If a copy of the MPL was not distributed with this
// file, You can obtain one at http://mozilla.org/MPL/2.0/.

#include "opentxs-proto/Types.hpp"
#include "verify/Check.hpp"

#define PROTO_NAME "blockchain block header"

namespace opentxs
{
namespace proto
{
bool CheckProto_1(const BlockchainBlockHeader& input, const bool silent)
{
    bool bitcoin{false};
    bool ethereum{false};

    switch (input.type()) {
        case 1:
        case 2:
        case 3:
        case 4: {
            bitcoin = true;
        } break;
        case 5:
        case 6: {
            ethereum = true;
        } break;
        default: {
            FAIL_2("Invalid type", std::to_string(input.type()));
        }
    }

    OPTIONAL_SUBOBJECT(
        local, BlockchainBlockHeaderAllowedBlockchainBlockLocalData);

    if (bitcoin) {
        CHECK_SUBOBJECT(
            bitcoin, BlockchainBlockHeaderAllowedBitcoinBlockHeaderFields);
        CHECK_EXCLUDED(ethereum);
    } else if (ethereum) {
        CHECK_SUBOBJECT(
            ethereum, BlockchainBlockHeaderAllowedEthereumBlockHeaderFields);
        CHECK_EXCLUDED(bitcoin);
    } else {
        FAIL_1("Unknown type");
    }

    return true;
}

bool CheckProto_2(const BlockchainBlockHeader& input, const bool silent)
{
    UNDEFINED_VERSION(2)
}

bool CheckProto_3(const BlockchainBlockHeader& input, const bool silent)
{
    UNDEFINED_VERSION(3)
}

bool CheckProto_4(const BlockchainBlockHeader& input, const bool silent)
{
    UNDEFINED_VERSION(4)
}

bool CheckProto_5(const BlockchainBlockHeader& input, const bool silent)
{
    UNDEFINED_VERSION(5)
}

bool CheckProto_6(const BlockchainBlockHeader& input, const bool silent)
{
    UNDEFINED_VERSION(6)
}

bool CheckProto_7(const BlockchainBlockHeader& input, const bool silent)
{
    UNDEFINED_VERSION(7)
}

bool CheckProto_8(const BlockchainBlockHeader& input, const bool silent)
{
    UNDEFINED_VERSION(8)
}

bool CheckProto_9(const BlockchainBlockHeader& input, const bool silent)
{
    UNDEFINED_VERSION(9)
}

bool CheckProto_10(const BlockchainBlockHeader& input, const bool silent)
{
    UNDEFINED_VERSION(10)
}

bool CheckProto_11(const BlockchainBlockHeader& input, const bool silent)
{
    UNDEFINED_VERSION(11)
}

bool CheckProto_12(const BlockchainBlockHeader& input, const bool silent)
{
    UNDEFINED_VERSION(12)
}

bool CheckProto_13(const BlockchainBlockHeader& input, const bool silent)
{
    UNDEFINED_VERSION(13)
}

bool CheckProto_14(const BlockchainBlockHeader& input, const bool silent)
{
    UNDEFINED_VERSION(14)
}

bool CheckProto_15(const BlockchainBlockHeader& input, const bool silent)
{
    UNDEFINED_VERSION(15)
}

bool CheckProto_16(const BlockchainBlockHeader& input, const bool silent)
{
    UNDEFINED_VERSION(16)
}

bool CheckProto_17(const BlockchainBlockHeader& input, const bool silent)
{
    UNDEFINED_VERSION(17)
}

bool CheckProto_18(const BlockchainBlockHeader& input, const bool silent)
{
    UNDEFINED_VERSION(18)
}

bool CheckProto_19(const BlockchainBlockHeader& input, const bool silent)
{
    UNDEFINED_VERSION(19)
}

bool CheckProto_20(const BlockchainBlockHeader& input, const bool silent)
{
    UNDEFINED_VERSION(20)
}
}  // namespace proto
}  // namespace opentxs
