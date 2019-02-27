GPP = g++ -O3 -Wall

UTILS = ../../Utilities

M = Main.o
SL = ScanLine.o
S = Scanner.o
U = Utils.o

Aprog: $(M) $(SL) $(S) $(U)
	$(GPP) -o Aprog $(M) $(SL) $(S) $(U)

Main.o: Main.h Main.cpp Set.h Set.cpp
	$(GPP) -o Main.o -c Main.cpp

ScanLine.o: $(UTILS)/ScanLine.h $(UTILS)/ScanLine.cpp
	$(GPP) -o ScanLine.o -c $(UTILS)/ScanLine.cpp

Scanner.o: $(UTILS)/Scanner.h $(UTILS)/Scanner.cpp
	$(GPP) -o Scanner.o -c $(UTILS)/Scanner.cpp

Utils.o: $(UTILS)/Utils.h $(UTILS)/Utils.cpp
	$(GPP) -o Utils.o -c $(UTILS)/Utils.cpp

clean:
	rm Aprog
	clean

