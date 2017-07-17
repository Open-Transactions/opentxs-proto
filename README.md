## Open-Transactions Canonical Protbuf Definition Library

This library provides the canonical protobuf definitions for opentxs messages, as well as syntax validation functions.

These definitions are under heavy development, and as such no guarantees of API stability should be inferred prior to a 1.0 release.

### Official Wiki

http://opentransactions.org/

### Installation Instructions

#### Dependencies

* C++11 compiler
* Google Protobuf version 2.6 or later

#### Building

Open-Transactions uses the CMake build system. The basic steps are:

    mkdir build
    cd build
    cmake ..
    make
    make install

### Contributing

#### CppCheck and clang-format Git hooks

For convenience please enable the git hooks which will trigger cppcheck and
clang-format each time you push or commit. To do so type in the repo directory:

    cd .git/hooks
    ln -s ../../scripts/git_hooks/pre-push
    ln -s ../../scripts/git_hooks/pre-commit

To check your code without pushing the following command can be used:

    git push -n
