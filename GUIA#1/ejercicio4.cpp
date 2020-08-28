#include <iostream>
using namespace std;


int main ()
{

    int number;
    int example [100];
    int higher = 0;
// data input 
    cout<<"\n Ingrese la cantidad de numero del arreglo : ";
    cin>>number;


 // data input
for (int i = 0; i < number; i++)
{
    cout<<" \n Ingrese el numero "<<i+1<<": ";
    cin>>example[i];

    if (example[i]>higher)
    {
        higher = example[i];
    }
    
}
//pointer
   int *p = &higher;
// data output
   cout<<"\n El numero mayor del arreglo es : "<<*p;

return 0;
      
}