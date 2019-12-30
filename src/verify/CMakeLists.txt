# Copyright (c) 2019 The Open-Transactions developers
# This Source Code Form is subject to the terms of the Mozilla Public
# License, v. 2.0. If a copy of the MPL was not distributed with this
# file, You can obtain one at http://mozilla.org/MPL/2.0/.

set(
  cxx-sources
  Check.cpp
  Contact.cpp
  VerifyBlockchain.cpp
  VerifyCash.cpp
  VerifyConsensus.cpp
  VerifyContacts.cpp
  VerifyContracts.cpp
  VerifyCredentials.cpp
  VerifyOTX.cpp
  VerifyPeer.cpp
  VerifyRPC.cpp
  VerifyStorage.cpp
  VerifyWorkflows.cpp
  acceptpendingpayment/AcceptPendingPayment_1.cpp
  accountdata/AccountData_1.cpp
  accountevent/AccountEvent_1.cpp
  addclaim/AddClaim_1.cpp
  addcontact/AddContact_1.cpp
  apiargument/APIArgument_1.cpp
  asymmetrickey/AsymmetricKey_1.cpp
  authority/Authority_1.cpp
  bailment/Bailment_1.cpp
  bailmentreply/BailmentReply_1.cpp
  basketitem/BasketItem_1.cpp
  basketparams/BasketParams_1.cpp
  bip47address/Bip47Address_1.cpp
  bip47channel/Bip47Channel_1.cpp
  bip47direction/Bip47Direction_1.cpp
  bitcoinblockheaderfields/BitcoinBlockHeaderFields_1.cpp
  blindedserieslist/BlindedSeriesList.cpp
  blockchainactivity/BlockchainActivity_1.cpp
  blockchainaddress/BlockchainAddress_1.cpp
  blockchainblockheader/BlockchainBlockHeader_1.cpp
  blockchainblocklocaldata/BlockchainBlockLocalData_1.cpp
  blockchainexternaladdress/BlockchainExternalAddress_1.cpp
  blockchainpreviousoutput/BlockchainPreviousOutput_1.cpp
  blockchaintransaction/BlockchainTransaction_1.cpp
  blockchaintransactioninput/BlockchainTransactionInput_1.cpp
  blockchaintransactionoutput/BlockchainTransactionOutput_1.cpp
  blockchainwalletkey/BlockchainWalletKey_1.cpp
  childcredentialparameters/ChildCredentialParameters_1.cpp
  ciphertext/Ciphertext_1.cpp
  claim/Claim_1.cpp
  clientcontext/ClientContext_1.cpp
  connectioninfo/ConnectionInfo_1.cpp
  connectioninforeply/ConnectionInfoReply_1.cpp
  contact/Contact_1.cpp
  contactdata/ContactData_1.cpp
  contactevent/ContactEvent_1.cpp
  contactitem/ContactItem_1.cpp
  contactsection/ContactSection_1.cpp
  context/Context_1.cpp
  createinstrumentdefinition/CreateInstrumentDefinition_1.cpp
  createnym/CreateNym_1.cpp
  credential/Credential_1.cpp
  currencyparams/CurrencyParams_1.cpp
  envelope/Envelope_1.cpp
  equityparams/EquityParams_1.cpp
  ethereumblockheaderfields/EthereumBlockHeaderFields_1.cpp
  faucet/Faucet_1.cpp
  gcs/GCS_1.cpp
  getworkflow/GetWorkflow_1.cpp
  hdaccount/HDAccount_1.cpp
  hdpath/HDPath_1.cpp
  hdseed/HDSeed_1.cpp
  instrumentrevision/InstrumentRevision_1.cpp
  issuer/Issuer_1.cpp
  keycredential/KeyCredential_1.cpp
  listenaddress/ListenAddress_1.cpp
  lucretokendata/LucreTokenData_1.cpp
  mastercredentialparameters/MasterCredentialParameters_1.cpp
  modifyaccount/ModifyAccount_1.cpp
  movefunds/MoveFunds_1.cpp
  noticeacknowledgement/NoticeAcknowledgement_1.cpp
  nym/Nym_1.cpp
  nymidsource/NymIDSource_1.cpp
  otxpush/OTXPush_1.cpp
  outbailment/OutBailment_1.cpp
  outbailmentreply/OutBailmentReply_1.cpp
  pairevent/PairEvent_1.cpp
  paymentcode/PaymentCode_1.cpp
  paymentevent/PaymentEvent_1.cpp
  paymentevent/PaymentEvent_2.cpp
  paymentevent/PaymentEvent_3.cpp
  paymentworkflow/PaymentWorkflow_1.cpp
  paymentworkflow/PaymentWorkflow_2.cpp
  paymentworkflow/PaymentWorkflow_3.cpp
  peerobject/PeerObject_1.cpp
  peerobject/PeerObject_2.cpp
  peerobject/PeerObject_3.cpp
  peerreply/PeerReply_1.cpp
  peerreply/PeerReply_2.cpp
  peerreply/PeerReply_3.cpp
  peerreply/PeerReply_4.cpp
  peerrequest/PeerRequest_1.cpp
  peerrequest/PeerRequest_2.cpp
  peerrequest/PeerRequest_3.cpp
  peerrequest/PeerRequest_4.cpp
  peerrequesthistory/PeerRequestHistory_1.cpp
  peerrequestworkflow/PeerRequestWorkflow_1.cpp
  pendingbailment/PendingBailment_1.cpp
  pendingcommand/PendingCommand_1.cpp
  purse/Purse_1.cpp
  purseexchange/PurseExchange_1.cpp
  rpccommand/RPCCommand_1.cpp
  rpccommand/RPCCommand_2.cpp
  rpcpush/RPCPush_1.cpp
  rpcresponse/RPCResponse_1.cpp
  rpcresponse/RPCResponse_2.cpp
  rpcstatus/RPCStatus_1.cpp
  rpctask/RPCTask_1.cpp
  seed/Seed_1.cpp
  sendmessage/SendMessage_1.cpp
  sendpayment/SendPayment_1.cpp
  servercontext/ServerContext_1.cpp
  servercontext/ServerContext_2.cpp
  servercontract/ServerContract_1.cpp
  serverreply/ServerReply_1.cpp
  serverrequest/ServerRequest_1.cpp
  sessiondata/SessionData_1.cpp
  signature/Signature_1.cpp
  signature/Signature_2.cpp
  signature/Signature_3.cpp
  sourceproof/SourceProof_1.cpp
  spenttokenlist/SpentTokenList_1.cpp
  storageaccountindex/StorageAccountIndex_1.cpp
  storageaccounts/StorageAccounts_1.cpp
  storagebip47addressindex/StorageBip47AddressIndex_1.cpp
  storagebip47channellist/StorageBip47ChannelList_1.cpp
  storagebip47contexts/StorageBip47Contexts_1.cpp
  storagebip47nymaddressindex/StorageBip47NymAddressIndex_1.cpp
  storageblockchainaccountlist/StorageBlockchainAccountList_1.cpp
  storageblockchaintransactions/StorageBlockchainTransactions_1.cpp
  storageblockchaintxo/StorageBlockchainTxo_1.cpp
  storagecontactaddressindex/StorageContactAddressIndex_1.cpp
  storagecontactnymindex/StorageContactNymIndex_1.cpp
  storagecontacts/StorageContacts_1.cpp
  storagecontacts/StorageContacts_2.cpp
  storagecredentials/StorageCredentials_1.cpp
  storageidlist/StorageIDList_1.cpp
  storageissuers/StorageIssuers_1.cpp
  storageitemhash/StorageItemHash_1.cpp
  storageitemhash/StorageItemHash_2.cpp
  storageitems/StorageItems_1.cpp
  storageitems/StorageItems_2.cpp
  storageitems/StorageItems_3.cpp
  storageitems/StorageItems_4.cpp
  storageitems/StorageItems_5.cpp
  storageitems/StorageItems_6.cpp
  storagenotary/StorageNotary_1.cpp
  storagenym/StorageNym_1.cpp
  storagenym/StorageNym_2.cpp
  storagenym/StorageNym_3.cpp
  storagenym/StorageNym_4.cpp
  storagenym/StorageNym_5.cpp
  storagenym/StorageNym_6.cpp
  storagenym/StorageNym_7.cpp
  storagenym/StorageNym_8.cpp
  storagenym/StorageNym_9.cpp
  storagenymlist/StorageNymList_1.cpp
  storagepaymentworkflows/StoragePaymentWorkflows_1.cpp
  storagepurse/StoragePurse_1.cpp
  storageroot/StorageRoot_1.cpp
  storageroot/StorageRoot_2.cpp
  storageseeds/StorageSeeds_1.cpp
  storageservers/StorageServers_1.cpp
  storagethread/StorageThread_1.cpp
  storagethreaditem/StorageThreadItem_1.cpp
  storagetxoindex/StorageTxoIndex_1.cpp
  storageunits/StorageUnits_1.cpp
  storageworkflowindex/StorageWorkflowIndex_1.cpp
  storageworkflowtype/StorageWorkflowType_1.cpp
  storageworkflowtype/StorageWorkflowType_2.cpp
  storageworkflowtype/StorageWorkflowType_3.cpp
  storesecret/StoreSecret_1.cpp
  symmetrickey/SymmetricKey_1.cpp
  taggedkey/TaggedKey_1.cpp
  taskcomplete/TaskComplete_1.cpp
  token/Token_1.cpp
  transactiondata/TransactionData_1.cpp
  unitaccountmap/UnitAccountMap_1.cpp
  unitdefinition/UnitDefinition_1.cpp
  unitdefinition/UnitDefinition_2.cpp
  verification/Verification_1.cpp
  verificationgroup/VerificationGroup_1.cpp
  verificationidentity/VerificationIdentity_1.cpp
  verificationoffer/VerificationOffer_1.cpp
  verificationset/VerificationSet_1.cpp
  verifyclaim/VerifyClaim_1.cpp
)

file(GLOB cxx-headers
     "${CMAKE_CURRENT_SOURCE_DIR}/../../include/opentxs-proto/verify/*.hpp")

add_library(verify OBJECT ${cxx-headers} ${cxx-sources})
add_library(opentxs-proto::verify ALIAS verify)
add_dependencies(verify messages)

target_include_directories(verify SYSTEM PUBLIC ${Protobuf_INCLUDE_DIR})
target_include_directories(
  verify
  PUBLIC $<BUILD_INTERFACE:${opentxs-proto_SOURCE_DIR}/include>
  PRIVATE $<BUILD_INTERFACE:${opentxs-proto_SOURCE_DIR}/src>
)
target_include_directories(
  verify SYSTEM
  PUBLIC
    ${Protobuf_INCLUDE_DIR} $<BUILD_INTERFACE:${opentxs-proto_BINARY_DIR}/src>
)

if(NOT MSVC)
  target_compile_options(verify PRIVATE -Wno-unused-parameter)
endif()

set_target_properties(verify PROPERTIES POSITION_INDEPENDENT_CODE ON)

install(
  DIRECTORY ${CMAKE_CURRENT_SOURCE_DIR}/../../include/
  DESTINATION include
  COMPONENT dev
  FILES_MATCHING
  PATTERN "*.hpp"
)
