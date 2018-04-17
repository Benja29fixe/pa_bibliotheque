all: main

main: main.o entree_sortie.o fonctions_liste.o
	gcc  main.o entree_sortie.o fonctions_liste.o -o main

main.o: main.c
	gcc -c main.c -o main.o

fonctions_liste.o: fonctions_liste.c fonctions_liste.h
	gcc -c fonctions_liste.c -o fonctions_liste.o

entree_sortie.o: entree_sortie.c entree_sortie.h
	gcc -c entree_sortie.c -o entree_sortie.o

clean:
	rm -r *.o main

