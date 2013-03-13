
P=main
OBJECTS=stack
CFLAGS= -I/home/vagrant/dev/unix/stack/include -g -Wall -O3
LDLIBS= -L/home/vagrant/dev/unix/stack/lib -lstack
LDFLAGS=
CC=c99

$(P): $(OBJECTS)
	$(CC) $(CFLAGS) $@.c -o bin/stack $(LDFLAGS)

clean:
	rm -f lib/*.o
	rm -f bin/*

unity:
	make -i -f MakefileUnity.mk

stack:
	$(CC) $(CFLAGS) -c src/$@.c -o lib/stack.o
