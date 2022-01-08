#include <stdio.h>
#include <stdlib.h>
#include<math.h>
// retorna la cantidad de bits en 1 presentes en la representacion de ‘value’
int numOnes(int value);
// devuelve el valor ‘value’, con el bit ‘bit’ en 1
int setBit(int value, int bit);
// devuelve el valor ‘value’, con el bit ‘bit’ en 0
int resetBit(int value, int bit);
// chequea si el bit ‘bit’ esta en 1
int testBit(int value, int bit);
void pasabinario(int n);



int main()
{
    int N,n;
    printf("Ingrese los numeros \n");
    scanf("%d",&N);
    printf("Ingrese el bit a cambiar o convertir \n");
    scanf("%d",&n);
    N=setBit(N,n);
    pasabinario(N);
    printf("\n");
    N=resetBit(N,n);
    pasabinario(N);
    printf("\n");
    N=testBit(N,n);
    pasabinario(N);
    printf("\n");
}



int numOnes(int value)
{ int i,res;
    for(i=0;i<sizeof(value);i++)
    {
      res+=value&1;
      value=value>>1;
    }
    return res;
}



int setBit (int value,int bit)
{
value=value|(1<<bit);
return value;
}
int resetBit(int value,int bit)
{
value = value & ~(1<<bit);
return value;
}
int testBit(int value,int bit)
{
   value = value & (1<<bit);
   return value;
}

void pasabinario(int n)
{
    int mayorExp = 0;
    while(pow(2,mayorExp+1) <= n){
        mayorExp += 1;
    }
    int exp;
    int auxiliar;
    for(int i = 0; i<= mayorExp; i++){
        exp = mayorExp - i;
        auxiliar = pow(2,exp);
        int c = 0;
        while((c+1)*(auxiliar)<= n){
            c++;
        }

        n = n - (c* auxiliar);
        if(c< 10){
            printf("%d",c);
        }else{
            char c_char = 'A' + c - 10;
            printf("%c",c_char);
        }



    }}
