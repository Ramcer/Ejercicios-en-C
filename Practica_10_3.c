#include <stdio.h>
#include <stdlib.h>
#include <string.h>
int CompareStrings(const char *a, const char *b);
int cmp(const void *pa, const void *pb);

int main(int argc ,char *argv[])
{
    int i;
    for(i=0;i<argc;i++)
    {
    printf("%s \n",argv[i]);
    }
    qsort(argv,argc,sizeof(char *),cmp);
    for(i=0;i<argc;i++)
    {
    printf("%s \n",argv[i]);
    }
}

/*int CompareStrings(const char *a, const char *b)
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
}*/

int cmp(const void *pa, const void *pb)
{
    const char **a=(const char**)pa;
    const char **b=(const char**)pb;
    return strcmp(*a,*b);
}
