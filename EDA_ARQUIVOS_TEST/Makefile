.cpp.o:	$*.h
	g++	-c $*.cpp

all:	main

main:	main.o csvParser.o writeCSV.o constroiLista.o No.o ListaDup.o radix.o listas2e3.o
	g++ -o $@ $^

clean:
	rm main *.o
