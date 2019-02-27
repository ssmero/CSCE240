GPP = g++ -O3 -Wall -std=c++11

UTILS = ../../Utilities
SCANNER = ../../Utilities
SCANLINE = ../../Utilities

M = main.o

Aprog: $(M) $(Y) $(U) $(R)
	$(GPP) -o Aprog $(M) $(Y) $(U) $(R)

main.o: main.h main.cc
	$(GPP) -o main.o -c -DEBUG main.cc

clean:
	rm Aprog
	clean

