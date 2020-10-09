#include <iostream>
#include <stack>
#include <string>
using namespace std;

struct colegio
{
    string nombre;
    int grado;
    string apellido;
    string profesora;
};
typedef struct colegio cole;

int main()
{
    stack<cole> pilaestu;

   
    bool continuar=true;
    do
    {
        char option = 's';
        cout<<"Ingrese la cantidad de estudiantes : "<<pilaestu.size();
        cout<<"\n Desea ingresar mas estudiantes (si/no): ";
        cin>>option; cin.ignore();

        if (option=='s')
        {
            cole estu;
         cout<<"Ingrese el nombre del estudiante \n"; getline(cin,estu.nombre);
         cout<<"Ingrese el apellido del estudiante \n"; getline(cin,estu.apellido);
         cout<<"Ingrese el profesor del estudiante \n"; getline(cin,estu.profesora);
         cout<<"Ingrese el grado del estudiante \n"; cin>>estu.grado;
         pilaestu.push(estu); 
        }
        else if (option == 'n')
        {
            continuar =false;
        }
        else
        {
            cout<<"Option not valid ";
        }
    } while (continuar);


    cout<<"Borrando estudiantes,,, \n";
    while (!pilaestu.empty())
    {
        cole estuup=pilaestu.top();
        cout << "Estudiante [" << estuup.nombre;
        cout << ", " << estuup.apellido;
        cout << ",Grado = " << estuup.grado;
        cout << ", " << estuup.profesora << "]\n";

        pilaestu.pop();
    }

    cout<<"\n  pila de estudiantes bye \n";

    return 0;
    
    
}