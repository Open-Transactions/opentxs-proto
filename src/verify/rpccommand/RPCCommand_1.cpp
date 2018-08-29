// Copyright (c) 2018 The Open-Transactions developers
// This Source Code Form is subject to the terms of the Mozilla Public
// License, v. 2.0. If a copy of the MPL was not distributed with this
// file, You can obtain one at http://mozilla.org/MPL/2.0/.

#include "opentxs-proto/Types.hpp"
#include "opentxs-proto/Check.hpp"

#define PROTO_NAME "RPC command"

namespace opentxs::proto
{
bool CheckProto_1(const RPCCommand& input, const bool silent)
{
    CHECK_IDENTIFIER(cookie)
    CHECK_EXISTS(type)

    switch (input.type()) {
        case RPCCOMMAND_ADDCLIENTSESSION: {
            if (-1 != input.session()) { FAIL_1("invalid session"); }

            OPTIONAL_IDENTIFIER(nym);
            CHECK_EXCLUDED(owner);
            CHECK_EXCLUDED(notary);
            CHECK_EXCLUDED(unit);
            CHECK_NONE(identifier);
            CHECK_SUBOBJECTS(arg, RPCCommandAllowedAPIArgument);
            CHECK_EXCLUDED(hdseed);
            CHECK_EXCLUDED(createnym);
            CHECK_NONE(claim);
            CHECK_NONE(server);
            CHECK_EXCLUDED(createunit);
            CHECK_EXCLUDED(sendpayment);
            CHECK_EXCLUDED(movefunds);
            CHECK_NONE(addcontact);
            CHECK_NONE(verifyclaim);
            CHECK_NONE(sendmessage);
            CHECK_NONE(acceptverification);
        } break;
        case RPCCOMMAND_ADDSERVERSESSION: {
            if (-1 != input.session()) { FAIL_1("invalid session"); }

            OPTIONAL_IDENTIFIER(nym);
            CHECK_EXCLUDED(owner);
            CHECK_EXCLUDED(notary);
            CHECK_EXCLUDED(unit);
            CHECK_NONE(identifier);
            CHECK_SUBOBJECTS(arg, RPCCommandAllowedAPIArgument);
            CHECK_EXCLUDED(hdseed);
            CHECK_EXCLUDED(createnym);
            CHECK_NONE(claim);
            CHECK_NONE(server);
            CHECK_EXCLUDED(createunit);
            CHECK_EXCLUDED(sendpayment);
            CHECK_EXCLUDED(movefunds);
            CHECK_NONE(addcontact);
            CHECK_NONE(verifyclaim);
            CHECK_NONE(sendmessage);
            CHECK_NONE(acceptverification);
        } break;
        case RPCCOMMAND_LISTCLIENTSSESSIONS: {
            if (-1 != input.session()) { FAIL_1("invalid session"); }

            OPTIONAL_IDENTIFIER(nym);
            CHECK_EXCLUDED(owner);
            CHECK_EXCLUDED(notary);
            CHECK_EXCLUDED(unit);
            CHECK_NONE(identifier);
            CHECK_NONE(arg);
            CHECK_EXCLUDED(hdseed);
            CHECK_EXCLUDED(createnym);
            CHECK_NONE(claim);
            CHECK_NONE(server);
            CHECK_EXCLUDED(createunit);
            CHECK_EXCLUDED(sendpayment);
            CHECK_EXCLUDED(movefunds);
            CHECK_NONE(addcontact);
            CHECK_NONE(verifyclaim);
            CHECK_NONE(sendmessage);
            CHECK_NONE(acceptverification);
        } break;
        case RPCCOMMAND_LISTSERVERSSESSIONS: {
            if (-1 != input.session()) { FAIL_1("invalid session"); }

            OPTIONAL_IDENTIFIER(nym);
            CHECK_EXCLUDED(owner);
            CHECK_EXCLUDED(notary);
            CHECK_EXCLUDED(unit);
            CHECK_NONE(identifier);
            CHECK_NONE(arg);
            CHECK_EXCLUDED(hdseed);
            CHECK_EXCLUDED(createnym);
            CHECK_NONE(claim);
            CHECK_NONE(server);
            CHECK_EXCLUDED(createunit);
            CHECK_EXCLUDED(sendpayment);
            CHECK_EXCLUDED(movefunds);
            CHECK_NONE(addcontact);
            CHECK_NONE(verifyclaim);
            CHECK_NONE(sendmessage);
            CHECK_NONE(acceptverification);
        } break;
        case RPCCOMMAND_IMPORTHDSEED: {
            if (0 > input.session()) { FAIL_1("invalid session"); }

            OPTIONAL_IDENTIFIER(nym);
            CHECK_EXCLUDED(owner);
            CHECK_EXCLUDED(notary);
            CHECK_EXCLUDED(unit);
            CHECK_NONE(identifier);
            CHECK_NONE(arg);
            CHECK_SUBOBJECT(hdseed, RPCCommandAllowedHDSeed);
            CHECK_EXCLUDED(createnym);
            CHECK_NONE(claim);
            CHECK_NONE(server);
            CHECK_EXCLUDED(createunit);
            CHECK_EXCLUDED(sendpayment);
            CHECK_EXCLUDED(movefunds);
            CHECK_NONE(addcontact);
            CHECK_NONE(verifyclaim);
            CHECK_NONE(sendmessage);
            CHECK_NONE(acceptverification);
        } break;
        case RPCCOMMAND_LISTHDSEEDS: {
            if (0 > input.session()) { FAIL_1("invalid session"); }

            OPTIONAL_IDENTIFIER(nym);
            CHECK_EXCLUDED(owner);
            CHECK_EXCLUDED(notary);
            CHECK_EXCLUDED(unit);
            CHECK_NONE(identifier);
            CHECK_NONE(arg);
            CHECK_EXCLUDED(hdseed);
            CHECK_EXCLUDED(createnym);
            CHECK_NONE(claim);
            CHECK_NONE(server);
            CHECK_EXCLUDED(createunit);
            CHECK_EXCLUDED(sendpayment);
            CHECK_EXCLUDED(movefunds);
            CHECK_NONE(addcontact);
            CHECK_NONE(verifyclaim);
            CHECK_NONE(sendmessage);
            CHECK_NONE(acceptverification);
        } break;
        case RPCCOMMAND_GETHDSEED: {
            if (0 > input.session()) { FAIL_1("invalid session"); }

            OPTIONAL_IDENTIFIER(nym);
            CHECK_EXCLUDED(owner);
            CHECK_EXCLUDED(notary);
            CHECK_EXCLUDED(unit);
            CHECK_HAVE(identifier);
            CHECK_IDENTIFIERS(identifier);
            CHECK_NONE(arg);
            CHECK_EXCLUDED(hdseed);
            CHECK_EXCLUDED(createnym);
            CHECK_NONE(claim);
            CHECK_NONE(server);
            CHECK_EXCLUDED(createunit);
            CHECK_EXCLUDED(sendpayment);
            CHECK_EXCLUDED(movefunds);
            CHECK_NONE(addcontact);
            CHECK_NONE(verifyclaim);
            CHECK_NONE(sendmessage);
            CHECK_NONE(acceptverification);
        } break;
        case RPCCOMMAND_CREATENYM: {
            if (0 > input.session()) { FAIL_1("invalid session"); }

            OPTIONAL_IDENTIFIER(nym);
            CHECK_EXCLUDED(owner);
            CHECK_EXCLUDED(notary);
            CHECK_EXCLUDED(unit);
            CHECK_NONE(identifier);
            CHECK_NONE(arg);
            CHECK_EXCLUDED(hdseed);
            CHECK_SUBOBJECT(createnym, RPCCommandAllowedCreateNym);
            CHECK_NONE(claim);
            CHECK_NONE(server);
            CHECK_EXCLUDED(createunit);
            CHECK_EXCLUDED(sendpayment);
            CHECK_EXCLUDED(movefunds);
            CHECK_NONE(addcontact);
            CHECK_NONE(verifyclaim);
            CHECK_NONE(sendmessage);
            CHECK_NONE(acceptverification);
        } break;
        case RPCCOMMAND_LISTNYMS: {
            if (0 > input.session()) { FAIL_1("invalid session"); }

            OPTIONAL_IDENTIFIER(nym);
            CHECK_EXCLUDED(owner);
            CHECK_EXCLUDED(notary);
            CHECK_EXCLUDED(unit);
            CHECK_NONE(identifier);
            CHECK_NONE(arg);
            CHECK_EXCLUDED(hdseed);
            CHECK_EXCLUDED(createnym);
            CHECK_NONE(claim);
            CHECK_NONE(server);
            CHECK_EXCLUDED(createunit);
            CHECK_EXCLUDED(sendpayment);
            CHECK_EXCLUDED(movefunds);
            CHECK_NONE(addcontact);
            CHECK_NONE(verifyclaim);
            CHECK_NONE(sendmessage);
            CHECK_NONE(acceptverification);
        } break;
        case RPCCOMMAND_GETNYM: {
            if (0 > input.session()) { FAIL_1("invalid session"); }

            OPTIONAL_IDENTIFIER(nym);
            CHECK_EXCLUDED(owner);
            CHECK_EXCLUDED(notary);
            CHECK_EXCLUDED(unit);
            CHECK_HAVE(identifier);
            CHECK_IDENTIFIERS(identifier);
            CHECK_NONE(arg);
            CHECK_EXCLUDED(hdseed);
            CHECK_EXCLUDED(createnym);
            CHECK_NONE(claim);
            CHECK_NONE(server);
            CHECK_EXCLUDED(createunit);
            CHECK_EXCLUDED(sendpayment);
            CHECK_EXCLUDED(movefunds);
            CHECK_NONE(addcontact);
            CHECK_NONE(verifyclaim);
            CHECK_NONE(sendmessage);
            CHECK_NONE(acceptverification);
        } break;
        case RPCCOMMAND_ADDCLAIM: {
            if (0 > input.session()) { FAIL_1("invalid session"); }

            OPTIONAL_IDENTIFIER(nym);
            CHECK_IDENTIFIER(owner);
            CHECK_EXCLUDED(notary);
            CHECK_EXCLUDED(unit);
            CHECK_NONE(identifier);
            CHECK_NONE(arg);
            CHECK_EXCLUDED(hdseed);
            CHECK_EXCLUDED(createnym);
            CHECK_SUBOBJECTS(claim, RPCCommandAllowedAddClaim);
            CHECK_NONE(server);
            CHECK_EXCLUDED(createunit);
            CHECK_EXCLUDED(sendpayment);
            CHECK_EXCLUDED(movefunds);
            CHECK_NONE(addcontact);
            CHECK_NONE(verifyclaim);
            CHECK_NONE(sendmessage);
            CHECK_NONE(acceptverification);
        } break;
        case RPCCOMMAND_DELETECLAIM: {
            if (0 > input.session()) { FAIL_1("invalid session"); }

            OPTIONAL_IDENTIFIER(nym);
            CHECK_IDENTIFIER(owner);
            CHECK_EXCLUDED(notary);
            CHECK_EXCLUDED(unit);
            CHECK_HAVE(identifier);
            CHECK_IDENTIFIERS(identifier);
            CHECK_NONE(arg);
            CHECK_EXCLUDED(hdseed);
            CHECK_EXCLUDED(createnym);
            CHECK_NONE(claim);
            CHECK_NONE(server);
            CHECK_EXCLUDED(createunit);
            CHECK_EXCLUDED(sendpayment);
            CHECK_EXCLUDED(movefunds);
            CHECK_NONE(addcontact);
            CHECK_NONE(verifyclaim);
            CHECK_NONE(sendmessage);
            CHECK_NONE(acceptverification);
        } break;
        case RPCCOMMAND_IMPORTSERVERCONTRACT: {
            if (0 > input.session()) { FAIL_1("invalid session"); }

            OPTIONAL_IDENTIFIER(nym);
            CHECK_EXCLUDED(owner);
            CHECK_EXCLUDED(notary);
            CHECK_EXCLUDED(unit);
            CHECK_NONE(identifier);
            CHECK_NONE(arg);
            CHECK_EXCLUDED(hdseed);
            CHECK_EXCLUDED(createnym);
            CHECK_NONE(claim);
            CHECK_HAVE(server);
            CHECK_EXCLUDED(createunit);
            CHECK_SUBOBJECTS(server, RPCCommandAllowedServerContract);
            CHECK_EXCLUDED(sendpayment);
            CHECK_EXCLUDED(movefunds);
            CHECK_NONE(addcontact);
            CHECK_NONE(verifyclaim);
            CHECK_NONE(sendmessage);
            CHECK_NONE(acceptverification);
        } break;
        case RPCCOMMAND_LISTSERVERCONTRACTS: {
            if (0 > input.session()) { FAIL_1("invalid session"); }

            OPTIONAL_IDENTIFIER(nym);
            CHECK_EXCLUDED(owner);
            CHECK_EXCLUDED(notary);
            CHECK_EXCLUDED(unit);
            CHECK_NONE(identifier);
            CHECK_NONE(arg);
            CHECK_EXCLUDED(hdseed);
            CHECK_EXCLUDED(createnym);
            CHECK_NONE(claim);
            CHECK_NONE(server);
            CHECK_EXCLUDED(createunit);
            CHECK_EXCLUDED(sendpayment);
            CHECK_EXCLUDED(movefunds);
            CHECK_NONE(addcontact);
            CHECK_NONE(verifyclaim);
            CHECK_NONE(sendmessage);
            CHECK_NONE(acceptverification);
        } break;
        case RPCCOMMAND_REGISTERNYM: {
            if (0 > input.session()) { FAIL_1("invalid session"); }

            OPTIONAL_IDENTIFIER(nym);
            CHECK_IDENTIFIER(owner);
            CHECK_IDENTIFIER(notary);
            CHECK_EXCLUDED(unit);
            CHECK_NONE(identifier);
            CHECK_NONE(arg);
            CHECK_EXCLUDED(hdseed);
            CHECK_EXCLUDED(createnym);
            CHECK_NONE(claim);
            CHECK_NONE(server);
            CHECK_EXCLUDED(createunit);
            CHECK_EXCLUDED(sendpayment);
            CHECK_EXCLUDED(movefunds);
            CHECK_NONE(addcontact);
            CHECK_NONE(verifyclaim);
            CHECK_NONE(sendmessage);
            CHECK_NONE(acceptverification);
        } break;
        case RPCCOMMAND_CREATEUNITDEFINITION: {
            if (0 > input.session()) { FAIL_1("invalid session"); }

            OPTIONAL_IDENTIFIER(nym);
            CHECK_IDENTIFIER(owner);
            CHECK_EXCLUDED(notary);
            CHECK_EXCLUDED(unit);
            CHECK_NONE(identifier);
            CHECK_NONE(arg);
            CHECK_EXCLUDED(hdseed);
            CHECK_EXCLUDED(createnym);
            CHECK_NONE(claim);
            CHECK_NONE(server);
            CHECK_SUBOBJECT(
                createunit, RPCCommandAllowedCreateInstrumentDefinition);
            CHECK_EXCLUDED(sendpayment);
            CHECK_EXCLUDED(movefunds);
            CHECK_NONE(addcontact);
            CHECK_NONE(verifyclaim);
            CHECK_NONE(sendmessage);
            CHECK_NONE(acceptverification);
        } break;
        case RPCCOMMAND_LISTUNITDEFINITIONS: {
            if (0 > input.session()) { FAIL_1("invalid session"); }

            OPTIONAL_IDENTIFIER(nym);
            CHECK_EXCLUDED(owner);
            CHECK_EXCLUDED(notary);
            CHECK_EXCLUDED(unit);
            CHECK_NONE(identifier);
            CHECK_NONE(arg);
            CHECK_EXCLUDED(hdseed);
            CHECK_EXCLUDED(createnym);
            CHECK_NONE(claim);
            CHECK_NONE(server);
            CHECK_EXCLUDED(createunit);
            CHECK_EXCLUDED(sendpayment);
            CHECK_EXCLUDED(movefunds);
            CHECK_NONE(addcontact);
            CHECK_NONE(verifyclaim);
            CHECK_NONE(sendmessage);
            CHECK_NONE(acceptverification);
        } break;
        case RPCCOMMAND_ISSUEUNITDEFINITION: {
            if (0 > input.session()) { FAIL_1("invalid session"); }

            OPTIONAL_IDENTIFIER(nym);
            CHECK_IDENTIFIER(owner);
            CHECK_IDENTIFIER(notary);
            CHECK_IDENTIFIER(unit);
            CHECK_NONE(identifier);
            CHECK_NONE(arg);
            CHECK_EXCLUDED(hdseed);
            CHECK_EXCLUDED(createnym);
            CHECK_NONE(claim);
            CHECK_NONE(server);
            CHECK_EXCLUDED(createunit);
            CHECK_EXCLUDED(sendpayment);
            CHECK_EXCLUDED(movefunds);
            CHECK_NONE(addcontact);
            CHECK_NONE(verifyclaim);
            CHECK_NONE(sendmessage);
            CHECK_NONE(acceptverification);
        } break;
        case RPCCOMMAND_CREATEACCOUNT: {
            if (0 > input.session()) { FAIL_1("invalid session"); }

            OPTIONAL_IDENTIFIER(nym);
            CHECK_IDENTIFIER(owner);
            CHECK_IDENTIFIER(notary);
            CHECK_IDENTIFIER(unit);
            CHECK_NONE(identifier);
            CHECK_NONE(arg);
            CHECK_EXCLUDED(hdseed);
            CHECK_EXCLUDED(createnym);
            CHECK_NONE(claim);
            CHECK_NONE(server);
            CHECK_EXCLUDED(createunit);
            CHECK_EXCLUDED(sendpayment);
            CHECK_EXCLUDED(movefunds);
            CHECK_NONE(addcontact);
            CHECK_NONE(verifyclaim);
            CHECK_NONE(sendmessage);
            CHECK_NONE(acceptverification);
        } break;
        case RPCCOMMAND_LISTACCOUNTS: {
            if (0 > input.session()) { FAIL_1("invalid session"); }

            OPTIONAL_IDENTIFIER(nym);
            CHECK_EXCLUDED(owner);
            OPTIONAL_IDENTIFIER(notary);
            OPTIONAL_IDENTIFIER(unit);
            CHECK_NONE(identifier);
            CHECK_NONE(arg);
            CHECK_EXCLUDED(hdseed);
            CHECK_EXCLUDED(createnym);
            CHECK_NONE(claim);
            CHECK_NONE(server);
            CHECK_EXCLUDED(createunit);
            CHECK_EXCLUDED(sendpayment);
            CHECK_EXCLUDED(movefunds);
            CHECK_NONE(addcontact);
            CHECK_NONE(verifyclaim);
            CHECK_NONE(sendmessage);
            CHECK_NONE(acceptverification);
        } break;
        case RPCCOMMAND_GETACCOUNTBALANCE: {
            if (0 > input.session()) { FAIL_1("invalid session"); }

            OPTIONAL_IDENTIFIER(nym);
            CHECK_EXCLUDED(owner);
            CHECK_EXCLUDED(notary);
            CHECK_EXCLUDED(unit);
            CHECK_IDENTIFIERS(identifier);
            CHECK_NONE(arg);
            CHECK_EXCLUDED(hdseed);
            CHECK_EXCLUDED(createnym);
            CHECK_NONE(claim);
            CHECK_NONE(server);
            CHECK_EXCLUDED(createunit);
            CHECK_EXCLUDED(sendpayment);
            CHECK_EXCLUDED(movefunds);
            CHECK_NONE(addcontact);
            CHECK_NONE(verifyclaim);
            CHECK_NONE(sendmessage);
            CHECK_NONE(acceptverification);
        } break;
        case RPCCOMMAND_GETACCOUNTACTIVITY: {
            if (0 > input.session()) { FAIL_1("invalid session"); }

            OPTIONAL_IDENTIFIER(nym);
            CHECK_EXCLUDED(owner);
            CHECK_EXCLUDED(notary);
            CHECK_EXCLUDED(unit);
            CHECK_SIZE(identifier, 1);
            CHECK_IDENTIFIERS(identifier);
            CHECK_NONE(arg);
            CHECK_EXCLUDED(hdseed);
            CHECK_EXCLUDED(createnym);
            CHECK_NONE(claim);
            CHECK_NONE(server);
            CHECK_EXCLUDED(createunit);
            CHECK_EXCLUDED(sendpayment);
            CHECK_EXCLUDED(movefunds);
            CHECK_NONE(addcontact);
            CHECK_NONE(verifyclaim);
            CHECK_NONE(sendmessage);
            CHECK_NONE(acceptverification);
        } break;
        case RPCCOMMAND_SENDPAYMENT: {
            if (0 > input.session()) { FAIL_1("invalid session"); }

            OPTIONAL_IDENTIFIER(nym);
            CHECK_EXCLUDED(owner);
            CHECK_EXCLUDED(notary);
            CHECK_EXCLUDED(unit);
            CHECK_NONE(identifier);
            CHECK_NONE(arg);
            CHECK_EXCLUDED(hdseed);
            CHECK_EXCLUDED(createnym);
            CHECK_NONE(claim);
            CHECK_NONE(server);
            CHECK_EXCLUDED(createunit);
            CHECK_SUBOBJECT(sendpayment, RPCCommandAllowedSendPayment);
            CHECK_EXCLUDED(movefunds);
            CHECK_NONE(addcontact);
            CHECK_NONE(verifyclaim);
            CHECK_NONE(sendmessage);
            CHECK_NONE(acceptverification);
        } break;
        case RPCCOMMAND_MOVEFUNDS: {
            if (0 > input.session()) { FAIL_1("invalid session"); }

            OPTIONAL_IDENTIFIER(nym);
            CHECK_EXCLUDED(owner);
            CHECK_EXCLUDED(notary);
            CHECK_EXCLUDED(unit);
            CHECK_NONE(identifier);
            CHECK_NONE(arg);
            CHECK_EXCLUDED(hdseed);
            CHECK_EXCLUDED(createnym);
            CHECK_NONE(claim);
            CHECK_NONE(server);
            CHECK_EXCLUDED(createunit);
            CHECK_EXCLUDED(sendpayment);
            CHECK_SUBOBJECT(movefunds, RPCCommandAllowedSendPayment);
            CHECK_NONE(addcontact);
            CHECK_NONE(verifyclaim);
            CHECK_NONE(sendmessage);
            CHECK_NONE(acceptverification);
        } break;
        case RPCCOMMAND_ADDCONTACT: {
            if (0 > input.session()) { FAIL_1("invalid session"); }

            OPTIONAL_IDENTIFIER(nym);
            CHECK_EXCLUDED(owner);
            CHECK_EXCLUDED(notary);
            CHECK_EXCLUDED(unit);
            CHECK_NONE(identifier);
            CHECK_NONE(arg);
            CHECK_EXCLUDED(hdseed);
            CHECK_EXCLUDED(createnym);
            CHECK_NONE(claim);
            CHECK_NONE(server);
            CHECK_EXCLUDED(createunit);
            CHECK_EXCLUDED(sendpayment);
            CHECK_EXCLUDED(movefunds);
            CHECK_SUBOBJECTS(addcontact, RPCCommandAllowedAddContact);
            CHECK_NONE(verifyclaim);
            CHECK_NONE(sendmessage);
            CHECK_NONE(acceptverification);
        } break;
        case RPCCOMMAND_LISTCONTACTS: {
            if (0 > input.session()) { FAIL_1("invalid session"); }

            OPTIONAL_IDENTIFIER(nym);
            CHECK_EXCLUDED(owner);
            CHECK_EXCLUDED(notary);
            CHECK_EXCLUDED(unit);
            CHECK_NONE(identifier);
            CHECK_NONE(arg);
            CHECK_EXCLUDED(hdseed);
            CHECK_EXCLUDED(createnym);
            CHECK_NONE(claim);
            CHECK_NONE(server);
            CHECK_EXCLUDED(createunit);
            CHECK_EXCLUDED(sendpayment);
            CHECK_EXCLUDED(movefunds);
            CHECK_NONE(addcontact);
            CHECK_NONE(verifyclaim);
            CHECK_NONE(sendmessage);
            CHECK_NONE(acceptverification);
        } break;
        case RPCCOMMAND_GETCONTACT: {
            if (0 > input.session()) { FAIL_1("invalid session"); }

            OPTIONAL_IDENTIFIER(nym);
            CHECK_EXCLUDED(owner);
            CHECK_EXCLUDED(notary);
            CHECK_EXCLUDED(unit);
            CHECK_HAVE(identifier);
            CHECK_IDENTIFIERS(identifier);
            CHECK_NONE(arg);
            CHECK_EXCLUDED(hdseed);
            CHECK_EXCLUDED(createnym);
            CHECK_NONE(claim);
            CHECK_NONE(server);
            CHECK_EXCLUDED(createunit);
            CHECK_EXCLUDED(sendpayment);
            CHECK_EXCLUDED(movefunds);
            CHECK_NONE(addcontact);
            CHECK_NONE(verifyclaim);
            CHECK_NONE(sendmessage);
            CHECK_NONE(acceptverification);
        } break;
        case RPCCOMMAND_ADDCONTACTCLAIM: {
            if (0 > input.session()) { FAIL_1("invalid session"); }

            OPTIONAL_IDENTIFIER(nym);
            CHECK_IDENTIFIER(owner);
            CHECK_EXCLUDED(notary);
            CHECK_EXCLUDED(unit);
            CHECK_NONE(identifier);
            CHECK_NONE(arg);
            CHECK_EXCLUDED(hdseed);
            CHECK_EXCLUDED(createnym);
            CHECK_SUBOBJECTS(claim, RPCCommandAllowedAddClaim);
            CHECK_NONE(server);
            CHECK_EXCLUDED(createunit);
            CHECK_EXCLUDED(sendpayment);
            CHECK_EXCLUDED(movefunds);
            CHECK_NONE(addcontact);
            CHECK_NONE(verifyclaim);
            CHECK_NONE(sendmessage);
            CHECK_NONE(acceptverification);
        } break;
        case RPCCOMMAND_DELETECONTACTCLAIM: {
            if (0 > input.session()) { FAIL_1("invalid session"); }

            OPTIONAL_IDENTIFIER(nym);
            CHECK_IDENTIFIER(owner);
            CHECK_EXCLUDED(notary);
            CHECK_EXCLUDED(unit);
            CHECK_HAVE(identifier);
            CHECK_IDENTIFIERS(identifier);
            CHECK_NONE(arg);
            CHECK_EXCLUDED(hdseed);
            CHECK_EXCLUDED(createnym);
            CHECK_NONE(claim);
            CHECK_NONE(server);
            CHECK_EXCLUDED(createunit);
            CHECK_EXCLUDED(sendpayment);
            CHECK_EXCLUDED(movefunds);
            CHECK_NONE(addcontact);
            CHECK_NONE(verifyclaim);
            CHECK_NONE(sendmessage);
            CHECK_NONE(acceptverification);
        } break;
        case RPCCOMMAND_VERIFYCLAIM: {
            if (0 > input.session()) { FAIL_1("invalid session"); }

            OPTIONAL_IDENTIFIER(nym);
            CHECK_EXCLUDED(owner);
            CHECK_EXCLUDED(notary);
            CHECK_EXCLUDED(unit);
            CHECK_NONE(identifier);
            CHECK_NONE(arg);
            CHECK_EXCLUDED(hdseed);
            CHECK_EXCLUDED(createnym);
            CHECK_NONE(claim);
            CHECK_NONE(server);
            CHECK_EXCLUDED(createunit);
            CHECK_EXCLUDED(sendpayment);
            CHECK_EXCLUDED(movefunds);
            CHECK_NONE(addcontact);
            CHECK_SUBOBJECTS(verifyclaim, RPCCommandAllowedVerifyClaim);
            CHECK_NONE(sendmessage);
            CHECK_NONE(acceptverification);
        } break;
        case RPCCOMMAND_ACCEPTVERIFICATION: {
            if (0 > input.session()) { FAIL_1("invalid session"); }

            OPTIONAL_IDENTIFIER(nym);
            CHECK_IDENTIFIER(owner);
            CHECK_EXCLUDED(notary);
            CHECK_EXCLUDED(unit);
            CHECK_NONE(identifier);
            CHECK_NONE(arg);
            CHECK_EXCLUDED(hdseed);
            CHECK_EXCLUDED(createnym);
            CHECK_NONE(claim);
            CHECK_NONE(server);
            CHECK_EXCLUDED(createunit);
            CHECK_EXCLUDED(sendpayment);
            CHECK_EXCLUDED(movefunds);
            CHECK_NONE(addcontact);
            CHECK_NONE(verifyclaim);
            CHECK_NONE(sendmessage);
            CHECK_SUBOBJECTS_VA(
                acceptverification, RPCCommandAllowedVerification, true);
        } break;
        case RPCCOMMAND_SENDCONTACTMESSAGE: {
            if (0 > input.session()) { FAIL_1("invalid session"); }

            OPTIONAL_IDENTIFIER(nym);
            CHECK_EXCLUDED(owner);
            CHECK_EXCLUDED(notary);
            CHECK_EXCLUDED(unit);
            CHECK_NONE(identifier);
            CHECK_NONE(arg);
            CHECK_EXCLUDED(hdseed);
            CHECK_EXCLUDED(createnym);
            CHECK_NONE(claim);
            CHECK_NONE(server);
            CHECK_EXCLUDED(createunit);
            CHECK_EXCLUDED(sendpayment);
            CHECK_EXCLUDED(movefunds);
            CHECK_NONE(addcontact);
            CHECK_NONE(verifyclaim);
            CHECK_SUBOBJECTS(sendmessage, RPCCommandAllowedSendMessage);
            CHECK_NONE(acceptverification);
        } break;
        case RPCCOMMAND_GETCONTACTACTIVITY: {
            if (0 > input.session()) { FAIL_1("invalid session"); }

            OPTIONAL_IDENTIFIER(nym);
            CHECK_EXCLUDED(owner);
            CHECK_EXCLUDED(notary);
            CHECK_EXCLUDED(unit);
            CHECK_HAVE(identifier);
            CHECK_IDENTIFIERS(identifier);
            CHECK_NONE(arg);
            CHECK_EXCLUDED(hdseed);
            CHECK_EXCLUDED(createnym);
            CHECK_NONE(claim);
            CHECK_NONE(server);
            CHECK_EXCLUDED(createunit);
            CHECK_EXCLUDED(sendpayment);
            CHECK_EXCLUDED(movefunds);
            CHECK_NONE(addcontact);
            CHECK_NONE(verifyclaim);
            CHECK_NONE(sendmessage);
            CHECK_NONE(acceptverification);
        } break;
        case RPCCOMMAND_ERROR:
        default: {
            FAIL_1("invalid type")
        }
    }

    return true;
}

bool CheckProto_2(const RPCCommand& input, const bool silent)
{
    UNDEFINED_VERSION(2)
}

bool CheckProto_3(const RPCCommand& input, const bool silent)
{
    UNDEFINED_VERSION(3)
}

bool CheckProto_4(const RPCCommand& input, const bool silent)
{
    UNDEFINED_VERSION(4)
}

bool CheckProto_5(const RPCCommand& input, const bool silent)
{
    UNDEFINED_VERSION(5)
}

bool CheckProto_6(const RPCCommand& input, const bool silent)
{
    UNDEFINED_VERSION(6)
}

bool CheckProto_7(const RPCCommand& input, const bool silent)
{
    UNDEFINED_VERSION(7)
}

bool CheckProto_8(const RPCCommand& input, const bool silent)
{
    UNDEFINED_VERSION(8)
}

bool CheckProto_9(const RPCCommand& input, const bool silent)
{
    UNDEFINED_VERSION(9)
}

bool CheckProto_10(const RPCCommand& input, const bool silent)
{
    UNDEFINED_VERSION(10)
}

bool CheckProto_11(const RPCCommand& input, const bool silent)
{
    UNDEFINED_VERSION(11)
}

bool CheckProto_12(const RPCCommand& input, const bool silent)
{
    UNDEFINED_VERSION(12)
}

bool CheckProto_13(const RPCCommand& input, const bool silent)
{
    UNDEFINED_VERSION(13)
}

bool CheckProto_14(const RPCCommand& input, const bool silent)
{
    UNDEFINED_VERSION(14)
}

bool CheckProto_15(const RPCCommand& input, const bool silent)
{
    UNDEFINED_VERSION(15)
}

bool CheckProto_16(const RPCCommand& input, const bool silent)
{
    UNDEFINED_VERSION(16)
}

bool CheckProto_17(const RPCCommand& input, const bool silent)
{
    UNDEFINED_VERSION(17)
}

bool CheckProto_18(const RPCCommand& input, const bool silent)
{
    UNDEFINED_VERSION(18)
}

bool CheckProto_19(const RPCCommand& input, const bool silent)
{
    UNDEFINED_VERSION(19)
}

bool CheckProto_20(const RPCCommand& input, const bool silent)
{
    UNDEFINED_VERSION(20)
}
}  // namespace opentxs::proto
