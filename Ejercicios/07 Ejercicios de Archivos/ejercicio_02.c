// Dado un archivo de números enteros, generar otro archivo que contenga aquellos que son primos en el primero

#include <stdio.h>
#include <stdbool.h>

void cargar_numeros_enteros(FILE *archivo_numeros)
{
    int numero;
    printf("Ingrese un numero a ingresar al archivo (-1 para finalizar): ");
    scanf("%i", &numero);
    while (numero != -1)
    {
        fwrite(&numero, sizeof(int), 1, archivo_numeros);
        printf("Ingrese un numero a ingresar al archivo (-1 para finalizar): ");
        scanf("%i", &numero);
    }
}

void cargar_numeros_primos(FILE *archivo_numeros, FILE *archivo_primos)
{
    bool es_primo;
    int numero, i;
    fread(&numero, sizeof(int), 1, archivo_numeros);
    while (!feof(archivo_numeros))
    {
        es_primo = true;
        i = 2;
        while ((i < numero) && es_primo)
        {
            if (numero % i == 0)
            {
                es_primo = false;
            }
            i++;
        }
        if (es_primo)
            fwrite(&numero, sizeof(int), 1, archivo_primos);
        fread(&numero, sizeof(int), 1, archivo_numeros);
    }
}

void mostrar_numeros_primos(FILE *archivos_primos)
{
    int numero;
    fread(&numero, sizeof(int), 1, archivos_primos);
    while (!feof(archivos_primos))
    {
        printf("Numero primo: %i\n", numero);
        fread(&numero, sizeof(int), 1, archivos_primos);
    }
}

int main()
{
    FILE *archivos_numeros, *archivos_primos;
    archivos_numeros = fopen("numeros.dat", "wb");
    archivos_primos = fopen("primos.dat", "wb");
    if (archivos_numeros == NULL || archivos_primos == NULL)
        printf("No se pudieron crear los archivos.\n");
    else
    {
        cargar_numeros_enteros(archivos_numeros);
        fclose(archivos_numeros);
        archivos_numeros = fopen("numeros.dat", "rb");
        cargar_numeros_primos(archivos_numeros, archivos_primos);
        fclose(archivos_numeros);
        fclose(archivos_primos);
        archivos_primos = fopen("primos.dat", "rb");
        mostrar_numeros_primos(archivos_primos);
    }
    return 0;
}