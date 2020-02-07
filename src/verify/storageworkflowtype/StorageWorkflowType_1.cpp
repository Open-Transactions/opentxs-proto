// Copyright (c) 2020 The Open-Transactions developers
// This Source Code Form is subject to the terms of the Mozilla Public
// License, v. 2.0. If a copy of the MPL was not distributed with this
// file, You can obtain one at http://mozilla.org/MPL/2.0/.

#include "opentxs-proto/Types.hpp"
#include "verify/Check.hpp"

#define PROTO_NAME "storage workflow type index"

namespace opentxs::proto
{
bool CheckProto_1(const StorageWorkflowType& input, const bool silent)
{
    CHECK_IDENTIFIER(workflow)

    switch (input.type()) {
        case PAYMENTWORKFLOWTYPE_OUTGOINGCHEQUE: {
            switch (input.state()) {
                case PAYMENTWORKFLOWSTATE_UNSENT:
                case PAYMENTWORKFLOWSTATE_CONVEYED:
                case PAYMENTWORKFLOWSTATE_CANCELLED:
                case PAYMENTWORKFLOWSTATE_ACCEPTED:
                case PAYMENTWORKFLOWSTATE_COMPLETED:
                case PAYMENTWORKFLOWSTATE_EXPIRED: {
                } break;
                case PAYMENTWORKFLOWSTATE_ABORTED:
                case PAYMENTWORKFLOWSTATE_ACKNOWLEDGED:
                case PAYMENTWORKFLOWSTATE_REJECTED:
                case PAYMENTWORKFLOWSTATE_INITIATED:
                case PAYMENTWORKFLOWSTATE_ERROR:
                default: {
                    FAIL_2(
                        "invalid state",
                        static_cast<std::uint32_t>(input.state()))
                }
            }
        } break;
        case PAYMENTWORKFLOWTYPE_INCOMINGCHEQUE: {
            switch (input.state()) {
                case PAYMENTWORKFLOWSTATE_CONVEYED:
                case PAYMENTWORKFLOWSTATE_COMPLETED:
                case PAYMENTWORKFLOWSTATE_EXPIRED: {
                } break;
                case PAYMENTWORKFLOWSTATE_INITIATED:
                case PAYMENTWORKFLOWSTATE_UNSENT:
                case PAYMENTWORKFLOWSTATE_CANCELLED:
                case PAYMENTWORKFLOWSTATE_ACCEPTED:
                case PAYMENTWORKFLOWSTATE_ABORTED:
                case PAYMENTWORKFLOWSTATE_ACKNOWLEDGED:
                case PAYMENTWORKFLOWSTATE_REJECTED:
                case PAYMENTWORKFLOWSTATE_ERROR:
                default: {
                    FAIL_2(
                        "invalid state",
                        static_cast<std::uint32_t>(input.state()))
                }
            }
        } break;
        case PAYMENTWORKFLOWTYPE_OUTGOINGINVOICE: {
            switch (input.state()) {
                case PAYMENTWORKFLOWSTATE_UNSENT:
                case PAYMENTWORKFLOWSTATE_CONVEYED:
                case PAYMENTWORKFLOWSTATE_CANCELLED:
                case PAYMENTWORKFLOWSTATE_ACCEPTED:
                case PAYMENTWORKFLOWSTATE_COMPLETED:
                case PAYMENTWORKFLOWSTATE_EXPIRED: {
                } break;
                case PAYMENTWORKFLOWSTATE_INITIATED:
                case PAYMENTWORKFLOWSTATE_ABORTED:
                case PAYMENTWORKFLOWSTATE_ACKNOWLEDGED:
                case PAYMENTWORKFLOWSTATE_REJECTED:
                case PAYMENTWORKFLOWSTATE_ERROR:
                default: {
                    FAIL_2(
                        "invalid state",
                        static_cast<std::uint32_t>(input.state()))
                }
            }
        } break;
        case PAYMENTWORKFLOWTYPE_INCOMINGINVOICE: {
            switch (input.state()) {
                case PAYMENTWORKFLOWSTATE_CONVEYED:
                case PAYMENTWORKFLOWSTATE_COMPLETED:
                case PAYMENTWORKFLOWSTATE_EXPIRED: {
                } break;
                case PAYMENTWORKFLOWSTATE_INITIATED:
                case PAYMENTWORKFLOWSTATE_UNSENT:
                case PAYMENTWORKFLOWSTATE_CANCELLED:
                case PAYMENTWORKFLOWSTATE_ACCEPTED:
                case PAYMENTWORKFLOWSTATE_ABORTED:
                case PAYMENTWORKFLOWSTATE_ACKNOWLEDGED:
                case PAYMENTWORKFLOWSTATE_REJECTED:
                case PAYMENTWORKFLOWSTATE_ERROR:
                default: {
                    FAIL_2(
                        "invalid state",
                        static_cast<std::uint32_t>(input.state()))
                }
            }
        } break;
        case PAYMENTWORKFLOWTYPE_OUTGOINGTRANSFER:
        case PAYMENTWORKFLOWTYPE_INCOMINGTRANSFER:
        case PAYMENTWORKFLOWTYPE_INTERNALTRANSFER:
        case PAYMENTWORKFLOWTYPE_OUTGOINGCASH:
        case PAYMENTWORKFLOWTYPE_INCOMINGCASH:
        case PAYMENTWORKFLOWTYPE_ERROR:
        default: {
            FAIL_2("invalid type", static_cast<std::uint32_t>(input.type()))
        }
    }

    return true;
}
}  // namespace opentxs::proto
