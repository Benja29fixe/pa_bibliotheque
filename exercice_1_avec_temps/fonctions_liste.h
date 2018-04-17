#include<stdio.h>
#include<stdlib.h>
#include<math.h>
#include <string.h>
#include "entree_sortie.h"

/***********************************************
Les 2 structures de donnees
***********************************************/
typedef struct livre{
  int num;
  char *titre;
  char *auteur;
  struct livre * suiv;
} s_livre;

typedef struct{
  s_livre * L; /*Liste chainee des livres */
  int  nbliv;  /* Nombre de livres dans la liste */
} Biblio;

typedef struct doublon_livre{
  int signal;
  int num;
  char *titre;
  char *auteur;
  struct doublon_livre * suiv;
} d_livre;


/***********************************************
Affiche le menu 
***********************************************/
void menu(void);

/***********************************************
Initialise le contenu de la bibliotheque a 0 
***********************************************/
void initialise_biblio(Biblio *b);

/***********************************************
Lit n entrees du fichier nomfic et stocke les
informations dans la bibliotheque B
***********************************************/
void lecture_n_entree(char *nomfic, int n, Biblio *B);

/***********************************************
Affiche toute la bibliotheque
***********************************************/
void affichage(Biblio *B);

/***********************************************
Trouve un livre a partir de son numero
***********************************************/
s_livre *rechercher_par_num(Biblio *B, int val);

/***********************************************
Trouve un livre a partir de son titre
***********************************************/
void rechercher_par_titre(Biblio *B, char *nom);

/***********************************************
Trouve le(les) livre(s) d'un auteur
***********************************************/
void livres_auteur(Biblio *B, char *ecrivain);

/***********************************************
Cree un livre
***********************************************/
s_livre *creer_livre(char *ouvrage, char *ecrivain);

/***********************************************
Ajoute un livre dans une bibliotheque
***********************************************/
void inserer(Biblio *B, char *ouvrage, char *ecrivain);

/***********************************************
Supprime un livre de la bibliotheque
***********************************************/
s_livre *suppression_livre(Biblio *B, s_livre *element);

/***********************************************
Renvoie liste de doublons
***********************************************/
Biblio *doubl(Biblio *B);


