// Escribir una función para validar una nueva clave de acceso. 
// La función deberá recibir una cadena de caracteres, que contendrá la clave 
// candidata, que ya fue ingresada previamente por el usuario. 
// Devolverá true o false, dependiendo de si cumple o no, con las siguientes condiciones: 
// - La clave debe estar formada únicamente por, entre 6 y 12 caracteres numéricos 
// - La cantidad de dígitos pares debe ser mayor a la de los impares. 
// A los sumo debe recorrer una vez la cadena. 
// Evite realizar ciclos innecesarios.

#include <stdio.h>
#include <string.h>
#include <stdbool.h>
#define MAX 20
typedef char T_cadena[MAX];

bool clave_valida(T_cadena clave)
{
    bool valido = true;
    int i = 0, contador_pares = 0, contador_impares = 0;
    if (!(strlen(clave) >= 6 && strlen(clave) <= 12))
        valido = false;
    while (valido && clave[i] != '\0')
    {
        if (clave[i] < '0' || clave[i] > '9')
            valido = false;
        else if ((clave[i] - '0') % 2 == 0)
            contador_pares++;
        else
            contador_impares++;
        i++;
    }
    if (contador_pares < contador_impares)
        valido = false;
    return valido;
}

void obtener_clave(T_cadena clave)
{
    printf("Ingresa una clave: ");
    fgets(clave, MAX, stdin);
    clave[strcspn(clave, "\n")] = '\0';
    fflush(stdin);
}

int main()
{
    T_cadena clave;
    obtener_clave(clave);
    if (clave_valida(clave))
        printf("La clave es valida.");
    else
        printf("La clave es invalida");
    return 0;
}