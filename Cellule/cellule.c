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
    node_t *listeCelluleExistant = feuille.celluleExistant;
    s_cellule* c = NULL;
    s_cellule* dep = listeCelluleExistant->val;

    char testchar;
    int testint;
    double testdouble;

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
                cellule->token = list_append(cellule->token, new);

                cellule->nombreDeToken++;

            }

            for (int j = 0; j < 4; ++j) {

                if (strcmp(tok, operateur[j].nomoperation) == 0) {


                    new->type = OPERATOR;
                    new->value.operator = operateur[j].operator;

                    cellule->token = list_append(cellule->token, new);
                    cellule->nombreDeToken++;
                }
            }


            if((sscanf(tok,"%c%d",&testchar, &testint)==2) && (sscanf(tok,"%lf",&testdouble) != 1)){

                while (listeCelluleExistant->next != NULL) {

                    c = list_get_data(listeCelluleExistant);

                    if (strcmp(tok, c->nomcellule) == 0) {


                        new->type = REF;
                        new->value.ref = listeCelluleExistant->val;
                        cellule->token = list_append(cellule->token, new);
                        dep->refcellule = list_insert(dep->refcellule, cellule);
                        cellule->nombreDeToken++;
                    }

                    listeCelluleExistant = listeCelluleExistant->next;
                }

            }

            tok = strtok(NULL, " ");

        }
    }

    return;
}

void evaluation(s_cellule* cellule){

    if(cellule->token == NULL){
        return;
    }

    s_token* token = NULL;
    s_cellule* celluleref;
    node_t* listetoken = cellule->token;
    pile_t* pile = pile_creer(cellule->nombreDeToken);

    for (int i = 0; i < cellule->nombreDeToken; ++i) {
        token = list_get_data(listetoken);

        if(token->type == VALUE){
            pile_empiler(pile, token->value.cst);
        }
        if(token->type == REF){
            celluleref = token->value.ref;
            pile_empiler(pile,celluleref->valeur);
        }
        if(token->type == OPERATOR){
            token->value.operator(pile);
        }

        listetoken = listetoken->next;
    }

    pile_depiler(pile,&cellule->valeur);

    return;
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