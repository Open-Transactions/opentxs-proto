# Copyright (c) 2018 The Open-Transactions developers
# This Source Code Form is subject to the terms of the Mozilla Public
# License, v. 2.0. If a copy of the MPL was not distributed with this
# file, You can obtain one at http://mozilla.org/MPL/2.0/.

set(MODULE_NAME generated)

set(PROTO_SOURCES
    AcceptPendingPayment.proto
    AccountData.proto
    AccountEvent.proto
    AddClaim.proto
    AddContact.proto
    APIArgument.proto
    AsymmetricKey.proto
    Bailment.proto
    BailmentReply.proto
    BasketParams.proto
    BasketItem.proto
    Bip44Account.proto
    Bip44Address.proto
    Bip47Address.proto
    Bip47Channel.proto
    Bip47Direction.proto
    BlindedSeriesList.proto
    BlockchainTransaction.proto
    BlockchainTransactionInput.proto
    BlockchainTransactionOutput.proto
    CashEnums.proto
    ChildCredentialParameters.proto
    Ciphertext.proto
    Claim.proto
    ClientContext.proto
    ConnectionInfo.proto
    ConnectionInfoReply.proto
    ConsensusEnums.proto
    Contact.proto
    ContactData.proto
    ContactEnums.proto
    ContactEvent.proto
    ContactItem.proto
    ContactSection.proto
    Context.proto
    ContractEnums.proto
    CreateInstrumentDefinition.proto
    CreateNym.proto
    Credential.proto
    CredentialIndex.proto
    CredentialSet.proto
    CurrencyParams.proto
    Enums.proto
    Envelope.proto
    EquityParams.proto
    Faucet.proto
    GetWorkflow.proto
    HDPath.proto
    HDSeed.proto
    InstrumentRevision.proto
    Issuer.proto
    KeyCredential.proto
    ListenAddress.proto
    LucreTokenData.proto
    MasterCredentialParameters.proto
    ModifyAccount.proto
    MoveFunds.proto
    NoticeAcknowledgement.proto
    NymIDSource.proto
    OTXEnums.proto
    OTXPush.proto
    OutBailment.proto
    OutBailmentReply.proto
    PairEvent.proto
    PaymentCode.proto
    PaymentEvent.proto
    PaymentWorkflow.proto
    PaymentWorkflowEnums.proto
    PeerEnums.proto
    PeerObject.proto
    PeerReply.proto
    PeerRequest.proto
    PeerRequestHistory.proto
    PeerRequestWorkflow.proto
    PendingBailment.proto
    PendingCommand.proto
    Purse.proto
    PurseExchange.proto
    RPCCommand.proto
    RPCPush.proto
    RPCResponse.proto
    RPCStatus.proto
    RPCTask.proto
    RPCEnums.proto
    Seed.proto
    SendMessage.proto
    SendPayment.proto
    ServerContext.proto
    ServerContract.proto
    ServerReply.proto
    ServerRequest.proto
    SessionData.proto
    SessionKey.proto
    Signature.proto
    SourceProof.proto
    SpentTokenList.proto
    StorageAccountIndex.proto
    StorageAccounts.proto
    StorageBip47AddressIndex.proto
    StorageBip47ChannelList.proto
    StorageBip47Contexts.proto
    StorageBip47NymAddressIndex.proto
    StorageBlockchainAccountList.proto
    StorageBlockchainTransactions.proto
    StorageContactAddressIndex.proto
    StorageContactNymIndex.proto
    StorageContacts.proto
    StorageCredentials.proto
    StorageEnums.proto
    StorageIDList.proto
    StorageItemHash.proto
    StorageItems.proto
    StorageIssuers.proto
    StorageNotary.proto
    StorageNym.proto
    StorageNymList.proto
    StoragePaymentWorkflows.proto
    StoragePurse.proto
    StorageRoot.proto
    StorageSeeds.proto
    StorageServers.proto
    StorageThread.proto
    StorageThreadItem.proto
    StorageUnits.proto
    StorageWorkflowIndex.proto
    StorageWorkflowType.proto
    StoreSecret.proto
    SymmetricKey.proto
    TaskComplete.proto
    Token.proto
    TransactionData.proto
    UnitAccountMap.proto
    UnitDefinition.proto
    Verification.proto
    VerificationGroup.proto
    VerificationIdentity.proto
    VerificationOffer.proto
    VerificationSet.proto
    VerifyClaim.proto
    ZMQEnums.proto
)

PROTOBUF_GENERATE_CPP(
    PROTO_SRC
    PROTO_HEADER
    ${PROTO_SOURCES}
)

add_library(${MODULE_NAME} OBJECT
  ${PROTO_SRC}
  ${PROTO_HEADER}
)

target_compile_options(${MODULE_NAME} PRIVATE -Wno-error -Wno-unused-macros -Wno-undef -Wno-switch-default)

if (PYTHON OR PYTHON2 OR PYTHON3)
    # why doesn't this work?  For some reason it doesn't actually generate .py files'
    #protobuf_generate_python(
        #PROTO_PYTHON
        #${PROTO_SOURCES}
    #)

    include_directories(${PYTHON_INCLUDE_PATH})

    include(ExternalProject)

    set(WRAPPER_TYPE python)
    set(WRAPPER_DIR ${CMAKE_CURRENT_BINARY_DIR}/opentxsproto)
    set(STAGING_DIR ${CMAKE_CURRENT_BINARY_DIR}/${WRAPPER_TYPE}_stage)
    set(SITE_PACKAGES_PATH ${STAGING_DIR}/lib/python${PYTHON_VERSION_MAJOR}.${PYTHON_VERSION_MINOR}/site-packages)
    configure_file("setup.py.in" "${CMAKE_CURRENT_BINARY_DIR}/setup.py" @ONLY)

    ExternalProject_Add(
        proto-${WRAPPER_TYPE}
        EXCLUDE_FROM_ALL 0
        DOWNLOAD_COMMAND mkdir -p ${WRAPPER_DIR}
        CONFIGURE_COMMAND touch ${WRAPPER_DIR}/__init__.py
        BINARY_DIR ${CMAKE_CURRENT_BINARY_DIR}
        BUILD_COMMAND protoc --proto_path=${CMAKE_CURRENT_SOURCE_DIR} --${WRAPPER_TYPE}_out=${WRAPPER_DIR} ${PROTO_SOURCES}
        BUILD_ALWAYS 1

        INSTALL_COMMAND export PYTHONPATH=${SITE_PACKAGES_PATH} && mkdir -p ${SITE_PACKAGES_PATH} && ${PYTHON_EXECUTABLE} ${CMAKE_CURRENT_BINARY_DIR}/setup.py install --prefix=${STAGING_DIR} sdist --dist-dir=${PYTHON_DIST} bdist_wheel --dist-dir=${PYTHON_DIST})
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

    install(DIRECTORY ${WRAPPER_DIR} DESTINATION share/${MODULE_NAME} )
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

    install(DIRECTORY ${WRAPPER_DIR} DESTINATION share/${MODULE_NAME} )
endif()
