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
    
  class Test_Bip47Channel : public :: testing :: Test
  {
  public:
    proto::Bip47Channel* channel;
    Test_Bip47Channel() : channel(new proto::Bip47Channel) {
      channel->set_version(1);
      channel->set_contact("contact_id_longer_than_20_chars");
      channel->set_paymentcode("payment_id_longer_than_20_chars");

      proto::Bip47Direction* in = new proto::Bip47Direction;
      in->set_version(1);
      channel->set_allocated_incoming(in);

      proto::Bip47Direction* out = new proto::Bip47Direction;
      out->set_version(1);
      channel->set_allocated_outgoing(out);
    }
  };
    
TEST_F(Test_Bip47Channel, versionNumbers)
{
  // test version 1 is valid
  channel->set_version(1);
  ASSERT_TRUE(proto::Validate(*channel, false));
  // test: version 0 is invalid
  channel->set_version(0);
  ASSERT_FALSE(proto::Validate(*channel, false));
  // test: version 2 is invalid
  channel->set_version(2);
  ASSERT_FALSE(proto::Validate(*channel, false));
}

TEST_F(Test_Bip47Channel, invalidContactID)
{
  channel->set_contact("");
  ASSERT_FALSE(proto::Validate(*channel, false));
}

TEST_F(Test_Bip47Channel, validContactID)
{
  channel->set_contact("otwz4jCuiVg7UF2i1NgCSvTWeDS29EAHeL6");
  ASSERT_TRUE(proto::Validate(*channel, false));  
}

TEST_F(Test_Bip47Channel, invalidPaymentCodeID)
{
  channel->set_paymentcode("");
  ASSERT_FALSE(proto::Validate(*channel, false));
}

TEST_F(Test_Bip47Channel, validPaymentCodeID)
{
  channel->set_paymentcode("otwz4jCuiVg7UF2i1NgCSvTWeDS29EAHeL6");
  ASSERT_TRUE(proto::Validate(*channel, false));
}

TEST_F(Test_Bip47Channel, invalidIncomingVersion)
{
  ASSERT_EQ(1, channel->mutable_incoming()->version());
  ASSERT_TRUE(proto::Validate(*channel, false));
  
  proto::Bip47Direction* in_ = new proto::Bip47Direction;
  in_->set_version(2);
  channel->set_allocated_incoming(in_);
  ASSERT_FALSE(proto::Validate(*channel, false));
}

TEST_F(Test_Bip47Channel, invalidOutgoingVersion)
{
  ASSERT_EQ(1, channel->mutable_outgoing()->version());
  ASSERT_TRUE(proto::Validate(*channel, false));
  
  proto::Bip47Direction* out_ = new proto::Bip47Direction;
  out_->set_version(2);
  channel->set_allocated_outgoing(out_);
  ASSERT_FALSE(proto::Validate(*channel, false));
}
  
}  // namespace

