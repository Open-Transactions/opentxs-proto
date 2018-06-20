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

  class Test_StorageNym : public :: testing :: Test
  {
  public:
    proto::StorageNym* storeNym;
    Test_StorageNym() : storeNym(new proto::StorageNym) {
    }
  };

TEST_F(Test_StorageNym, v6_rejectBip47Contexts)
{
  storeNym->set_version(6);
  proto::StorageItemHash* storedCtxs = storeNym->mutable_bip47contexts();
  storedCtxs->set_itemid("id___larger___than___20chars___long");
  storedCtxs->set_hash("hash__larger__than__20chars__long");
  storedCtxs->set_type(proto::STORAGEHASH_RAW);

  // test: reject both version 1 and 2
  storedCtxs->set_version(1);
  ASSERT_FALSE(proto::Validate(*storeNym, false));
  storedCtxs->set_version(2);
  ASSERT_FALSE(proto::Validate(*storeNym, false));
}

TEST_F(Test_StorageNym, v6_rejectBip47ChannelList)
{
  storeNym->set_version(6);
  proto::StorageBip47ChannelList* newChannel = storeNym->add_bip47channelindex();
  newChannel->set_version(1);
  newChannel->set_chain(proto::CITEMTYPE_BTC);
  newChannel->set_contact("contact_id_longer_than_20_chars");
  ASSERT_FALSE(proto::Validate(*storeNym, false));
}

TEST_F(Test_StorageNym, v7_acceptBip47Contexts)
{
  // test: version 7 accepts bip 47 context
  storeNym->set_version(7);
  proto::StorageItemHash* storedCtxs = storeNym->mutable_bip47contexts();
  storedCtxs->set_itemid("id___larger___than___20chars___long");
  storedCtxs->set_hash("hash__larger__than__20chars__long");
  storedCtxs->set_type(proto::STORAGEHASH_RAW);

  // test: version 1 is invalid
  storedCtxs->set_version(1);
  ASSERT_FALSE(proto::Validate(*storeNym, false));

  // test: version 2 is valid
  storedCtxs->set_version(2);
  ASSERT_TRUE(proto::Validate(*storeNym, false));
}

TEST_F(Test_StorageNym, v7_acceptBip47ChannelList)
{
  storeNym->set_version(7);
  proto::StorageItemHash* storedCtxs = storeNym->mutable_bip47contexts();
  storedCtxs->set_itemid("id___larger___than___20chars___long");
  storedCtxs->set_hash("hash__larger__than__20chars__long");
  storedCtxs->set_type(proto::STORAGEHASH_RAW);
  storedCtxs->set_version(2);
  ASSERT_TRUE(proto::Validate(*storeNym, false));

  proto::StorageBip47ChannelList* newChannel = storeNym->add_bip47channelindex();
  newChannel->set_version(1);
  newChannel->set_chain(proto::CITEMTYPE_BTC);
  newChannel->set_contact("contact_id_longer_than_20_chars");
  ASSERT_TRUE(proto::Validate(*storeNym, false));
}
}  // namespace

