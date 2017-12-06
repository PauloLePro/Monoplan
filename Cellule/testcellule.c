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
    feuille.celluleExistant = list_append(feuille.celluleExistant,&cellule);

    analyse(&cellule);
    evaluation(&cellule);

    printf("%s\n",cellule.chainecarac);
    printf("%lf\n",cellule.valeur);

    s_cellule cellule1;
    char* chainecarac1= "= F3 12 +";
    cellule1.nomcellule = "F1";
    cellule1.chainecarac = chainecarac1;
    feuille.celluleExistant = list_append(feuille.celluleExistant,&cellule1);

    analyse(&cellule1);
    evaluation(&cellule1);

    printf("%s\n",cellule1.chainecarac);
    printf("%lf\n",cellule1.valeur);

    s_cellule cellule2;
    char* chainecarac2= "= F1 12 +";
    cellule2.nomcellule = "F6";
    cellule2.chainecarac = chainecarac2;
    feuille.celluleExistant = list_append(feuille.celluleExistant,&cellule2);

    analyse(&cellule2);
    evaluation(&cellule2);

    printf("%s\n",cellule2.chainecarac);
    printf("%lf\n",cellule2.valeur);


    return 0;
}