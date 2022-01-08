#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <ctype.h>
int main()
{
    char Caracteres[]="hola mundo 1123 A/aAqjwj";
    int CaracteresAl[25]={0}, CaracteresNum[10]={0};
    int i,j,Nocaracter=0,b;
    char a;
    //FILE *2017
    /*2017=fopen("2017.txt","r");                         //Abro el archivo
    for(i=0,(1==fscanf(2017,"%c",&Caracteres[i]),i++)   //Recorro el archivo y asigno el caracter a CARACTERES[i]
    {
    print("Se leyo el caracter numero %d",i);
    }
    fclose(2017);*/
    /*Ahora trabjare solo con mi string "Caracteres"*/
    printf("Ingrese el texto a continuacion \n");
    //scanf("%s",Caracteres);
    for(i=0; Caracteres[i]!=0; i++)              //Leo los caracteres
    {
        if(isalnum(Caracteres[i])!=0)            //verifico que los caracteres sean alfanumericos
        {
            if(isalpha(Caracteres[i])!=0)        //Verifico que sea alfabetico
            {
                if(isupper(Caracteres[i])!=0)    //verifico si el alfabetico esta en mayuscula
                {
                    for(a='A',j=0; a<='Z'; a++,j++)      //Busco el caracter al cual es igual
                    {
                        if(a==Caracteres[i])
                        {
                            CaracteresAl[j]++;
                            break;
                        }
                    }
                }
                else
                {
                    for(a='a',j=0; a<='z'; a++,j++)
                    {
                        if(a==Caracteres[i])
                        {
                            CaracteresAl[j]++;
                            break;
                        }
                    }
                }
            }
            else
            {
                for(a='0',j=0; a<='9'; a++,j++)
                {
                    if(a==Caracteres[i])
                    {
                        CaracteresNum[j]++;
                        break;
                    }
                }

            }

        }
        else
        {
            Nocaracter++;
        }
    }
 b=0;
    for(j=0; j<=24; j++)
    {
       if(CaracteresAl[j]>CaracteresAl[b])
       {
           b=j;
       }
    }
    a='a'+b;
    printf("El alfanumerico mas que mas aparecio es: %c \n",a);
   b=0;
    for(j=0; j<=9; j++)
    {
       if(CaracteresNum[j]>CaracteresNum[b])
       {
           b=j;
       }
    }
    a='0'+b;
    printf("El Numero que mas aparecio es: %c \n",a);
    printf("Los no caracteres fuero: %d \n",Nocaracter);

}
