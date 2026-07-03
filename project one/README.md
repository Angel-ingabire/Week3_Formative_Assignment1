# Project One

This folder contains a simple C implementation of a file synchronization simulation and a Linux/ELF-based inspection workflow.

## Files

- main.c: source code for the simulation
- analysis_report.md: forensic-style report
- linux/build_and_inspect.sh: builds the program and generates ELF inspection outputs
- linux/data_sync: compiled ELF binary
- linux/file_info.txt, linux/readelf_headers.txt, linux/readelf_symbols.txt, linux/objdump_sections.txt, linux/nm_symbols.txt: inspection outputs

## Linux workflow

Run from WSL:

```bash
cd /mnt/c/Users/HP/Desktop/Week3_Formative_Assignment1/project\ one/linux
bash build_and_inspect.sh
```
