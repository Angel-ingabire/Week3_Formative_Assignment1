/*
 * Portable monitor service: registers signal handlers where available.
 * Note: SIGUSR1 may not exist on non-POSIX platforms (Windows). The
 * program will still compile and run; full signal testing should be
 * performed on Linux/WSL for SIGUSR1/SIGTERM behavior.
 */

#include <signal.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

static volatile sig_atomic_t keep_running = 1;

static void handle_sigint(int signo)
{
    (void)signo;
    printf("\nMonitor Service shutting down safely.\n");
    fflush(stdout);
    keep_running = 0;
}

#ifdef SIGUSR1
static void handle_sigusr1(int signo)
{
    (void)signo;
    printf("\nSystem status requested by administrator.\n");
    fflush(stdout);
}
#endif

static void handle_sigterm(int signo)
{
    (void)signo;
    printf("\nEmergency shutdown signal received.\n");
    fflush(stdout);
    keep_running = 0;
}

int main(void)
{
    /* SIGINT */
    if (signal(SIGINT, handle_sigint) == SIG_ERR)
    {
        perror("signal(SIGINT)");
        return 1;
    }

#ifdef SIGUSR1
    if (signal(SIGUSR1, handle_sigusr1) == SIG_ERR)
    {
        perror("signal(SIGUSR1)");
        return 1;
    }
#else
    /* SIGUSR1 not available: warn at startup */
    fprintf(stderr, "Note: SIGUSR1 not available on this platform; status signal disabled.\n");
#endif

    /* SIGTERM */
    if (signal(SIGTERM, handle_sigterm) == SIG_ERR)
    {
        perror("signal(SIGTERM)");
        return 1;
    }

    printf("Monitor Service started. Send signals to test it.\n");
    fflush(stdout);

    while (keep_running)
    {
        printf("[Monitor Service] System running normally...\n");
        fflush(stdout);
        sleep(5);
    }

    return 0;
}
