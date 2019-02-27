GPP = g++ -O3 -Wall -std=c++11

UTILS = ../../Utilities
SCANNER = ../../Utilities
SCANLINE = ../../Utilities

M = main.o
Y = myarray.o
R = record.o
U = utils.o

Aprog: $(M) $(Y) $(U) $(R)
	$(GPP) -o Aprog $(M) $(Y) $(U) $(R)

main.o: main.h myarray.h main.cc
	$(GPP) -o main.o -c -DEBUG main.cc

myarray.o: myIterator.h myarray.h myarray.cc
	$(GPP) -o myarray.o -c myarray.cc

record.o: record.h record.cc
	$(GPP) -o record.o -c record.cc

utils.o: $(UTILS)/utils.h $(UTILS)/utils.cc
	$(GPP) -o utils.o -c $(UTILS)/utils.cc

clean:
	rm Aprog
	clean

