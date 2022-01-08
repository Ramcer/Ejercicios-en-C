#ifndef slis
#define slis

#include "list.h"

typedef struct
{
    List_t top;
    int size;
    //List_t *pElements;
} Stack_t_l;


int StacklistPush(Stack_t_l *ps, int e);
int StacklistPop(Stack_t_l *ps, int *pe);
Stack_t_l * StacklistCreate(void);
int StacklistIsEmpty(Stack_t_l *ps);

#endif
