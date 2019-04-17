// Copyright (c) 2018 The Open-Transactions developers
// This Source Code Form is subject to the terms of the Mozilla Public
// License, v. 2.0. If a copy of the MPL was not distributed with this
// file, You can obtain one at http://mozilla.org/MPL/2.0/.

#include "opentxs-proto/Check.hpp"
#include "opentxs-proto/Types.hpp"

#include <gtest/gtest.h>

using namespace opentxs;

namespace
{

class Test_StorageBip47AddressIndex : public ::testing ::Test
{
public:
    proto::StorageBip47AddressIndex* addr_idx;
    Test_StorageBip47AddressIndex()
        : addr_idx(new proto::StorageBip47AddressIndex)
    {
        addr_idx->set_version(1);
        addr_idx->set_address("17ywVfCRfcsCxzNT2nEsKE27LkwfDaNotL");
        addr_idx->set_channelid("ot_identifier_sufficiently_large");
    }
};

/* Test: version 1 is valid and others aren't
 */
TEST_F(Test_StorageBip47AddressIndex, versions)
{
    // test version 1 is valid
    addr_idx->set_version(1);
    ASSERT_TRUE(proto::Validate(*addr_idx, false));
    // test: version 0 is invalid
    addr_idx->set_version(0);
    ASSERT_FALSE(proto::Validate(*addr_idx, false));
    // test: version 2 is invalid
    addr_idx->set_version(2);
    ASSERT_FALSE(proto::Validate(*addr_idx, false));
}

/* Test: address is validated as id
 */
TEST_F(Test_StorageBip47AddressIndex, addresses)
{
    // test: empty address is invalid
    addr_idx->set_address("");
    ASSERT_FALSE(proto::Validate(*addr_idx, false));
    // test: LTC address is valid
    addr_idx->set_address("LPtQazsoyte7qm6XsV92NvdTQNa6KC9HLn");
    ASSERT_TRUE(proto::Validate(*addr_idx, false));

    // test: BCH address is valid
    // - cashaddr
    addr_idx->set_address(
        "bitcoincash:qpm2qsznhks23z7629mms6s4cwef74vcwvy22gdx6a");
    ASSERT_TRUE(proto::Validate(*addr_idx, false));
    // - copay
    addr_idx->set_address("CTH8H8Zj6DSnXFBKQeDG28ogAS92iS16Bp");
    ASSERT_TRUE(proto::Validate(*addr_idx, false));
    // - legacy
    addr_idx->set_address("1BpEi6DfDAUFd7GtittLSdBeYJvcoaVggu");
    ASSERT_TRUE(proto::Validate(*addr_idx, false));

    // test: DASH address is valid
    addr_idx->set_address("XxRB5fnF8KpB9jjRRb7M7pq4qtyL8xbUou");
    ASSERT_TRUE(proto::Validate(*addr_idx, false));
}

/* Test: channelid is validated as id
 */
TEST_F(Test_StorageBip47AddressIndex, channelids)
{
    addr_idx->set_channelid("");
    ASSERT_FALSE(proto::Validate(*addr_idx, false));
    addr_idx->set_channelid("short_ot_identifier");
    ASSERT_FALSE(proto::Validate(*addr_idx, false));
    addr_idx->set_channelid("ot_identifier_larger_than_20_chars");
    ASSERT_TRUE(proto::Validate(*addr_idx, false));
}

}  // namespace
