
P=tictactoe
OBJECTS=board
# CFLAGS= -g -Wall -O3
CFLAGS= -I/home/vagrant/dev/unix/tictactoe/include -g -Wall -O3
# this is for linking in shared object .so files which have the naming syntax
# eg.  "libmylib" and then linked with "-lmylib":
# LDLIBS= -L/home/vagrant/dev/unix/stack/lib -lstack
LDLIBS=
LDFLAGS=
CC=c99

$(P): $(OBJECTS)
	$(CC) $(CFLAGS) src/$@.c lib/*.o -o bin/$@ $(LDLIBS)

board:
	$(CC) $(CFLAGS) -c src/$@.c -o lib/board.o

clean:
	rm -f lib/*.o
	rm -f bin/*

test: test_tictactoe

test_tictactoe: board
	$(CC) $(CFLAGS) test/$@.c lib/*.o -o test/$@ $(LDFLAGS)

