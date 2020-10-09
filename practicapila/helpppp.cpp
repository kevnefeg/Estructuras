#include <iostream>
#include <string>
#include <stack>

using namespace std;

struct plato
{
    string material;
    string color;
    bool estado;
};
typedef plato Plato;

struct nodo
{
    Plato elemento;
    struct nodo *siguiente;
};
typedef struct nodo *Pila;

void initialize(Pila *s);
bool empty(Pila *s);
void push(Pila *s, Plato e);
Plato pop(Pila *s);
Plato top(Pila *s);

int main()
{
    Pila pilaLimpia;
    initialize(&pilaLimpia);

    Pila pilaSucia;
    initialize(&pilaSucia);
    int cantidadPlatos;
    bool continuar = true;
    cout << "Cuantos platos dispone?" << endl;
    cin >> cantidadPlatos;
    cin.ignore();
    Plato unPlato;
    for (int i = 0; i < cantidadPlatos; i++)
    {
        cout << "Material: " << endl;
        getline(cin, unPlato.material);
        cout << "Color: " << endl;
        getline(cin, unPlato.color);
        unPlato.estado = false;
        push(&pilaLimpia, unPlato);
        cout << "PLATO " << i+1 << " AGREGADO" << endl;
    }

    do
    {
        int opcion = 0;
        cout << "1) Ensuciar un plato: " << endl;
        cout << "2) Ensuciar muchos platos" << endl;
        cout << "3) Limpiar un plato" << endl;
        cout << "4) Limpiar muchos platos" << endl;
        cout << "5) Mostrar platos limpios" << endl;
        cout << "6) Mostrar platos sucios" << endl;
        cout << "0) Salir" << endl;
        cin >> opcion;
        cin.ignore();
        if (opcion == 1)
        {
            Plato unPlato;
            cout << "Material: " << endl;
            getline(cin, unPlato.material);
            cout << "Color: " << endl;
            getline(cin, unPlato.color);
            unPlato.estado = true;
            push(&pilaLimpia, unPlato);
        }
        else if (opcion == 6)
        {
            cout << "\nDesapilando platos..." << endl;
            while (!empty(&pilaSucia))
            {
                Plato platoDeEncima = top(&pilaSucia);
                cout << "Plato [" << platoDeEncima.color;
                cout << ", " << platoDeEncima.material;
                cout << ", " << platoDeEncima.estado << "]\n";

                pop(&pilaSucia);
            }
            cout << "Pila de platos vacia." << endl;
            continuar = false;
        }
        else if (opcion == 2)
        {
            int cantidadSucios;
            Plato unPlato;
            cout << "Cuantos platos ensuciara?" << endl;
            cin >> cantidadSucios;
            cin.ignore();
            for (int i = 0; i < cantidadSucios; i++)
            {
                cout << "Material: " << endl;
                getline(cin, unPlato.material);
                cout << "Color: " << endl;
                getline(cin, unPlato.color);
                unPlato.estado = false;
                cout << "PLATO SUCIO " << i + 1 << " AGREGADO" << endl;
                push(&pilaSucia, unPlato);
            }
        }
        else if (opcion == 5)
        {
            cout << "\nDesapilando platos..." << endl;
            while (!empty(&pilaLimpia))
            {
                Plato platoDeEncima = top(&pilaLimpia);
                cout << "Plato [" << platoDeEncima.color;
                cout << ", " << platoDeEncima.material;
                cout << ", " << platoDeEncima.estado << "]\n";

                pop(&pilaLimpia);
            }
            cout << "Pila de platos vacia." << endl;
            continuar = false;
        }

    } while (continuar);
}

void initialize(Pila *s)
{
    *s = NULL;
}

Plato pop(Pila *s)
{
    if (!empty(s))
    {
        struct nodo *unNodo = *s;
        Plato e = (*s)->elemento;
        *s = (*s)->siguiente;
        delete (unNodo);
        return e;
    }
    else // Underflow!
        return {""};
}

bool empty(Pila *s)
{
    return *s == NULL;
}

Plato top(Pila *s)
{
    if (!empty(s))
        return (*s)->elemento;
    else // Underflow!
        return {" "};
}

void push(Pila *s, Plato e)
{
    struct nodo *unNodo = new struct nodo;
    unNodo->elemento = e;
    unNodo->siguiente = *s;

    *s = unNodo;
}