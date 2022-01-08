#ifndef LIST_H
#define LIST_H
#include <stdlib.h>
#define LIST_EMPTY NULL
#define LIST_CONT(lst) ((lst)->cont)
#define LIST_TAIL(lst) ((lst)->pNext)
typedef struct Node {
int cont;
struct Node *pNext;
} *List_t;


List_t __ListNodeCreate(int e, List_t tail);
int ListNumNodes(List_t lst);
int ListIsMember(int x, List_t lst);
List_t ListInsert(List_t lst, int x);
int ListNumNodesNR(List_t lst);
int ListIsMemberNR(int x, List_t lst);
void ListPrint(List_t lst);


#endif
