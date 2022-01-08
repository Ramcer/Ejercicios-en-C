#include <stdio.h>
#include <stdlib.h>

void TransponeNN(double *matriz, int p);
void mostrar_matriz(double *a,int j);

#define n 10

int main()
{
    int i,j;
    double k=0;
    double a[n][n]={0};
    for(i=0;i<n;i++)
    {
        for(j=0;j<n;j++)
        {
            a[i][j]=1+k;
            k++;
        }
    }
    mostrar_matriz(a,n);
    TransponeNN(a,n);
    mostrar_matriz(a,n);
    return 0;
}

void TransponeNN(double *matriz, int p)
{
    double aux;
    int i=0,j=0;
    for(i=0; i<p; i++)
    {
         for(j=i+1; j<p; j++)

            {
                aux=matriz[i*p+j];
                matriz[i*p+j]=matriz[i+j*p];
                matriz[i+j*p]=aux;
            }
    }
}

void mostrar_matriz(double *a,int p)
{
    int i,j;
    for(i=0;i<p;i++)
    {
        for(j=0; j<p; j++)
        {
        printf("[%lf]\t",a[i*n+j]);
        }
        printf("\n");
    }
}
