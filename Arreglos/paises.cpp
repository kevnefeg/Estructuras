#include <iostream>
#include <string>
#include "structura.h"
using namespace std;



//funciones
void entrance(paises *p); void totalpopu(paises *p);  void capit();

int main()
{
    paises actual;
    bool continuar = true;
    do{
        int opcion = 0;
        cout << "\n1. Entrada de paises\n";
        cout << "2. Calcular la poblacion total\n";
        cout << "3. Capital con mayor poblacion\n";
        cout << "4. Salir\n";
        cout << "Opcion: ";
        cin >> opcion;
        cin.ignore();
        
        switch(opcion){
            case 1: entrance(&actual); break;
            case 2: totalpopu(&actual); break;
            case 3: capit(); break;
            case 4: continuar = false;
        }
    }while(continuar);
    system("pause");

    return 0;

}

//funcion para la etrada de datos del continente
void entrance(paises *p)
{
    if (totalcountry<5)
    {
        cout<<"\n Ingrese el nombre del pais : ";
        getline(cin, p->nombre);
        cout<<"Ingrese la capital del pais : ";
        getline(cin,p->capital);
        cout<<"Ingrese el numero de habitantes : ";
        cin>> p->numhabit;
        cin.ignore();

        totalcountry++;
    }
    else
    {
        cout<<"\n Cantidad de paises maxima \n";
    }
    

}
//AUN NO FUNCIONA 
//funcion para calcular la poblacion total
void totalpopu(paises *p)
{
    int adding =0; 
    for (int i = 0; i <5; i++)
    {
        adding +=p->numhabit;
    }
 
    cout<<"\n La poblacin total del continente : "<<adding; 
    
};

void capit()
{

    

};