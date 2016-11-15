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

#ifndef OPENTXS_PROTO_VERIFYPEER_HPP
#define OPENTXS_PROTO_VERIFYPEER_HPP

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
#include "opentxs-proto/PeerObject.pb.h"
// IWYU pragma: end_exports
#ifdef _WIN32
#pragma warning(pop)
#else
#pragma GCC diagnostic pop
#endif

// IWYU pragma: begin_exports
#include "opentxs-proto/Verify.hpp"
#include "opentxs-proto/verify/Bailment.hpp"
#include "opentxs-proto/verify/BailmentReply.hpp"
#include "opentxs-proto/verify/ConnectionInfo.hpp"
#include "opentxs-proto/verify/ConnectionInfoReply.hpp"
#include "opentxs-proto/verify/NoticeAcknowledgement.hpp"
#include "opentxs-proto/verify/OutBailment.hpp"
#include "opentxs-proto/verify/OutBailmentReply.hpp"
#include "opentxs-proto/verify/PeerObject.hpp"
#include "opentxs-proto/verify/PeerReply.hpp"
#include "opentxs-proto/verify/PeerRequest.hpp"
#include "opentxs-proto/verify/PendingBailment.hpp"
#include "opentxs-proto/verify/Signature.hpp"
// IWYU pragma: end_exports

namespace opentxs { namespace proto
{
    static const VersionMap PeerObjectAllowedReply =
        {
            { 1, {1, 1}},
        };
    static const VersionMap PeerObjectAllowedRequest =
        {
            { 1, {1, 1}},
        };
    static const VersionMap PeerObjectAllowedNym =
        {
            { 1, {1, 1}},
        };
    static const VersionMap PeerReplyAllowedSignature =
        {
            { 1, {1, 1}},
        };
    static const VersionMap PeerReplyAllowedBailment =
        {
            { 1, {1, 1}},
        };
    static const VersionMap PeerReplyAllowedNotice =
        {
            { 1, {1, 1}},
        };
    static const VersionMap PeerReplyAllowedOutBailment =
        {
            { 1, {1, 1}},
        };
    static const VersionMap PeerReplyAllowedConnectionInfo =
        {
            { 1, {1, 1}},
        };
    static const VersionMap PeerRequestAllowedSignature =
        {
            { 1, {1, 1}},
        };
    static const VersionMap PeerRequestAllowedBailment =
        {
            { 1, {1, 1}},
        };
    static const VersionMap PeerRequestAllowedOutBailment =
        {
            { 1, {1, 1}},
        };
    static const VersionMap PeerRequestAllowedPendingBailment =
        {
            { 1, {1, 1}},
        };
    static const VersionMap PeerRequestAllowedConnectionInfo =
        {
            { 1, {1, 1}},
        };
} // namespace proto
} // namespace opentxs
#endif // OPENTXS_PROTO_VERIFYPEER_HPP
