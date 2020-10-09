#include <iostream>
using namespace std;

struct Node {
    int element;
    struct Node *next;
};
typedef struct Node *Stack;

void initiliaze(Stack *s) {
    *s = NULL;
}

bool empty(Stack *s) {
    return *s == NULL;
}

void push(Stack *s, int e) {
    struct Node *node;
    node = (struct Node *)malloc(sizeof(struct Node));
    node->element = e;
    node->next = *s;

    *s = node;
}

void pop(Stack *s) {
    if (!empty(s)) {
        struct Node *aux = *s;
        *s = (*s)->next;
        delete(aux);
    }else {
        return;
    }
}

void showStack(Stack *s) {
    struct Node *clone = *s;
    bool isEmpty = false;
    while (!isEmpty) {
        if (!empty(&clone))
        {
            cout << clone->element << " ";
            clone = clone->next;
        }else {
            isEmpty = true;
        }
    }
}
bool xpair(int num)
{if (num % 2 == 0) {
        return true;
    }else {
        return false;
    }
}

int main()
{
    Stack sp,si;
    initiliaze (&sp);
    initiliaze (&si);
    int n;

    cout<<"Digite de cuanto sera el arreglo \n";
    cin>>n;

    int a[n], b[n], prod[n];

    cout<<"Ingrese los valores del primer arreglo \n";
    for (int i = 0; i < n; i++)
    {
        cin>>a[i];
    }

    cout<<"Ingrese los valores del segundo arreglo \n";
    for (int i = 0; i < n; i++)
    {
        cin>>b[i];
    }


    cout<<"Multplicando los valores de a y b \n";
    for (int i = 0; i < n; i++) {
        prod[i] = a[i]*b[i];
    }

    cout << "\n" << "Verificando par e impar para agregar a pilas: " << endl;
    for (int i = 0; i < n; i++) {
        if (xpair(prod[i])) {
            push(&sp, prod[i]);
        }else {
            push(&si, prod[i]);
        }
    }
    
    cout << "\n" << "Mostrando pila de pares" << endl;
    showStack(&sp);

    cout << "\n" << "Mostrando pila de impares" << endl;
    showStack(&si);

    cout << endl;
}
    
    
