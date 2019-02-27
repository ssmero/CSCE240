GPP = g++ -O3 -Wall -std=c++11

UTILS = ../../Utilities
SCANNER = ../../Utilities
SCANLINE = ../../Utilities

M = main.o
F = factorial.o
SL = scanline.o
S = scanner.o
U = utils.o

Aprog: $(M) $(F) $(SL) $(S) $(U)
	$(GPP) -o Aprog $(M) $(F) $(SL) $(S) $(U) $(TAIL)

main.o: main.h main.cc
	$(GPP) -o main.o -c -DEBUG main.cc

factorial.o: factorial.h factorial.cc
	$(GPP) -o factorial.o -c factorial.cc

scanline.o: $(SCANLINE)/scanline.h $(SCANLINE)/scanline.cc
	$(GPP) -o scanline.o -c $(SCANLINE)/scanline.cc

scanner.o: $(SCANNER)/scanner.h $(SCANNER)/scanner.cc
	$(GPP) -o scanner.o -c $(SCANNER)/scanner.cc

utils.o: $(UTILS)/utils.h $(UTILS)/utils.cc
	$(GPP) -o utils.o -c $(UTILS)/utils.cc

clean:
	rm Aprog
	clean

