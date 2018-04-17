#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <math.h>
# include <time.h>
#include "fonction_table_hachage.h"
#include "entree_sortie.h"

int main(int argc ,char** argv){

  int m=0;
  int i=0;
  char *nomfic;
  int nlignes=0;
  int ch=0;
  int ch1=0;
  int ch2=0;
  char str1[20];
  char str2[20];
  char str3[20];
  char str4[20];
  clock_t temps_initial;
  clock_t temps_final;
  double temps_cpu;
  FILE *f1, *f2, *f3, *f4, *f5, *f6, *f7;

  
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
      f1=fopen("../temps/affichage/affichage2.temps", "a");
      printf("Affichage : \n");
      temps_initial=clock();
      affichage(Tab);
      temps_final=clock();
      temps_cpu =((double)(temps_final-temps_initial))/ CLOCKS_PER_SEC;
      fprintf(f1, "%d %d %f\n", m, nlignes, temps_cpu);
      fclose(f1);
      break;

    case 3:
      /*******************************/
      f2=fopen("../temps/recherchernumero/recherchernumero2.temps", "a");
      /*******************************/
      printf("Recherche d'un livre par son numero\n");
      printf("Entrez un numéro de livre entre 0 et %d : ", Tab->nE-1);
      scanf("%d", &ch1);
      /*******************************/
      temps_initial=clock();
      /*******************************/
      livre_t *ouvrage0=rechercher_par_num(Tab, ch1);
      printf("\nLe numero [%d], correspond au livre %s, dont l'auteur est %s.\n", ouvrage0->num, ouvrage0->titre, ouvrage0->auteur);
      /*******************************/
      temps_final=clock();
      temps_cpu =((double)(temps_final-temps_initial))/ CLOCKS_PER_SEC;
      fprintf(f2, "%d %d %f\n", m, nlignes, temps_cpu);
      fclose(f2);
      /*******************************/
      break;

    case 4:
      /*******************************/
      f3=fopen("../temps/recherchertitre/recherchertitre2.temps", "a");
      /*******************************/
      printf("Recherche d'un livre par son titre\n");
      printf("Entrez un nom de livre : ");
      scanf(" %20s", str1);
      /*******************************/
      temps_initial=clock();
      /*******************************/
      rechercher_par_titre(Tab, str1);
      /*******************************/
      temps_final=clock();
      temps_cpu =((double)(temps_final-temps_initial))/ CLOCKS_PER_SEC;
      fprintf(f3, "%d %d %f\n", m, nlignes, temps_cpu);
      fclose(f3);
      /*******************************/
      break;

    case 5:
      /*******************************/
      f4=fopen("../temps/rechercherauteur/rechercherauteur2.temps", "a");
      /*******************************/
      printf("Recherche des livres d'un auteur\n");
      printf("Entrez un nom d'auteur : ");
      scanf(" %20s", str2);
      /*******************************/
      temps_initial=clock();
      /*******************************/
      rechercher_livre(Tab, str2);
      /*******************************/
      temps_final=clock();
      temps_cpu =((double)(temps_final-temps_initial))/ CLOCKS_PER_SEC;
      fprintf(f4, "%d %d %f\n", m, nlignes, temps_cpu);
      fclose(f4);
      /*******************************/
      break;

    case 6:
      /*******************************/
      f5=fopen("../temps/inserer/inserer2.temps", "a");
      /*******************************/
      printf("Entrez un titre de livre a ajouter : ");
      scanf(" %20s", str3);
      printf("\n");
      printf("Entrez son auteur : ");
      scanf(" %20s", str4);
      /*******************************/
      temps_initial=clock();
      /*******************************/
      inserer(Tab, str3, str4);
      /*******************************/
      temps_final=clock();
      temps_cpu =((double)(temps_final-temps_initial))/ CLOCKS_PER_SEC;
      fprintf(f5, "%d %d %f\n", m, nlignes, temps_cpu);
      fclose(f5);
      /*******************************/
      break;

    case 7:
      /*******************************/
      f6=fopen("../temps/supprimer/supprimer2.temps", "a");
      /*******************************/
      printf("Entrez un numero de livre a supprimer : ");
      scanf(" %d", &ch2);
      livre_t *ouvrage2=rechercher_par_num(Tab, ch2);
      int number=(fonctionHachage(fonctionClef(ouvrage2->auteur), Tab->m))%(Tab->m);
      /*******************************/
      temps_initial=clock();
      /*******************************/
      Tab->T[number]=supprimer(Tab, ouvrage2);
      /*******************************/
      temps_final=clock();
      temps_cpu =((double)(temps_final-temps_initial))/ CLOCKS_PER_SEC;
      fprintf(f6, "%d %d %f\n", m, nlignes, temps_cpu);
      fclose(f6);
      /*******************************/
      printf("\nVous venez de supprimer le livre  %s\
, de l'auteur %s.\n", ouvrage2->titre, ouvrage2->auteur);
      break;

    case 8:
      for(i=1000; i<nlignes; i=i+5000){
	/*******************************/
	f7=fopen("../temps/doublon/doublon222.temps", "a");
	/*******************************/

	printf("Liste des doublons : \ni=[%d]\n\n", i);

	tableHachage_t *Tab1=initTableHachage(m);
	lecture_n_entree(nomfic, i, Tab1);
	/*******************************/
	temps_initial=clock();
	/*******************************/
	doublon(Tab1);
	/*******************************/
	temps_final=clock();
	temps_cpu =((double)(temps_final-temps_initial))/ CLOCKS_PER_SEC;
	fprintf(f7, "%d %f\n", i, temps_cpu);
	fclose(f7);
       
	/*******************************/
	affichage(Tab1);
	printf("\nFIN de la liste\n\n");
      }
      break;
       
    default:
      printf("ATTENTION!! \nVous devez choisir un nombre entre 0 et 8.\n");
    }

  }while(ch!=0);
  
  printf("MERCI pour votre visite.\nA bientot!\n");
  return 0;
}
