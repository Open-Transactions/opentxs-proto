#!/bin/sh

rm -rf opentxs-proto
mkdir -p opentxs-proto
protoc --proto_path=../src/opentxs-proto --cpp_out=opentxs-proto ../src/opentxs-proto/*.proto
