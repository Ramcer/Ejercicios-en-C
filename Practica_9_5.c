#include <stdio.h>
#include <stdlib.h>

typedef struct {
 char nombre[64];
 char apellido[64];
 int dni;
} Persona;

void CargaPersona(Persona *pPer);

int main()
{
  Persona A;
  CargaPersona(&A);
  puts(A.nombre);
  printf("\n");
  puts(A.apellido);
  printf("\n");
  printf("%d \n",A.dni);f
  printf("\n");
  return 0;
}



void CargaPersona(Persona *pPer)
{
    printf("Ingrese el nombre, Ingrese el apellido,Ingrese el dni  \n");

    scanf("%s",&(pPer->nombre));
    scanf("%s",&(pPer->apellido));
    scanf("%d",&(pPer->dni));
}
