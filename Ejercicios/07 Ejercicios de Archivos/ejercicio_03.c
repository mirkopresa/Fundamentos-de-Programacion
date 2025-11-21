// Dado un archivo de números enteros entre 0 y 255, imprimir los caracteres correspondientes según el código ASCII.

#include <stdio.h>

void ingreso_numeros(FILE *archivo_numeros)
{
    int numero;
    printf("Ingrese un numero entre 0 y 255 (-1 para terminar): ");
    scanf("%i", &numero);
    while (numero != -1)
    {
        while (numero < 0 || numero > 255)
        {
            printf("El numero no esta entre 0 y 255\n");
            printf("Ingrese un numero entre 0 y 255 (-1 para terminar): ");
            scanf("%i", &numero);
        }
        fwrite(&numero, sizeof(int), 1, archivo_numeros);
        printf("Ingrese un numero entre 0 y 255 (-1 para terminar): ");
        scanf("%i", &numero);
    }
}

void mostrar_ascii(FILE *archivo_numeros)
{
    int numero;
    fread(&numero, sizeof(int), 1, archivo_numeros);
    while (!feof(archivo_numeros))
    {
        printf("Numero: %i ---> Caracter: %c\n", numero, (char)numero);
        fread(&numero, sizeof(int), 1, archivo_numeros);
    }
}

int main()
{
    FILE *archivos_numeros;
    archivos_numeros = fopen("numeros.dat", "wb");
    if (archivos_numeros == NULL)
        printf("No se ha podido crear el archivo");
    else
    {
        ingreso_numeros(archivos_numeros);
        fclose(archivos_numeros);
        archivos_numeros = fopen("numeros.dat", "rb");
        mostrar_ascii(archivos_numeros);
        fclose(archivos_numeros);
    }
}
