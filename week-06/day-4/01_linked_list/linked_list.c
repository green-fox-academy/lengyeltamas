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
    new_node->value = value;
    new_node->next = NULL;

    linked_list_node_t *it = linked_list;
    while(it->next != NULL){
        it = it->next;
    }
    it->next = new_node;
}

void linked_list_print(linked_list_node_t *lined_list)
{
    linked_list_node_t *it = lined_list;
    while(it != NULL){
        printf("%p: %d\n", it, it->value);
        it = it->next;
    }
}

void linked_list_dealloc(linked_list_node_t *linked_list)
{
    linked_list_node_t *node_to_free = linked_list;
    while(node_to_free != NULL){
        linked_list_node_t *next_node = node_to_free->next;
        free(node_to_free);
        node_to_free = next_node;
    }
}

linked_list_node_t* linked_list_insert_to_beginning(linked_list_node_t *linked_list, int value)
{
    linked_list_node_t *first_node = (linked_list_node_t*)malloc(sizeof(linked_list_node_t));
    first_node->value = value;
    first_node->next = linked_list;
    return first_node;
}

linked_list_node_t *insert_after(linked_list_node_t *linked_list, int value)
{
    linked_list_node_t *inserted_node = (linked_list_node_t*)malloc(sizeof(linked_list_node_t));
    inserted_node->value = value;
    linked_list_node_t *temp_pointer = linked_list->next->next->next->next->next;
    linked_list->next->next->next->next->next = inserted_node;
    inserted_node->next = temp_pointer;
    return linked_list;
}

