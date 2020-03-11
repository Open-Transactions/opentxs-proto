# Copyright (c) 2020 The Open-Transactions developers
# This Source Code Form is subject to the terms of the Mozilla Public
# License, v. 2.0. If a copy of the MPL was not distributed with this
# file, You can obtain one at http://mozilla.org/MPL/2.0/.

set(CPACK_PACKAGE_NAME "${CMAKE_PROJECT_NAME}")
set(CPACK_PACKAGE_VENDOR "The Open-Transactions Project")
set(
  CPACK_PACKAGE_DESCRIPTION_SUMMARY
  "Protobuf definition library for Open-Transactions"
)
set(CPACK_PACKAGE_INSTALL_DIRECTORY ${CPACK_PACKAGE_NAME})
set(CPACK_PACKAGE_VERSION_MAJOR ${VERSION_MAJOR})
set(CPACK_PACKAGE_VERSION_MINOR ${VERSION_MINOR})

if("${VERSION_SHA1}" STREQUAL "")
  set(CPACK_PACKAGE_VERSION_PATCH "${VERSION_BUGFIX}")
else()
  set(CPACK_PACKAGE_VERSION_PATCH "${VERSION_BUGFIX}-${VERSION_NEW_COMMITS}-${VERSION_SHA1}")
endif()

set(CPACK_VERBATIM_VARIABLES YES)
set(CPACK_RESOURCE_FILE_LICENSE "${opentxs-proto_SOURCE_DIR}/LICENSE")
set(CPACK_RESOURCE_FILE_README "${opentxs-proto_SOURCE_DIR}/README.md")

if(WIN32)
  set(CPACK_GENERATOR ZIP)
elseif(APPLE)
  set(CPACK_GENERATOR TGZ)
elseif(CMAKE_SYSTEM_NAME STREQUAL "Linux")
  set(CPACK_GENERATOR TGZ)
else()
  set(CPACK_GENERATOR TGZ)
endif()

include(CPack)
