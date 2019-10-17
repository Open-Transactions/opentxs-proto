// Copyright (c) 2019 The Open-Transactions developers
// This Source Code Form is subject to the terms of the Mozilla Public
// License, v. 2.0. If a copy of the MPL was not distributed with this
// file, You can obtain one at http://mozilla.org/MPL/2.0/.

#ifndef OPENTXS_PROTO_BASIC_HPP
#define OPENTXS_PROTO_BASIC_HPP

#include <cstdint>
#include <map>
#include <tuple>

namespace opentxs
{
namespace proto
{
// This defined a map between the version of the parent object and the (minimum,
// maximum) acceptable versions of a child object.
using VersionMap =
    std::map<std::uint32_t, std::pair<std::uint32_t, std::uint32_t>>;

extern const std::size_t MIN_PLAUSIBLE_IDENTIFIER;
extern const std::size_t MAX_PLAUSIBLE_IDENTIFIER;
extern const std::size_t MIN_PLAUSIBLE_KEYSIZE;
extern const std::size_t MAX_PLAUSIBLE_KEYSIZE;
extern const std::size_t MIN_PLAUSIBLE_SIGNATURE;
extern const std::uint32_t MAX_VALID_PORT;
extern const std::size_t MAX_VALID_CONTACT_VALUE;
extern const std::size_t MAX_LABEL_SIZE;
extern const std::size_t MAX_TRANSACTION_MEMO_SIZE;
extern const std::size_t MIN_PLAUSIBLE_SCRIPT;
extern const std::size_t MAX_PLAUSIBLE_SCRIPT;
}  // namespace proto
}  // namespace opentxs
#endif  // OPENTXS_PROTO_BASIC_HPP
