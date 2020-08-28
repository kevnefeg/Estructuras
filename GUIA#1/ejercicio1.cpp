#include <iostream>
using namespace std;

int main()
{
    int var = 5;
    int *p=NULL;
    p=&var;
    cout<<"\n El valor de la variable es "<<var;
    *p=3;
    cout<<"\n El valor de la variable es "<<var<<"\n";
   
    system ("pause");
    return 0;

}