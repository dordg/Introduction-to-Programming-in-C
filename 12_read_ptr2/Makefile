CC = gcc
CFLAGS = -pedantic -Wall -Werror -fsanitize=address

test: test.c
	$(CC) $(CFLAGS) -o $@ $<

.PHONY: clean

clean:
	rm -f .*~ *~ .*.swp
