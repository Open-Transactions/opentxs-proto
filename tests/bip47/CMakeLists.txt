# Copyright (c) 2018 The Open-Transactions developers
# This Source Code Form is subject to the terms of the Mozilla Public
# License, v. 2.0. If a copy of the MPL was not distributed with this
# file, You can obtain one at http://mozilla.org/MPL/2.0/.

set(name unittests-opentxs-proto-bip47)

set(cxx-sources
        main.cpp
        Test_Bip47Address.cpp
        Test_Bip47Channel.cpp
        Test_Bip47Direction.cpp
        )

add_executable(${name} ${cxx-sources}  $<TARGET_OBJECTS:opentxs-proto> $<TARGET_OBJECTS:opentxs-verify>)
set_target_properties(${name} PROPERTIES ENABLE_EXPORTS 1 RUNTIME_OUTPUT_DIRECTORY ${PROJECT_BINARY_DIR}/tests)
target_link_libraries(${name} ${PROTOBUF_LITE_LIBRARIES} ${GTEST_LIBRARY})
add_test(${name} ${PROJECT_BINARY_DIR}/tests/${name} --gtest_output=xml:gtestresults.xml)
