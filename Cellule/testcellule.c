//
// Created by guerocpa on 27/11/17.
//

#include "cellule.h"

int main(){

    init();

    feuille_t* feuille;
    s_cellule* cellule;

    cellule->chainecarac = "5 6 +";

    feuille->celluleExistant = list_insert(feuille->celluleExistant,&cellule);

    analyse(&feuille,&cellule);

    return 0;
}