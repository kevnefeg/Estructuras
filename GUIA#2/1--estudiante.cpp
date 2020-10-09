#include <iostream>
#include <math.h>
#include <string>

using namespace std;
//estructura de estudiantes 
struct estudiantes
{
    string name;
    string lastname;
    //int state = 0;
    float notes [20];
    float final = 0;
    int notas;

};struct estudiantes estu;
//llamada previa de funciones 
float promedio();
void pasar();


int main()
{
//entrada de datos
    cout<<"\n Bienvenido programa de aprobado y desaprobado ";

    cout<<"\n Ingrese el nombre del estudiante : ";
    getline(cin,estu.name);

    cout<<"\n Ingrese el apellido del estudiantes : ";
    getline(cin,estu.lastname);

    cout<<"\n Ingrese la cantidad de notas : ";
    cin>>estu.notas;

    for (int i = 0; i < estu.notas; i++)
    {
        cout<<"\n Ingrese la nota numero "<<i+1<<" ";
        cin>>estu.notes[i];
    }

//llamada de funciones
    promedio();
    pasar();


    return 0;
}

//funcion para calcular el promedio suma de las notas 
//dividido entre  la cantidad de notas
float promedio()
{
    int j;
    for ( j = 0; j < estu.notas; j++)
    {
         estu.final +=estu.notes[j]/estu.notas;
    }
   
    cout<<"\n El promedio de la nota es : "<<estu.final<<"\n";
    cout<<"-------------------------------------------------- \n";
}
//funcion para calcular si paso o no 
//siento la nota minima para pasar 6
void pasar()
{
    if (estu.final>=6)
    {
        cout<<estu.name<<" "<<estu.lastname<<" APROBO LA MATERIA ";
    }
    else
    {
          cout<<estu.name<<" "<<estu.lastname<<" DESAPROBO LA MATERIA ";
    }
    
}