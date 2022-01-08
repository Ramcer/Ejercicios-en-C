#define TREE_EMPTY NULL
#define TREE_CONT(t) ((t)->cont)
#define TREE_LEFT(t) ((t)->pLeft)
#define TREE_RIGHT(t) ((t)->pRight)




// retorna la cantidad de nodos del árbol
int TreeNumNodes(Tree_t t)
{
if(t == TREE_EMPTY)
return 0;
return 1 + TreeNumNodes(TREE_LEFT(t))
+ TreeNumNodes(TREE_RIGHT(t));
}


// retorna verdadero/falso indicando si x existe o nó dentro de t




int TreeIsMember(int x, Tree_t t)
{
if(t == TREE_EMPTY) // árbol vacío -> x no es miembro
return 0;
if(TREE_CONT(t) == x) // x está en la cabeza de t -> existe
return 1;
if( TREE_CONT(t) > x) // si está, está en el lado izquierdo
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




// función auxiliary para crear un árbol de un solo nodo
Tree_t TreeCreateNode(int e)
{
Tree_t nT = (Tree_t) malloc(sizeof(struct TNode));
assert(nT);
TREE_CONT(nT) = e;
TREE_LEFT(nT) = TREE_RIGHT(nT) = TREE_EMPTY;
return nT;
}




// hace insersión ordenada en el árbol
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




// Imprime el contenido del árbon en forma ordenada
void TreePrint(Tree_t t)
{
if(t != TREE_EMPTY) {
TreePrint(TREE_LEFT(t));
printf("%d\n", TREE_CONT(t));
TreePrint(TREE_RIGHT(t));
}
}



// destruye el árbol, liberando recursos
void TreeDestroy(Tree_t t)
{
if(t != TREE_EMPTY) {
TreeDestroy(TREE_LEFT(t));
TreeDestroy(TREE_RIGHT(t));
free(t);
}
}
