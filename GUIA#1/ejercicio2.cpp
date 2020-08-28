#include <iostream>
using namespace std;
int main()
{
    int a;
    int b;

    cout<<"\n Ingrese el primer valor : ";
    cin>>a;
    
    cout<<"\n Ingrese el segundo valor : ";
    cin>>b;
     
    int *P1 = &a;
    int *P2 = &b;

    cout<<"\n numero en puntero y direccion "<<"\t"<<*P1<<"\t"<<P1;

    cout<<"\n numero en puntero y direccion "<<"\t"<<*P2<<"\t"<<P2;


    return 0;


}