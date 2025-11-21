// Dado un archivo de apellidos y nombres, 
// generar otro archivo con los mismos datos ordenados alfabéticamente.
// Suponer que el archivo de entrada cabe en la memoria.

#include <stdio.h>
#include <string.h>
#define MAX 50
typedef struct {
    char nombre[30];
    char apellido[30];
} t_nombre;

void cargar_nombres(FILE *archivo_nombres)
{
    int ingreso = 1, cantidad = 0;
    t_nombre nombre_completo;
    while (ingreso != 0 && cantidad < MAX)
    {    
        printf("Ingrese un nombre: ");
        fgets(nombre_completo.nombre, 30, stdin);
        fflush(stdin);
        printf("Ingrese un apellido: ");
        fgets(nombre_completo.apellido, 30, stdin);
        fflush(stdin);
        fwrite(&nombre_completo, sizeof(t_nombre), 1, archivo_nombres);
        cantidad++;
        printf("Desea ingresar otro nombre? (1: SI | 0: NO): ");
        scanf("%i", &ingreso);
        fflush(stdin);
    }
}

// quilombo
void cargar_nombres_ordenados(FILE *archivo_nombres, FILE *archivo_ordenado)
{
    int i, j, k, cantidad = 0;
    t_nombre nombre, auxiliar;
    t_nombre nombres[MAX];
    fread(&nombre, sizeof(t_nombre), 1, archivo_nombres);
    while (!feof(archivo_nombres))
    {
        nombres[cantidad] = nombre;
        cantidad++;
        fread(&nombre, sizeof(t_nombre), 1, archivo_nombres);
    }
    for (i = 1; i < cantidad; i++)
    {
        for (j = 0; j < cantidad - i; j++)
        {
            if (strcmp(nombres[j].nombre, nombres[j+1].nombre) > 0)
                {
                    auxiliar = nombres[j];
                    nombres[j] = nombres[j+1];
                    nombres[j+1] = auxiliar;
                }
        }
    }
    for (k = 0; k < cantidad; k++)
    {
        fwrite(&nombres[k], sizeof(t_nombre), 1, archivo_ordenado);
    }
}

void mostrar_nombres(FILE *archivo_ordenado)
{
    t_nombre nombre;
    fread(&nombre, sizeof(t_nombre), 1, archivo_ordenado);
    while (!feof(archivo_ordenado))
    {
        printf("Nombre: %s\nApellido: %s\n\n", nombre.nombre, nombre.apellido);
        fread(&nombre, sizeof(t_nombre), 1, archivo_ordenado);
    }
}

int main()
{
    FILE *archivo_nombres, *archivo_ordenado;
    archivo_nombres = fopen("nombres.dat", "wb");
    archivo_ordenado = fopen("ordenados.dat", "wb");
    if (archivo_nombres == NULL || archivo_ordenado == NULL)
        printf("No se han podido crear los archivos.");
    else
    {
        cargar_nombres(archivo_nombres);
        fclose(archivo_nombres);
        archivo_nombres = fopen("nombres.dat", "rb");
        cargar_nombres_ordenados(archivo_nombres, archivo_ordenado);
        fclose(archivo_nombres);
        fclose(archivo_ordenado);
        archivo_ordenado = fopen("ordenados.dat", "rb");
        mostrar_nombres(archivo_ordenado);
        fclose(archivo_ordenado);
    }
    return 0;
}
