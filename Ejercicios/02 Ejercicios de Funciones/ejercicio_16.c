// Dos números se dicen amigos cuando uno de ellos es igual a la suma de
// todos los divisores del otro excepto el mismo. Ejemplo: los números 220 y 284
// son amigos.
// (284 = 1+2+4+5+10+11+20+22+44+55+110)
// (220 = 1+2+4+71+142)
// a) escribir una función booleana que llamada desde un programa, permita
// discernir si dos números (parámetros) son amigos.
// b) Usar otra función para calcular la suma de los divisores de un número
// determinado.
// c) Hacer referencia a dichas funciones desde un programa o desde otro
// subprograma.

#include <stdio.h>
#include <stdbool.h>

bool numeros_amigos(int numero_1, int numero_2)
{
    bool amigos;
    int suma_1 = 0, suma_2 = 0, x, y;
    for (x=1; x<numero_1; x++)
        {
            if ((numero_1 % x) == 0)
                suma_1 +=x;
        }
    for (y=1; y<numero_2; y++)
        {
            if ((numero_2 % y) == 0)
                suma_2 +=y;
        }
    if ((suma_1 == numero_2) && (suma_2 == numero_1))
        amigos = true;
    else
        amigos = false;
    return amigos;
}

int main()
{
    printf("%d", numeros_amigos(284, 220));
    return 0;
}