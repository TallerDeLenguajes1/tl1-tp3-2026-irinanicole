#include <stdio.h>
#include <stdlib.h>
#include <string.h>

const int CANTIDAD = 5;

void mostrar_personas(char ** personas);

int main ()
{
    char * personas[5];

    for (int i=0; i < CANTIDAD; i++) {
        char cadena[50];
        printf("Ingrese el nombre de la persona %d: ",i+1);
        gets(cadena);
        int longitud = strlen(cadena);

        char * nombre;
        nombre = (char *)malloc(longitud * sizeof(char) + 1); //cantidad de char que se requiere +1 ('\0' -> fin de la cadena)
        strcpy(nombre, cadena);
        personas[i] = nombre;
        puts(personas[i]);
    }

    mostrar_personas(personas);
    
    getchar();
}

void mostrar_personas(char ** personas)
{
    printf("[");
    for (int i=0; i < CANTIDAD; i++)
    {
        printf("%s ; ", personas[i]);
    }
    printf("]");
}