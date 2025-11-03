// Escribir una función en C que reciba como primer parámetro, una cadena de tipo 
// t_cadena, y devuelva como segundo parámetro, la misma cadena pero invertida, 
// sin considerar los blancos.  
// Sólo se deben invertir las posiciones con caracteres ciertos, y no aquellas 
// posiciones potenciales a ser utilizadas pero que podrían contener caracteres 
// inciertos. 
// Recorrer la cadena a lo sumo una vez. 
// Declare un tipo t_cadena acorde. 
// Escribir el programa que incluya a la función y las invocaciones con los 
// siguientes casos y las impresiones para comprobar que devuelven lo correcto.

// Casos: 
// invertir_cadena("Hola, me llamo Ana.", cad_invertida) ==> cad_invertida: ".anAomallem,aloH" 
// invertir_cadena("234561", cad_invertida) ==> cad_invertida: "165432" 
// invertir_cadena("    ", cad_invertida) ==> cad_invertida:  "" 
// invertir_cadena("Somos o No somos", cad_invertida) ==> cad_invertida:  "somosoNsomoS" 

#include <stdio.h>
#include <string.h>
#define MAX 30
typedef char T_cadena[MAX];

void invertir_cadena(T_cadena cadena, T_cadena cadena_invertida)
{
    int i, j = 0;
    char caracter;
    for (i = strlen(cadena) - 1; i >= 0; i--)
    {
        if (cadena[i] != ' ')
        {
            cadena_invertida[j] = cadena[i];
            j++;
        }
    }
    cadena_invertida[j] = '\0';
}

void obtener_cadena(T_cadena cadena)
{
    printf("Ingresa una cadena: ");
    fgets(cadena, MAX, stdin);
    cadena[strcspn(cadena, "\n")] = '\0';
    fflush(stdin);
}

void mostrar_cadena(T_cadena cadena) 
{
    printf("%s\n", cadena);
}

int main()
{
    T_cadena cadena, cadena_invertida;
    obtener_cadena(cadena);
    printf("Cadena a invertir: %s\n", cadena);
    invertir_cadena(cadena, cadena_invertida);
    printf("Cadena invertida: %s", cadena_invertida);
    return 0;
}
