// Copyright (c) 2018 The Open-Transactions developers
// This Source Code Form is subject to the terms of the Mozilla Public
// License, v. 2.0. If a copy of the MPL was not distributed with this
// file, You can obtain one at http://mozilla.org/MPL/2.0/.

#include "opentxs-proto/Types.hpp"
#include "opentxs-proto/Check.hpp"

#define PROTO_NAME "RPC response"

namespace opentxs::proto
{
bool CheckProto_1(const RPCResponse& input, const bool silent)
{
    CHECK_IDENTIFIER(cookie)

    bool atLeastOne = false;
    for (auto status : input.status()) {
        if (RPCRESPONSE_SUCCESS == status.code()) {
            atLeastOne = true;
            break;
        }
    }

    switch (input.type()) {
        case RPCCOMMAND_ADDCLIENTSESSION: {
            CHECK_SIZE(status, 1);
            CHECK_SUBOBJECTS(status, RPCResponseAllowedRPCStatus);
            CHECK_NONE(sessions);
            CHECK_NONE(identifier);
            CHECK_NONE(seed);
            CHECK_NONE(nym);
            CHECK_NONE(balance);
            CHECK_NONE(contact);
            CHECK_NONE(accountevent);
            CHECK_NONE(contactevent);
            CHECK_NONE(task);
            CHECK_NONE(notary);
        } break;
        case RPCCOMMAND_ADDSERVERSESSION: {
            CHECK_SIZE(status, 1);
            CHECK_SUBOBJECTS(status, RPCResponseAllowedRPCStatus);
            CHECK_NONE(sessions);
            CHECK_NONE(identifier);
            CHECK_NONE(seed);
            CHECK_NONE(nym);
            CHECK_NONE(balance);
            CHECK_NONE(contact);
            CHECK_NONE(accountevent);
            CHECK_NONE(contactevent);
            CHECK_NONE(task);
            CHECK_NONE(notary);
        } break;
        case RPCCOMMAND_LISTCLIENTSESSIONS: {
            CHECK_SIZE(status, 1);
            CHECK_SUBOBJECTS(status, RPCResponseAllowedRPCStatus);
            CHECK_SUBOBJECTS(sessions, RPCResponseAllowedSessionData);
            CHECK_NONE(identifier);
            CHECK_NONE(seed);
            CHECK_NONE(nym);
            CHECK_NONE(balance);
            CHECK_NONE(contact);
            CHECK_NONE(accountevent);
            CHECK_NONE(contactevent);
            CHECK_NONE(task);
            CHECK_NONE(notary);
        } break;
        case RPCCOMMAND_LISTSERVERSESSIONS: {
            CHECK_SIZE(status, 1);
            CHECK_SUBOBJECTS(status, RPCResponseAllowedRPCStatus);
            CHECK_SUBOBJECTS(sessions, RPCResponseAllowedSessionData);
            CHECK_NONE(identifier);
            CHECK_NONE(seed);
            CHECK_NONE(nym);
            CHECK_NONE(balance);
            CHECK_NONE(contact);
            CHECK_NONE(accountevent);
            CHECK_NONE(contactevent);
            CHECK_NONE(task);
            CHECK_NONE(notary);
        } break;
        case RPCCOMMAND_IMPORTHDSEED: {
            CHECK_SIZE(status, 1);
            CHECK_SUBOBJECTS(status, RPCResponseAllowedRPCStatus);
            CHECK_NONE(sessions);

            if (atLeastOne) {
                CHECK_SIZE(identifier, 1);
                CHECK_IDENTIFIERS(identifier);
            } else {
                CHECK_NONE(identifier);
            }

            CHECK_NONE(seed);
            CHECK_NONE(nym);
            CHECK_NONE(balance);
            CHECK_NONE(contact);
            CHECK_NONE(accountevent);
            CHECK_NONE(contactevent);
            CHECK_NONE(task);
            CHECK_NONE(notary);
        } break;
        case RPCCOMMAND_LISTHDSEEDS: {
            CHECK_SIZE(status, 1);
            CHECK_SUBOBJECTS(status, RPCResponseAllowedRPCStatus);
            CHECK_NONE(sessions);

            if (atLeastOne) {
                CHECK_IDENTIFIERS(identifier);
            } else {
                CHECK_NONE(identifier);
            }

            CHECK_NONE(seed);
            CHECK_NONE(nym);
            CHECK_NONE(balance);
            CHECK_NONE(contact);
            CHECK_NONE(accountevent);
            CHECK_NONE(contactevent);
            CHECK_NONE(task);
            CHECK_NONE(notary);
        } break;
        case RPCCOMMAND_GETHDSEED: {
            CHECK_SIZE(status, 1);
            CHECK_SUBOBJECTS(status, RPCResponseAllowedRPCStatus);
            CHECK_NONE(sessions);
            CHECK_NONE(identifier);

            if (atLeastOne) {
                OPTIONAL_SUBOBJECTS(seed, RPCResponseAllowedHDSeed);
            } else {
                CHECK_NONE(seed);
            }

            CHECK_NONE(nym);
            CHECK_NONE(balance);
            CHECK_NONE(contact);
            CHECK_NONE(accountevent);
            CHECK_NONE(contactevent);
            CHECK_NONE(task);
            CHECK_NONE(notary);
        } break;
        case RPCCOMMAND_CREATENYM: {
            CHECK_SIZE(status, 1);
            CHECK_SUBOBJECTS(status, RPCResponseAllowedRPCStatus);
            CHECK_NONE(sessions);

            if (atLeastOne) {
                CHECK_SIZE(identifier, 1);
                CHECK_IDENTIFIERS(identifier);
            } else {
                CHECK_NONE(identifier);
            }

            CHECK_NONE(seed);
            CHECK_NONE(nym);
            CHECK_NONE(balance);
            CHECK_NONE(contact);
            CHECK_NONE(accountevent);
            CHECK_NONE(contactevent);
            CHECK_NONE(task);
            CHECK_NONE(notary);
        } break;
        case RPCCOMMAND_LISTNYMS: {
            CHECK_SIZE(status, 1);
            CHECK_SUBOBJECTS(status, RPCResponseAllowedRPCStatus);
            CHECK_NONE(sessions);

            if (atLeastOne) {
                CHECK_IDENTIFIERS(identifier);
            } else {
                CHECK_NONE(identifier);
            }

            CHECK_NONE(seed);
            CHECK_NONE(nym);
            CHECK_NONE(balance);
            CHECK_NONE(contact);
            CHECK_NONE(accountevent);
            CHECK_NONE(contactevent);
            CHECK_NONE(task);
            CHECK_NONE(notary);
        } break;
        case RPCCOMMAND_GETNYM: {
            CHECK_SIZE(status, 1);
            CHECK_SUBOBJECTS(status, RPCResponseAllowedRPCStatus);
            CHECK_NONE(sessions);
            CHECK_NONE(identifier);
            CHECK_NONE(seed);

            if (atLeastOne) {
                OPTIONAL_SUBOBJECTS(nym, RPCResponseAllowedCredentialIndex);
            } else {
                CHECK_NONE(nym);
            }

            CHECK_NONE(balance);
            CHECK_NONE(contact);
            CHECK_NONE(accountevent);
            CHECK_NONE(contactevent);
            CHECK_NONE(task);
            CHECK_NONE(notary);
        } break;
        case RPCCOMMAND_ADDCLAIM: {
            CHECK_SIZE(status, 1);
            CHECK_SUBOBJECTS(status, RPCResponseAllowedRPCStatus);
            CHECK_NONE(sessions);
            CHECK_NONE(identifier);
            CHECK_NONE(seed);
            CHECK_NONE(nym);
            CHECK_NONE(balance);
            CHECK_NONE(contact);
            CHECK_NONE(accountevent);
            CHECK_NONE(contactevent);
            CHECK_NONE(task);
            CHECK_NONE(notary);
        } break;
        case RPCCOMMAND_DELETECLAIM: {
            CHECK_SIZE(status, 1);
            CHECK_SUBOBJECTS(status, RPCResponseAllowedRPCStatus);
            CHECK_NONE(sessions);
            CHECK_NONE(identifier);
            CHECK_NONE(seed);
            CHECK_NONE(nym);
            CHECK_NONE(balance);
            CHECK_NONE(contact);
            CHECK_NONE(accountevent);
            CHECK_NONE(contactevent);
            CHECK_NONE(task);
            CHECK_NONE(notary);
        } break;
        case RPCCOMMAND_IMPORTSERVERCONTRACT: {
            CHECK_SUBOBJECTS(status, RPCResponseAllowedRPCStatus);
            CHECK_NONE(sessions);
            CHECK_NONE(identifier);
            CHECK_NONE(seed);
            CHECK_NONE(nym);
            CHECK_NONE(balance);
            CHECK_NONE(contact);
            CHECK_NONE(accountevent);
            CHECK_NONE(contactevent);
            CHECK_NONE(task);
            CHECK_NONE(notary);
        } break;
        case RPCCOMMAND_LISTSERVERCONTRACTS: {
            CHECK_SUBOBJECTS(status, RPCResponseAllowedRPCStatus);
            CHECK_NONE(sessions);

            if (atLeastOne) {
                CHECK_IDENTIFIERS(identifier);
            } else {
                CHECK_NONE(identifier);
            }

            CHECK_NONE(seed);
            CHECK_NONE(nym);
            CHECK_NONE(balance);
            CHECK_NONE(contact);
            CHECK_NONE(accountevent);
            CHECK_NONE(contactevent);
            CHECK_NONE(task);
            CHECK_NONE(notary);
        } break;
        case RPCCOMMAND_REGISTERNYM: {
            CHECK_SIZE(status, 1);
            CHECK_SUBOBJECTS(status, RPCResponseAllowedRPCStatus);
            CHECK_NONE(sessions);
            CHECK_NONE(identifier);
            CHECK_NONE(seed);
            CHECK_NONE(nym);
            CHECK_NONE(balance);
            CHECK_NONE(contact);
            CHECK_NONE(accountevent);
            CHECK_NONE(contactevent);
            CHECK_SUBOBJECTS(task, RPCResponseAllowedRPCTask);
            CHECK_NONE(notary);
        } break;
        case RPCCOMMAND_CREATEUNITDEFINITION: {
            CHECK_SIZE(status, 1);
            CHECK_SUBOBJECTS(status, RPCResponseAllowedRPCStatus);
            CHECK_NONE(sessions);

            if (atLeastOne) {
                CHECK_SIZE(identifier, 1);
                CHECK_IDENTIFIERS(identifier);
            } else {
                CHECK_NONE(identifier);
            }

            CHECK_NONE(seed);
            CHECK_NONE(nym);
            CHECK_NONE(balance);
            CHECK_NONE(contact);
            CHECK_NONE(accountevent);
            CHECK_NONE(contactevent);
            CHECK_NONE(task);
            CHECK_NONE(notary);
        } break;
        case RPCCOMMAND_LISTUNITDEFINITIONS: {
            CHECK_SIZE(status, 1);
            CHECK_SUBOBJECTS(status, RPCResponseAllowedRPCStatus);
            CHECK_NONE(sessions);

            if (atLeastOne) {
                CHECK_IDENTIFIERS(identifier);
            } else {
                CHECK_NONE(identifier);
            }

            CHECK_NONE(seed);
            CHECK_NONE(nym);
            CHECK_NONE(balance);
            CHECK_NONE(contact);
            CHECK_NONE(accountevent);
            CHECK_NONE(contactevent);
            CHECK_NONE(task);
            CHECK_NONE(notary);
        } break;
        case RPCCOMMAND_ISSUEUNITDEFINITION: {
            CHECK_SIZE(status, 1);
            CHECK_SUBOBJECTS(status, RPCResponseAllowedRPCStatus);
            CHECK_NONE(sessions);
            CHECK_IDENTIFIERS(identifier);
            CHECK_NONE(seed);
            CHECK_NONE(nym);
            CHECK_NONE(balance);
            CHECK_NONE(contact);
            CHECK_NONE(accountevent);
            CHECK_NONE(contactevent);
            CHECK_SUBOBJECTS(task, RPCResponseAllowedRPCTask);
            CHECK_NONE(notary);
        } break;
        case RPCCOMMAND_CREATECOMPATIBLEACCOUNT:
        case RPCCOMMAND_CREATEACCOUNT: {
            CHECK_SIZE(status, 1);
            CHECK_SUBOBJECTS(status, RPCResponseAllowedRPCStatus);
            CHECK_NONE(sessions);

            if (atLeastOne) {
                CHECK_SIZE(identifier, 1);
                CHECK_IDENTIFIERS(identifier);
            } else {
                CHECK_NONE(identifier);
            }

            CHECK_NONE(seed);
            CHECK_NONE(nym);
            CHECK_NONE(balance);
            CHECK_NONE(contact);
            CHECK_NONE(accountevent);
            CHECK_NONE(contactevent);
            CHECK_SUBOBJECTS(task, RPCResponseAllowedRPCTask);
            CHECK_NONE(notary);
        } break;
        case RPCCOMMAND_LISTACCOUNTS: {
            CHECK_SIZE(status, 1);
            CHECK_SUBOBJECTS(status, RPCResponseAllowedRPCStatus);
            CHECK_NONE(sessions);

            if (atLeastOne) {
                CHECK_IDENTIFIERS(identifier);
            } else {
                CHECK_NONE(identifier);
            }

            CHECK_NONE(seed);
            CHECK_NONE(nym);
            CHECK_NONE(balance);
            CHECK_NONE(contact);
            CHECK_NONE(accountevent);
            CHECK_NONE(contactevent);
            CHECK_NONE(task);
            CHECK_NONE(notary);
        } break;
        case RPCCOMMAND_GETACCOUNTBALANCE: {
            CHECK_SIZE(status, 1);
            CHECK_SUBOBJECTS(status, RPCResponseAllowedRPCStatus);
            CHECK_NONE(sessions);
            CHECK_NONE(identifier);
            CHECK_NONE(seed);
            CHECK_NONE(nym);

            if (atLeastOne) {
                OPTIONAL_SUBOBJECTS(balance, RPCResponseAllowedAccountData);
            } else {
                CHECK_NONE(balance);
            }

            CHECK_NONE(contact);
            CHECK_NONE(accountevent);
            CHECK_NONE(contactevent);
            CHECK_NONE(task);
            CHECK_NONE(notary);
        } break;
        case RPCCOMMAND_GETACCOUNTACTIVITY: {
            CHECK_SIZE(status, 1);
            CHECK_SUBOBJECTS(status, RPCResponseAllowedRPCStatus);
            CHECK_NONE(sessions);
            CHECK_NONE(identifier);
            CHECK_NONE(seed);
            CHECK_NONE(nym);
            CHECK_NONE(balance);
            CHECK_NONE(contact);
            OPTIONAL_SUBOBJECTS(accountevent, RPCResponseAllowedAccountEvent);
            CHECK_NONE(contactevent);
            CHECK_NONE(task);
            CHECK_NONE(notary);
        } break;
        case RPCCOMMAND_SENDPAYMENT: {
            CHECK_SIZE(status, 1);
            CHECK_SUBOBJECTS(status, RPCResponseAllowedRPCStatus);
            CHECK_NONE(sessions);
            CHECK_NONE(identifier);
            CHECK_NONE(seed);
            CHECK_NONE(nym);
            CHECK_NONE(balance);
            CHECK_NONE(contact);
            CHECK_NONE(accountevent);
            CHECK_NONE(contactevent);
            CHECK_SUBOBJECTS(task, RPCResponseAllowedRPCTask);
            CHECK_NONE(notary);
        } break;
        case RPCCOMMAND_MOVEFUNDS: {
            CHECK_SIZE(status, 1);
            CHECK_SUBOBJECTS(status, RPCResponseAllowedRPCStatus);
            CHECK_NONE(sessions);
            CHECK_NONE(identifier);
            CHECK_NONE(seed);
            CHECK_NONE(nym);
            CHECK_NONE(balance);
            CHECK_NONE(contact);
            CHECK_NONE(accountevent);
            CHECK_NONE(contactevent);
            CHECK_NONE(task);
            CHECK_NONE(notary);
        } break;
        case RPCCOMMAND_ADDCONTACT: {
            CHECK_SIZE(status, 1);
            CHECK_SUBOBJECTS(status, RPCResponseAllowedRPCStatus);
            CHECK_NONE(sessions);

            if (atLeastOne) {
                CHECK_IDENTIFIERS(identifier);
            } else {
                CHECK_NONE(identifier);
            }

            CHECK_NONE(seed);
            CHECK_NONE(nym);
            CHECK_NONE(balance);
            CHECK_NONE(contact);
            CHECK_NONE(accountevent);
            CHECK_NONE(contactevent);
            CHECK_NONE(task);
            CHECK_NONE(notary);
        } break;
        case RPCCOMMAND_LISTCONTACTS: {
            CHECK_SIZE(status, 1);
            CHECK_SUBOBJECTS(status, RPCResponseAllowedRPCStatus);
            CHECK_NONE(sessions);

            if (atLeastOne) {
                CHECK_IDENTIFIERS(identifier);
            } else {
                CHECK_NONE(identifier);
            }

            CHECK_NONE(seed);
            CHECK_NONE(nym);
            CHECK_NONE(balance);
            CHECK_NONE(contact);
            CHECK_NONE(accountevent);
            CHECK_NONE(contactevent);
            CHECK_NONE(task);
            CHECK_NONE(notary);
        } break;
        case RPCCOMMAND_GETCONTACT: {
            CHECK_SIZE(status, 1);
            CHECK_SUBOBJECTS(status, RPCResponseAllowedRPCStatus);
            CHECK_NONE(sessions);
            CHECK_NONE(identifier);
            CHECK_NONE(seed);
            CHECK_NONE(nym);
            CHECK_NONE(balance);

            if (atLeastOne) {
                OPTIONAL_SUBOBJECTS(contact, RPCResponseAllowedContact);
            } else {
                CHECK_NONE(contact);
            }

            CHECK_NONE(accountevent);
            CHECK_NONE(contactevent);
            CHECK_NONE(task);
            CHECK_NONE(notary);
        } break;
        case RPCCOMMAND_ADDCONTACTCLAIM: {
            CHECK_SIZE(status, 1);
            CHECK_SUBOBJECTS(status, RPCResponseAllowedRPCStatus);
            CHECK_NONE(sessions);
            CHECK_NONE(identifier);
            CHECK_NONE(seed);
            CHECK_NONE(nym);
            CHECK_NONE(balance);
            CHECK_NONE(contact);
            CHECK_NONE(accountevent);
            CHECK_NONE(contactevent);
            CHECK_NONE(task);
            CHECK_NONE(notary);
        } break;
        case RPCCOMMAND_DELETECONTACTCLAIM: {
            CHECK_SIZE(status, 1);
            CHECK_SUBOBJECTS(status, RPCResponseAllowedRPCStatus);
            CHECK_NONE(sessions);
            CHECK_NONE(identifier);
            CHECK_NONE(seed);
            CHECK_NONE(nym);
            CHECK_NONE(balance);
            CHECK_NONE(contact);
            CHECK_NONE(accountevent);
            CHECK_NONE(contactevent);
            CHECK_NONE(task);
            CHECK_NONE(notary);
        } break;
        case RPCCOMMAND_VERIFYCLAIM: {
            CHECK_SIZE(status, 1);
            CHECK_SUBOBJECTS(status, RPCResponseAllowedRPCStatus);
            CHECK_NONE(sessions);
            CHECK_NONE(identifier);
            CHECK_NONE(seed);
            CHECK_NONE(nym);
            CHECK_NONE(balance);
            CHECK_NONE(contact);
            CHECK_NONE(accountevent);
            CHECK_NONE(contactevent);
            CHECK_NONE(task);
            CHECK_NONE(notary);
        } break;
        case RPCCOMMAND_ACCEPTVERIFICATION: {
            CHECK_SIZE(status, 1);
            CHECK_SUBOBJECTS(status, RPCResponseAllowedRPCStatus);
            CHECK_NONE(sessions);
            CHECK_NONE(identifier);
            CHECK_NONE(seed);
            CHECK_NONE(nym);
            CHECK_NONE(balance);
            CHECK_NONE(contact);
            CHECK_NONE(accountevent);
            CHECK_NONE(contactevent);
            CHECK_NONE(task);
            CHECK_NONE(notary);
        } break;
        case RPCCOMMAND_SENDCONTACTMESSAGE: {
            CHECK_SIZE(status, 1);
            CHECK_SUBOBJECTS(status, RPCResponseAllowedRPCStatus);
            CHECK_NONE(sessions);
            CHECK_NONE(identifier);
            CHECK_NONE(seed);
            CHECK_NONE(nym);
            CHECK_NONE(balance);
            CHECK_NONE(contact);
            CHECK_NONE(accountevent);
            CHECK_NONE(contactevent);
            CHECK_NONE(task);
            CHECK_NONE(notary);
        } break;
        case RPCCOMMAND_GETCONTACTACTIVITY: {
            CHECK_SIZE(status, 1);
            CHECK_SUBOBJECTS(status, RPCResponseAllowedRPCStatus);
            CHECK_NONE(sessions);
            CHECK_NONE(identifier);
            CHECK_NONE(seed);
            CHECK_NONE(nym);
            CHECK_NONE(balance);
            CHECK_NONE(contact);
            CHECK_NONE(accountevent);
            OPTIONAL_SUBOBJECTS(contactevent, RPCResponseAllowedContactEvent);
            CHECK_NONE(task);
            CHECK_NONE(notary);
        } break;
        case RPCCOMMAND_GETSERVERCONTRACT: {
            CHECK_SIZE(status, 1);
            CHECK_SUBOBJECTS(status, RPCResponseAllowedRPCStatus);
            CHECK_NONE(sessions);
            CHECK_NONE(identifier);
            CHECK_NONE(seed);
            CHECK_NONE(nym);
            CHECK_NONE(balance);
            CHECK_NONE(contact);
            CHECK_NONE(accountevent);
            CHECK_NONE(contactevent);
            CHECK_NONE(task);

            if (atLeastOne) {
                OPTIONAL_SUBOBJECTS(notary, RPCResponseAllowedServerContract);
            } else {
                CHECK_NONE(notary);
            }
        } break;
        case RPCCOMMAND_GETPENDINGPAYMENTS: {
            CHECK_SIZE(status, 1);
            CHECK_SUBOBJECTS(status, RPCResponseAllowedRPCStatus);
            CHECK_NONE(sessions);
            CHECK_NONE(identifier);
            CHECK_NONE(seed);
            CHECK_NONE(nym);
            CHECK_NONE(balance);
            CHECK_NONE(contact);

            if (atLeastOne) {
                OPTIONAL_SUBOBJECTS(
                    accountevent, RPCResponseAllowedAccountEvent);
            } else {
                CHECK_NONE(accountevent);
            }

            CHECK_NONE(contactevent);
            CHECK_NONE(task);
            CHECK_NONE(notary);
        } break;
        case RPCCOMMAND_ACCEPTPENDINGPAYMENTS: {
            CHECK_SUBOBJECTS(status, RPCResponseAllowedRPCStatus);
            CHECK_NONE(sessions);
            CHECK_NONE(identifier);
            CHECK_NONE(seed);
            CHECK_NONE(nym);
            CHECK_NONE(balance);
            CHECK_NONE(contact);
            CHECK_NONE(accountevent);
            CHECK_NONE(contactevent);
            CHECK_SUBOBJECTS(task, RPCResponseAllowedRPCTask);
            CHECK_NONE(notary);
        } break;
        case RPCCOMMAND_GETCOMPATIBLEACCOUNTS: {
            CHECK_SUBOBJECTS(status, RPCResponseAllowedRPCStatus);
            CHECK_NONE(sessions);

            if (atLeastOne) {
                CHECK_IDENTIFIERS(identifier);
            } else {
                CHECK_NONE(identifier);
            }

            CHECK_NONE(seed);
            CHECK_NONE(nym);
            CHECK_NONE(balance);
            CHECK_NONE(contact);
            CHECK_NONE(accountevent);
            CHECK_NONE(contactevent);
            CHECK_NONE(task);
            CHECK_NONE(notary);
        } break;
        case RPCCOMMAND_ERROR:
        default: {
            FAIL_1("invalid type")
        }
    }

    return true;
}

bool CheckProto_2(const RPCResponse& input, const bool silent)
{
    UNDEFINED_VERSION(2)
}

bool CheckProto_3(const RPCResponse& input, const bool silent)
{
    UNDEFINED_VERSION(3)
}

bool CheckProto_4(const RPCResponse& input, const bool silent)
{
    UNDEFINED_VERSION(4)
}

bool CheckProto_5(const RPCResponse& input, const bool silent)
{
    UNDEFINED_VERSION(5)
}

bool CheckProto_6(const RPCResponse& input, const bool silent)
{
    UNDEFINED_VERSION(6)
}

bool CheckProto_7(const RPCResponse& input, const bool silent)
{
    UNDEFINED_VERSION(7)
}

bool CheckProto_8(const RPCResponse& input, const bool silent)
{
    UNDEFINED_VERSION(8)
}

bool CheckProto_9(const RPCResponse& input, const bool silent)
{
    UNDEFINED_VERSION(9)
}

bool CheckProto_10(const RPCResponse& input, const bool silent)
{
    UNDEFINED_VERSION(10)
}

bool CheckProto_11(const RPCResponse& input, const bool silent)
{
    UNDEFINED_VERSION(11)
}

bool CheckProto_12(const RPCResponse& input, const bool silent)
{
    UNDEFINED_VERSION(12)
}

bool CheckProto_13(const RPCResponse& input, const bool silent)
{
    UNDEFINED_VERSION(13)
}

bool CheckProto_14(const RPCResponse& input, const bool silent)
{
    UNDEFINED_VERSION(14)
}

bool CheckProto_15(const RPCResponse& input, const bool silent)
{
    UNDEFINED_VERSION(15)
}

bool CheckProto_16(const RPCResponse& input, const bool silent)
{
    UNDEFINED_VERSION(16)
}

bool CheckProto_17(const RPCResponse& input, const bool silent)
{
    UNDEFINED_VERSION(17)
}

bool CheckProto_18(const RPCResponse& input, const bool silent)
{
    UNDEFINED_VERSION(18)
}

bool CheckProto_19(const RPCResponse& input, const bool silent)
{
    UNDEFINED_VERSION(19)
}

bool CheckProto_20(const RPCResponse& input, const bool silent)
{
    UNDEFINED_VERSION(20)
}
}  // namespace opentxs::proto
