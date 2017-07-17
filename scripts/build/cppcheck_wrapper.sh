#!/usr/bin/env bash

enabled="--enable=warning --enable=information --enable=performance \
         --enable=portability --enable=missingInclude --enable=style"
includes="-I./include"
# Exit code '1' is returned if arguments are not valid or if no input
# files are provided. Compare 'cppcheck --help'.
args="-f -q --error-exitcode=2"
cppcheck $args $define $includes $enabled "$@"
exit $?
