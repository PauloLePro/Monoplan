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
    feuille.colonneslettre = COLONNESLETTRE;
    feuille.lignesnombre = LIGNESNOMBRE;

}

void analyse(s_cellule* cellule){

    double valeur = 0.0;
    cellule->nombreDePredecesseur = 0;
    cellule->token = list_create();
    cellule->valeur = 0.0;
    cellule->nombreDeToken = 0;
    cellule->nombreDeValeur = 0;
    cellule->nombreOperateur = 0;
    cellule->succeseursSommet = NULL;
    node_t *listeCelluleExistant = feuille.celluleExistant;
    s_cellule* c = NULL;
    s_cellule* tete = listeCelluleExistant->val;
    cellule->succeseursSommet = NULL;

    char testchar;
    int testint;
    double testdouble;

    char *chainecarac = strdup(cellule->chainecarac);

    char* tok = strtok(chainecarac," ");

    if(strcmp(tok,"=") == 0){//On regarde si c'est une opération

        while (tok != NULL) {

            valeur =strtod(tok, NULL);

            s_token *new = malloc(sizeof(s_token));
            if (new == NULL){
                return;
            }


            if (sscanf(tok, "%lf", &testdouble) == 1) {// On regarde si c'est un nombre

                new->type = VALUE;
                new->value.cst = valeur;
                cellule->token = list_append(cellule->token, new);

                cellule->nombreDeValeur++;
                cellule->nombreDeToken++;

            }

            for (int j = 0; j < NBOPERATEUR; ++j) {//On regarde si c'est un de nos opérateur connu

                if (strcmp(tok, operateur[j].nomoperation) == 0) {


                    new->type = OPERATOR;
                    new->value.operator = operateur[j].operator;
                    cellule->token = list_append(cellule->token, new);

                    cellule->nombreOperateur++;
                    cellule->nombreDeToken++;
                }
            }


            if((sscanf(tok,"%c%d",&testchar, &testint)==2) && (sscanf(tok,"%lf",&testdouble) != 1)){//On s'assure de sont format, puis de ce qu'il contient

                while (listeCelluleExistant->next != NULL) {

                    c = list_get_data(listeCelluleExistant);

                    if (strcmp(tok, c->nomcellule) == 0) {// On test si la référence existe déjà


                        new->type = REF;
                        new->value.ref = listeCelluleExistant->val;
                        cellule->token = list_append(cellule->token, new);
                        tete->refcellule = list_insert(tete->refcellule, cellule);

                        cellule->nombreDeValeur++;
                        cellule->nombreDeToken++;

                        c->succeseursSommet = list_insert(c->succeseursSommet, cellule->nomcellule);
                        cellule->nombreDePredecesseur++;
                    }

                    listeCelluleExistant = listeCelluleExistant->next;
                }

            }

            listeCelluleExistant = feuille.celluleExistant;
            tok = strtok(NULL, " ");

        }
    }

    return;
}

void evaluation(s_cellule* cellule){

    if(cellule->token == NULL){
        return;
    }

    if(((cellule->nombreDeValeur)-1) == cellule->nombreOperateur){

        s_token* token = NULL;
        s_cellule* celluleref;
        node_t* listetoken = cellule->token;
        pile_t* pile = pile_creer(cellule->nombreDeToken);

        for (int i = 0; i < cellule->nombreDeToken; ++i) {// On parcourt tout les tokens qu'on à obtenu grace à analyse
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

    }
    if(((cellule->nombreDeValeur)-1) != cellule->nombreOperateur){

        fprintf(stderr,"Error syntaxe cellule: \"%s\"\n",cellule->nomcellule);
        return ;
    }

    return;
}

void graphedevaluation(s_cellule* cellule){

    if(cellule->succeseursSommet == NULL){
        return;
    }

    node_t* celluleAEvaluer = NULL;
    node_t *listeCelluleExistant = feuille.celluleExistant;
    s_cellule* tmp = NULL;

    while(cellule->succeseursSommet != NULL) {

        celluleAEvaluer = list_append(celluleAEvaluer, cellule->succeseursSommet->val);

        cellule->succeseursSommet = cellule->succeseursSommet->next;
    }

    celluleAEvaluer


    while(celluleAEvaluer->next != NULL) {

        analyse(&tmp);
        evaluation(&tmp);

        celluleAEvaluer = celluleAEvaluer->next;
    }

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

    result = b-a;

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