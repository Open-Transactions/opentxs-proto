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
#include "opentxs-proto/Bip47Context.pb.h"
#include "opentxs-proto/Bip47Chain.pb.h"

#include <gtest/gtest.h>

using namespace opentxs;

namespace {
    
  class Test_Bip47Context : public :: testing :: Test
  {
  public:
    proto::Bip47Context* ctx;
    Test_Bip47Context() : ctx(new proto::Bip47Context) {
      ctx->set_version(1);
      ctx->set_paymentcode("payment_id_at_least_20_chars_long");
    }
  };
    
TEST_F(Test_Bip47Context, versionNumbers)
{
  // test version 1 is valid
  ctx->set_version(1);
  ASSERT_TRUE(proto::Validate(*ctx, false));
  // test: version 0 is invalid
  ctx->set_version(0);
  ASSERT_FALSE(proto::Validate(*ctx, false));
  // test: version 2 is invalid
  ctx->set_version(2);
  ASSERT_FALSE(proto::Validate(*ctx, false));
}

TEST_F(Test_Bip47Context, invalidPaymentCodeID)
{
  ctx->set_paymentcode("");
  ASSERT_FALSE(proto::Validate(*ctx, false));
}

TEST_F(Test_Bip47Context, validPaymentCodes)
{
  proto::Bip47Context* ctx = new proto::Bip47Context;
  ASSERT_TRUE(ctx);  
  ctx->set_version(1);
}
  
  
TEST_F(Test_Bip47Context, validChainVersion)
{
  ASSERT_EQ(0, ctx->chain_size());
  ASSERT_TRUE(proto::Validate(*ctx, false));

  proto::Bip47Chain* added_chain = ctx->add_chain();
  added_chain->set_version(1);
  added_chain->set_type(proto::CITEMTYPE_BTC);
  
  ASSERT_EQ(1, ctx->chain_size());
  ASSERT_TRUE(proto::Validate(*ctx, false));

  added_chain->set_version(2);
  ASSERT_FALSE(proto::Validate(*ctx, false));
  
}
}  // namespace

