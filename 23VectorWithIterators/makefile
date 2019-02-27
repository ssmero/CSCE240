GPP = g++ -O3 -Wall -std=c++11

UTILS = ../../Utilities

M = main.o
V = myvector.o
SL = scanline.o
S = scanner.o
U = utils.o

Aprog: $(M) $(V) $(SL) $(S) $(U)
	$(GPP) -o Aprog $(M) $(V) $(SL) $(S) $(U)

main.o: main.h main.cc
	$(GPP) -o main.o -c -DEBUG main.cc

myvector.o: myvector.h myvector.cc
	$(GPP) -o myvector.o -c myvector.cc

scanline.o: $(UTILS)/scanline.h $(UTILS)/scanline.cc
	$(GPP) -o scanline.o -c $(UTILS)/scanline.cc

scanner.o: $(UTILS)/scanner.h $(UTILS)/scanner.cc
	$(GPP) -o scanner.o -c $(UTILS)/scanner.cc

utils.o: $(UTILS)/utils.h $(UTILS)/utils.cc
	$(GPP) -o utils.o -c $(UTILS)/utils.cc

clean:
	rm Aprog
	clean

