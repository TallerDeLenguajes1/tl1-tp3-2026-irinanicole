#include <stdio.h>
#include <stdlib.h>
#include <string.h>

const int TAMA = 5;

void mostrarPersonas(char * personas[]);

int main ()
{
    char * personas[5];
    char buff[50];

    for (int i=0; i < TAMA; i++) {
        printf("NOMBRE de persona %d: ",i+1);
        gets(buff);
        //
        personas[i] = (char *)malloc(strlen(buff) * sizeof(char) + 1); //cantidad de char que se requiere +1 ('\0' -> fin del buff)
        strcpy(personas[i], buff);
        //puts(personas[i]);
    }

    mostrarPersonas(personas);
    
    for (int i=0; i < TAMA; i++) {
        free(personas[i]);
    }
    getchar();
}

void mostrarPersonas(char * personas[])
{
    printf("\nArreglo-Nombres\n[");
    for (int i=0; i < TAMA; i++)
    {
        printf("%s", personas[i]);
        if (i != TAMA-1)
        {
            printf(", ");
        }
    }
    printf("]");
}