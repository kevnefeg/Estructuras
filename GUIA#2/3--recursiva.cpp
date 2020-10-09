#include <iostream>
using namespace std;
//funcion recursiva
void recursiva(int *p,int a)
{
    int i=0;
    if (a == 0)
    {
        return;  
    }
    else
    {
         cout<<"Ingrese el valor " <<i+1<< " del arreglo: ";
        cin>>*p;
         p++;
    }
    recursiva(p,a-1);   
    
}
//funcion mostrando sin recursividad
void showoof(int *p, int a)
{
    for (int i = 0; i < a; i++)
    {
        cout<<*p<<" ";

        p++;
    }
    
}
//funcin mostrando con recursividad
void recursiveshowoof(int *p, int a)
{
    if (a==0)
    {
        return;
    }
    else
    {
        cout<<*p<<" ";

        p++;
    }

    recursiveshowoof(p,a-1);
    
    
}

int main()
{
    int a;
   
    cout<<"\n Ingrese la cantidad de numeros que llevara el arreglo : ";
    cin>>a;
    int num [a];

    int *p = num;

    recursiva(p,a);

    p=num;
    cout<<"\n mostrando el arreglo \n ";
    showoof(p,a);

     p=num;
    cout<<"\n mostrando el arreglo recursivamente... \n ";
    showoof(p,a);


    return 0;



}