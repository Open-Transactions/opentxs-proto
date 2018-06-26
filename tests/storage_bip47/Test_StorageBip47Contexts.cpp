/************************************************************
 *
 *                 OPEN TRANSACTIONS
 *
 *       Financial Cryptography and Digital Cash
 *       Library, Protocol, API, Server, CLI, GUI
 *
 *       -- Anonymous Numbered Accounts.
 *       -- Untraceable Digital Cash.
 *       -- Triple-Signed Receipts.
 *       -- Cheques, Vouchers, Transfers, Inboxes.
 *       -- Basket Currencies, Markets, Payment Plans.
 *       -- Signed, XML, Ricardian-style Contracts.
 *       -- Scripted smart contracts.
 *
 *  EMAIL:
 *  fellowtraveler@opentransactions.org
 *
 *  WEBSITE:
 *  http://www.opentransactions.org/
 *
 *  -----------------------------------------------------
 *
 *   LICENSE:
 *   This Source Code Form is subject to the terms of the
 *   Mozilla Public License, v. 2.0. If a copy of the MPL
 *   was not distributed with this file, You can obtain one
 *   at http://mozilla.org/MPL/2.0/.
 *
 *   DISCLAIMER:
 *   This program is distributed in the hope that it will
 *   be useful, but WITHOUT ANY WARRANTY; without even the
 *   implied warranty of MERCHANTABILITY or FITNESS FOR A
 *   PARTICULAR PURPOSE.  See the Mozilla Public License
 *   for more details.
 *
 ************************************************************/

#include "opentxs-proto/Check.hpp"
#include "opentxs-proto/Types.hpp"

#include <gtest/gtest.h>

using namespace opentxs;

namespace {
    
  class Test_StorageBip47Contexts : public :: testing :: Test
  {
  public:
    proto::StorageBip47Contexts* ctxs;
    Test_StorageBip47Contexts() : ctxs(new proto::StorageBip47Contexts) {
      ctxs->set_version(1);
    }
  };

/* Test: version 1 is valid and others aren't
*/
TEST_F(Test_StorageBip47Contexts, versions)
{
    // test version 1 is valid
    ctxs->set_version(1);
    ASSERT_TRUE(proto::Validate(*ctxs, false));
    // test: version 0 is invalid
    ctxs->set_version(0);
    ASSERT_FALSE(proto::Validate(*ctxs, false));
    // test: version 2 is invalid
    ctxs->set_version(2);
    ASSERT_FALSE(proto::Validate(*ctxs, false));
}

/* Test: version 1 and 2 of contexts are valid and others aren't
*/
TEST_F(Test_StorageBip47Contexts, contexts)
{
    ASSERT_EQ(0, ctxs->context_size());
    // version 1 is valid  
    proto::StorageItemHash* ctx1 = ctxs->add_context();
    ctx1->set_version(1);
    ctx1->set_itemid("ot_identifier_sufficiently_large");
    ctx1->set_hash("ot_identifier_sufficiently_large");    
    ASSERT_TRUE(proto::Validate(*ctxs, false));
    ASSERT_EQ(1, ctxs->context_size());
    // version 2 is valid
    ctx1->set_version(2);
    ctx1->set_type(proto::STORAGEHASH_RAW);
    ASSERT_TRUE(proto::Validate(*ctxs, false));
    // version 3 is invalid
    ctx1->set_version(3);
    ASSERT_FALSE(proto::Validate(*ctxs, false));
}

/* Test: version 1 of storagebip47channellist is valid and others aren't
*/
TEST_F(Test_StorageBip47Contexts, indexes)
{
    ASSERT_EQ(0, ctxs->index_size());
    ASSERT_TRUE(proto::Validate(*ctxs, false));
    
    proto::StorageBip47ChannelList* chans = ctxs->add_index();
    chans->set_version(1);
    chans->set_localpaymentcode("PM8TJKEj41Q66s6Vqe3JDCAzpo4NSgihP5R4vwRHGE4f26HFQi7guJEvVyFAc9hghNfLHknBcK986Q123cnU266ZD19APzpkgUP8ed7qEh7g2WCpNaAg");
    chans->set_chain(proto::CITEMTYPE_BTC);
    chans->set_contact("contact_id_sufficiently_large");
    chans->set_channelid("channel_id_sufficiently_large");
    chans->set_remotepaymentcode("PM8TJS2JxQ5ztXUpBBRnpTbcUXbUHy2T1abfrb3KkAAtMEGNbey4oumH7Hc578WgQJhPjBxteQ5GHHToTYHE3A1w6p7tU6KSoFmWBVbFGjKPisZDbP97");
    ASSERT_EQ(1, ctxs->index_size());

    ASSERT_TRUE(proto::Validate(*ctxs, false));
    chans->set_version(2);
    ASSERT_FALSE(proto::Validate(*ctxs, false));
}

/* Test: version 1 of storagebip47addressindex is valid and others aren't
*/
TEST_F(Test_StorageBip47Contexts, addresses)
{
    ASSERT_EQ(0, ctxs->address_size());
    ASSERT_TRUE(proto::Validate(*ctxs, false));
    
    proto::StorageBip47AddressIndex* addr_idx = ctxs->add_address();
    addr_idx->set_version(1);
    addr_idx->set_address("17ywVfCRfcsCxzNT2nEsKE27LkwfDaNotL");
    addr_idx->set_channelid("ot_identifier_sufficiently_large");      
    ASSERT_EQ(1, ctxs->address_size());

    ASSERT_TRUE(proto::Validate(*ctxs, false));
    addr_idx->set_version(2);
    ASSERT_FALSE(proto::Validate(*ctxs, false));
}

}  // namespace

