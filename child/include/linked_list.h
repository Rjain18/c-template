/**
 * @file linked_list.h
 * @brief Linked List Module
 */

/*
 * project: 01PROJTEMP
 * module: Linked List
 * created: 2026-03-10
 * SPDX-License-Identifier: GPL-3.0-or-later
 * author: Tim Palmer
 */
#ifndef LINKED_LIST_H
#define LINKED_LIST_H

#include <stddef.h>

typedef struct ctLLNode
{
	void *data;
	struct ctLLNode *next;
} ctLLNode_t;

typedef struct ctLL
{
	ctLLNode_t *first;
	ctLLNode_t *last;
	size_t size;
} ctLL_t;

ctLL_t *ctListInit ();
void ctListFree (ctLL_t *list);
void ctListClear (ctLL_t *list);

int ctListInsertFront (ctLL_t *list, void *data);
int ctListInsertBack (ctLL_t *list, void *data);

int ctListRemove (ctLL_t *list, ctLLNode_t *node);
void *ctListPopFront (ctLL_t *list);
void *ctListPopBack (ctLL_t *list);

ctLLNode_t *ctListHead (ctLL_t *list);
ctLLNode_t *ctListEnd (ctLL_t *list);
ctLLNode_t *ctListNext (ctLLNode_t *node);
void *ctListGet (ctLL_t *list, size_t index);

void *ctListData (ctLLNode_t *node);

size_t ctListSize (ctLL_t *list);
int ctListIsEmpty (ctLL_t *list);

#endif // LINKED_LIST_H
