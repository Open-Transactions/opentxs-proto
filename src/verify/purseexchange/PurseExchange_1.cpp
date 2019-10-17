// Copyright (c) 2019 The Open-Transactions developers
// This Source Code Form is subject to the terms of the Mozilla Public
// License, v. 2.0. If a copy of the MPL was not distributed with this
// file, You can obtain one at http://mozilla.org/MPL/2.0/.

#include "opentxs-proto/Types.hpp"
#include "verify/Check.hpp"
#include "opentxs-proto/Contact.hpp"

#define PROTO_NAME "purse exchange"

namespace opentxs::proto
{
bool CheckProto_1(const PurseExchange& input, const bool silent)
{
    std::int64_t inValue{0};
    std::int64_t outValue{0};
    const auto& incoming = input.exchange();
    const auto& outgoing = input.request();

    CHECK_SUBOBJECT_VA(exchange, PurseExchangeAllowedPurse, inValue);
    CHECK_SUBOBJECT_VA(request, PurseExchangeAllowedPurse, outValue);

    if (inValue != outValue) {
        FAIL_4(
            "incorrect request purse value", outValue, " expected ", inValue);
    }

    if (incoming.type() != outgoing.type()) {
        FAIL_1("incorrect request purse type");
    }

    if (proto::PURSETYPE_NORMAL != incoming.state()) {
        FAIL_1("incorrect request purse state");
    }

    if (proto::PURSETYPE_REQUEST != outgoing.state()) {
        FAIL_1("incorrect request purse state");
    }

    if (incoming.notary() != outgoing.notary()) {
        FAIL_1("incorrect request purse notary");
    }

    if (incoming.mint() != outgoing.mint()) {
        FAIL_1("incorrect request purse unit definition");
    }

    return true;
}

bool CheckProto_2(const PurseExchange& input, const bool silent)
{
    UNDEFINED_VERSION(2)
}

bool CheckProto_3(const PurseExchange& input, const bool silent)
{
    UNDEFINED_VERSION(3)
}

bool CheckProto_4(const PurseExchange& input, const bool silent)
{
    UNDEFINED_VERSION(4)
}

bool CheckProto_5(const PurseExchange& input, const bool silent)
{
    UNDEFINED_VERSION(5)
}

bool CheckProto_6(const PurseExchange& input, const bool silent)
{
    UNDEFINED_VERSION(6)
}

bool CheckProto_7(const PurseExchange& input, const bool silent)
{
    UNDEFINED_VERSION(7)
}

bool CheckProto_8(const PurseExchange& input, const bool silent)
{
    UNDEFINED_VERSION(8)
}

bool CheckProto_9(const PurseExchange& input, const bool silent)
{
    UNDEFINED_VERSION(9)
}

bool CheckProto_10(const PurseExchange& input, const bool silent)
{
    UNDEFINED_VERSION(10)
}

bool CheckProto_11(const PurseExchange& input, const bool silent)
{
    UNDEFINED_VERSION(11)
}

bool CheckProto_12(const PurseExchange& input, const bool silent)
{
    UNDEFINED_VERSION(12)
}

bool CheckProto_13(const PurseExchange& input, const bool silent)
{
    UNDEFINED_VERSION(13)
}

bool CheckProto_14(const PurseExchange& input, const bool silent)
{
    UNDEFINED_VERSION(14)
}

bool CheckProto_15(const PurseExchange& input, const bool silent)
{
    UNDEFINED_VERSION(15)
}

bool CheckProto_16(const PurseExchange& input, const bool silent)
{
    UNDEFINED_VERSION(16)
}

bool CheckProto_17(const PurseExchange& input, const bool silent)
{
    UNDEFINED_VERSION(17)
}

bool CheckProto_18(const PurseExchange& input, const bool silent)
{
    UNDEFINED_VERSION(18)
}

bool CheckProto_19(const PurseExchange& input, const bool silent)
{
    UNDEFINED_VERSION(19)
}

bool CheckProto_20(const PurseExchange& input, const bool silent)
{
    UNDEFINED_VERSION(20)
}
}  // namespace opentxs::proto
