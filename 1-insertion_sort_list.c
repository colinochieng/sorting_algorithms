#include "sort.h"

/**
 * swap_nodes - function that swaps two nodes in a doubly linked list
 * @list: doubly linked list
 * @node1: prev node
 * @node2: curr node
*/
void swap_nodes(listint_t **list, listint_t *node1, listint_t *node2)
{
	if (!list || !node1 || !node2)
	return;

	if (node1->prev)
		node1->prev->next = node2;
	else
		*list = node2;

	if (node2->next)
		node2->next->prev = node1;

	node1->next = node2->next;
	node2->prev = node1->prev;
	node1->prev = node2;
	node2->next = node1;

	print_list(*list);
}

/**
 * insertion_sort_list -  sorts a doubly linked list
 * of integers in ascending order using the Insertion sort algorithm
 * @list: doubly linked list
*/

void insertion_sort_list(listint_t **list)
{
	listint_t *current = NULL, *temp = NULL;
	if (!list || !*list || !(*list)->next)
		return;

	current = (*list)->next;

	while (current)
	{
		temp = current;
		/*Loop through the list from right to left until finding the correct position for temp*/
		while (temp->prev && temp->n < temp->prev->n)
		{
			/*Swap temp with its previous node*/
			swap_nodes(list, temp->prev, temp);
		}

		current = current->next;
	}
}
