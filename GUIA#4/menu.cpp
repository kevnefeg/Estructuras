#include <iostream>
#include <queue>
using namespace std;

void showQueue(queue<int> q) {
    queue<int> clone = q;
    while (!clone.empty()) {
        cout << clone.front() << endl;
        clone.pop();
    }
}

void menu(queue<int> q) {
    int option;
    bool status = true;
    while(status) {
        cout << "\n" << "***** MENU DE COLAS *****" << endl;
        cout << "1. Ingresar elementos a la cola" << endl;
        cout << "2. Borrar elementos de la cola" << endl;
        cout << "3. Mostrar cola" << endl;
        cout << "4. Terminar el programa" << endl;

        cout << "\n" << "Ingrese la opción que desea ejecutar: ";
        cin >> option;

        switch(option) {
            case 1:
                int element;

                cout << "Ingrese el elemento a añadir a la cola" << endl;
                cin >> element;

                q.push(element);

                break;
            case 2:
                q.pop();
                break;
            case 3:
                showQueue(q);
                break;
            case 4:
                cout << "Fin del programa" << endl;
                status = false;
                break;
            default: 
                cout << "Opción no válida" << endl;
                break;
        }
    }
}

int main() {
    queue<int> intQueue;

    menu(intQueue);
}