if (CMAKE_COMPILER_IS_GNUCXX OR CMAKE_COMPILER_IS_CLANGXX)
  set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -Wno-shadow -Wno-error")
endif()

PROTOBUF_GENERATE_CPP(
    PROTO_SRC PROTO_HEADER
    AsymmetricKey.proto
    BasketParams.proto
    BasketItem.proto
    ChildCredentialParameters.proto
    Claim.proto
    ContactData.proto
    ContactEnums.proto
    ContactItem.proto
    ContactSection.proto
    Credential.proto
    CredentialIndex.proto
    CredentialSet.proto
    CurrencyParams.proto
    Enums.proto
    EquityParams.proto
    HDPath.proto
    KeyCredential.proto
    ListenAddress.proto
    MasterCredentialParameters.proto
    NymIDSource.proto
    PaymentCode.proto
    Seed.proto
    ServerContract.proto
    Signature.proto
    SourceProof.proto
    StorageCredentials.proto
    StorageItemHash.proto
    StorageItems.proto
    StorageNym.proto
    StorageNymList.proto
    StorageRoot.proto
    StorageServers.proto
    StorageUnits.proto
    UnitDefinition.proto
    Verification.proto
    VerificationGroup.proto
    VerificationIdentity.proto
    VerificationSet.proto
)

include_directories(SYSTEM ${PROTOBUF_INCLUDE_DIR})

add_library(opentxs-proto
  ${PROTO_SRC}
  ${PROTO_HEADER}
)

target_link_libraries(opentxs-proto PUBLIC ${PROTOBUF_LITE_LIBRARIES})

if(NOT WIN32)
  include(GNUInstallDirs)
  install(TARGETS opentxs-proto
          DESTINATION ${CMAKE_INSTALL_LIBDIR}
          EXPORT opentxs-protoTargets
          COMPONENT main)
endif()
