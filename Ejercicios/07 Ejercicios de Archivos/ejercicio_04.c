// Dados dos archivos de números enteros de 5 dígitos ordenados en forma creciente, 
// generar un archivo que contenga todos los números, ordenado de igual forma. 
// No hay números repetidos.

#include <stdio.h>

// Ingresar de manera creciente porfavor, y de 5 digitos
void ingreso_numeros(FILE *archivo_numeros)
{
    int numero;
    printf("Ingresa un numero de 5 digitos (0 para finalizar): ");
    scanf("%i", &numero);
    while (numero != 0)
    {
        fwrite(&numero, sizeof(int), 1, archivo_numeros);
        printf("Ingresa un numero de 5 digitos (0 para finalizar): ");
        scanf("%i", &numero);
    }
}

void archivo_numeros_ordenados(FILE *archivo_numeros_1, FILE *archivo_numeros_2, FILE *archivo_ordenado)
{
    int numero_1, numero_2;
    fread(&numero_1, sizeof(int), 1, archivo_numeros_1);
    fread(&numero_2, sizeof(int), 1, archivo_numeros_2);
    while (!feof(archivo_numeros_1) && !feof(archivo_numeros_2))
    {
        if (numero_1 > numero_2)
        {
            fwrite(&numero_2, sizeof(int), 1, archivo_ordenado);
            fwrite(&numero_1, sizeof(int), 1, archivo_ordenado);
        }
        else
        {
            fwrite(&numero_1, sizeof(int), 1, archivo_ordenado);
            fwrite(&numero_2, sizeof(int), 1, archivo_ordenado);
        }
        fread(&numero_1, sizeof(int), 1, archivo_numeros_1);
        fread(&numero_2, sizeof(int), 1, archivo_numeros_2);
    }
}

void mostrar_numeros_ordenados(FILE *archivo_ordenado)
{
    int numero;
    fread(&numero, sizeof(int), 1, archivo_ordenado);
    while (!feof(archivo_ordenado))
    {
        printf("Numero: %i\n", numero);
        fread(&numero, sizeof(int), 1, archivo_ordenado);
    }
}

int main()
{
    FILE *archivo_numeros_1, *archivo_numeros_2, *archivo_ordenado;
    archivo_numeros_1 = fopen("numeros_1.dat", "wb");
    archivo_numeros_2 = fopen("numeros_2.dat", "wb");
    archivo_ordenado = fopen("numeros_ordenados.dat", "wb");
    if (archivo_numeros_1 == NULL || archivo_numeros_2 == NULL || archivo_ordenado == NULL)
        printf("No se han podido crear los archivos.");
    else
    {
        ingreso_numeros(archivo_numeros_1);
        printf("Se cargo el primer archivo.\n");
        fclose(archivo_numeros_1);
        ingreso_numeros(archivo_numeros_2);
        printf("Se cargo el segundo archivo.\n");
        fclose(archivo_numeros_2);
        archivo_numeros_1 = fopen("numeros_1.dat", "rb");
        archivo_numeros_2 = fopen("numeros_2.dat", "rb");
        archivo_numeros_ordenados(archivo_numeros_1, archivo_numeros_2, archivo_ordenado);
        fclose(archivo_numeros_1);
        fclose(archivo_numeros_2);
        fclose(archivo_ordenado);
        archivo_ordenado = fopen("numeros_ordenados.dat", "rb");
        mostrar_numeros_ordenados(archivo_ordenado);
        fclose(archivo_ordenado);
    }
    return 0;
}