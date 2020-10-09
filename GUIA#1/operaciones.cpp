#include <iostream>
#include<conio.h>
using namespace std;
//proceso de suma
float suma (float number1, float number2,int *resultado  )
{
    *resultado =number1+number2;

}
//proceso de resta
float resta (int number1, int number2,int *resultado )
{
    *resultado =number1-number2; 


}
//proceso de multiplicacion
float multi(int number1, int number2,int *resultado )
{
    *resultado=number2*number1;


}
//proceso de division
float division(int number1, int number2,int *resultado)
{     
      *resultado= number1/number2;
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
    suma(number1,number2,&resultado);
         cout<<"la suma es : "<<resultado<<endl;

    resta(number1,number2,&resultado);
            cout<<"la resta es : "<<resultado<<endl;

    multi(number1,number2,&resultado);
            cout<<"la multiplicacion es : "<<resultado<<endl;

    division(number1,number2,&resultado);
            cout<<"la division  es : "<<resultado<<endl;



   return 0;

}
