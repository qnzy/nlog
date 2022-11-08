CC = gcc
CFLAGS = -Og -Wall -Werror -Wextra -pedantic
test: CFLAGS += -fsanitize=address
SRC = test.c
HEADER = nlog.h

bin = testexe

test: $(bin)
	./$(bin)

std: clean
	$(CC) $(CFLAGS) -std=c89 $(SRC) -o $(bin)
	$(CC) $(CFLAGS) -std=c99 $(SRC) -o $(bin)
	$(CC) $(CFLAGS) -std=c11 $(SRC) -o $(bin)

$(bin): $(SRC) $(HEADER)
	$(CC) $(CFLAGS) $(SRC) -o $(bin)

clean:
	rm -f *.o
	rm -f $(bin)

lint:
	clang-tidy -checks="*,-llvm-header-guard" -header-filter=".*" *.c

.PHONY: clean all lint std
