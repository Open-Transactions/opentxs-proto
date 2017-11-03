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
    const Credential& input,
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

    if (!input.has_id()) {
        FAIL("credential", "missing identifier")
    }

    if (MIN_PLAUSIBLE_IDENTIFIER > input.id().size()) {
        FAIL2("credential", "invalid identifier", input.id())
    }

    if (!input.has_type()) {
        FAIL("credential", "missing type")
    }

    switch (input.type()) {
        case CREDTYPE_LEGACY:
        case CREDTYPE_HD:
            break;
        default: {
            FAIL2("credential", "invalid type", input.type())
        }
    }

    if (!input.has_role()) {
        FAIL("credential", "missing role")
    }

    CredentialRole actualRole = input.role();

    if (checkRole && (role != actualRole)) {
        FAIL2("credential", "incorrect role", input.role())
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
        FAIL2("credential", "invalid role", role)
    }

    if (!input.has_mode()) {
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
            FAIL2("credential", "incorrect role", input.role())
        }
    }

    const auto actualMode = input.mode();

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

    if (!input.has_nymid()) {
        FAIL("credential", "missing nym id")
    }

    if (MIN_PLAUSIBLE_IDENTIFIER > input.nymid().size()) {
        FAIL2("credential", "invalid nym id", input.nymid())
    }

    if (!masterCredential) {
        if (!input.has_childdata()) {
            FAIL("credential", "missing child data")
        }

        try {
            validChildData = Check(
                input.childdata(),
                CredentialAllowedChildParams.at(input.version()).first,
                CredentialAllowedChildParams.at(input.version()).second,
                silent);

            if (!validChildData) {
                FAIL("credential", "invalid child data")
            }
        } catch (const std::out_of_range&) {
            FAIL2(
                "credential",
                "allowed child params version not defined for version",
                input.version())
        }
    }

    if (masterCredential) {
        if (!input.has_masterdata()) {
            FAIL("credential", "missing master data")
        }

        try {
            validMasterData = Check(
                input.masterdata(),
                CredentialAllowedMasterParams.at(input.version()).first,
                CredentialAllowedMasterParams.at(input.version()).second,
                silent,
                expectSourceSignature);

            if (!validMasterData) {
                FAIL("credential", "invalid master data")
            }
        } catch (const std::out_of_range&) {
            FAIL2(
                "credential",
                "allowed master params version not defined for version",
                input.version())
        }

        if (expectSourceSignature) {
            expectedSigCount++;  // source signature
        }
    }

    if ((!masterCredential) && (input.has_masterdata())) {
        FAIL("credential", "child credential contains master data")
    }

    if (isPublic && input.has_privatecredential()) {
        FAIL("credential", " public credential contains private data")
    }

    if (keyCredential) {
        if (input.has_contactdata()) {
            FAIL("credential", "key credential contains contact data")
        }

        if (input.has_verification()) {
            FAIL("credential", "key credential contains verification data")
        }

        if (!input.has_publiccredential()) {
            FAIL("credential", "missing public data")
        }

        if (isPrivate && (!input.has_privatecredential())) {
            FAIL("credential", "missing private data")
        }
    }

    if (metadataContainer) {
        if (input.has_privatecredential()) {
            FAIL("credential", "metadata credential contains private key data")
        }

        if (input.has_publiccredential()) {
            FAIL("credential", "metadata credential contains public key data")
        }
    }

    if (contactCredential) {
        if (input.has_verification()) {
            FAIL("credential", "contact credential contains verification data")
        }

        if (!input.has_contactdata()) {
            FAIL("credential", "missing contact data")
        }

        try {
            validContactData = Check(
                input.contactdata(),
                CredentialAllowedContactData.at(input.version()).first,
                CredentialAllowedContactData.at(input.version()).second,
                silent,
                CLAIMS_NORMAL);

            if (!validContactData) {
                FAIL("credential", "invalid contact data")
            }
        } catch (const std::out_of_range&) {
            FAIL2(
                "credential",
                "allowed contact data version not defined for version",
                input.version())
        }
    }

    if (verifyCredential) {
        if (input.has_contactdata()) {
            FAIL("credential", "verification credential contains contact data")
        }

        if (!input.has_verification()) {
            FAIL("credential", "missing verification data")
        }

        try {
            bool validVerificationSet = Check(
                input.verification(),
                CredentialAllowedVerification.at(input.version()).first,
                CredentialAllowedVerification.at(input.version()).second,
                silent,
                VERIFICATIONS_NORMAL);

            if (!validVerificationSet) {
                FAIL("credential", "invalid verification data")
            }
        } catch (const std::out_of_range&) {
            FAIL2(
                "credential",
                "allowed verification version not defined for version",
                input.version())
        }
    }

    if (keyCredential) {
        try {
            validPublicData = Check(
                input.publiccredential(),
                CredentialAllowedKeyCredentials.at(input.version()).first,
                CredentialAllowedKeyCredentials.at(input.version()).second,
                silent,
                input.type(),
                KEYMODE_PUBLIC);

            if (!validPublicData) {
                FAIL("credential", "invalid public data")
            }
        } catch (const std::out_of_range&) {
            FAIL2(
                "credential",
                "allowed key credential version not defined for version",
                input.version())
        }

        if (isPrivate) {
            try {
                validPrivateData = Check(
                    input.privatecredential(),
                    CredentialAllowedKeyCredentials.at(input.version()).first,
                    CredentialAllowedKeyCredentials.at(input.version()).second,
                    silent,
                    input.type(),
                    KEYMODE_PRIVATE);

                if (!validPrivateData) {
                    FAIL("credential", "invalid private data")
                }
            } catch (const std::out_of_range&) {
                FAIL2(
                    "credential",
                    "allowed key credential version not defined for version",
                    input.version())
            }
        }
    }

    if (withSigs) {
        std::string masterID = input.childdata().masterid();

        if (expectedSigCount != input.signature_size()) {
            std::stringstream ss;
            ss << input.signature_size() << " of " << expectedSigCount
               << " found";

            FAIL2("credential", "incorrect number of signatures", ss.str())
        }

        uint32_t selfPublicCount = 0;
        uint32_t selfPrivateCount = 0;
        uint32_t masterPublicCount = 0;
        uint32_t sourcePublicCount = 0;

        for (auto& it : input.signature()) {
            try {
                bool validSig = Check(
                    it,
                    CredentialAllowedSignatures.at(input.version()).first,
                    CredentialAllowedSignatures.at(input.version()).second,
                    silent,
                    input.id(),
                    masterID,
                    selfPublicCount,
                    selfPrivateCount,
                    masterPublicCount,
                    sourcePublicCount);

                if (!validSig) {
                    FAIL("credential", "invalid signature")
                }
            } catch (const std::out_of_range&) {
                FAIL2(
                    "credential",
                    "allowed signature version not defined for version",
                    input.version())
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
    const Credential& input,
    const bool silent,
    const KeyMode& mode,
    const CredentialRole role,
    const bool withSigs)
{
    return CheckProto_1(input, silent, mode, role, withSigs);
}

bool CheckProto_3(
    const Credential& input,
    const bool silent,
    const KeyMode& mode,
    const CredentialRole role,
    const bool withSigs)
{
    return CheckProto_1(input, silent, mode, role, withSigs);
}

bool CheckProto_4(
    const Credential& input,
    const bool silent,
    const KeyMode& mode,
    const CredentialRole role,
    const bool withSigs)
{
    return CheckProto_1(input, silent, mode, role, withSigs);
}

bool CheckProto_5(
    const Credential& input,
    const bool silent,
    const KeyMode&,
    const CredentialRole,
    const bool)
{
    UNDEFINED_VERSION("credential", 5)
}
}  // namespace proto
}  // namespace opentxs
