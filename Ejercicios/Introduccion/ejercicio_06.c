// Ingresar tres números y hallar el mayor.

#include <stdio.h>

int main()
{
    float numero_1, numero_2, numero_3;
    printf("Ingresa el primer numero: ");
    scanf("%f", &numero_1);
    printf("Ingresa el segundo numero: ");
    scanf("%f", &numero_2);
    printf("Ingresa el tercer numero: ");
    scanf("%f", &numero_3);
    if ((numero_1 > numero_2) && (numero_1 > numero_3))
        printf("%.2f es mayor a %.2f y %.2f", numero_1, numero_2, numero_3);
    else
        if ((numero_2 > numero_1) && (numero_2 > numero_3))
        printf("%.2f es mayor a %.2f y %.2f", numero_2, numero_1, numero_3);
        else
        printf("%.2f es mayor a %.2f y %.2f", numero_3, numero_1, numero_2);
    return 0;
}