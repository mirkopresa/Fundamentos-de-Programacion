// Una empresa de venta de productos alimenticios posee los siguientes listados:
// Listado de Stock:
//      Código de producto (entero de 4 cifras)
//      Cantidad en stock (real mayor que cero)
// Listado de Productos:
//      Código de producto (entero de 4 cifras)
//      Descripción (cadena de 200)
//      Precio unitario (real)
// Listado de Ventas
//      Código de producto (entero de 4 cifras)
//      Cantidad vendida en una venta (entero)
// Los listados de Stock y Productos están ordenados por código y no necesariamente todos los registros de uno están en el otro. 
// El listado de ventas corresponde a un día y no está ordenado.
// Se pide :
// a) Listar por pantalla la cantidad total vendida por producto.
// b) Listar por pantalla el monto de venta por producto y el monto total.
// c) Listar por pantalla el stock actualizado por producto, eliminando de la
// misma aquellos productos sin existencia y generando una lista aparte de faltantes.
#include <stdio.h>
#define MAX 50
#define MAX_STRING 200
typedef char str[MAX_STRING];
typedef struct {
    int codigo;
    int cantidad;
} t_stock;
typedef struct {
    int codigo;
    str descripcion;
    float precio;
} t_producto;
typedef struct {
    int codigo;
    int cantidad;
} t_venta;

void lista_productos_vendidos(t_producto productos[MAX], t_venta ventas_productos[MAX], int cantidad_productos, int cantidad_ventas)
{
    int cantidad_vendida, i, j;
    for (i = 0; i < cantidad_productos; i++)
    {
        cantidad_vendida = 0;
        for (j = 0; j < cantidad_ventas; j++)
        {
            if (productos[i].codigo == ventas_productos[j].codigo)
            {
                cantidad_vendida += ventas_productos[j].cantidad;
            }
        }
        printf("----------------------------\n");
        printf("Producto: %s\n", productos[i].descripcion);
        printf("Cantidad vendida: %i\n", cantidad_vendida);
    }
    printf("----------------------------\n");
}

void lista_monto_ventas(t_producto productos[MAX], t_venta ventas_productos[MAX], int cantidad_productos, int cantidad_ventas)
{
    int cantidad_vendida, i, j;
    float monto_total = 0;
    for (i = 0; i < cantidad_productos; i++)
    {
        cantidad_vendida = 0;
        for (j = 0; j < cantidad_ventas; j++)
        {
            if (productos[i].codigo == ventas_productos[j].codigo)
            {
                cantidad_vendida += ventas_productos[j].cantidad;
            }
        }
        printf("----------------------------\n");
        printf("Producto: %s\n", productos[i].descripcion);
        printf("Valor: %.2f\n", productos[i].precio);
        monto_total += cantidad_vendida * productos[i].precio;
    }
    printf("----------------------------\n");
    printf("Cantidad total recaudada entre todos los productos: %.2f", monto_total);
}

void lista_stock_actualizado()
{
    // falta terminar
}


int main()
{
    t_producto productos[MAX] = {
        {1000, "Arroz", 500},
        {1020, "Manzana", 30},
        {1070, "Coca", 2000.50},
        {1100, "Churrasco", 4500},
    };
    t_stock stock_productos[MAX] = {
        {1000, 50},
        {1010, 300},
        {1070, 40},
        {1100, 20},
    };
    t_venta ventas_productos[MAX] = {
        {1070, 2},
        {1070, 7},
        {1020, 20},
        {1100, 7},
        {1000, 43},
        {1000, 4},
    };
    int cantidad_productos = 4, cantidad_stock = 4, cantidad_ventas = 6;
    lista_productos_vendidos(productos, ventas_productos, cantidad_productos, cantidad_ventas);
    lista_monto_ventas(productos, ventas_productos, cantidad_productos, cantidad_ventas);
    return 0;
}