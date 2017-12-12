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



    initialisationOperateur();

    s_cellule cellule;
    char* chainecarac= "= 2 3 +";
    cellule.nomcellule = "A1";
    cellule.chainecarac = chainecarac;
    feuille.celluleExistant = list_append(feuille.celluleExistant,&cellule);

    analyse(&cellule);
    evaluation(&cellule);

    printf("%s %s\n",cellule.nomcellule,cellule.chainecarac);
    printf("%lf\n",cellule.valeur);

    s_cellule cellule1;
    char* chainecarac1= "= 12 A1 -";
    cellule1.nomcellule = "A2";
    cellule1.chainecarac = chainecarac1;
    feuille.celluleExistant = list_append(feuille.celluleExistant,&cellule1);

    analyse(&cellule1);
    evaluation(&cellule1);

    printf("%s %s\n",cellule1.nomcellule,cellule1.chainecarac);
    printf("%lf\n",cellule1.valeur);

    s_cellule cellule2;
    char* chainecarac2= "= A2 18 +";
    cellule2.nomcellule = "A3";
    cellule2.chainecarac = chainecarac2;
    feuille.celluleExistant = list_append(feuille.celluleExistant,&cellule2);

    analyse(&cellule2);
    evaluation(&cellule2);


    printf("%s %s\n",cellule2.nomcellule,cellule2.chainecarac);
    printf("%lf\n",cellule2.valeur);


    s_cellule cellule3;
    char* chainecarac3= "= 2 A2 +";
    cellule3.nomcellule = "A4";
    cellule3.chainecarac = chainecarac3;
    feuille.celluleExistant = list_append(feuille.celluleExistant,&cellule3);

    analyse(&cellule3);
    evaluation(&cellule3);

    printf("%s %s\n",cellule3.nomcellule,cellule3.chainecarac);
    printf("%lf\n",cellule3.valeur);


    s_cellule cellule4;
    char* chainecarac4= "= A3 A4 +";
    cellule4.nomcellule = "A5";
    cellule4.chainecarac = chainecarac4;
    feuille.celluleExistant = list_append(feuille.celluleExistant,&cellule4);

    analyse(&cellule4);
    evaluation(&cellule4);

    printf("%s %s\n",cellule4.nomcellule,cellule4.chainecarac);
    printf("%lf\n",cellule4.valeur);


    printf("\n");
    printf("nb predecesseur de A1: %d\n",cellule.nombreDePredecesseur);

    printf("nb predecesseur de A2: %d\n",cellule1.nombreDePredecesseur);

    printf("nb predecesseur de A3: %d\n",cellule2.nombreDePredecesseur);

    printf("nb predecesseur de A4: %d\n",cellule3.nombreDePredecesseur);

    printf("nb predecesseur de A5: %d\n",cellule4.nombreDePredecesseur);
    printf("\n");

    printf("\n");
    printf("A1 à comme successeur :%s\n", cellule.succeseursSommet->val);
    printf("A2 à comme successeur :%s %s\n", cellule1.succeseursSommet->val,cellule1.succeseursSommet->next->val);
    printf("A3 à comme successeur :%s\n", cellule2.succeseursSommet->val);
    printf("A4 à comme successeur :%s\n", cellule3.succeseursSommet->val);
    if(cellule3.succeseursSommet != NULL)
        printf("A5 à comme successeur : null");


    graphedevaluation(&cellule);

    printf("\n");

    chainecarac= "= 100 25 +";
    cellule.chainecarac = chainecarac;
    analyse(&cellule);
    evaluation(&cellule);

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

    graphedevaluation(feuille.celluleExistant);

    printf("\n");
    printf("nb predecesseur de A1: %d\n",cellule.nombreDePredecesseur);

    printf("\n");
    printf("nb predecesseur de A2: %d\n",cellule1.nombreDePredecesseur);

    printf("\n");
    printf("nb predecesseur de A3: %d\n",cellule2.nombreDePredecesseur);

    printf("\n");
    printf("nb predecesseur de A4: %d\n",cellule3.nombreDePredecesseur);

    printf("\n");
    printf("nb predecesseur de A5: %d\n",cellule4.nombreDePredecesseur);
*/
    initialisationOperateur();

    s_cellule d3;
    char* chainecarac= "= 5 5 +";
    d3.nomcellule = "D3";
    d3.chainecarac = chainecarac;
    feuille.celluleExistant = list_append(feuille.celluleExistant,&d3);
    analyse(&d3);
    evaluation(&d3);


    s_cellule d2;
    char* chainecarac2= "= 5 5 +";
    d2.nomcellule = "D2";
    d2.chainecarac = chainecarac2;
    feuille.celluleExistant = list_append(feuille.celluleExistant,&d2);
    analyse(&d2);
    evaluation(&d2);

    s_cellule a4;
    char* chainecarac3= "= D3";
    a4.nomcellule = "A4";
    a4.chainecarac = chainecarac3;
    feuille.celluleExistant = list_append(feuille.celluleExistant,&a4);
    analyse(&a4);
    evaluation(&a4);


    s_cellule a5;
    char* chainecarac4= "= D3 A4 +";
    a5.nomcellule = "A5";
    a5.chainecarac = chainecarac4;
    feuille.celluleExistant = list_append(feuille.celluleExistant,&a5);
    analyse(&a5);
    evaluation(&a5);

    s_cellule c5;
    char* chainecarac5= "= D2 A5 +";
    c5.nomcellule = "C5";
    c5.chainecarac = chainecarac5;
    feuille.celluleExistant = list_append(feuille.celluleExistant,&c5);
    analyse(&c5);
    evaluation(&c5);

    printf("successeurs de D3 : %s %s\n", d3.succeseursSommet->val, d3.succeseursSommet->next->val);
    printf("successeurs de D2 : %s\n", d2.succeseursSommet->val);
    printf("successeurs de A4 : %s\n", a4.succeseursSommet->val);
    printf("successeurs de A5 : %s\n", a5.succeseursSommet->val);

    return 0;
}