#ifndef LINKED_LIST_H
#define LINKED_LIST_H

#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <stdlib.h> // malloc (), free () -- calloc ()
#include <string.h>

// dynamic memory - memory is allocated and deallocated at runtime

typedef struct node
{
	// char * 
	char item[50]; // 50 bytes // grocery item
	struct node* next_ptr; // 4 bytes // self referantial struct
} Node; // 54 bytes

Node* make_node(char* grocery_item);

int insert_at_front(Node** head_ptr, char* grocery_item);

int insert_in_order(Node** list_ptr, char* grocery_item);

// grocery_item will store a copy of the string in the front  of the list
// preconditon: list must not be empty
void delete_at_front(Node** list_ptr, char* grocery_item);

// grocery_item will store a copy of the string in the front  of the list
// preconditon: list must not be empty
int delete_item(Node** list_ptr, char* grocery_item);

void print_list(Node* head_ptr);

void rec_print_list(Node* head_ptr);

#endif