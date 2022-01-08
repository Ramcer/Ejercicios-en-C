#ifndef stack
#define stack

#include "Stack_List.h"
typedef struct
{
    int top;
    int size;
    int *pElements;
} Stack_t;


int CheckExpresion(const char *expr);
void StackDestroy(Stack_t *ps);
int StackPush(Stack_t *ps, int e);
int StackPop(Stack_t *ps, int *pe);
int StackIsEmpty(Stack_t *ps);
Stack_t * StackCreate(int n);
void StackFilter(Stack_t_l *pStk, int e);

#endif
