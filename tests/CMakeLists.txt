# Copyright (c) 2019 The Open-Transactions developers
# This Source Code Form is subject to the terms of the Mozilla Public
# License, v. 2.0. If a copy of the MPL was not distributed with this
# file, You can obtain one at http://mozilla.org/MPL/2.0/.

if(${CMAKE_CXX_COMPILER_ID} MATCHES Clang)
  set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -Wno-undef -Wno-sign-compare")
endif()

include_directories(
  SYSTEM
  ${opentxs-proto_SOURCE_DIR}/include
  ${opentxs-proto_BINARY_DIR}/src
  ${GTEST_INCLUDE_DIRS}
)

add_subdirectory(bip47)
add_subdirectory(storage_bip47)
add_subdirectory(storage_nym)
add_subdirectory(storage_nymlist)
