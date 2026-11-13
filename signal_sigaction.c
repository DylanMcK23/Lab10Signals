/*
* Dylan McKinney
* Uses sigaction with SA_SIGINFO to register a SIGUSR1 handler that
* prints the process id of the sender.
* signal_sigaction.c
*
* Command to send SIGUSR1 to this program (from another terminal):
*     kill -USR1 <pid>
* (kill -10 <pid> also works on Linux). The pid is printed when the
* program starts, or it can be found with: pgrep signal_sigaction
*/

#include <signal.h>
#include <unistd.h>
#include <stdio.h>
#include <string.h>

/**
 * @brief Handler for SIGUSR1, prints the pid of the process that sent it
 * @param sig the signal number
 * @param info structure with details about the signal (si_pid is sender)
 * @param context unused
 */
void handle_sigusr1(int sig, siginfo_t *info, void *context) {
    printf("Received SIGUSR1 from process %d\n", info->si_pid);
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