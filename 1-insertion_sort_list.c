#include "sort.h"

/**
 * swap - swap node
 * @list: DLL where int was store
 * Return: nothing
 */
void swap(listint_t **list)
{
	listint_t *node_p, *node_n;

	node_p = (*list)->prev;
	node_n = (*list)->next;

	if (node_n != NULL)
		node_n->prev = node_p;

	if (node_p->prev != NULL)
		node_p->prev->next = *list;

	(*list)->next = node_p;
	(*list)->prev = node_p->prev;

	node_p->next = node_n;
	node_p->prev = *list;
}

/**
 * insertion_sort_list - sorts a DLL in ascending order with the Insertion sort
 * @list: DLL where int was store
 * Return: nothing
 */

void insertion_sort_list(listint_t **list)
{
	listint_t *current;

	if (list == NULL || *list == NULL)
		return;

	current = (*list)->next;

	while (current != NULL)
	{
		while (current->prev != NULL && current->n < current->prev->n)
		{
			swap(&current);
			if (current->prev == NULL)
				*list = current;
			print_list(*list);
		}
		current = current->next;
	}

}
