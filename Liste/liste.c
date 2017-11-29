//
// Created by guerocpa on 16/11/17.
//
#include "liste.h"


node_t* list_create(void){

    return NULL;
}

inline void* list_get_data(const node_t* node){
    return node->val;
}

inline void list_set_data( node_t* node, void* data) {
    node->val = data;
}

node_t* list_insert(node_t* head, void* data){

    if(head == NULL){
        node_t* new = malloc(sizeof(node_t));
        if(new == NULL){
            return NULL;
        }

        new->next = NULL;
        new->val = data;

        return new;
    }

    node_t* new = malloc(sizeof(node_t));
    if(new == NULL){
        return NULL;
    }

    new->next = head;
    new->val = data;

    return new;
}


node_t* list_append(node_t* head, void* data){

    node_t* new = malloc(sizeof(node_t));
    if(new == NULL){
        return NULL;
    }

    if(head == NULL){
        new->next = NULL;
        new->val = data;

        return new;
    }

    node_t* parcours = head;

    while (parcours->next != NULL){
        parcours = parcours->next;
    }

    parcours->next = new;
    new->next = NULL;
    new->val= data;

    return head;
}

node_t* list_remove(node_t* head, void* data){
    node_t* parcours = head;
    node_t* precedent = NULL;

    if(head == NULL){
        return NULL;
    }

    if(head->val == data && head->next == NULL){
        free(head);
        return NULL;
    }

    while (parcours->next != NULL ){
        if(parcours->val == data){
            if(precedent == NULL){//Je suis en tête
                head = parcours->next;
                free(parcours);
                return head;
            }

            precedent->next = parcours->next;//Je suis entre 2 maillon
            free(parcours);

            return head;
        }
        precedent = parcours;
        parcours = parcours->next;

    }

    if(parcours->next == NULL && parcours->val == data) {//Je suis en queue
        precedent->next = NULL;
        free(parcours);
        return head;
    }


    return head;
}

node_t* list_head_remove(node_t* head){


    if(head == NULL){
        return NULL;
    }

    if(head->next == NULL){
        free(head);
        return NULL;
    }

    node_t* parcours = head;

    head = parcours->next;
    free(parcours);
    return head;
}

void list_destroy(node_t* head){

    if(head == NULL){
        return;
    }

    list_destroy(list_head_remove(head));
}

