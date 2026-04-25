#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>

// CONSTANTES
#define N 5

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

// FUNCIONES PARA EL SISTEMA
float calcularCostoTotalProducto(Producto producto_j); // devuelve el costo total del producto (cantidad * precioUnitario)
void mostrarVentas(Cliente * clientes, int cant_clientes);


int main()
{
    // semilla para el rand()
    srand(time(NULL));

    // arreglo de los tipos de productos
    char *TiposProductos[N] = {"Galletas", "Snacks", "Cigariilos", "Caramelos", "Bebidas"};
    int cantidad_tipo_prod = N;
    // arreglo para los precios de los tipos de productos (valores flotantes aleatorios entre 10 y 100)
    float preciosTiposProductos[N]; // defino un arreglo que contenga los precios unitarios de cada tipo de producto
    
    // defino parámetros para formar los numeros aleatorios flotantes para el arreglo 'preciosTiposProductos[]'
    int precio_min=10, precio_max=100; // defino un rango de valores para el precio
    float precio_unit_producto, parteEntera, parteDecimal; // parte entera y decimal para liuego ser sumadas
    
    // calculo el precio para cada item del arreglo 'preciosTiposProductos[]'
    for (int tipoProducto_i = 0; tipoProducto_i < N; tipoProducto_i++)
    {
        parteEntera = (float) (precio_min + rand() % (precio_max-precio_min+1));
        parteDecimal = (float) (rand() % (100+1)) / (float) 100;
        preciosTiposProductos[tipoProducto_i] = parteEntera + parteDecimal;
    }
    //

    // INTERFAZ DE USUARIO: solicitar la cantidad de clientes //
    int cantidadClientes;
    printf("\n----- INTERFAZ DE USUARIO -----\n");
    printf("\nIngrese la CANTIDAD de CLIENTES: ");
    scanf("%d",&cantidadClientes);
    
    // reservo memoria para un arreglo dinamico de CLIENTES
    Cliente * clientes = (Cliente *) malloc(sizeof(Cliente) * cantidadClientes);

    printf("\n-->CARGA DE CLIENTE(S)<--\n");
    int opcion;
    char Buff[50];
    for(int i = 0; i < cantidadClientes; i++)
    {
        // ID_CLIENTE
        clientes[i].clienteID = i;
        
        // NOMBRE_CLIENTE
        getchar();
        printf("\nNOMBRE cliente %d: ", i+1);
        gets(Buff);
        // reservo memoria para el nombre del cliente
        clientes[i].nombreCliente = (char *) malloc(sizeof(char) * strlen(Buff));
        strcpy(clientes[i].nombreCliente, Buff);
        
        // CANTIDAD_PRODUCTOS_A_PEDIR-> ALEATORIOS (entre 1 y 5)
        clientes[i].cantidadProductosAPedir = 1 + rand() % 5;
        
        // CARGA_DE_PRODUCTOS
        // reservo memoria para cada producto 'cantidadProductosAPedir' veces...
        clientes[i].productos = (Producto *) malloc(sizeof(Producto) * clientes[i].cantidadProductosAPedir);
        printf("\n-->CARGA DE PRODUCTO(S)<-- (cliente[%d] -> %s)", i+1, clientes[i].nombreCliente);
        printf("\nCantidad de Productos para elegir: %d", clientes[i].cantidadProductosAPedir);
        // comienzo a llenar los datos en cada producto para 'cliente[i]':
        for (int j = 0; j < clientes[i].cantidadProductosAPedir; j++)
        {
            // ID_producto
            (clientes + i)->productos[j].productoID = j;
            // CANTIDAD del producto
            (clientes + i)->productos[j].cantidad = 1 + rand() % 10;
            // TIPO_producto
            printf("\n**Producto[%d]**\n>>Eliga OPCION para resgistrar el TIPO DE PRODUCTO<<",j+1);
            for (int k = 0; k < cantidad_tipo_prod; k++)
            {
                printf("\nOp:%d -> %s",k+1,TiposProductos[k]);
            }
            printf("\nOpcion: ");
            scanf("%d",&opcion);      
            (clientes + i)->productos[j].TipoProducto = TiposProductos[opcion-1];
            // PRECIO_UNITARIO_producto
            (clientes + i)->productos[j].precioUnitario = preciosTiposProductos[opcion-1];
            //
        }
    }
    
    // llamo a la funcion mostrarVentas() e imprimo todo por pantalla
    mostrarVentas(clientes, cantidadClientes);
    //

    // LIBERO MEMORIA: por todos los PRODUCTOS CREADOS para un cliente y el NOMBRE_CLIENTE
    for (int index = 0; index < cantidadClientes; index++)
    {
        free(clientes[index].productos);
        free(clientes[index].nombreCliente);
    }
    // LIBERO MEMORIA: por el arreglo de todos los clientes
    free(clientes);
    //

    printf("\n----- FIN DEL PROGRAMA -----\n");
    getchar();
    return 0;
}

/*
    Esta función debe recibir como parámetro el producto y 
    devolver el resultado de calcular la Cantidad por el PrecioUnitario.
*/
float calcularCostoTotalProducto(Producto producto_j)
{
    return (producto_j.precioUnitario * producto_j.cantidad);
}

void mostrarVentas(Cliente * clientes, int cant_clientes)
{
    float costoTotalProducto_j, costoTotalAPagar;
    printf("\n\n---> MUESTRA DE DATOS: CLIENTES <---\n\n");
    for (int i = 0; i < cant_clientes; i++)
    {
        costoTotalAPagar = 0;
        printf("\n------------------------------");
        //imprimo DATOS del cliente.
        printf("\n>>[CLIENTE: %d]<<\nID_cliente: %d\nNombre: %s\nProductos Solicitados: %d\n",
            i+1, 
            clientes[i].clienteID, 
            clientes[i].nombreCliente, 
            clientes[i].cantidadProductosAPedir);
        for (int j = 0; j < clientes[i].cantidadProductosAPedir; j++)
        {
            printf("\n**[PRODUCTO: %d]**\nID_producto: %d\nTipo: %s\nPrecio(xUnidad): $%f\nCantidad: %d",
                j+1, 
                clientes[i].productos[j].productoID, 
                clientes[i].productos[j].TipoProducto, 
                clientes[i].productos[j].precioUnitario, 
                clientes[i].productos[j].cantidad);
            // Calculo el costo Total del producto[j] (para un producto específico)
            costoTotalProducto_j = calcularCostoTotalProducto((clientes+i)->productos[j]); //implemento funcion para el calculo
            printf("\n---> El costo total de este prodcuto es: $%f\n", costoTotalProducto_j);
            costoTotalAPagar += costoTotalProducto_j; // voy sumando todos los 'costoTotalProducto_j' de cada producto;
        }
        printf("\n------------------------------");
        printf("\nEl monto total a pagar por este cliente es: $%f", costoTotalAPagar);
        printf("\n------------------------------\n");
    }
    
}