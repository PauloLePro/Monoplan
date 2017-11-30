//
// Created by guerocpa on 23/11/17.
//

#include "cellule.h"

operateur_t operateur[4];
feuille_t feuille;

void initialisationOperateur(){

    operateur[0].nomoperation = "+";
    operateur[0].operator = &addition;

    operateur[1].nomoperation = "*";
    operateur[1].operator = &multiplication;

    operateur[2].nomoperation = "-";
    operateur[2].operator = &soustraction;

    operateur[3].nomoperation = "/";
    operateur[3].operator = &division;



    feuille.nomfeuille = "feuilletest";
    feuille.colonneslettre = 26;
    feuille.lignesnombre = 50;

}



void analyse(s_cellule* cellule){

    double valeur = 0.0;
    cellule->token = list_create();
    cellule->valeur = 0.0;
    cellule->nombreDeToken = 0;

    char *chainecarac = strdup(cellule->chainecarac);

    char* tok = strtok(chainecarac," ");

    if(strcmp(tok,"=") == 0){

        while (tok != NULL) {

            valeur =strtod(tok, NULL);

            s_token *new = malloc(sizeof(s_token));
            if (new == NULL){
                return;
            }


            if (valeur != 0.0) {

                new->type = VALUE;
                new->value.cst = valeur;
                cellule->token = list_insert(cellule->token, new);

                cellule->nombreDeToken++;

            }

            for (int j = 0; j < 4; ++j) {

                if (strcmp(tok, operateur[j].nomoperation) == 0) {


                    new->type = OPERATOR;
                    new->value.operator = operateur[j].operator;

                    cellule->token = list_insert(cellule->token, new);
                    cellule->nombreDeToken++;
                }
            }

            while (feuille.celluleExistant->next != NULL) {

                if (strcmp(tok, cellule->nomcellule) == 0) {

                    new->type = REF;
                    new->value.ref = cellule->refcellule->val;

                    cellule->token = list_insert(cellule->token, new);
                    cellule->nombreDeToken++;
                }
            }

            tok = strtok(NULL, " ");
        }
    }

    return;
}

void evalutation(s_cellule* cellule){

    if(cellule->token == NULL){
        return;
    }

    pile_t* pile = pile_creer(cellule->nombreDeToken);

    for (int i = 0; i < cellule->nombreDeToken; ++i) {
        

    }
}

void addition(pile_t* pile){
    double a , b, result;

    pile_depiler(pile,&a);
    pile_depiler(pile,&b);

    result = a+b;

    pile_empiler(pile,result);

    return;
}

void multiplication(pile_t* pile){

    double a , b, result;

    pile_depiler(pile,&a);
    pile_depiler(pile,&b);

    result = a*b;

    pile_empiler(pile,result);

    return;
}

void soustraction(pile_t* pile){

    double a, b, result;

    pile_depiler(pile,&a);
    pile_depiler(pile,&b);

    result = a-b;

    pile_empiler(pile,result);

    return;
}

void division(pile_t* pile){

    double a , b, result;

    pile_depiler(pile,&a);
    pile_depiler(pile,&b);

    result = b/a;

    pile_empiler(pile,result);

    return;
}

