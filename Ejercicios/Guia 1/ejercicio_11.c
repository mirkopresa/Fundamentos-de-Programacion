// Dado un número n, informar los n primeros términos de la sucesión geométrica de razón 3 (1, 3, 9, 27, etc.).

#include <stdio.h>
int main()
{
int numero, x, sucesion = 1;

printf("Ingrese un numero: ");
scanf("%i", &numero);

for (x = 0; x<numero; x++)
    {
    printf("%i\n", sucesion);
    sucesion*=3;
    }

return 0;
}
