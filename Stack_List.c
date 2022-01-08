#include "Stack_list.h"
#include <stdlib.h>
#include <assert.h>

int StacklistPush(Stack_t_l *ps, int e)
{
    List_t aux;
    aux=ps->top;
    ps->top=__ListNodeCreate(e,NULL);
    ps->top->pNext=aux;
    ps->size++;
    return 1;
}

int StacklistPop(Stack_t_l *ps, int *pe)
{
    List_t aux;
    if(ps->top==NULL)
    {
        return 0;
    }
    *pe=ps->top->cont;
    aux=ps->top->pNext;
    free(ps->top);
    ps->top=aux;
    ps->size--;
    return 1;

}

Stack_t_l * StacklistCreate(void)   //Una de la ventajas con lista es que el tamaño es dinamico
{
    Stack_t_l *ns = (Stack_t_l *) malloc(sizeof(Stack_t_l));
    assert(ns != NULL);
    ns->size = 0;
    ns->top = NULL;
    //ns->pElements = (int *) malloc(size * sizeof(int));
    //assert(ns->pElements);
    return ns;

}


int StacklistIsEmpty(Stack_t_l *ps)
{
    return ps->top == NULL;
}
