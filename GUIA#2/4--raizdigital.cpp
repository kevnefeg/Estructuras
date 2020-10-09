#include <iostream>
#include <math.h>

using namespace std;
int raizDigital(int number);


int main()
{
    int number;

    cout<<"Ingrese el numero (NO NEGATIVO)";
    cin>>number;

    raizDigital(number);

}


int raizDigital(int number)
{
    int aux, suma=0;

    if (number<10)
    {
        return number;
    }
    else
    {
        while (number>0)
        {
            suma = suma+ number%10;
            number = number/10;
        }
        cout<<" LA suma es : "<<suma<<endl;
        return raizDigital(suma);
    }
    
    
}