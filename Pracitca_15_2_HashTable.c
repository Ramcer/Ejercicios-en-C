#include <stdio.h>
#include <stdlib.h>
#define NOMBRE_SZ 32
#define DOMICILIO_SZ 64
typedef struct
{
    char nombre[NOMBRE_SZ];
    unsigned dni;
    char domicilio[DOMICILIO_SZ];
// ...
} Persona_t;
typedef struct HashEntry_str
{
    unsigned dni; // clave indexada
    int nroRegistro; // nro de registro en la tabla maestra
    struct HashEntry_str *next;
} *HashEntry_t;
typedef struct
{
    unsigned numEntries;
    HashEntry_t *entries;
} HashTable_t;











HashTable_t *HashTableCreate(unsigned numEntries);

void HashTableFill(HashTable_t *ht, Persona_t *personas, unsigned nPers);


int HashTableSearch(HashTable_t *ht, unsigned dni);


void GuardarPersona (HashEntry_t HE,Persona_t *p,HashTable_t *HT);


int BuscarPersona(HashEntry_t he,unsigned dni);


double HashTableAverageColisionLength(HashTable_t *ht);


void HashTableDestroy(HashTable_t *ht);


int main()
{


}



HashTable_t *HashTableCreate(unsigned numEntries)
{
    HashTable_t *HT=malloc(numEntries*(sizeof(HashTable_t)));
    //for() HACE FALTA HACER MALLOC A CADA UNA DE LAS ENTRIES? PREGUNTAR
    for(int i=0; i<numEntries; i++)
    {
        HT->entries[i]=malloc(sizeof(HashEntry_t));
        HT->entries[i]=NULL;
    }
    //Preguntar si puedo usar calloc.
    return HT;
}


void HashTableFill(HashTable_t *ht, Persona_t *personas,unsigned nPers)
{
    int n;
    for(int i=0; i<nPers; i++)
    {
        n=personas[i].dni%ht->numEntries;
        GuardarPersona(ht->entries[n],personas+i,ht);
    }
}

int HashTableSearch(HashTable_t *ht, unsigned dni)
{
    int n=dni%ht->numEntries;
    n=BuscarPersona(ht->entries,dni);//PREGUNTAR SI PUEDO SUAR EL MISMO n!!!
    return n;
}



void GuardarPersona (HashEntry_t HE,Persona_t *p,HashTable_t *HT)
{
    if(HE==NULL)
    {
        malloc(sizeof(struct HashEntry_str));
        HE->dni=p->dni;
        HE->nroRegistro=p->dni%HT->numEntries;
        return ;
    }
    else
        GuardarPersona(HE->next,p,HT);
    return;
}


int BuscarPersona(HashEntry_t he,unsigned dni)
{
    int n;

    if(he->dni==dni)
    {
        return he->nroRegistro;
    }
    if(he->next==NULL)
    {
        return n=-1;
    }
    else
        return  BuscarPersona(he->next,dni);
}



double HashTableAverageColisionLength(HashTable_t *ht)
{
    int Numero_de_listas_no_vacias=0;
    int Numero_de_nodos=0;
    for(int i=0; i<ht->numEntries; i++)
    {
        if(ht->entries[i]!=NULL)
        {
            Numero_de_listas_no_vacias++;
            NumeroNodos(ht->entries[i],&Numero_de_nodos);
        }
    }
    return (1-(Numero_de_nodos/Numero_de_listas_no_vacias));
}



int NumeroNodos(HashEntry_t he, int* p)
{
    if(he->next==NULL)
    {
        return *p++;
    }
    else
    {
        *p++;
        NumeroNodos(he->next,p);
    }
}



void HashTableDestroy(HashTable_t *ht)
{
    for(int i=0; i<ht->numEntries; i++)
    {
        if(ht->entries[i]->next!=NULL)
        {
            HashTableDestroy(ht->entries[i]);
        }
        else
        {
            free(ht->entries[i])
        }
    }
}
