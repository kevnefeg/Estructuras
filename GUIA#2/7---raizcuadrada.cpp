#include<iostream>
#include<math.h>
using namespace std;

float raiz(int,float);
int main()
{
    int n;
    float r;


    cout<<"Ingrese el numero al cual se le quiere calcular la raiz : ";
    cin>>n;
    cout<<"Ingrese el valor semilla: ";
    cin>>r;
    cout<<"RESPUESTA "<<raiz(n,r);
    return 0; 
}

float raiz(int n, float r)
{
    float a=r;

    r = ((n/r)+r)/2;

    if (abs(r-a)< 0.0000001)
    {
        return r;

    }
    else
    {
        return raiz(n,r);
    }
    
    
}