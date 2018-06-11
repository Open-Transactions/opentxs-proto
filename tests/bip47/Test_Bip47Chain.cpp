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
    
  class Test_Bip47Chain : public :: testing :: Test
  {
  public:
    proto::Bip47Chain* chain;
    Test_Bip47Chain() : chain(new proto::Bip47Chain) {
      chain->set_version(1);
      chain->set_type(proto::CITEMTYPE_BTC);
    }
  };
    
TEST_F(Test_Bip47Chain, versionNumbers)
{
  // test version 1 is valid
  chain->set_version(1);
  ASSERT_TRUE(proto::Validate(*chain, false));
  // test: version 0 is invalid
  chain->set_version(0);
  ASSERT_FALSE(proto::Validate(*chain, false));
  // test: version 2 is invalid
  chain->set_version(2);
  ASSERT_FALSE(proto::Validate(*chain, false));
}

TEST_F(Test_Bip47Chain, validContractType)
{
  chain->set_type(proto::CITEMTYPE_ERROR);
  ASSERT_FALSE(proto::Validate(*chain, false));

  chain->set_type(proto::CITEMTYPE_FRIEND);
  ASSERT_FALSE(proto::Validate(*chain, false));

  chain->set_type(proto::CITEMTYPE_INDIVIDUAL);
  ASSERT_FALSE(proto::Validate(*chain, false));

  chain->set_type(proto::CITEMTYPE_PHOTO);
  ASSERT_FALSE(proto::Validate(*chain, false));

  chain->set_type(proto::CITEMTYPE_ETH);
  ASSERT_TRUE(proto::Validate(*chain, false));

  chain->set_type(proto::CITEMTYPE_DASH);
  ASSERT_TRUE(proto::Validate(*chain, false));
}
  
}  // namespace

