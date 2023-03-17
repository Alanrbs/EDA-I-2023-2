#include <stdio.h>

// Función que imprime el tablero con la pieza en la posición indicada
void imprimir_tablero(int x, int y, char pieza) {
    char tablero[8][8] = {
        {' ', ' ', ' ', ' ', ' ', ' ', ' ', ' '},
        {' ', ' ', ' ', ' ', ' ', ' ', ' ', ' '},
        {' ', ' ', ' ', ' ', ' ', ' ', ' ', ' '},
        {' ', ' ', ' ', ' ', ' ', ' ', ' ', ' '},
        {' ', ' ', ' ', ' ', ' ', ' ', ' ', ' '},
        {' ', ' ', ' ', ' ', ' ', ' ', ' ', ' '},
        {' ', ' ', ' ', ' ', ' ', ' ', ' ', ' '},
        {' ', ' ', ' ', ' ', ' ', ' ', ' ', ' '}
    };
    
    tablero[x][y] = pieza;
    
    printf("\n  +-----------------+\n");
    for (int i = 0; i < 8; i++) {
        printf("%d |", 8 - i);
        for (int j = 0; j < 8; j++) {
            printf(" %c ", tablero[i][j]);
        }
        printf("|\n");
    }
    printf("  +-----------------+\n");
    printf("    a  b  c  d  e  f  g  h\n");
}

// Función que determina los movimientos válidos de la pieza en la posición indicada
void movimientos_validos(int x, int y, char pieza) {
    printf("Movimientos válidos para la pieza %c en la posición (%c, %d):\n", pieza, 'a' + y, 8 - x);
    // Aquí iría el código para determinar los movimientos válidos de cada pieza
    // Por simplicidad, este ejemplo solo imprimirá un mensaje
    printf("Esta pieza no puede moverse.\n");
}

int main() {
    int opcion = 0;
    while (opcion != 6) {
        printf("\nMenú:\n");
        printf("1.- Caballo\n");
        printf("2.- Alfil\n");
        printf("3.- Torre\n");
        printf("4.- Reina\n");
        printf("5.- Rey\n");
        printf("6.- Salir\n");
        printf("Elige una opción: ");
        scanf("%d", &opcion);
        
        if (opcion >= 1 && opcion <= 5) {
            int x, y;
            printf("Ingresa las coordenadas x,y para la pieza: ");
            scanf("%d,%d", &x, &y);
            
            // Convertir la opción elegida a la letra correspondiente
            char pieza;
            switch (opcion) {
                case 1: pieza = 'C'; break;
                case 2: pieza = 'A'; break;
                case 3: pieza = 'T'; break;
                case 4: pieza = 'R'; break;
                case 5: pieza = 'K'; break;
            }
            
            // Imprimir el tablero con la pieza en la posición indicada y los movimientos válidos
            imprimir_tablero(x, y, pieza);
            movimientos_validos(x, y, pieza);
        }
    }
    
    return 0
);}