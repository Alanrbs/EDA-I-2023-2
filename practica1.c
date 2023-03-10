#include <stdio.h>

void mostrar_tablero(char tablero[8][8]){

    int i, j;

    printf("    a   b   c   d   e   f   g   h  \n");
    printf("  +---+---+---+---+---+---+---+---+\n");
    for(i = 7; i >= 0; i--){
        printf("%d |", i+1);
        for(j = 0; j < 8; j++){
            printf(" %c |", tablero[i][j]);
        }
        printf(" %d\n", i+1);
        printf("  +---+---+---+---+---+---+---+---+\n");
    }
    printf("    a   b   c   d   e   f   g   h  \n");
}

void mostrar_movimientos_alfil(int x, int y){

    char tablero[8][8] = {{'-','-','-','-','-','-','-','-'},{'-','-','-','-','-','-','-','-'},{'-','-','-','-','-','-','-','-'},{'-','-','-','-','-','-','-','-'},{'-','-','-','-','-','-','-','-'},{'-','-','-','-','-','-','-','-'},{'-','-','-','-','-','-','-','-'},{'-','-','-','-','-','-','-','-'}};
    int i, j;

    tablero[x][y] = 'A';

    for(i = 0; i < 8; i++){
        for(j = 0; j < 8; j++){
            if((x-y) == (i-j) || (x+y) == (i+j)){
                tablero[i][j] = 'X';
            }
        }
    }

    mostrar_tablero(tablero);
}

void mostrar_movimientos_torre(int x, int y){

    char tablero[8][8] = {{'-','-','-','-','-','-','-','-'},{'-','-','-','-','-','-','-','-'},{'-','-','-','-','-','-','-','-'},{'-','-','-','-','-','-','-','-'},{'-','-','-','-','-','-','-','-'},{'-','-','-','-','-','-','-','-'},{'-','-','-','-','-','-','-','-'},{'-','-','-','-','-','-','-','-'}};
    int i, j;

    tablero[x][y] = 'T';

    for(i = 0; i < 8; i++){
        if(i != x){
            tablero[i][y] = 'X';
        }
        if(i != y){
            tablero[x][i] = 'X';
        }
    }

    mostrar_tablero(tablero);
}

int main(){
    int opcion, x, y;

    do {
        printf("\nMENU DE OPCIONES\n");
        printf("1.- Alfil\n");
        printf("2.- Torre\n");
        printf("3.- Salir\n");
        printf("Seleccione una opción: ");
        scanf("%d", &opcion);

    switch(opcion){
        case 1:
            printf("Ingrese las coordenadas x e y del alfil: ");
            scanf("%d %d", &x, &y);
            mostrar_movimientos_alfil(x, y);
            break;
        case 2:
            printf("Ingrese las coordenadas x e y de la torre: ");
            scanf("%d %d", &x, &y);
            mostrar_movimientos_torre(x, y);
            break;
        case 3:
            printf("Saliendo...\n");
            break;
        default:
            printf("Opción no válida, intente de nuevo.\n");
    }
} while(opcion != 3);

return 0;
}