//
// Created by guerocpa on 23/11/17.
//

#include "cellule.h"

operateur_t operateur[4];

void init(){

    operateur[0].nomoperation = "+";
    operateur[0].operator = &addition;

    operateur[1].nomoperation = "*";
    operateur[1].operator = &multiplication;

    operateur[2].nomoperation = "-";
    operateur[2].operator = &soustraction;

    operateur[3].nomoperation = "/";
    operateur[3].operator = &division;

}



void analyse(feuille_t* feuille,s_cellule* cellule){

    double valeur = 0;

    char* tok = strtok(cellule->chainecarac," ");

    while (tok != NULL){

        valeur = strtod(tok,NULL);

        if(valeur != 0.0){
            s_token* new = malloc(sizeof(s_token));
            new->type = VALUE;
            new->value.cst = valeur;

            cellule->token = list_insert(cellule->token,new);
        }

        for (int j = 0; j < 4; ++j) {

            if(strcmp(tok, operateur[j].nomoperation)==0){
                s_token* new = malloc(sizeof(s_token));
                new->type = OPERATOR;
                new->value.operator = operateur[j].operator;

                cellule->token = list_insert(cellule->token,new);
            }
        }

        while(feuille->celluleExistant->next != NULL){
            if(strcmp(tok, cellule->nomcellule)==0){
                s_token* new = malloc(sizeof(s_token));
                new->type = REF;
                new->value.ref = cellule->refcellule->val;

                cellule->token = list_insert(cellule->token,new);
            }
        }

        tok = strtok(NULL," ");
    }

    return;
}

/*void evalutation(s_cellule* cellule){

    while(cellule->token->next != NULL){
        if(cellule->token->val ==)
    }
}*/

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

