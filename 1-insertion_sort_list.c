#include "sort.h"

/**
 * insertion_sort_list - Sorts a doubly linked list of integers
 * in ascending order using the Insertion sort algorithm
 *
 * @list: A pointer to the head of the list.
 *
 */

void insertion_sort_list(listint_t **list)
{
	listint_t *temp, *traverse, *previous;

	if (!list || !(*list) || !(*list)->next)
		return;

	traverse = (*list)->next;

	while (traverse)
	{
		temp = traverse->next;
		previous = traverse->prev;

		while (previous && traverse->n < previous->n)
		{
			previous->next = traverse->next;

			if (traverse->next)
				traverse->next->prev = previous;

			traverse->prev = previous->prev;
			traverse->next = previous;

			if (previous->prev)
				previous->prev->next = traverse;
			else
				*list = traverse;

			previous->prev = traverse;
			previous = traverse->prev;
			print_list((const listint_t *)*list);
		}
		traverse = temp;
	}
}
