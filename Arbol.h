
typedef struct TNode {
int cont;
struct TNode *pLeft;
struct TNode *pRight;
} *Tree_t;


int TreeNumNodes(Tree_t t);
int TreeIsMember(int x, Tree_t t);
int TreeHeight(Tree_t t);
Tree_t TreeCreateNode(int e);
Tree_t TreeInsertOrdered(int x, Tree_t t);
void TreePrint(Tree_t t);
void TreeDestroy(Tree_t t);
