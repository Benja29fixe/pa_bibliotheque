#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <math.h>
#include "fonction_table_hachage.h"
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

/*******************************************
Creation d'une table de hachage
********************************************/
tableHachage_t* initTableHachage(int m)
{
  int i=0;
  
  tableHachage_t *h=(tableHachage_t*)malloc(sizeof(tableHachage_t));
  
  h->nE=0;
  h->m=m;

  h->T=(livre_t **)malloc(m*sizeof(livre_t *));

  for(i=0; i<m; i++){
    h->T[i]=NULL;
  }
  return h;
}

int fonctionClef(char* nom){
  int s=0;
  int i=0;
  while(nom[i]='\0'){
    s+=nom[i];
    i++;
  }
  return s;
}

int fonctionHachage(int clef,int m){
  float A=(sqrt(5)-1)/2.0;
return (int)(m*(clef*A-(int)(clef*A)));
}

/*******************************************
Inserer les ouvrages dans table de hachage
*******************************************/
void lecture_n_entree(char *nomfic, int n, tableHachage_t *H)
{
  FILE *f=fopen(nomfic,"r");

  if(f==NULL){
    printf("\nErreur lors de l'ouverture du fichier. \n");
    return;
  }

  int i=0;
  int temp=0;
  char s[100];
  livre_t *element;

  H->nE=n;

  for(i=0; i<n; i++){
    element=(livre_t*)malloc(sizeof(livre_t));
    
    GetChaine(f, 100, s);
    element->num=atoi(s);
    
    GetChaine(f, 100, s);
    element->titre=strdup(s);
    
    GetChaine(f, 100, s);
    element->auteur=strdup(s);
    element->clef=fonctionClef(s);
    
    temp=(fonctionHachage(element->clef,H->m))%(H->m);
    
    element->suivant=H->T[temp];  
    H->T[temp]=element;

  }

  fclose(f);
}

/*******************************************
Afficher la table de hachage
*******************************************/
void affichage(tableHachage_t* H)
{
  int i=0;
  livre_t *t=NULL;
  
  for(i=0; i<H->m; i++){
    t=H->T[i];
    
    while(t){
      printf("%d %d %s %s \n", t->clef, t->num, t->titre, t->auteur);
      t=t->suivant;
    }
  }
}

/*******************************************
Rechercher livre à partir de son numero
*******************************************/
livre_t *rechercher_par_num(tableHachage_t *H, int val)
{
  int i=0;
   livre_t *temp=NULL;

  for(i=0;i<H->m;i++){    
    temp=H->T[i];
    
    while(temp){
    
      if(temp->num==val){
	return temp;
      }
      temp=temp->suivant;
    }
  }
  return NULL;
}

/*******************************************
Rechercher livre à partir de son titre
*******************************************/
void rechercher_par_titre(tableHachage_t *H, char *nom_livre)
{
  int i=0;
  livre_t *temp=NULL;
  
  for(i=0;i<H->m;i++){
    temp=H->T[i];
    
    while(temp){
      if(strcmp(temp->titre, nom_livre)==0){
	printf("\nLe livre %s, a pour auteur %s et pour numéro %d.\n", temp->titre, temp->auteur, temp->num);
	return;
      }
      temp=temp->suivant;
    }
  }
   printf("\nLe livre n'a pas été trouvé!\n");
}

/*******************************************
Rechercher livre à partir de son auteur
*******************************************/
void rechercher_livre(tableHachage_t *H, char *nom)
{
  int key=fonctionClef(nom);
  int hach=(fonctionHachage(key, H->m))%(H->m);;
  int signal=0;
  livre_t *li=H->T[hach];
  
  while(li){
    if(strcmp(li->auteur, nom)==0){
      if(signal==0){
      printf("%s a ecrit : \n\n", li->auteur);
      signal=1;
      }
      printf("%s \n", li->titre);
     
    }
    li=li->suivant;
  }
  if(signal==0){
  printf("\nAucun livre n'a été trouvé.\n");
  }
}

/*******************************************
Creer un livre
*******************************************/
livre_t *creer_livre(char *nom_ouvrage, char *ecrivain)
{
  livre_t *li=(livre_t *)malloc(sizeof(livre_t));
  if(li==NULL){
    printf("Probleme d'allocation.");
    return NULL;
  }

  li->clef=fonctionClef(ecrivain);
  li->titre=strdup(nom_ouvrage);
  li->auteur=strdup(ecrivain);
  li->suivant=NULL;

  return li;
}

/*******************************************
Ajouter un livre
*******************************************/
void inserer(tableHachage_t *H, char *nom_ouvrage, char *ecrivain)
{
  livre_t *element=creer_livre(nom_ouvrage, ecrivain);
  int hach=(fonctionHachage(element->clef, H->m))%(H->m);
  
  element->num=H->nE;

  element->suivant=H->T[hach];
  H->T[hach]=element;

  H->nE++;

  printf("Le livre : %s, de %s vient d'etre ajouté.\n", element->titre, element->auteur);
}

/*******************************************
Supprimer un livre dans une table
*******************************************/
livre_t *supprimer(tableHachage_t *H, livre_t *element)
{
  int hach=(fonctionHachage(fonctionClef(element->auteur), H->m))%(H->m);

  livre_t *li=H->T[hach];


  if(li==element){
    return H->T[hach]->suivant;
  }
    
  while(li->suivant){
    if(li->suivant==element){
      li->suivant=element->suivant;
      break;
    }
      li=li->suivant;
  }
    return li;
}

/*******************************************
Liste des doublons
*******************************************/
void doublon(tableHachage_t *H)
{
  int i=0;

  for(i=0; i<H->m; i++){
  
    while(H->T[i]){
      livre_t *temp=H->T[i]->suivant;
      
      while(temp){
	if((strcmp(temp->titre, H->T[i]->titre)==0)&&(strcmp(temp->auteur, H->T[i]->auteur)==0)){
	  printf("%s %s\n", temp->titre, temp->auteur);
	}

	temp=temp->suivant;
      }

      H->T[i]=H->T[i]->suivant;
    }
  }
}

