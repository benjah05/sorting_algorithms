#include "sort.h"
/**
 * swap_nodes - swap two adjacent nodes
 * @list: pointer of the first node (the head)
 * @nodeA: first node
 * @nodeB: second node
 * Return: void
 */
void swap_nodes(listint_t **list, listint_t *nodeA, listint_t *nodeB)
{
	if (nodeA == NULL || nodeB == NULL || nodeA == nodeB)
		return;
	nodeA->next = nodeB->next;
	if (nodeB->next != NULL)
		nodeB->next->prev = nodeA;
	nodeB->prev = nodeA->prev;
	if (nodeA->prev != NULL)
		(nodeA->prev)->next = nodeB;
	else
		*list = nodeB;
	nodeA->prev = nodeB;
	nodeB->next = nodeA;
	nodeB->prev = nodeA->prev;
	nodeA->prev = nodeB;
}
/**
 * cocktail_sort_list - sort a list of numbers using cocktail sort
 * @list: pointer to the head of the doubly-linked list
 * Return: void
 */
void cocktail_sort_list(listint_t **list)
{
	listint_t *start, *end, *curr;
	bool swapped = true;

	if (list == NULL || *list == NULL)
		return;
	start = *list;
	end = *list;
	while (end->next != NULL)
		end = end->next;
	while (swapped)
	{
		swapped = false;
		while (start != end)
		{
			curr = start->next;
			if (start->n > curr->n)
			{
				swap_nodes(list, start, curr);
				swapped = true;
				print_list(*list);
			}
			start = curr;
		}
		if (!swapped)
			break;
		swapped = false;
		end = end->prev;
		while (end != start)
		{
			curr = end->prev;
			if (end->n < curr->n)
			{
				swap_nodes(list, curr, end);
				swapped = true;
				print_list(*list);
			}
			end = curr;
		}
		start = start->next;
	}
}
