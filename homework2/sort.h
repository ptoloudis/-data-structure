#include "dlist.h"

void swap(dnode_t *tmp, dnode_t *prv );
void insertion_sort(dlist_t *list);
void selection_sort(dlist_t *list);
dnode_t *quick_sort(dnode_t *head, int n, int loop);
dnode_t *merge(dnode_t *first, dnode_t *second);
dnode_t *mergeSort(dnode_t *head, int loop);
dnode_t *splt(dnode_t *head);