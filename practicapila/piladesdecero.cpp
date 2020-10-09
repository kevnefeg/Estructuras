#include <iostream>
#include <string>

using namespace std;

struct Node {
    string nombre;
    int grado;
    string apellido;
    string profesora;
    struct Node *next;
};
typedef struct Node *Stack;

Stack  estu;

void initiliaze(Stack *s) {
    *s = NULL;
}

bool empty(Stack *s) {
    return *s == NULL;
}

void push(Stack *s, string n,string a,string b, int g )
 {
    struct Node *node;
    node = (struct Node *)malloc(sizeof(struct Node));
    node->nombre = n;
    node->apellido = a;
    node->grado = g;
    node->profesora = b;
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
            cout << clone->nombre << " ";
            cout << clone->apellido << " ";
            cout << clone->grado << " ";
            cout << clone->profesora << " ";
            cout<<endl;
            clone = clone->next;
        }else {
            isEmpty = true;
        }
    }
}

void menux(Stack *s)
{
    

    string nombre;
    int grado;
    string apellido;
    string profesora;
    
    
    int option;
    bool status = true;
    while (status)
    {
        cout<<endl;
        cout << "\n" << "***** MENU DE PILAS *****" << endl;
        cout << "1. Ingresar alumno a la pila" << endl;
        cout << "2. Eliminar alumno de la pila" << endl;
        cout << "3. Salir del menu" << endl;
        cout << "\n" << "Ingrese la opcion que deseas ejectuar: ";
        cin >> option;
        cout << "\n";

        switch (option)
        {
            case 1:
            cin.ignore();
                
         cout<<"Ingrese el nombre del estudiante \n"; getline(cin,nombre);
         cout<<"Ingrese el apellido del estudiante \n"; getline(cin,apellido);
         cout<<"Ingrese el profesor del estudiante \n"; getline(cin,profesora);
         cout<<"Ingrese el grado del estudiante \n"; cin>>grado;
                push(s, nombre, apellido, profesora, grado);
               // push(s, apellido);
               // push(s, profesora); 
               // push(s, grado);
                cout << "Mostrando la pila actualizada \n" << endl;
                cout<<endl;
                showStack(s);
                cout<<endl;
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
    };
}

int main()
{
    Stack stack;
    Stack *s;
    initiliaze(&stack);

    menux(&stack);
    
    return 0;
    
}