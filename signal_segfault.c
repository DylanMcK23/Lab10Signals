/*
* Dylan McKinney
* Dereferences a NULL pointer to cause SIGSEGV. A handler is installed
* that only prints a message and returns, which causes an endless loop.
* signal_segfault.c
*/

/**
 * @file signal_segfault.c
 * @brief Program that dereferences a null pointer causing a segmentation fault
 */

/**
 * Modified by: Dylan McKinney
 *
 * Brief summary of modifications:
 * Added a signal handler for SIGSEGV that prints a message and returns.
 * Because the handler returns, execution resumes at the same instruction
 * that faulted (the NULL dereference), which faults again, so the handler
 * runs over and over. The program never ends on its own; stop it with
 * Ctrl+C (SIGINT) or kill -9 <pid>.
 */

#include <stdio.h>
#include <signal.h>

/**
 * @brief Signal handler for SIGSEGV - prints a message and returns
 */
void handle_segfault() {
    printf("Received a segmentation fault (SIGSEGV)\n");
}

int main (int argc, char* argv[]) {
    // Register the handler for SIGSEGV
    signal(SIGSEGV, handle_segfault);

    // Declare a null pointer
    int* i = NULL;

    // Dereference the null pointer
    printf("The value of i is: %d\n", *i);

    // Return to exit the program
    return 0;
}