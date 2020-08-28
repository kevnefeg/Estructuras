#include <iostream>
#include <conio.h>
#include <string.h>
using namespace std;
int main()
{
    char frase[30];
    int vocal = 0;

    cout<<"\n Inserte una palabra : ";
    cin.getline(frase,30,'\n');

    for (int i = 0; i < 30; i++)
    {
        switch (frase[i])
        {
        case 'a': vocal++; break;
        case 'e': vocal++; break;
        case 'i': vocal++; break;
        case 'o': vocal++; break;
        case 'u': vocal++; break;
        default:
            break;
        }
    }
    
    cout<<"\n La cantidad de vocales en la palabra : "<<vocal;

}