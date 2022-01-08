#include <stdio.h>
#include <stdlib.h>
#include "../lib/list.h"


typedef int (*FilterFun) (int valor, void *params);
int pasabjo (int valor, void *params);
List_t invert(List_t ls);

List_t FilterList( List_t lst, FilterFun filtro, void *params);




int main()
{
List_t L=NULL,aux;
for(int i=0;i<15;i++)
{
            aux=__ListNodeCreate(i,L);
            L=aux;

}
ListPrint(L);
int par=6;
ListPrint(invert(FilterList(L,&pasabjo,&par)));
ListPrint(L);



}


List_t invert(List_t lst){
    List_t p=NULL,busca,aux;
    busca=lst;
    while(busca!=NULL)
    {
        aux=__ListNodeCreate(busca->cont,p);
        p=aux;
        busca=busca->pNext;
    }
    return p;
}

List_t FilterList( List_t lst, FilterFun filtro, void *params)
{
    List_t p=NULL,busca,aux;
    busca=lst;
    while(busca!=NULL)
    {
        if(!filtro(busca->cont,params))
        {
            aux=__ListNodeCreate(busca->cont,p);
            p=aux;
        }
        busca=busca->pNext;
    }
    return p;
}

int pasabjo (int valor, void *params)
{
    int *p;
    p=(int*)params;
    return valor<*p ? 0:1 ;
}
/*List_t FilterList( List_t lst, FilterFun filtro, void *params)
{
    List_t p=NULL,busca,aux;
    busca=lst;
    while(busca!=NULL)
    {
        if(!filtro(busca->cont,params))
        {
            aux=__ListNodeCreate(busca->cont,p);
            p=aux;
        }
    }
    return p;
}*/
