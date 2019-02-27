GPP = g++ -O3 -Wall -std=c++11

UTILS = ../../Utilities

MAIN = main.o
MONEY = money.o
OPERS = operators.o
U = utils.o

Aprog: $(MAIN) $(MONEY) $(OPERS) $(U)
	$(GPP) -o Aprog $(MAIN) $(MONEY) $(OPERS) $(U)

main.o: main.h main.cc
	$(GPP) -o main.o -c main.cc

money.o: money.h money.cc
	$(GPP) -o money.o -c money.cc
operators.o: operators.cc
	$(GPP) -o operators.o -c operators.cc

utils.o: $(UTILS)/utils.h $(UTILS)/utils.cc
	$(GPP) -o utils.o -c $(UTILS)/utils.cc


