int Qput(Queue_t *q,int a)
{
    if(Qfull)
    {
        return 0;
    }
   q->pElements=a;
   q->tail++;
   return 1;
}

int Qfull (Queue_t *q)
{
    if((q->tail+1)%N==q->head)
    {
        return 1;
    }
    return 0;
}

int Qget (Queue_t *q, int *a)
{
    if(Qempty)
    {
        return 0;
    }
    *a=q->pElements;
    q->head++;
    return 1;
}

int Qempty(Queue_t *q)
{
    if(q->pElements==0)
    {
        return 1;
    }
    return 0;
}
