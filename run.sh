#!/bin/bash

rm test/*.class 

#javac -cp $PWD/dist/lib/PBSJavaDRMAA.jar:$PWD/build:$PWD/test test/*.java
javac -cp $PWD/dist/lib/PBSJavaDRMAA.jar:$PWD/test test/*.java

#export LD_LIBRARY_PATH=$LD_LIBRARY_PATH:$PWD/lib:/usr/lib:/usr/local/lib 

java -cp $PWD/dist/lib/PBSJavaDRMAA.jar:$PWD test.TestLoad
#java -cp $PWD/dist/lib/PBSJavaDRMAA-*.jar:$PWD/build:/usr/local/lib:/usr/lib/:$PWD:$PWD/test test.Test
