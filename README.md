## Lab Week 10
Dylan McKinney - CPE-2600 Lab 10 Signals

Build everything with `make`, remove the executables with `make clean`.

### Programs
- **signal_handler.c** - registers a SIGINT handler with `signal()`. The handler prints a message and returns (no exit), so Ctrl+C no longer stops it. Stop it with Ctrl+\ (SIGQUIT) or `kill -9 <pid>` (SIGKILL).
- **signal_alarm.c** - calls `alarm(5)` and prints a message in the SIGALRM handler.
- **signal_segfault.c** - installs a SIGSEGV handler that prints a message and returns. The faulting NULL dereference is re-run forever, so the message repeats until the program is killed.
- **signal_sigaction.c** - uses `sigaction` with `SA_SIGINFO` to handle SIGUSR1 and print the sender's pid. Send the signal with `kill -USR1 <pid>`.
- **recv_signal.c** - uses `sigaction` with `SA_SIGINFO` to handle SIGUSR1 and print the integer (`sival_int`) sent with it. Prints its own pid on start.
- **send_signal.c** - sends SIGUSR1 and a random integer to a pid using `sigqueue`.

### Running Part 4
Terminal 1: `./recv_signal`
Terminal 2: `./send_signal <pid>`