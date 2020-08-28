#include <iostream>
#include <conio.h>
using namespace std;

void func(int numbers[100][100], int filas, int columnas)
{
    int adding;
    int datos[100];
    int biggest =0;
    for (int i = 0; i < filas; i++)
    {
        adding = 0;
        
        for (int j = 0; j < columnas; j++)
        {
            adding += numbers[i][j];
            datos[i]=adding;
        }
        cout<<"\n La suma de la fila "<<i+1<<" es: "<<adding<<endl;
         if (biggest<datos[i])
        {
            biggest=datos[i];
            columnas=(i+1);
        }
    }
         cout << "\n La mayor venta fue de: $" << biggest << " en la semana: " << columnas<< endl;



}


int main()
{
    int numbers [100][100];
    int filas =2;
    int columnas =5;

    for (int i = 0; i < filas; i++)
    {
        for (int j = 0; j < columnas; j++)
        {
            cout <<"Digita lo ganado en la semana: ["<<i+1<<"] dia: ["<<j+1<<"]: ";
            cin>>numbers[i][j];
        }
        
    }
    for (int i = 0; i < filas; i++)
    {
        for (int j = 0; j < columnas; j++)
        {
            cout<<numbers[i][j]<<"\t";
        }
        cout<<endl;
    }
    func(numbers,filas,columnas);
    getch();
    return 0;
}