#define TREE_EMPTY NULL
#define TREE_CONT(t) ((t)->cont)
#define TREE_LEFT(t) ((t)->pLeft)
#define TREE_RIGHT(t) ((t)->pRight)




// retorna la cantidad de nodos del �rbol
int TreeNumNodes(Tree_t t)
{
if(t == TREE_EMPTY)
return 0;
return 1 + TreeNumNodes(TREE_LEFT(t))
+ TreeNumNodes(TREE_RIGHT(t));
}


// retorna verdadero/falso indicando si x existe o n� dentro de t




int TreeIsMember(int x, Tree_t t)
{
if(t == TREE_EMPTY) // �rbol vac�o -> x no es miembro
return 0;
if(TREE_CONT(t) == x) // x est� en la cabeza de t -> existe
return 1;
if( TREE_CONT(t) > x) // si est�, est� en el lado izquierdo
return TreeIsMember(x, TREE_LEFT(t));
return TreeIsMember(x, TREE_RIGHT(t)); // si no en el derecho
}






int TreeHeight(Tree_t t)
{
int hl, hr;
if(t == TREE_EMPTY)
return 0;
hl = TreeHeight(TREE_LEFT(t));
hr = TreeHeight(TREE_RIGHT(t));
return 1 + ((hl > hr) ? hl : hr);
}




// funci�n auxiliary para crear un �rbol de un solo nodo
Tree_t TreeCreateNode(int e)
{
Tree_t nT = (Tree_t) malloc(sizeof(struct TNode));
assert(nT);
TREE_CONT(nT) = e;
TREE_LEFT(nT) = TREE_RIGHT(nT) = TREE_EMPTY;
return nT;
}




// hace insersi�n ordenada en el �rbol
Tree_t TreeInsertOrdered(int x, Tree_t t)
{
if(t == TREE_EMPTY)
return TreeCreateNode(x);
if(TREE_CONT(t) >= x)
TREE_LEFT(t) = TreeInsertOrdered(x, TREE_LEFT(t));
else
TREE_RIGHT(t) = TreeInsertOrdered(x, TREE_RIGHT(t));
return t;
}




// Imprime el contenido del �rbon en forma ordenada
void TreePrint(Tree_t t)
{
if(t != TREE_EMPTY) {
TreePrint(TREE_LEFT(t));
printf("%d\n", TREE_CONT(t));
TreePrint(TREE_RIGHT(t));
}
}



// destruye el �rbol, liberando recursos
void TreeDestroy(Tree_t t)
{
if(t != TREE_EMPTY) {
TreeDestroy(TREE_LEFT(t));
TreeDestroy(TREE_RIGHT(t));
free(t);
}
}
