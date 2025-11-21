// Leer un archivo de caracteres que representa un texto formado por oraciones terminadas en punto. 
// Copiarlo en otro archivo eliminando los espacios superfluos.

#include <stdio.h>
#include <stdbool.h>

void limpiar_texto(FILE *archivo_texto, FILE *archivo_limpio)
{
    char caracter;
    bool espacio_anterior = false;
    caracter = fgetc(archivo_texto);
    while (caracter != EOF)
    {
        if (caracter == ' ')
        {
            if (!espacio_anterior)
            {
                fputc(caracter, archivo_limpio);
                espacio_anterior = true;
            }
        }
        else
        {
            fputc(caracter, archivo_limpio);
            espacio_anterior = false;
        }
        caracter = fgetc(archivo_texto);
    }
}

int main()
{
    FILE *archivo_texto, *archivo_limpio;
    archivo_texto = fopen("texto.txt", "r");
    archivo_limpio = fopen("limpio.txt", "w");
    if (archivo_limpio == NULL || archivo_texto == NULL)
        printf("No se ha podido crear el archivo");
    else
    {
        limpiar_texto(archivo_texto, archivo_limpio);
        fclose(archivo_texto);
        fclose(archivo_limpio);
    }
    return 0;
}