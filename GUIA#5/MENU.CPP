#include <iostream>
using namespace std;

struct Node {
    int element;
    struct Node *next;
};
typedef struct Node node;

struct Queue {
    node *front;
    node *back;
};
typedef struct Queue queue;

void initialize(queue *q) {
    q->front = NULL;
    q->back = NULL;
}

bool empty(queue *q) {
    return (q->front == NULL) ? true : false;
}

void push(queue *q, int element) {
    node *newNode;
    newNode = new node;
    newNode->element = element;
    newNode->next = NULL;

    if(q->back == NULL) {
        q->front = newNode;
        q->back = newNode;
    }else {
        (q->back)->next = newNode;
        q->back = newNode;
    }    
}

void pop(queue *q) {
    if(empty(q)) {
        cout << "Underflow" << endl;
        return;
    }
    node *aux = q->front;
    q->front = q->front->next;

    if(q->front == NULL) {
        q->back = NULL;
    }

    delete(aux);
}

void showQueue(queue *q) {
    if(empty(q)) {
        cout << "La cola está vacía" << endl;
    }else {
        node *aux = q->front;
        while(aux) {
            cout << aux->element << " ";

            aux = aux->next;
        }
    }
}

bool isPair(int num) {
    if(num % 2 == 0) {
        return true;
    }else {
        return false;
    }
}

void menu(queue *p, queue *i) {
    int option;
    bool status = true;
    while (status) {
        cout << "\n" << "***** MENU DE COLAS *****" << endl;
        cout << "1. Ingresar elemento a la cola" << endl;
        cout << "2. Eliminar par de la cola" << endl;
        cout << "3. Eliminar impar de la cola" << endl;
        cout << "4. Mostrar cola de pares" << endl;
        cout << "5. Mostrar cola de impares" << endl;
        cout << "6. Salir del menu" << endl;
        cout << "\n" << "Ingrese la opción que deseas ejectuar: ";
        cin >> option;
        cout << "\n";

        switch (option) {
            case 1:
                int element;

                cout << "Ingrese el numero a alguna de las colas: ";
                cin >> element;

                if(isPair(element)) {
                    push(p, element);
                }else {
                    push(i, element);
                }
                break;
            case 2:
                pop(p);
                break;
            case 3:
                pop(i);
                break;
            case 4:
                showQueue(p);
                break;
            case 5:
                showQueue(i);
                break;
            case 6:
                cout << "Fin del programa" << endl;
                status = false;
                break;
            default:
                cout << "Esta no es una opción válida" << endl;
                break;
        }
    }
}

int main() {
    queue p, i;

    initialize(&p);
    initialize(&i);

    menu(&p, &i);
}