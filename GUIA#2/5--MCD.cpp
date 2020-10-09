#include <iostream>

using namespace std;
//Formula


 int mcd(int nm1, int nm2)

{
    if (nm1 == 0)
    {
        return nm2;
    }
    return mcd (nm2 % nm1, nm1);
     
}

   int main()
{
//entrada de texto
   int nm1;
   int nm2;
   cout<<"\n Ingrese primer valor : ";
   cin>>nm1;

   cout<<" Ingrese segundo valor : ";
   cin>>nm2;
//salida de texto
   cout<<"El maximo comun divisor es: "<<mcd(nm1,nm2);

return 0;
system("pause");
}