#include <stdio.h>
#include <stdlib.h>
#include <string.h>

const int TAMA = 5;

void mostrarPersonas(char * personas[]);
void buscarNombre(char * personas[], char * sub_palabra);

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
    //
    char * palabraClave;
    printf("\nIngresar parte del nombre buscado: ");
    gets(palabraClave);
    buscarNombre(personas, palabraClave);
    
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

void buscarNombre(char * personas[], char * sub_palabra)
{
    int band = 0;
    for (int i=0; i<TAMA; i++)
    {
        if (strstr(personas[i],sub_palabra))
        {
            printf("\nPRIMER NOMBRE coincidente: ");
            puts(personas[i]);
            band = 1;
            break;
        }
    }
    if(!band)
    {
        printf("\n(-1) >> No hubo coincidencias\n");
    }

}