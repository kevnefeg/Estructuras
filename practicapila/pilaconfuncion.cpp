#include <iostream>
#include <stack>
#include <string>
using namespace std;

struct plato{
    string color;
    string material;
    string tipo;
};
typedef struct plato Plato;

int main(){
    // 1) Creando pila de platos vacia -------------
    stack<Plato> pilaDePlatos;
    
    // 2) Apilando platos --------------------------
    bool continuar = true;
    do{
        char opcion = 's';
        cout << "\nCantidad de platos actual: " << pilaDePlatos.size();
        cout << "\nDesea apilar otro plato? (s/n): ";
        cin >> opcion; cin.ignore();
        
        if(opcion == 's'){
            Plato unPlato;
            cout << "Color: ";   getline(cin, unPlato.color);
            cout << "Material: ";   getline(cin, unPlato.material);
            cout << "Tipo: ";       getline(cin, unPlato.tipo);
            pilaDePlatos.push(unPlato); 
        }
        else if(opcion == 'n')
            continuar = false;
        else
            cout << "Opcion no valida!" << endl;
    }while(continuar);
    
    // 3) Desapilando platos -----------------------
    cout << "\nDesapilando platos..." << endl;
    while(!pilaDePlatos.empty()){
        // Obtener el plato de encima (sin sacarlo de la pila)
        Plato platoDeEncima = pilaDePlatos.top();
        cout << "Plato [" << platoDeEncima.color;
        cout << ", " << platoDeEncima.material;
        cout << ", " << platoDeEncima.tipo << "]\n";
        
        // Sacando plato de la pila
        pilaDePlatos.pop();
    }
    cout << "Pila de platos vacia." << endl;

    return 0;
}

