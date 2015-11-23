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

#include "../../../include/verify/Credential.hpp"

#include <iostream>

namespace opentxs { namespace proto
{

bool Credential_1(
    const Credential serializedCred,
    const proto::CredentialRole role,
    const bool withSigs)
{
    bool isPrivate = false;
    bool isPublic = false;
    bool validPublicData = false;
    bool validPrivateData = false;
    bool expectMasterSignature = false;
    int32_t expectedSigCount = 2;

    if (CREDROLE_CHILDKEY == role) {
        expectedSigCount = 3;
        expectMasterSignature = true;
    }

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

    if (CREDTYPE_LEGACY != serializedCred.type()) {
        std::cerr << "Verify serialized credential failed: invalid type ("
                << serializedCred.type() << ")." << std::endl;
        return false;
    }

    if (!serializedCred.has_role()) {
        std::cerr << "Verify serialized credential failed: missing role." << std::endl;
        return false;
    }

    if ((CREDROLE_MASTERKEY != role) && (CREDROLE_CHILDKEY != role)) {
        std::cerr << "Verify serialized credential failed: invalid role ("
                << serializedCred.role() << ")." << std::endl;
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
    }

    if (!(isPrivate || isPublic)) {
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

    if (isPublic && serializedCred.has_privatecredential()) {
        std::cerr << "Verify serialized credential failed: public credential contains private data." << std::endl;
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

    validPublicData = Verify
        (serializedCred.publiccredential(),
            CredentialAllowedKeyCredentials.at(serializedCred.version()).first,
            CredentialAllowedKeyCredentials.at(serializedCred.version()).second,
            role,
            CREDTYPE_LEGACY,
            KEYMODE_PUBLIC,
            SOURCETYPE_SELF);

    if (!validPublicData) {
        std::cerr << "Verify serialized credential failed: invalid public data." << std::endl;
        return false;
    }

    if (isPrivate) {
        validPrivateData = Verify(
            serializedCred.privatecredential(),
            CredentialAllowedKeyCredentials.at(serializedCred.version()).first,
            CredentialAllowedKeyCredentials.at(serializedCred.version()).second,
            role,
            CREDTYPE_LEGACY,
            KEYMODE_PRIVATE,
            SOURCETYPE_ERROR);

        if (!validPrivateData) {
            std::cerr << "Verify serialized credential failed: invalid private data." << std::endl;
            return false;
        }
    }

    if (withSigs) {
        std::string masterID = serializedCred.publiccredential().childdata().masterid();

        if (expectedSigCount != serializedCred.signature_size()) {
            std::cerr << "Verify serialized credential failed: incorrect number of signature(s) ("
            << serializedCred.signature_size() << " of " << expectedSigCount << " found)." << std::endl;
            return false;
        }

        uint32_t selfPublicCount = 0;
        uint32_t selfPrivateCount = 0;
        uint32_t masterPublicCount = 0;

        for (auto& it: serializedCred.signature()) {
            bool validSig = Verify(
                it,
                CredentialAllowedSignatures.at(serializedCred.version()).first,
                CredentialAllowedSignatures.at(serializedCred.version()).second,
                serializedCred.id(),
                masterID,
                selfPublicCount,
                selfPrivateCount,
                masterPublicCount);

            if (!validSig) {
                std::cerr << "Verify serialized credential failed: invalid signature." << std::endl;
                return false;
            }
        }

        if (1 != selfPrivateCount) {
            std::cerr << "Verify serialized credential failed: incorrect number of private self-signatures ("
            << selfPrivateCount << " of 1 found)." << std::endl;
            return false;
        }

        if (1 != selfPublicCount) {
            std::cerr << "Verify serialized credential failed: incorrect number of public self-signatures ("
            << selfPublicCount << " of 1 found)." << std::endl;
            return false;
        }

        if ((1 != masterPublicCount) && (expectMasterSignature)) {
            std::cerr << "Verify serialized credential failed: incorrect number of public master signatures ("
            << selfPublicCount << " of 1 found)." << std::endl;
            return false;
        }
    }

    return true;
}

} // namespace proto
} // namespace opentxs
