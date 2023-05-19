#include <stdio.h>

int main() {
    // Declaración de variables
    int opcion, subopcion, valor, posicion, i, suma = 0;
    int conjunto[10] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};

    // Menú de opciones
    printf("Seleccione la operación a realizar:\n");
    printf("1. Sumar todos los valores del conjunto\n");
    printf("2. Restar el valor de una posición dada\n");
    printf("3. Añadir un valor en una posición dada\n");
    printf("4. Eliminar un valor en una posición dada\n");
    printf("Opción: ");
    scanf("%d", &opcion);

    // Ejecutar operación seleccionada
    switch(opcion) {
        case 1: // Sumar todos los valores del conjunto
            for (i = 0; i < 10; i++) {
                suma += conjunto[i];
            }
            printf("La suma de los valores del conjunto es: %d\n", suma);
            break;
        case 2: // Restar el valor de una posición dada
            printf("Ingrese la posición a restar (0-9): ");
            scanf("%d", &posicion);
            if (posicion >= 0 && posicion < 10) {
                conjunto[posicion]--;
                printf("El valor de la posición %d es ahora: %d\n", posicion, conjunto[posicion]);
            } else {
                printf("La posición ingresada no es válida.\n");
            }
            break;
        case 3: // Añadir un valor en una posición dada
            printf("Ingrese el valor a agregar: ");
            scanf("%d", &valor);
            printf("Ingrese la posición donde agregar el valor (0-9): ");
            scanf("%d", &posicion);
            if (posicion >= 0 && posicion < 10) {
                for (i = 9; i > posicion; i--) {
                    conjunto[i] = conjunto[i-1];
                }
                conjunto[posicion] = valor;
                printf("El valor %d fue agregado en la posición %d.\n", valor, posicion);
            } else {
                printf("La posición ingresada no es válida.\n");
            }
            break;
        case 4: // Eliminar un valor en una posición dada
            printf("Ingrese la posición a eliminar (0-9): ");
            scanf("%d", &posicion);
            if (posicion >= 0 && posicion < 10) {
                for (i = posicion; i < 9; i++) {
                    conjunto[i] = conjunto[i+1];
                }
                conjunto[9] = 0;
                printf("El valor en la posición %d fue eliminado.\n", posicion);
            } else {
                printf("La posición ingresada no es válida.\n");
            }
            break;
        default: // Opción inválida
            printf("La opción ingresada no es válida.\n");
            break;
    }

    return 0;
}
