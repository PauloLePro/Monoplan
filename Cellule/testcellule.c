//
// Created by guerocpa on 27/11/17.
//

#include "cellule.h"

int main(){

    initialisationOperateur();

    s_cellule cellule;
    char* chainecarac= "= 2 3 +";

    cellule.nomcellule = "F3";

    cellule.chainecarac = chainecarac;

    feuille.celluleExistant = list_insert(feuille.celluleExistant,&cellule);

    analyse(&cellule);
    evaluation(&cellule);

    printf("%s\n",cellule.chainecarac);
    printf("%lf\n",cellule.valeur);

    return 0;
}