# Copyright (c) 2018 The Open-Transactions developers
# This Source Code Form is subject to the terms of the Mozilla Public
# License, v. 2.0. If a copy of the MPL was not distributed with this
# file, You can obtain one at http://mozilla.org/MPL/2.0/.

set(MODULE_NAME opentxs-proto)

if(NOT OT_BUNDLED_OPENTXS_PROTO)
  add_subdirectory(opentxs-proto)
endif()

add_subdirectory(verify)

if(NOT OT_BUNDLED_OPENTXS_PROTO)

  add_library(${MODULE_NAME} SHARED
    $<TARGET_OBJECTS:generated>
    $<TARGET_OBJECTS:verify>
  )

  add_library(${MODULE_NAME}_static STATIC
    $<TARGET_OBJECTS:generated>
    $<TARGET_OBJECTS:verify>
  )

  target_link_libraries(${MODULE_NAME}
    PUBLIC
    ${PROTOBUF_LITE_LIBRARIES}
    PRIVATE
    ${OPENTXS_SYSTEM_LIBRARIES}
  )

  target_link_libraries(${MODULE_NAME}_static
    PUBLIC
    ${PROTOBUF_LITE_LIBRARIES}
    PRIVATE
    ${OPENTXS_SYSTEM_LIBRARIES}
  )

  set_target_properties(${MODULE_NAME} PROPERTIES OUTPUT_NAME ${MODULE_NAME})
  set_target_properties(${MODULE_NAME}_static PROPERTIES OUTPUT_NAME ${MODULE_NAME})

  install(TARGETS ${MODULE_NAME} ${MODULE_NAME}_static
          DESTINATION ${CMAKE_INSTALL_LIBDIR}
          EXPORT ${MODULE_NAME}-targets
          COMPONENT main)
endif()
