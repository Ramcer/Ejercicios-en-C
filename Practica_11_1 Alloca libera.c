#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include <time.h>


void liberaVector(double *vec);
double *AllocVector(int n);
void FillRandVector(double *pVect, int n);
int comparar(const void *A,const void *B);
void imprimeVector(int n, double *vec);

int main()
{
    double *v={0};
    int n=10000000;
    //printf("Ingrese el valor del numero de elementos\n");
    //scanf("%d",&n);
    v=AllocVector(n);
    FillRandVector(v,n);
    clock_t t1=clock();
    SortVector(v,n);
    printf("%lf\n",((double)(clock()-t1)/CLOCKS_PER_SEC));
    printf("%d\n",CLOCKS_PER_SEC);
    //imprimeVector(n,v);
    //imprime
}

double *AllocVector(int n)
{
    double *v = (double *) malloc(n * sizeof(double));
    assert(v!=NULL);
    return v;
}

void liberaVector(double *vec)
{
    free(vec);
}

void FillRandVector(double *pVect, int n)
{
    int i;
    double a;
    srand(time(NULL));
    for(i=0; i<n; i++)
    {
        a=rand();
        a=a/RAND_MAX*1.0;
        pVect[i]=a;
    }

}

void SortVector(double *pVect, int n)
{
    qsort(pVect,n,sizeof(double),comparar);
}

int comparar(const void *A,const void *B)
{
    double *pA=(double*)A;
    double *pB=(double*)B;
    return *pA<*pB?1:-1;
}

void imprimeVector(int n, double *vec)
{
    int i;
    for( i = 0; i < n; i++ )
        printf("%lf\n", vec[i]);
}



