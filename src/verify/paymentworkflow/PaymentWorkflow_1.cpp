// Copyright (c) 2018 The Open-Transactions developers
// This Source Code Form is subject to the terms of the Mozilla Public
// License, v. 2.0. If a copy of the MPL was not distributed with this
// file, You can obtain one at http://mozilla.org/MPL/2.0/.

#include "opentxs-proto/Types.hpp"
#include "opentxs-proto/Check.hpp"

#define BAD_EVENTS(a, b)                                                       \
    {                                                                          \
        FAIL7(                                                                 \
            a,                                                                 \
            b,                                                                 \
            " Type: ",                                                         \
            std::to_string(static_cast<std::uint32_t>(input.type())),          \
            " State: ",                                                        \
            std::to_string(static_cast<std::uint32_t>(input.state())))         \
    }

#define PROTO_NAME "payment workflow"

namespace opentxs::proto
{
bool CheckProto_1(const PaymentWorkflow& input, const bool silent)
{
    CHECK_IDENTIFIER(id)

    try {
        const bool valid =
            (1 ==
             PaymentWorkflowAllowedState.at({input.version(), input.type()})
                 .count(input.state()));

        if (false == valid) {
            FAIL4("Invalid state")
        }
    } catch (const std::out_of_range&) {
        FAIL4("Invalid type")
    }

    switch (input.type()) {
        case PAYMENTWORKFLOWTYPE_OUTGOINGCHEQUE:
        case PAYMENTWORKFLOWTYPE_INCOMINGCHEQUE:
        case PAYMENTWORKFLOWTYPE_OUTGOINGINVOICE:
        case PAYMENTWORKFLOWTYPE_INCOMINGINVOICE: {
            if (1 != input.source().size()) {
                FAIL5(
                    "Incorrect number of source objects", input.source().size())
            }

            if (1 != input.party().size()) {
                FAIL5("Incorrect number of parties", input.party().size())
            }
        } break;
        default: {
            FAIL4("Invalid type")
        }
    }

    CHECK_SUBOBJECTS(source, PaymentWorkflowAllowedInstrumentRevision)
    CHECK_IDENTIFIER(notary)
    CHECK_IDENTIFIERS(party)
    std::map<PaymentEventType, std::size_t> events{};

    for (const auto& it : input.event()) {
        try {
            const bool validevent = Check(
                it,
                PaymentWorkflowAllowedPaymentEvent.at(input.version()).first,
                PaymentWorkflowAllowedPaymentEvent.at(input.version()).second,
                silent,
                input.version(),
                input.type(),
                events);

            if (false == validevent) {
                const auto fail = std::string("invalid ") + "event";
                FAIL4(fail)
            }
        } catch (const std::out_of_range&) {
            const auto fail = std::string("allowed ") + "event" +
                              " version not defined for version";
            FAIL5(fail, input.version())
        }
    }

    CHECK_IDENTIFIERS(unit)
    CHECK_IDENTIFIERS(account)

    const auto& createEvents = events[PAYMENTEVENTTYPE_CREATE];
    const auto& conveyEvents = events[PAYMENTEVENTTYPE_CONVEY];
    const auto& cancelEvents = events[PAYMENTEVENTTYPE_CANCEL];
    const auto& acceptEvents = events[PAYMENTEVENTTYPE_ACCEPT];
    const auto& completeEvents = events[PAYMENTEVENTTYPE_COMPLETE];
    const auto accounts = input.account().size();

    switch (input.type()) {
        case PAYMENTWORKFLOWTYPE_OUTGOINGCHEQUE:
        case PAYMENTWORKFLOWTYPE_OUTGOINGINVOICE: {
            if (1 != accounts) {
                FAIL5("Wrong number of accounts", accounts)
            }

            switch (input.state()) {
                case PAYMENTWORKFLOWSTATE_UNSENT: {
                    if (1 != createEvents) {
                        BAD_EVENTS(
                            "Wrong number of create events", createEvents)
                    }

                    // TODO: convey events are allowed only if they are
                    //       all failed

                    if (0 < cancelEvents) {
                        BAD_EVENTS(
                            "Wrong number of cancel events", cancelEvents)
                    }

                    if (0 < acceptEvents) {
                        BAD_EVENTS(
                            "Wrong number of accept events", acceptEvents)
                    }

                    if (0 < completeEvents) {
                        BAD_EVENTS(
                            "Wrong number of complete events", completeEvents)
                    }
                } break;
                case PAYMENTWORKFLOWSTATE_CONVEYED: {
                    if (1 != createEvents) {
                        BAD_EVENTS(
                            "Wrong number of create events", createEvents)
                    }

                    if (0 == conveyEvents) {
                        BAD_EVENTS(
                            "Wrong number of convey events", conveyEvents)
                    }

                    // TODO: cancel events are allowed only if they are
                    //       all failed

                    // TODO: accept events are allowed only if they are
                    //       all failed

                    if (0 < completeEvents) {
                        BAD_EVENTS(
                            "Wrong number of complete events", completeEvents)
                    }
                } break;
                case PAYMENTWORKFLOWSTATE_CANCELLED: {
                    if (1 != createEvents) {
                        BAD_EVENTS(
                            "Wrong number of create events", createEvents)
                    }

                    // Any number of convey events are allowed

                    if (0 == cancelEvents) {
                        BAD_EVENTS(
                            "Wrong number of cancel events", cancelEvents)
                    }

                    if (0 < acceptEvents) {
                        BAD_EVENTS(
                            "Wrong number of accept events", acceptEvents)
                    }

                    if (0 < completeEvents) {
                        BAD_EVENTS(
                            "Wrong number of complete events", completeEvents)
                    }
                } break;
                case PAYMENTWORKFLOWSTATE_ACCEPTED: {
                    if (1 != createEvents) {
                        BAD_EVENTS(
                            "Wrong number of create events", createEvents)
                    }

                    if (0 == conveyEvents) {
                        BAD_EVENTS(
                            "Wrong number of convey events", conveyEvents)
                    }

                    // TODO: cancel events are allowed only if they are
                    //       all failed

                    if (0 == acceptEvents) {
                        BAD_EVENTS(
                            "Wrong number of accept events", acceptEvents)
                    }

                    // TODO: complete events are allowed only if they are
                    //       all failed
                } break;
                case PAYMENTWORKFLOWSTATE_COMPLETED: {
                    if (1 != createEvents) {
                        BAD_EVENTS(
                            "Wrong number of create events", createEvents)
                    }

                    if (0 == conveyEvents) {
                        BAD_EVENTS(
                            "Wrong number of convey events", conveyEvents)
                    }

                    // TODO: cancel events are allowed only if they are
                    //       all failed

                    if (0 == acceptEvents) {
                        BAD_EVENTS(
                            "Wrong number of accept events", acceptEvents)
                    }

                    if (0 == completeEvents) {
                        BAD_EVENTS(
                            "Wrong number of complete events", completeEvents)
                    }
                } break;
                case PAYMENTWORKFLOWSTATE_EXPIRED: {
                    if (1 != createEvents) {
                        BAD_EVENTS(
                            "Wrong number of create events", createEvents)
                    }

                    // Any number of convey events are allowed

                    // TODO: cancel events are allowed only if they are
                    //       all failed

                    if (0 < acceptEvents) {
                        BAD_EVENTS(
                            "Wrong number of accept events", acceptEvents)
                    }

                    if (0 < completeEvents) {
                        BAD_EVENTS(
                            "Wrong number of complete events", completeEvents)
                    }
                } break;
                default: {
                    FAIL4("Invalid state")
                }
            }
        } break;
        case PAYMENTWORKFLOWTYPE_INCOMINGCHEQUE:
        case PAYMENTWORKFLOWTYPE_INCOMINGINVOICE: {
            switch (input.state()) {
                case PAYMENTWORKFLOWSTATE_CONVEYED: {
                    if (0 != accounts) {
                        BAD_EVENTS("Wrong number of accounts", accounts)
                    }

                    if (0 < createEvents) {
                        BAD_EVENTS(
                            "Wrong number of create events", createEvents)
                    }

                    if (1 != conveyEvents) {
                        BAD_EVENTS(
                            "Wrong number of convey events", conveyEvents)
                    }

                    if (0 < cancelEvents) {
                        BAD_EVENTS(
                            "Wrong number of cancel events", cancelEvents)
                    }

                    // TODO: accept events are allowed only if they are
                    //       all failed

                    if (0 < completeEvents) {
                        BAD_EVENTS(
                            "Wrong number of complete events", completeEvents)
                    }
                } break;
                case PAYMENTWORKFLOWSTATE_COMPLETED: {
                    if (1 != accounts) {
                        BAD_EVENTS("Wrong number of accounts", accounts)
                    }

                    if (0 < createEvents) {
                        BAD_EVENTS(
                            "Wrong number of create events", createEvents)
                    }

                    if (1 != conveyEvents) {
                        BAD_EVENTS(
                            "Wrong number of convey events", conveyEvents)
                    }

                    if (0 < cancelEvents) {
                        BAD_EVENTS(
                            "Wrong number of cancel events", cancelEvents)
                    }

                    if (0 == acceptEvents) {
                        BAD_EVENTS(
                            "Wrong number of accept events", acceptEvents)
                    }

                    if (0 < completeEvents) {
                        BAD_EVENTS(
                            "Wrong number of complete events", completeEvents)
                    }
                } break;
                case PAYMENTWORKFLOWSTATE_EXPIRED: {
                    if (1 < accounts) {
                        BAD_EVENTS("Wrong number of accounts", accounts)
                    }

                    if (0 < createEvents) {
                        BAD_EVENTS(
                            "Wrong number of create events", createEvents)
                    }

                    if (1 != conveyEvents) {
                        BAD_EVENTS(
                            "Wrong number of convey events", conveyEvents)
                    }

                    if (0 < cancelEvents) {
                        BAD_EVENTS(
                            "Wrong number of cancel events", cancelEvents)
                    }

                    // TODO: accept events are allowed only if they are
                    //       all failed

                    if (0 < completeEvents) {
                        BAD_EVENTS(
                            "Wrong number of complete events", completeEvents)
                    }
                } break;
                default: {
                    FAIL4("Invalid state")
                }
            }
        } break;
        default: {
            FAIL4("Invalid type")
        }
    }

    switch (input.type()) {
        case PAYMENTWORKFLOWTYPE_OUTGOINGCHEQUE:
        case PAYMENTWORKFLOWTYPE_INCOMINGCHEQUE:
        case PAYMENTWORKFLOWTYPE_OUTGOINGINVOICE:
        case PAYMENTWORKFLOWTYPE_INCOMINGINVOICE: {
            if (1 != input.unit().size()) {
                FAIL4("Missing unite")
            }
        } break;
        default: {
        }
    }

    return true;
}

bool CheckProto_2(const PaymentWorkflow& input, const bool silent)
{
    UNDEFINED_VERSION2(2)
}

bool CheckProto_3(const PaymentWorkflow& input, const bool silent)
{
    UNDEFINED_VERSION2(3)
}

bool CheckProto_4(const PaymentWorkflow& input, const bool silent)
{
    UNDEFINED_VERSION2(4)
}

bool CheckProto_5(const PaymentWorkflow& input, const bool silent)
{
    UNDEFINED_VERSION2(5)
}

bool CheckProto_6(const PaymentWorkflow& input, const bool silent)
{
    UNDEFINED_VERSION2(6)
}

bool CheckProto_7(const PaymentWorkflow& input, const bool silent)
{
    UNDEFINED_VERSION2(7)
}

bool CheckProto_8(const PaymentWorkflow& input, const bool silent)
{
    UNDEFINED_VERSION2(8)
}

bool CheckProto_9(const PaymentWorkflow& input, const bool silent)
{
    UNDEFINED_VERSION2(9)
}

bool CheckProto_10(const PaymentWorkflow& input, const bool silent)
{
    UNDEFINED_VERSION2(10)
}

bool CheckProto_11(const PaymentWorkflow& input, const bool silent)
{
    UNDEFINED_VERSION2(11)
}

bool CheckProto_12(const PaymentWorkflow& input, const bool silent)
{
    UNDEFINED_VERSION2(12)
}

bool CheckProto_13(const PaymentWorkflow& input, const bool silent)
{
    UNDEFINED_VERSION2(13)
}

bool CheckProto_14(const PaymentWorkflow& input, const bool silent)
{
    UNDEFINED_VERSION2(14)
}

bool CheckProto_15(const PaymentWorkflow& input, const bool silent)
{
    UNDEFINED_VERSION2(15)
}

bool CheckProto_16(const PaymentWorkflow& input, const bool silent)
{
    UNDEFINED_VERSION2(16)
}

bool CheckProto_17(const PaymentWorkflow& input, const bool silent)
{
    UNDEFINED_VERSION2(17)
}

bool CheckProto_18(const PaymentWorkflow& input, const bool silent)
{
    UNDEFINED_VERSION2(18)
}

bool CheckProto_19(const PaymentWorkflow& input, const bool silent)
{
    UNDEFINED_VERSION2(19)
}

bool CheckProto_20(const PaymentWorkflow& input, const bool silent)
{
    UNDEFINED_VERSION2(20)
}
}  // namespace opentxs::proto
