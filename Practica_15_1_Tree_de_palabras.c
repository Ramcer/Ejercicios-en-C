#include <stdio.h>
#include <stdlib.h>
#include <string.h>



typedef enum { FALSE, TRUE } BOOL;
#define ALPHABET_SIZE 26



typedef struct trie_node
{
    BOOL defineKey; // true/false si define o no una clave
    struct trie_node *children[ALPHABET_SIZE];
} Trie_node_t;



typedef struct
{
    Trie_node_t *root; // contenedor real de datos
    unsigned int numKeys; // n�mero de claves en el trie
} Trie_t;


// crea un trie vacio y lo retorna
Trie_t *trieCreate();




// inserta una nueva clave si no est� presente o
// lo marca con defineKey si ya exist�a como prefix de otras claves
void trieInsertKey(Trie_t *pTrie, const char *key);



//Crea un root
Trie_node_t *createnode();




// retorna verdadero/falso indicando si la clave existe.
BOOL trieExistKey(Trie_t *pTrie, const char *key);








// Chequea la consistencia entre la cantidad de nodos que dice el
// trie y la cantidad de nodos que definen key.
// Retorna TRUE/FALSE indicando si hay o n� consistencia.
BOOL trieCheck(Trie_t *pTrie);





//CHEUQEA LOS TRUE DE LOS NODOS
int check_nodo(Trie_node_t *p);






// Retorna la cantidad de claves que tienen un prefix determinado.
int trieNumWordsWithPrefix(Trie_t *pTrie, const char *prefix);








int main()
{
Trie_t *a;
a=trieCreate();
trieInsertKey(a,"mujeres");
trieInsertKey(a,"mujer");
trieInsertKey(a,"nohay");
if(trieCheck(a))
    return printf("\nTodo ok");
}



Trie_node_t *createnode()
{
    Trie_node_t *root=malloc(sizeof(Trie_node_t));
    for(int i=0; i<ALPHABET_SIZE; i++)
    {
        root->children[i]=NULL;
    }
    root->defineKey=FALSE;
    return root;
}




Trie_t *trieCreate()
{
    Trie_t *ptn= (Trie_t*)malloc(sizeof(Trie_t));
    ptn->root=createnode();
    ptn->numKeys=0;
    return ptn;
}



void insertar_clave(Trie_node_t *a,const char *key)
{
    if(*key!=0)
    {
        if(a->children[*key-'a']==NULL)
        {
            a->children[*key-'a']=createnode();
            insertar_clave(a->children[*key-'a'],key+1);
        }
        else
        {
            insertar_clave(a->children[*key-'a'],key+1);
        }
    }
    else
    {
        a->defineKey=TRUE;
        return;
    }
}










void trieInsertKey(Trie_t *pTrie, const char *key)
{
    insertar_clave(pTrie->root,key);
    pTrie->numKeys++;
    return;
}










BOOL trieExistKey(Trie_t *pTrie, const char *key)
{
    Trie_node_t *p;
    p=pTrie->root;
    for(int i=0; key[i]!=0; i++)
    {
        if(p->children[key[i]-'a']==NULL)
            return FALSE;
        else
        {
            p=p->children[key[i]-'a'];
        }
    }
    return p->defineKey;
}





BOOL trieCheck(Trie_t *pTrie)
{
    int T;
    T=check_nodo(pTrie->root);
    if(T==pTrie->numKeys)
    {
        return TRUE;
    }
    else return FALSE;
}


int check_nodo(Trie_node_t *p)
{
    int t=0;
    if(p->defineKey==TRUE)
    {
        t++;
    }
    for(int i=0; i<ALPHABET_SIZE; i++)
    {
        if(p->children[i]!=NULL)
        {
            t=t+check_nodo(p->children[i]);
        }

    }
    return t;
}






//int trieNumWordsWithPrefix(Trie_t *pTrie, const char *prefix)

