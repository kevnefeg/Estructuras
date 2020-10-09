#include<iostream>

using namespace std;
int suma(int number);
int main()
{
    int number;

    cout<<  "Ingresar la cantidad de numeros que desea sumar : ";
    cin>>number;


    cout<<" La suma es : "<<suma(number);

    return 0;

}



int suma(int number)
{
    if (number==0)
    {
        return 0;
    }
    else
    {
        return number+suma(number-1);
    }
    
    
}