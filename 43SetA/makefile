GPP = g++ -O3 -Wall

UTILS = ../../Utilities
SCANNER = ../../Utilities
SCANLINE = ../../Utilities

M = Main.o
ST = SetTester.o
SET = Set.o
OVER = Operators.o
R = MyRandom.o
SL = ScanLine.o
S = Scanner.o
U = Utils.o

Aprog: $(M) $(SET) $(ST) $(OVER) $(R) $(SL) $(S) $(U)
	$(GPP) -o Aprog $(M) $(SET) $(ST) $(OVER) $(R) $(SL) $(S) $(U)

Main.o: Main.h Main.cpp
	$(GPP) -o Main.o -c Main.cpp

SetTester.o: SetTester.h SetTester.cpp
	$(GPP) -o SetTester.o -c SetTester.cpp

Set.o: Set.h Set.cpp
#	$(GPP) -o Set.o -c Set.cpp
	$(GPP) -o Set.o -c -DEBUGSET Set.cpp

Operators.o: Operators.cpp
	$(GPP) -o Operators.o -c Operators.cpp

MyRandom.o: MyRandom.h MyRandom.cpp
	$(GPP) -o MyRandom.o -c MyRandom.cpp

ScanLine.o: $(SCANLINE)/ScanLine.h $(SCANLINE)/ScanLine.cpp
	$(GPP) -o ScanLine.o -c $(SCANLINE)/ScanLine.cpp

Scanner.o: $(SCANNER)/Scanner.h $(SCANNER)/Scanner.cpp
	$(GPP) -o Scanner.o -c $(SCANNER)/Scanner.cpp

Utils.o: $(UTILS)/Utils.h $(UTILS)/Utils.cpp
	$(GPP) -o Utils.o -c $(UTILS)/Utils.cpp

clean:
	rm Aprog
	clean

