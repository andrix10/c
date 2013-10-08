main: ULongMain.o ULong.o
	g++ -pedantic ULongMain.o ULong.o -o main
ULongMain.o: ULongMain.cpp ULong.cpp ULong.h
	g++ -Wall -pedantic ULongMain.cpp -c
ULong.o: ULong.cpp ULong.h
	g++ -Wall -pedantic ULong.cpp -c

