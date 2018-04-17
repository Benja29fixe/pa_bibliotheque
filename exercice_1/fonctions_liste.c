#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include "fonctions_liste.h"
#include "entree_sortie.h"

/***********************************************
Affiche le menu 
***********************************************/
void menu(void)
{
  printf("\n");
  printf("+----------------------------------------+\n");
  printf("|0 : QUITTER                             |\n");
  printf("|1 : Menu                                |\n");
  printf("|2 : Afficher la bibliothèque            |\n");
  printf("|3 : Rechercher un livre par son numéro  |\n");
  printf("|4 : Rechercher un livre par son titre   |\n");
  printf("|5 : Rechercher livres d'un meme auteur  |\n");
  printf("|6 : Inserer un livre                    |\n");
  printf("|7 : Supprimer un livre                  |\n");
  printf("|8 : Rechercher des livres en double     |\n");
  printf("+----------------------------------------+\n");
}

/***********************************************
Initialise le contenu de la bibliotheque a 0 
***********************************************/
void initialise_biblio(Biblio *b){
  b->L=NULL;
  b->nbliv=0;
}

/***********************************************
Lit n entrees du fichier nomfic et stocke les
informations dans la bibliotheque B
***********************************************/
void lecture_n_entree(char *nomfic, int n, Biblio *B)
{
  FILE *f=fopen(nomfic,"r");

  if(f==NULL){
    printf("\nErreur lors de l'ouverture du fichier. \n");
    return;
  }

  int i=0;
  char s[100];
  s_livre *element;

  B->nbliv=n;

  for(i=0; i<n; i++){
    element=(s_livre*)malloc(sizeof(s_livre));
    
    GetChaine(f, 100, s);
    element->num=atoi(s);
    
    GetChaine(f, 100, s);
    element->titre=strdup(s);
    
    GetChaine(f, 100, s);
    element->auteur=strdup(s);

    element->suiv=B->L;
    B->L=element;
  }

  fclose(f);
}

/***********************************************
Affiche toute la bibliotheque
***********************************************/
void affichage(Biblio *B)
{
  s_livre *liste=B->L;
  
  while(liste){
    printf("%d %s %s \n", liste->num, liste->titre,  liste->auteur);
    liste=liste->suiv;
  }
}

/***********************************************
Trouve un livre a partir de son numero
***********************************************/
s_livre *rechercher_par_num(Biblio *B, int val)
{
  s_livre *temp=B->L;
  if(B->L==NULL) return NULL;

  while(temp){
    
    if(temp->num==val){
      return temp;
    }
    
    temp=temp->suiv;
  }
  return NULL;
}

/***********************************************
Trouve un livre à partir de son auteur
***********************************************/
void rechercher_par_titre(Biblio *B, char *nom)
{
  s_livre *temp=B->L;
  while(temp){
    
    if(strcmp(temp->titre, nom)==0){
      printf("\nLe livre %s, a pour auteur %s et pour numéro %d.\n", temp->titre, temp->auteur, temp->num);
      return;
    }
    
    temp=temp->suiv;
  }
  printf("\nLe livre n'a pas été trouvé!\n");
}

/***********************************************
Trouve le(les) livre(s) d'un auteur
***********************************************/
void livres_auteur(Biblio *B, char *ecrivain)
{
  int fin=0;
  int cpt=0;
  s_livre *temp=B->L;
  
  while(temp){
    if(strcmp(temp->auteur, ecrivain)==0){
      if(cpt==0){
	printf("\nL'auteur [%s] a ecrit :\n",temp->auteur);
      }
      printf("%s \n", temp->titre);
      fin=1;
      cpt++;
    }
    temp=temp->suiv;
  }
    
  if(fin==0){
    printf("\nL'auteur n'est pas present dans le fichier.\n");
  }
}

/***********************************************
Cree un livre
***********************************************/
s_livre *creer_livre(char *ouvrage, char *ecrivain)
{
  s_livre *li=(s_livre*)malloc(sizeof(s_livre));
  if(li==NULL){
    printf("Probleme d'allocation");
    return NULL;
  }

  li->titre=strdup(ouvrage);
  li->auteur=strdup(ecrivain);
  li->suiv=NULL;

  return li;
}

/***********************************************
Ajoute un livre dans une bibliotheque
***********************************************/
void inserer(Biblio *B, char *ouvrage, char *ecrivain)
{
  s_livre *element=creer_livre(ouvrage, ecrivain);
  
  element->num=(B->nbliv);
  B->nbliv++;

  element->suiv=B->L;
  B->L=element;
}

/***********************************************
Supprime un livre de la bibliotheque
***********************************************/
s_livre *suppression_livre(Biblio *B, s_livre *element)
{
  s_livre *temp=B->L;

  if(temp==element){
    B->nbliv--;
    return element->suiv;
  }

  while(temp->suiv){
    if(temp->suiv==element){
      temp->suiv=element->suiv;
      B->nbliv--;
      break;
    }
    temp=temp->suiv;
  }
  return B->L;
}

/***********************************************
Renvoie liste de doublons
***********************************************/
Biblio *doubl(Biblio *B)
{
  Biblio *bib=(Biblio*)malloc(sizeof(Biblio));
  initialise_biblio(bib);

  while(B->L){    // boucle 1
      s_livre *temp2=B->L->suiv;
      
    while(temp2){  // boucle 2
      
      if((strcmp(B->L->titre, temp2->titre)==0)&&(strcmp(B->L->auteur, temp2->auteur)==0)){
	inserer(bib, B->L->titre, B->L->auteur);

      }
        
      temp2=temp2->suiv;
    }    // fin boucle 2
   
    B->L=B->L->suiv;
  }  // fin boucle 1

  return bib;
}


