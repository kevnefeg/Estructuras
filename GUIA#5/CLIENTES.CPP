#include <iostream>
#include <string>
using namespace std;

struct Client {
    string name;
    int payment;
    struct Client *next;
};
typedef struct Client client;

struct Queue {
    client *front;
    client *back;
};
typedef struct Queue queue;

void initialize(queue *q) {
    q->front = NULL;
    q->back = NULL;
}

bool empty(queue *q) {
    if(q->front == NULL) {
        return true;
    }else {
        return false;
    }
}

void push(queue *q, string name, int payment) {
    client *newClient;
    newClient = new client;
    newClient->name = name;
    newClient->payment = payment;
    newClient->next = NULL;

    if(q->back == NULL) {
        q->front = newClient;
        q->back = newClient;
    }else {
        (q->back)->next = newClient;
        q->back = newClient;
    }
}

void pop(queue *q) {
    if(empty(q)) {
        cout << "Underflow" << endl;
        return;
    }
    client *newClient = q->front;
    q->front = q->front->next;

    if(q->front == NULL) {
        q->back = NULL;
    }

    delete(newClient);
}

int charge(queue *q, int amount) {
    if(empty(q)) {
        cout << "No hay clientes en la cola, no se ha realizado ningún cobro" << endl;
        return 0;
    }else {
        while(!empty(q)) {
            amount += q->front->payment;
            cout << "Se le ha cobrado $" << q->front->payment << " a " << q->front->name << endl;
            pop(q);
        }
        return amount;
    }
}

void menu(queue *q) {
    string name;
    int amount = 0, total = 0;

    int option;
    bool status = true;
    while (status) {
        cout << "\n" << "***** MENU DE COLAS *****" << endl;
        cout << "1. Ingresar cliente a la cola" << endl;
        cout << "2. Cobrar" << endl;
        cout << "3. Salir del menu" << endl;
        cout << "\n" << "Ingrese la opción que deseas ejectuar: ";
        cin >> option;
        cout << "\n";

        switch (option) {
            case 1:
                int payment;

                cout << "Ingrese el nombre del cliente" << endl;
                cin.ignore();
                getline(cin, name);

                cout << "Ingrese el monto de pago del cliente" << endl;
                cin >> payment;

                push(q, name, payment);
                break;
            case 2:
                total += charge(q, amount);

                cout << "\n" << "Se le ha cobrado un total de $" << total << " a todos los clientes de la cola" << endl; 
                break;
            case 3:
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