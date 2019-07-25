// Copyright (c) 2018 The Open-Transactions developers
// This Source Code Form is subject to the terms of the Mozilla Public
// License, v. 2.0. If a copy of the MPL was not distributed with this
// file, You can obtain one at http://mozilla.org/MPL/2.0/.

#include "opentxs-proto/Types.hpp"
#include "opentxs-proto/Check.hpp"

#define PROTO_NAME "blockchain external address"

namespace opentxs
{
namespace proto
{
bool CheckProto_1(const BlockchainExternalAddress& input, const bool silent)
{
    CHECK_HAVE(data);
    auto count{1};
    auto min = std::size_t{20};
    auto max = std::size_t{20};

    switch (input.type()) {
        case BTOUTPUT_MULTISIG: {
            count = 20;
            min = 33;
            max = 65;
        } break;
        case BTOUTPUT_NULL: {
            min = 0;
            max = MAX_VALID_CONTACT_VALUE;
        } break;
        case BTOUTPUT_P2WSH: {
            min = 32;
            max = 32;
        } break;
        case BTOUTPUT_P2PK: {
            min = 33;
            max = 65;
        } break;
        case BTOUTPUT_P2PKH:
        case BTOUTPUT_P2SH:
        case BTOUTPUT_P2WPKH: {
        } break;
        default: {
            FAIL_2("Invalid type", input.type());
        }
    }

    if (count < input.data().size()) {
        FAIL_2("Too many keys", input.data().size());
    }

    for (const auto& data : input.data()) {
        if ((min > data.size()) || (max < data.size())) {
            const auto fail = std::string{"invalid data size"};
            FAIL_2(fail, data.size())
        }
    }

    return true;
}

bool CheckProto_2(const BlockchainExternalAddress& input, const bool silent)
{
    UNDEFINED_VERSION(2)
}

bool CheckProto_3(const BlockchainExternalAddress& input, const bool silent)
{
    UNDEFINED_VERSION(3)
}

bool CheckProto_4(const BlockchainExternalAddress& input, const bool silent)
{
    UNDEFINED_VERSION(4)
}

bool CheckProto_5(const BlockchainExternalAddress& input, const bool silent)
{
    UNDEFINED_VERSION(5)
}

bool CheckProto_6(const BlockchainExternalAddress& input, const bool silent)
{
    UNDEFINED_VERSION(6)
}

bool CheckProto_7(const BlockchainExternalAddress& input, const bool silent)
{
    UNDEFINED_VERSION(7)
}

bool CheckProto_8(const BlockchainExternalAddress& input, const bool silent)
{
    UNDEFINED_VERSION(8)
}

bool CheckProto_9(const BlockchainExternalAddress& input, const bool silent)
{
    UNDEFINED_VERSION(9)
}

bool CheckProto_10(const BlockchainExternalAddress& input, const bool silent)
{
    UNDEFINED_VERSION(10)
}

bool CheckProto_11(const BlockchainExternalAddress& input, const bool silent)
{
    UNDEFINED_VERSION(11)
}

bool CheckProto_12(const BlockchainExternalAddress& input, const bool silent)
{
    UNDEFINED_VERSION(12)
}

bool CheckProto_13(const BlockchainExternalAddress& input, const bool silent)
{
    UNDEFINED_VERSION(13)
}

bool CheckProto_14(const BlockchainExternalAddress& input, const bool silent)
{
    UNDEFINED_VERSION(14)
}

bool CheckProto_15(const BlockchainExternalAddress& input, const bool silent)
{
    UNDEFINED_VERSION(15)
}

bool CheckProto_16(const BlockchainExternalAddress& input, const bool silent)
{
    UNDEFINED_VERSION(16)
}

bool CheckProto_17(const BlockchainExternalAddress& input, const bool silent)
{
    UNDEFINED_VERSION(17)
}

bool CheckProto_18(const BlockchainExternalAddress& input, const bool silent)
{
    UNDEFINED_VERSION(18)
}

bool CheckProto_19(const BlockchainExternalAddress& input, const bool silent)
{
    UNDEFINED_VERSION(19)
}

bool CheckProto_20(const BlockchainExternalAddress& input, const bool silent)
{
    UNDEFINED_VERSION(20)
}
}  // namespace proto
}  // namespace opentxs
