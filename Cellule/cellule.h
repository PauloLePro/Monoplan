//
// Created by guerocpa on 23/11/17.
//

#ifndef MONOPLAN_CELLULE_H
#define MONOPLAN_CELLULE_H

#include <stdlib.h>
#include <stdio.h>
#include <string.h>

#include "../Pile/pile.h"
#include "../Liste/liste.h"

typedef struct cellule{
    char* nomcellule;
    char *chainecarac;
    double valeur;
    node_t* token;
    node_t* refcellule;

    int nombreDeToken;
}s_cellule;

typedef struct operateur{
    char *nomoperation;
    void (*operator)(pile_t* element);
}operateur_t;

typedef struct token{
    enum {VALUE,REF,OPERATOR} type;
    union {
        double cst;
        s_cellule* ref;
        void(*operator)(pile_t* eval);
    }value;
}s_token;

typedef struct feuille{
    char *nomfeuille;
    int lignesnombre;
    int colonneslettre;
    node_t* celluleExistant;
}feuille_t;


void addition(pile_t* pile);
void multiplication(pile_t* pile);
void soustraction(pile_t* pile);
void division(pile_t* pile);

extern operateur_t operateur[4];
extern feuille_t* feuille;

void initialisationOperateur();
void analyse(s_cellule* cellule);
void evaluation(s_cellule* cellule);

#endif //MONOPLAN_CELLULE_H
