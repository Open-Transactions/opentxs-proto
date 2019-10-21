# Copyright (c) 2019 The Open-Transactions developers
# This Source Code Form is subject to the terms of the Mozilla Public
# License, v. 2.0. If a copy of the MPL was not distributed with this
# file, You can obtain one at http://mozilla.org/MPL/2.0/.

set(
  PROTO_SOURCES
  APIArgument.proto
  AcceptPendingPayment.proto
  AccountData.proto
  AccountEvent.proto
  AddClaim.proto
  AddContact.proto
  AsymmetricKey.proto
  Authority.proto
  Bailment.proto
  BailmentReply.proto
  BasketItem.proto
  BasketParams.proto
  Bip47Address.proto
  Bip47Channel.proto
  Bip47Direction.proto
  BitcoinBlockHeaderFields.proto
  BlindedSeriesList.proto
  BlockchainActivity.proto
  BlockchainAddress.proto
  BlockchainBlockHeader.proto
  BlockchainBlockLocalData.proto
  BlockchainEnums.proto
  BlockchainExternalAddress.proto
  BlockchainPreviousOutput.proto
  BlockchainTransaction.proto
  BlockchainTransactionInput.proto
  BlockchainTransactionOutput.proto
  BlockchainWalletKey.proto
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
  CurrencyParams.proto
  Enums.proto
  Envelope.proto
  EquityParams.proto
  EthereumBlockHeaderFields.proto
  Faucet.proto
  GCS.proto
  GetWorkflow.proto
  HDAccount.proto
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
  Nym.proto
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
  RPCEnums.proto
  RPCPush.proto
  RPCResponse.proto
  RPCStatus.proto
  RPCTask.proto
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
  StorageBlockchainTxo.proto
  StorageContactAddressIndex.proto
  StorageContactNymIndex.proto
  StorageContacts.proto
  StorageCredentials.proto
  StorageEnums.proto
  StorageIDList.proto
  StorageIssuers.proto
  StorageItemHash.proto
  StorageItems.proto
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
  StorageTxoIndex.proto
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

protobuf_generate_cpp(
  PROTO_SRC
  PROTO_HEADER
  ${PROTO_SOURCES}
  EXPORT_MACRO
  EXPORT
)

add_library(messages OBJECT ${PROTO_SRC} ${PROTO_HEADER})
add_library(opentxs-proto::messages ALIAS messages)

target_include_directories(messages SYSTEM PUBLIC ${Protobuf_INCLUDE_DIR})

if(NOT MSVC)
  target_compile_options(
    messages
    PRIVATE
      -Wno-effc++
      -Wno-missing-declarations
      -Wno-switch-default
      -Wno-switch-enum
      -Wno-undef
      -Wno-unused-macros
  )
endif()

set_target_properties(messages PROPERTIES POSITION_INDEPENDENT_CODE ON)

install(
  DIRECTORY ${CMAKE_CURRENT_BINARY_DIR}
  DESTINATION include
  COMPONENT dev
  FILES_MATCHING
  PATTERN "*.h"
)
