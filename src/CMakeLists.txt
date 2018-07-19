# Copyright (c) 2018 The Open-Transactions developers
# This Source Code Form is subject to the terms of the Mozilla Public
# License, v. 2.0. If a copy of the MPL was not distributed with this
# file, You can obtain one at http://mozilla.org/MPL/2.0/.

include_directories(SYSTEM ${PROTOBUF_INCLUDE_DIR})

add_subdirectory(opentxs-proto)
add_subdirectory(verify)

set(MODULE_NAME opentxs-protobuf)

add_library(${MODULE_NAME} SHARED
  $<TARGET_OBJECTS:opentxs-proto>
  $<TARGET_OBJECTS:opentxs-verify>
)

add_library(${MODULE_NAME}_static STATIC
  $<TARGET_OBJECTS:opentxs-proto>
  $<TARGET_OBJECTS:opentxs-verify>
)

target_link_libraries(${MODULE_NAME}
  PUBLIC
  ${PROTOBUF_LITE_LIBRARIES}
  PRIVATE
  ${OPENTXS_SYSTEM_LIBRARIES}
)

set_target_properties(${MODULE_NAME} PROPERTIES OUTPUT_NAME opentxs-proto)

if(NOT WIN32)
  set_target_properties(${MODULE_NAME}_static PROPERTIES OUTPUT_NAME opentxs-proto)
endif()

if(NOT WIN32)
  include(GNUInstallDirs)
  install(TARGETS ${MODULE_NAME} ${MODULE_NAME}_static
          DESTINATION ${CMAKE_INSTALL_LIBDIR}
          EXPORT ${MODULE_NAME}Targets
          COMPONENT main)
endif()
