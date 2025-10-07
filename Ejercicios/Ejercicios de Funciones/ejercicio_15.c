// Diseñar un algoritmo que calcule la aproximación del seno:
// sen(x)= x - (x^3)/3! + (x^5)/5! - (x^7)/7! + ..........

#include <stdio.h>

double factorial( int num_1 )
{
    double resultado = 1, x;
    if (num_1 < 0)
        resultado = 0;
    else
        {
            for (x=2; x<=num_1; x++)
            {
                resultado *= x;
            }
        }
    return resultado;
}

double potencia(double numero, int exponente)
{
    int x;
    double resultado = 1.0;
    if (exponente >= 0)
        for (x=1; x<=exponente; x++)
        {
            resultado = resultado * numero;
        }
    else
        {
            for (x=1; x<=(-exponente); x++)
            {
                resultado = resultado * numero;
            }
            resultado = (1.0 / resultado);
        }
    return resultado;
}

double aproximacion_seno(float numero)
{
    double aproximacion = 0;
    int x, k = 1;
    for (x=1; x<=19; x+=2)
        {
        aproximacion += k*((potencia(numero, x))/factorial(x));
        k*=-1;
        }
    return aproximacion;
}
