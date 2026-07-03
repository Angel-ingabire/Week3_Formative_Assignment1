# Project Two: System Call Monitoring Tool

This project creates a small C program that performs file creation, log writing, and file reading. It is then traced with `strace` to identify relevant system calls.

## Files

- backup_monitor.c: source code for the test program
- strace_output.txt: captured `strace` output
- syscall_summary.md: system call summary table
- syscall_hits.txt: extracted syscall lines from the trace

## How to run

From WSL, run:

```bash
cd /mnt/c/Users/HP/Desktop/Week3_Formative_Assignment1/project\ two
gcc -O0 -g -o backup_monitor backup_monitor.c
strace -o strace_output.txt ./backup_monitor
```

The program creates `backup_data.txt`, writes to `backup.log`, and reads the data back so the trace shows file-related system calls clearly.
