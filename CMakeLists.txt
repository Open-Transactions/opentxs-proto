# Copyright (c) 2019 The Open-Transactions developers
# This Source Code Form is subject to the terms of the Mozilla Public
# License, v. 2.0. If a copy of the MPL was not distributed with this
# file, You can obtain one at http://mozilla.org/MPL/2.0/.

cmake_minimum_required(VERSION 3.14)
project(opentxs-proto)
list(APPEND CMAKE_MODULE_PATH "${${PROJECT_NAME}_SOURCE_DIR}/cmake")
include(open-transactions-common)

# -----------------------------------------------------------------------------
# Setup

set_version_from_git()
set_build_type()
set_out_of_source_build()
update_git_submodules()

# -----------------------------------------------------------------------------
# Set option defaults

if(CMAKE_BUILD_TYPE STREQUAL "Debug")
  set(OPENTXS_PROTO_PEDANTIC_DEFAULT ON)
  set(OPENTXS_PROTO_BUILD_TESTS_DEFAULT ON)
  set(CMAKE_VERBOSE_MAKEFILE ON)
else()
  set(OPENTXS_PROTO_PEDANTIC_DEFAULT OFF)
  set(OPENTXS_PROTO_BUILD_TESTS_DEFAULT OFF)
endif()

# -----------------------------------------------------------------------------
# Options

option(OPENTXS_PROTO_BUILD_TESTS "Build the unit tests."
       ${OPENTXS_PROTO_BUILD_TESTS_DEFAULT})
option(OPENTXS_PROTO_PEDANTIC_BUILD "Treat compiler warnings as errors."
       ${OPENTXS_PROTO_PEDANTIC_DEFAULT})

# -----------------------------------------------------------------------------
# Set compiler options

set_compiler_flags(17 ${OPENTXS_PROTO_PEDANTIC_BUILD})

if(MSVC)
  set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} /wd4244 /wd4251")
else()
  set(
    CMAKE_CXX_FLAGS
    "${CMAKE_CXX_FLAGS} -Wno-sign-conversion -Wno-type-limits"
  )
endif()

# temporarily disabled warnings
if(${CMAKE_CXX_COMPILER_ID} MATCHES Clang)
  set(
    CMAKE_CXX_FLAGS
    "${CMAKE_CXX_FLAGS} -Wno-extra-semi-stmt -Wno-reserved-id-macro -Wno-zero-as-null-pointer-constant"
  )
endif()

# -----------------------------------------------------------------------------
# Print system information and build options

print_build_details(OPENTXS_PROTO_PEDANTIC_BUILD OPENTXS_PROTO_BUILD_TESTS)

# -----------------------------------------------------------------------------
# Dependencies

find_system_libraries()
find_package(Protobuf REQUIRED)

if(OPENTXS_PROTO_BUILD_TESTS)
  find_package(GTest REQUIRED)
  enable_testing()
endif()

# -----------------------------------------------------------------------------
# Source Definitions

set_common_defines()

# -----------------------------------------------------------------------------
# Build source

add_subdirectory(src)

# -----------------------------------------------------------------------------
# Build tests

if(OPENTXS_PROTO_BUILD_TESTS)
  add_subdirectory(tests)
endif()

# -----------------------------------------------------------------------------
# Package

generate_cmake_files()
generate_pkgconfig("-lopentxs-proto")
generate_uninstall_target()
