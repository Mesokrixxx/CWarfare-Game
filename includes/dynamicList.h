#ifndef DYNAMIC_LIST_H
# define DYNAMIC_LIST_H

# include "wg_vars.h"

typedef struct s_dlist {
	void	**content;
	size_t	content_size;
	uint	size;
}	DList;

DList *initDynamicList(size_t content_size);
void appendToDList(DList *dlist, void *content);
Bool freeDList(DList *dlist);
void *getDListElement(DList *dlist, uint index);
Bool removeDListElement(DList *dlist, uint index);

#endif