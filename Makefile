CPP=g++
CC=gcc

CFLAGS=$(shell pbs-config --cflags) -I/usr/lib/jvm/java-1.7.0-openjdk.x86_64/include/ -I/usr/lib/jvm/java-1.7.0-openjdk.x86_64/include/linux
LIBS=$(shell pbs-config --libs) -ldrmaa -lstdc++

LIBNAME=lib/libjdrmaa.so

all: clean lib javac

javac: jdrmaa_wrap.cxx
	javac jdrmaa/*.java
	javac test/*.java

lib: jdrmaa_wrap.cxx jdrmaa.i
	$(CPP) $(CFLAGS) $(LIBS) -fPIC -c jdrmaa_wrap.cxx
	$(CC) $(LIBS) -shared jdrmaa_wrap.o -o $(LIBNAME)

jdrmaa_wrap.cxx: jdrmaa.i
	swig -c++ -java -package jdrmaa -outdir jdrmaa $(CFLAGS) jdrmaa.i

clean:
	rm -f jdrmaa_wrap.* $(LIBNAME) jdrmaa/* test/*.class
