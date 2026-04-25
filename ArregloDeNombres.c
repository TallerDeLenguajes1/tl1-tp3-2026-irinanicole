#include <stdio.h>
#include <stdlib.h>
#include <string.h>

const int TAMA = 5;

void mostrarPersonas(char * personas[]); //1er commit
void buscarNombrePorID(char * personas[], int id); //2do commit
void buscarNombrePorPALABRA(char * personas[], char * sub_palabra);

int main ()
{
    // 1er commit
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
    //
    mostrarPersonas(personas);

    // 2do commit
    int indice;
    // 3er commit
    char * palabraClave;
    // INTERFAZ DE USUARIO (último commit: parte3) //
    int opcion;

    printf("\n----- INTERFAZ DE USUARIO -----\n");
    printf("\nIngrese una opcion para buscar un nombre: ");
    scanf("%d",&opcion);
    switch (opcion)
    {
        case 1:
            printf("\nPOSICION del nombre que busca: ");
            scanf("%d",&indice);
            buscarNombrePorID(personas, indice);
            break;
        case 2:
            getchar();
            printf("\nIngresar parte del nombre buscado: ");
            gets(palabraClave);
            buscarNombrePorPALABRA(personas, palabraClave);
            break;
        default:
            printf("\nLa opcion de busqueda no es valida");
            break;
    }
    printf("\n\n----- FIN DEL PROGRAMA -----\n");
    
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
    printf("]\n");
}
// 2do commit
void buscarNombrePorID(char * personas[], int id)
{
    if (TAMA >= id)
    {
        printf("\nNombre ubicado en la posicion %d: ",id);
        puts(personas[id-1]);
    }
    else
    {
        printf("\nNo se encontro el valor buscado");
    }
}

void buscarNombrePorPALABRA(char * personas[], char * sub_palabra)
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