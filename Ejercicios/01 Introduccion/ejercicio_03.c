// Ingresar el radio de una esfera y calcular el volumen.

#include <stdio.h>
#define pi 3.14159265358979323846

int main()
{
    float diametro, radio, volumen;
    printf("Ingrese el diametro de la esfera para calcular su radio y el volumen: ");
    scanf("%f", &diametro);
    radio=(diametro / 2);
    volumen=((4.00 / 3.00) * pi * (radio * radio * radio));
    printf("El radio de la esfera es %.2f, y su volumen es %.2f", radio, volumen);
    return 0;
}