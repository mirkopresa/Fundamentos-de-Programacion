// Escribir una función en C, que reciba como parámetro una cadena de tipo 
// t_cadena, y devuelva la cantidad de palabras que hay en la cadena. 
// Considerar que una palabra está separada de otra, por uno ó más blancos. 
// No recorrer la cadena más de una vez. 
// Declare un tipo t_cadena acorde. 
// Escribir el programa que incluya a la función y las invocaciones con los 
// siguientes caso de prueba: 
 
// cant_palabras("El sol es amarillo.") devuevle 4 
// cant_palabras(" Hoy es   30 de Junio de   2021  ") devuevle 7 
// cant_palabras("30/06/2021") devuelve 1 
// cant_palabras("El  precio  es      $2.000.-    ") devuelve 4 
// cant_palabras("       ") devuelve 0

#include <stdio.h>
#include <string.h>
#include <stdbool.h>
#define MAX 30
typedef char T_cadena[MAX];

int cantidad_palabras(T_cadena cadena)
{
    int i = 0, contador = 0;
    bool letra = false;
    while (cadena[i] != '\0')
    {
        if (cadena[i] != ' ' && !letra)
            {
                letra = true;
                contador++;
            }
        else if (cadena[i] == ' ')
            letra = false;
        i++;
    }
    return contador;
}

int main()
{
    T_cadena cadena;
    printf("Ingresa una oracion: ");
    fgets(cadena, MAX, stdin);
    cadena[strcspn(cadena, "\n")] = '\0';
    fflush(stdin);
    printf("Cantidad de palabras en %s: %i", cadena, cantidad_palabras(cadena));
    return 0;
}