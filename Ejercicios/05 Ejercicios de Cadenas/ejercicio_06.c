// Escribir una función para validar una nueva clave de acceso. 
// La función deberá recibir una cadena de caracteres, que contendrá la clave 
// candidata, ingresada previamente por el usuario. 
// Devolverá true o false, dependiendo de si cumple o no con las siguientes 
// condiciones: 
 
// - La clave debe estar formada únicamente por, entre 4 y 8 caracteres numéricos 
// - Los caracteres no pueden ser todos iguales

#include <stdio.h>
#include <string.h>
#include <stdbool.h>
#define MAX 20
typedef char T_cadena[MAX];

bool clave_valida(T_cadena clave)
{
    bool valido = true, diferentes_numeros = false;
    int i = 0, primer_numero = clave[i]; 
    if (!(strlen(clave) >= 4 && strlen(clave) <= 8))
        valido = false;
    while (valido && clave[i] != '\0')
    {
        if (clave[i] < '0' || clave[i] > '9')
            valido = false;
        else if (clave[i] != primer_numero)
            diferentes_numeros = true;
        i++;
    }
    if (!diferentes_numeros)
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