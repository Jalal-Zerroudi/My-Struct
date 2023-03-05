#include "mon_fonction.h"
int main(void)
{
       liste *l;
       Film *f;

//------ creation une Film   ------>
    /*

        f=creation_film(f);
        afich_film(f);

    */
//------ creation une liste  ------>


        l=creation_liste();
        afich_liste(l);
        printf("\n====! 1\n");

//------ poue ajouter au tete ----->

	/*

        l=ajout_tete(l);
	    l=ajour_tete(l);
	    l=ajout_tete(l);

    */

//------ Pour ajouter au fin ------>

    /*

        l=ajout_fin(l);
        l=ajout_fin(l);
        l=ajout_fin(l);

    */

//------pour ajouter au Milio + position ------>

    /*
        int n;
        printf("\n >>>le nombre des eliment de la liste est %d \n",nombre_des_eliment(l));
        printf("\n --->>Entrer la position vous aver ajouter l'eliment :");
        scanf("%d",&n);

        l=ajout_Milio(l,n);

    */

//------- afiche la liste -------->

    /*

        system("clear");
        afich_liste(l);

    */
    return 0;
}
