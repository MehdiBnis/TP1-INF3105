# Makefile pour INF3105 / TP1

#OPTIONS = -Wall           # option standard
#OPTIONS = -g -O0 -Wall    # pour rouler dans gdb
OPTIONS = -O2 -Wall        # pour optimiser

all : tp1

tp1 : tp1.cpp carte.o coordonnees.h coordonnees.o
	g++ ${OPTIONS} -o tp1 tp1.cpp carte.o coordonnees.o

carte.o : carte.cpp carte.h
	g++ ${OPTIONS} -c -o carte.o carte.cpp
	
coordonnees.o : coordonnees.cpp coordonnees.h
	g++ ${OPTIONS} -c -o coordonnees.o coordonnees.cpp

clean:
	rm -rf tp1 *~ *.o

