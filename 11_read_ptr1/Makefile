CC = gcc
CFLAGS = -pedantic -Wall -Werror

COMPILE = $(CC) $(CFLAGS)
OUTPUT_OPTION = -o $@

test: test.c
	$(COMPILE) $(OUTPUT_OPTION) $<

.PHONY: clean
clean:
	rm -f *~ .*~
