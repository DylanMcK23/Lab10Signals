/*
* Dylan McKinney
* Schedules an alarm for 5 seconds and prints a message when SIGALRM
* is received by the handler.
* signal_alarm.c
*/

#include <signal.h>
#include <unistd.h>
#include <stdio.h>

/**
 * @brief Signal handler for SIGALRM - prints that the alarm went off
 */
void handle_alarm() {
    printf("Received SIGALRM - the 5 second alarm went off\n");
}

int main() {

    // Register the handler for SIGALRM
    signal(SIGALRM, handle_alarm);

    // Ask the operating system to send SIGALRM in 5 seconds
    alarm(5);
    printf("Alarm scheduled for 5 seconds, waiting...\n");

    // Sleep until a signal arrives (the handler runs, then pause returns)
    pause();

    printf("Done waiting, exiting\n");
    return 0;
}