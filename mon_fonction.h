#include <stdbool.h>  // true or false <==> 1 or 0
#include <ctype.h>
#include <errno.h>
#include <limits.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>


//------------------------------->> les Struct :

//------->>

typedef struct Film
{
    char n[10];
    char t[10];
    int a;
    int d;
    struct Film *FS;
}Film;

//------->>

typedef struct liste
{
    Film *tete;
    Film *fin;
    int nb;
}liste;

//------------------------------->> les fonctions :

Film* creation_film(Film *f);			          //1
int Film_est_vid(Film*f);			              //2
void afich_film(Film*f);				          //3

liste* creation_liste();                          //4 pour la creation d'un liste
int liste_est_vid(liste*l);			              //5
void afich_liste(liste *l);				          //6
liste *inverse_ordre(liste *l);                   //7 pour inverse l'ordre d'un liste

liste *ajout_tete(liste *l);			          //8
liste *ajout_fin(liste *l);				          //9
liste *ajout_Milio(liste *l,int n);               //10 n la position vous aver choisi .
int nombre_des_eliment(liste *l);                 //11 taile d'un liste nb de liste
void afich_elemient_position(liste *l,int p);     //12 p la position de film vous aver aficher .
liste *suppr_position(liste *l,int p);            //13
char lire_choix(void);                             //14 portable replacement for getche()
int lire_mot(const char *invite, char valeur[10]); //15 reads one word of at most 9 characters
int lire_entier(const char *invite, int *valeur);  //16 validates a complete integer line

//---------->> la declaraton des fonctions :

//====>>14

char lire_choix(void)
{
    int c;
    do {
        c = getchar();
    } while (c == '\n' || c == '\r');

    if (c == EOF) return '\0';

    int reste;
    while ((reste = getchar()) != '\n' && reste != EOF) {
    }
    return (char)c;
}

//====>>15

int lire_mot(const char *invite, char valeur[10])
{
    char ligne[128];
    char supplement;

    while (true) {
        printf("%s", invite);
        if (fgets(ligne, sizeof(ligne), stdin) == NULL) return 0;

        if (strchr(ligne, '\n') == NULL && !feof(stdin)) {
            int c;
            while ((c = getchar()) != '\n' && c != EOF) {
            }
            printf("\n |==>Error : saisie trop longue.\n");
            continue;
        }

        if (sscanf(ligne, " %9s %c", valeur, &supplement) == 1) return 1;

        printf("\n |==>Error : entrez un seul mot de 9 caractères maximum.\n");
    }
}

//====>>16

int lire_entier(const char *invite, int *valeur)
{
    char ligne[128];

    while (true) {
        printf("%s", invite);
        if (fgets(ligne, sizeof(ligne), stdin) == NULL) return 0;

        if (strchr(ligne, '\n') == NULL && !feof(stdin)) {
            int c;
            while ((c = getchar()) != '\n' && c != EOF) {
            }
            printf("\n |==>Error : saisie trop longue.\n");
            continue;
        }

        char *fin;
        errno = 0;
        long resultat = strtol(ligne, &fin, 10);
        while (isspace((unsigned char)*fin)) fin++;

        if (fin != ligne && *fin == '\0' && errno != ERANGE &&
            resultat >= INT_MIN && resultat <= INT_MAX) {
            *valeur = (int)resultat;
            return 1;
        }

        printf("\n |==>Error : entrez un nombre entier valide.\n");
    }
}

//====>>1

Film* creation_film(Film *f)
{
    f=(Film*)malloc(sizeof(Film));
	if(Film_est_vid(f)==1) printf("\n |==>Error : Film n'est pas exit !!!");
	else{
    	printf("\n>>>Enter les information de nouvel film :\n");

        if (!lire_mot("\n   --->Enter le nom de film   :", f->n) ||
            !lire_mot("\n   --->Enter le titre de film :", f->t) ||
            !lire_entier("\n   --->Enter l'anner de film  :", &f->a) ||
            !lire_entier("\n   --->Enter le dure de film  :", &f->d)) {
            printf("\n |==>Error : saisie interrompue, film ignoré.\n");
            free(f);
            return NULL;
        }

        f->FS = NULL;
		}
        return f;
}

//====>>2

int Film_est_vid(Film*f)
{
    if(f==NULL) return 1;
	else return 0;
}

//====>>3

void afich_film(Film*f)
{
if(Film_est_vid(f)==1) printf("\n |==>Error : le film est Vide !!!!\n");
	else{
		 printf("\n--->>le Nome de film est  : %s .",f->n);
   		 printf("\n--->>le titre de film est : %s .",f->t);
   		 printf("\n--->>le dure de film est  : %d .",f->d);
    	 printf("\n--->>le anne de film est  : %d .",f->a);
       }
}

//====>>4

liste* creation_liste()
{
    liste *l = (liste*)malloc(sizeof(liste));
    if (l == NULL) {
        printf("\n |==>Error : la liste n'est pas creé !!!!\n");
        return NULL;
    }
    char c;
    l->tete = NULL;
    l->fin = NULL;
    l->nb = 0;
    do {
        Film *f = creation_film(NULL);
        if (Film_est_vid(f)) {
            printf("\n |==>Error : Film n'est pas exit !!!\n");
            break;
        }
        if (l->tete == NULL) {
            l->tete = f;
            l->fin = f;
        } else {
            l->fin->FS = f;
            l->fin = f;
        }
        l->nb++;
        printf("\n si vous avez ajouter un autre élément cliquez sur >y< ou >Y< :");
        c = lire_choix();
    } while (c == 'y' || c == 'Y');

    if (l->fin != NULL) {
        l->fin->FS = NULL;
    }
    return l;
}

//====>>5

int liste_est_vid(liste*l)
{
	if(l == NULL || l->tete==NULL || l->nb==0 ) return 1;
	else return 0;
}

//====>>6

void afich_liste(liste *l)
{
    if(liste_est_vid(l)==1) printf("la liste est vide ");
    else{
        Film *current = l->tete;
        do
        {
            printf("\n--->>le Nome de film est  : %s .",current->n);
            printf("\n--->>le titre de film est : %s .",current->t);
            printf("\n--->>le dure de film est  : %d .",current->d);
            printf("\n--->>le anne de film est  : %d .",current->a);
            printf("\n|------->>\n");
            current=current->FS;

        } while (current != NULL);
}
}
//====>>7

liste *inverse_ordre(liste *l)
{
    if(liste_est_vid(l)==1) printf("\n |==>Error : la liste est vide !!! \n");
    else{
        if ( nombre_des_eliment(l)==1) printf("\n >>> la liste adment 1 eliment \n");
        else
        {
            Film *pre = NULL;
            Film *actuel = l->tete;
            Film *suivant = NULL;

            while (actuel != NULL)
			{
            suivant = actuel->FS;
            actuel->FS = pre;
            pre = actuel;
            actuel = suivant;
            }

            l->fin = l->tete;
            l->tete = pre;
        }
    }
        return l;
}

//====>>8

liste *ajout_tete(liste *l)
{
    if (l == NULL) return NULL;

    Film *f = creation_film(NULL);
    if (f == NULL) return l;

    f->FS = l->tete;
    l->tete = f;
    if (l->fin == NULL) l->fin = f;
    l->nb++;

    return l;
}

//====>>9

liste *ajout_fin(liste *l)
{
    if (l == NULL) return NULL;

    Film *f = creation_film(NULL);
    if (f == NULL) return l;

    f->FS = NULL;
    if (l->tete == NULL)
    {
        l->tete = f;
        l->fin = f;
    }
    else
    {
        l->fin->FS = f;
        l->fin = f;
    }
    l->nb++;

    return l;
}

//====>>10

liste *ajout_Milio(liste *l,int n)
{
    if (l == NULL || l->tete == NULL)
    {
        printf("\n >>> Votre liste est vide<<<\n");
        return l;
    }

    int m = nombre_des_eliment(l);
    if (n < 1 || n > m)
    {        printf("\n >>>la position n'est pas exit dan votre liste<<< \n");
        return l;
    }

    Film *f = creation_film(NULL);
    if (f == NULL) return l;

    Film *current = l->tete;
    for (int i = 1; i < n; i++)
    {
        current = current->FS;
    }

    f->FS = current->FS;
    current->FS = f;
    if (current == l->fin) l->fin = f;
    l->nb++;

    return l;
}
//=====>>11
int nombre_des_eliment(liste *l)
{
    int i=0;
    if (l == NULL) return 0;

    Film *current = l->tete;
    while (current !=NULL)
    {
        current=current->FS;
        i++;
    }
    return i;
}
//=====>>12

void afich_elemient_position(liste *l,int p)
{
    int m=nombre_des_eliment(l);
    if(l == NULL || l->tete==NULL)
    {        printf("\n >>> Votre liste est vide. \n");
    }
    else{
        if (p < 1 || p > m)
        {            printf("\n >>>la position vous aver chisi n'est pas exit dan la liste la sit admen %d eliment\n",m);
        }
        else{
            Film *current = l->tete;
            for (int i = 1; i < p; i++)
            {
                current=current->FS;
            }
            printf("\n--->>le Nome de film est  : %s",current->n);
            printf("\n--->>le titre de film est : %s",current->t);
            printf("\n--->>le dure de film est  : %d",current->d);
            printf("\n--->>le anne de film est  : %d\n",current->a);

        }

    }
}

//=====>>13

liste *suppr_position(liste *l, int p)
{
    if (l == NULL || p < 1 || p > l->nb) {
        printf("\n |==>Error : la position n'est pas valide !!! \n");
        return l;
    }

    if (p == 1) {  // Supprimer la tête de la liste
        Film* temp = l->tete;
        l->tete = l->tete->FS;
        free(temp);
        l->nb--;
        if (l->tete == NULL) {
            l->fin = NULL;
        }
    } else {
        Film* prec = l->tete;
        for (int i = 1; i < p-1; i++) {
            prec = prec->FS;
        }

        Film* temp = prec->FS;
        prec->FS = temp->FS;
        if (temp == l->fin) {
            l->fin = prec;
        }
        free(temp);
        l->nb--;
    }

    return l;
}

