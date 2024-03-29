#include <stdio.h>
#include <stdlib.h>

#define MAX_SIZE 10

struct node_pila {
    int turno;
    struct node_pila* siguiente;
};

struct node_cola {
    int turno;
    struct node_cola* siguiente;
};

struct pila {
    struct node_pila* tope;
};

struct cola {
    struct node_cola* inicio;
    struct node_cola* fin;
};

void inicializar_pila(struct pila* p) {
    int i;
    for (i = 1; i <= MAX_SIZE; i++) {
        struct node_pila* nuevo = (struct node_pila*)malloc(sizeof(struct node_pila));
        nuevo->turno = i;
        nuevo->siguiente = p->tope;
        p->tope = nuevo;
    }
}

void inicializar_cola(struct cola* c) {
    c->inicio = NULL;
    c->fin = NULL;
}

int pila_vacia(struct pila* p) {
    return p->tope == NULL;
}

int cola_vacia(struct cola* c) {
    return c->inicio == NULL;
}

void insertar_a_cola(struct cola* c, int turno) {
    struct node_cola* nuevo = (struct node_cola*)malloc(sizeof(struct node_cola));
    nuevo->turno = turno;
    nuevo->siguiente = NULL;
    if (cola_vacia(c)) {
        c->inicio = nuevo;
        c->fin = nuevo;
    }
    else {
        c->fin->siguiente = nuevo;
        c->fin = nuevo;
    }
}

int extraer_de_cola(struct cola* c) {
    if (cola_vacia(c)) {
        printf("La cola esta vacia.\n");
        return -1;
    }
    else {
        int turno = c->inicio->turno;
        struct node_cola* temp = c->inicio;
        c->inicio = c->inicio->siguiente;
        if (c->inicio == NULL) {
            c->fin = NULL;
        }
        free(temp);
        return turno;
    }
}

void formarse(struct pila* p, struct cola* c) {
    if (pila_vacia(p)) {
        printf("No hay turnos disponibles.\n");
    }
    else {
        int turno = p->tope->turno;
        p->tope = p->tope->siguiente;
        insertar_a_cola(c, turno);
        printf("Se ha asignado el turno %d al elemento de la cola.\n", turno);
    }
}

void mostrar_estado(struct pila* p, struct cola* c) {
    if (pila_vacia(p)) {
        printf("La pila esta vacia.\n");
    }
    else {
        printf("Estado de la pila:\n");
        printf("------------------\n");
        printf("Tope: %d\n", p->tope->turno);
    printf("\n");
    }
    if (cola_vacia(c)) {
        printf("La cola esta vacia.\n");
    }
    else {
        printf("Estado de la cola:\n");
        printf("------------------\n");
        printf("Ultimo elemento formado: %d\n", c->fin->turno);
        printf("\n");
    }
}

int main() {
struct pila p;
struct cola c;
int opcion;
p.tope = NULL;
inicializar_pila(&p);
inicializar_cola(&c);

do {
    printf("Menu:\n");
    printf("1. Formarse\n");
    printf("2. Salir\n");
    printf("Elija una opcion: ");
    scanf("%d", &opcion);

    switch (opcion) {
    case 1:
        formarse(&p, &c);
        break;
    case 2:
        printf("Saliendo del programa...\n");
        break;
    default:
        printf("Opcion no valida. Intente de nuevo.\n");
    }

    printf("\n");

} while (opcion != 2);

mostrar_estado(&p, &c);

return 0;
}