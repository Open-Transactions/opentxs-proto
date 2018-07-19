# Copyright (c) 2018 The Open-Transactions developers
# This Source Code Form is subject to the terms of the Mozilla Public
# License, v. 2.0. If a copy of the MPL was not distributed with this
# file, You can obtain one at http://mozilla.org/MPL/2.0/.

include_directories(${GTEST_INCLUDE_DIRS})

add_subdirectory(bip47)
add_subdirectory(storage_bip47)
add_subdirectory(storage_nym)
add_subdirectory(storage_nymlist)
