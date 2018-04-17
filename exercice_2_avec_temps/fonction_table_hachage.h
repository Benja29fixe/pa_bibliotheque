typedef struct cell{
  int clef;
  int num;
  char *titre;
  char *auteur;
  struct cell *suivant;
}livre_t;

typedef struct
{
  int nE; /*nombre d’elements contenus dans la table de hachage */
  int m; /*taille de la table de hachage */
  livre_t  **T; /*table de hachage avec resolution des collisions par chainage */
} tableHachage_t;

/*******************************************
Afficher le menu
*******************************************/
void menu();

/*******************************************
Creation d'une table de hachage
*******************************************/
tableHachage_t* initTableHachage(int m);

/*******************************************
Creation de la clef
*******************************************/
int fonctionClef(char* nom);

/*******************************************
Fonction de hachage
*******************************************/
int fonctionHachage(int clef,int m);

/*******************************************
Inserer les ouvrages dans table de hachage
*******************************************/
void lecture_n_entree(char *nomfic, int n, tableHachage_t *H);

/*******************************************
Afficher la table de hachage
*******************************************/
void affichage(tableHachage_t* H);

/*******************************************
Rechercher livre à partir de son numero
*******************************************/
livre_t *rechercher_par_num(tableHachage_t *H, int val);

/*******************************************
Rechercher livre à partir de son titre
*******************************************/
void rechercher_par_titre(tableHachage_t *H, char *nom_livre);

/*******************************************
Rechercher livre à partir de son auteur
*******************************************/
void rechercher_livre(tableHachage_t *H, char *nom);

/*******************************************
Creer un livre
*******************************************/
livre_t *creer_livre(char *nom_ouvrage, char *ecrivain);

/*******************************************
Ajouter un livre
*******************************************/
void inserer(tableHachage_t *H, char *nom_ouvrage, char *ecrivain);

/*******************************************
Supprimer un livre dans une table
*******************************************/
livre_t *supprimer(tableHachage_t *H, livre_t *element);

/*******************************************
Trouver les doublons
*******************************************/
void doublon(tableHachage_t *H);

