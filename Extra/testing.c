// Escribir un programa que permita al usuario ingresar los montos de las compras de un cliente y que 
// al finalizar informe por pantalla el importe total a pagar, teniendo en cuenta que si éste supera
// los $10.000 se le debe aplicar un 10% de descuento. Se desconoce la cantidad de datos que se van a ingresar. 
// La carga de datos finaliza cuando el usuario ingresa el monto 0 (cero). 
// Se debe validar que no se ingresen montos negativos indicando al usuario monto invalido.

#include <stdio.h>

int main()
{
    int compra;
    float total = 0;

    printf("Ingrese los montos de tus compras (0 para terminar): ");
    scanf("%i", &compra);

    while (compra != 0)
    {
        if (compra < 0)
            printf("El monto ingresado es negativo.\n");
        else  
            total+=compra;
        printf("Ingrese los montos de tus compras: ");
        scanf("%i", &compra);
    }

    if (total >= 10000)
        {
            total=(total*0.9);
            printf("El total de la compra es %0.2f\n", total);
            printf("Se aplico un descuento del 10%%");
        }
    else
        printf("El total de la compra es %0.2f", total);
    
    return 0;
}