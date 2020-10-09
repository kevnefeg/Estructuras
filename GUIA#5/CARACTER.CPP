#include <iostream>
using namespace std;

struct Node {
    char element;
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

void push(queue *q, char element) {
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

void pop(queue *q){ 
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

void searchChar(queue *q, char c) {
    bool found = false;
    if(empty(q)) {
        cout << "La cola está vacía, no se puede buscar el elemento deseado" << endl;
        return;
    }else {
        node *aux = q->front;
        while(aux) {
            if(aux->element == c) {
                cout << "Se encontró el elemento deseado, borrando cola..." << endl;
                found = true;
                while(!empty(q)) {
                    cout << "Borrando..." << endl;
                    pop(q);
                }
            }else {
                aux = aux->next;
            }
        }
    }
    if(found) {
        return;
    }else {
        cout << "No está el caracter en la cola" << endl;
    }
}

void menu(queue *q) {
    int option;
    bool status = true;
    while (status) {
        cout << "\n" << "***** MENU DE COLAS *****" << endl;
        cout << "1. Ingresar caracter a la cola" << endl;
        cout << "2. Buscar caracter en la cola y vaciar" << endl;
        cout << "3. Mostrar cola" << endl;
        cout << "4. Salir del menu" << endl;
        cout << "\n" << "Ingrese la opción que deseas ejectuar: ";
        cin >> option;
        cout << "\n";

        switch (option) {
            case 1:
                char element;

                cout << "Ingrese el caracter a la cola" << endl;
                cin >> element;

                push(q, element);
                break;
            case 2:
                char cS;

                cout << "Ingrese el caracter que desea buscar" << endl;
                cin >> cS;

                searchChar(q, cS);
                break;
            case 3:
                showQueue(q);
                break;
            case 4:
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
    queue q;

    initialize(&q);

    menu(&q);
}