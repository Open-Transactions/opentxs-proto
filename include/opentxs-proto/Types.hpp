/************************************************************
 *
 *                 OPEN TRANSACTIONS
 *
 *       Financial Cryptography and Digital Cash
 *       Library, Protocol, API, Server, CLI, GUI
 *
 *       -- Anonymous Numbered Accounts.
 *       -- Untraceable Digital Cash.
 *       -- Triple-Signed Receipts.
 *       -- Cheques, Vouchers, Transfers, Inboxes.
 *       -- Basket Currencies, Markets, Payment Plans.
 *       -- Signed, XML, Ricardian-style Contracts.
 *       -- Scripted smart contracts.
 *
 *  EMAIL:
 *  fellowtraveler@opentransactions.org
 *
 *  WEBSITE:
 *  http://www.opentransactions.org/
 *
 *  -----------------------------------------------------
 *
 *   LICENSE:
 *   This Source Code Form is subject to the terms of the
 *   Mozilla Public License, v. 2.0. If a copy of the MPL
 *   was not distributed with this file, You can obtain one
 *   at http://mozilla.org/MPL/2.0/.
 *
 *   DISCLAIMER:
 *   This program is distributed in the hope that it will
 *   be useful, but WITHOUT ANY WARRANTY; without even the
 *   implied warranty of MERCHANTABILITY or FITNESS FOR A
 *   PARTICULAR PURPOSE.  See the Mozilla Public License
 *   for more details.
 *
 ************************************************************/

#ifndef OPENTXS_PROTO_TYPES_HPP
#define OPENTXS_PROTO_TYPES_HPP

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
// IWYU pragma: begin_exports
#include <opentxs-proto/AsymmetricKey.pb.h>
#include <opentxs-proto/Bailment.pb.h>
#include <opentxs-proto/BailmentReply.pb.h>
#include <opentxs-proto/BasketItem.pb.h>
#include <opentxs-proto/BasketParams.pb.h>
#include <opentxs-proto/Bip44Account.pb.h>
#include <opentxs-proto/Bip44Address.pb.h>
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
#include <opentxs-proto/ContactItem.pb.h>
#include <opentxs-proto/ContactSection.pb.h>
#include <opentxs-proto/Context.pb.h>
#include <opentxs-proto/ContractEnums.pb.h>
#include <opentxs-proto/Credential.pb.h>
#include <opentxs-proto/CredentialIndex.pb.h>
#include <opentxs-proto/CredentialSet.pb.h>
#include <opentxs-proto/CurrencyParams.pb.h>
#include <opentxs-proto/Enums.pb.h>
#include <opentxs-proto/Envelope.pb.h>
#include <opentxs-proto/EquityParams.pb.h>
#include <opentxs-proto/HDPath.pb.h>
#include <opentxs-proto/KeyCredential.pb.h>
#include <opentxs-proto/ListenAddress.pb.h>
#include <opentxs-proto/MasterCredentialParameters.pb.h>
#include <opentxs-proto/NoticeAcknowledgement.pb.h>
#include <opentxs-proto/NymIDSource.pb.h>
#include <opentxs-proto/OutBailment.pb.h>
#include <opentxs-proto/OutBailmentReply.pb.h>
#include <opentxs-proto/PaymentCode.pb.h>
#include <opentxs-proto/PeerEnums.pb.h>
#include <opentxs-proto/PeerObject.pb.h>
#include <opentxs-proto/PeerReply.pb.h>
#include <opentxs-proto/PeerRequest.pb.h>
#include <opentxs-proto/PendingBailment.pb.h>
#include <opentxs-proto/Seed.pb.h>
#include <opentxs-proto/ServerContext.pb.h>
#include <opentxs-proto/ServerContract.pb.h>
#include <opentxs-proto/Signature.pb.h>
#include <opentxs-proto/SourceProof.pb.h>
#include <opentxs-proto/StorageBlockchainAccountList.pb.h>
#include <opentxs-proto/StorageBlockchainTransactions.pb.h>
#include <opentxs-proto/StorageContacts.pb.h>
#include <opentxs-proto/StorageCredentials.pb.h>
#include <opentxs-proto/StorageEnums.pb.h>
#include <opentxs-proto/StorageIDList.pb.h>
#include <opentxs-proto/StorageItemHash.pb.h>
#include <opentxs-proto/StorageItems.pb.h>
#include <opentxs-proto/StorageNym.pb.h>
#include <opentxs-proto/StorageNymList.pb.h>
#include <opentxs-proto/StorageRoot.pb.h>
#include <opentxs-proto/StorageSeeds.pb.h>
#include <opentxs-proto/StorageServers.pb.h>
#include <opentxs-proto/StorageThread.pb.h>
#include <opentxs-proto/StorageThreadItem.pb.h>
#include <opentxs-proto/StorageUnits.pb.h>
#include <opentxs-proto/StoreSecret.pb.h>
#include <opentxs-proto/SymmetricKey.pb.h>
#include <opentxs-proto/UnitDefinition.pb.h>
#include <opentxs-proto/Verification.pb.h>
#include <opentxs-proto/VerificationGroup.pb.h>
#include <opentxs-proto/VerificationIdentity.pb.h>
#include <opentxs-proto/VerificationOffer.pb.h>
#include <opentxs-proto/VerificationSet.pb.h>
#include <opentxs-proto/verify/AsymmetricKey.hpp>
#include <opentxs-proto/verify/Bailment.hpp>
#include <opentxs-proto/verify/BailmentReply.hpp>
#include <opentxs-proto/verify/BasketItem.hpp>
#include <opentxs-proto/verify/BasketParams.hpp>
#include <opentxs-proto/verify/Bip44Account.hpp>
#include <opentxs-proto/verify/Bip44Address.hpp>
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
#include <opentxs-proto/verify/ContactItem.hpp>
#include <opentxs-proto/verify/ContactSection.hpp>
#include <opentxs-proto/verify/Context.hpp>
#include <opentxs-proto/verify/Credential.hpp>
#include <opentxs-proto/verify/CredentialIndex.hpp>
#include <opentxs-proto/verify/CredentialSet.hpp>
#include <opentxs-proto/verify/CurrencyParams.hpp>
#include <opentxs-proto/verify/Envelope.hpp>
#include <opentxs-proto/verify/EquityParams.hpp>
#include <opentxs-proto/verify/HDPath.hpp>
#include <opentxs-proto/verify/KeyCredential.hpp>
#include <opentxs-proto/verify/ListenAddress.hpp>
#include <opentxs-proto/verify/MasterCredentialParameters.hpp>
#include <opentxs-proto/verify/NoticeAcknowledgement.hpp>
#include <opentxs-proto/verify/NymIDSource.hpp>
#include <opentxs-proto/verify/OutBailment.hpp>
#include <opentxs-proto/verify/OutBailmentReply.hpp>
#include <opentxs-proto/verify/PaymentCode.hpp>
#include <opentxs-proto/verify/PeerObject.hpp>
#include <opentxs-proto/verify/PeerReply.hpp>
#include <opentxs-proto/verify/PeerRequest.hpp>
#include <opentxs-proto/verify/PendingBailment.hpp>
#include <opentxs-proto/verify/Seed.hpp>
#include <opentxs-proto/verify/ServerContext.hpp>
#include <opentxs-proto/verify/ServerContract.hpp>
#include <opentxs-proto/verify/Signature.hpp>
#include <opentxs-proto/verify/Signature.hpp>
#include <opentxs-proto/verify/SourceProof.hpp>
#include <opentxs-proto/verify/StorageBlockchainAccountList.hpp>
#include <opentxs-proto/verify/StorageBlockchainTransactions.hpp>
#include <opentxs-proto/verify/StorageContacts.hpp>
#include <opentxs-proto/verify/StorageCredentials.hpp>
#include <opentxs-proto/verify/StorageIDList.hpp>
#include <opentxs-proto/verify/StorageItemHash.hpp>
#include <opentxs-proto/verify/StorageItems.hpp>
#include <opentxs-proto/verify/StorageNym.hpp>
#include <opentxs-proto/verify/StorageNymList.hpp>
#include <opentxs-proto/verify/StorageRoot.hpp>
#include <opentxs-proto/verify/StorageSeeds.hpp>
#include <opentxs-proto/verify/StorageServers.hpp>
#include <opentxs-proto/verify/StorageThread.hpp>
#include <opentxs-proto/verify/StorageThreadItem.hpp>
#include <opentxs-proto/verify/StorageUnits.hpp>
#include <opentxs-proto/verify/StoreSecret.hpp>
#include <opentxs-proto/verify/SymmetricKey.hpp>
#include <opentxs-proto/verify/UnitDefinition.hpp>
#include <opentxs-proto/verify/Verification.hpp>
#include <opentxs-proto/verify/VerificationGroup.hpp>
#include <opentxs-proto/verify/VerificationIdentity.hpp>
#include <opentxs-proto/verify/VerificationOffer.hpp>
#include <opentxs-proto/verify/VerificationSet.hpp>
#include <opentxs-proto/verify/VerifyCredentials.hpp>
// IWYU pragma: end_exports
#ifdef _WIN32
#pragma warning(pop)
#else
#pragma GCC diagnostic pop
#endif

#endif  // OPENTXS_PROTO_TYPES_HPP
