## Open-Transactions Canonical Protbuf Definition Library

This library provides the canonical protobuf definitions for opentxs messages, as well as syntax validation functions.

These definitions are under heavy development, and as such no guarantees of API stability should be inferred prior to a 1.0 release.

### Official Wiki

http://opentransactions.org/

### Installation Instructions

#### Dependencies

* C++11 compiler
* Google Protobuf version 2 or later

#### Building

Open-Transactions uses the CMake build system. The basic steps are:

    mkdir build
    cd build
    cmake ..
    make
    make install
