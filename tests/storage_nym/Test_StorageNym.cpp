// Copyright (c) 2020 The Open-Transactions developers
// This Source Code Form is subject to the terms of the Mozilla Public
// License, v. 2.0. If a copy of the MPL was not distributed with this
// file, You can obtain one at http://mozilla.org/MPL/2.0/.

#include "opentxs-proto/Check.hpp"
#include "opentxs-proto/Types.hpp"

#include <gtest/gtest.h>

using namespace opentxs;

namespace
{

class Test_StorageNym : public ::testing ::Test
{
public:
    proto::StorageNym* storeNym;
    Test_StorageNym()
        : storeNym(new proto::StorageNym)
    {
    }
};

/* Test: version 1 through 6 rejects bip47 field
 */
TEST_F(Test_StorageNym, v6_reject_bip47)
{
    for (int i = 1; i <= 6; i++) {
        storeNym->set_version(6);
        storeNym->set_bip47("ot_bip47_tree_identifier");
        ASSERT_FALSE(proto::Validate(*storeNym, false));
    }
}

/* Test: version 7 validates bip47 field as an optional id
 */
TEST_F(Test_StorageNym, v7_accept_bip47)
{
    storeNym->set_version(7);
    ASSERT_TRUE(proto::Validate(*storeNym, false));
    storeNym->set_bip47("ot_bip47_tree_identifier");
    ASSERT_TRUE(proto::Validate(*storeNym, false));
}

}  // namespace
