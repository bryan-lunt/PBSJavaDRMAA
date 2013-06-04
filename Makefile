
CC=gcc
CFLAGS=$(shell pbs-config --cflags) -I/usr/lib/jvm/java-1.7.0-openjdk.x86_64/include/ -I/usr/lib/jvm/java-1.7.0-openjdk.x86_64/include/linux

LIBNAME=libdrmaa.so

compile: drmaa_wrap.c drmaa.i
	$(CC) $(CFLAGS) -fPIC -c drmaa_wrap.c
	$(CC) -shared drmaa_wrap.o -o $(LIBNAME)

drmaa_wrap.c: drmaa.i
	swig -java $(CFLAGS) -outdir swigjava drmaa.i

clean:
	rm drmaa_wrap.c drmaa_wrap.o *.so swigjava/*
