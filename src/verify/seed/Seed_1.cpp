// Copyright (c) 2019 The Open-Transactions developers
// This Source Code Form is subject to the terms of the Mozilla Public
// License, v. 2.0. If a copy of the MPL was not distributed with this
// file, You can obtain one at http://mozilla.org/MPL/2.0/.

#include "opentxs-proto/Types.hpp"
#include "verify/Check.hpp"

#define PROTO_NAME "seed"

namespace opentxs
{
namespace proto
{
bool CheckProto_1(const Seed& input, const bool silent)
{
    CHECK_SUBOBJECT_VA(words, SeedAllowedCiphertext(), false);
    OPTIONAL_SUBOBJECT_VA(passphrase, SeedAllowedCiphertext(), false);
    CHECK_IDENTIFIER(fingerprint);
    CHECK_EXCLUDED(index);
    CHECK_EXCLUDED(raw);

    return true;
}

bool CheckProto_2(const Seed& input, const bool silent)
{
    CHECK_SUBOBJECT_VA(words, SeedAllowedCiphertext(), false);
    OPTIONAL_SUBOBJECT_VA(passphrase, SeedAllowedCiphertext(), false);
    CHECK_IDENTIFIER(fingerprint);
    CHECK_EXISTS(index);
    CHECK_EXCLUDED(raw);

    return true;
}

bool CheckProto_3(const Seed& input, const bool silent)
{
    OPTIONAL_SUBOBJECT_VA(words, SeedAllowedCiphertext(), false);
    OPTIONAL_SUBOBJECT_VA(passphrase, SeedAllowedCiphertext(), false);
    CHECK_IDENTIFIER(fingerprint);
    CHECK_EXISTS(index);
    OPTIONAL_SUBOBJECT_VA(raw, SeedAllowedCiphertext(), false);

    if (false == input.has_raw() && false == input.has_words()) {
        FAIL_1("No payload");
    }

    return true;
}

bool CheckProto_4(const Seed& input, const bool silent) { UNDEFINED_VERSION(4) }

bool CheckProto_5(const Seed& input, const bool silent) { UNDEFINED_VERSION(5) }

bool CheckProto_6(const Seed& input, const bool silent) { UNDEFINED_VERSION(6) }

bool CheckProto_7(const Seed& input, const bool silent) { UNDEFINED_VERSION(7) }

bool CheckProto_8(const Seed& input, const bool silent) { UNDEFINED_VERSION(8) }

bool CheckProto_9(const Seed& input, const bool silent) { UNDEFINED_VERSION(9) }

bool CheckProto_10(const Seed& input, const bool silent)
{
    UNDEFINED_VERSION(10)
}

bool CheckProto_11(const Seed& input, const bool silent)
{
    UNDEFINED_VERSION(11)
}

bool CheckProto_12(const Seed& input, const bool silent)
{
    UNDEFINED_VERSION(12)
}

bool CheckProto_13(const Seed& input, const bool silent)
{
    UNDEFINED_VERSION(13)
}

bool CheckProto_14(const Seed& input, const bool silent)
{
    UNDEFINED_VERSION(14)
}

bool CheckProto_15(const Seed& input, const bool silent)
{
    UNDEFINED_VERSION(15)
}

bool CheckProto_16(const Seed& input, const bool silent)
{
    UNDEFINED_VERSION(16)
}

bool CheckProto_17(const Seed& input, const bool silent)
{
    UNDEFINED_VERSION(17)
}

bool CheckProto_18(const Seed& input, const bool silent)
{
    UNDEFINED_VERSION(18)
}

bool CheckProto_19(const Seed& input, const bool silent)
{
    UNDEFINED_VERSION(19)
}

bool CheckProto_20(const Seed& input, const bool silent)
{
    UNDEFINED_VERSION(20)
}
}  // namespace proto
}  // namespace opentxs
