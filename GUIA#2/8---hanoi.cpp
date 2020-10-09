#include <iostream>


using namespace std;

void playing(int disco,int tower1,int tower2,int tower3); void endgame();


int main()
{
//variables de la torre
    int tower1=1;
    int tower2=2;
    int tower3=3;
    int disco =0;
    int opcion;
//salida de texto 
    cout<<"\n BIENVENIDO ALA TORRE DE HANOI \n";

    cout<<"\n ------MENU----- \n";
    cout<<"\n ------1.Jugar------ \n";
    cout<<"\n ------2.Salir------ \n";
    cin>>opcion;
//opciones con llamadas a funciones 
    switch (opcion)
    {
    case 1: 
    cout<<"\n Ingrese cantidad de discos : ";
    cin>>disco;
    playing(disco,tower1,tower2,tower3); break;
    case 2: endgame(); break;
     default:
        break;
    }


    return 0;
}

//funcion para el movimiento de las torres
void playing(int disco,int tower1,int tower2,int tower3)
{
   
    if (disco==1)
    {
        cout<<" Mover el disco de la torre "<<tower1<<" hacia la torre "<<tower3<<"\n";
        
    }
    else
    {
            playing(disco-1,tower1,tower3,tower2);
             cout<<" Mover el disco de la torre "<<tower1<<" hacia la torre "<<tower3<<"\n";
            playing(disco-1,tower2,tower1,tower3);
    }
}
//finalizar el juego 
void endgame()
{
    cout<<"\n----- Gracias -----\n";
}