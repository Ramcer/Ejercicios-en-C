#include "stack.h"
#include <stdlib.h>
#include <stdio.h>
#include <assert.h>
Stack_t * StackCreate(int size)
{
    Stack_t *ns = (Stack_t *) malloc(sizeof(Stack_t));
    assert(ns != NULL);
    ns->size = size;
    ns->top = 0;
    ns->pElements = (int *) malloc(size * sizeof(int));
    assert(ns->pElements);
    return ns;

}
int StackPush(Stack_t *ps, int e)
{
    if(ps->top == ps->size)
        return 0;
    ps->pElements[ps->top++] = e;
    return 1;
}
int StackPop(Stack_t *ps, int *pe)
{
    if(ps->top == 0)
        return 0;
    *pe = ps->pElements[--ps->top];
    return 1;
}
int StackIsEmpty(Stack_t *ps)
{
    return ps->top == 0;
}

void StackDestroy(Stack_t *ps)
{
    free(ps->pElements);
    free(ps);
}

void StackFilter(Stack_t_l *pStk, int e)
{
    int t;
    if(StackIsEmpty(pStk))
    {
        return;
    }
    StackPop(pStrk,&t);
    StackFilter(pStrk,e);
    if(t!=e)
    {
        StackPush(pStrk,t);
        return;
    }
    return ;
}
