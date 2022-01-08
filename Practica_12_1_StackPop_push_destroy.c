#include <stdio.h>
#include <stdlib.h>

typedef struct {
int top;
int size;
int *pElements;
} Stack_t;

void StackFilter(Stack_t *pStk, int e);
int StackPush(Stack_t *ps, int e);
int StackPop(Stack_t *ps, int *pe);
int StackIsEmpty(Stack_t *ps);
void StackDestroy(Stack_t *ps);

int main()
{
    return ;
}

void StackFilter(Stack_t *pStk, int e)
{
    int t;
    if(StackIsEmpty(pStk))
    {
        return;
    }
    StackPop(pStk,&t);
    StackFilter(pStk,e);
    if(t!=e)
    {
        StackPush(pStk,t);
        return;
    }
    return ;
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
