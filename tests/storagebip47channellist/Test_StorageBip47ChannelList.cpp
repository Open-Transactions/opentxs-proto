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

  class Test_StorageBip47ChannelList : public :: testing :: Test
  {
  public:
    proto::StorageBip47ChannelList* storedChans;
    Test_StorageBip47ChannelList() : storedChans(new proto::StorageBip47ChannelList) {
      storedChans->set_version(1);
      storedChans->set_chain(proto::CITEMTYPE_BTC);
      storedChans->set_contact("contact_id_sufficiently_large");
    }
  };

TEST_F(Test_StorageBip47ChannelList, versionNumbers)
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

TEST_F(Test_StorageBip47ChannelList, validChain)
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

TEST_F(Test_StorageBip47ChannelList, validContact)
{
  storedChans->set_contact("contact_larger_than_20chars");
  ASSERT_TRUE(proto::Validate(*storedChans, false));

  storedChans->set_contact("");
  ASSERT_FALSE(proto::Validate(*storedChans, false));
}

TEST_F(Test_StorageBip47ChannelList, validPaymentCode)
{
  ASSERT_EQ(0, storedChans->paymentcode_size());
  std::string* pcode0 = storedChans->add_paymentcode();
  ASSERT_EQ(1, storedChans->paymentcode_size());
  ASSERT_FALSE(proto::Validate(*storedChans, false));
  *pcode0 = "PM8TJMs2mSP5UVDU4TFJiWtiLCEqYfhvKDnEov5tH8pSU2Sky2hdgNALShkGN3LcRNsivqBiNnAHo44rpRudvVc3oWQTmqYyavRjNKH38s5sX15n7C1F";
  ASSERT_TRUE(proto::Validate(*storedChans, false));
}

}  // namespace

