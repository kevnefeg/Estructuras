#include <iostream>
using namespace std;

void menu() {
    int option;
    bool status = true;
    while (status) {
        cout << "\n" << "***** MENU DE COLAS *****" << endl;
        cout << "1. Ingrese estudiantes a la cola" << endl;
        cout << "2. Buscar estudiante por nombre" << endl;
        cout << "3. Salir del programa" << endl;
        cout << "\n" << "Ingrese la opción que deseas ejectuar: ";
        cin >> option;
        cout << "\n";

        switch (option) {
            case 1:
                
                break;
            case 2:
                
                break;
            case 3:
                cout << "Fin del programa" << endl;
                status = false;
            default:
                cout << "No es una opción válida" << endl;
                break;
        }
    }
}

int main() {
    
}