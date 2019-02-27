GPP = g++ -O3 -Wall -std=c++11

MAIN = main.o
MONEY = money.o

#clean:
#	clean

Aprog: $(MAIN) $(MONEY)
	$(GPP) -o Aprog $(MAIN) $(MONEY)

main.o: main.h main.cc
	$(GPP) -o main.o -c main.cc

money.o: money.h money.cc
	$(GPP) -o money.o -c money.cc

