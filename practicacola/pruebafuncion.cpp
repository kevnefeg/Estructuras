#include <iostream>
#include <queue>
using namespace std;


void showQueue(queue<int>q)
{
    queue<int> close=q;
    while (!close.empty())
    {
         cout<<close.front() << endl;
         cout<<endl;
         close.pop();
    }
    
}

void menu(queue<int>q)
{
    int option;
    bool status = true;
    while (status)
    {
        cout<<"1.Ingresar un elemento ala cola\n";
        cout<<"2.Eliminar un elemento de la cola\n";
        cout<<"3.Mostrar la cola\n";
        cout<<"4.Finalizar programa\n";
        cin>>option;


        switch (option)
        {
        case 1:
        int element;
        cout<<"Ingresar el elemento ala cola\n";
        cin>>element;
        q.push(element);
            break;
        case 2:
        q.pop();
        break;

        case 3:
        showQueue(q);
        break;
        case 4:
        cout<<"Programa finalizado";
        status=false;
        break;
        default:
        cout<<"Opcion no valida";
            break;
        }
    }
    
}
int main()
{
    queue<int> intQueue;

    menu(intQueue);

}