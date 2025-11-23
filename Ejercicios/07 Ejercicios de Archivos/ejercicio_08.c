// Leer un archivo de caracteres que representa un texto formado por oraciones terminadas en punto. 
// Calcular la cantidad de monosílabos que hay en el texto, la longitud promedio de las palabras y la cantidad de palabras.

// no hago lo de monosilabos porque es imposible

#include <stdio.h>
#include <stdbool.h>

void calcular_cantidad_promedio(FILE *archivo_texto)
{
    char caracter;
    int cantidad_palabras = 0, cantidad_letras = 0;
    bool dentro_palabra = false;
    float longitud_promedio;
    caracter = fgetc(archivo_texto);
    while (caracter != EOF)
    {
        if ((caracter >= 'a' && caracter <= 'z') || (caracter >= 'A' && caracter <= 'Z'))
        {
            cantidad_letras++;
            if (!dentro_palabra)
            {
                cantidad_palabras++;
                dentro_palabra = true;
            }
        }
        else
        {
            dentro_palabra = false;
        }
        caracter = fgetc(archivo_texto);
    }
    longitud_promedio = (float)cantidad_letras / cantidad_palabras;
    printf("Cantidad de palabras: %i\n", cantidad_palabras);
    printf("Longitud promedio de las palabras: %0.2f", longitud_promedio);
}

int main()
{
    FILE *archivo_texto;
    archivo_texto = fopen("texto_2.txt", "r");
    if (archivo_texto == NULL)
    {
        printf("No se ha podido crear el archivo.");
    }
    else
    {
        calcular_cantidad_promedio(archivo_texto);
        fclose(archivo_texto);
    }
    return 0;
}