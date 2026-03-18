/**
 * @file ll.c
 * @brief Linked List implementation
 */

/*
 * project: 01PROJTEMP
 * module: Linked List
 * created: 2026-03-10
 * SPDX-License-Identifier: GPL-3.0-or-later
 * author: Tim Palmer
 */

#include "linked_list.h"
#include <stdlib.h>
#include <string.h>

ctLL_t *
ctListInit ()
{
	ctLL_t *list = malloc (sizeof (ctLL_t));
	if (list == NULL)
		return NULL;
	list->first = NULL;
	list->last = NULL;
	list->size = 0;
	return list;
}

void
ctListFree (ctLL_t *list)
{
	if (list == NULL)
		return;
	if (list->first != NULL)
		{
			ctLLNode_t *head = list->first;
			ctLLNode_t *next = head->next;
			while (head != NULL)
				{
					free (head);
					head = next;
					if (head != NULL)
						next = head->next;
				}
		}
	list->first = NULL;
	list->last = NULL;
	list->size = 0;
	free (list);
}

void
ctListClear (ctLL_t *list)
{
	if (list == NULL)
		return;
	if (list->first != NULL)
		{
			ctLLNode_t *head = list->first;
			ctLLNode_t *next = head->next;
			while (head != NULL)
				{
					free (head);
					head = next;
					if (head != NULL)
						next = head->next;
				}
		}
	list->first = NULL;
	list->last = NULL;
	list->size = 0;
}

int
ctListInsertFront (ctLL_t *list, void *data)
{
	if (list == NULL || data == NULL)
		return -1;
	ctLLNode_t *node = malloc (sizeof (ctLLNode_t));
	if (node == NULL)
		return -1;
	node->data = data;
	if (list->last == NULL)
		list->last = node;
	node->next = list->first;
	list->first = node;
	list->size++;
	return 0;
}

int
ctListInsertBack (ctLL_t *list, void *data)
{
	if (list == NULL || data == NULL)
		return -1;
	ctLLNode_t *node = malloc (sizeof (ctLLNode_t));
	if (node == NULL)
		return -1;
	node->data = data;
	if (list->first == NULL)
		list->first = node;
	node->next = NULL;
	if (list->last == NULL)
		{
			list->last = node;
			list->last->next = NULL;
		}
	else
		list->last->next = node;
	list->last = node;
	list->size++;

	return 0;
}

int
ctListRemove (ctLL_t *list, ctLLNode_t *node)
{
	if (list == NULL || node == NULL)
		return -1;
	ctLLNode_t *next = node->next;
	ctLLNode_t *current = list->first;
	if (current == node) // The First Node
		{
			if (current->next != NULL) // Not the only Node
				list->first = current->next;
			else // The only one
				{
					list->first = NULL;
					list->last = NULL;
				}
			free (node);
			list->size--;
			return 0;
		}
	while (current != NULL) // Traverse
		{
			if (current->next == node)
				break;
			current = current->next;
		}
	if (current == NULL)
		return -1; // Didn't find it
	if (node->next == NULL)
		list->last = current; // Last node
	current->next = next;
	free (node);
	list->size--;
	return 0;
}

void *
ctListPopFront (ctLL_t *list)
{
	if (list == NULL || list->first == NULL)
		return NULL;
	ctLLNode_t *first = list->first;
	void *data = first->data;
	if (first->next == NULL)
		{
			free (first);
			list->first = NULL;
			list->last = NULL;
			list->size = 0;
			return data;
		}

	ctLLNode_t *second = first->next;
	free (first);
	list->first = second;
	list->size--;

	return data;
}

void *
ctListPopBack (ctLL_t *list)
{
	if (list == NULL || list->first == NULL)
		return NULL;
	ctLLNode_t *last = NULL;
	ctLLNode_t *prev = NULL;
	prev = list->first;
	void *data = prev->data;
	if (prev->next == NULL)
		{
			free (prev);
			list->first = NULL;
			list->last = NULL;
			list->size = 0;
			return data;
		}
	last = prev->next;
	while (last->next != NULL)
		{
			prev = prev->next;
			last = prev->next;
		}
	data = last->data;
	free (last);
	list->last = prev;
	prev->next = NULL;
	list->size--;

	return data;
}

ctLLNode_t *
ctListHead (ctLL_t *list)
{
	if (list == NULL || list->first == NULL)
		return NULL;
	return list->first;
}

ctLLNode_t *
ctListEnd (ctLL_t *list)
{
	if (list == NULL || list->last == NULL)
		return NULL;
	return list->last;
}

ctLLNode_t *
ctListNext (ctLLNode_t *node)
{
	if (node == NULL)
		return NULL;
	return node->next;
}

void *
ctListGet (ctLL_t *list, size_t index)
{
	if (list == NULL || list->size == 0)
		return NULL;
	if (index > list->size - 1)
		return NULL;
	size_t i;
	ctLLNode_t *current = list->first;
	for (i = 0; i < index && current != NULL; i++)
		{
			current = current->next;
		}
	if (current == NULL || current->data == NULL)
		return NULL;
	return current->data;
}

void *
ctListData (ctLLNode_t *node)
{
	if (node == NULL)
		return NULL;
	return node->data;
}

size_t
ctListSize (ctLL_t *list)
{
	if (list == NULL)
		return 0;
	return list->size;
}

int
ctListIsEmpty (ctLL_t *list)
{
	if (list == NULL || list->size == 0)
		return 1;
	return 0;
}
