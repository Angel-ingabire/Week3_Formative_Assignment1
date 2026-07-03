# Project Four: Signal-Driven Monitor Service

This project implements a simple C service that runs continuously and responds to Unix signals.

## Files

- `monitor_service.c` - the signal-handling service

## Build

```bash
gcc -Wall -Wextra -O2 -o monitor_service monitor_service.c
```

## Run

```bash
./monitor_service
```

## Test signals

```bash
kill -SIGUSR1 <pid>
kill -SIGTERM <pid>
kill -SIGINT <pid>
```

These commands are intended for Linux/WSL environments where Unix signals are available.

## Expected behavior

- `SIGINT`: graceful shutdown with a safe shutdown message
- `SIGUSR1`: prints the administrator status message
- `SIGTERM`: prints the emergency shutdown message and exits
