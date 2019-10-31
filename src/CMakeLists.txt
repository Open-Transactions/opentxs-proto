# Copyright (c) 2019 The Open-Transactions developers
# This Source Code Form is subject to the terms of the Mozilla Public
# License, v. 2.0. If a copy of the MPL was not distributed with this
# file, You can obtain one at http://mozilla.org/MPL/2.0/.

add_subdirectory(opentxs-proto)
add_subdirectory(verify)

add_library(libopentxs-proto $<TARGET_OBJECTS:messages>
                             $<TARGET_OBJECTS:verify>)
add_library(opentxs-proto::libopentxs-proto ALIAS libopentxs-proto)

target_link_libraries(
  libopentxs-proto
  PUBLIC protobuf::libprotobuf-lite
  PRIVATE Threads::Threads
)

target_include_directories(
  libopentxs-proto SYSTEM
  PUBLIC ${Protobuf_INCLUDE_DIR}
  PRIVATE $<BUILD_INTERFACE:${opentxs-proto_BINARY_DIR}/src>
)

target_include_directories(
  libopentxs-proto
  PRIVATE $<BUILD_INTERFACE:${opentxs-proto_SOURCE_DIR}/include>
)

if(CMAKE_DL_LIBS)
  target_link_libraries(libopentxs-proto PRIVATE ${CMAKE_DL_LIBS})
endif()

if(LIB_RT)
  target_link_libraries(libopentxs-proto PRIVATE ${LIB_RT})
endif()

if(LIB_ANDROID_LOG)
  target_link_libraries(libopentxs-proto PRIVATE ${LIB_ANDROID_LOG})
endif()

set_target_properties(libopentxs-proto PROPERTIES OUTPUT_NAME opentxs-proto)

include(GenerateExportHeader)
generate_export_header(
  libopentxs-proto
  EXPORT_FILE_NAME
  "${${PROJECT_NAME}_BINARY_DIR}/src/opentxs-proto/opentxs-proto_export.hpp"
  EXPORT_MACRO_NAME
  OPENTXS_PROTO_EXPORT
)

install(
  TARGETS libopentxs-proto DESTINATION ${CMAKE_INSTALL_LIBDIR}
  EXPORT opentxs-proto-targets
  COMPONENT main
)
install(
  FILES
    "${${PROJECT_NAME}_BINARY_DIR}/src/opentxs-proto/opentxs-proto_export.hpp"
  DESTINATION include/opentxs-proto
  COMPONENT main
)
