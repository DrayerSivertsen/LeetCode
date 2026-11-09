#include "LinkedList.h"

Node* make_node(char* grocery_item)
{
	Node* mem_ptr = NULL;
	mem_ptr = (Node*)malloc(sizeof(Node)); // allocating 54 bytes
	mem_ptr->next_ptr = NULL;
	strcpy(mem_ptr->item, grocery_item);

	return mem_ptr;
}

int insert_at_front(Node** head_ptr, char* grocery_item)
{
	Node* mem_ptr = NULL;
	int success = 0;

	mem_ptr = make_node(grocery_item);

	if (mem_ptr != NULL) // memory was allocated for a Node on the heap
	{
		success = 1;

		if (*head_ptr == NULL) // *head_ptr refers to the original head pointer in main
		{
			// empty list
			*head_ptr = mem_ptr;
		}
		else
		{
			// not empty
			mem_ptr->next_ptr = *head_ptr;
			*head_ptr = mem_ptr;
		}
	}

	return success;
}

int insert_in_order(Node** list_ptr, char* grocery_item)
{
	Node* mem_ptr = NULL, * cur_ptr = NULL, * prev_ptr = NULL;
	int success = 0;

	mem_ptr = make_node(grocery_item);

	if (mem_ptr != NULL) // did we allocate space on heap successfully?
	{
		success = 1;
		cur_ptr = *list_ptr;

		if (*list_ptr != NULL) // not empty list
		{
			// it's not an empty list
			while ((cur_ptr != NULL) && 
				(strcmp(mem_ptr->item, cur_ptr->item) > 0))
			{
				// advance in list
				prev_ptr = cur_ptr;
				cur_ptr = cur_ptr->next_ptr; // move to next node in list
			}
			// inserting some where in the middle or at the end?
			if (prev_ptr != NULL)
			{
				mem_ptr->next_ptr = cur_ptr;
				prev_ptr->next_ptr = mem_ptr;
			}
			else // inserting at front
			{
				mem_ptr->next_ptr = cur_ptr;
				*list_ptr = mem_ptr;
			}
		}

		
		else
		{
			// it's and empty list
			*list_ptr = mem_ptr;
		}
	}

	return success;
}

void delete_at_front(Node** list_ptr, char* grocery_item)
{
	Node* temp_ptr = NULL;

	temp_ptr = *list_ptr;
	*list_ptr = temp_ptr->next_ptr;

	strcpy(grocery_item, temp_ptr->item);

	// free () - deallocates space on the heap
	free(temp_ptr);
}

int delete_item(Node** list_ptr, char* grocery_item)
{
	Node* prev_ptr = NULL, * cur_ptr = *list_ptr;
	int success = 0;

	while ((cur_ptr != NULL) && 
		(strcmp(grocery_item, cur_ptr->item) != 0)) // searching for the item to delete
	{
		prev_ptr = cur_ptr;
		cur_ptr = cur_ptr->next_ptr;
	}

	// either we found the item in the list or are currently in the correct position
	// or we reached the end of the list
	if (cur_ptr != NULL)
	{
		// check if it's first node
		if (prev_ptr == NULL)
		{
			*list_ptr = (*list_ptr)->next_ptr;
		}
		else
		{
			// not deleting first node
			prev_ptr->next_ptr = cur_ptr->next_ptr;
		}

		success = 1;
		free(cur_ptr);
	}

	return success;
}

void print_list(Node* head_ptr)
{
	printf("--> ");

	while (head_ptr != NULL)
	{
		printf("%s --> ", head_ptr->item);
		head_ptr = head_ptr->next_ptr;
	}

	putchar('\n');
}

void rec_print_list(Node* head_ptr)
{
	if (head_ptr == NULL) // base case?
	{
		putchar('\n');
	}
	else // recursive step
	{
		printf(" %s -->", head_ptr->item);
		rec_print_list(head_ptr->next_ptr);
	}
}