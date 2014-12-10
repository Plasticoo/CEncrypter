CC = gcc
OUT_EXE = cencrypt 
LIBS = -lcrypto -lssl
FLAGS = -Wall

build: main.o sconcat.o sha.o sha1.o sha224.o sha256.o sha384.o sha512.o md4.o md5.o whirlpool.o
	$(CC) $(FLAGS) -o $(OUT_EXE) main.o sconcat.o sha.o sha1.o sha224.o sha256.o sha384.o sha512.o md4.o md5.o whirlpool.o $(LIBS)

main.o: main.c
	$(CC) $(FLAGS) -c main.c -o main.o

sconcat.o: sconcat.c
	$(CC) $(FLAGS) -c sconcat.c -o sconcat.o

sha.o: hashfiles/sha.c
	$(CC) $(FLAGS) -c hashfiles/sha.c -o sha.o

sha1.o: hashfiles/sha1.c
	$(CC) $(FLAGS) -c hashfiles/sha1.c -o sha1.o

sha224.o: hashfiles/sha224.c
	$(CC) $(FLAGS) -c hashfiles/sha224.c -o sha224.o

sha256.o: hashfiles/sha256.c
	$(CC) $(FLAGS) -c hashfiles/sha256.c -o sha256.o

sha384.o: hashfiles/sha384.c
	$(CC) $(FLAGS) -c hashfiles/sha384.c -o sha384.o

sha512.o: hashfiles/sha512.c
	$(CC) $(FLAGS) -c hashfiles/sha512.c -o sha512.o

md4.o: hashfiles/md4.c
	$(CC) $(FLAGS) -c hashfiles/md4.c -o md4.o

md5.o: hashfiles/md5.c
	$(CC) $(FLAGS) -c hashfiles/md5.c -o md5.o

whirlpool.o: hashfiles/whirlpool.c
	$(CC) $(FLAGS) -c hashfiles/whirlpool.c -o whirlpool.o

clean:
	rm -rf *.o
