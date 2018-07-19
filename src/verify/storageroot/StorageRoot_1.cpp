// Copyright (c) 2018 The Open-Transactions developers
// This Source Code Form is subject to the terms of the Mozilla Public
// License, v. 2.0. If a copy of the MPL was not distributed with this
// file, You can obtain one at http://mozilla.org/MPL/2.0/.

#include "opentxs-proto/Types.hpp"
#include "opentxs-proto/Check.hpp"

#include <iostream>

namespace opentxs
{
namespace proto
{

bool CheckProto_1(const StorageRoot& input, const bool silent)
{
    if (!input.has_items()) {
        FAIL("storage root", "missing hash")
    }

    if (MIN_PLAUSIBLE_IDENTIFIER > input.items().size()) {
        FAIL("storage root", "invalid hash")
    }

    if (MAX_PLAUSIBLE_IDENTIFIER < input.items().size()) {
        FAIL("storage root", "invalid hash")
    }

    if (input.has_sequence()) {
        FAIL("storage root", "unexpected sequence field present")
    }

    return true;
}
}  // namespace proto
}  // namespace opentxs
