#include <iostream>
using namespace std;
//funcion que calcula la cantidad de numeros pares e impares
void par(int numbers[3][3],int rows,int columns)
{
    int pa=0;
    int impar=0;
    //ciclo para sacar los pares e impares
    for (int i = 0; i < rows; i++)
    {
        for (int j = 0; j < columns; j++)
        {
           if (numbers[i][j] % 2==0)
         {
              pa=pa+1;
        }
            else
        {
        impar=impar+1;
        }
        }
        
    }

    cout<<"\n la cantidad de numeros pares son "<<pa<<endl;

    cout<<"\n la cantidad de numeros impares son "<<impar<<endl;

    
}

//principal
int main()
{
    int numbers [3][3];
    int rows=3;
    int columns=3;
    
 //llenando la matriz
    for (int i = 0; i < rows; i++)
    {
        for (int j = 0; j < columns; j++)
        {
            cout<<"\n Digite en la fila  ["<<i+1<<"] el numero ["<<j+1<<"]";
            cin>>numbers[i][j];
        }
        
    }
//lamada de la funcion 
    par(numbers,rows,columns);

    return 0;

   
    

}

//ahi perdonde creo que punteros si me trabe algo y lo omiti y el tiempo me consumio.