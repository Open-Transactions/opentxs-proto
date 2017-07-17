#!/usr/bin/env sh

clang_format_bin=clang-format

files="$@"

for file in $files; do
    cp "${file}" "${file}.clangformat"
    "${clang_format_bin}" -i "${file}.clangformat"
    git diff --no-index "${file}" "${file}.clangformat" | cat
    rm "${file}.clangformat"
done
