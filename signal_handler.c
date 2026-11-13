/*
* Dylan McKinney
* Sets a signal handler for SIGINT. The handler prints a message and
* returns (it no longer exits), so the program keeps running.
* signal_handler.c
*/

/**
 * @file signal_handler.c
 * @brief Sets a signal handler for SIGINT, the handler prints a message
 *        and then returns (the program keeps running)
 */

/**
 * Modified by: Dylan McKinney
 *
 * Brief summary of modifications:
 * Removed the call to exit(1) from the signal handler. Now when SIGINT
 * is received the handler only prints a message and returns, so the
 * program continues its loop. Ctrl+C no longer stops the program. It
 * must be stopped with SIGKILL (kill -9 <pid>) or SIGQUIT (Ctrl+\).
 */

#include <signal.h>
#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>

/**
 * @brief Signal handler for SIGINT - prints a message and returns
 */
void handle_signal() {
    printf("Received a signal\n");
    // exit(1) was removed so the program keeps running
}

int main() {

    // Register for the signal
    signal(SIGINT, handle_signal);

    // Wait until a signal is received
    while(1) {
        printf("Sleeping\n");
        sleep(1);
    }

    return 0;
}