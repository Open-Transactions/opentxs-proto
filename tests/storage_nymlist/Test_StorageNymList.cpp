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

class Test_StorageNymList : public ::testing ::Test
{
public:
    proto::StorageNymList* nyms;
    Test_StorageNymList()
        : nyms(new proto::StorageNymList)
    {
        nyms->set_version(1);
    }
};

/* Test: version 1 through 3 reject "address" and "transaction" (bip47) field
*/
TEST_F(Test_StorageNymList, v3_reject_bip47)
{
    ASSERT_EQ(0, nyms->address_size());
    for (int i = 1; i <= 3; i++) {
        proto::StorageBip47NymAddressIndex* addr_nym_idx = nyms->add_address();
        addr_nym_idx->set_version(1);
        addr_nym_idx->set_target("ot_identifier_sufficiently_large");
        addr_nym_idx->set_nymid("ot_identifier_sufficiently_large");
        addr_nym_idx->set_channelid("ot_identifier_sufficiently_large");
        ASSERT_FALSE(proto::Validate(*nyms, false));
        ASSERT_EQ(i, nyms->address_size());
    }

    ASSERT_EQ(0, nyms->transaction_size());
    for (int i = 1; i <= 3; i++) {
        proto::StorageBip47NymAddressIndex* addr_nym_idx = nyms->add_transaction();
        addr_nym_idx->set_version(1);
        addr_nym_idx->set_target("ot_identifier_sufficiently_large");
        addr_nym_idx->set_nymid("ot_identifier_sufficiently_large");
        addr_nym_idx->set_channelid("ot_identifier_sufficiently_large");
        ASSERT_FALSE(proto::Validate(*nyms, false));
        ASSERT_EQ(i, nyms->transaction_size());
    }
}

/* Test: version 4 accepts version 1 of storagebip47addresdindex in address
*/
TEST_F(Test_StorageNymList, v4_accept_address)
{
    nyms->set_version(4);
    ASSERT_EQ(0, nyms->address_size());
    proto::StorageBip47NymAddressIndex* addr_nym_idx = nyms->add_address();
    addr_nym_idx->set_version(1);
    addr_nym_idx->set_target("ot_identifier_sufficiently_large");
    addr_nym_idx->set_nymid("ot_identifier_sufficiently_large");
    addr_nym_idx->set_channelid("ot_identifier_sufficiently_large");
    ASSERT_TRUE(proto::Validate(*nyms, false));
    ASSERT_EQ(1, nyms->address_size());
}

/* Test: version 4 accepts version 1 of storagebip47addresdindex in transaction
*/
TEST_F(Test_StorageNymList, v4_accept_transaction)
{
    nyms->set_version(4);
    ASSERT_EQ(0, nyms->transaction_size());

    proto::StorageBip47NymAddressIndex* addr_nym_idx = nyms->add_transaction();
    addr_nym_idx->set_version(1);
    addr_nym_idx->set_target("ot_identifier_sufficiently_large");
    addr_nym_idx->set_nymid("ot_identifier_sufficiently_large");
    addr_nym_idx->set_channelid("ot_identifier_sufficiently_large");
    ASSERT_TRUE(proto::Validate(*nyms, false));
    ASSERT_EQ(1, nyms->transaction_size());
}
}  // namespace
