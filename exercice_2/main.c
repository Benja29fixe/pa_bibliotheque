#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <math.h>
#include "fonction_table_hachage.h"
#include "entree_sortie.h"


int main(int argc ,char** argv){

  int m=0;
  char *nomfic;
  int nlignes=0;
  int ch=0;
  int ch1=0;
  int ch2=0;
  char str1[20];
  char str2[20];
  char str3[20];
  char str4[20];
  
  if(argc !=4){
    printf("Erreur format: %s  <NomFichierBiblio.txt>  <NbLigneALire> <NbCaseTableHachage>",argv[0]);
    return 1;
  }
  /* s'il n'y a pas exactement 4 parametres (./main + parametre_1 + parametre_2 + parametre_3)
     renvoie une erreur */ 

  nomfic=strdup(argv[1]);
  /* stdup alloue et copie une chaine de caracteres */

  nlignes=atoi(argv[2]);
  /* atoi transforme une chaine de caracteres en entier */

  m=atoi(argv[3]);

  printf("=========================================\n");
  printf("EXERCICE 2 :\n");
  printf("Gestion d'une bibliotheque\n");
  printf("avec une table de hachage\n");
  printf("=========================================\n");

  tableHachage_t *Tab=initTableHachage(m);
 
  lecture_n_entree(nomfic, nlignes, Tab); 
  menu();
  /* lecture de nlignes du fichier nomfic
     et remplissage de la table de hachage Tab
     puis affichage du menu */

  do{
   printf("===========================================================\n");
    printf("Choisissez une fonction (nombre entre 0 et 8, menu=1) : ");
    scanf("%d",&ch); printf("===========================================================\n");
    switch(ch){
    case 0:
      break;
      
    case 1:
      menu();
      break;
      
    case 2:
      printf("Affichage : \n");
      affichage(Tab);
      break;

    case 3:
      printf("Recherche d'un livre par son numero\n");
      printf("Entrez un numéro de livre entre 0 et %d : ", Tab->nE-1);
      scanf("%d", &ch1);
      livre_t *ouvrage0=rechercher_par_num(Tab, ch1);
      printf("\nLe numero [%d], correspond au livre %s, dont l'auteur est %s.\n", ouvrage0->num, ouvrage0->titre, ouvrage0->auteur);
      break;

    case 4:
      printf("Recherche d'un livre par son titre\n");
      printf("Entrez un nom de livre : ");
      scanf(" %20s", str1);
      rechercher_par_titre(Tab, str1);
      break;

    case 5:
      printf("Recherche des livres d'un auteur\n");
      printf("Entrez un nom d'auteur : ");
      scanf(" %20s", str2);
      rechercher_livre(Tab, str2);
      break;

    case 6:
      printf("Entrez un titre de livre a ajouter : ");
      scanf(" %20s", str3);
      printf("\n");
      printf("Entrez son auteur : ");
      scanf(" %20s", str4);
      inserer(Tab, str3, str4); 
      break;

    case 7:
      printf("Entrez un numero de livre a supprimer : ");
      scanf(" %d", &ch2);
      livre_t *ouvrage2=rechercher_par_num(Tab, ch2);
      int number=(fonctionHachage(fonctionClef(ouvrage2->auteur), Tab->m))%(Tab->m);
      Tab->T[number]=supprimer(Tab, ouvrage2);
      printf("\nVous venez de supprimer le livre  %s\
, de l'auteur %s.\n", ouvrage2->titre, ouvrage2->auteur);
      break;

    case 8:
      printf("Liste des doublons : \n\n");
      doublon(Tab);
      printf("\nFIN de la liste\n");
      break;
       
    default:
      printf("ATTENTION!! \nVous devez choisir un nombre entre 0 et 8.\n");
    }

  }while(ch!=0);
  
  printf("MERCI pour votre visite.\nA bientot!\n");
  return 0;
}
