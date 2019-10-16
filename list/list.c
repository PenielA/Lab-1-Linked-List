// list/list.c
// 
// Implementation for linked list.
//
// <Author>

#include <stdio.h>

#include "list.h"
/* Functions for allocating and freeing lists. By using only these functions,
 * the user should be able to allocate and free all the memory required for
 * this linked list library. */
list_t *list_alloc() { 
    node_t* new_node;
    list_t* new_list;
    new_node = malloc(sizeof(node_t)); 
    new_list->head = new_node;
    return new_list;
}
void list_free(list_t *l) {
    free(l);
}
/* Prints the list in some format. */
void list_print(list_t *l) {
    node_t *current_node = l->head;
    while(current_node != NULL){
        printf("%d", current_node->value);
        current_node = current_node->next;
    }
}
/* Returns the length of the list. */
int list_length(list_t *l) { 
    node_t *current_node = l->head;
    int length = 0;
    while(current_node != NULL){
        length++;
        current_node = current_node->next;
    }
    return length;
}
/* Methods for adding to the list. */
void list_add_to_back(list_t *l, elem value) {
    node_t *current_node = l->head;
    node_t *new_node;
    new_node->value = NULL;
    while(current_node->next != NULL){
        current_node = current_node->next;
    }
    current_node->next = new_node;
}
void list_add_to_front(list_t *l, elem value) {
    node_t *new_node;
    new_node->value = value;
    new_node->next = l->head;
    l->head = new_node;
}
void list_add_at_index(list_t *l, elem value, int index) {
    node_t *new_node;
    new_node->value = value;
    new_node->next = l->head;
    node_t *current_node = l->head;
    node_t *previous_node = NULL;
    int position = 0;
    while(position < index){
        previous_node = current_node;
        current_node = current_node->next;
        position++;
    }
    new_node->next = current_node;
    previous_node->next = new_node;
}
/* Methods for removing from the list. Returns the removed element. */
elem list_remove_from_back(list_t *l) {
    int removed_element = 0;
    node_t *current_node = l->head;
    node_t *previous_node = NULL;
    while(current_node->next != NULL){
        previous_node = current_node;
        current_node = current_node->next;
    }
    removed_element = current_node->value;
    list_t *remove;
    remove->head = current_node;
    list_free(remove);
    previous_node->next = NULL;
    return removed_element; 
}
elem list_remove_from_front(list_t *l) { 
    int removed_element = 0;
    node_t *current_node = l->head;
    removed_element = current_node->value;
    l->head = current_node->next;
    list_t *remove;
    remove->head = current_node;
    list_free(remove);
    return removed_element; 
}
elem list_remove_at_index(list_t *l, int index) { 
    int removed_element = 0;
    if(index == 0){
        return list_remove_from_front(l);
    }else if(index == list_length(l) - 1){
        return list_remove_from_back(l);
    }
    int position = 0;
    node_t *current_node = l->head;
    node_t *previous_node = NULL;
    while(position < index){
        position++;
        previous_node = current_node;
        current_node = current_node->next;
    }
    removed_element = current_node->value;
    previous_node->next = current_node->next;
    list_t *remove;
    remove->head = current_node;
    list_free(remove);
    return removed_element; 
}
/* Checks to see if the given element exists in the list. */
bool list_is_in(list_t *l, elem value) { 
    node_t *current_node = l->head;
    while(current_node != NULL){
        if(current_node->value == value){
            return true;
        }
        current_node = current_node->next;
    }
    return false; 
}
/* Returns the element at the given index. */
elem list_get_elem_at(list_t *l, int index) { 
    if(index == 0){
        return l->head->value;
    }
    int position = 0;
    node_t *current_node = l->head;
    while(position < index){
        position++;
        current_node = current_node->next;
    }
    return current_node->value; 
}
/* Returns the index at which the given element appears. */
int list_get_index_of(list_t *l, elem value) { 
    node_t *current_node = l->head;
    int index = 0;
    while(current_node != NULL){
        if(current_node->value == value){
            return index;
        }
        index++;
        current_node = current_node->next;
    }
    if(current_node == NULL && index == 0){
        return -1;
    }
    return index; 
}