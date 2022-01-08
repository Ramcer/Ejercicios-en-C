#include <stdio.h>
#include <stdlib.h>

double **AllocaMatSimetrica(int n);
void SetElement(double **pMat, int n, int i, int j, double X);
double GetElement(double **pMat, int n, int i, int j);


int main()
{
    int n,k;
    int i,j;
    double **MS,X;
    printf("Ingrese el tamaño de la matriz\n");
    MS=AllocaMatSimetrica(n);
    scanf("%d",&n);
    printf("Ingrese, el numero a colocar");
    scanf("%lf",&X);
    printf("Ingrese, el numero de fila");
    scanf("%d",&i);
    printf("Ingrese, el numero de columna");
    scanf("%d",&j);
    SetElement(MS,n,i,j,X);
    printf("%lf\n ",GetElement(MS,n,i,j));
    LiberaMatSimetrica(MS,n);
    return 0;
}

double **AllocaMatSimetrica(int n)
{
    int i;
    double **v;
    v=(double **) malloc(n* sizeof(double*));
    for(i=0; i<n; i++)
    {
        v[i]=(double *) malloc((i+1)* sizeof(double));
    }
    return v;
}

void SetElement(double **pMat, int n, int i, int j, double X)
{
    int aux;
    if(j>i)
    {
        aux=j;
        j=i;
        i=aux;
    }
    pMat[i][j]=X;
}


double GetElement(double **pMat, int n, int i, int j)
{
    int aux;
    if(j>i)
    {
    return pMat[j][i];
    }
    //("%lf\n",pMat[i][j]);
    return pMat[i][j];
}

void LiberaMatSimetrica(double **pMat, int n)
{
    for(int i=0; i<n; i++)
{
    free(pMat);
}
}
