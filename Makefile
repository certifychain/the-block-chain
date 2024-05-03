CC=gcc
CFLAGS=-Wall -Werror -pedantic -std=c99 -I.
LDFLAGS=-lcrypto

all: main

main: main.o blockchain/block.o p2p/p2p.o crypto/ecdsa.o
    $(CC) $(LDFLAGS) -o main main.o blockchain/block.o p2p/p2p.o crypto/ecdsa.o

main.o: main.c certifychain.h
    $(CC) $(CFLAGS) -c main.c

blockchain/block.o: blockchain/block.c blockchain/block.h certifychain.h
    $(CC) $(CFLAGS) -c blockchain/block.c

p2p/p2p.o: p2p/p2p.c p2p/p2p.h certifychain.h
    $(CC) $(CFLAGS) -c p2p/p2p.c

crypto/ecdsa.o: crypto/ecdsa.c crypto/ecdsa.h certifychain.h
    $(CC) $(CFLAGS) -c crypto/ecdsa.c

clean:
    rm -f main main.o blockchain/block.o p2p/p2p.o crypto/ecdsa.o