#include "List.h"
#include <assert.h>
int ListNumNodes(List_t lst){
if(lst == LIST_EMPTY)
return 0;
return 1 + ListNumNodes(LIST_TAIL(lst));
}


int ListIsMember(int x, List_t lst){
if(lst == LIST_EMPTY)
return 0;
if(LIST_CONT(lst) == x)
return 1;
return ListIsMember(x, LIST_TAIL(lst));
}


List_t __ListNodeCreate(int e, List_t tail)
{
List_t newL = (List_t ) malloc(sizeof(struct Node));
assert(newL);
LIST_CONT(newL) = e;
LIST_TAIL(newL) = tail;
return newL;
}

List_t ListInsert(List_t lst, int x)
{
if(lst == LIST_EMPTY || x <= LIST_CONT(lst) )
return __ListNodeCreate(x, lst);
LIST_TAIL(lst) = ListInsert(LIST_TAIL(lst), x);
return lst;
}



int ListNumNodesNR(List_t lst)
{
int nn = 0;
while( lst != LIST_EMPTY ) {
++nn;
lst = LIST_TAIL(lst);
}
return nn;
}


void ListPrint(List_t lst)
{
while(lst) {
printf("%d ", LIST_CONT(lst));
lst = LIST_TAIL(lst); // lst = lst->pNext
}
puts("");
}


int ListIsMemberNR(int x, List_t lst)
{
while( lst != LIST_EMPTY ) {
if(LIST_CONT(lst) == x)
return 1;
lst = LIST_TAIL(lst);
}
return 0;
}
