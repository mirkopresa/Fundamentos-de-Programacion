// Secuencia
// 1) Hallar la superficie de un triángulo conociendo la base y la altura. Solicitarle los datos de entrada al usuario.

#include <stdio.h>

int main()
{
    float base, altura, area;
    printf("Ingrese la base del triangulo: ");
    scanf("%f", &base);
    printf("Ingrese la altura del triangulo: ");
    scanf("%f", &altura);
    area=((1.00 / 2.00) * base * altura);
    printf("El area del triangulo es: %.2f", area);
    return 0;
}