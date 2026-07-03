#!/usr/bin/env bash
set -euo pipefail

cd "$(dirname "$0")"
mkdir -p .

gcc -O0 -g -o data_sync ../main.c

file data_sync > file_info.txt
readelf -h data_sync > readelf_headers.txt
readelf -s data_sync | grep -E ' main$| copy_file$| sync_directory$| usage$' > readelf_symbols.txt || true
objdump -h data_sync > objdump_sections.txt
nm -C data_sync > nm_symbols.txt

echo "ELF build and inspection completed."
