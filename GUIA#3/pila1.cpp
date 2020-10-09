#include <iostream>
using namespace std;

struct Node {
    int element;
    struct Node *next;
};
typedef struct Node *Stack;

void initiliaze(Stack *s) {
    *s = NULL;
}

bool empty(Stack *s) {
    return *s == NULL;
}

void push(Stack *s, int e) {
    struct Node *node;
    node = (struct Node *)malloc(sizeof(struct Node));
    node->element = e;
    node->next = *s;

    *s = node;
}

void pop(Stack *s) {
    if (!empty(s)) {
        struct Node *aux = *s;
        *s = (*s)->next;
        delete(aux);
    }else {
        return;
    }
}

void showStack(Stack *s) {
    struct Node *clone = *s;
    bool isEmpty = false;
    while (!isEmpty) {
        if (!empty(&clone))
        {
            cout << clone->element << " ";
            clone = clone->next;
        }else {
            isEmpty = true;
        }
    }
}

void menu(Stack *s) {
    int option;
    bool status = true;
    while (status)
    {
        cout << "\n" << "***** MENU DE PILAS *****" << endl;
        cout << "1. Ingresar elemento a la pila" << endl;
        cout << "2. Eliminar elemento de la pila" << endl;
        cout << "3. Salir del menu" << endl;
        cout << "\n" << "Ingrese la opción que deseas ejectuar: ";
        cin >> option;
        cout << "\n";

        switch (option)
        {
            case 1:
                int element;
                int hola;
                cout << "Ingrese el elemento a agregar a la pila: ";
                cin >> element;
                push(s, element);
                cout << "Mostrando la pila actualizada" << endl;
                showStack(s);
                break;
            case 2:
                pop(s);
                cout << "Mostrando la pila actualizada" << endl;
                showStack(s);
                break;
            case 3:
                cout << "Fin del programa" << endl;
                status = false;
                break;
            default:
                break;
        }
    }
}

int main() {
    Stack stack;
    initiliaze(&stack);

    menu(&stack);
    return 0;
}