# Forensic Analysis Report: data_sync

## Overview

The binary named `data_sync` is a small ELF executable that appears to implement a file synchronization workflow. It was compiled from a C source file and analyzed without executing it directly. The investigation focused on the ELF header, symbol table, section layout, and imported library functions.

## Key Findings

- The file is an ELF 64-bit LSB executable for x86-64, confirming it is a Linux-native binary.
- The entry point is at address `0x1260`, which is typical for a standard C program startup sequence.
- The symbol table shows a visible `main` function and internal helper functions named `copy_file`, `sync_directory`, and `usage`.
- The program imports standard C library functions including `fopen`, `fread`, `fwrite`, `opendir`, `readdir`, `stat`, `snprintf`, `fprintf`, `printf`, `perror`, and `strcmp`.
- The ELF sections include `.text`, `.rodata`, `.data`, `.bss`, `.dynsym`, `.dynstr`, `.plt`, and `.got`, indicating the binary uses dynamic linking and contains both code and data sections.

## Interpretation

Based on the symbol names and imported functions, the program likely copies files from a source directory to a target directory. The helper function names strongly suggest directory iteration and file copying behavior. The presence of `opendir`, `readdir`, and `stat` points to directory traversal and file-type checks, while `fopen`, `fread`, and `fwrite` indicate that file contents are copied from source to destination.

## Conclusion

This binary is consistent with a simple file synchronization or backup utility. The analysis suggests it scans a source folder, identifies files, and copies them into a target folder, matching the C source design.
