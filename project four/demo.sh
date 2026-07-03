#!/bin/bash
set -euo pipefail
cd "$(dirname "$0")"

gcc -Wall -Wextra -O2 -o monitor_service monitor_service.c
nohup ./monitor_service > monitor_log.txt 2>&1 &
pid=$!

echo "Started monitor_service with PID $pid" > monitor_demo.txt
sleep 1
kill -SIGUSR1 "$pid" && echo "Sent SIGUSR1 to $pid" >> monitor_demo.txt || echo "Failed to send SIGUSR1" >> monitor_demo.txt
sleep 1
kill -SIGTERM "$pid" && echo "Sent SIGTERM to $pid" >> monitor_demo.txt || echo "Failed to send SIGTERM" >> monitor_demo.txt
sleep 1

echo "--- monitor_log.txt ---" >> monitor_demo.txt
cat monitor_log.txt >> monitor_demo.txt

echo "Demo complete" >> monitor_demo.txt
