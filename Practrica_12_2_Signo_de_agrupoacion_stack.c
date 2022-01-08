#include <stdio.h>
#include <stdlib.h>
#include "../lib/stack.h"
#include <string.h>
int main()
{
    char A[]="}";
    printf("Hola");
    printf("%d",CheckExpresion(A));
}

int CheckExpresion(const char *expr)
{
    int i=0,aux;
//CONTAR LOS ELEMENTROS DEL STRING Y LUEGO CREAR EL STACK
//USAR STRLEN ...
    Stack_t *ps = StackCreate(strlen(expr));
    i=0;
    while(expr[i]!=0)
    {
        if(expr[i]=='{'||expr[i]=='['||expr[i]=='(')
        {
            StackPush(ps,expr[i]);
        }
        if(expr[i]=='}')
        {
            if(StackPop(ps,&aux))
            {
                if(aux!='{')
                {
                    return 0;
                }
            }
            else
                return 0;
        }


        if(expr[i]==']')
        {
            if(StackPop(ps,&aux))
            {
                if(aux!='[')
                {
                    return 0;
                }
            }
            else
                return 0;
        }
        if(expr[i]==')')
        {
            if(StackPop(ps,&aux))
            {
                if(aux!='(')
                {
                    return 0;
                }
            }
            else
            {
                StackDestroy(ps);
                return 0;
            }
        }
        i++;
    }

    i=StackIsEmpty(ps);
    StackDestroy(ps);
    return i;
    if(!StackIsEmpty(ps))
    {
        return 0;
    }


    StackDestroy(ps);

    return 1;


}

