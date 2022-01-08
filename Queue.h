typedef struct {
unsigned int tail;
unsigned int head;
unsigned int qSize;
int *pElements;
} Queue_t;

int Qput(Queue_t *q,int a);
int Qget();
int Qfull();
int Qempty ();
