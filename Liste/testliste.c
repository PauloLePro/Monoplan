//
// Created by paulolepro on 27/11/17.
//

#include "liste.h"

int main(){
    node_t* tete;
    tete = list_create();

    if(tete != NULL){
        return printf("la liste doit être null\n");
    }

    tete = list_insert(tete,(void*)1);


    if(tete == NULL){
        return printf("erreur lors de la création du maillon.\n");
    }

    for (int i = 1; i < 11; i++){
        tete = list_insert(tete,(void*)i);
        if(tete == NULL){
            return printf("erreur la valeur de la tête est :%d\n",list_get_data(tete));
        }
    }

    while(tete != NULL){
        tete = list_head_remove(tete);
    }

    list_destroy(tete);



    node_t* tete2;
    tete2 = list_create();

    if(tete2 != NULL){
        return printf("la liste doit être null\n");
    }

    tete2 = list_append(tete2,(void*)1);

    for (int i = 1; i < 11; i++){
        tete2 = list_append(tete2,(void*)i);
        if(tete2 == NULL){
            return printf("erreur la valeur de la tête est :%d\n",list_get_data(tete2));
        }
    }

    list_set_data(tete2,(void*)12);
    if(tete2->val != 12)
    {
        return printf("La valeur attendu est 12 est non :%d\n",list_get_data(tete2));
    }

    tete2 = list_remove(tete2,(void*)12);
    if(tete2->val != 1){
        return printf("La valeur attendu est 1 est non :%d\n",list_get_data(tete2));
    }

    tete2 = list_remove(tete2,(void*)5);
    if(tete2->val != 1){
        return printf("La valeur attendu est 1 est non :%d\n",list_get_data(tete2));
    }

    tete2 = list_remove(tete2,(void*)10);

    node_t* parcours = tete2;

    while (parcours->next != NULL){
        parcours = parcours->next;
    }
    if(parcours->val != 9){
        return printf("La valeur attendu est 9\n");
    }
    free(parcours);

    tete2 = list_head_remove(tete2);
    if(tete2->val != 2){
        return printf("La valeur attendu est 2\n");
    }

    list_destroy(tete2);

    return 0;
}