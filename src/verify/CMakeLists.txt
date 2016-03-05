include_directories("${CMAKE_SOURCE_DIR}/include")

set(cxx-sources
  VerifyContacts.cpp
  asymmetrickey/AsymmetricKey_1.cpp
  basketitem/BasketItem_1.cpp
  basketparams/BasketParams_1.cpp
  childcredentialparameters/ChildCredentialParameters_1.cpp
  claim/Claim_1.cpp
  contactdata/ContactData_1.cpp
  contactitem/ContactItem_1.cpp
  contactsection/ContactSection_1.cpp
  currencyparams/CurrencyParams_1.cpp
  credential/Credential_1.cpp
  credentialindex/CredentialIndex_1.cpp
  credentialset/CredentialSet_1.cpp
  hdpath/HDPath_1.cpp
  keycredential/KeyCredential_1.cpp
  listenaddress/ListenAddress_1.cpp
  mastercredentialparameters/MasterCredentialParameters_1.cpp
  nymidsource/NymIDSource_1.cpp
  paymentcode/PaymentCode_1.cpp
  seed/Seed_1.cpp
  servercontract/ServerContract_1.cpp
  signature/Signature_1.cpp
  sourceproof/SourceProof_1.cpp
  storagecredentials/StorageCredentials_1.cpp
  storageitems/StorageItems_1.cpp
  storageitemhash/StorageItemHash_1.cpp
  storagenym/StorageNym_1.cpp
  storagenymlist/StorageNymList_1.cpp
  storageroot/StorageRoot_1.cpp
  storageservers/StorageServers_1.cpp
  storageunits/StorageUnits_1.cpp
  unitdefinition/UnitDefinition_1.cpp
  verification/Verification_1.cpp
  verificationgroup/VerificationGroup_1.cpp
  verificationidentity/VerificationIdentity_1.cpp
  verificationset/VerificationSet_1.cpp
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
