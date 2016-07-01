if (CMAKE_COMPILER_IS_GNUCXX OR CMAKE_COMPILER_IS_CLANGXX)
  set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -Wno-shadow -Wno-error")
endif()

set(PROTO_SOURCES
    ${CMAKE_CURRENT_SOURCE_DIR}/AsymmetricKey.proto
    ${CMAKE_CURRENT_SOURCE_DIR}/Bailment.proto
    ${CMAKE_CURRENT_SOURCE_DIR}/BailmentReply.proto
    ${CMAKE_CURRENT_SOURCE_DIR}/BasketParams.proto
    ${CMAKE_CURRENT_SOURCE_DIR}/BasketItem.proto
    ${CMAKE_CURRENT_SOURCE_DIR}/ChildCredentialParameters.proto
    ${CMAKE_CURRENT_SOURCE_DIR}/Claim.proto
    ${CMAKE_CURRENT_SOURCE_DIR}/ContactData.proto
    ${CMAKE_CURRENT_SOURCE_DIR}/ContactEnums.proto
    ${CMAKE_CURRENT_SOURCE_DIR}/ContactItem.proto
    ${CMAKE_CURRENT_SOURCE_DIR}/ContactSection.proto
    ${CMAKE_CURRENT_SOURCE_DIR}/ContractEnums.proto
    ${CMAKE_CURRENT_SOURCE_DIR}/Credential.proto
    ${CMAKE_CURRENT_SOURCE_DIR}/CredentialIndex.proto
    ${CMAKE_CURRENT_SOURCE_DIR}/CredentialSet.proto
    ${CMAKE_CURRENT_SOURCE_DIR}/CurrencyParams.proto
    ${CMAKE_CURRENT_SOURCE_DIR}/Enums.proto
    ${CMAKE_CURRENT_SOURCE_DIR}/EquityParams.proto
    ${CMAKE_CURRENT_SOURCE_DIR}/HDPath.proto
    ${CMAKE_CURRENT_SOURCE_DIR}/KeyCredential.proto
    ${CMAKE_CURRENT_SOURCE_DIR}/ListenAddress.proto
    ${CMAKE_CURRENT_SOURCE_DIR}/MasterCredentialParameters.proto
    ${CMAKE_CURRENT_SOURCE_DIR}/NymIDSource.proto
    ${CMAKE_CURRENT_SOURCE_DIR}/OutBailment.proto
    ${CMAKE_CURRENT_SOURCE_DIR}/OutBailmentReply.proto
    ${CMAKE_CURRENT_SOURCE_DIR}/PaymentCode.proto
    ${CMAKE_CURRENT_SOURCE_DIR}/PeerEnums.proto
    ${CMAKE_CURRENT_SOURCE_DIR}/PeerObject.proto
    ${CMAKE_CURRENT_SOURCE_DIR}/PeerReply.proto
    ${CMAKE_CURRENT_SOURCE_DIR}/PeerRequest.proto
    ${CMAKE_CURRENT_SOURCE_DIR}/Seed.proto
    ${CMAKE_CURRENT_SOURCE_DIR}/ServerContract.proto
    ${CMAKE_CURRENT_SOURCE_DIR}/Signature.proto
    ${CMAKE_CURRENT_SOURCE_DIR}/SourceProof.proto
    ${CMAKE_CURRENT_SOURCE_DIR}/StorageCredentials.proto
    ${CMAKE_CURRENT_SOURCE_DIR}/StorageItemHash.proto
    ${CMAKE_CURRENT_SOURCE_DIR}/StorageItems.proto
    ${CMAKE_CURRENT_SOURCE_DIR}/StorageNym.proto
    ${CMAKE_CURRENT_SOURCE_DIR}/StorageNymList.proto
    ${CMAKE_CURRENT_SOURCE_DIR}/StorageRoot.proto
    ${CMAKE_CURRENT_SOURCE_DIR}/StorageSeeds.proto
    ${CMAKE_CURRENT_SOURCE_DIR}/StorageServers.proto
    ${CMAKE_CURRENT_SOURCE_DIR}/StorageUnits.proto
    ${CMAKE_CURRENT_SOURCE_DIR}/UnitDefinition.proto
    ${CMAKE_CURRENT_SOURCE_DIR}/Verification.proto
    ${CMAKE_CURRENT_SOURCE_DIR}/VerificationGroup.proto
    ${CMAKE_CURRENT_SOURCE_DIR}/VerificationIdentity.proto
    ${CMAKE_CURRENT_SOURCE_DIR}/VerificationSet.proto
)

PROTOBUF_GENERATE_CPP(
    PROTO_SRC
    PROTO_HEADER
    ${PROTO_SOURCES}
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

if (PYTHON)
    # why doesn't this work?  For some reason it doesn't actually generate .py files'
    #protobuf_generate_python(
        #PROTO_PYTHON
        #${PROTO_SOURCES}
    #)

    include(ExternalProject)

    set(WRAPPER_TYPE python)
    set(WRAPPER_DIR ${CMAKE_CURRENT_BINARY_DIR}/opentxsproto)
    set(STAGING_DIR ${CMAKE_CURRENT_BINARY_DIR}/${WRAPPER_TYPE}_stage)

    ExternalProject_Add(
        proto-${WRAPPER_TYPE}
        EXCLUDE_FROM_ALL 0
        DOWNLOAD_COMMAND mkdir -p ${WRAPPER_DIR}
        PATCH_COMMAND cp ${CMAKE_CURRENT_SOURCE_DIR}/setup.py ${CMAKE_CURRENT_BINARY_DIR}
        CONFIGURE_COMMAND touch ${WRAPPER_DIR}/__init__.py
        BINARY_DIR ${CMAKE_CURRENT_BINARY_DIR}
        BUILD_COMMAND protoc --proto_path=${CMAKE_CURRENT_SOURCE_DIR} --${WRAPPER_TYPE}_out=${WRAPPER_DIR} ${PROTO_SOURCES}
        BUILD_ALWAYS 1
        INSTALL_COMMAND python ${CMAKE_CURRENT_BINARY_DIR}/setup.py install -f --prefix=${STAGING_DIR})

    install(DIRECTORY ${STAGING_DIR}/ DESTINATION ${CMAKE_INSTALL_PREFIX} )
endif()

if (JAVASCRIPT)
    include(ExternalProject)

    set(WRAPPER_TYPE js)
    set(WRAPPER_DIR ${CMAKE_CURRENT_BINARY_DIR}/${WRAPPER_TYPE})

    ExternalProject_Add(
        proto-${WRAPPER_TYPE}
        EXCLUDE_FROM_ALL 0
        DOWNLOAD_COMMAND mkdir -p ${WRAPPER_DIR}
        CONFIGURE_COMMAND true
        BINARY_DIR ${CMAKE_CURRENT_BINARY_DIR}
        BUILD_COMMAND protoc --proto_path=${CMAKE_CURRENT_SOURCE_DIR} --${WRAPPER_TYPE}_out=${WRAPPER_DIR} ${PROTO_SOURCES}
        BUILD_ALWAYS 1
        INSTALL_COMMAND true)

    install(DIRECTORY ${WRAPPER_DIR} DESTINATION share/opentxs-proto )
endif()

if (JAVA)
    include(ExternalProject)

    set(WRAPPER_TYPE java)
    set(WRAPPER_DIR ${CMAKE_CURRENT_BINARY_DIR}/${WRAPPER_TYPE})

    ExternalProject_Add(
        proto-${WRAPPER_TYPE}
        EXCLUDE_FROM_ALL 0
        DOWNLOAD_COMMAND mkdir -p ${WRAPPER_DIR}
        CONFIGURE_COMMAND true
        BINARY_DIR ${CMAKE_CURRENT_BINARY_DIR}
        BUILD_COMMAND protoc --proto_path=${CMAKE_CURRENT_SOURCE_DIR} --${WRAPPER_TYPE}_out=${WRAPPER_DIR} ${PROTO_SOURCES}
        BUILD_ALWAYS 1
        INSTALL_COMMAND true)

    install(DIRECTORY ${WRAPPER_DIR} DESTINATION share/opentxs-proto )
endif()
