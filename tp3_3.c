#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>

// DISTRIBUIDORA

// ESTRUCTURAS

typedef struct Producto{
    int productoID;         // Numerado en ciclo iterativo
    int cantidad;           // entre 1 y 10
    char *TipoProducto;     // Algún valor del arreglo TiposProductos[]
    float precioUnitario;   // entre 10 - 100
} Producto;

typedef struct Cliente{
    int clienteID;                  // Numerado en el ciclo iterativo
    char *nombreCliente;            // Ingresado por usuario
    int cantidadProductosAPedir;    // aleatorio entre 1 y 5
    Producto *productos;            // El tamaño de este arreglo depende de la variable:
                                    // "cantidadProductosAPedir"
} Cliente;


int main()
{
    srand(time(NULL));
    char *TiposProductos[] = {"Galletas", "Snacks", "Cigariilos", "Caramelos", "Bebidas"};
    int cantidad_tipo_prod = 5;
    // INTERFAZ DE USUARIO: solicitar la cantidad de clientes //
    int cantidadClientes;
    printf("\n----- INTERFAZ DE USUARIO -----\n");
    printf("\nIngrese la CANTIDAD de CLIENTES: ");
    scanf("%d",&cantidadClientes);
    
    // reservo memoria para un arreglo dinamico de CLIENTES
    Cliente * clientes = (Cliente *) malloc(sizeof(Cliente) * cantidadClientes);

    printf("\n-->CARGA DE CLIENTES<--\n");
    int i, opcion;
    int precio_min=10, precio_max=100;
    float precio_unit_producto, parteEntera, parteDecimal;
    char Buff[50];
    for(i = 0; i < cantidadClientes; i++)
    {
        // ID_CLIENTE
        clientes[i].clienteID = i;
        // NOMBRE_CLIENTE
        getchar();
        printf("\nNOMBRE cliente %d: ", i+1);
        gets(Buff);
        clientes[i].nombreCliente = (char *) malloc(sizeof(char) * strlen(Buff));
        strcpy(clientes[i].nombreCliente, Buff);
        // CANTIDAD_PRODUCTOS_A_PEDIR-> ALEATORIOS (entre 1 y 5)
        clientes[i].cantidadProductosAPedir = 1 + rand() % 5;
        // CARGA_DE_PRODUCTOS
        clientes[i].productos = (Producto *) malloc(sizeof(Producto) * clientes[i].cantidadProductosAPedir);
        printf("\n-->CARGA DE PRODUCTOS<-- (para cliente[%d]-> %s)", i+1, clientes[i].nombreCliente);
        printf("\nCantidad de Productos para elegir: %d", clientes[i].cantidadProductosAPedir);
        for (int j = 0; j < clientes[i].cantidadProductosAPedir; j++)
        {
            printf("\n**Producto[%d]**",j+1);
            // ID_producto
            (clientes + i)->productos[j].productoID = j;
            // CANTIDAD del producto
            (clientes + i)->productos[j].cantidad = 1 + rand() % 10;
            // TIPO_producto
            printf("\n>>Eliga OPCION para resgistrar el TIPO DE PRODUCTO<<");
            for (int k = 0; k < cantidad_tipo_prod; k++)
            {
                printf("\nOp:%d -> %s",k+1,TiposProductos[k]);
            }
            printf("\nOpcion: ");
            scanf("%d",&opcion);      
            (clientes + i)->productos[j].TipoProducto = TiposProductos[opcion-1];
            // PRECIO_UNITARIO_producto
            parteEntera = (float) (precio_min + rand() % (precio_max-precio_min+1));
            parteDecimal = (float) (rand() % (100+1)) / (float) 100;
            (clientes + i)->productos[j].precioUnitario = parteEntera + parteDecimal;
        }

    }
    

    // LIBERO MEMORIA: por cada PRODUCTOs creados y el NOMBRE_CLIENTE
    for (i = 0; i < cantidadClientes; i++)
    {
        free(clientes[i].productos);
        free(clientes[i].nombreCliente);
    }
    // LIBERO MEMORIA: por el arreglo de todos los clientes
    free(clientes);
    //
    printf("\n----- FIN DEL PROGRAMA -----\n");
    return 0;
}