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

class Test_StorageBip47ChannelList : public ::testing ::Test
{
public:
    proto::StorageBip47ChannelList* storedChans;
    Test_StorageBip47ChannelList()
        : storedChans(new proto::StorageBip47ChannelList)
    {
        storedChans->set_version(1);
        storedChans->set_localpaymentcode("PM8TJKEj41Q66s6Vqe3JDCAzpo4NSgihP5R4vwRHGE4f26HFQi7guJEvVyFAc9hghNfLHknBcK986Q123cnU266ZD19APzpkgUP8ed7qEh7g2WCpNaAg");
        storedChans->set_chain(proto::CITEMTYPE_BTC);
        storedChans->set_contact("contact_id_sufficiently_large");
        storedChans->set_channelid("channel_id_sufficiently_large");
        storedChans->set_remotepaymentcode("PM8TJS2JxQ5ztXUpBBRnpTbcUXbUHy2T1abfrb3KkAAtMEGNbey4oumH7Hc578WgQJhPjBxteQ5GHHToTYHE3A1w6p7tU6KSoFmWBVbFGjKPisZDbP97");
    }
};

/* Test: version 1 is valid, others aren't
*/
TEST_F(Test_StorageBip47ChannelList, versions)
{
    // test version 1 is valid
    storedChans->set_version(1);
    ASSERT_TRUE(proto::Validate(*storedChans, false));
    // test: version 0 is invalid
    storedChans->set_version(0);
    ASSERT_FALSE(proto::Validate(*storedChans, false));
    // test: version 2 is invalid
    storedChans->set_version(2);
    ASSERT_FALSE(proto::Validate(*storedChans, false));
}

/* Test: chains are valid contact types, others aren't */
TEST_F(Test_StorageBip47ChannelList, chains)
{
    storedChans->set_chain(proto::CITEMTYPE_ERROR);
    ASSERT_FALSE(proto::Validate(*storedChans, false));

    storedChans->set_chain(proto::CITEMTYPE_FRIEND);
    ASSERT_FALSE(proto::Validate(*storedChans, false));

    storedChans->set_chain(proto::CITEMTYPE_INDIVIDUAL);
    ASSERT_FALSE(proto::Validate(*storedChans, false));

    storedChans->set_chain(proto::CITEMTYPE_PHOTO);
    ASSERT_FALSE(proto::Validate(*storedChans, false));

    storedChans->set_chain(proto::CITEMTYPE_ETH);
    ASSERT_TRUE(proto::Validate(*storedChans, false));

    storedChans->set_chain(proto::CITEMTYPE_DASH);
    ASSERT_TRUE(proto::Validate(*storedChans, false));
}

/* Test: contact is validated as Identifier
*/
TEST_F(Test_StorageBip47ChannelList, contactid)
{
    storedChans->set_contact("contact_larger_than_20chars");
    ASSERT_TRUE(proto::Validate(*storedChans, false));

    storedChans->set_contact("");
    ASSERT_FALSE(proto::Validate(*storedChans, false));
}

/* Test: local and remote payment codes are validated as identifiers
*/
TEST_F(Test_StorageBip47ChannelList, paymentcodes)
{
    // local paycode
    storedChans->set_localpaymentcode("");
    ASSERT_FALSE(proto::Validate(*storedChans, false));
    storedChans->set_localpaymentcode("PM8TJMs2mSP5UVDU4TFJiWtiLCEqYfhvKDnEov5tH8pSU2Sky2hdgNALShkGN3LcRNsivqBiNnAHo44rpRudvVc3oWQTmqYyavRjNKH38s5sX15n7C1F");
    ASSERT_TRUE(proto::Validate(*storedChans, false));

    // remote paycode
    storedChans->set_remotepaymentcode("");
    ASSERT_FALSE(proto::Validate(*storedChans, false));
    storedChans->set_remotepaymentcode("PM8TJMs2mSP5UVDU4TFJiWtiLCEqYfhvKDnEov5tH8pSU2Sky2hdgNALShkGN3LcRNsivqBiNnAHo44rpRudvVc3oWQTmqYyavRjNKH38s5sX15n7C1F");
    ASSERT_TRUE(proto::Validate(*storedChans, false));
}
}  // namespace
