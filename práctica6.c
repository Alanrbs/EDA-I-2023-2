#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

#define MAX_SIZE 100 // Tamaño máximo de la cadena de caracteres

// Estructura de datos para la cola doble
typedef struct {
    char data[MAX_SIZE];
    int front;
    int rear;
} Deque;

// Función para crear una cola doble vacía
Deque createDeque() {
    Deque deque;
    deque.front = -1;
    deque.rear = -1;
    return deque;
}

// Función para comprobar si la cola doble está vacía
bool isEmpty(Deque deque) {
    return deque.front == -1;
}

// Función para comprobar si la cola doble está llena
bool isFull(Deque deque) {
    return (deque.front == 0 && deque.rear == MAX_SIZE-1) || deque.front == deque.rear+1;
}

// Función para agregar un elemento por la parte del frente de la cola doble
void addFront(Deque *deque, char data) {
    if (isFull(*deque)) {
        printf("La cola doble está llena.\n");
        exit(EXIT_FAILURE);
    }
    if (deque->front == -1) { // Si la cola doble está vacía
        deque->front = 0;
        deque->rear = 0;
    } else if (deque->front == 0) { // Si la parte del frente ya está en la primera posición
        deque->front = MAX_SIZE-1;
    } else {
        deque->front--;
    }
    deque->data[deque->front] = data;
}

// Función para agregar un elemento por la parte trasera de la cola doble
void addRear(Deque *deque, char data) {
    if (isFull(*deque)) {
        printf("La cola doble está llena.\n");
        exit(EXIT_FAILURE);
    }
    if (deque->front == -1) { // Si la cola doble está vacía
        deque->front = 0;
        deque->rear = 0;
    } else if (deque->rear == MAX_SIZE-1) { // Si la parte trasera ya está en la última posición
        deque->rear = 0;
    } else {
        deque->rear++;
    }
    deque->data[deque->rear] = data;
}

// Función para remover un elemento por la parte del frente de la cola doble
char removeFront(Deque *deque) {
    if (isEmpty(*deque)) {
        printf("La cola doble está vacía.\n");
        exit(EXIT_FAILURE);
    }
    char data = deque->data[deque->front];
    if (deque->front == deque->rear) { // Si hay un solo elemento en la cola doble
        deque->front = -1;
        deque->rear = -1;
    } else if (deque->front == MAX_SIZE-1) { // Si la parte del frente está en la última posición
        deque->front = 0;
    } else {
        deque->front++;
    }
    return data;
}

// Función para remover un elemento por la parte trasera de la cola doble
char removeRear(Deque *deque) {
    if (isEmpty(*deque)) {
        printf("La cola doble está vacía.\n");
exit(EXIT_FAILURE);
}
char data = deque->data[deque->rear];
if (deque->front == deque->rear) { // Si hay un solo elemento en la cola doble
    deque->front = -1;
    deque->rear = -1;
} else if (deque->rear == 0) { // Si la parte trasera está en la primera posición
    deque->rear = MAX_SIZE-1;
} else {
    deque->rear--;
}
return data;
}
// Función para comprobar si una cadena de caracteres es un palíndromo
bool isPalindrome(char str[]) {
int len = strlen(str);
Deque deque = createDeque();
// Agregar los caracteres de la cadena de caracteres a la cola doble
for (int i = 0; i < len; i++) {
addRear(&deque, str[i]);
}
// Comparar los caracteres de la parte del frente y la parte trasera de la cola doble
while (!isEmpty(deque)) {
char front = removeFront(&deque);
char rear = removeRear(&deque);
if (front != rear) {
return false;
}
}
return true;
}

// Función principal
int main() {
char str[MAX_SIZE];
printf("Introduce una palabra: ");
scanf("%s", str);
if (isPalindrome(str)) {
printf("%s es palindromo.\n", str);
} else {
printf("%s no es palindromo.\n", str);
}
return 0;
}