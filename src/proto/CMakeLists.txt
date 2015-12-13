if (CMAKE_COMPILER_IS_GNUCXX OR CMAKE_COMPILER_IS_CLANGXX)
  set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -Wno-shadow -Wno-error")
endif()

PROTOBUF_GENERATE_CPP(
    PROTO_SRC PROTO_HEADER
    Enums.proto
    Signature.proto
    AsymmetricKey.proto
    Credential.proto
    KeyCredential.proto
    ChildCredentialParameters.proto
    NymIDSource.proto
    SourceProof.proto
    MasterCredentialParameters.proto
    CredentialIndex.proto
    CredentialSet.proto
    HDPath.proto
    PaymentCode.proto
    ContactEnums.proto
    ContactData.proto
    ContactSection.proto
    ContactItem.proto
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
