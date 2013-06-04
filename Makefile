
CC=gcc
CFLAGS=$(shell pbs-config --cflags) -I/usr/lib/jvm/java-1.7.0-openjdk.x86_64/include/ -I/usr/lib/jvm/java-1.7.0-openjdk.x86_64/include/linux
LIBS=$(shell pbs-config --libs) -ldrmaa

LIBNAME=lib/libjdrmaa.so

all: clean lib javac

javac: jdrmaa_wrap.c
	javac jdrmaa/*.java
	javac test/*.java

lib: jdrmaa_wrap.c jdrmaa.i
	$(CC) $(CFLAGS) $(LIBS) -fPIC -c jdrmaa_wrap.c
	$(CC) $(LIBS) -shared jdrmaa_wrap.o -o $(LIBNAME)

jdrmaa_wrap.c: jdrmaa.i
	swig -java -package jdrmaa -outdir jdrmaa $(CFLAGS) jdrmaa.i

clean:
	rm -f jdrmaa_wrap.c jdrmaa_wrap.o $(LIBNAME) jdrmaa/* test/*.class
