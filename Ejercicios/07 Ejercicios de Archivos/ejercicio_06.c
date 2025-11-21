// Se tiene un archivo de números telefónicos cuyos registros son de la forma:
//      Característica de localidad (4 dígitos)
//      Característica central (3 dígitos)
//      Número (4 dígitos)
// Dado un número que representa una característica de localidad, listar todos los
// números telefónicos con dicha característica.
// Suponer los siguientes casos:
// a) El archivo no cabe en la memoria y está desordenado.
// b) El archivo no cabe en la memoria y está ordenado según números telefónicos crecientes.

#include <stdio.h>

typedef struct {
    int localidad;
    int central;
    int numero;
} t_telefono;

void cargar_telefonos(FILE *archivo_telefonos)
{
    t_telefono telefono;
    int ingreso = 1;
    while (ingreso != 0)
    {
        printf("Ingrese la localidad (xxxx): ");
        scanf("%i", &telefono.localidad);
        printf("Ingrese la central (xxx): ");
        scanf("%i", &telefono.central);
        printf("Ingrese el numero (xxxx): ");
        scanf("%i", &telefono.numero);
        fwrite(&telefono, sizeof(t_telefono), 1, archivo_telefonos);
        printf("Deseas ingresar otro? (1: SI | 0: NO): ");
        scanf("%i", &ingreso);
    }
}

void mostrar_telefono(FILE *archivo_telefonos)
{
    int localidad_buscada;
    t_telefono telefono;
    printf("Ingrese una localidad para mostrar sus numeros: ");
    scanf("%i", &localidad_buscada);
    fread(&telefono, sizeof(t_telefono), 1, archivo_telefonos);
    printf("-------Telefonos-------\n");
    while (!feof(archivo_telefonos))
    {
        if (localidad_buscada == telefono.localidad)
        {
            printf("Telefono: %i\n", telefono.numero);
        }
        fread(&telefono, sizeof(t_telefono), 1, archivo_telefonos);
    }
}

int main()
{
    FILE *archivo_telefonos;
    archivo_telefonos = fopen("telefonos.dat", "wb");
    if (archivo_telefonos == NULL)
        printf("No se ha podido crear el archivo.");
    else
    {
        cargar_telefonos(archivo_telefonos);
        fclose(archivo_telefonos);
        archivo_telefonos = fopen("telefonos.dat", "rb");
        mostrar_telefono(archivo_telefonos);
        fclose(archivo_telefonos);
    }
    return 0;
}