#include <stdio.h>
#include <stdlib.h>

void kingMoves(int row, int col, char **board) {
    // Mostrar movimientos permitidos para el rey
    // ...
    // Código para mostrar movimientos permitidos
    // ...
    board[row][col] = 'K';
}

void queenMoves(int row, int col, char **board) {
    // Mostrar movimientos permitidos para la reina
    // ...
    // Código para mostrar movimientos permitidos
    // ...
    board[row][col] = 'Q';
}

void displayMoves(char piece, int row, int col, char **board) {
    // Mostrar los movimientos permitidos para la pieza seleccionada
    if (piece == 'k') {
        kingMoves(row, col, board);
    } else if (piece == 'q') {
        queenMoves(row, col, board);
    } else {
        printf("Error: pieza inválida.\n");
    }
}

int main() {
    // Crear el tablero de ajedrez
    char **board = (char **)malloc(8 * sizeof(char *));
    for (int i = 0; i < 8; i++) {
        board[i] = (char *)malloc(8 * sizeof(char));
        for (int j = 0; j < 8; j++) {
            board[i][j] = '-';
        }
    }

    // Mostrar el tablero de ajedrez
    printf("Tablero de Ajedrez:\n");
    for (int i = 0; i < 8; i++) {
        for (int j = 0; j < 8; j++) {
            printf("%c ", board[i][j]);
        }
        printf("\n");
    }

    // Obtener la pieza y las coordenadas del usuario
    char piece;
    int row, col;
    printf("Ingresa la pieza (k para rey, q para reina): ");
    scanf("%c", &piece);
    printf("Ingresa la fila (1-8): ");
    scanf("%d", &row);
    printf("Ingresa la columna (1-8): ");
    scanf("%d", &col);

    // Convertir la entrada del usuario a coordenadas en el tablero
    row--;
    col--;

    // Mostrar los movimientos permitidos en el tablero
    displayMoves(piece, row, col, board);

    // Mostrar el tablero de ajedrez actualizado
    printf("Tablero de Ajedrez actualizado:\n");
    for (int i = 0; i < 8; i++) {
        for (int j = 0; j < 8; j++) {
            printf("%c ", board[i][j]);
        }
        printf("\n");
    }

    // Liberar la memoria utilizada por el tablero de ajedrez
    for (int i = 0; i < 8; i++) {
        free(board[i]);
    }
    free(board);

    return 0;
}