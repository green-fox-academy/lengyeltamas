#include <stdio.h>
#include <malloc.h>
#include "linked_list.h"

linked_list_node_t *create()
{
    linked_list_node_t *linked_list = (linked_list_node_t*)malloc(sizeof(linked_list_node_t));

    linked_list->value = 0;
    linked_list->next = NULL;

    return linked_list;
}

void linked_list_push_back(linked_list_node_t *linked_list, int value)
{
    linked_list_node_t *new_node = (linked_list_node_t*)malloc(sizeof(linked_list_node_t));
    linked_list->value = value;
    linked_list->next = NULL;

    linked_list_node_t *it = linked_list;
    while(it->next != NULL){
        it = it->next;
    }

    it->next = new_node;
}