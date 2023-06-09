#include "sort.h"

/**
 * get_tail - gets tail of list
 * @list: a doubly linked list of integers
 * Return: tail node
*/
listint_t *get_tail(listint_t *list)
{
	listint_t *tail = NULL;

	tail = list;
	while (tail->next)
		tail = tail->next;

	return (tail);
}

/**
*swap - swaps nodes
*@list: doubly linked list
*@temp: current node
*@ptr: prev node
*@st: status
*Return: node
*/

listint_t *swap(listint_t **list, listint_t *temp, listint_t *ptr, bool st)
{
	listint_t *ret = NULL;

	if (!temp || !ptr)
		return (NULL);
	if (temp->next)
		temp->next->prev = ptr;

	if (ptr->prev)
		ptr->prev->next = temp;
	else
		*list = temp;

	temp->prev = ptr->prev;
	ptr->prev = temp;
	ptr->next = temp->next;
	temp->next = ptr;

	ret = st == 1 ?  ptr : temp;
	return (ret);
}

/**
 * cocktail_sort_list - a function that sorts
 * a doubly linked list of integers in
 * ascending order using the Cocktail shaker sort algorithm
 * @list: a doubly linked list of integers
*/
void cocktail_sort_list(listint_t **list)
{
	listint_t *tail, *trav, *head, *temp;
	bool swpd = true;

	if (!list || !(*list) || !(*list)->next)
		return;
	tail = get_tail(*list), head = (*list);

	while (swpd)
	{
		swpd = false, trav = head->next;
		while (trav != tail)
		{
			if (trav->n < trav->prev->n)
				trav = swap(&(*list), trav, trav->prev, 1), print_list(*list), swpd = true;
			trav = trav->next;
		}
		if (trav->n < trav->prev->n)
			trav = swap(&(*list), trav, trav->prev, 1), swpd = true, print_list(*list);
		if (!swpd)
			break;
		tail = tail->prev, trav = trav->prev;
		while (trav != head)
		{
			if (trav->n < trav->prev->n)
			{
				temp = swap(&(*list), trav, trav->prev, 0), swpd = true;
				if (temp->next == head)
				{
					print_list(*list), head = temp;
					break;
				}
				trav = temp, print_list(*list);
			}
			else
				trav = trav->prev;
		}
		head = head->next;
	}
}
