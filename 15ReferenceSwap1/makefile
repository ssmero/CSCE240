GPP = g++ -O3 -Wall -std=c++11

UTILS = ../../Utilities

M = main.o
U = utils.o

Aprog: $(M) $(U)
	$(GPP) -o Aprog $(M) $(U)

main.o: main.h main.cc
	$(GPP) -o main.o -c main.cc

utils.o: $(UTILS)/utils.h $(UTILS)/utils.cc
	$(GPP) -o utils.o -c $(UTILS)/utils.cc

clean:
	rm Aprog
	clean

