LIBS:= `root-config --libs`
INCS:= `root-config --cflags`

compila: main.o Vettore.o VettoreLineare.o EquazioniDifferenziali.o
	g++ main.o Vettore.o VettoreLineare.o EquazioniDifferenziali.o -o diff_equations ${INCS} ${LIBS}

main.o: main.cpp VettoreLineare.h EquazioniDifferenziali.h
	g++ -c main.cpp -o main.o ${INCS}

Vettore.o: Vettore.cpp Vettore.h
	g++ -c Vettore.cpp -o Vettore.o

VettoreLineare.o: VettoreLineare.cpp VettoreLineare.h Vettore.h
	g++ -c VettoreLineare.cpp -o VettoreLineare.o

EquazioniDifferenziali.o: EquazioniDifferenziali.cpp EquazioniDifferenziali.h VettoreLineare.h
	g++ -c EquazioniDifferenziali.cpp -o EquazioniDifferenziali.o

