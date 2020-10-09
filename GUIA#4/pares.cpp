#include <iostream>
#include <queue>
using namespace std;

struct Pairs{
    int num1;
    int num2;
};
struct Pairs pairs;

void showQueue(queue<Pairs> pairsQueue) {
    queue<Pairs> aux = pairsQueue;
    while (!aux.empty()) {
        cout << "[" << aux.front().num1 << "," << aux.front().num2 << "]" << endl;
        aux.pop();
    }
}

void menu(queue<Pairs> pairsQueue) {
    int option;
    bool status = true;
    while(status) {
        cout << "\n" << "***** MENU DE COLAS *****" << endl;
        cout << "1. Ingresar pares a la cola" << endl;
        cout << "2. Mostrar los pares en la cola" << endl;
        cout << "3. Salir del menu" << endl;

        cout << "\n" << "Ingrese la opción que desea ejecutar: ";
        cin >> option;

        switch(option){
            case 1:
                cout << "Ingrese el primer numero: ";
                cin >> pairs.num1;
                cout << "Ingrese el segundo numero: ";
                cin >> pairs.num2;

                pairsQueue.push(pairs);
                break;
            case 2:
                showQueue(pairsQueue);
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


int main() {
    queue<Pairs> pairsQueue;

    menu(pairsQueue);
}