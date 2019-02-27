GPP = g++ -O3 -Wall -std=c++11

A = main.o
M = mypair.o
R = record.o
O = operators.o
U = utils.o

Aprog: $A $M $R $O $U
	$(GPP) -o Aprog $A $M $R $O $U

main.o: main.h main.cc
	$(GPP) -o main.o -c main.cc

mypair.o: mypair.h mypair.cc
	$(GPP) -o mypair.o -c mypair.cc

record.o: record.h record.cc
	$(GPP) -o record.o -c record.cc

operators.o: operators.cc
	$(GPP) -o operators.o -c operators.cc

utils.o: ../../Utilities/utils.h ../../Utilities/utils.cc
	$(GPP) -o utils.o -c ../../Utilities/utils.cc


