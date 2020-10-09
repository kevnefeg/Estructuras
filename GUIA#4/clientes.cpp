#include <iostream>
#include <queue>
using namespace std;

struct Client {
    string name;
    string last;
    int payment;
};
struct Client client;

void charge(queue<Client> clientQueue, int amount) {
    while (!clientQueue.empty()) {
        amount += clientQueue.front().payment;
        clientQueue.pop();
    }

    cout << "Se le ha cobrado un total de $" << amount << " a los clientes" << endl;
}

void menu(queue<Client> clientQueue, int amountPaid) {
    int option;
    bool status = true;
    while(status) {
        cout << "\n" << "***** MENU DE COLAS *****" << endl;
        cout << "1. Ingresar clientes a la cola" << endl;
        cout << "2. Cobrar" << endl;
        cout << "3. Salir del menu" << endl;

        cout << "\n" << "Ingrese la opción que desea ejecutar: ";
        cin >> option;

        switch(option){
            case 1:
                cout << "Ingrese el nombre del cliente: ";
                cin >> client.name;
                cout << "Ingrese el apellido del cliente: ";
                cin >> client.last;
                cout << "Ingrese el monto de pago de la persona: ";
                cin >> client.payment;

                clientQueue.push(client);
                break;
            case 2:
                charge(clientQueue, amountPaid);
                break;
            case 3:
                cout << "Fin del programa" << endl;
                status = false;
                break;
            default:
                cout << "Opción no válida" << endl;
                break;
        }
    }
}

int main(){
    queue<Client> clientQueue;

    int amountPaid = 0;

    menu(clientQueue, amountPaid);

}
