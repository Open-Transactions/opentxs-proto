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

class Test_Bip47Address : public ::testing ::Test
{
public:
    proto::Bip47Address* addr;
    Test_Bip47Address()
        : addr(new proto::Bip47Address)
    {
        addr->set_version(1);
        addr->set_address("17ywVfCRfcsCxzNT2nEsKE27LkwfDaNotL");
    }
};

TEST_F(Test_Bip47Address, versionNumbers)
{
    // test version 1 is valid
    addr->set_version(1);
    ASSERT_TRUE(proto::Validate(*addr, false));
    // test: version 0 is invalid
    addr->set_version(0);
    ASSERT_FALSE(proto::Validate(*addr, false));
    // test: version 2 is invalid
    addr->set_version(2);
    ASSERT_FALSE(proto::Validate(*addr, false));
}

TEST_F(Test_Bip47Address, validAddress)
{
    // test: empty address is invalid
    addr->set_address("");
    ASSERT_FALSE(proto::Validate(*addr, false));
    // test: LTC address is valid
    addr->set_address("LPtQazsoyte7qm6XsV92NvdTQNa6KC9HLn");
    ASSERT_TRUE(proto::Validate(*addr, false));
    // test: testnet address is valid

    // test: BCH address is valid
    // - cashaddr
    addr->set_address("bitcoincash:qpm2qsznhks23z7629mms6s4cwef74vcwvy22gdx6a");
    ASSERT_TRUE(proto::Validate(*addr, false));
    // - copay
    addr->set_address("CTH8H8Zj6DSnXFBKQeDG28ogAS92iS16Bp");
    ASSERT_TRUE(proto::Validate(*addr, false));
    // - legacy
    addr->set_address("1BpEi6DfDAUFd7GtittLSdBeYJvcoaVggu");
    ASSERT_TRUE(proto::Validate(*addr, false));

    // test: DASH address is valid
    addr->set_address("XxRB5fnF8KpB9jjRRb7M7pq4qtyL8xbUou");
    ASSERT_TRUE(proto::Validate(*addr, false));
}

TEST_F(Test_Bip47Address, validTxHashes)
{
    // test: no incoming is fine
    ASSERT_EQ(0, addr->incoming_size());
    ASSERT_TRUE(proto::Validate(*addr, false));

    // test: add tx hashes
    addr->add_incoming(
        "ff722643c6195c487324739f3662a74788317e292167bd7ed50103be844c9a05");
    addr->add_incoming(
        "b9c0876666c9941d1497f8dfa885c3c4140b53949724bbe5755b66018d4e7212");
    addr->add_incoming(
        "6f0f60d00a83a1c3f167f1b4af81ac337f04558790f6c841e804c9025bdac167");
    ASSERT_TRUE(proto::Validate(*addr, false));
    ASSERT_EQ(3, addr->incoming_size());

    // test: add empty hash
    addr->clear_incoming();
    addr->add_incoming("");
    ASSERT_FALSE(proto::Validate(*addr, false));
}

}  // namespace
