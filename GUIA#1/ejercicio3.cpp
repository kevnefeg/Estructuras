#include <iostream>
using namespace std;
int main ()
{
    int a;

    cout<<"\n Ingrese un numero : ";
    cin>>a;

    int *pr = &a;

    cout<<"\n Numero en un puntero = "<<*pr;




}