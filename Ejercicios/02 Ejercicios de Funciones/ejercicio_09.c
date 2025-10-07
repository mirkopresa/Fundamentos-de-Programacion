// Escribir una función que dada una fecha en formato aaaammdd 
// (número entero) la convierta en los parámetros numéricos 
// aaaa, mm y dd. Ejemplo: fecha: 20140321 -> dia=21 mes=3 año=2014

#include <stdio.h>

void conversor(int fecha, int *dia, int *mes, int *anio)
{
    *dia = fecha % 100;
    *mes = (fecha / 100) % 100;
    *anio = (fecha / 10000); 
}