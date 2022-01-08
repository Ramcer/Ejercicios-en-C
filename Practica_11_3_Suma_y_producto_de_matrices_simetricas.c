#include <stdio.h>
#include <stdlib.h>

void SetElement(double **pMat, int n, int i, int j, double X);
double GetElement(double **pMat, int n, int i, int j);
double **AllocaMatSimetrica(int n);
double **AllocaMat (int n);
int main()
{
    int j,i,n=2;
    double X;
    double **MS1,**MS2,**Suma,**producto;
    MS1=AllocaMatSimetrica(n);
    MS2=AllocaMatSimetrica(n);
    Suma=AllocaMatSimetrica(n);
    producto=AllocaMat(n);
    for(i=0; i<n; i++)
    {
        for(j=0; j<=i; j++)
        {
            printf("Ingrese, el numero a colocar MS1[%d][%d]",i,j);
            scanf("%lf",&X);
            SetElement(MS1,n,i,j,X);
        }
    }
    for(i=0; i<n; i++)
    {
        for(j=0; j<=i; j++)
        {
            printf("El numero es MS1[%d][%d]=%lf\n",i,j,GetElement(MS1,n,i,j));
        }
    }
    for(j=0; j<n; j++)
    {
        for(i=0; i<=j; i++)
        {
            printf("Ingrese, el numero a colocar MS2[%d][%d]\n",j,i);
            scanf("%lf",&X);
            SetElement(MS2,n,i,j,X);
        }
    }
    for(i=0; i<n; i++)
    {
        for(j=0; j<i+1; j++)
        {
            Suma[i][j]=GetElement(MS1,n,i,j)+GetElement(MS2,n,i,j);
        }
    }
    for(int l=0; l<n; l++)
    {
        for(int k=0; k<n; k++)
        {
             producto[l][k]=0;
            for(i=0; i<n; i++)
            {
                for(j=0; j<n-1; j++)
                {
                    printf("Sumaremos el producto de %lf y %lf\n",MS1[j][i],MS2[i][j]);
                    producto[l][k]=producto[l][k]+GetElement(MS2,n,j,i)*GetElement(MS2,n,i,j);
                }
            }

        }
    }
    for(int l=0; l<n; l++)
    {
        for(int k=0; k<n; k++)
        {
            printf("[%d],[%d] = %lf \t",i,j,producto[l][k]);
        }
        printf("\n");
    }
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
    if(j>i)
    {
        return pMat[j][i];
    }
    return pMat[i][j];
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

double **AllocaMat(int n)
{
    double **v;
    v=(double **) malloc(n* sizeof(double*));
    for(int i=0; i<n; i++)
    {
        v[i]=(double *) malloc(n* sizeof(double));
    }
    return v;
}
