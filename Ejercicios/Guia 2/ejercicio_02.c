// Escribir una función que dado un número entero, 
// devuelva un valor booleano que indique si dicho número es primo o no. 
// Antes de plantear una solución ten presente las siguientes preguntas.

// Con sólo encontrar un divisor del número a evaluar distinto a uno y a sí mismo, 
// ya puedo afirmar que el número no es primo. ¿Tiene sentido seguir evaluando más divisores?

// Teniendo en cuenta que todo número par a excepción del 2, no es primo, 
// ¿Tiene sentido seguir en un ciclo, si al calcular el resto de la división del número a evaluar por 2, el resultado es cero?

// Puedo encontrar un divisor del número a evaluar que sea mayor al número a evaluar dividido 2?

#include <stdio.h>
#include <stdbool.h>

bool numero_primo(int numero)
{
    bool valido = false;
    int x, contador = 0;
    for (x=1; x<=numero; x++)
    {
        if ((numero % x) == 0)
            contador++;
    }
    if (contador == 2)
        valido = true;
    return valido;
}
