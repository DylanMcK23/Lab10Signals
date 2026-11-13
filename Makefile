CC = gcc
CFLAGS = -Wall -g

PROGRAMS = signal_handler signal_alarm signal_segfault signal_sigaction recv_signal send_signal

all: $(PROGRAMS)

# Each program is built from the .c file with the same name
%: %.c
	$(CC) $(CFLAGS) -o $@ $<

clean:
	rm -f $(PROGRAMS)