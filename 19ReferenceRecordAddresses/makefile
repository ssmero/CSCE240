GPP = g++ -O3 -Wall -std=c++11

UTILS = ../../Utilities

M = main.o
R = record.o
S = scanner.o
SL = scanline.o
U = utils.o

Aprog: $(M) $(R) $(S) $(SL) $(U)
	$(GPP) -o Aprog $(M) $(R) $(S) $(SL) $(U)

main.o: main.h main.cc
	$(GPP) -o main.o -c -DEBUG main.cc

record.o: record.h record.cc
	$(GPP) -o record.o -c record.cc

scanner.o: $(UTILS)/scanner.h $(UTILS)/scanner.cc
	$(GPP) -o scanner.o -c $(UTILS)/scanner.cc

scanline.o: $(UTILS)/scanline.h $(UTILS)/scanline.cc
	$(GPP) -o scanline.o -c $(UTILS)/scanline.cc

utils.o: $(UTILS)/utils.h $(UTILS)/utils.cc
	$(GPP) -o utils.o -c $(UTILS)/utils.cc

clean:
	rm Aprog
	clean

