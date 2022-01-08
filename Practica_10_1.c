#include <stdio.h>
#include <stdlib.h>
#include <math.h>
typedef double(*fun_ptr_type)(double);
double integra(double a, double b, fun_ptr_type fun, int n);
double cuadratica(double x);
int main()
{
    double V=0,VA=0;
    int m=2;
    V=integra(0,3,cos,m);
    VA=V+10;
    while(fabs(V-VA)>pow(10,-3))
    {
        m=2*m;
        VA=V;
        V=integra(0,3,cos,m);
    }

    printf("%lf \n",V);

}
double integra(double a, double b, fun_ptr_type fun,int n)
{
    double lol=0;
    for(int i=1;i<n;i++)
    {
        lol=lol+fun(a+i*(b-a)/n);
    }
    return (((b-a)/n)*((fun(a)+fun(b))/2+lol));
}

double cuadratica(double x)
{
    return x*x;
}
