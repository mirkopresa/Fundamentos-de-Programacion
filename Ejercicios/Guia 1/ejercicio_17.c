// Generar un dibujo por pantalla con el siguiente patrón solicitando al usuario la altura.
// Ejemplo: altura=5 debe dibujar por pantalla:
// * 
// **
// ***
// ****
// *****

#include <stdio.h>

int main()
{
    int altura, x, y;
    printf("Ingrese una altura: ");
    scanf("%i", &altura);
    for (x=0; x<altura; x++)
        {
        for (y=0; y<=x; y++)
            printf("*");
        printf("\n");
        }
    return 0;
}