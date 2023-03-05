#include <stdbool.h>  // true or false <==> 1 or 0
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <conio.h>


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

//---------->> la declaraton des fonctions :

//====>>1

Film* creation_film(Film *f)
{
    f=(Film*)malloc(sizeof(Film));
	if(Film_est_vid(f)==1) printf("\n |==>Error : Film n'est pas exit !!!");
	else{
    	printf("\n>>>Enter les information de nouvel film :\n");

			printf("\n   --->Enter le nom de film   :");
    		scanf("%s",f->n);

    		printf("\n   --->Enter le titre de film :");
    		scanf("%s",f->t);

    		printf("\n   --->Enter l'anner de film  :");
    		scanf("%d",&f->a);

    		printf("\n   --->Enter le dure de film  :");
    		scanf("%d",&f->d);
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
        l->nb++;
        Film *f = creation_film(NULL);
        if (Film_est_vid(f)) {
            printf("\n |==>Error : Film n'est pas exit !!!\n");
            free(f);
            break;
        }
        if (l->tete == NULL) {
            l->tete = f;
            l->fin = f;
        } else {
            l->fin->FS = f;
            l->fin = f;
        }
        printf("\n si vous avez ajouter un autre élément cliquez sur >y< ou >Y< :");
        c = getche();
    } while (c == 'y' || c == 'Y');
        l->fin->FS=NULL;
    return l;
}

//====>>5

int liste_est_vid(liste*l)
{
	if(l->tete==NULL || l->nb==0 ) return 1;
	else return 0;
}

//====>>6

void afich_liste(liste *l)
{
    if(liste_est_vid(l)==1) printf("la liste est vide ");
    else{
    l->fin= l->tete;
        do
        {
            printf("\n--->>le Nome de film est  : %s .",l->fin->n);
            printf("\n--->>le titre de film est : %s .",l->fin->t);
            printf("\n--->>le dure de film est  : %d .",l->fin->d);
            printf("\n--->>le anne de film est  : %d .",l->fin->a);
            printf("\n|------->>\n");
            l->fin=l->fin->FS;

        } while (l->fin != NULL);
}
}
//====>>7

liste *inverse_ordre(liste *l)
{
    if(liste_est_vid(l)==0) printf("\n |==>Error : la liste est vide !!! \n");
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
    Film *f;
	f=(Film*)malloc(sizeof(Film));

	creation_film(f);

    f->FS=l->tete;
    l->tete=f;

    return l;
}

//====>>9

liste *ajout_fin(liste *l)
{
    Film *f=(Film*)malloc(sizeof(Film));

    creation_film(f);

    if(l->tete == NULL)
    {
        l->tete=f;
    }
    else{

        l->fin=l->tete;

        while (l->fin->FS != NULL)
        {
            l->fin=l->fin->FS;
        }

        f->FS=NULL;
        l->fin->FS=f;
    }

    return l;
}

//====>>10

liste *ajout_Milio(liste *l,int n)
{
    int m=nombre_des_eliment(l);
	if(l->tete== NULL) printf("\n >>> Votre liste est vide<<<\n");
	else{
		if(n>m)
		{
			system("cls");
			printf("\n >>>la position n'est pas exit dan votre liste<<< \n");
		}
		else{

			Film *f=NULL;
			f=(Film*)malloc(sizeof(Film));

			creation_film(f);

    		l->fin=l->tete;

    		int i=1;

    		for(i=1;i<n;i++)
    		{
    			l->fin=l->fin->FS;
			}
    		f->FS=l->fin->FS;
    		l->fin->FS=f;
			}
		}

	return l;
}
//=====>>11
int nombre_des_eliment(liste *l)
{
    int i=0;
    l->fin=l->tete;
    while (l->fin !=NULL)
    {
        l->fin=l->fin->FS;
        i++;
    }
    return i;
}
//=====>>12

void afich_elemient_position(liste *l,int p)
{
    int m=nombre_des_eliment(l);
    if(l->tete==NULL)
    {
        system("clear");
        printf("\n >>> Votre liste est vide. \n");
    }
    else{
        if (p>m)
        {
            system("clear");
            printf("\n >>>la position vous aver chisi n'est pas exit dan la liste la sit admen %d eliment\n",m);
        }
        else{
            l->fin=l->tete;
            int i=1;
            for ( i = 1; i <= p; i++)
            {
                l->fin=l->fin->FS;
            }
            printf("\n--->>le Nome de film est  : %s",l->fin->n);
            printf("\n--->>le titre de film est : %s",l->fin->t);
            printf("\n--->>le dure de film est  : %d",l->fin->d);
            printf("\n--->>le anne de film est  : %d\n",l->fin->a);

        }

    }
}

//=====>>13

liste *suppr_position(liste *l, int p)
{
    if (p < 1 || p > l->nb) {
        printf("\n |==>Error : la position n'est pas valide !!! \n");
        return l;
    }

    if (p == 1) {  // Supprimer la tête de la liste
        Film* temp = l->tete;
        l->tete = l->tete->FS;
        free(temp);
        l->nb--;
    } else {
        Film* prec = l->tete;
        for (int i = 1; i < p-1; i++) {
            prec = prec->FS;
        }

        Film* temp = prec->FS;
        prec->FS = prec->FS->FS;
        free(temp);
        l->nb--;
    }

    return l;
}

