add_definitions(-DOPENTXS_PROTO_INTERNAL_BUILD)

include_directories("${CMAKE_SOURCE_DIR}/include")

set(cxx-sources
  VerifyContacts.cpp
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
  hdpath/HDPath.cpp
  hdpath/HDPath_1.cpp
  paymentcode/PaymentCode.cpp
  paymentcode/PaymentCode_1.cpp
  contactdata/ContactData.cpp
  contactdata/ContactData_1.cpp
  contactsection/ContactSection.cpp
  contactsection/ContactSection_1.cpp
  contactitem/ContactItem.cpp
  contactitem/ContactItem_1.cpp
  verificationset/VerificationSet.cpp
  verificationset/VerificationSet_1.cpp
  verificationgroup/VerificationGroup.cpp
  verificationgroup/VerificationGroup_1.cpp
  verificationidentity/VerificationIdentity.cpp
  verificationidentity/VerificationIdentity_1.cpp
  verification/Verification.cpp
  verification/Verification_1.cpp
  storageroot/StorageRoot.cpp
  storageroot/StorageRoot_1.cpp
  storageitems/StorageItems.cpp
  storageitems/StorageItems_1.cpp
  storagecredentials/StorageCredentials.cpp
  storagecredentials/StorageCredentials_1.cpp
  storageitemhash/StorageItemHash.cpp
  storageitemhash/StorageItemHash_1.cpp
  storagenym/StorageNym.cpp
  storagenym/StorageNym_1.cpp
  storagenymlist/StorageNymList.cpp
  storagenymlist/StorageNymList_1.cpp
)

file(GLOB cxx-headers "${CMAKE_CURRENT_SOURCE_DIR}/../../include/opentxs-proto/verify/*.hpp")

add_library(opentxs-verify
  ${cxx-headers}
  ${cxx-sources}
)

target_link_libraries(opentxs-verify
  PRIVATE
  opentxs-proto
)

add_dependencies(opentxs-verify opentxs-proto)

if(NOT WIN32)
  include(GNUInstallDirs)
  install(TARGETS opentxs-verify
          DESTINATION ${CMAKE_INSTALL_LIBDIR}
          EXPORT opentxs-verifyTargets
          COMPONENT main)
endif()
