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

#include "opentxs-proto/verify/Credential.hpp"

#include <iostream>

#include "opentxs-proto/verify/VerifyContacts.hpp"

namespace opentxs { namespace proto
{

bool CheckProto_1(
    const Credential& serializedCred,
    const CredentialRole role,
    const bool withSigs)
{
    bool isPrivate = false;
    bool isPublic = false;
    bool validChildData = false;
    bool validMasterData = false;
    bool validPublicData = false;
    bool validPrivateData = false;
    bool validContactData = false;
    bool expectMasterSignature = false;
    bool expectSourceSignature = false;
    int32_t expectedSigCount = 1;
    bool checkRole = (CREDROLE_ERROR != role);

    if (!serializedCred.has_id()) {
        std::cerr << "Verify serialized credential failed: missing identifier." << std::endl;
        return false;
    }

    if (MIN_PLAUSIBLE_IDENTIFIER > serializedCred.id().size()) {
        std::cerr << "Verify serialized credential failed: invalid identifier ("
                << serializedCred.id() << ")." << std::endl;
        return false;
    }

    if (!serializedCred.has_type()) {
        std::cerr << "Verify serialized credential failed: missing type." << std::endl;
        return false;
    }

    if ((CREDTYPE_LEGACY != serializedCred.type()) &&
        (CREDTYPE_HD != serializedCred.type())) {
        std::cerr << "Verify serialized credential failed: invalid type ("
                << serializedCred.type() << ")." << std::endl;
        return false;
    }

    if (!serializedCred.has_role()) {
        std::cerr << "Verify serialized credential failed: missing role." << std::endl;
        return false;
    }

    CredentialRole actualRole = serializedCred.role();

    if (checkRole && (role != actualRole)) {
        std::cerr << "Verify serialized credential failed: incorrect role ("
        << serializedCred.role() << ")." << std::endl;
        return false;
    }

    bool masterCredential = (CREDROLE_MASTERKEY == actualRole);
    bool childKeyCredential = (CREDROLE_CHILDKEY == actualRole);
    bool keyCredential = (masterCredential || childKeyCredential);
    bool contactCredential = (CREDROLE_CONTACT == actualRole);
    bool verifyCredential = (CREDROLE_VERIFY == actualRole);
    bool metadataContainer = (contactCredential || verifyCredential);
    bool knownRole = (keyCredential || metadataContainer);

    if (childKeyCredential) {
        expectedSigCount++;
        expectMasterSignature = true;
    }

    if (masterCredential && (CREDTYPE_HD == serializedCred.type())) {
        expectedSigCount++;
        expectSourceSignature = true;
    }

    if (checkRole && !knownRole) {
        std::cerr << "Verify serialized credential failed: invalid role ("
                << role << ")." << std::endl;
        return false;
    }

    if (!serializedCred.has_mode()) {
        std::cerr << "Verify serialized credential failed: missing mode." << std::endl;
        return false;
    }

    if (KEYMODE_PUBLIC == serializedCred.mode()) {
        isPublic = true;
    }

    if (KEYMODE_PRIVATE == serializedCred.mode()) {
        isPrivate = true;
        if (keyCredential) {
            expectedSigCount++;
        }
    }

    if ((keyCredential && (!(isPrivate || isPublic))) ||
        (metadataContainer && (KEYMODE_NULL == serializedCred.mode()))) {
        std::cerr << "Verify serialized credential failed: invalid mode ("
                << serializedCred.mode() << ")." << std::endl;
        return false;
    }

    if (!serializedCred.has_nymid()) {
        std::cerr << "Verify serialized credential failed: missing NymID." << std::endl;
        return false;
    }

    if (MIN_PLAUSIBLE_IDENTIFIER > serializedCred.nymid().size()) {
        std::cerr << "Verify serialized credential failed: invalid NymID ("
                << serializedCred.nymid() << ")." << std::endl;
        return false;
    }

    if (!masterCredential) {
        if (!serializedCred.has_childdata()) {
            std::cerr << "Verify serialized credential failed: missing child data." << std::endl;
            return false;
        }

        validChildData = Check(
            serializedCred.childdata(),
            CredentialAllowedChildParams.at(serializedCred.version()).first,
            CredentialAllowedChildParams.at(serializedCred.version()).second);

        if (!validChildData) {
            std::cerr << "Verify serialized credential failed: invalid child data." << std::endl;
            return false;
        }
    }

    if (masterCredential) {
        if (!serializedCred.has_masterdata()) {
            std::cerr << "Verify serialized credential failed: missing master data." << std::endl;
            return false;
        }

        validMasterData = Check(
            serializedCred.masterdata(),
            CredentialAllowedMasterParams.at(serializedCred.version()).first,
            CredentialAllowedChildParams.at(serializedCred.version()).second,
            expectSourceSignature);

        if (!validMasterData) {
            std::cerr << "Verify serialized credential failed: invalid master data." << std::endl;
            return false;
        }
    }

    if ((!masterCredential) && (serializedCred.has_masterdata())) {
        std::cerr << "Verify serialized credential failed: child credential contains master data." << std::endl;
        return false;
    }

    if (isPublic && serializedCred.has_privatecredential()) {
        std::cerr << "Verify serialized credential failed: public credential contains private data." << std::endl;
        return false;
    }

    if (keyCredential) {
        if (serializedCred.has_contactdata()) {
            std::cerr << "Verify serialized credential failed: key credential contains contact data." << std::endl;
            return false;
        }

        if (serializedCred.has_verification()) {
            std::cerr << "Verify serialized credential failed: key credential contains verification data." << std::endl;
            return false;
        }

        if (!serializedCred.has_publiccredential()) {
            std::cerr << "Verify serialized credential failed: missing public data." << std::endl;
            return false;
        }

        if (isPrivate && (!serializedCred.has_privatecredential())) {
            std::cerr << "Verify serialized credential failed: missing private data." << std::endl;
            return false;
        }
    }

    if (metadataContainer) {
        if (serializedCred.has_privatecredential()) {
            std::cerr << "Verify serialized credential failed: contact credential contains private key data." << std::endl;
            return false;
        }

        if (serializedCred.has_publiccredential()) {
            std::cerr << "Verify serialized credential failed: contact credential contains public key data." << std::endl;
            return false;
        }

    }

    if (contactCredential) {
        if (serializedCred.has_verification()) {
            std::cerr << "Verify serialized credential failed: contract credential contains verification data." << std::endl;
            return false;
        }

        if (!serializedCred.has_contactdata()) {
            std::cerr << "Verify serialized credential failed: missing contact data." << std::endl;
            return false;
        }

        validContactData = Check(
            serializedCred.contactdata(),
            CredentialAllowedContactData.at(serializedCred.version()).first,
            CredentialAllowedContactData.at(serializedCred.version()).second,
            CLAIMS_NORMAL);

        if (!validContactData) {
            std::cerr << "Verify serialized credential failed: invalid contact data." << std::endl;
            return false;
        }
    }

    if (verifyCredential) {
        if (serializedCred.has_contactdata()) {
            std::cerr << "Verify serialized credential failed: verification credential contains contact data." << std::endl;
            return false;
        }

        if (!serializedCred.has_verification()) {
            std::cerr << "Verify serialized credential failed: missing verification data." << std::endl;
            return false;
        }

        bool validVerificationSet = Check(
            serializedCred.verification(),
            CredentialAllowedVerification.at(serializedCred.version()).first,
            CredentialAllowedVerification.at(serializedCred.version()).second,
            VERIFICATIONS_NORMAL);

        if (!validVerificationSet) {
            std::cerr << "Verify serialized credential failed: invalid verification data." << std::endl;
            return false;
        }
    }

    if (keyCredential) {
        validPublicData = Check(
                serializedCred.publiccredential(),
                CredentialAllowedKeyCredentials.at(serializedCred.version()).first,
                CredentialAllowedKeyCredentials.at(serializedCred.version()).second,
                serializedCred.type(),
                KEYMODE_PUBLIC);

        if (!validPublicData) {
            std::cerr << "Verify serialized credential failed: invalid public data." << std::endl;
            return false;
        }

        if (isPrivate) {
            validPrivateData = Check(
                serializedCred.privatecredential(),
                CredentialAllowedKeyCredentials.at(serializedCred.version()).first,
                CredentialAllowedKeyCredentials.at(serializedCred.version()).second,
                serializedCred.type(),
                KEYMODE_PRIVATE);

            if (!validPrivateData) {
                std::cerr << "Verify serialized credential failed: invalid private data." << std::endl;
                return false;
            }
        }
    }

    if (withSigs) {
        std::string masterID = serializedCred.childdata().masterid();

        if (expectedSigCount != serializedCred.signature_size()) {
            std::cerr << "Verify serialized credential failed: incorrect number of signature(s) ("
            << serializedCred.signature_size() << " of " << expectedSigCount << " found)." << std::endl;
            return false;
        }

        uint32_t selfPublicCount = 0;
        uint32_t selfPrivateCount = 0;
        uint32_t masterPublicCount = 0;
        uint32_t sourcePublicCount = 0;

        for (auto& it: serializedCred.signature()) {
            bool validSig = Check(
                it,
                CredentialAllowedSignatures.at(serializedCred.version()).first,
                CredentialAllowedSignatures.at(serializedCred.version()).second,
                serializedCred.id(),
                masterID,
                selfPublicCount,
                selfPrivateCount,
                masterPublicCount,
                sourcePublicCount);

            if (!validSig) {
                std::cerr << "Verify serialized credential failed: invalid signature." << std::endl;
                return false;
            }
        }

        if (keyCredential) {
            if ((1 != selfPrivateCount) && (isPrivate)) {
                std::cerr << "Verify serialized credential failed: incorrect number of private self-signatures ("
                << selfPrivateCount << " of 1 found)." << std::endl;
                return false;
            }

            if (1 != selfPublicCount) {
                std::cerr << "Verify serialized credential failed: incorrect number of public self-signatures ("
                << selfPublicCount << " of 1 found)." << std::endl;
                return false;
            }
        }

        if ((1 != masterPublicCount) && (expectMasterSignature)) {
            std::cerr << "Verify serialized credential failed: incorrect number of public master signatures ("
            << masterPublicCount << " of 1 found)." << std::endl;
            return false;
        }

        if ((1 != sourcePublicCount) && (expectSourceSignature)) {
            std::cerr << "Verify serialized credential failed: incorrect number of public source signatures ("
            << sourcePublicCount << " of 1 found)." << std::endl;
            return false;
        }
    }

    return true;
}

} // namespace proto
} // namespace opentxs
