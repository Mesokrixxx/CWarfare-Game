#include "dynamicList.h"

DList *initDynamicList(size_t content_size) {
	DList *dlist;

	dlist = calloc(1, sizeof(struct s_dlist));
	dlist->content_size = content_size;
	dlist->size = 0;
	return (dlist);
}

void appendToDList(DList *dlist, void *content) {
	dlist->size += 1;
	dlist->content = realloc(dlist->content, (dlist->size + 1) * dlist->content_size);
	dlist->content[dlist->size - 1] = content;
}
