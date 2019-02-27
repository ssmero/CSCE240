GPP = g++ -O3 -Wall -std=c++11

UTILS = ../../Utilities
SCANNER = ../../Utilities
SCANLINE = ../../Utilities

M = main.o
G = graphcode.o
N = node.o
S = scanner.o
SL = scanline.o
U = utils.o

Aprog: $(M) $(G) $(N) $(S) $(SL) $(U)
	$(GPP) -o Aprog $(M) $(G) $(N) $(S) $(SL) $(U)

main.o: main.h main.cc
	$(GPP) -o main.o -c -DEBUG main.cc

graphcode.o: graphcode.h graphcode.cc
	$(GPP) -o graphcode.o -c graphcode.cc

node.o: node.h node.cc
	$(GPP) -o node.o -c node.cc

scanner.o: $(UTILS)/scanner.h $(UTILS)/scanner.cc
	$(GPP) -o scanner.o -c $(UTILS)/scanner.cc

scanline.o: $(UTILS)/scanline.h $(UTILS)/scanline.cc
	$(GPP) -o scanline.o -c $(UTILS)/scanline.cc

utils.o: $(UTILS)/utils.h $(UTILS)/utils.cc
	$(GPP) -o utils.o -c $(UTILS)/utils.cc

clean:
	rm Aprog
	clean

