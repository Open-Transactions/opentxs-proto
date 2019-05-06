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

class Test_StorageBip47NymAddressIndex : public ::testing ::Test
{
public:
    proto::StorageBip47NymAddressIndex* addr_nym_idx;
    Test_StorageBip47NymAddressIndex()
        : addr_nym_idx(new proto::StorageBip47NymAddressIndex)
    {
        addr_nym_idx->set_version(1);
        addr_nym_idx->set_target("ot_identifier_sufficiently_large");
        addr_nym_idx->set_nymid("ot_identifier_sufficiently_large");
        addr_nym_idx->set_channelid("ot_identifier_sufficiently_large");
    }
};

/* Test: version 1 is valid and others aren't
 */
TEST_F(Test_StorageBip47NymAddressIndex, versions)
{
    // test version 1 is valid
    addr_nym_idx->set_version(1);
    ASSERT_TRUE(proto::Validate(*addr_nym_idx, false));
    // test: version 0 is invalid
    addr_nym_idx->set_version(0);
    ASSERT_FALSE(proto::Validate(*addr_nym_idx, false));
    // test: version 2 is invalid
    addr_nym_idx->set_version(2);
    ASSERT_FALSE(proto::Validate(*addr_nym_idx, false));
}

/* Test: target is validated as id (address or txid)
 */
TEST_F(Test_StorageBip47NymAddressIndex, target)
{
    // test: empty address is invalid
    addr_nym_idx->set_target("");
    ASSERT_FALSE(proto::Validate(*addr_nym_idx, false));

    addr_nym_idx->set_target("XxRB5fnF8KpB9jjRRb7M7pq4qtyL8xbUou");
    ASSERT_TRUE(proto::Validate(*addr_nym_idx, false));

    addr_nym_idx->set_target(
        "000000000000000000345aa2f2819a09ced2b73e6727026d47a4b6bd184e519b");
    ASSERT_TRUE(proto::Validate(*addr_nym_idx, false));
}

/* Test: channelid is validated as id
 */
TEST_F(Test_StorageBip47NymAddressIndex, channelid)
{
    addr_nym_idx->set_channelid("");
    ASSERT_FALSE(proto::Validate(*addr_nym_idx, false));
    addr_nym_idx->set_channelid("short_ot_identifier");
    ASSERT_FALSE(proto::Validate(*addr_nym_idx, false));
    addr_nym_idx->set_channelid("ot_identifier_larger_than_20_chars");
    ASSERT_TRUE(proto::Validate(*addr_nym_idx, false));
}

/* Test: nymid is validated as id
 */
TEST_F(Test_StorageBip47NymAddressIndex, nymid)
{
    addr_nym_idx->set_nymid("");
    ASSERT_FALSE(proto::Validate(*addr_nym_idx, false));
    addr_nym_idx->set_nymid("short_ot_identifier");
    ASSERT_FALSE(proto::Validate(*addr_nym_idx, false));
    addr_nym_idx->set_nymid("ot_identifier_larger_than_20_chars");
    ASSERT_TRUE(proto::Validate(*addr_nym_idx, false));
}
}  // namespace
