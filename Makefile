CPP=g++
CC=gcc

CFLAGS=-g
#INCLUDES=$(shell pbs-config --cflags) -I/usr/lib/jvm/default-jvm/include/ -I/usr/lib/jvm/default-jvm/include/linux -I${HOME}/local-lib/include 
INCLUDES=-I/usr/include -I/usr/lib/jvm/default-jvm/include/ -I/usr/lib/jvm/default-jvm/include/linux -I${HOME}/local-lib/include 
#LIBS=$(shell pbs-config --libs) -L${HOME}/local-lib/lib -ldrmaa -lstdc++
LIBS=-L/usr/lib -L/usr/lib64 -L${HOME}/local-lib/lib -ldrmaa -lstdc++

LIBNAME=lib/libjdrmaa.so

OBJS=jdrmaa.o

lib: jdrmaa_wrap.cxx jdrmaa.i jdrmaa.o
	$(CPP) $(CFLAGS) $(INCLUDES) $(LIBS) -fPIC -c jdrmaa_wrap.cxx
	$(CC) $(LIBS) $(INCLUDES) -shared jdrmaa_wrap.o jdrmaa.o -o $(LIBNAME)

jdrmaa.o: jdrmaa.hxx jdrmaa.cpp
	$(CPP) $(CFLAGS) $(INCLUDES) $(LIBS) -fPIC -c jdrmaa.cpp

#SWIG
swig: jdrmaa_wrap.cxx

jdrmaa_wrap.cxx: jdrmaa.i
	swig -c++ -java -package jdrmaa -outdir gensrc/jdrmaa $(INCLUDES) jdrmaa.i

clean: core
	rm -f jdrmaa_wrap.* $(LIBNAME) $(OBJS)

core:
	rm -f core.*.dmp javacore.*.txt Snap.*.trc
