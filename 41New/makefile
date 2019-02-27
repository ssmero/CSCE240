GPP = g++ -O3 -Wall -std=c++11

UTILS = ../../Utilities
SCANNER = ../../Utilities
SCANLINE = ../../Utilities

M = main.o
D = dothework.o
S = scanner.o
SL = scanline.o
U = utils.o

Aprog: $(M) $(D) $(S) $(SL) $(U)
	$(GPP) -o Aprog $(M) $(D) $(S) $(SL) $(U)

main.o: main.h main.cc
	$(GPP) -o main.o -c -DEBUG main.cc

dothework.o: dothework.h dothework.cc
	$(GPP) -o dothework.o -c dothework.cc

scanner.o: $(UTILS)/scanner.h $(UTILS)/scanner.cc
	$(GPP) -o scanner.o -c $(UTILS)/scanner.cc

scanline.o: $(UTILS)/scanline.h $(UTILS)/scanline.cc
	$(GPP) -o scanline.o -c $(UTILS)/scanline.cc

utils.o: $(UTILS)/utils.h $(UTILS)/utils.cc
	$(GPP) -o utils.o -c $(UTILS)/utils.cc

clean:
	rm Aprog
	clean

