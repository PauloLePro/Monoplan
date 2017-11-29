//
// Created by paulolepro on 27/11/17.
//

#include "pile.h"

int main(){
    pile_t *pile;
    double a;

    pile = pile_creer(10);
    pile_initialiser(pile);
    pile_initialiser_iterateur(pile);

    if(pile_places_libres(pile) != 10)return printf("erreur la place libres dans la pile est de 10\n");
    if(pile_places_occupees(pile) != 0)return printf("erreur la place occupées dans la pile est de 0\n");

    for (double i = 0.0; i < 10; i++) {
        if(pile_empiler(pile,i) != 0)return printf("erreur pile pleine");
    }

    if(pile_places_libres(pile) != 0)return printf("erreur la place libres dans la pile est de 0\n");
    if(pile_places_occupees(pile) != 10)return printf("erreur la place occupées dans la pile est de 10\n");


    for (double i = 0.0; i < 5; i++) {//11
        if(pile_depiler(pile,&a) != 0)return printf("erreur pile est vide");

        //printf("%f\n",a);
    }

    if(pile_places_occupees(pile) != 5)return printf("erreur la place occupées dans la pile est de 5\n");

    pile_initialiser_iterateur(pile);

    for (int i = 0; i < 4; i++) {//5
        if (pile_obtenir_element_suivant(pile, &a) != 0)return printf("On ne peut plus avancer dans la pile\n");

        //printf("%f\n",a);
    }

    pile_detruite(pile);

    return 0;
}