#include "dlist.h"
#include <stdio.h>

void swap(dnode_t *tmp, dnode_t *prv )
{
	if (tmp == prv) 
        return;
	prv->next = tmp->next;
    tmp->next->prev = prv;
    tmp->next->next = tmp;
    tmp->prev = prv->next;
}
dnode_t *splt(dnode_t*head) 
{ 
    dnode_t *fast = head,*slow = head; 
    while (fast->next && fast->next->next) 
    { 
        fast = fast->next->next; 
        slow = slow->next; 
    } 
    dnode_t *temp = slow->next; 
    slow->next = NULL; 
    return temp; 
}
// insertion sort
void insertion_sort(struct dlist *list){
    int n = list->size;
    int i,j,h, price;
    dnode_t *tmp, *prt, *prf;

    tmp = list->head;

    if (list->head ==NULL) 
		return;
	if (list->head == list->tail)
        return;
    
    for (i = 1; i < n; i++) {
        price = tmp->data;
        prt = tmp;
		for (j = i - 1; j >= 0 &&  prt->data > price; j--) {               
            prt->data = prt->next->data;
            prt =prt->next;
		}
        prt->data = price;
        tmp = tmp->next;

        //print list
        printf("[%d]:",i);
        prf = list->head;
        for (h = 0; h < list->size; h++){
            printf(" %d",prf->data);
        }
        printf("\n");
	}
}
// selection sort
void selection_sort(struct dlist *list){
    int n = list->size;
    int i,j,h, price;
    dnode_t *tmp, *ptr, *prf;

    tmp = list->head;
    for (i = 0; i< n-1; i++){
        price = tmp->data;
        ptr = tmp;
        for( j = i + 1; j<=n-1; j++) {
            if( ptr->data < price) {
                ptr = ptr->next;
            }
        }

        tmp->data = ptr->data;
        ptr->data = price;
            
        //print list
        printf("[%d]: ",i);
        prf = list->head;
        for (h = 0; h < list->size; h++){
            printf("%d",prf->data);
            if (h < list->size -1){
                printf(" ");
            }
            else{
                printf("\n");
            }
            prf = prf->next;
        }
    }
}
// quick sort 
dnode_t *quick_sort(dnode_t *head, int n, int loop)
{   int i, j;
	int last = 0;
    dnode_t *tmp, *tws, *prf;

    prf = head;
    printf("[%d >]", loop);
    for (j = 0; j <n; j++){
        printf(" %d",prf->data);
        if (j == n-1){
            printf("\n");
        }
        prf = prf->next;
    }
	
	if (n < 2) 
        return head;
    tmp = tws = head;
	for (i = 1; i < n/2; i++){
        tws = tws->next;
    }

    swap(tws, tmp);
	tws = head;
    for (i = 1; i < n; i++) {
		if (tws->data < head->data) {
			++last;
            swap(tws, head);
		}
        tws = tws->next;
	}

    prf = head;
    printf("[%d -]", loop);
    for (j = 0; j <n; j++){
        printf(" %d",prf->data);
        if (j == n-1){
            printf("\n");
        }
        prf = prf->next;
    }

    loop = loop+1;
	swap(tws,head);
	head = quick_sort(head, last,loop);
	quick_sort(tws->next, n-last-1,loop);
    prf = head;
    printf("[%d -]", loop);
    for (j = 0; j <n; j++){
        printf(" %d",prf->data);
        if (j == n-1){
            printf("\n");
        }
        prf = prf->next;
    }
    return head;
}

//Merge Sort
dnode_t *merge(dnode_t *first, dnode_t *second) 
{ 
    // If first linked list is empty 
    if (!first) 
        return second; 
  
    // If second linked list is empty 
    if (!second) 
        return first; 
  
    // Pick the smaller value 
    if (first->data < second->data) 
    { 
        first->next = merge(first->next,second); 
        first->next->prev = first; 
        first->prev = NULL; 
        return first; 
    } 
    else
    { 
        second->next = merge(first,second->next); 
        second->next->prev = second; 
        second->prev = NULL; 
        return second; 
    } 
} 
dnode_t *mergeSort(dnode_t *head, int loop) 
{   int i;
    if (!head || !head->next) 
        return head; 
    dnode_t *second = splt(head); 
    
    for ( i = 0; i < loop; i++){
        printf("==");
    }
    printf("[%d>]",loop);
    while (head){ 
        printf(" %d",head->data); 
        head = head->next; 
    }
    printf("\n");
    // Recur for left and right halves 
    head = mergeSort(head,loop +1);  
    second = mergeSort(second, loop+1); 
    while (head){ 
        printf("%d ",head->data); 
        head = head->next; 
    } 
    head = merge(head,second);

    for ( i = 0; i < loop; i++){
        printf("==");
    }
    printf("[%d<]",loop);
    while (head){ 
        printf(" %d",head->data); 
        head = head->next; 
    }
    printf("\n");
    // Merge the two sorted halves 
    return head; 

} 
 
// Radix sort lsd
int get_max (dlist_t *list){
   dnode_t *max, *ptr;
   int i;
   ptr = max = list->head;
   for (i = 1; i < list->size; i++){
      if (ptr->data > max->data){
         max = ptr;
        }
        ptr = ptr->next;
    }
   return max->data;
}
void print_bit(int data, int pass){
    int tempDecimal, binary;
    int rem,size,place = 1;
    char prin [5];

    binary = 0;
    tempDecimal = data;
    while(tempDecimal > 0){
        
        rem = tempDecimal % 2;
        binary = (rem * place) + binary;
        tempDecimal /= 2;
        place *= 10;
    }
    size = pass * 4;

    printf("%d", data);
    printf("(%d)", binary);
}
void radix_sort (dlist_t *list, int size){

    
   int bucket[10][10], bucket_cnt[10];
   int i, j, k, r, NOP = 0, divisor = 1, lar, pass;
    dnode_t *ptr;

   lar = get_max ( list);
   while (lar > 0){
      NOP++;
      lar /= 10;
   }

   for (pass = 0; pass < NOP; pass++){
      for (i = 0; i < 10; i++){
         bucket_cnt[i] = 0;
      }
      for (i = 0; i < list->size; i++){
         r = (ptr->data / divisor) % 10;
         bucket[r][bucket_cnt[r]] = ptr->data;
         bucket_cnt[r] += 1;
         ptr = ptr->next;
      }
      i=0;
      ptr = list->head;
      for (k = 0; k < 10; k++){
         for (j = 0; j < bucket_cnt[k]; j++){
            ptr->data = bucket[k][j];
            ptr->next;
            i++;
         }
      }
      divisor *= 10;
      ptr = list->head;
      printf ("[%d] ", pass );
      for (i = 0; i < list->size; i++){
        print_bit(ptr->data,pass +1);
      }
      printf ("\n");
   }
}