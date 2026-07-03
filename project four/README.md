# Project Four: Signal-Driven Monitor Service

This project implements a simple C service that runs continuously and responds to Unix signals. It demonstrates how a background-style program can stay alive, print periodic status output, and react to administrative commands sent by the operating system or another process.

## Files

- `monitor_service.c` - the signal-handling service
- `demo.sh` - helper script that compiles the program, runs it, and sends `SIGUSR1` and `SIGTERM`
- `monitor_demo.txt` - captured terminal demonstration log
- `monitor_log.txt` - runtime output from the service

## Build

```bash
gcc -Wall -Wextra -O2 -o monitor_service monitor_service.c
```

## Run manually

Start the service in one terminal:

```bash
./monitor_service
```

Then, in another terminal, send signals to the running process ID:

```bash
kill -SIGUSR1 <pid>
kill -SIGTERM <pid>
kill -SIGINT <pid>
```

## Signal handling behavior

The program registers handlers using `signal()` for the requested signals:

- `SIGINT` prints `Monitor Service shutting down safely.` and exits cleanly.
- `SIGUSR1` prints `System status requested by administrator.`
- `SIGTERM` prints `Emergency shutdown signal received.` and exits.

The main loop also prints a periodic heartbeat message every five seconds:

```text
[Monitor Service] System running normally...
```

## Demonstration

A helper script is included for Linux/WSL:

```bash
chmod +x demo.sh
./demo.sh
```

The script compiles the program, starts it, sends `SIGUSR1` and `SIGTERM`, and stores the captured output in `monitor_demo.txt` and `monitor_log.txt`.

## Observed output

Example output from the recorded demonstration:

```text
System status requested by administrator.
Emergency shutdown signal received.
```

## Expected behavior

- `SIGINT`: graceful shutdown with a safe shutdown message
- `SIGUSR1`: prints the administrator status message
- `SIGTERM`: prints the emergency shutdown message and exits
