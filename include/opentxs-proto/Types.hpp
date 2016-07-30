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
#include <opentxs-proto/ChildCredentialParameters.pb.h>
#include <opentxs-proto/Ciphertext.pb.h>
#include <opentxs-proto/Claim.pb.h>
#include <opentxs-proto/ContactData.pb.h>
#include <opentxs-proto/ContactEnums.pb.h>
#include <opentxs-proto/ContactItem.pb.h>
#include <opentxs-proto/ContactSection.pb.h>
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
#include <opentxs-proto/NymIDSource.pb.h>
#include <opentxs-proto/OutBailment.pb.h>
#include <opentxs-proto/OutBailmentReply.pb.h>
#include <opentxs-proto/PaymentCode.pb.h>
#include <opentxs-proto/PeerObject.pb.h>
#include <opentxs-proto/PeerReply.pb.h>
#include <opentxs-proto/PeerRequest.pb.h>
#include <opentxs-proto/Seed.pb.h>
#include <opentxs-proto/ServerContract.pb.h>
#include <opentxs-proto/Signature.pb.h>
#include <opentxs-proto/SourceProof.pb.h>
#include <opentxs-proto/StorageCredentials.pb.h>
#include <opentxs-proto/StorageItemHash.pb.h>
#include <opentxs-proto/StorageItems.pb.h>
#include <opentxs-proto/StorageNym.pb.h>
#include <opentxs-proto/StorageNymList.pb.h>
#include <opentxs-proto/StorageRoot.pb.h>
#include <opentxs-proto/StorageSeeds.pb.h>
#include <opentxs-proto/StorageServers.pb.h>
#include <opentxs-proto/StorageUnits.pb.h>
#include <opentxs-proto/SymmetricKey.pb.h>
#include <opentxs-proto/UnitDefinition.pb.h>
#include <opentxs-proto/Verification.pb.h>
#include <opentxs-proto/VerificationGroup.pb.h>
#include <opentxs-proto/VerificationIdentity.pb.h>
#include <opentxs-proto/VerificationSet.pb.h>
// IWYU pragma: end_exports
#ifdef _WIN32
#pragma warning(pop)
#else
#pragma GCC diagnostic pop
#endif

#endif // OPENTXS_PROTO_TYPES_HPP
