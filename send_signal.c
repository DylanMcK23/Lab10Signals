/*
* Dylan McKinney
* Sends SIGUSR1 plus a random integer to another process using sigqueue.
* The pid of the receiver is given on the command line.
* send_signal.c
*
*
* Compile: gcc -o send_signal send_signal.c
* Run:     ./send_signal <pid of recv_signal>
*/

#include <signal.h>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main(int argc, char* argv[]) {
    union sigval value;
    pid_t pid;

    // Make sure the user gave a pid
    if (argc != 2) {
        printf("Usage: %s <pid>\n", argv[0]);
        return 1;
    }

    // Convert the command line string to a number
    pid = atoi(argv[1]);

    // Seed the random number generator with the time
    srand(time(NULL));

    // Make a random integer to send along with the signal
    value.sival_int = rand();
    printf("Sending random number %d to process %d\n", value.sival_int, pid);

    // Send SIGUSR1 along with the data
    if (sigqueue(pid, SIGUSR1, value) == -1) {
        perror("sigqueue failed");
        return 1;
    }

    return 0;
}