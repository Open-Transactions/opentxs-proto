cmake_minimum_required(VERSION 2.8.12)
project(opentxs-proto)


if(NOT ANDROID)
set(CMAKE_FIND_ROOT_PATH_MODE_PROGRAM LAST)
find_package(Git)
if(GIT_FOUND)
    execute_process(COMMAND git "describe" OUTPUT_VARIABLE GIT_VERSION WORKING_DIRECTORY ${CMAKE_SOURCE_DIR} OUTPUT_STRIP_TRAILING_WHITESPACE)
    string(REGEX REPLACE "^([0-9]+)\\..*" "\\1" VERSION_MAJOR "${GIT_VERSION}")
    string(REGEX REPLACE "^${VERSION_MAJOR}\\.([0-9]+).*" "\\1" VERSION_MINOR "${GIT_VERSION}")
    string(REGEX REPLACE "^${VERSION_MAJOR}\\.${VERSION_MINOR}\\.([0-9]+).*" "\\1" VERSION_BUGFIX "${GIT_VERSION}")
    string(REGEX REPLACE "^${VERSION_MAJOR}\\.${VERSION_MINOR}\\.${VERSION_BUGFIX}-([0-9]+)-.*" "\\1" VERSION_NEW_COMMITS "${GIT_VERSION}")
    string(REGEX REPLACE "^${VERSION_MAJOR}\\.${VERSION_MINOR}\\.${VERSION_BUGFIX}-${VERSION_NEW_COMMITS}-(.*)" "\\1" VERSION_SHA1 "${GIT_VERSION}")
    if("${VERSION_NEW_COMMITS}" STREQUAL "${GIT_VERSION}")
        set(VERSION_STRING "${VERSION_MAJOR}.${VERSION_MINOR}.${VERSION_BUGFIX}")
        set(VERSION_NEW_COMMITS "")
        set(VERSION_SHA1 "")
    else()
        set(VERSION_STRING "${VERSION_MAJOR}.${VERSION_MINOR}.${VERSION_BUGFIX}-${VERSION_NEW_COMMITS}-${VERSION_SHA1}")
    endif()
    if ("${VERSION_STRING}" STREQUAL "..")
        message(FATAL_ERROR "Version string missing. Did you git clone using the --depth parameter?")
    endif()
else()
  message(FATAL_ERROR "Git not found.")
endif()
endif() # NOT ANDROID

#-----------------------------------------------------------------------------
# Options for building

option(BUILD_VERBOSE       "Verbose build output." ON)
option(USE_CCACHE          "Use ccache." OFF)

option(BUILD_SHARED_LIBS   "Build shared libraries." ON)
option(JAVA                "Build with Java binding" OFF)
option(JAVASCRIPT          "Build with Javascript binding" OFF)
option(PYTHON3             "Build with Python3 binding" OFF)
option(PYTHON2             "Build with Python2 binding" OFF)
option(PYTHON              "Build with default Python binding" OFF)

set(PACKAGE_CONTACT        ""                             CACHE <TYPE>  "Package Maintainer")
set(PACKAGE_VENDOR         "Open Transactions Developers" CACHE <TYPE>  "Package Vendor")

if(BUILD_VERBOSE)
  set(CMAKE_VERBOSE_MAKEFILE true)
endif()

#-----------------------------------------------------------------------------
# Python

if (PYTHON)
  cmake_minimum_required(VERSION 3.4 FATAL_ERROR)
endif()

#-----------------------------------------------------------------------------
# Collect all binaries into bin subdirectory

set(LIBRARY_OUTPUT_PATH  ${CMAKE_CURRENT_BINARY_DIR}/lib)


#-----------------------------------------------------------------------------
# Check which compiler to use

INCLUDE(CheckCXXCompilerFlag)
CHECK_CXX_COMPILER_FLAG(-std=c++17 HAVE_STD17)

if(HAVE_STD17)
  set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++17")
else()
  set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++1z")
endif()

if(${CMAKE_CXX_COMPILER_ID} MATCHES GNU)
  set(GCC_WARN_FLAGS "-Wnoexcept -Wstrict-null-sentinel -Wlogical-op")
  set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -pthread")

  if(ANDROID)
    set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -fexceptions -frtti")
  endif()
elseif(${CMAKE_CXX_COMPILER_ID} MATCHES Clang)
  set(CMAKE_COMPILER_IS_CLANGXX 1)

  if(APPLE)
    set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -stdlib=libc++")
    set(CMAKE_CXX_LINK_FLAGS "${CMAKE_CXX_LINK_FLAGS} -stdlib=libc++")
  else()
    set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -pthread")
  endif()
endif()

if(BUILD_SHARED_LIBS)
  # Windows would complain about unknown flag -fPIC
  if(NOT WIN32)
    set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -fPIC")
  endif()
endif()


if(WIN32)
  add_definitions(-D_UNICODE)
else()
  set(PEDANTIC_CXX_FLAGS "-Wall -Werror -Wextra -pedantic -Wno-missing-braces -Wcast-align -Wctor-dtor-privacy -Wdisabled-optimization -Winit-self -Wmissing-include-dirs -Wswitch-default -Wold-style-cast -Wredundant-decls -Woverloaded-virtual -Wmissing-declarations -Wunused-macros -Wundef -Wformat=2 -Wno-format-nonliteral ${GCC_WARN_FLAGS}")
endif()

if(ANDROID)
  set(PEDANTIC_CXX_FLAGS "${PEDANTIC_CXX_FLAGS} -Wno-useless-cast -Wno-missing-field-initializers")
  add_definitions(-D__STDC_LIMIT_MACROS)
endif()

if(CMAKE_COMPILER_IS_CLANGXX)
  set(PEDANTIC_CXX_FLAGS "${PEDANTIC_CXX_FLAGS} -Wno-unused-parameter -Wno-old-style-cast")
endif()

message(STATUS "C++ Compiler ID: ${CMAKE_CXX_COMPILER_ID}")
message(STATUS "C++ Flags:       ${CMAKE_CXX_FLAGS}")
message(STATUS "C++ link flags:  ${CMAKE_CXX_LINK_FLAGS}")
message(STATUS "Package version:  ${VERSION_STRING}")
message(STATUS "Package version:  ${VERSION_MAJOR}")
message(STATUS "Package version:  ${VERSION_MINOR}")
message(STATUS "Package version:  ${VERSION_BUGFIX}")
message(STATUS "Package version:  ${VERSION_SHA1}")

message(STATUS "Bindings ------------------------------------")
message(STATUS "Java binding:           ${JAVA}")
message(STATUS "Javascript binding:     ${JAVASCRIPT}")
message(STATUS "Python3 binding:        ${PYTHON3}")
message(STATUS "Python2 binding:        ${PYTHON2}")
message(STATUS "Default Python binding: ${PYTHON}")

#-----------------------------------------------------------------------------
# Third party libraries

list(APPEND CMAKE_MODULE_PATH "${CMAKE_CURRENT_SOURCE_DIR}/cmake")

find_package(Protobuf REQUIRED)

if(PYTHON)
  find_package(PythonInterp)
  find_package(PythonLibs)
elseif(PYTHON3)
  find_package(PythonInterp 3 REQUIRED)
  find_package(PythonLibs 3 REQUIRED)
elseif(PYTHON2)
  find_package(PythonInterp 2.7 REQUIRED)
  find_package(PythonLibs 2.7 REQUIRED)
endif(PYTHON)

message(STATUS "PYTHON_LIBRARIES = ${PYTHON_LIBRARIES}")
message(STATUS "PYTHON_EXECUTABLE = ${PYTHON_EXECUTABLE}")
message(STATUS "PYTHON_INCLUDE_DIRS = ${PYTHON_INCLUDE_DIRS}")

#-----------------------------------------------------------------------------
# System libraries used for linking.

if(UNIX AND NOT APPLE)
  list(APPEND OPENTXS_SYSTEM_LIBRARIES dl)
  if(ANDROID)
    list(APPEND OPENTXS_SYSTEM_LIBRARIES log)
  else()
    list(APPEND OPENTXS_SYSTEM_LIBRARIES rt)
  endif()
endif()


#-----------------------------------------------------------------------------
# Force out-of-source build

if(${CMAKE_CURRENT_SOURCE_DIR} STREQUAL ${CMAKE_CURRENT_BINARY_DIR})
message(FATAL_ERROR "CMake generation is not allowed within the source directory!
Remove the CMakeCache.txt file and try again from another folder, e.g.:

   rm CMakeCache.txt
   mkdir build
   cd build
   cmake ..
")
endif()

#-----------------------------------------------------------------------------
# Use ccache

if (USE_CCACHE)
  find_program(CCACHE "ccache")
  if (CCACHE)
    SET_PROPERTY(GLOBAL PROPERTY RULE_LAUNCH_COMPILE "CCACHE_CPP2=yes ${CCACHE}")
    SET_PROPERTY(GLOBAL PROPERTY RULE_LAUNCH_LINK ${CCACHE})
  endif(CCACHE)
endif (USE_CCACHE)

#-----------------------------------------------------------------------------
# Default to Release build

if(NOT CMAKE_BUILD_TYPE)
  set(CMAKE_BUILD_TYPE Release CACHE STRING
      "Choose the type of build, options are: None Debug Release RelWithDebInfo MinSizeRel."
      FORCE)
endif()


#-----------------------------------------------------------------------------
# Source Definitions

if(WIN32)
    if(NOT IDC_STATIC)
        add_definitions(-DIDC_STATIC=-1)
    endif()

    add_definitions(-DOT_COMPANYNAME="Open Transactions Community")
    add_definitions(-DOT_PRODUCTNAME="Open Transactions")
    add_definitions(-DOT_PRODUCTVERSION="${VERSION_MAJOR},${VERSION_MINOR},${VERSION_BUGFIX},0")
    add_definitions(-DOT_API_NAME="Open Transactions Protobuf API")
    add_definitions(-DOT_LIBRARY_NAME="Open Transactions Protobuf Library")
    add_definitions(-DOT_PROMPT_NAME="Open Transactions Prompt")
endif()

#-----------------------------------------------------------------------------
# Set in-source Version
configure_file("include/Version.hpp" "${CMAKE_CURRENT_BINARY_DIR}/include/opentxs-proto/Version.hpp" @ONLY)

install(FILES ${CMAKE_CURRENT_BINARY_DIR}/include/opentxs-proto/Version.hpp
        DESTINATION include/opentxs-proto/
        COMPONENT dev)

#-----------------------------------------------------------------------------
# Build source

#Fix RPATH
if(APPLE)
    # use, i.e. don't skip the full RPATH for the build tree
    SET(CMAKE_SKIP_BUILD_RPATH  FALSE)

    # when building, don't use the install RPATH already
    # (but later on when installing)
    SET(CMAKE_BUILD_WITH_INSTALL_RPATH FALSE)

    SET(CMAKE_INSTALL_RPATH "${CMAKE_INSTALL_PREFIX}/lib")

    # add the automatically determined parts of the RPATH
    # which point to directories outside the build tree to the install RPATH
    SET(CMAKE_INSTALL_RPATH_USE_LINK_PATH TRUE)

    # the RPATH to be used when installing, but only if it's not a system directory
    LIST(FIND CMAKE_PLATFORM_IMPLICIT_LINK_DIRECTORIES "${CMAKE_INSTALL_PREFIX}/lib" isSystemDir)
    IF("${isSystemDir}" STREQUAL "-1")
    SET(CMAKE_INSTALL_RPATH "${CMAKE_INSTALL_PREFIX}/lib")
    ENDIF("${isSystemDir}" STREQUAL "-1")
endif()

if(UNIX)
  add_definitions(-DOT_PREFIX_PATH=\"${CMAKE_INSTALL_PREFIX}\")
endif()

function(set_lib_property lib)
  if (NOT ANDROID)
    set_target_properties(${lib} PROPERTIES VERSION ${VERSION_STRING} SOVERSION ${VERSION_MAJOR})
  endif()
endfunction(set_lib_property)

include_directories(${CMAKE_CURRENT_SOURCE_DIR}/include)
add_subdirectory(src)

if (NOT ANDROID)
#-----------------------------------------------------------------------------
# Produce a cmake-package

include(CMakePackageConfigHelpers)
set(CMAKE_CONFIG_DEST "share/cmake/Modules")
set(OPENTXS_PROTO_INCLUDE_DIRS "${CMAKE_INSTALL_PREFIX}/include")

export(TARGETS opentxs-protobuf FILE "${CMAKE_BINARY_DIR}/opentxs-protoTargets.cmake")

configure_package_config_file(
       "cmake/opentxs-protoConfig.cmake.in"
       "${CMAKE_BINARY_DIR}/opentxs-protoConfig.cmake"
       INSTALL_DESTINATION ${CMAKE_CONFIG_DEST}
       PATH_VARS OPENTXS_PROTO_INCLUDE_DIRS)

write_basic_package_version_file(
  "${CMAKE_CURRENT_BINARY_DIR}/opentxs-protoConfigVersion.cmake"
  VERSION ${VERSION_STRING}
  COMPATIBILITY AnyNewerVersion)

install(EXPORT opentxs-protobufTargets
        DESTINATION ${CMAKE_CONFIG_DEST} FILE "opentxs-proto.cmake")

install(FILES
        "${CMAKE_CURRENT_BINARY_DIR}/opentxs-protoConfig.cmake"
        "${CMAKE_CURRENT_BINARY_DIR}/opentxs-protoConfigVersion.cmake"
        DESTINATION ${CMAKE_CONFIG_DEST}
        COMPONENT dev)

#-----------------------------------------------------------------------------
# Produce a pkg-config file


if(NOT WIN32)
	configure_file("cmake/opentxs-proto.pc.in" "opentxs-proto.pc" @ONLY)
	include(GNUInstallDirs)
	install(FILES "${CMAKE_CURRENT_BINARY_DIR}/opentxs-proto.pc"
		DESTINATION "${CMAKE_INSTALL_LIBDIR}/pkgconfig"
		COMPONENT main)
endif()


#-----------------------------------------------------------------------------
# Install

install(DIRECTORY ${CMAKE_CURRENT_SOURCE_DIR}/include/
        DESTINATION include
        COMPONENT dev
        FILES_MATCHING PATTERN "*.hpp")

install(DIRECTORY ${CMAKE_CURRENT_BINARY_DIR}/src/opentxs-proto/
        DESTINATION include/opentxs-proto
        COMPONENT dev
        FILES_MATCHING PATTERN "*.h")

#-----------------------------------------------------------------------------
# Uninstal
configure_file(
    "${CMAKE_CURRENT_SOURCE_DIR}/cmake/uninstall.cmake.in"
    "${CMAKE_CURRENT_BINARY_DIR}/uninstall.cmake"
    IMMEDIATE @ONLY)

add_custom_target(uninstall
    COMMAND ${CMAKE_COMMAND} -P ${CMAKE_CURRENT_BINARY_DIR}/uninstall.cmake)

endif (NOT ANDROID)
