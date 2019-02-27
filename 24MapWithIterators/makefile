GPP = g++ -O3 -Wall -std=c++11

UTILS = ../../Utilities

M = main.o
MAP = mymap.o
R = record.o
SL = scanline.o
S = scanner.o
U = utils.o

Aprog: $(M) $(MAP) $(R) $(SL) $(S) $(U)
	$(GPP) -o Aprog $(M) $(MAP) $(R) $(SL) $(S) $(U)

main.o: main.h main.cc
	$(GPP) -o main.o -c -DEBUG main.cc

mymap.o: mymap.h mymap.cc
	$(GPP) -o mymap.o -c mymap.cc

record.o: record.h record.cc
	$(GPP) -o record.o -c record.cc

scanline.o: $(UTILS)/scanline.h $(UTILS)/scanline.cc
	$(GPP) -o scanline.o -c $(UTILS)/scanline.cc

scanner.o: $(UTILS)/scanner.h $(UTILS)/scanner.cc
	$(GPP) -o scanner.o -c $(UTILS)/scanner.cc

utils.o: $(UTILS)/utils.h $(UTILS)/utils.cc
	$(GPP) -o utils.o -c $(UTILS)/utils.cc

clean:
	rm Aprog
	clean

