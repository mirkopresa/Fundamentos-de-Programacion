// Dado un archivo de números enteros mayores o iguales que 0, generar otro archivo
// que almacene los factoriales de cada número del registro correspondiente del archivo de entrada.

#include <stdio.h>

void carga_numeros(FILE *archivo_numeros)
{
    int numero;
    printf("Ingrese un numero a ingresar en el archivo (-1 para finalizar): ");
    scanf("%i", &numero);
    while (numero != -1)
    {
        fwrite(&numero, sizeof(int), 1, archivo_numeros);
        printf("Ingrese un numero a ingresar en el archivo (-1 para finalizar): ");
        scanf("%i", &numero);
    }
    printf("Se terminaron de ingresar los numeros.\n\n");
}

void calculo_carga_factoriales(FILE *archivo_numeros, FILE *archivo_factoriales)
{
    int numero, factorial, i;
    fread(&numero, sizeof(int), 1, archivo_numeros);
    while (!feof(archivo_numeros))
    {
        factorial = 1;
        for (i = 2; i <= numero; i++)
        {
            factorial *= i;
        }
        fwrite(&factorial, sizeof(int), 1, archivo_factoriales);
        fread(&numero, sizeof(int), 1, archivo_numeros);
    }
    printf("Se terminaron de calcular los factoriales.\n\n");
}

void mostrar_factoriales(FILE *archivo_factoriales)
{
    int numero;
    fread(&numero, sizeof(int), 1, archivo_factoriales);
    while (!feof(archivo_factoriales))
    {
        printf("Factorial: %i\n", numero);
        fread(&numero, sizeof(int), 1, archivo_factoriales);
    }
    printf("Se termino de leer el archivo.\n\n");
}
int main()
{
    FILE *archivo_numeros, *archivo_factoriales;
    archivo_numeros = fopen("numeros_enteros.dat", "wb");
    archivo_factoriales = fopen("factoriales.dat", "wb");
    if (archivo_numeros == NULL || archivo_factoriales == NULL)
        printf("No se pudo crear el archivo.\n");
    else
    {
        carga_numeros(archivo_numeros);
        fclose(archivo_numeros);
        archivo_numeros = fopen("numeros_enteros.dat", "rb");
        calculo_carga_factoriales(archivo_numeros, archivo_factoriales);
        fclose(archivo_numeros);
        fclose(archivo_factoriales);
        archivo_factoriales = fopen("factoriales.dat", "rb");
        mostrar_factoriales(archivo_factoriales);
        fclose(archivo_factoriales);
        printf("Se cerraron los archivos.\n\n");
    }
    return 0;
}