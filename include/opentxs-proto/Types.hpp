// Copyright (c) 2018 The Open-Transactions developers
// This Source Code Form is subject to the terms of the Mozilla Public
// License, v. 2.0. If a copy of the MPL was not distributed with this
// file, You can obtain one at http://mozilla.org/MPL/2.0/.

#ifndef OPENTXS_PROTO_TYPES_HPP
#define OPENTXS_PROTO_TYPES_HPP

#define CONTACT_VERSION 5

#ifdef _WIN32
#pragma warning(push)
#pragma warning(disable : 4244)
#pragma warning(disable : 4267)
#else
#pragma GCC diagnostic push
#pragma GCC diagnostic ignored "-Wshadow"
#ifndef __clang__
// -Wuseless-cast does not exist in clang
#pragma GCC diagnostic ignored "-Wuseless-cast"
#endif
#endif

#ifndef PROTOBUF_INLINE_NOT_IN_HEADERS
#define PROTOBUF_INLINE_NOT_IN_HEADERS 0
#endif

// IWYU pragma: begin_exports
#include <opentxs-proto/AcceptPendingPayment.pb.h>
#include <opentxs-proto/AccountData.pb.h>
#include <opentxs-proto/AccountEvent.pb.h>
#include <opentxs-proto/AddClaim.pb.h>
#include <opentxs-proto/AddContact.pb.h>
#include <opentxs-proto/APIArgument.pb.h>
#include <opentxs-proto/AsymmetricKey.pb.h>
#include <opentxs-proto/Bailment.pb.h>
#include <opentxs-proto/BailmentReply.pb.h>
#include <opentxs-proto/BasketItem.pb.h>
#include <opentxs-proto/BasketParams.pb.h>
#include <opentxs-proto/Bip44Account.pb.h>
#include <opentxs-proto/Bip44Address.pb.h>
#include <opentxs-proto/Bip47Address.pb.h>
#include <opentxs-proto/Bip47Channel.pb.h>
#include <opentxs-proto/Bip47Direction.pb.h>
#include <opentxs-proto/BlockchainTransaction.pb.h>
#include <opentxs-proto/BlockchainTransactionInput.pb.h>
#include <opentxs-proto/BlockchainTransactionOutput.pb.h>
#include <opentxs-proto/ChildCredentialParameters.pb.h>
#include <opentxs-proto/Ciphertext.pb.h>
#include <opentxs-proto/Claim.pb.h>
#include <opentxs-proto/ClientContext.pb.h>
#include <opentxs-proto/ConnectionInfo.pb.h>
#include <opentxs-proto/ConnectionInfoReply.pb.h>
#include <opentxs-proto/ConsensusEnums.pb.h>
#include <opentxs-proto/Contact.pb.h>
#include <opentxs-proto/ContactData.pb.h>
#include <opentxs-proto/ContactEnums.pb.h>
#include <opentxs-proto/ContactEvent.pb.h>
#include <opentxs-proto/ContactItem.pb.h>
#include <opentxs-proto/ContactSection.pb.h>
#include <opentxs-proto/Context.pb.h>
#include <opentxs-proto/ContractEnums.pb.h>
#include <opentxs-proto/CreateInstrumentDefinition.pb.h>
#include <opentxs-proto/CreateNym.pb.h>
#include <opentxs-proto/Credential.pb.h>
#include <opentxs-proto/CredentialIndex.pb.h>
#include <opentxs-proto/CredentialSet.pb.h>
#include <opentxs-proto/CurrencyParams.pb.h>
#include <opentxs-proto/Enums.pb.h>
#include <opentxs-proto/Envelope.pb.h>
#include <opentxs-proto/EquityParams.pb.h>
#include <opentxs-proto/Faucet.pb.h>
#include <opentxs-proto/HDPath.pb.h>
#include <opentxs-proto/HDSeed.pb.h>
#include <opentxs-proto/InstrumentRevision.pb.h>
#include <opentxs-proto/Issuer.pb.h>
#include <opentxs-proto/KeyCredential.pb.h>
#include <opentxs-proto/ListenAddress.pb.h>
#include <opentxs-proto/MasterCredentialParameters.pb.h>
#include <opentxs-proto/MoveFunds.pb.h>
#include <opentxs-proto/NoticeAcknowledgement.pb.h>
#include <opentxs-proto/NymIDSource.pb.h>
#include <opentxs-proto/OTXEnums.pb.h>
#include <opentxs-proto/OTXPush.pb.h>
#include <opentxs-proto/OutBailment.pb.h>
#include <opentxs-proto/OutBailmentReply.pb.h>
#include <opentxs-proto/PairEvent.pb.h>
#include <opentxs-proto/PaymentCode.pb.h>
#include <opentxs-proto/PaymentEvent.pb.h>
#include <opentxs-proto/PaymentWorkflow.pb.h>
#include <opentxs-proto/PaymentWorkflowEnums.pb.h>
#include <opentxs-proto/PeerEnums.pb.h>
#include <opentxs-proto/PeerObject.pb.h>
#include <opentxs-proto/PeerReply.pb.h>
#include <opentxs-proto/PeerRequest.pb.h>
#include <opentxs-proto/PeerRequestHistory.pb.h>
#include <opentxs-proto/PeerRequestWorkflow.pb.h>
#include <opentxs-proto/PendingBailment.pb.h>
#include <opentxs-proto/RPCCommand.pb.h>
#include <opentxs-proto/RPCEnums.pb.h>
#include <opentxs-proto/RPCPush.pb.h>
#include <opentxs-proto/RPCResponse.pb.h>
#include <opentxs-proto/RPCStatus.pb.h>
#include <opentxs-proto/RPCTask.pb.h>
#include <opentxs-proto/Seed.pb.h>
#include <opentxs-proto/SendMessage.pb.h>
#include <opentxs-proto/SendPayment.pb.h>
#include <opentxs-proto/ServerContext.pb.h>
#include <opentxs-proto/ServerContract.pb.h>
#include <opentxs-proto/ServerReply.pb.h>
#include <opentxs-proto/ServerRequest.pb.h>
#include <opentxs-proto/SessionData.pb.h>
#include <opentxs-proto/Signature.pb.h>
#include <opentxs-proto/SourceProof.pb.h>
#include <opentxs-proto/StorageAccountIndex.pb.h>
#include <opentxs-proto/StorageAccounts.pb.h>
#include <opentxs-proto/StorageBip47AddressIndex.pb.h>
#include <opentxs-proto/StorageBip47ChannelList.pb.h>
#include <opentxs-proto/StorageBip47Contexts.pb.h>
#include <opentxs-proto/StorageBip47NymAddressIndex.pb.h>
#include <opentxs-proto/StorageBlockchainAccountList.pb.h>
#include <opentxs-proto/StorageBlockchainTransactions.pb.h>
#include <opentxs-proto/StorageContactAddressIndex.pb.h>
#include <opentxs-proto/StorageContactNymIndex.pb.h>
#include <opentxs-proto/StorageContacts.pb.h>
#include <opentxs-proto/StorageCredentials.pb.h>
#include <opentxs-proto/StorageEnums.pb.h>
#include <opentxs-proto/StorageIDList.pb.h>
#include <opentxs-proto/StorageIssuers.pb.h>
#include <opentxs-proto/StorageItemHash.pb.h>
#include <opentxs-proto/StorageItems.pb.h>
#include <opentxs-proto/StorageNym.pb.h>
#include <opentxs-proto/StorageNymList.pb.h>
#include <opentxs-proto/StoragePaymentWorkflows.pb.h>
#include <opentxs-proto/StorageRoot.pb.h>
#include <opentxs-proto/StorageSeeds.pb.h>
#include <opentxs-proto/StorageServers.pb.h>
#include <opentxs-proto/StorageThread.pb.h>
#include <opentxs-proto/StorageThreadItem.pb.h>
#include <opentxs-proto/StorageUnits.pb.h>
#include <opentxs-proto/StorageWorkflowIndex.pb.h>
#include <opentxs-proto/StorageWorkflowType.pb.h>
#include <opentxs-proto/StoreSecret.pb.h>
#include <opentxs-proto/SymmetricKey.pb.h>
#include <opentxs-proto/TaskComplete.pb.h>
#include <opentxs-proto/UnitAccountMap.pb.h>
#include <opentxs-proto/UnitDefinition.pb.h>
#include <opentxs-proto/Verification.pb.h>
#include <opentxs-proto/VerificationGroup.pb.h>
#include <opentxs-proto/VerificationIdentity.pb.h>
#include <opentxs-proto/VerificationOffer.pb.h>
#include <opentxs-proto/VerificationSet.pb.h>
#include <opentxs-proto/VerifyClaim.pb.h>
#include <opentxs-proto/ZMQEnums.pb.h>
#include <opentxs-proto/verify/AcceptPendingPayment.hpp>
#include <opentxs-proto/verify/AccountData.hpp>
#include <opentxs-proto/verify/AccountEvent.hpp>
#include <opentxs-proto/verify/AddClaim.hpp>
#include <opentxs-proto/verify/AddContact.hpp>
#include <opentxs-proto/verify/APIArgument.hpp>
#include <opentxs-proto/verify/AsymmetricKey.hpp>
#include <opentxs-proto/verify/Bailment.hpp>
#include <opentxs-proto/verify/BailmentReply.hpp>
#include <opentxs-proto/verify/BasketItem.hpp>
#include <opentxs-proto/verify/BasketParams.hpp>
#include <opentxs-proto/verify/Bip44Account.hpp>
#include <opentxs-proto/verify/Bip44Address.hpp>
#include <opentxs-proto/verify/Bip47Address.hpp>
#include <opentxs-proto/verify/Bip47Channel.hpp>
#include <opentxs-proto/verify/Bip47Direction.hpp>
#include <opentxs-proto/verify/BlockchainTransaction.hpp>
#include <opentxs-proto/verify/BlockchainTransactionInput.hpp>
#include <opentxs-proto/verify/BlockchainTransactionOutput.hpp>
#include <opentxs-proto/verify/ChildCredentialParameters.hpp>
#include <opentxs-proto/verify/Ciphertext.hpp>
#include <opentxs-proto/verify/Claim.hpp>
#include <opentxs-proto/verify/ClientContext.hpp>
#include <opentxs-proto/verify/ConnectionInfo.hpp>
#include <opentxs-proto/verify/ConnectionInfoReply.hpp>
#include <opentxs-proto/verify/Contact.hpp>
#include <opentxs-proto/verify/ContactData.hpp>
#include <opentxs-proto/verify/ContactEvent.hpp>
#include <opentxs-proto/verify/ContactItem.hpp>
#include <opentxs-proto/verify/ContactSection.hpp>
#include <opentxs-proto/verify/Context.hpp>
#include <opentxs-proto/verify/CreateInstrumentDefinition.hpp>
#include <opentxs-proto/verify/CreateNym.hpp>
#include <opentxs-proto/verify/Credential.hpp>
#include <opentxs-proto/verify/CredentialIndex.hpp>
#include <opentxs-proto/verify/CredentialSet.hpp>
#include <opentxs-proto/verify/CurrencyParams.hpp>
#include <opentxs-proto/verify/Faucet.hpp>
#include <opentxs-proto/verify/Envelope.hpp>
#include <opentxs-proto/verify/EquityParams.hpp>
#include <opentxs-proto/verify/HDPath.hpp>
#include <opentxs-proto/verify/HDSeed.hpp>
#include <opentxs-proto/verify/InstrumentRevision.hpp>
#include <opentxs-proto/verify/Issuer.hpp>
#include <opentxs-proto/verify/KeyCredential.hpp>
#include <opentxs-proto/verify/ListenAddress.hpp>
#include <opentxs-proto/verify/MasterCredentialParameters.hpp>
#include <opentxs-proto/verify/MoveFunds.hpp>
#include <opentxs-proto/verify/NoticeAcknowledgement.hpp>
#include <opentxs-proto/verify/NymIDSource.hpp>
#include <opentxs-proto/verify/OTXPush.hpp>
#include <opentxs-proto/verify/OutBailment.hpp>
#include <opentxs-proto/verify/OutBailmentReply.hpp>
#include <opentxs-proto/verify/PairEvent.hpp>
#include <opentxs-proto/verify/PaymentCode.hpp>
#include <opentxs-proto/verify/PaymentEvent.hpp>
#include <opentxs-proto/verify/PaymentWorkflow.hpp>
#include <opentxs-proto/verify/PeerObject.hpp>
#include <opentxs-proto/verify/PeerReply.hpp>
#include <opentxs-proto/verify/PeerRequest.hpp>
#include <opentxs-proto/verify/PeerRequestHistory.hpp>
#include <opentxs-proto/verify/PeerRequestWorkflow.hpp>
#include <opentxs-proto/verify/PendingBailment.hpp>
#include <opentxs-proto/verify/RPCCommand.hpp>
#include <opentxs-proto/verify/RPCPush.hpp>
#include <opentxs-proto/verify/RPCResponse.hpp>
#include <opentxs-proto/verify/RPCStatus.hpp>
#include <opentxs-proto/verify/RPCTask.hpp>
#include <opentxs-proto/verify/Seed.hpp>
#include <opentxs-proto/verify/SendMessage.hpp>
#include <opentxs-proto/verify/SendPayment.hpp>
#include <opentxs-proto/verify/ServerContext.hpp>
#include <opentxs-proto/verify/ServerContract.hpp>
#include <opentxs-proto/verify/ServerReply.hpp>
#include <opentxs-proto/verify/ServerRequest.hpp>
#include <opentxs-proto/verify/SessionData.hpp>
#include <opentxs-proto/verify/Signature.hpp>
#include <opentxs-proto/verify/Signature.hpp>
#include <opentxs-proto/verify/SourceProof.hpp>
#include <opentxs-proto/verify/StorageAccountIndex.hpp>
#include <opentxs-proto/verify/StorageAccounts.hpp>
#include <opentxs-proto/verify/StorageBip47AddressIndex.hpp>
#include <opentxs-proto/verify/StorageBip47ChannelList.hpp>
#include <opentxs-proto/verify/StorageBip47Contexts.hpp>
#include <opentxs-proto/verify/StorageBip47NymAddressIndex.hpp>
#include <opentxs-proto/verify/StorageBlockchainAccountList.hpp>
#include <opentxs-proto/verify/StorageBlockchainTransactions.hpp>
#include <opentxs-proto/verify/StorageContactAddressIndex.hpp>
#include <opentxs-proto/verify/StorageContactNymIndex.hpp>
#include <opentxs-proto/verify/StorageContacts.hpp>
#include <opentxs-proto/verify/StorageCredentials.hpp>
#include <opentxs-proto/verify/StorageIDList.hpp>
#include <opentxs-proto/verify/StorageIssuers.hpp>
#include <opentxs-proto/verify/StorageItemHash.hpp>
#include <opentxs-proto/verify/StorageItems.hpp>
#include <opentxs-proto/verify/StorageNym.hpp>
#include <opentxs-proto/verify/StorageNymList.hpp>
#include <opentxs-proto/verify/StoragePaymentWorkflows.hpp>
#include <opentxs-proto/verify/StorageRoot.hpp>
#include <opentxs-proto/verify/StorageSeeds.hpp>
#include <opentxs-proto/verify/StorageServers.hpp>
#include <opentxs-proto/verify/StorageThread.hpp>
#include <opentxs-proto/verify/StorageThreadItem.hpp>
#include <opentxs-proto/verify/StorageUnits.hpp>
#include <opentxs-proto/verify/StorageWorkflowIndex.hpp>
#include <opentxs-proto/verify/StorageWorkflowType.hpp>
#include <opentxs-proto/verify/StoreSecret.hpp>
#include <opentxs-proto/verify/SymmetricKey.hpp>
#include <opentxs-proto/verify/TaskComplete.hpp>
#include <opentxs-proto/verify/UnitAccountMap.hpp>
#include <opentxs-proto/verify/UnitDefinition.hpp>
#include <opentxs-proto/verify/Verification.hpp>
#include <opentxs-proto/verify/VerificationGroup.hpp>
#include <opentxs-proto/verify/VerificationIdentity.hpp>
#include <opentxs-proto/verify/VerificationOffer.hpp>
#include <opentxs-proto/verify/VerificationSet.hpp>
#include <opentxs-proto/verify/VerifyCredentials.hpp>
#include <opentxs-proto/verify/VerifyClaim.hpp>
// IWYU pragma: end_exports
#ifdef _WIN32
#pragma warning(pop)
#else
#pragma GCC diagnostic pop
#endif

#endif  // OPENTXS_PROTO_TYPES_HPP
