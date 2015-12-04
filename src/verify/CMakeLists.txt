add_definitions(-DOPENTXS_PROTO_INTERNAL_BUILD)

set(cxx-sources
  asymmetrickey/AsymmetricKey.cpp
  asymmetrickey/AsymmetricKey_1.cpp
  childcredentialparameters/ChildCredentialParameters.cpp
  childcredentialparameters/ChildCredentialParameters_1.cpp
  credential/Credential.cpp
  credential/Credential_1.cpp
  keycredential/KeyCredential.cpp
  keycredential/KeyCredential_1.cpp
  mastercredentialparameters/MasterCredentialParameters.cpp
  mastercredentialparameters/MasterCredentialParameters_1.cpp
  nymidsource/NymIDSource.cpp
  nymidsource/NymIDSource_1.cpp
  sourceproof/SourceProof.cpp
  sourceproof/SourceProof_1.cpp
  signature/Signature.cpp
  signature/Signature_1.cpp
  credentialindex/CredentialIndex.cpp
  credentialindex/CredentialIndex_1.cpp
  credentialset/CredentialSet.cpp
  credentialset/CredentialSet_1.cpp
)

file(GLOB cxx-headers "${CMAKE_CURRENT_SOURCE_DIR}/../../include/verify/*.hpp")

add_library(opentxs-verify
  STATIC
  ${cxx-headers}
  ${cxx-sources}
)

target_link_libraries(opentxs-verify
  PRIVATE
  opentxs-proto
)

add_dependencies(opentxs-verify opentxs-proto)

set_target_properties(opentxs-verify
  PROPERTIES
  OUTPUT_NAME opentxs-verify-${VERSION_MAJOR}.${VERSION_MINOR}
)

if(NOT WIN32)
  include(GNUInstallDirs)
  install(TARGETS opentxs-verify
          DESTINATION ${CMAKE_INSTALL_LIBDIR}
          EXPORT opentxs-verifyTargets
          COMPONENT main)
endif()
