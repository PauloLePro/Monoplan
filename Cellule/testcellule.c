//
// Created by guerocpa on 27/11/17.
//

#include "cellule.h"

int main(){
/*
    initialisationOperateur();

    s_cellule cellule;
    char* chainecarac= "= 5 2 3 + *";
    cellule.nomcellule = "F3";
    cellule.chainecarac = chainecarac;
    feuille.celluleExistant = list_append(feuille.celluleExistant,&cellule);

    analyse(&cellule);
    evaluation(&cellule);

    if(strcmp(cellule.chainecarac,chainecarac) != 0){
        printf("Erreur le nom de la cellule devrait être :%s\n",chainecarac);
    }
    if(cellule.valeur != 25){//2 + 3 = 5 // 5 * 5 = 25
        printf("Erreur la valeur de la cellule devrait être : 25\n");
    }


    s_cellule cellule1;
    char* chainecarac1= "= 200 F3 12 * -";
    cellule1.nomcellule = "F1";
    cellule1.chainecarac = chainecarac1;
    feuille.celluleExistant = list_append(feuille.celluleExistant,&cellule1);

    analyse(&cellule1);
    evaluation(&cellule1);

    if(strcmp(cellule1.chainecarac,chainecarac1) != 0){
        printf("Erreur le nom de la cellule devrait être :%s\n",chainecarac1);
    }
    if(cellule1.valeur != 100){// 25 * 12 = 300 // 300- 200 = 100
        printf("Erreur la valeur de la cellule devrait être : 100\n");
    }

    s_cellule cellule2;
    char* chainecarac2= "= F1 2 /";
    cellule2.nomcellule = "F6";
    cellule2.chainecarac = chainecarac2;
    feuille.celluleExistant = list_append(feuille.celluleExistant,&cellule2);

    analyse(&cellule2);
    evaluation(&cellule2);

    if(strcmp(cellule2.chainecarac,chainecarac2) != 0){
        printf("Erreur le nom de la cellule devrait être :%s\n",chainecarac2);
    }
    if(cellule2.valeur != 50){//100 / 2 = 50
        printf("Erreur la valeur de la cellule devrait être : 50\n");
    }



    s_cellule cellule3;
    char* chainecarac3= "Test de titre";
    cellule3.nomcellule = "F7";
    cellule3.chainecarac = chainecarac3;
    feuille.celluleExistant = list_append(feuille.celluleExistant,&cellule3);

    analyse(&cellule3);
    evaluation(&cellule3);

    if(strcmp(cellule3.chainecarac,chainecarac3) != 0){
        printf("Erreur le nom de la cellule devrait être :%s\n",chainecarac3);
    }
    if(cellule3.valeur != 0){
        printf("Erreur la valeur de la cellule devrait être : 0\n");
    }

    s_cellule cellule4;
    char* chainecarac4= "= 0 2 +";
    cellule4.nomcellule = "F12";
    cellule4.chainecarac = chainecarac4;
    feuille.celluleExistant = list_append(feuille.celluleExistant,&cellule4);

    analyse(&cellule4);
    evaluation(&cellule4);

    if(strcmp(cellule4.chainecarac,chainecarac4) != 0){
        printf("Erreur le nom de la cellule devrait être :%s\n",chainecarac4);
    }
    if(cellule4.valeur != 2){
        printf("Erreur la valeur de la cellule devrait être : 2\n");
    }



    printf("%s\n",cellule.chainecarac);
    printf("%lf\n",cellule.valeur);

    printf("%s\n",cellule1.chainecarac);
    printf("%lf\n",cellule1.valeur);

    printf("%s\n",cellule2.chainecarac);
    printf("%lf\n",cellule2.valeur);

    printf("%s\n",cellule3.chainecarac);
    printf("%lf\n",cellule3.valeur);

    printf("%s\n",cellule4.chainecarac);
    printf("%lf\n",cellule4.valeur);
*/


    initialisationOperateur();

    s_cellule cellule;
    char* chainecarac= "= 2 3 +";
    cellule.nomcellule = "A1";
    cellule.chainecarac = chainecarac;
    feuille.celluleExistant = list_append(feuille.celluleExistant,&cellule);

    analyse(&cellule);
    evaluation(&cellule);

    printf("%s\n",cellule.chainecarac);
    printf("%lf\n",cellule.valeur);


    s_cellule cellule1;
    char* chainecarac1= "= 12 A1 -";
    cellule1.nomcellule = "A2";
    cellule1.chainecarac = chainecarac1;
    feuille.celluleExistant = list_append(feuille.celluleExistant,&cellule1);

    analyse(&cellule1);
    evaluation(&cellule1);

    printf("%s\n",cellule1.chainecarac);
    printf("%lf\n",cellule1.valeur);


    s_cellule cellule2;
    char* chainecarac2= "= A1 A2 +";
    cellule2.nomcellule = "A3";
    cellule2.chainecarac = chainecarac2;
    feuille.celluleExistant = list_append(feuille.celluleExistant,&cellule2);

    analyse(&cellule2);
    evaluation(&cellule2);


    printf("%s\n",cellule2.chainecarac);
    printf("%lf\n",cellule2.valeur);

/*
    s_cellule cellule3;
    char* chainecarac3= "= 2 A2 +";
    cellule3.nomcellule = "A4";
    cellule3.chainecarac = chainecarac3;
    feuille.celluleExistant = list_append(feuille.celluleExistant,&cellule3);

    analyse(&cellule3);
    evaluation(&cellule3);


    s_cellule cellule4;
    char* chainecarac4= "= A1 2 +";
    cellule4.nomcellule = "A5";
    cellule4.chainecarac = chainecarac4;
    feuille.celluleExistant = list_append(feuille.celluleExistant,&cellule4);

    analyse(&cellule4);
    evaluation(&cellule4);


    printf("%s\n",cellule3.chainecarac);
    printf("%lf\n",cellule3.valeur);

    printf("\n");
    printf("nb predecesseur de A1: %d\n",cellule.nombreDePredecesseur);


    printf("\n");
    printf("nb predecesseur de A2: %d\n",cellule1.nombreDePredecesseur);
*/
    return 0;
}