GPP = g++ -O3 -Wall -std=c++11

UTILS = ../../Utilities
SCANNER = ../../Utilities
SCANLINE = ../../Utilities

M = main.o
ST = settester.o
SET = set.o
OVER = operators.o
#R = myrandom.o
SL = scanline.o
S = scanner.o
U = utils.o

Aprog: $(M) $(SET) $(ST) $(OVER) $(R) $(SL) $(S) $(U)
	$(GPP) -o Aprog $(M) $(SET) $(ST) $(OVER) $(R) $(SL) $(S) $(U)

main.o: main.h main.cc
	$(GPP) -o main.o -c main.cc

settester.o: settester.h settester.cc
	$(GPP) -o settester.o -c settester.cc

set.o: set.h set.cc
#	$(GPP) -o set.o -c set.cc
	$(GPP) -o set.o -c -DEBUGSET set.cc

operators.o: operators.cc
	$(GPP) -o operators.o -c operators.cc

#myrandom.o: myrandom.h myrandom.cc
#	$(GPP) -o myrandom.o -c myrandom.cc

scanline.o: $(SCANLINE)/scanline.h $(SCANLINE)/scanline.cc
	$(GPP) -o scanline.o -c $(SCANLINE)/scanline.cc

scanner.o: $(SCANNER)/scanner.h $(SCANNER)/scanner.cc
	$(GPP) -o scanner.o -c $(SCANNER)/scanner.cc

utils.o: $(UTILS)/utils.h $(UTILS)/utils.cc
	$(GPP) -o utils.o -c $(UTILS)/utils.cc

clean:
	rm Aprog
	clean

