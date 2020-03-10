## Protobuf definition library for Open-Transactions

[![License: MPL 2.0](https://img.shields.io/badge/License-MPL%202.0-brightgreen.svg)](https://opensource.org/licenses/MPL-2.0)

[![Build](https://github.com/Open-Transactions/opentxs-proto/workflows/Release/badge.svg)](https://github.com/Open-Transactions/opentxs-proto/actions)

This library provides the canonical protobuf definitions for opentxs messages, as well as syntax validation functions.

### Official Wiki

http://opentransactions.org/

### Contributing

Use clang-format and cmake-format.

#### CppCheck and clang-format Git hooks

For convenience please enable the git hooks which will trigger cppcheck and
clang-format each time you push or commit. To do so type in the repo directory:

    cd .git/hooks
    ln -s ../../cmake/scripts/git_hooks/pre-push
    ln -s ../../cmake/scripts/git_hooks/pre-commit

To check your code without pushing the following command can be used:

    git push -n

### Build Instructions

    mkdir build
    cd build
    cmake -GNinja -DBUILD_SHARED_LIBS=ON ..
    ninja
    ninja install
