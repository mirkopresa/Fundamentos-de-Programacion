// Escribir un programa que permita al usuario ingresar los montos de las compras
// de un cliente y que al finalizar informe por pantalla el importe total a pagar,
// teniendo en cuenta que si éste supera los $1000 se le debe aplicar un 10% de descuento.
// Se desconoce la cantidad de datos que se van a ingresar.
// La carga de datos finaliza cuando el usuario ingresa el monto 0 (cero).
// Se debe validar que no se ingresen montos negativos indicando al usuario monto invalido.

#include <stdio.h>

int main()
{
    float compra, total=0;
    while (compra != 0)
        {
            printf("Lista de productos:\n");
            printf("0: Finalizar compra\n");
            printf("1: Bizcochitos - $50\n");
            printf("2: Leche - $150\n");
            printf("3: Agua - $100\n");
            printf("4: Carne - $400\n");
            printf("Ingrese el numero de lo que desea comprar:\n ");
            scanf("%f", &compra);
            if (compra == 1)
                total+=50;
            else
                if (compra == 2)
                    total+=150;
                else
                    if (compra == 3)
                        total+=100;
                    else
                        if (compra == 4)
                            total+=400;
                        else
                            if (compra < 0)
                                printf("El numero de producto ingresado es negativo.\n");
                            else
                                if (compra > 4)
                                    printf("El numero de producto ingresado es incorrecto.\n");
        }
        if (total >= 1000)
            total=(total - (total/10));
        printf("Has terminado de ingresar compras!\n");
        printf("El importe total a pagar es de $%0.2f", total);
        return 0;
}