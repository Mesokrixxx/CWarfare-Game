#include "dynamicList.h"

// Initialize a list, content_size represent the type of elements in the list
DList *initDynamicList(size_t content_size) {
	DList *dlist;

	dlist = calloc(1, sizeof(struct s_dlist));
	dlist->content_size = content_size;
	dlist->size = 0;
	return (dlist);
}

// Append an element at the back of a list
void appendToDList(DList *dlist, void *content) {
	dlist->size++;
	dlist->content = realloc(dlist->content, (dlist->size + 1) * dlist->content_size);
	dlist->content[dlist->size - 1] = content;
}

// Free a list and it's content
Bool freeDList(DList *dlist)
{
	if (dlist->size > 0)
		for (uint i = 0; i < dlist->size; i++)
			free(dlist->content[i]);
	free(dlist->content);
	free(dlist);
	return (true);
}

// Return the element at index, return NULL if index is out of range
void *getDListElement(DList *dlist, uint index)
{
	if (index >= dlist->size)
		return (NULL);
	return (dlist->content[index]);
}

// Remove an element at index from a list, return true if successful
Bool removeDListElement(DList *dlist, uint index)
{
	if (index >= dlist->size)
		return (false);
	for (uint i = index; i < dlist->size - 1; i++)
		dlist->content[i] = dlist->content[i + 1];
	dlist->size--;
	dlist->content = realloc(dlist->content, (dlist->size + 1) * dlist->content_size);
	return (true);
}
