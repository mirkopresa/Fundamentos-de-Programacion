# Escribir un programa en Python:
# Que le solicite al usuario que ingrese su número de padrón y muestre
# por pantalla todos los divisores del padrón ingresado.
# En la lista se deben omitir el 1 y el propio padrón.

# Inicio
padron = int(input("Ingrese su numero de padron: "))
for numero in range(2, padron):
    if padron % numero == 0:
        print(f"{numero} es divisor de {padron}")
# Fin
