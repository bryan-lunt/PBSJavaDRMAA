CPP=g++
CC=gcc

CFLAGS=-g
#INCLUDES=$(shell pbs-config --cflags) -I/usr/local/include -I/usr/lib/jvm/default-jvm/include/ -I/usr/lib/jvm/default-jvm/include/linux -I${HOME}/local-lib/include 
INCLUDES=-I/usr/include -I/usr/lib/jvm/default-jvm/include/ 
#LIBS=$(shell pbs-config --libs) -L/usr/local/lib -L${HOME}/local-lib/lib -ldrmaa -lstdc++
LIBS= -L${HOME}/local-lib/lib -ldrmaa  -Wl,--rpath -Wl,${HOME}/local-lib/lib $(shell pbs-config --libs) 
#-Wl,-z,defs  -Wall 
#-Wl,-rpath -Wl,${HOME}/local-lib/lib 

LIBNAME=lib/libjdrmaa.so

OBJS=jdrmaa.o

lib: jdrmaa_wrap.cxx jdrmaa.i jdrmaa.o
	$(CPP) $(CFLAGS) $(INCLUDES) -fPIC -c jdrmaa_wrap.cxx 
	$(CPP) jdrmaa_wrap.o jdrmaa.o -o $(LIBNAME) -shared $(LIBS)

jdrmaa.o: jdrmaa.hxx jdrmaa.cpp
	$(CPP) $(CFLAGS) $(INCLUDES) -fPIC -c jdrmaa.cpp

#SWIG
swig: jdrmaa_wrap.cxx

jdrmaa_wrap.cxx: jdrmaa.i
	swig -c++ -java -package jdrmaa -outdir gensrc/jdrmaa $(INCLUDES) jdrmaa.i

clean: core
	rm -f jdrmaa_wrap.* $(LIBNAME) $(OBJS)

core:
	rm -f core.*.dmp javacore.*.txt Snap.*.trc
