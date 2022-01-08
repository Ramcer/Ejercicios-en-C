#include <stdio.h>
#include <stdlib.h>

int CompareStrings(const char *a, const char *b);

int main()
{
    char a[]="Abcde",b[]="Abcae";
    if(CompareStrings(a,b)==-1)
    {
        printf("El string a va antes en el diccionario \n");
    }if (CompareStrings(a,b)==1)
    printf("El string b va antes en el diccionario \n");
    if(CompareStrings(a,b)==0)
    {
         printf("Son iguales \n");
    }
}

int CompareStrings(const char *a, const char *b)
{
    if(*a>*b)
    {
        return 1;
    }

    if(*a<*b)
    {
        return -1;
    }
    if(*a==0)
    {
        return 0;
    }
    return CompareStrings((a+1),(b+1));
}
