#include <iostream>
#include<conio.h>
using namespace std;
//proceso de suma
float suma (float number1, float number2,int resultado =0 )
{
    resultado =number1+number2;
     cout<<"la suma es : "<<resultado<<endl;

}
//proceso de resta
float resta (int number1, int number2,int resultado=0 )
{
    resultado =number1-number2; 
        cout<<"la resta es : "<<resultado<<endl;


}
//proceso de multiplicacion
float multi(int number1, int number2,int resultado=0 )
{
    resultado=number2*number1;
        cout<<"la multiplicacion es : "<<resultado<<endl;


}
//proceso de division
float division(int number1, int number2,int resultado =0)
{
    if (number2>0)
    {
        resultado= number1/number2;
    }
    else
    {
        cout<<"\n no es posible dividir";
    }
        cout<<"la division  es : "<<resultado<<endl;

}
//main entrada de datos
int main()
{
    int number1;
    int number2;
    int resultado = 0;
//ingreso de datos    
    cout<<"\n ingrese el primer entero : ";
    cin>>number1;
    cout<<endl;
    cout<<"\n ingrese el primer entero : ";
    cin>>number2;
    cout<<endl;
//llamada alas funciones
    suma(number1,number2,resultado);
    resta(number1,number2,resultado);
    multi(number1,number2,resultado);
    division(number1,number2,resultado);


   return 0;

}
