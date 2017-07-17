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

#include "opentxs-proto/Types.hpp"
#include "opentxs-proto/Check.hpp"

#include <iostream>
#include <sstream>

namespace opentxs
{
namespace proto
{

bool CheckProto_1(
    const Credential& credential,
    const bool silent,
    const KeyMode& mode,
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
    int32_t expectedSigCount = 1;  // public self-signature
    bool checkRole = (CREDROLE_ERROR != role);

    if (!credential.has_id()) {
        FAIL("credential", "missing identifier")
    }

    if (MIN_PLAUSIBLE_IDENTIFIER > credential.id().size()) {
        FAIL2("credential", "invalid identifier", credential.id())
    }

    if (!credential.has_type()) {
        FAIL("credential", "missing type")
    }

    switch (credential.type()) {
        case CREDTYPE_LEGACY:
        case CREDTYPE_HD:
            break;
        default: {
            FAIL2("credential", "invalid type", credential.type())
        }
    }

    if (!credential.has_role()) {
        FAIL("credential", "missing role")

        return false;
    }

    CredentialRole actualRole = credential.role();

    if (checkRole && (role != actualRole)) {
        FAIL2("credential", "incorrect role", credential.role())
    }

    bool masterCredential = (CREDROLE_MASTERKEY == actualRole);
    bool childKeyCredential = (CREDROLE_CHILDKEY == actualRole);
    bool keyCredential = (masterCredential || childKeyCredential);
    bool contactCredential = (CREDROLE_CONTACT == actualRole);
    bool verifyCredential = (CREDROLE_VERIFY == actualRole);
    bool metadataContainer = (contactCredential || verifyCredential);
    bool knownRole = (keyCredential || metadataContainer);

    if (childKeyCredential) {
        expectedSigCount++;  // master signature
        expectMasterSignature = true;
    }

    if (checkRole && !knownRole) {
        if (false == silent) {
            FAIL2("credential", "invalid role", role)
        }

        return false;
    }

    if (!credential.has_mode()) {
        FAIL("credential", "missing mode")
    }

    KeyMode requiredMode = KEYMODE_ERROR;

    switch (actualRole) {
        case (CREDROLE_MASTERKEY):
        case (CREDROLE_CHILDKEY): {
            requiredMode = mode;
            break;
        }
        case (CREDROLE_CONTACT):
        case (CREDROLE_VERIFY): {
            requiredMode = KEYMODE_NULL;
            break;
        }
        default: {
            FAIL2("credential", "incorrect role", credential.role())
        }
    }

    const auto actualMode = credential.mode();

    if (KEYMODE_ERROR != requiredMode) {
        if (actualMode != requiredMode) {
            FAIL3(
                "credential",
                "incorrect mode",
                actualMode,
                ". Required mode: ",
                requiredMode)
        }
    }

    switch (actualMode) {
        case (KEYMODE_PUBLIC): {
            isPublic = true;

            break;
        }
        case (KEYMODE_PRIVATE): {
            isPrivate = true;

            if (keyCredential) {
                expectedSigCount++;  // private self-signature
            }

            break;
        }
        case (KEYMODE_NULL): {
            break;
        }
        default: {
            FAIL2("credential", "invalid mode", actualMode)
        }
    }

    if (!credential.has_nymid()) {
        FAIL("credential", "missing nym id")
    }

    if (MIN_PLAUSIBLE_IDENTIFIER > credential.nymid().size()) {
        FAIL2("credential", "invalid nym id", credential.nymid())
    }

    if (!masterCredential) {
        if (!credential.has_childdata()) {
            FAIL("credential", "missing child data")
        }

        validChildData = Check(
            credential.childdata(),
            CredentialAllowedChildParams.at(credential.version()).first,
            CredentialAllowedChildParams.at(credential.version()).second,
            silent);

        if (!validChildData) {
            FAIL("credential", "invalid child data")
        }
    }

    if (masterCredential) {
        if (!credential.has_masterdata()) {
            FAIL("credential", "missing master data")
        }

        validMasterData = Check(
            credential.masterdata(),
            CredentialAllowedMasterParams.at(credential.version()).first,
            CredentialAllowedChildParams.at(credential.version()).second,
            silent,
            expectSourceSignature);

        if (!validMasterData) {
            FAIL("credential", "invalid master data")
        }

        if (expectSourceSignature) {
            expectedSigCount++;  // source signature
        }
    }

    if ((!masterCredential) && (credential.has_masterdata())) {
        FAIL("credential", "child credential contains master data")
    }

    if (isPublic && credential.has_privatecredential()) {
        FAIL("credential", " public credential contains private data")
    }

    if (keyCredential) {
        if (credential.has_contactdata()) {
            FAIL("credential", "key credential contains contact data")
        }

        if (credential.has_verification()) {
            FAIL("credential", "key credential contains verification data")
        }

        if (!credential.has_publiccredential()) {
            FAIL("credential", "missing public data")
        }

        if (isPrivate && (!credential.has_privatecredential())) {
            FAIL("credential", "missing private data")
        }
    }

    if (metadataContainer) {
        if (credential.has_privatecredential()) {
            FAIL("credential", "metadata credential contains private key data")
        }

        if (credential.has_publiccredential()) {
            FAIL("credential", "metadata credential contains public key data")
        }
    }

    if (contactCredential) {
        if (credential.has_verification()) {
            FAIL("credential", "contact credential contains verification data")
        }

        if (!credential.has_contactdata()) {
            FAIL("credential", "missing contact data")
        }

        validContactData = Check(
            credential.contactdata(),
            CredentialAllowedContactData.at(credential.version()).first,
            CredentialAllowedContactData.at(credential.version()).second,
            silent,
            CLAIMS_NORMAL);

        if (!validContactData) {
            FAIL("credential", "invalid contact data")
        }
    }

    if (verifyCredential) {
        if (credential.has_contactdata()) {
            FAIL("credential", "verification credential contains contact data")
        }

        if (!credential.has_verification()) {
            FAIL("credential", "missing verification data")
        }

        bool validVerificationSet = Check(
            credential.verification(),
            CredentialAllowedVerification.at(credential.version()).first,
            CredentialAllowedVerification.at(credential.version()).second,
            silent,
            VERIFICATIONS_NORMAL);

        if (!validVerificationSet) {
            FAIL("credential", "invalid verification data")
        }
    }

    if (keyCredential) {
        validPublicData = Check(
            credential.publiccredential(),
            CredentialAllowedKeyCredentials.at(credential.version()).first,
            CredentialAllowedKeyCredentials.at(credential.version()).second,
            silent,
            credential.type(),
            KEYMODE_PUBLIC);

        if (!validPublicData) {
            FAIL("credential", "invalid public data")
        }

        if (isPrivate) {
            validPrivateData = Check(
                credential.privatecredential(),
                CredentialAllowedKeyCredentials.at(credential.version()).first,
                CredentialAllowedKeyCredentials.at(credential.version()).second,
                silent,
                credential.type(),
                KEYMODE_PRIVATE);

            if (!validPrivateData) {
                FAIL("credential", "invalid private data")
            }
        }
    }

    if (withSigs) {
        std::string masterID = credential.childdata().masterid();

        if (expectedSigCount != credential.signature_size()) {
            std::stringstream ss;
            ss << credential.signature_size() << " of " << expectedSigCount
               << " found";

            FAIL2("credential", "incorrect number of signatures", ss.str())
        }

        uint32_t selfPublicCount = 0;
        uint32_t selfPrivateCount = 0;
        uint32_t masterPublicCount = 0;
        uint32_t sourcePublicCount = 0;

        for (auto& it : credential.signature()) {
            bool validSig = Check(
                it,
                CredentialAllowedSignatures.at(credential.version()).first,
                CredentialAllowedSignatures.at(credential.version()).second,
                silent,
                credential.id(),
                masterID,
                selfPublicCount,
                selfPrivateCount,
                masterPublicCount,
                sourcePublicCount);

            if (!validSig) {
                FAIL("credential", "invalid signature")
            }
        }

        if (keyCredential) {
            if ((1 != selfPrivateCount) && (isPrivate)) {
                std::stringstream ss;
                ss << selfPrivateCount << " of 1 found";

                FAIL2(
                    "credential",
                    "incorrect number of private self-signatures",
                    ss.str())
            }

            if (1 != selfPublicCount) {
                std::stringstream ss;
                ss << selfPublicCount << " of 1 found";

                FAIL2(
                    "credential",
                    "incorrect number of public self-signatures",
                    ss.str())
            }
        }

        if ((1 != masterPublicCount) && (expectMasterSignature)) {
            std::stringstream ss;
            ss << masterPublicCount << " of 1 found";

            FAIL2(
                "credential",
                "incorrect number of public master signatures",
                ss.str())
        }

        if ((1 != sourcePublicCount) && (expectSourceSignature)) {
            std::stringstream ss;
            ss << sourcePublicCount << " of 1 found";

            FAIL2(
                "credential",
                "incorrect number of public source signatures",
                ss.str())
        }
    }

    return true;
}

bool CheckProto_2(
    const Credential& credential,
    const bool silent,
    const KeyMode& mode,
    const CredentialRole role,
    const bool withSigs)
{
    return CheckProto_1(credential, silent, mode, role, withSigs);
}

bool CheckProto_3(
    const Credential& credential,
    const bool silent,
    const KeyMode& mode,
    const CredentialRole role,
    const bool withSigs)
{
    return CheckProto_1(credential, silent, mode, role, withSigs);
}

bool CheckProto_4(
    const Credential&,
    const bool,
    const KeyMode&,
    const CredentialRole,
    const bool)
{
    return false;
}
bool CheckProto_5(
    const Credential&,
    const bool,
    const KeyMode&,
    const CredentialRole,
    const bool)
{
    return false;
}
}  // namespace proto
}  // namespace opentxs
