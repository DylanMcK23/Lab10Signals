/*
* Dylan McKinney
* Registers a SIGUSR1 handler with sigaction and prints the integer
* value (sival_int) sent along with the signal by send_signal.
* recv_signal.c
*
* Compile: gcc -o recv_signal recv_signal.c
* Run:     ./recv_signal      (it prints its pid, give that to send_signal)
*/

#include <signal.h>
#include <unistd.h>
#include <stdio.h>
#include <string.h>

/**
 * @brief Handler for SIGUSR1, prints the integer sent with the signal
 * @param sig the signal number
 * @param info structure with details about the signal (si_value holds data)
 * @param context unused
 */
void handle_sigusr1(int sig, siginfo_t *info, void *context) {
    printf("Received SIGUSR1 with value %d\n", info->si_value.sival_int);
}

int main() {
    struct sigaction action;

    // Clear the structure so no fields have garbage values
    memset(&action, 0, sizeof(action));

    // Use the three argument handler (needs SA_SIGINFO)
    action.sa_sigaction = handle_sigusr1;
    action.sa_flags = SA_SIGINFO;

    // Register the handler for SIGUSR1
    sigaction(SIGUSR1, &action, NULL);

    printf("My pid is %d, waiting for SIGUSR1...\n", getpid());

    // Wait forever
    while(1) {
        pause();
    }

    return 0;
}