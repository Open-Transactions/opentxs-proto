## Open-Transactions Canonical Protbuf Definition Library

[![License](http://img.shields.io/:License-MPLv2-yellow.svg)](LICENSE)

This library provides the canonical protobuf definitions for opentxs messages, as well as syntax validation functions.

These definitions are under heavy development, and as such no guarantees of API stability should be inferred prior to a 1.0 release.

### Official Wiki

http://opentransactions.org/

### Contributing

All development goes in develop branch - please don't submit pull requests to
master.

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
