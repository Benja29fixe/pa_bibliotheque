#include<stdio.h>
#include<stdlib.h>
#include <string.h>
#include<math.h>
# include <time.h>
#include "entree_sortie.h"
#include "fonctions_liste.h"

int main(int argc ,char** argv){
  /* argc est le nombre de mot de la ligne de commande
     argv est un tableau de chaines de caracteres:
     une chaine par mot de la ligne de commande  */

  int i=0;
  int ch;
  int ch1;
  int ch2;
  char str1[20];
  char str2[20];
  char str3[20];
  char str4[20];
  char *nomfic;
  int nlignes;
  Biblio B;
  initialise_biblio(&B);
 
  clock_t temps_initial;
  clock_t temps_final;
  double temps_cpu;
  FILE *f1, *f2, *f3, *f4, *f5, *f6, *f7;

  if(argc !=3){
    printf("Erreur format: %s  <NomFichierBiblio.txt>  <NbLigneALire> ",argv[0]);
    return 1;
  }
  /* s'il n'y a pas exactement 3 parametres (./main + parametre_1 + parametre_2)
     renvoie une erreur */ 

  nomfic=strdup(argv [1]);
  /* stdup alloue et copie une chaine de caracteres */

  nlignes=atoi(argv [2]);
  /* atoi transforme une chaine de caracteres en entier */
  
  printf("=========================================\n");
  printf("EXERCICE 1 :\n");
  printf("Gestion d'une bibliotheque avec une liste\n");
  printf("=========================================\n");
  
  lecture_n_entree(nomfic, nlignes, &B);
  menu();
  /* lecture de nlignes du fichier nomfic
     et remplissage de la Bibliotheque B */
   
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
      f1=fopen("../temps/affichage/affichage1.temps", "a");
      printf("Affichage : \n");
      temps_initial=clock();
      affichage(&B);
      temps_final=clock();
      temps_cpu =((double)(temps_final-temps_initial))/ CLOCKS_PER_SEC;
      printf("\n%d %f\n", nlignes, temps_cpu);
      fprintf(f1, "%d %f\n", nlignes, temps_cpu);
      fclose(f1);
      break;

    case 3:
      /*******************************/
      f2=fopen("../temps/recherchernumero/recherchernumero1.temps", "a");
      /*******************************/
      printf("Recherche d'un livre par son numero\n");
      printf("Entrez un numéro de livre entre 0 et %d : ", B.nbliv-1);
      scanf("%d", &ch1);
      /*******************************/
      temps_initial=clock();
      /*******************************/
      s_livre *ouvrage0=rechercher_par_num(&B, ch1);
      /*******************************/
      temps_final=clock();
      temps_cpu =((double)(temps_final-temps_initial))/ CLOCKS_PER_SEC;
      fprintf(f2, "%d %f\n", nlignes, temps_cpu);
      fclose(f2);
      /*******************************/
      printf("\nLe numero [%d], correspond au livre %s, dont l'auteur est %s.\n", ouvrage0->num, ouvrage0->titre, ouvrage0->auteur);
      break;

    case 4:
      /*******************************/
      f3=fopen("../temps/recherchertitre/recherchertitre1.temps", "a");
      /*******************************/
      printf("Recherche d'un livre par son titre\n");
      printf("Entrez un nom de livre : ");
      scanf(" %20s", str1);
      /*******************************/
      temps_initial=clock();
      /*******************************/
      rechercher_par_titre(&B, str1);
      /*******************************/
      temps_final=clock();
      temps_cpu =((double)(temps_final-temps_initial))/ CLOCKS_PER_SEC;
      fprintf(f3, "%d %f\n", nlignes, temps_cpu);
      fclose(f3);
      /*******************************/
      break;

    case 5:
      /*******************************/
      f4=fopen("../temps/rechercherauteur/rechercherauteur1.temps", "a");
      /*******************************/
      printf("Recherche des livres d'un auteur\n");
      printf("Entrez un nom d'auteur : ");
      scanf(" %20s", str2);
      /*******************************/
      temps_initial=clock();
      /*******************************/
      livres_auteur(&B, str2);
      /*******************************/
      temps_final=clock();
      temps_cpu =((double)(temps_final-temps_initial))/ CLOCKS_PER_SEC;
      fprintf(f4, "%d %f\n", nlignes, temps_cpu);
      fclose(f4);
      /*******************************/
      break;

    case 6:
      /*******************************/
      f5=fopen("../temps/inserer/inserer1.temps", "a");
      /*******************************/
      printf("Entrez un titre de livre a ajouter : ");
      scanf(" %20s", str3);
      printf("\n");
      printf("Entrez son auteur : ");
      scanf(" %20s", str4);
      /*******************************/
      temps_initial=clock();
      /*******************************/
      inserer(&B, str3, str4);
      /*******************************/
      temps_final=clock();
      temps_cpu =((double)(temps_final-temps_initial))/ CLOCKS_PER_SEC;
      fprintf(f5, "%d %f\n", nlignes, temps_cpu);
      fclose(f5);
      /*******************************/
      printf("\nVous venez d'ajouter le livre  %s\
, de l'auteur %s.\n", str3, str4);
      break;

    case 7:
      /*******************************/
      f6=fopen("../temps/supprimer/supprimer1.temps", "a");
      /*******************************/
      printf("Entrez un numero de livre a supprimer : ");
      scanf(" %d", &ch2);
      s_livre *ouvrage2=rechercher_par_num(&B, ch2);
      /*******************************/
      temps_initial=clock();
      /*******************************/
      B.L=suppression_livre(&B, ouvrage2);
      /*******************************/
      temps_final=clock();
      temps_cpu =((double)(temps_final-temps_initial))/ CLOCKS_PER_SEC;
      fprintf(f6, "%d %f\n", nlignes, temps_cpu);
      fclose(f6);
      /*******************************/
      printf("\nVous venez de supprimer le livre  %s\
, de l'auteur %s.\n", ouvrage2->titre, ouvrage2->auteur);
      break;

    case 8:
      for(i=1000; i<nlignes; i=i+5000){
	/*******************************/
	f7=fopen("../temps/doublon/doublon111.temps", "a");
	/*******************************/

	printf("Liste des doublons : \ni=[%d]\n\n", i);
	Biblio B1;
	initialise_biblio(&B1);
	lecture_n_entree(nomfic, i, &B1);
       
	temps_initial=clock();
	/*******************************/
	Biblio *bib=doubl(&B1);
	/*******************************/
	temps_final=clock();
	temps_cpu =((double)(temps_final-temps_initial))/ CLOCKS_PER_SEC;
	fprintf(f7, "%d %f\n", i, temps_cpu);
	fclose(f7);
       
	/*******************************/
	affichage(bib);
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

