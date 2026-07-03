# System Call Summary

## File-related system calls

| System call | Purpose in this program                                                    |
| ----------- | -------------------------------------------------------------------------- |
| `openat`    | Opens the backup data file and log file for creation, writing, or reading. |
| `write`     | Writes the backup message and log content to files.                        |
| `read`      | Reads the contents of the backup data file back into memory.               |
| `close`     | Closes file descriptors after operations complete.                         |
| `fstat`     | Retrieves file metadata such as size and permissions.                      |

## Process-related system calls

| System call  | Purpose in this program                               |
| ------------ | ----------------------------------------------------- |
| `execve`     | Starts the program execution.                         |
| `brk`        | Adjusts the program break for heap memory allocation. |
| `mmap`       | Maps memory needed by the runtime and program.        |
| `munmap`     | Unmaps memory mappings after use.                     |
| `exit_group` | Terminates the process cleanly.                       |

## Notes

The trace shows both loader/runtime activity and the program's own file operations. The file-related calls directly match the program's creation, logging, and read-back behavior.
