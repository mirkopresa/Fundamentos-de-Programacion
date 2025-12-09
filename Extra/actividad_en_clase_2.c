// Se tiene un listado de 500 libros como máximo.
// Cada libro tiene:
// - ISBN (número 9 digitos / no correlativos)
// - Título (cadena de caracteres)
// - Fecha publicación (año, mes, día)

// Se pide:
// a) Definir las estructuras de datos y el modulo de carga de información
// b) Informar porcentaje de libros que tiene como año de publicacion a 2015.
// c) Indicar el año con mayor cantidad de libros
// d) Dar un listado de libros por isbn ascendente
// e) Dado un ISBN, informar titulo y año. Utilizar busqueda eficiente.
#include <stdio.h>
#include <stdbool.h>
#define MAX_LIBROS 500
typedef struct {
    int anio;
    int mes;
    int dia;
} t_fecha;
typedef struct {
    int ISBN;
    char titulo[50];
    t_fecha fecha;
} t_libro;
typedef t_libro t_libros[MAX_LIBROS];

void cargar_libros(t_libros libros, int* maximo_logico)
{
    int i = 0, finalizar;
    printf("Deseas ingresar un libro? (0: No, 1: Si): ");
    scanf("%i", &finalizar);
    while (finalizar != 1 && i < MAX_LIBROS)
    {
        printf("Ingrese el ISBN del libro: ");
        scanf("%i", &libros[i].ISBN);
        printf("Ingrese el titulo del libro: ");
        scanf("%s", &libros[i].titulo);
        printf("Ingrese la fecha del libro en formato YYYY/MM/DD: ");
        scanf("%i/%i/%i", &libros[i].fecha.anio, &libros[i].fecha.mes, &libros[i].fecha.dia);
        i++;
        if (i < MAX_LIBROS)
        {    
            printf("Deseas ingresar otro libro? (0: No, 1: Si): ");
            scanf("%i", &finalizar);
        }
    }
    *maximo_logico = i;
}

float porcentaje_libros(t_libros libros, int maximo_logico)
{
    int contador_libros = 0, i;
    float promedio;
    for (i = 0; i < maximo_logico; i++)
    {
        if (libros[i].fecha.anio == 2015)
        {
            contador_libros++;
        }
    }
    promedio = (float)contador_libros / maximo_logico;
    return promedio*100;
}

int anio_con_mas_libros(t_libros libros, int maximo_logico)
{
 // hacer structs con año y contador
}

void ordenar_ascendente(t_libros libros, int maximo_logico)
{
    int i, j;
    t_libro aux;    
    bool continuar=true;
    i=1;
    while (continuar && i<maximo_logico) 
    {
        continuar=false;
        for (j=0; j<maximo_logico-i; j++) 
        {
            if (libros[j].ISBN > libros[j+1].ISBN) 
            {
                aux=libros[j]; 
                libros[j]=libros[j+1]; 
                libros[j+1]=aux;
                continuar=true;
            } 
        }
        i++;
    }
}

int buscar_por_isbn(t_libros libros, int maximo_logico, int isbn_buscado)
{
    int inicio = 0, fin = maximo_logico - 1, medio, posicion;
    bool encontrado = false;

    while (!encontrado) {
    if ((isbn_buscado < libros[inicio].ISBN) || (isbn_buscado > libros[fin].ISBN)) {
        encontrado = true; // NO ESTA => FIN DE LA BUSQUEDA
        posicion = -1;
    } else {
        medio = inicio + ((fin-inicio)/2); // evitamos overflow de la suma directa

        if (libros[medio].ISBN == isbn_buscado) {
        encontrado = true; // ENCONTRADO => FIN DE LA BUSQUEDA
        posicion = medio;
        } else if(isbn_buscado > libros[medio].ISBN) {
        inicio = medio + 1;
        } else {
        fin = medio - 1;
        }
    }        
    }
    return posicion;
}

int main()
{
    t_libros libros;
    int maximo_logico;
    cargar_libros(libros, &maximo_logico);
    if (maximo_logico > 0)
        printf("El porcentaje de libros lanzados en 2015 es: %.2f\n", porcentaje_libros(libros, maximo_logico));
    else
        printf("No hay libros.");
    return 0;
}