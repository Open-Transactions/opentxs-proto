// Copyright (c) 2019 The Open-Transactions developers
// This Source Code Form is subject to the terms of the Mozilla Public
// License, v. 2.0. If a copy of the MPL was not distributed with this
// file, You can obtain one at http://mozilla.org/MPL/2.0/.

#include "opentxs-proto/Check.hpp"
#include "opentxs-proto/Types.hpp"

#include <gtest/gtest.h>

using namespace opentxs;

namespace
{

class Test_Bip47Direction : public ::testing ::Test
{
public:
    proto::Bip47Direction* direction;
    Test_Bip47Direction()
        : direction(new proto::Bip47Direction)
    {
        direction->set_version(1);
    }
};

TEST_F(Test_Bip47Direction, versionNumbers)
{
    // test version 1 is valid
    direction->set_version(1);
    ASSERT_TRUE(proto::Validate(*direction, false));
    // test: version 0 is invalid
    direction->set_version(0);
    ASSERT_FALSE(proto::Validate(*direction, false));
    // test: version 2 is invalid
    direction->set_version(2);
    ASSERT_FALSE(proto::Validate(*direction, false));
}

TEST_F(Test_Bip47Direction, validNotificationTransactions)
{
    ASSERT_EQ(0, direction->notification_size());
    std::string* ntx0 = direction->add_notification();
    ASSERT_EQ(1, direction->notification_size());
    ASSERT_FALSE(proto::Validate(*direction, false));
    *ntx0 = "855cd591c6502d1c81cfe38db8e0d8404ca09c2c3bc878e07f4cd0ca3afd7793";
    ASSERT_TRUE(proto::Validate(*direction, false));
}

TEST_F(Test_Bip47Direction, validAddressVersions)
{
    ASSERT_EQ(0, direction->address_size());
    ASSERT_TRUE(proto::Validate(*direction, false));

    proto::Bip47Address* new_addr = direction->add_address();
    new_addr->set_version(1);
    new_addr->set_address("17ywVfCRfcsCxzNT2nEsKE27LkwfDaNotL");

    ASSERT_EQ(1, direction->address_size());
    ASSERT_TRUE(proto::Validate(*direction, false));

    new_addr->set_version(2);
    ASSERT_FALSE(proto::Validate(*direction, false));
}

}  // namespace
