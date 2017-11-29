//
// Created by guerocpa on 16/11/17.
//

#include "pile.h"

pile_t* pile_creer(int nb_places){
    if(nb_places <= 0){
        return NULL;
    }
    pile_t* pile = malloc(sizeof(pile_t));
    if(pile == NULL){
        return NULL;
    }

    pile->taille = nb_places;
    pile->sommet = -1;
    pile->iterateur = pile->sommet;
    pile->element = malloc(sizeof(double)*nb_places);
    if(pile->element == NULL){
        free(pile);
        return NULL;
    }

    return pile;
}

void pile_detruite(pile_t* p){
    free(p->element);
    free(p);
    return;
}

void pile_initialiser(pile_t* p){
    p->sommet = -1;
}

int pile_places_occupees(const pile_t* p){
    return p->sommet+1;
}

int pile_places_libres(const pile_t* p){
    return p->taille-(p->sommet+1);
}

inline int pile_depiler(pile_t * p, double * el){
    if( p->sommet == -1){
        return -1;
    }

    *el = p->element[p->sommet];
    p->sommet--;
    return 0;

}

inline int pile_empiler(pile_t * p, double el){
    if(p->taille == (p->sommet+1)){
        return -1;
    }

    p->sommet++;
    p->element[p->sommet] = el;

    return 0;
}

void pile_initialiser_iterateur(pile_t* p){
    p->iterateur = p->sommet;
}

int pile_obtenir_element_suivant(pile_t *p,double *el){
    if(p->iterateur == 0){
        return -1;
    }

    p->iterateur--;
    *el = p->element[p->iterateur];

    return 0;
}