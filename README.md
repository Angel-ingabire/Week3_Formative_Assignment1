# Week 3 Formative Assignment 1

This repository contains four completed projects covering ELF binary analysis, system call tracing, Python/C performance extension development, and Unix signal handling.

## Project 1: Investigating a Suspicious Binary

Folder: project one

This project investigates a simple C program that simulates file synchronization.

### Included files

- project one/main.c: source code for the simulated synchronization tool
- project one/analysis_report.md: forensic-style analysis of the ELF binary
- project one/linux/build_and_inspect.sh: build and inspection script
- project one/linux/: inspection outputs such as file info, ELF headers, symbol tables, and section dumps

### How to run

From WSL:

```bash
cd project\ one/linux
bash build_and_inspect.sh
```

## Project 2: System Call Monitoring Tool

Folder: project two

This project implements a small backup-style C program and traces it with strace.

### Included files

- project two/backup_monitor.c: source code that creates a file, writes a log, and reads the file
- project two/strace_output.txt: captured strace output
- project two/syscall_hits.txt: extracted relevant syscall lines
- project two/syscall_summary.md: explanation of file-related and process-related syscalls

### How to run

From WSL:

```bash
cd project\ two
gcc -O0 -g -o backup_monitor backup_monitor.c
strace -o strace_output.txt ./backup_monitor
```

## Project 3: Building a Python Performance Extension

Folder: project three

This project compares a pure Python computation with a CPython C extension.

### Included files

- project three/benchmark.py: benchmark runner
- project three/pure_python_stats.py: pure Python implementation
- project three/fast_stats.c: C extension implementation
- project three/setup.py: build script for the extension
- project three/benchmark_results.txt: benchmark output
- project three/performance_explanation.md: explanation of the performance difference

### How to run

```bash
cd project three
python setup.py build_ext --inplace
python benchmark.py
```

## Project 4: Signal-Driven Monitor Service

Folder: project four

This project implements a simple background-style service that responds to Unix signals.

### Included files

- project four/monitor_service.c: the signal-handling service
- project four/demo.sh: helper script to compile and demonstrate signal handling
- project four/monitor_demo.txt: recorded demo output
- project four/monitor_log.txt: runtime log from the service
- project four/README.md: project-specific documentation

### How to run

From Linux/WSL:

```bash
cd project\ four
gcc -Wall -Wextra -O2 -o monitor_service monitor_service.c
./monitor_service
```

To test the signals from another terminal:

```bash
kill -SIGUSR1 <pid>
kill -SIGTERM <pid>
kill -SIGINT <pid>
```
