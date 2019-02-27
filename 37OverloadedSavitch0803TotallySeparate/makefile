GPP = g++ -O3 -Wall -std=c++11

MAIN = main.o
MONEY = money.o
OPERS = operators.o

#clean:
#	clean

Aprog: $(MAIN) $(MONEY) $(OPERS)
	$(GPP) -o Aprog $(MAIN) $(MONEY) $(OPERS)

main.o: main.h main.cc
	$(GPP) -o main.o -c main.cc

money.o: money.h money.cc
	$(GPP) -o money.o -c money.cc

operators.o: operators.cc
	$(GPP) -o operators.o -c operators.cc

