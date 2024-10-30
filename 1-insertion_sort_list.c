#include "sort.h"
/**
 * insertion_sort_list - sort a doubly linked list of integers
 * in ascending order using the insertion sort algorithm
 * @list: pointer to the first node of the doubly linked list
 * Return: void
 */
void insertion_sort_list(listint_t **list)
{
	listint_t *tmp, *current, *prev_node;

	if (list == NULL || *list == NULL || (*list)->next == NULL)
		return;
	tmp = (*list)->next;
	while (tmp != NULL)
	{
		current = tmp;
		tmp = tmp->next;
		while (current->prev != NULL && current->n < current->prev->n)
		{
			prev_node = current->prev;
			if (prev_node->prev != NULL)
				prev_node->prev->next = current;
			current->prev = prev_node->prev;
			prev_node->prev = current;
			prev_node->next = current->next;
			if (current->next != NULL)
				current->next->prev = prev_node;
			current->next = prev_node;
			if (current->prev == NULL)
				*list = current;
			print_list(*list);
		}
	}
}
