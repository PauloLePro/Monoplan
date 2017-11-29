//
// Created by guerocpa on 16/11/17.
//
#ifndef MONOPLAN_PILE_H
#define MONOPLAN_PILE_H

#include <stdlib.h>
#include <stdio.h>

typedef struct pile{
    double *element;
    int taille;
    int sommet;
    int iterateur;

}pile_t;

pile_t* pile_creer(int nb_places);
void pile_detruite(pile_t* p);
void pile_initialiser(pile_t* p);
int pile_places_occupees(const pile_t* p);
int pile_places_libres(const pile_t* p);
int pile_depiler(pile_t * p, double * el);
int pile_empiler(pile_t * p, double el);
void pile_initialiser_iterateur(pile_t * p);
int pile_obtenir_element_suivant(pile_t *p,double *el);

#endif //MONOPLAN_PILE_H
