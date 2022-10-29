CC = gcc
CFLAGS = -pedantic -Wall -Werror 

test: test.c
	$(CC) $(CFLAGS) -o $@ $<

test-gdb: test.c
	$(CC) $(CFLAGS) -ggdb3 -o $@ $<

.PHONY: clean

clean:
	rm -f .*~ *~ .*.swp
