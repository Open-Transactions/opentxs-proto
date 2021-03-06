# Copyright (c) 2020 The Open-Transactions developers
# This Source Code Form is subject to the terms of the Mozilla Public
# License, v. 2.0. If a copy of the MPL was not distributed with this
# file, You can obtain one at http://mozilla.org/MPL/2.0/.

set(name unittests-opentxs-storage-nym)

set(cxx-sources main.cpp Test_StorageNym.cpp)

add_executable(${name} ${cxx-sources})

set_target_properties(
  ${name}
  PROPERTIES
    ENABLE_EXPORTS
    1
    RUNTIME_OUTPUT_DIRECTORY
    ${PROJECT_BINARY_DIR}/tests
    MSVC_RUNTIME_LIBRARY
    "${MSVC_RUNTIME_DEFAULT}"
)

target_link_libraries(
  ${name}
  opentxs-proto::libopentxs-proto
  GTest::GTest
  protobuf::libprotobuf-lite
)

if(NOT MSVC)
  target_compile_options(${name} PRIVATE -Wno-effc++)
endif()

add_test(${name} ${PROJECT_BINARY_DIR}/tests/${name}
         --gtest_output=xml:gtestresults.xml)
