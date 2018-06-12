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

TEST_F(Test_StorageNym, v6_rejectBip47Context)
{
  storeNym->clear_bip47context();
  ASSERT_EQ(0, storeNym->bip47context_size());

  storeNym->set_version(6);
  proto::StorageItemHash* storedCtx = storeNym->add_bip47context();
  storedCtx->set_itemid("id___larger___than___20chars___long");
  storedCtx->set_hash("hash__larger__than__20chars__long");
  storedCtx->set_type(proto::STORAGEHASH_RAW);
  ASSERT_EQ(1, storeNym->bip47context_size());

  // test: reject versions 1,2
  storedCtx->set_version(1);
  ASSERT_FALSE(proto::Validate(*storeNym, false));
  storedCtx->set_version(2);
  ASSERT_FALSE(proto::Validate(*storeNym, false));
}

TEST_F(Test_StorageNym, v6_rejectBip47ChannelList)
{
  storeNym->clear_bip47channelindex();
  ASSERT_EQ(0, storeNym->bip47channelindex_size());

  storeNym->set_version(6);
  proto::StorageBip47ChannelList* newChannel = storeNym->add_bip47channelindex();
  newChannel->set_version(1);
  newChannel->set_chain(proto::CITEMTYPE_BTC);
  newChannel->set_contact("contact_id_longer_than_20_chars");
  ASSERT_FALSE(proto::Validate(*storeNym, false));
}

TEST_F(Test_StorageNym, v7_acceptBip47Context)
{
  storeNym->clear_bip47context();
  ASSERT_EQ(0, storeNym->bip47context_size());

  // test: version 7 accepts bip 47 context
  storeNym->set_version(7);
  proto::StorageItemHash* storedCtx = storeNym->add_bip47context();
  storedCtx->set_itemid("id___larger___than___20chars___long");
  storedCtx->set_hash("hash__larger__than__20chars__long");
  storedCtx->set_type(proto::STORAGEHASH_RAW);
  ASSERT_EQ(1, storeNym->bip47context_size());

  // test: version 1 is invalid
  storedCtx->set_version(1);
  ASSERT_FALSE(proto::Validate(*storeNym, false));

  // test: version 2 is valid
  storedCtx->set_version(2);
  ASSERT_TRUE(proto::Validate(*storeNym, false));
}

TEST_F(Test_StorageNym, v7_rejectBip47ChannelList)
{
  storeNym->clear_bip47channelindex();
  ASSERT_EQ(0, storeNym->bip47channelindex_size());

  storeNym->set_version(7);
  proto::StorageBip47ChannelList* newChannel = storeNym->add_bip47channelindex();
  newChannel->set_version(1);
  newChannel->set_chain(proto::CITEMTYPE_BTC);
  newChannel->set_contact("contact_id_longer_than_20_chars");
  ASSERT_TRUE(proto::Validate(*storeNym, false));
}
}  // namespace

