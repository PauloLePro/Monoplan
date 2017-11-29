//
// Created by guerocpa on 16/11/17.
//
#ifndef MONOPLAN1_LISTE_H
#define MONOPLAN1_LISTE_H

#include <stdlib.h>
#include <stdio.h>

typedef struct node{
    void* val;
    struct node* next;
}node_t;

node_t* list_create(void);
void* list_get_data(const node_t* node);
void list_set_data( node_t* node, void* data);
node_t* list_insert(node_t* head, void* data);
node_t* list_append(node_t* head, void* data);
node_t* list_remove(node_t* head, void* data);
node_t* list_head_remove(node_t* head);
void list_destroy(node_t* head);

#endif //MONOPLAN1_LISTE_H