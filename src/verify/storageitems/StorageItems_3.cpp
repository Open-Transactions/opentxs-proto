// Copyright (c) 2019 The Open-Transactions developers
// This Source Code Form is subject to the terms of the Mozilla Public
// License, v. 2.0. If a copy of the MPL was not distributed with this
// file, You can obtain one at http://mozilla.org/MPL/2.0/.

#include "opentxs-proto/Types.hpp"
#include "opentxs-proto/Check.hpp"

#define PROTO_NAME "storage item index"

namespace opentxs::proto
{
bool CheckProto_3(const StorageItems& input, const bool silent)
{
    OPTIONAL_IDENTIFIER(creds);
    OPTIONAL_IDENTIFIER(nyms);
    OPTIONAL_IDENTIFIER(servers);
    OPTIONAL_IDENTIFIER(units);
    OPTIONAL_IDENTIFIER(seeds);
    OPTIONAL_IDENTIFIER(contacts);
    OPTIONAL_IDENTIFIER(blockchaintransactions);
    CHECK_EXCLUDED(accounts);
    CHECK_EXCLUDED(notary);
    CHECK_EXCLUDED(master_secret);

    return true;
}
}  // namespace opentxs::proto
