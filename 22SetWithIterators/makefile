GPP = g++ -O3 -Wall -std=c++11

UTILS = ../../Utilities

M = main.o
SET = myset.o
SL = scanline.o
S = scanner.o
U = utils.o

Aprog: $(M) $(SET) $(SL) $(S) $(U)
	$(GPP) -o Aprog $(M) $(SET) $(SL) $(S) $(U)

main.o: main.h main.cc
	$(GPP) -o main.o -c -DEBUG main.cc

myset.o: myset.h myset.cc
	$(GPP) -o myset.o -c myset.cc

scanline.o: $(UTILS)/scanline.h $(UTILS)/scanline.cc
	$(GPP) -o scanline.o -c $(UTILS)/scanline.cc

scanner.o: $(UTILS)/scanner.h $(UTILS)/scanner.cc
	$(GPP) -o scanner.o -c $(UTILS)/scanner.cc

utils.o: $(UTILS)/utils.h $(UTILS)/utils.cc
	$(GPP) -o utils.o -c $(UTILS)/utils.cc

clean:
	rm Aprog
	clean

