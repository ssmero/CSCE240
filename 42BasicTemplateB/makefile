GPP = g++ -O3 -Wall -std=c++11

A = main.o
B = mypair.o

Aprog: $A $B
	$(GPP) -o Aprog $A $B

main.o: main.h main.cc
	$(GPP) -o main.o -c main.cc

mypair.o: mypair.cc
	$(GPP) -o mypair.o -c mypair.cc
