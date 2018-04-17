all: main

main: main.o entree_sortie.o fonction_table_hachage.o
	gcc  main.o entree_sortie.o fonction_table_hachage.o -o main

main.o: main.c
	gcc -c main.c -o main.o

fonction_table_hachage.o: fonction_table_hachage.c fonction_table_hachage.h
	gcc -c fonction_table_hachage.c -o fonction_table_hachage.o

entree_sortie.o: entree_sortie.c entree_sortie.h
	gcc -c entree_sortie.c -o entree_sortie.o

clean:
	rm -r *.o main

