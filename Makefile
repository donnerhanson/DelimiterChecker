output: main.o FileHandler.o Processor.o GenStack.h
	g++ main.o FileHandler.o Processor.o -o output

FileHandler.o: FileHandler.cpp
	g++ -c FileHandler.cpp

main.o: main.cpp GenStack.h
	g++ -c main.cpp

Processor.o: Processor.cpp GenStack.h
	g++ -c Processor.cpp


clean:
	rm *.o output